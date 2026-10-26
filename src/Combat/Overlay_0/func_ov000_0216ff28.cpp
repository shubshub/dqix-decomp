#include <globaldefs.h>
#include "std_library_functions.h"

struct State0xc0cc {
#if defined(jpn)
    char entries[0x14];
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
    int unk34;
#else
    int unk0;
    int unk4;
    int unknown_8_;
    int unknown_c_;
    int unk10;
    short unknown1_14_;
#endif
};

extern "C" void CachedTextLabel_Init(struct State0xc0cc* obj);

struct Struct_020200c0 {
    char unk0[0x1c];
    unsigned char active : 1;
    unsigned char unknown_1c_1_ : 7;
    char unknown_1d_[0x28 - 0x1d];
};

extern "C" void func_ov000_0216fe9c(struct Struct_020200c0* status);

struct Struct_ov000_0215ab88 {
    int unk0;
    int unk4;
    struct Struct_020200c0 status;
    int unk30;
    int unk34;
    int unknown_38_;
    int unk3c;
    int unknown_40_;
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
    struct State0xc0cc unk50;
    struct State0xc0cc unk68;
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
extern "C" ARM void func_ov000_0216ff28(struct Struct_ov000_0215ab88* obj) {
    int i;
    obj->unk0 = 0;
    obj->unk4 = 0;
    func_ov000_0216fe9c(&obj->status);
    obj->unknown_87_ = 0;
    obj->unk30 = 0;
    obj->unknown_38_ = 0;
    obj->unk3c = 0;
    obj->unknown_40_ = 0;
    obj->unknown_48_ = 0;
    obj->unknown_44_ = 0;
    obj->unknown_4c_ = -1;
    obj->unknown_82_ = 0;
    obj->unknown_86_ = 0;
    obj->unknown_80_ = 0x7fff;
    obj->unknown_438_ = 0;
    obj->unknown_43c_ = 0;
    obj->unknown_430_ = 0x7fff;
    obj->unknown_432_ = 0x7fff;
    obj->unknown_434_ = 0;
    obj->unknown_43d_ = -1;
    obj->unknown_43e_ = 0;
    obj->unknown_440_ = 0;
    obj->unknown_43f_ = 0;
    obj->unknown_441_ = 0;
    obj->unknown_442_ = -1;
    obj->unknown_443_ = 5;
    obj->unknown_444_ = 0;
    obj->unknown_445_ = 1;
    CachedTextLabel_Init(&obj->unk68);
    CachedTextLabel_Init(&obj->unk50);
    memset(obj->unknown_88_, 0, sizeof(obj->unknown_88_));
    for (i = 0; i < 0x42; i++) {
        obj->unknown_9c_[i] = 0;
    }
    for (i = 0; i < 0x93; i++) {
        obj->unknown_1a4_[i] = 0;
    }
    for (i = 0; i < 0x10; i++) {
        obj->unknown_3f0_[i] = 0;
    }
    obj->status.active = 0;
}
