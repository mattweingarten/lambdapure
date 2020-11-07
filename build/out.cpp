
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

lean_object* L_dot_Inhabited( ){
lean_object* x_2 = lean_alloc_ctor(0,0,0);
return x_2;
}
lean_object* map_dot__main( lean_object* arg0, lean_object* arg1){
int x_5 = lean_obj_tag(arg1);
switch(x_5){
case 0:
{
return arg1;
}
default:
{
lean_object* x_8 = lean_ctor_get(arg1, 0);
lean_object* x_9 = lean_ctor_get(arg1, 1);
lean_object* x_10 = lean_apply_1(arg0, x_8);
lean_object* x_11 = map_dot__main(arg0, x_9);
lean_object* x_12 = lean_alloc_ctor(1,2,0);
lean_ctor_set(x_12, 0, x_10);
lean_ctor_set(x_12, 1, x_11);
return x_12;
}
}
}
lean_object* map( lean_object* arg0, lean_object* arg1){
lean_object* x_17 = map_dot__main(arg0, arg1);
return x_17;
}
lean_object* add_one( lean_object* arg0){
lean_object* x_20 = lean_box(1);
lean_object* x_21 = lean_nat_add(arg0, x_20);
return x_21;
}
lean_object* make_prime__dot__main( lean_object* arg0, lean_object* arg1){
lean_object* x_24 = lean_box(0);
int x_25 = lean_nat_dec_eq(arg1, x_24);
switch(x_25){
case 0:
{
lean_object* x_27 = lean_nat_sub(arg0, arg1);
lean_object* x_28 = lean_box(1);
lean_object* x_29 = lean_nat_sub(arg1, x_28);
lean_object* x_30 = make_prime__dot__main(arg0, x_29);
lean_object* x_31 = lean_alloc_ctor(1,2,0);
lean_ctor_set(x_31, 0, x_27);
lean_ctor_set(x_31, 1, x_30);
return x_31;
}
default:
{
lean_object* x_35 = lean_alloc_ctor(0,0,0);
lean_object* x_36 = lean_alloc_ctor(1,2,0);
lean_ctor_set(x_36, 0, arg0);
lean_ctor_set(x_36, 1, x_35);
return x_36;
}
}
}
lean_object* make_prime_( lean_object* arg0, lean_object* arg1){
lean_object* x_41 = make_prime__dot__main(arg0, arg1);
return x_41;
}
lean_object* make( lean_object* arg0){
lean_object* x_44 = make_prime__dot__main(arg0, arg0);
return x_44;
}
lean_object* sum_dot__main( lean_object* arg0){
int x_47 = lean_obj_tag(arg0);
switch(x_47){
case 0:
{
lean_object* x_49 = lean_box(0);
return x_49;
}
default:
{
lean_object* x_51 = lean_ctor_get(arg0, 0);
lean_object* x_52 = lean_ctor_get(arg0, 1);
lean_object* x_53 = sum_dot__main(x_52);
lean_object* x_54 = lean_nat_add(x_51, x_53);
return x_54;
}
}
}
lean_object* sum( lean_object* arg0){
lean_object* x_57 = sum_dot__main(arg0);
return x_57;
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

