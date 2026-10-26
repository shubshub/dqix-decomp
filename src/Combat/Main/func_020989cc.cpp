#include <globaldefs.h>

struct Struct_020989cc {
    char pad[0xb38];
    unsigned int unknown_b38_;
    unsigned int unknown_b3c_;
    unsigned char unknown_b40_;
    unsigned char unknown_b41_;
};

struct Struct_02097cac_2 {
    char pad[0x1000];
    struct Struct_020989cc sub;
};

// USA: func_020989cc
extern "C" ARM void func_020989cc(struct Struct_02097cac_2* base) {
    unsigned int v;
    unsigned char rank;
    if (base->sub.unknown_b3c_ == 6) return;
    v = base->sub.unknown_b38_;
    if (v < 7) base->sub.unknown_b41_ = 1;
    else if (v >= 7 && v < 0xd) base->sub.unknown_b41_ = 2;
    else if (v >= 0xd && v < 0x13) base->sub.unknown_b41_ = 3;
    else if (v >= 0x13 && v < 0x19) base->sub.unknown_b41_ = 4;
    else if (v >= 0x19 && v < 0x1e) base->sub.unknown_b41_ = 5;
    else if (v >= 0x1e) base->sub.unknown_b41_ = 6;
    rank = base->sub.unknown_b41_;
    if (rank > base->sub.unknown_b3c_) base->sub.unknown_b3c_ = base->sub.unknown_b3c_ + 1;
}
