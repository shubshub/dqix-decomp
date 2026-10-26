#include <globaldefs.h>

struct Struct_020d507c {
    unsigned char pad0[0x4];
    unsigned short f4;
    unsigned char pad1[0x12];
    unsigned short f18;
    unsigned char pad2[0x18];
    unsigned short unknown_32_;
};

// USA: func_020d5158
extern "C" ARM int func_020d5158(struct Struct_020d507c* o) {
    if (o->f4 > 0x70) return 0;
    if (o->f18 < 0xa || o->f18 > 0x3e8) return 0;
    if (o->unknown_32_ < 1) goto ret0;
    if (o->unknown_32_ <= 0xe) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
