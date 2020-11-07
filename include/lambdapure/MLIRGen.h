#ifndef LAMBDAPURE_GEN
#define LAMBDAPURE_GEN
#include <memory>
#include "mlir/IR/Module.h"

namespace mlir {
class MLIRContext;
class OwningModuleRef;
} // namespace mlir

namespace lambdapure {
class ModuleAST;
mlir::OwningModuleRef mlirGen(mlir::MLIRContext &context, ModuleAST &moduleAST);
// mlir::ModuleOp emptyModuleOp(mlir::MLIRContext &context);
} // namespace lambdpure

#endif // LAMBDAPURE_GEN
