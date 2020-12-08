
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

lean_object* map( lean_object* arg0, lean_object* arg1){
int x_2 = lean_obj_tag(arg1);
switch(x_2){
case 0:
{
lean_dec(arg0);
return arg1;
}
default:
{
if(lean_is_exclusive(arg1)){
lean_object* x_7 = lean_ctor_get(arg1, 0);
lean_object* x_8 = lean_ctor_get(arg1, 1);
lean_object* x_9 = lean_apply_1(arg0, x_7);
lean_inc(arg0);
lean_object* x_11 = map_dot__main(arg0, x_8);
lean_object* x_12 = arg1;
lean_ctor_set(x_12, 0, x_9);
lean_ctor_set(x_12, 1, x_11);
return x_12;
}else{
lean_object* x_16 = lean_ctor_get(arg1, 0);
lean_object* x_17 = lean_ctor_get(arg1, 1);
lean_inc(x_16);
lean_object* x_19 = lean_apply_1(arg0, x_16);
lean_inc(arg0);
lean_inc(x_17);
lean_object* x_22 = map_dot__main(arg0, x_17);
lean_inc(x_19);
lean_inc(x_22);
lean_object* x_25 = lean_alloc_ctor(1,2,0);
lean_ctor_set(x_25, 0, x_19);
lean_ctor_set(x_25, 1, x_22);
lean_dec(arg1);
return x_25;
}
}
}
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

