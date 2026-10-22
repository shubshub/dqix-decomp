#include <globaldefs.h>

#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_02082d6c_2128 = 0x7b8 };
#else
enum { Enum_02082d6c_2128 = 0x850 };
#endif

struct Struct_02082fa8 { unsigned int unknown_0_, unknown_4_, unknown_8_; };

struct Struct_02082cdc_2 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
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
    unsigned char unknown_140_[0x14];
    struct Struct_02082cdc_2 unknown_154_;
    unsigned char unknown_158_[8];
    unsigned char unknown_160_[0x1c];
    unsigned char unknown_17c_[0xc0];
};

struct Struct_02082d6c {
    unsigned char unknown_0_[0x18];
    unsigned int unknown_18_;
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
    unsigned char unknown_20_[0x1c];
    char unknown_3c_[0x3c];
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
extern "C" void func_02042764(void*, void*, int);
extern char g_stringFormat[];

// USA: func_02082d6c
extern "C" ARM void func_02082d6c(struct Struct_02082d6c* arg0, struct Struct_02082d6c_2* arg1) {
    if (arg1 == NULL) {
        return;
    }
    func_02082828(arg0);
    arg0->unknown_56a_ = arg1->unknown_1_0_;
    arg0->unknown_950_ = arg1->unknown_50_;
    arg0->unknown_954_ = arg1->unknown_54_;
    for (int var0 = 0; var0 < 13; var0++) {
        arg0->unknown_16c_[var0] = arg1->unknown_2_[var0];
        arg0->unknown_186_[var0] = arg1->unknown_f_[var0];
        arg0->unknown_138_[var0] = arg1->unknown_1c_[var0];
    }
    func_02082fc4(arg0, NULL);
    for (int var1 = 0; var1 < 13; var1++) {
        func_02082fa8(&arg0->unknown_850_[var1], &arg1->unknown_58_[var1]);
    }
    arg0->unknown_564_ = arg1->unknown_f4_;
    for (int var2 = 0; var2 < 27; var2++) {
        arg0->unknown_464_[var2] = arg1->unknown_f6_[var2];
    }
    memcpy(arg0->unknown_910_, arg1->unknown_111_, 9);
    memcpy(arg0->unknown_8ec_, arg1->unknown_11a_, 0x24);
    unsigned char var3 = arg1->unknown_13e_;
    if (var3 & 1) {
        arg0->unknown_18_ |= 1;
    }
    if (var3 & 2) {
        arg0->unknown_18_ |= 2;
    }
    if (var3 & 4) {
        arg0->unknown_18_ |= 4;
    }
#if defined(jpn)
    sprintf(dst->name3c, g_stringFormat, src->b140);
#else
    char local[0x30];
    __clear(local, 0x30);
    func_02042764(src->b140, local, 1);
    sprintf(dst->name3c, g_stringFormat, local);
#endif
    arg0->unknown_7b_6_ = arg1->unknown_1_4_;
    arg0->unknown_1c_ = arg1->unknown_154_.unknown_1_2_;
    arg0->unknown_1e_ = arg1->unknown_154_.unknown_2_4_;
    memcpy(arg0->unknown_488_, arg1->unknown_160_, 0x1c);
    arg0->unknown_56b_0_ = arg1->unknown_1_5_;
    arg0->unknown_56b_4_ = arg1->unknown_13f_0_;
    memcpy(arg0->unknown_4a4_, arg1->unknown_17c_, 0xc0);
    arg0->unknown_94c_ = arg1->unknown_13f_3_;
}
