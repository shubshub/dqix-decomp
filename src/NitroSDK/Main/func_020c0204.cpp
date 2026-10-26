#include <globaldefs.h>

struct Struct_020bc180_2 { int f0; int f4; int f8; int fc; };

extern "C" int func_020c022c(struct Struct_020bc180_2* t);

// USA: func_020c0204
extern "C" ARM void func_020c0204(struct Struct_020bc180_2* t, int end, int duration) {
    t->f0 = func_020c022c(t);
    t->f4 = end;
    t->fc = duration;
    t->f8 = 0;
}
