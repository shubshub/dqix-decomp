#include <globaldefs.h>

struct Struct_0205bd58 {
    char unk0[0x34];
    int f34;
    char unknown_38_[0x4];
    int f3c;
    int f40;
    int unknown_44_;
    int unknown_48_;
};

// USA: func_0205bd58
extern "C" ARM void func_0205bd58(struct Struct_0205bd58* s, int a, int b, int c, int d, int e) {
    s->f34 = a;
    s->f3c = b;
    s->f40 = c;
    s->unknown_44_ = d;
    s->unknown_48_ = e;
}
