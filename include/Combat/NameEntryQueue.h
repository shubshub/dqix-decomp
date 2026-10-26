#ifndef COMBAT_NAME_ENTRY_QUEUE_H
#define COMBAT_NAME_ENTRY_QUEUE_H

struct Struct_ov017_02195214 {
    unsigned char v[12];
};

struct Struct_ov017_021941fc {
    unsigned char a;
    unsigned char b;
    Struct_ov017_02195214 unknown_2_;
    unsigned char e;
};

extern "C" void func_ov017_02195214(Struct_ov017_021941fc *dst, Struct_ov017_021941fc *src);

struct Struct_ov017_02195250 {
    unsigned char state;
    unsigned char mode;
    Struct_ov017_021941fc entry;
};

struct Struct_ov017_02195250_2 {
#if defined(jpn)
    unsigned char unknown0[0x40d0];
#else
    unsigned char unknown0[0x42f0];
#endif
    unsigned char count;
    Struct_ov017_021941fc entries[3];
    unsigned char unknown_431e_;
#if defined(jpn)
    unsigned char unknown_40ff_[0x416c - 0x40ff];
#else
    unsigned char unknown_431f_[0x441c - 0x431f];
#endif
    Struct_ov017_02195250 *active;
};

#endif
