#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);

struct Struct_ov023_021fc4b4 { unsigned int v[3]; };

// USA: func_ov023_021fc4b4
extern "C" ARM void func_ov023_021fc4b4(void* dst, void* src) {
    struct Struct_ov023_021fc4b4 t;
    __clear(&t, 0xc);
    t.v[0] = *(unsigned short*)((char*)src + 0x26) << 0xc;
    t.v[1] = *(unsigned short*)((char*)src + 0x28) << 0xc;
    *(struct Struct_ov023_021fc4b4*)dst = t;
}
