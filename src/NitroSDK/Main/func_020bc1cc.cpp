#include <globaldefs.h>

extern "C" int func_020d1ea0(int, int, int);

struct Struct_020bc1cc { char pad[0x3c]; unsigned char f3c; };
struct Struct_020bc1cc_2 { struct Struct_020bc1cc* f0; };

// USA: func_020bc1cc
extern "C" ARM void func_020bc1cc(struct Struct_020bc1cc_2* p, int arg1, int arg2) {
    if (*(int*)p != 0) {
        func_020d1ea0(p->f0->f3c, arg1, arg2);
    }
}
