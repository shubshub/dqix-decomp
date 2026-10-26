#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_0209a218 { unsigned char unknown_0_[8]; };

struct Struct_0209a104_3 {
    unsigned int a : 5;
    unsigned int b : 7;
    unsigned int c : 8;
    unsigned int d : 5;
    unsigned int e : 7;
};
union Struct_0209a104 { struct Struct_0209a104_3 b; unsigned int raw; };
struct Struct_0209a104_2 {
    unsigned short id : 11;
    unsigned short slot : 5;
    unsigned short f2;
    union Struct_0209a104 u;
    unsigned short f8;
    unsigned short fa;
};

struct Struct_0209a55c;
extern "C" void func_0209a55c(struct Struct_0209a55c* list, struct Struct_0209a104_2* src);

extern struct Struct_0209a55c* data_02109ba4;

static inline int inline_0209a218(const struct Struct_0209a218* p) { return ((Script::Parameter*)p)->ToInt(); }

// USA: func_0209a218
extern "C" ARM int func_0209a218(struct Struct_0209a218* args) {
    struct Struct_0209a104_2 rec;
    unsigned int v;

    rec.id = inline_0209a218(&args[0]);
    rec.u.b.a = inline_0209a218(&args[1]);
    rec.u.b.b = inline_0209a218(&args[2]);
    rec.f2 = inline_0209a218(&args[3]);
    rec.slot = inline_0209a218(&args[4]);
    v = inline_0209a218(&args[5]);
    rec.u.raw &= ~0xff000u;
    rec.u.raw |= (v & 0xff) << 12;
    rec.f8 = inline_0209a218(&args[6]);
    rec.fa = inline_0209a218(&args[7]);
    v = inline_0209a218(&args[8]);
    rec.u.raw &= ~0x1f00000u;
    rec.u.raw |= (v & 0x1f) << 20;
    rec.u.b.e = 0;

    if (rec.u.b.c != 0) {
        func_0209a55c(data_02109ba4, &rec);
    }
    return 1;
}
