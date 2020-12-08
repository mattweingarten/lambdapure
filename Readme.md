# Github for bachelor thesis
## A single-static-assignment intermediate representation for a pure functional language



#List of commands
export BUILD_DIR=/mnt/c/Users/Matthew/Desktop/llvm-project/build/

  cmake  .. -DMLIR_DIR=$BUILD_DIR/lib/cmake/mlir \
  -DLLVM_EXTERNAL_LIT=$BUILD_DIR/bin/llvm-lit \

cmake --build .

##to view tblgen (from build)

$BUILD_DIR/bin/mlir-tblgen -gen-op-defs ../include/lambdapure/Ops.td -I $BUILD_DIR/../mlir/include/


#lambdapure generation



set_option trace.compiler.lambda_pure true

set_option trace.compiler.ir.init true


lean_object* closure = lean_alloc_closure((void*)(add_one),1,0);
lean_object* list = map(closure,make(lean_box(30000)));

lean_object* closure = lean_alloc_closure((void*)(add_one),1,0);
lean_object* list = map(closure,make(lean_box(30000)));


lean_object* ret_obj = sum(list);
int ret_value = lean_unbox(ret_obj);
printf("%d\n",ret_value );
