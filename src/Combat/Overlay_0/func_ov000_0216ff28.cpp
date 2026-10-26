#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0203c0cc {
#if defined(jpn)
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    int unknown_2c_;
    unsigned int unknown_30_0_ : 16;
    unsigned int unknown_32_0_ : 8;
    unsigned int unknown_33_0_ : 8;
    int unknown_34_;
#else
    int unknown1_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    short unknown1_14_;
#endif
};

void CachedTextLabel_Init(struct State0xc0cc* obj);

struct Struct_020200c0 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 1;
    unsigned char unknown_1c_1_ : 7;
    char unknown_1d_[0x28 - 0x1d];
};

extern "C" void func_ov000_0216fe9c(struct Struct_020200c0* arg0);

struct Struct_ov000_0215ab88 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_020200c0 unknown_8_;
    int unknown_30_;
    int unknown_34_;
    int unknown_38_;
    int unknown_3c_;
    int unknown_40_;
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
    struct Struct_0203c0cc unknown_50_;
    struct Struct_0203c0cc unknown_68_;
    short unknown_80_;
    short unknown_82_;
    char unknown_84_[2];
    unsigned char unknown_86_;
    unsigned char unknown_87_;
    unsigned char unknown_88_[0x13];
    int unknown_9c_[0x42];
    int unknown_1a4_[0x93];
    int unknown_3f0_[0x10];
    short unknown_430_;
    short unknown_432_;
    int unknown_434_;
    int unknown_438_;
    unsigned char unknown_43c_;
    signed char unknown_43d_;
    unsigned char unknown_43e_;
    unsigned char unknown_43f_;
    unsigned char unknown_440_;
    unsigned char unknown_441_;
    signed char unknown_442_;
    unsigned char unknown_443_;
    unsigned char unknown_444_;
    unsigned char unknown_445_;
};

// USA: func_ov000_0216ff28
extern "C" ARM void func_ov000_0216ff28(struct Combatant* obj) {
    int i;
    obj->unk0 = 0;
    obj->unk4 = 0;
    func_ov000_0216fe9c(&obj->status);
    obj->unk87 = 0;
    obj->unk30 = 0;
    obj->unk38 = 0;
    obj->unk3c = 0;
    obj->unk40 = 0;
    obj->unk48 = 0;
    obj->unk44 = 0;
    obj->unk4c = -1;
    obj->unk82 = 0;
    obj->unk86 = 0;
    obj->unk80 = 0x7fff;
    obj->unk438 = 0;
    obj->unk43c = 0;
    obj->unk430 = 0x7fff;
    obj->unk432 = 0x7fff;
    obj->unk434 = 0;
    obj->unk43d = -1;
    obj->unk43e = 0;
    obj->unk440 = 0;
    obj->unk43f = 0;
    obj->unk441 = 0;
    obj->unk442 = -1;
    obj->unk443 = 5;
    obj->unk444 = 0;
    obj->unk445 = 1;
    CachedTextLabel_Init(&obj->unk68);
    CachedTextLabel_Init(&obj->unk50);
    memset(obj->unk88, 0, sizeof(obj->unk88));
    for (i = 0; i < 0x42; i++) {
        obj->unk9c[i] = 0;
    }
    for (var0 = 0; var0 < 0x93; var0++) {
        arg0->unknown_1a4_[var0] = 0;
    }
    for (var0 = 0; var0 < 0x10; var0++) {
        arg0->unknown_3f0_[var0] = 0;
    }
    arg0->unknown_8_.unknown_1c_0_ = 0;
}
