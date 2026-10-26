#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);

struct Struct_ov023_021f81f4_2 { int x; int y; int z; };

struct Struct_ov023_021f81f4 {
    char pad[0x100];
    unsigned short unknown_100_;
    unsigned short unknown_102_;
};

// USA: func_ov023_021f81f4
extern "C" ARM void func_ov023_021f81f4(struct Struct_ov023_021f81f4_2* out, struct Struct_ov023_021f81f4* src) {
    int tmp[3];
    __clear(tmp, 0xc);
    tmp[0] = src->unknown_100_ << 0xc;
    tmp[1] = src->unknown_102_ << 0xc;
    *(int(*)[3])out = *(int(*)[3])tmp;
}
