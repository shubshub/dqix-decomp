#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);

struct Struct_ov023_021fbc68 { unsigned int v[3]; };

// USA: func_ov023_021fbc68
extern "C" ARM void func_ov023_021fbc68(void* dst, void* src) {
    struct Struct_ov023_021fbc68 t;
    __clear(&t, 0xc);
    t.v[0] = *(unsigned short*)((char*)src + 0x32) << 0xc;
    t.v[1] = *(unsigned short*)((char*)src + 0x34) << 0xc;
    *(struct Struct_ov023_021fbc68*)dst = t;
}
