#include <globaldefs.h>

#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_020830cc_2128 = 0x7b8 };
#else
enum { Enum_020830cc_2128 = 0x850 };
#endif

struct Struct_02082fa8 { unsigned int unknown_0_, unknown_4_, unknown_8_; };

struct Struct_02082cdc_2 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_020830cc_2 {
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
    unsigned char unknown_140_[0xc];
    struct Struct_02082cdc_2 unknown_14c_[5];
    unsigned char unknown_160_[0x1c];
    unsigned char unknown_17c_[0xc0];
};

struct Struct_020830cc {
    struct Struct_02082cdc_2 unknown_0_[4];
    unsigned char unknown_10_[0x8];
    unsigned int unknown_18_;
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
    unsigned char unknown_20_[0x1c];
    char unknown_3c_[0x30];
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

// USA: func_020830cc
extern "C" ARM void func_020830cc(struct Struct_020830cc* arg0, struct Struct_020830cc_2* arg1) {
    arg1->unknown_1_0_ = arg0->unknown_56a_;
    unsigned int var0 = arg0->unknown_950_;
    arg1->unknown_54_ |= 1 << var0;
    arg1->unknown_50_ = var0;
    arg1->unknown_54_ = arg0->unknown_954_;
    for (int var1 = 0; var1 < 13; var1++) {
        arg1->unknown_2_[var1] = arg0->unknown_16c_[var1];
        arg1->unknown_f_[var1] = arg0->unknown_186_[var1];
        arg1->unknown_1c_[var1] = arg0->unknown_138_[var1];
    }
    for (int var2 = 0; var2 < 13; var2++) {
        func_02082fa8(&arg1->unknown_58_[var2], &arg0->unknown_850_[var2]);
    }
    arg1->unknown_f4_ = arg0->unknown_564_;
    for (int var3 = 0; var3 < 27; var3++) {
        arg1->unknown_f6_[var3] = arg0->unknown_464_[var3];
    }
    memcpy(arg1->unknown_111_, arg0->unknown_910_, 9);
    memcpy(arg1->unknown_11a_, arg0->unknown_8ec_, 0x24);
    unsigned int var4 = arg0->unknown_18_;
    unsigned char* var5 = &arg1->unknown_13e_;
    if (var4 & 1) {
        *var5 |= 1;
    }
    if (var4 & 2) {
        *var5 |= 2;
    }
    if (var4 & 4) {
        *var5 |= 4;
    }
#if defined(jpn)
    memcpy(arg1->unknown_140_, arg0->unknown_3c_, 0xc);
#else
    char local[0xc];
    __clear(local, 0xc);
    Font_EncodeText(src->name3c, local, 1);
    memcpy(dst->b140, local, 0xc);
#endif
    arg1->unknown_1_4_ = (unsigned short)arg0->unknown_7b_6_;
    struct Struct_02082cdc_2* var7 = arg1->unknown_14c_;
    var7[0].unknown_0_0_ = arg0->unknown_0_[0].unknown_0_0_;
    var7[0].unknown_1_2_ = arg0->unknown_0_[0].unknown_1_2_;
    var7[0].unknown_2_4_ = arg0->unknown_0_[0].unknown_2_4_;
    var7[1].unknown_0_0_ = arg0->unknown_0_[1].unknown_0_0_;
    var7[1].unknown_1_2_ = arg0->unknown_0_[1].unknown_1_2_;
    var7[1].unknown_2_4_ = arg0->unknown_0_[1].unknown_2_4_;
    var7[2].unknown_0_0_ = arg0->unknown_0_[2].unknown_0_0_;
    var7[2].unknown_1_2_ = arg0->unknown_1c_;
    var7[2].unknown_2_4_ = arg0->unknown_1e_;
    var7[3].unknown_0_0_ = arg0->unknown_6c_;
    var7[3].unknown_1_2_ = arg0->unknown_6e_;
    var7[3].unknown_2_4_ = arg0->unknown_70_;
    var7[4].unknown_0_0_ = arg0->unknown_72_;
    var7[4].unknown_1_2_ = arg0->unknown_0_[3].unknown_0_0_;
    memcpy(arg1->unknown_160_, arg0->unknown_488_, 0x1c);
    arg1->unknown_1_5_ = arg0->unknown_56b_0_;
    arg1->unknown_13f_0_ = arg0->unknown_56b_4_;
    memcpy(arg1->unknown_17c_, arg0->unknown_4a4_, 0xc0);
    arg1->unknown_13f_3_ = arg0->unknown_94c_;
}
