#include <globaldefs.h>
struct Struct_ov024_021ea4d0;

struct Struct_ov024_021ea4d0_2 { int pad0[5]; unsigned int f14; int pad1[1]; unsigned int f1c; };

// USA: func_ov024_021ea4d0
extern "C" ARM int func_ov024_021ea4d0(Struct_ov024_021ea4d0* a0, Struct_ov024_021ea4d0_2* obj) {
    unsigned int t = obj->f14 >> 0x1c;
    if (t != 4 && t != 3) goto ret0;
    {
        unsigned int v = obj->f1c;
        v = (v << 0xd) >> 0x1b;
        if (v == 0) return 1;
    }
ret0:
    return 0;
}
