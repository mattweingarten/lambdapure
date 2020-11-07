#ifndef LAMBDAPURE_DIALECT_H_
#define LAMBDAPURE_DIALECT_H_

#include "mlir/IR/Dialect.h"
#include "mlir/IR/Function.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"
#include "mlir/IR/StandardTypes.h"

namespace mlir {
namespace lambdapure {


  class LambdapureDialect : public mlir::Dialect {
  public:
    explicit LambdapureDialect(mlir::MLIRContext *ctx);

    /// Provide a utility accessor to the dialect namespace. This is used by
    /// several utilities for casting between dialects.
    static llvm::StringRef getDialectNamespace() { return "lambdapure"; }

    // mlir::Type parseType(mlir::DialectAsmParser &parser) const override;
    void printType(mlir::Type type, mlir::DialectAsmPrinter &printer) const override;
  };

//include generated ops file
#define GET_OP_CLASSES
#include "lambdapure/Ops.h.inc"

namespace lambdapureTypes{
  enum Types {
    Object = mlir::Type::FIRST_PRIVATE_EXPERIMENTAL_0_TYPE,
  };
}//lambdapureTypes

class ObjectType : public mlir::Type::TypeBase<ObjectType, mlir::Type,TypeStorage> {
public:
  /// Inherit some necessary constructors from 'TypeBase'.
  using Base::Base;

  /// This static method is used to support type inquiry through isa, cast,
  /// and dyn_cast.
  static bool kindof(unsigned kind) { return kind == lambdapureTypes::Object; }
  static ObjectType get(MLIRContext *context){
    return Base::get(context,lambdapureTypes::Object);
  }


};
}//lambdapure
}//mlir

#endif //LAMBDAPURE_DIALECT_H_
