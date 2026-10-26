#include <globaldefs.h>

#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_020830cc_2128 = 0x7b8 };
#else
enum { Enum_020830cc_2128 = 0x850 };
#endif

struct Struct_02082fa8 { unsigned int a, b, c; };

struct Struct_02082cdc_2 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct SlotRecord020830cc {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 1;
    unsigned char unknown_1_5_ : 3;
    unsigned char unknown_2_[13];
    unsigned char unknown_f_[13];
    unsigned int unknown_1c_[13];
    unsigned int unknown_50_;
    unsigned short unknown_54_;
    unsigned char unknown_56_[2];
    struct Struct_02082fa8 unknown_58_[13];
    unsigned short unknown_f4_;
    unsigned char unknown_f6_[27];
    unsigned char unknown_111_[9];
    unsigned char unknown_11a_[0x24];
    unsigned char unknown_13e_;
    unsigned char unknown_13f_0_ : 3;
    unsigned char unknown_13f_3_ : 5;
    unsigned char b140[0xc];
    struct Struct_02082cdc_2 stats[5];
    unsigned char unknown_160_[0x1c];
    unsigned char unknown_17c_[0xc0];
};

struct SlotState020830cc {
    struct Struct_02082cdc_2 stats[4];
    unsigned char unknown_10_[0x8];
    unsigned int unknown_18_;
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
    unsigned char unknown_20_[0x1c];
    char name3c[0x30];
    unsigned short unknown_6c_;
    unsigned short unknown_6e_;
    unsigned short unknown_70_;
    unsigned short unknown_72_;
    unsigned char unknown_74_[4];
    unsigned int unknown_78_0_ : 30;
    unsigned int unknown_7b_6_ : 1;
    unsigned int unknown_7b_7_ : 1;
    unsigned char unknown_7c_[0x0c];
    unsigned char unknown_88_[0xb0];
    unsigned int unknown_138_[13];
    unsigned short unknown_16c_[13];
    unsigned char unknown_186_[13];
    unsigned char unknown_193_[0x2d1];
    unsigned char unknown_464_[27];
    unsigned char unknown_47f_[9];
    unsigned char unknown_488_[0x1c];
    unsigned char unknown_4a4_[0xc0];
    unsigned short unknown_564_;
    unsigned char unknown_566_[4];
    unsigned char unknown_56a_;
    unsigned char unknown_56b_0_ : 4;
    unsigned char unknown_56b_4_ : 4;
    unsigned char unknown_56c_[Enum_020830cc_2128 - 0x56c];
    struct Struct_02082fa8 unknown_850_[13];
    unsigned char unknown_8ec_[0x24];
    unsigned char unknown_910_[9];
    unsigned char unknown_919_[0x94c - 0x919];
    unsigned int unknown_94c_;
    unsigned int unknown_950_;
    unsigned short unknown_954_;
};

extern "C" void func_02082fa8(struct Struct_02082fa8*, struct Struct_02082fa8*);
extern "C" void __clear(void*, unsigned int);
extern "C" void Font_EncodeText(void*, char*, int);

// Main, originally func_020830cc (USA 0x020830cc, EUR 0x020830dc, JPN 0x02083a38)
extern "C" ARM void PartyMember_WriteRecord(struct SlotState020830cc* src, struct SlotRecord020830cc* dst) {
    dst->unknown_1_0_ = src->unknown_56a_;
    unsigned int bit = src->unknown_950_;
    dst->unknown_54_ |= 1 << bit;
    dst->unknown_50_ = bit;
    dst->unknown_54_ = src->unknown_954_;
    for (int i = 0; i < 13; i++) {
        dst->unknown_2_[i] = src->unknown_16c_[i];
        dst->unknown_f_[i] = src->unknown_186_[i];
        dst->unknown_1c_[i] = src->unknown_138_[i];
    }
    for (int i = 0; i < 13; i++) {
        func_02082fa8(&dst->unknown_58_[i], &src->unknown_850_[i]);
    }
    dst->unknown_f4_ = src->unknown_564_;
    for (int j = 0; j < 27; j++) {
        dst->unknown_f6_[j] = src->unknown_464_[j];
    }
    memcpy(dst->unknown_111_, src->unknown_910_, 9);
    memcpy(dst->unknown_11a_, src->unknown_8ec_, 0x24);
    unsigned int flags = src->unknown_18_;
    unsigned char* fp = &dst->unknown_13e_;
    if (flags & 1) {
        *fp |= 1;
    }
    if (flags & 2) {
        *fp |= 2;
    }
    if (flags & 4) {
        *fp |= 4;
    }
#if defined(jpn)
    memcpy(dst->b140, src->name3c, 0xc);
#else
    char local[0xc];
    __clear(local, 0xc);
    Font_EncodeText(src->name3c, local, 1);
    memcpy(dst->b140, local, 0xc);
#endif
    dst->unknown_1_4_ = (unsigned short)src->unknown_7b_6_;
    struct Struct_02082cdc_2* s = dst->stats;
    s[0].a = src->stats[0].a;
    s[0].b = src->stats[0].b;
    s[0].c = src->stats[0].c;
    s[1].a = src->stats[1].a;
    s[1].b = src->stats[1].b;
    s[1].c = src->stats[1].c;
    s[2].a = src->stats[2].a;
    s[2].b = src->unknown_1c_;
    s[2].c = src->unknown_1e_;
    s[3].a = src->unknown_6c_;
    s[3].b = src->unknown_6e_;
    s[3].c = src->unknown_70_;
    s[4].a = src->unknown_72_;
    s[4].b = src->stats[3].a;
    memcpy(dst->unknown_160_, src->unknown_488_, 0x1c);
    dst->unknown_1_5_ = src->unknown_56b_0_;
    dst->unknown_13f_0_ = src->unknown_56b_4_;
    memcpy(dst->unknown_17c_, src->unknown_4a4_, 0xc0);
    dst->unknown_13f_3_ = src->unknown_94c_;
}
