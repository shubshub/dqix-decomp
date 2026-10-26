#include <globaldefs.h>

struct Struct_ov023_021f8198 { int f0; int f4; };
struct Struct_ov023_021f8198_2 {
    unsigned char pad0[0xcc];
    unsigned short fcc;
    unsigned short unknown_ce_;
    unsigned char pad1[0x100 - 0xd0];
    unsigned short unknown_100_;
    unsigned short unknown_102_;
};

// USA: func_ov023_021f8198
extern "C" ARM void func_ov023_021f8198(struct Struct_ov023_021f8198_2* a, struct Struct_ov023_021f8198* b) {
    a->unknown_100_ = (unsigned short)((float)b->f0 / 4096.0f);
    a->unknown_102_ = (unsigned short)((float)b->f4 / 4096.0f);
    unsigned short var0 = a->unknown_102_;
    unsigned short var1 = a->unknown_100_;
    a->fcc = var1;
    a->unknown_ce_ = var0;
}
