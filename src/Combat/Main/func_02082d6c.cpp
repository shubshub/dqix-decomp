#include <globaldefs.h>

#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_02082d6c_2128 = 0x7b8 };
#else
enum { Enum_02082d6c_2128 = 0x850 };
#endif

struct Struct_02082fa8 { unsigned int a, b, c; };

struct Struct_02082cdc_2 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Struct_02082d6c_2 {
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
    unsigned char b140[0x14];
    struct Struct_02082cdc_2 unknown_154_;
    unsigned char unknown_158_[8];
    unsigned char unknown_160_[0x1c];
    unsigned char unknown_17c_[0xc0];
};

struct Struct_02082d6c {
    unsigned char pad000[0x18];
    unsigned int unknown_18_;
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
    unsigned char unknown_20_[0x1c];
    char name3c[0x3c];
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
    unsigned char unknown_56c_[Enum_02082d6c_2128 - 0x56c];
    struct Struct_02082fa8 unknown_850_[13];
    unsigned char unknown_8ec_[0x24];
    unsigned char unknown_910_[9];
    unsigned char unknown_919_[0x94c - 0x919];
    unsigned int unknown_94c_;
    unsigned int unknown_950_;
    unsigned short unknown_954_;
};

extern "C" void func_02082828(struct Struct_02082d6c*);
extern "C" void func_02082fc4(void*, void*);
extern "C" void func_02082fa8(struct Struct_02082fa8*, struct Struct_02082fa8*);
extern "C" void __clear(void*, unsigned int);
extern "C" void Font_DecodeText(void*, void*, int);
extern char g_stringFormat[];

// USA: func_02082d6c
extern "C" ARM void func_02082d6c(struct Struct_02082d6c* dst, struct Struct_02082d6c_2* src) {
    if (src == NULL) {
        return;
    }
    func_02082828(dst);
    dst->unknown_56a_ = src->unknown_1_0_;
    dst->unknown_950_ = src->unknown_50_;
    dst->unknown_954_ = src->unknown_54_;
    for (int i = 0; i < 13; i++) {
        dst->unknown_16c_[i] = src->unknown_2_[i];
        dst->unknown_186_[i] = src->unknown_f_[i];
        dst->unknown_138_[i] = src->unknown_1c_[i];
    }
    func_02082fc4(dst, NULL);
    for (int i = 0; i < 13; i++) {
        func_02082fa8(&dst->unknown_850_[i], &src->unknown_58_[i]);
    }
    dst->unknown_564_ = src->unknown_f4_;
    for (int j = 0; j < 27; j++) {
        dst->unknown_464_[j] = src->unknown_f6_[j];
    }
    memcpy(dst->unknown_910_, src->unknown_111_, 9);
    memcpy(dst->unknown_8ec_, src->unknown_11a_, 0x24);
    unsigned char flags = src->unknown_13e_;
    if (flags & 1) {
        dst->unknown_18_ |= 1;
    }
    if (flags & 2) {
        dst->unknown_18_ |= 2;
    }
    if (flags & 4) {
        dst->unknown_18_ |= 4;
    }
#if defined(jpn)
    sprintf(dst->name3c, g_stringFormat, src->b140);
#else
    char local[0x30];
    __clear(local, 0x30);
    Font_DecodeText(src->b140, local, 1);
    sprintf(dst->name3c, g_stringFormat, local);
#endif
    dst->unknown_7b_6_ = src->unknown_1_4_;
    dst->unknown_1c_ = src->unknown_154_.b;
    dst->unknown_1e_ = src->unknown_154_.c;
    memcpy(dst->unknown_488_, src->unknown_160_, 0x1c);
    dst->unknown_56b_0_ = src->unknown_1_5_;
    dst->unknown_56b_4_ = src->unknown_13f_0_;
    memcpy(dst->unknown_4a4_, src->unknown_17c_, 0xc0);
    dst->unknown_94c_ = src->unknown_13f_3_;
}
