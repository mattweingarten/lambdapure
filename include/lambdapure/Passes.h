#ifndef LAMBDAPURE_PASSES_H_
#define LAMBDAPURE_PASSES_H_
#include <memory>

namespace mlir{
  class Pass;

  namespace lambdapure {
    std::unique_ptr<mlir::Pass> createLambdapureToLeanLowering();
    std::unique_ptr<mlir::Pass> createReferenceRewriterPattern();
    std::unique_ptr<mlir::Pass> createDestructiveUpdatePattern();
  }
}

#endif//LAMBDAPURE_PASSES_H
