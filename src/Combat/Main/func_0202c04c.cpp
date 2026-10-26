#include <globaldefs.h>

extern "C" int func_020d4ac8(void);

struct Struct_0202c04c_3 {
    int seq;
    int reset;
};

inline Struct_0202c04c_3& inline_0202c04c() {
    static Struct_0202c04c_3 s;
    return s;
}

struct Struct_0202c04c {
    unsigned short type : 3;
    unsigned short state : 2;
    unsigned short actor : 3;
    unsigned short pad0 : 8;
    unsigned short pad1 : 5;
    unsigned short unknown_2_5_ : 2;
    unsigned short slotB : 2;
    unsigned short unknown_3_1_ : 2;
};

struct Struct_0202c04c_2 {
    char pad000[8];
    int unknown_8_;
    char unknown_c_[0x7b4];
    Struct_0202c04c flags;
    char unknown_7c4_[0x7fc];
    int unknown_fc0_;
    char unknown_fc4_[0x40];
    int actorId;
    int unknown_1008_;
    char unknown_100c_[0x2c];
    char unknown_1038_;
    signed char unknown_1039_;
    signed char slotB;
    signed char unknown_103b_;
};

// USA: func_0202c04c
extern "C" ARM void func_0202c04c(Struct_0202c04c_2* turn) {
    if (turn->unknown_fc0_ != 0) {
        return;
    }
    turn->flags.type = 1;
    inline_0202c04c().seq++;
    turn->flags.actor = (unsigned short)turn->actorId;
    Struct_0202c04c* flags = &turn->flags;
    turn->flags.state = (unsigned short)func_020d4ac8();

    int pending = turn->unknown_1008_;
    if (pending != -1) {
        flags->actor = (unsigned short)pending;
        turn->unknown_1008_ = -1;
    }

    int var2 = turn->unknown_8_;
    if (var2 != 0) {
        if (var2 > 0) {
            turn->unknown_8_ = 1 - var2;
        } else {
            turn->unknown_8_ = -1 - var2;
        }
    }

    flags->unknown_2_5_ = turn->unknown_1039_;
    flags->slotB = turn->slotB;
    flags->unknown_3_1_ = turn->unknown_103b_;
}
