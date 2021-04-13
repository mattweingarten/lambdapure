# Github for bachelor thesis
## [A static-single-assignment intermediate representation for a pure functional language](./bachelor_thesis_matt_weingarten.pdf)


## Build / Commands

### build
```
export BUILD_DIR=/mnt/c/Users/path-to-llvm
  
cmake  .. -DMLIR_DIR=$BUILD_DIR/lib/cmake/mlir \
-DLLVM_EXTERNAL_LIT=$BUILD_DIR/bin/llvm-lit \

cmake --build .
```
### to view tblgen (from build)
```
$BUILD_DIR/bin/mlir-tblgen -gen-op-defs ../include/lambdapure/Ops.td -I $BUILD_DIR/../mlir/include/

```
### lambdapure generation


```
set_option trace.compiler.lambda_pure true

set_option trace.compiler.ir.init true
```
