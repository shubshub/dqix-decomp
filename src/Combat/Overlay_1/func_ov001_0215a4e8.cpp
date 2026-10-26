#include <globaldefs.h>

struct Struct_ov001_0215a4e8 { int type; char pad[0xc]; int f10; int f14; };
extern "C" struct Struct_ov001_0215a4e8* func_ov001_0215a054(void*);

// USA: func_ov001_0215a4e8
extern "C" ARM void func_ov001_0215a4e8(void* self, int a1, int a2) {
    struct Struct_ov001_0215a4e8* n = func_ov001_0215a054(self);
    if (n != NULL) {
        n->type = 0x13;
        n->f10 = a1;
        n->f14 = a2;
    }
}
