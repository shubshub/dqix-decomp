#include <globaldefs.h>

extern "C" void func_020dd7ac(void*);
extern "C" void func_020dd8b4(int, int, int, int);

struct Struct_ov023_021dbc58 {
    char pad0[0x3e];
    unsigned short unknown_3e_;
    char unknown_40_[0x42 - 0x40];
    unsigned short unknown_42_;
    char unknown_44_[0x48 - 0x44];
    int unknown_48_;
    char unknown_4c_[0x50 - 0x4c];
    int unknown_50_;
    char unknown_54_[0x58 - 0x54];
    int unknown_58_;
    char unknown_5c_[0x66 - 0x5c];
    unsigned short unknown_66_;
    char pad68[0x6a - 0x68];
    unsigned short unknown_6a_;
    char pad6c[0x6e - 0x6c];
    unsigned short unknown_6e_;
    char unknown_70_[0x72 - 0x70];
    unsigned short unknown_72_;
    char unknown_74_[0x76 - 0x74];
    unsigned short unknown_76_;
    char unknown_78_[0x7a - 0x78];
    unsigned short unknown_7a_;
};

struct Struct_ov023_021dbc58_2 {
    float f0;
    float f4;
    int f8;
    int fc;
    int f10;
    int f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float unknown_2c_;
};

// USA: func_ov023_021dbc58
extern "C" ARM void func_ov023_021dbc58(void* obj, Struct_ov023_021dbc58_2* dest, int flagC) {
    Struct_ov023_021dbc58 raw;
    func_020dd7ac(&raw);
    func_020dd8b4((int)&raw, (int)obj, flagC, 1);

    dest->f0 = raw.unknown_3e_;
    dest->f4 = raw.unknown_42_;
    dest->f8 = raw.unknown_48_;
    dest->fc = raw.unknown_50_;
    dest->f10 = raw.unknown_58_;
    dest->f14 = 0;
    dest->f18 = raw.unknown_66_;
    dest->f1c = raw.unknown_6a_;
    dest->f20 = raw.unknown_6e_;
    dest->f24 = raw.unknown_72_;
    dest->f28 = raw.unknown_76_;
    dest->unknown_2c_ = raw.unknown_7a_;
}
