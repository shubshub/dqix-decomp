#include <globaldefs.h>

struct Struct_ov001_0215a674 { int type; char pad[0xc]; int f10; int f14; };
extern "C" struct Struct_ov001_0215a674* func_ov001_0215a054(void*);

// USA: func_ov001_0215a674
extern "C" ARM void func_ov001_0215a674(void* self, int a1, int a2) {
    struct Struct_ov001_0215a674* n = func_ov001_0215a054(self);
    if (n != NULL) {
        n->type = 0x16;
        n->f10 = a1;
        n->f14 = a2;
    }
}
