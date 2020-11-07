#include "lambdapure/Dialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/StandardTypes.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/DialectImplementation.h"
#include <iostream>

using namespace mlir;

using namespace mlir::lambdapure;

LambdapureDialect::LambdapureDialect(mlir::MLIRContext *ctxt) :mlir::Dialect("lambdapure",ctxt){

  addOperations<

    #define GET_OP_LIST
    #include "lambdapure/Ops.cpp.inc"
    >();
    addTypes<ObjectType>();

}

void LambdapureDialect::printType(mlir::Type type,
                           mlir::DialectAsmPrinter &printer) const{
    ObjectType objType = type.cast<ObjectType>();
    printer << "Object";
}

void IntegerConstOp::build(mlir::OpBuilder &builder, mlir::OperationState &state, int value){
  state.addAttribute("value",builder.getI64IntegerAttr(value));
  mlir::MLIRContext *ctxt = builder.getContext();
  state.addTypes(ObjectType::get(ctxt));
}

void AppOp::build(mlir::OpBuilder &builder, mlir::OperationState &state,
                  Value func, ArrayRef<Value> args,mlir::Type ty){

  state.addOperands({func});
  state.addOperands(args);
  state.addTypes(ty);
}


void CallOp::build(mlir::OpBuilder &builder,mlir::OperationState &state, llvm::StringRef fName,
                  ArrayRef<Value> args, mlir::Type ty)
{
  state.addAttribute("callee", builder.getSymbolRefAttr(fName));
  state.addOperands(args);
  state.addTypes(ty);
}


void ConstructorOp::build(mlir::OpBuilder &builder,mlir::OperationState &state,
  int tag,ArrayRef<Value> operands, mlir::Type ty){
    state.addAttribute("tag",builder.getI64IntegerAttr(tag));
    state.addOperands(operands);
    state.addTypes(ty);
}

void ProjectionOp::build(mlir::OpBuilder &builder, mlir::OperationState &state,
                           int index, mlir::Value operand, mlir::Type ty){
  state.addAttribute("index",builder.getI64IntegerAttr(index));
  state.addOperands({operand});
  state.addTypes(ty);
 }


 void TagCheckOp::build(mlir::OpBuilder &builder, mlir::OperationState &state,
                            int branch, mlir::Value operand){
   state.addAttribute("branch",builder.getI64IntegerAttr(branch));
   state.addOperands({operand});
   state.addTypes(builder.getIntegerType(1));
  }

  // void ReuseAllocCtorOp::build(mlir::OpBuilder &builder, mlir::OperationState &state,
  //                            int tag, int size,mlir::Value object){
  //   state.addAttribute("tag",builder.getI64IntegerAttr(tag));
  //   state.addAttribute("size",builder.getI64IntegerAttr(size));
  //   state.addOperands({object});
  //   state.addTypes(ObjectType::get(builder.getContext()));
  //  }

  void ReuseConstructorOp::build(mlir::OpBuilder &builder,mlir::OperationState &state,
                                 int tag,ArrayRef<Value> operands){
    state.addAttribute("tag",builder.getI64IntegerAttr(tag));
    state.addOperands(operands);

    state.addTypes(ObjectType::get(builder.getContext()));
  }

  void ExclCheckOp::build(mlir::OpBuilder &builder,mlir::OperationState &state,
                                 mlir::Value operand){
    state.addOperands({operand});

    state.addTypes(builder.getIntegerType(1));
  }


#define GET_OP_CLASSES
#include "lambdapure/Ops.cpp.inc"
