#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Memory.h"

struct Struct_020827c4 { char field_0x0[0x1c]; };
extern "C" void func_020827c4(Struct_020827c4*);

struct Struct_02098364 {
    char field_0x0[11];
    unsigned char mode : 7;
    unsigned char enabled : 1;
    unsigned int unknown_c_0_ : 4;
    unsigned int unknown_c_4_ : 4;
    unsigned int unknown_d_0_ : 7;
    unsigned int unknown_d_7_ : 4;
    unsigned int unknown_e_3_ : 5;
    unsigned int unknown_f_0_ : 6;
    unsigned int unknown_f_6_ : 1;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 2;
    unsigned int unknown_10_2_ : 30;
    char unknown_14_[6];
    Struct_020827c4 unknown_1a_;
    char unknown_36_[2];
    char unknown_38_[0x18];
    char unknown_50_[0x1c];
    unsigned int unknown_6c_0_ : 12;
    unsigned int rate : 4;
    unsigned int count : 5;
    unsigned int unknown_6e_5_ : 4;
    unsigned int unknown_6f_1_ : 1;
    unsigned int unknown_6f_2_ : 1;
    unsigned int unknown_6f_3_ : 1;
    unsigned int unknown_6f_4_ : 1;
    unsigned int unknown_6f_5_ : 1;
    unsigned int flag30 : 1;
    unsigned int unknown_6f_7_ : 1;
    unsigned int limit : 9;
    unsigned int duration : 10;
    unsigned int scale : 11;
    unsigned int unknown_73_6_ : 1;
    unsigned int unknown_73_7_ : 1;
    unsigned char unknown_74_;
};

// USA: func_02098364
extern "C" ARM void func_02098364(Struct_02098364* settings) {
    memset(settings, 0, 11);
    settings->unknown_c_0_ = 0;
    settings->unknown_c_4_ = 0;
    settings->mode = 0;
    settings->unknown_d_7_ = 0;
    settings->unknown_e_3_ = 0;
    settings->unknown_f_0_ = 0;
    settings->unknown_f_6_ = 0;
    settings->unknown_10_0_ = 0;
    settings->unknown_f_7_ = 0;
    settings->enabled = 0;
    settings->unknown_10_2_ = 0;
    VectorizedMemset(settings->unknown_14_, 0, 6);
    settings->unknown_6c_0_ = 2000;
    settings->rate = 1;
    settings->count = 1;
    settings->unknown_6f_4_ = 0;
    settings->unknown_6e_5_ = 0;
    settings->unknown_6f_3_ = 0;
    settings->unknown_6f_1_ = 0;
    settings->unknown_6f_2_ = 0;
    settings->unknown_6f_5_ = 0;
    settings->flag30 = 1;
    settings->unknown_6f_7_ = 0;
    settings->limit = 511;
    settings->unknown_73_6_ = 0;
    settings->duration = 300;
    settings->scale = 706;
    settings->unknown_74_ = 0;
    func_020827c4(&settings->unknown_1a_);
    VectorizedMemset(settings->unknown_38_, 0, 0x18);
    VectorizedMemset(settings->unknown_50_, 0, 0x1c);
}
