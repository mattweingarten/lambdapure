#include "lambdapure/Dialect.h"
#include "lambdapure/Passes.h"
#include <iostream>
#include "mlir/IR/Matchers.h"
#include "mlir/IR/PatternMatch.h"


#include "mlir/Support/LLVM.h"
#include "mlir/Support/LogicalResult.h"

#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"

using namespace mlir;

namespace{
class ReferenceRewriterPattern
    : public mlir::PassWrapper<ReferenceRewriterPattern, FunctionPass> {
public:
  void runOnFunction() override {
    auto f = getFunction();
    std::vector<mlir::Value> args;
    std::vector<int> consumes;

    for(int i = 0; i <f.getNumArguments();++i ){
      args.push_back(f.getArgument(i));
      consumes.push_back(-1);//assume ownerships => starts with 1
    }
    runOnRegion(args,consumes,f.getBody());

  }

  void runOnRegion(std::vector<mlir::Value> args,std::vector<int> consumes,mlir::Region &region){
    for(auto it = region.op_begin(); it != region.op_end();++it ){
      auto context = it -> getContext();
      auto builder = mlir::OpBuilder(context);
      //check each block argument if it is operand of return, call, dec
      //or storing it in a newl allocated heap value
      // TODO: check for newly allocated heap value, check for owned/borrowed
      auto name = it -> getName().getStringRef().str();
      if(name == "lambdapure.ReturnOp"){
        mlir::Value val = it -> getOperand(0);
        checkConsume(val,args,consumes);
        addAllDecs(&*it,args,consumes,builder);
      }
      if(name == "lambdapure.DecOP" || name == "lambdapure.ReuseAllocCtorOp"){
        mlir::Value val = it -> getOperand(0);
        checkConsume(val,args,consumes);
      }
      if(name == "lambdapure.CtorSetOp"){
        //todo check if Alloca is new
        mlir::Value alloca = it -> getOperand(0);
        if(OpResult::classof(alloca)){
            mlir::Value val = it -> getOperand(1);
            checkConsume(val,args,consumes);
        }
      }
      if(name == "lambdapure.ProjectionOp"){
        mlir::Value val = it -> getOpResult(0);
        args.push_back(val);
        consumes.push_back(1);
      }

      if(name == "lambdapure.CallOp" || name == "lambdapure.AppOp"){
        for(auto val = it ->operand_begin();val != it -> operand_end();++val){
          checkConsume(*val,args,consumes);
        }
      }

      if(name == "lambdapure.CaseOp" ){
          //call recursively the next region with copied arg vector and consumes vector
          std::vector<mlir::Value> new_args(args);
          std::vector<int> new_consumes(consumes);
          // std::cout << "got here" << std::endl;
          for(int i = 0 ; i < it ->getNumRegions();++i){
            auto &region = it -> getRegion(i);
            runOnRegion(new_args,new_consumes,region);
          }
          //
      }

    }
  }

  void checkConsume(mlir::Value value,std::vector<mlir::Value> &args,std::vector<int> &consumes){
    for(int i = 0; i < args.size(); ++i){
      if(args.at(i) == value){
        consumes[i]++;
      }
    }
  }

  void addAllDecs(Operation *op, std::vector<mlir::Value> &args,std::vector<int> &consumes,mlir::OpBuilder &builder){
    builder.setInsertionPoint(op);
    for(int i = 0;i < args.size(); ++i){
      if(consumes[i] ==  -1){
        builder.create<lambdapure::DecOp>(builder.getUnknownLoc(),args[i]);
      }else if(consumes[i] >= 1){
        for(int j = 0; j < consumes[i];++j){
          builder.create<lambdapure::IncOp>(builder.getUnknownLoc(),args[i]);
        }
      }
    }
  }
};
}//end anonymous namespace

std::unique_ptr<Pass> mlir::lambdapure::createReferenceRewriterPattern(){
  return std::make_unique<ReferenceRewriterPattern>();
}
