#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_0209a104_3 {
    unsigned int a : 5;
    unsigned int b : 7;
    unsigned int c : 8;
    unsigned int d : 5;
    unsigned int e : 7;
};
union Struct_0209a104 { struct Struct_0209a104_3 b; unsigned int raw; unsigned int unknown2_0_; };
struct Struct_0209a104_2 {
    unsigned short id : 11;
    unsigned short slot : 5;
    unsigned short f2;
    union Struct_0209a104 u;
    unsigned short f8;
    unsigned short fa;
};

struct Struct_0209a4f0;
extern "C" void func_0209a4f0(struct Struct_0209a4f0* list, struct Struct_0209a104_2* src);

extern struct Struct_0209a4f0* data_02109ba4;

static inline int inline_0209a104(char* p, int off) { struct Variant02030b0c* q = (struct Variant02030b0c*)(p + off); int r = ((Script::Parameter*)q)->ToInt(); return r; }

// USA: func_0209a104
extern "C" ARM int func_0209a104(char* v) {
    struct Struct_0209a104_2 rec;
    unsigned int var1;

    rec.id = inline_0209a104(v, 0);
    rec.u.b.a = inline_0209a104(v, 8);
    rec.u.b.b = inline_0209a104(v, 0x10);
    rec.f2 = inline_0209a104(v, 0x18);
    rec.slot = inline_0209a104(v, 0x20);
    var1 = (unsigned int)inline_0209a104(v, 0x28); var1 <<= 24; rec.u.raw &= ~0xff000u; rec.u.raw |= var1 >> 12;
    rec.f8 = inline_0209a104(v, 0x30);
    rec.fa = inline_0209a104(v, 0x38);
    var1 = (unsigned int)inline_0209a104(v, 0x40) << 27; rec.u.raw &= ~0x1f00000u; rec.u.raw |= var1 >> 7;
    rec.u.unknown2_0_ = rec.u.raw & 0x01ffffffu;

    func_0209a4f0(data_02109ba4, &rec);
    return 1;
}
