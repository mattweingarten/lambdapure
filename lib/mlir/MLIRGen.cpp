#include "lambdapure/MLIRGen.h"

#include "lambdapure/AST.h"
#include "lambdapure/Dialect.h"
#include "lambdapure/Scope.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/Function.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/StandardTypes.h"
#include "mlir/IR/Verifier.h"
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"

#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/ScopedHashTable.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Casting.h"

#include <numeric>

using namespace mlir::lambdapure;
using namespace lambdapure;

using llvm::ArrayRef;
using llvm::cast;
using llvm::dyn_cast;
using llvm::isa;
using llvm::makeArrayRef;
using llvm::ScopedHashTableScope;
using llvm::SmallVector;
using llvm::StringRef;
using llvm::Twine;


//
namespace{
class MLIRGenImpl{
public:
MLIRGenImpl(mlir::MLIRContext &context) : builder(&context),lastLoc(builder.getUnknownLoc()){}
  //converts lambdapure AST -> MLIR
  mlir::ModuleOp mlirGen(ModuleAST &moduleAST){
    theModule = mlir::ModuleOp::create(loc());
    auto funcs = moduleAST.getFList();
    for(auto &funcAST : funcs){
      mlir::FuncOp func = mlirGen(*funcAST);
      if(!func){
        return nullptr;
      }
      theModule.push_back(func);
    }
    // for(int i = 0; i < funcs.size(); ++i){
    //   // auto func = mlirGen(*funcs.at(i));
    // }
    // for(FunctionAST &funcAST : moduleAST.getFList()){
    //   // auto func = mlirGen(funcAST);
    //   // if(!func){
    //   //   return nullptr;
    //   // }
    //   // theModule.push_back(func);
    // }

    // if (failed(mlir::verify(theModule))) {
    //   theModule.emitError("module verification error");
    //   return nullptr;
    // }
    return theModule;
  }



  mlir::ModuleOp emptyModuleOp(){
    return mlir::ModuleOp::create(builder.getUnknownLoc());

  }

private:
  mlir::ModuleOp theModule;
  mlir::OpBuilder builder;
  llvm::ScopedHashTable<StringRef, mlir::Value> symbolTable;
  lambdapure::ScopeTable scopeTable = lambdapure::ScopeTable();
  mlir::Location lastLoc;
  mlir::Block lastBlock;
  mlir::Location loc(){return lastLoc;}

  mlir::Location loc(Location loc){
    auto mlirLoc = builder.getFileLineColLoc(builder.getIdentifier(*loc.file),
                                     loc.line, loc.col);
    lastLoc = mlirLoc;
    return mlirLoc;
  }

  mlir::Type typeGen(VarType t){
    switch (t){
      case object:
        return ObjectType::get(builder.getContext());
      case u8:
        return builder.getIntegerType(8);
      default:
        return builder.getIntegerType(64);
    }

  }



  mlir::FuncOp mlirGen(FunctionAST &functionAST){
    //create scope
    scopeTable.scope();
    ScopedHashTableScope<StringRef, mlir::Value> var_scope(symbolTable);
    // setup type
    std::vector<mlir::Type> inputs;
    for(VarType t : functionAST.getArgTypes()){
      inputs.push_back(typeGen(t));

    }
    mlir::Type retTy;
    auto FName = functionAST.getName();
    auto func_type = builder.getFunctionType(inputs,typeGen(functionAST.getRetType()));
    // if(FName.compare("main") == 0){
    //   FName = "main";
    //   // if(inputs.size() > 0 ) {assert(false && "Invalid function main_, no input types allowed");}
    //   func_type = builder.getFunctionType(inputs,llvm::None);
    // }




    //setup loc,name,type
    //--------------------------------------------------------
    mlir::FuncOp function = mlir::FuncOp::create(loc(functionAST.getLoc()), FName, func_type);
    mlir::Block &entryBlock = *function.addEntryBlock();

    for(unsigned i = 0; i < functionAST.getArgs().size();++i){
      if(failed(scopeTable.declare(
        functionAST.getArgs().begin()[i] -> getName(),
        entryBlock.getArguments().begin()[i],
        typeGen(functionAST.getArgTypes().begin()[i])
      ))){return nullptr;}
    }
    //
    builder.setInsertionPointToStart(&entryBlock);
    auto region = function.getCallableRegion();
    auto fbody = mlirGen(*functionAST.getFBody());



    //--------------------------------------------------------
    //experimenting
    // ReturnOp returnOp;
    // builder.create<ReturnOp>(loc());
    //===============

    scopeTable.descope();
    return function;
  }



mlir::LogicalResult mlirGen(DirectRetStmtAST &direct){
  llvm::StringRef var = direct.getVar();
  mlir::Value result = scopeTable.lookup(var);
  builder.create<ReturnOp>(loc(),result);
  // if(!result){
  //   builder.create<ReturnOp>(loc());
  //
  // }
  // else {
  //   builder.create<ReturnOp>(loc(),result);
  // }
  return mlir::success();
}

mlir::LogicalResult mlirGen(CaseStmtAST &casestmt){
  llvm::StringRef var = casestmt.getVar();
  mlir::Value curr_val = scopeTable.lookup(var);
  auto bodies = casestmt.getBodies();
  mlir::Type t  = curr_val.getType();
  if(mlir::lambdapure::ObjectType::kindof(t.getKind())){
    curr_val = builder.create<ObjTagOp>(loc(), builder.getIntegerType(8),curr_val);
  }
  auto caseOp = builder.create<CaseOp>(loc(),curr_val,bodies.size());
  int i = 0;
  for(auto &body : bodies){
    auto &region = caseOp.getRegion(i);
    auto block = builder.createBlock(&region);
    builder.setInsertionPointToStart(block);
    mlirGen(*body);
    ++i;
  }
  return mlir::success();
}

mlir::LogicalResult mlirGen(RetStmtAST &ret){
  switch(ret.getKind()){
      case lambdapure::RetStmtAST::Direct:
        return mlirGen(cast<DirectRetStmtAST>(ret));
      case lambdapure::RetStmtAST::Case:
        return  mlirGen(cast<CaseStmtAST>(ret));
      default:
        return mlir::failure();
  }
}


mlir::Value mlirGen(NumberExprAST &expr){
  return builder.create<IntegerConstOp>(loc(),expr.getValue());
}

mlir::Value mlirGen(VariableExprAST &expr){
  return scopeTable.lookup(expr.getName());
}

mlir::Value mlirGen(AppExprAST &expr,mlir::Type ty){
  std::vector<mlir::Value> args = std::vector<mlir::Value>();

  mlir::Value funcVal = scopeTable.lookup(expr.getFName());
  for(auto &varExpr : expr.getArgs()){
    args.push_back(mlirGen(*varExpr));
  }
  return builder.create<AppOp>(loc(),funcVal,args,ty);
}


mlir::Value mlirGen(CallExprAST &expr,mlir::Type ty){
  std::vector<mlir::Value> args = std::vector<mlir::Value>();
  for(auto &varExpr : expr.getArgs()){
    args.push_back(mlirGen(*varExpr));
  }
  std::string fName = expr.getFName();
  std::vector<mlir::Type> results;
  results.push_back(ty);
  return builder.create<CallOp>(loc(),fName,args,ty);

}


mlir::Value mlirGen(ProjExprAST &expr, mlir::Type ty){
  auto varExpr = expr.getVar();
  return builder.create<ProjectionOp>(loc(),expr.getIndex(),mlirGen(*varExpr),ty);
}

mlir::Value mlirGen(CtorExprAST &expr, mlir::Type ty){
  std::vector<mlir::Value> args = std::vector<mlir::Value>();
  for(auto &varExpr : expr.getArgs()){
    args.push_back(mlirGen(*varExpr));
  }
  return builder.create<ConstructorOp>(loc(),expr.getTag(),args,ty);
  // return nullptr;
}


mlir::Value mlirGen(ExprAST &expr,mlir::Type ty){

  switch(expr.getKind()){
    case lambdapure::ExprAST::NumberExpr:
        return mlirGen(cast<NumberExprAST>(expr));
    case lambdapure::ExprAST::VarExpr:
        return mlirGen(cast<VariableExprAST>(expr));
    case lambdapure::ExprAST::AppExpr:
        return mlirGen(cast<AppExprAST>(expr),ty);
    case lambdapure::ExprAST::CallExpr:
        return mlirGen(cast<CallExprAST>(expr),ty);
    case lambdapure::ExprAST::CtorExpr:
        return mlirGen(cast<CtorExprAST>(expr),ty);
    case lambdapure::ExprAST::ProjExpr:
        return mlirGen(cast<ProjExprAST>(expr),ty);
    default:
      std::cout << "Invalid expression found in lambdapure AST" << std::endl;
      return nullptr;
  }

}


mlir::LogicalResult mlirGen(FBodyAST &fBodyAST){
  for(const std::unique_ptr<LetStmtAST> &letstmt :fBodyAST.getStmts()){
    auto expr = letstmt -> getExpr();
    mlir::Type ty = typeGen(letstmt -> getVtype());
    mlir::Value value = mlirGen(*expr,ty);
    if(failed(scopeTable.declare(
                  letstmt -> getName(),
                  value,
                  ty
       ))){
      std::cout << "Failed to declare variable in let stament" << std::endl;
      return mlir::failure();
    }
  }
  auto ret = mlirGen(*fBodyAST.getRet());
  return ret;
}







};
}//namespace

namespace lambdapure{
  // mlir::ModuleOp emptyModuleOp(mlir::MLIRContext &context){
  //   return MLIRGenImpl(context).emptyModuleOp();
  // }
  mlir::OwningModuleRef mlirGen(mlir::MLIRContext &context, ModuleAST &moduleAST){
      return MLIRGenImpl(context).mlirGen(moduleAST);
    }
}//namespace lambdapure
