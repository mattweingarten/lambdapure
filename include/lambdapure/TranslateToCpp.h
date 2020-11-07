#ifndef LAMBDAPURE_TRANSLATE
#define LAMBDAPURE_TRANSLATE
#include "mlir/IR/Module.h"

namespace lambdapure{
   void translate(mlir::ModuleOp &module);
}//end namespace


#endif //LAMBDAPURE_TRANSLATE
