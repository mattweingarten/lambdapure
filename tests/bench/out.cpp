
#include "runtime/lean.h"
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
void lean_initialize_runtime_module();

lean_object* fold_dot__main( lean_object* arg0){
int x_2 = lean_obj_tag(arg0);
switch(x_2){
case 0:
{
return arg0;
}
case 1:
{
if(lean_is_exclusive(arg0)){
lean_object* x_6 = lean_ctor_get(arg0, 0);
lean_object* x_7 = lean_ctor_get(arg0, 1);
lean_object* x_8 = fold_dot__main(x_7);
lean_object* x_9 = arg0;
lean_ctor_set(x_9, 0, x_6);
lean_ctor_set(x_9, 1, x_8);
lean_dec(x_6);
return x_9;
}else{
lean_object* x_14 = lean_ctor_get(arg0, 0);
lean_object* x_15 = lean_ctor_get(arg0, 1);
lean_inc(x_15);
lean_object* x_17 = fold_dot__main(x_15);
lean_inc(x_14);
lean_inc(x_17);
lean_object* x_20 = lean_alloc_ctor(1,2,0);
lean_ctor_set(x_20, 0, x_14);
lean_ctor_set(x_20, 1, x_17);
lean_inc(x_20);
lean_dec(arg0);
return x_20;
}
}
default:
{
if(lean_is_exclusive(arg0)){
lean_object* x_27 = lean_ctor_get(arg0, 0);
lean_object* x_28 = lean_ctor_get(arg0, 1);
lean_object* x_29 = lean_ctor_get(arg0, 2);
lean_object* x_30 = lean_nat_add(x_27, x_28);
lean_object* x_31 = fold_dot__main(x_29);
lean_object* x_32 = arg0;
lean_ctor_set(x_32, 0, x_30);
lean_ctor_set(x_32, 1, x_31);
return x_32;
}else{
lean_object* x_36 = lean_ctor_get(arg0, 0);
lean_object* x_37 = lean_ctor_get(arg0, 1);
lean_object* x_38 = lean_ctor_get(arg0, 2);
lean_inc(x_36);
lean_inc(x_37);
lean_object* x_41 = lean_nat_add(x_36, x_37);
lean_inc(x_38);
lean_object* x_43 = fold_dot__main(x_38);
lean_inc(x_41);
lean_inc(x_43);
lean_object* x_46 = lean_alloc_ctor(1,2,0);
lean_ctor_set(x_46, 0, x_41);
lean_ctor_set(x_46, 1, x_43);
lean_inc(x_46);
lean_dec(arg0);
return x_46;
}
}
}
}
lean_object* fold( lean_object* arg0){
lean_object* x_53 = fold_dot__main(arg0);
lean_inc(x_53);
return x_53;
}

int main(int argc, char ** argv) {
lean_object* in; lean_object* res;
lean_initialize_runtime_module();
in = lean_box(0);
int i = argc;
while (i > 1) {
 lean_object* n;
 i--;
 n = lean_alloc_ctor(1,2,0); lean_ctor_set(n, 0, lean_mk_string(argv[i])); lean_ctor_set(n, 1, in);
 in = n;
}
//res = _lean_main(in, lean_io_mk_world());
return 0;
}



#ifdef __cplusplus
}
#endif

