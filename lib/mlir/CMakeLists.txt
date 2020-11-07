add_mlir_dialect_library(MLIRlambdapure

        MLIRGen.cpp
        Dialect.cpp
        LambdapureToLeanLowering.cpp
        ReferenceRewritePattern.cpp
        DestructiveUpdates.cpp
        AST.cpp
        TranslateToCpp.cpp
          ADDITIONAL_HEADER_DIRS
          ${PROJECT_SOURCE_DIR}/include/lambdapure

          DEPENDS
          LambdapureOpsIncGen
        )
