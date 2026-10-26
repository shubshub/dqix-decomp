#include <globaldefs.h>

struct Struct_020de3ac;
extern "C" int func_020de3ac(struct Struct_020de3ac* obj, int a, int unused, int b);

struct Struct_020de38c;
extern "C" int func_020de38c(struct Struct_020de38c* obj, int a, int b);

struct Struct_020de3cc;
extern "C" int func_020de3cc(struct Struct_020de3cc* obj, int a, int b, int c);

// USA: func_020de524
extern "C" ARM void func_020de524(int a, int b, void** out) {
    if (a == 999) {
        if (b == 999) {
            *out = 0;
        } else {
            *out = (void*)func_020de3ac;
        }
    } else {
        if (b == 999) {
            *out = (void*)func_020de38c;
        } else {
            *out = (void*)func_020de3cc;
        }
    }
}
