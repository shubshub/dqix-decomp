#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);

struct Struct_ov023_021fd3d8 { unsigned int v[3]; };

// USA: func_ov023_021fd3d8
extern "C" ARM void func_ov023_021fd3d8(void* dst, void* src) {
    struct Struct_ov023_021fd3d8 t;
    __clear(&t, 0xc);
    t.v[0] = *(unsigned short*)((char*)src + 0x22) << 0xc;
    t.v[1] = *(unsigned short*)((char*)src + 0x24) << 0xc;
    *(struct Struct_ov023_021fd3d8*)dst = t;
}
