#include <globaldefs.h>

struct Struct_ov016_0219d1c0 { unsigned char pad[0x8]; int f8; unsigned char pad2[0x8]; int f14; int f18; };
extern struct Struct_ov016_0219d1c0 data_ov016_0219d1c0;

// USA: func_ov016_0218fc8c
extern "C" ARM void func_ov016_0218fc8c(void* a, unsigned int b) {
    data_ov016_0219d1c0.f18 = (int)a;
    data_ov016_0219d1c0.f14 = (int)(b & ~3u);
    data_ov016_0219d1c0.f8 = 0;
}
