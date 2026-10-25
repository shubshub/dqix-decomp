#if defined(jpn)
enum {Enum_ov023_021f5ad8_2112=0x860};
#else
enum {Enum_ov023_021f5ad8_2112=0x840};
#endif
#include <globaldefs.h>
#include "Resource/Script.h"

struct Struct_020117f0_4
{
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int unknown_3_2_ : 6;
};

struct Struct_020117f0_5
{
    short unknown_0_;
    char unknown_2_[2];
    unsigned int unknown_4_0_ : 7;
    unsigned int unknown_4_7_ : 25;
    char unknown_8_[0x28 - 8];
};

struct Struct_ov023_021f5ad8_3
{
    short unknown_0_;
    char unknown_2_[2];
    Struct_020117f0_5 unknown_4_[6];
    Struct_020117f0_4 unknown_f4_;
    short unknown_f8_;
    char unknown_fa_[2];
    unsigned short unknown_fc_;
    char unknown_fe_[2];
    Struct_020117f0_4 unknown_100_;
    char unknown_104_[8];
    unsigned short unknown_10c_0_ : 13;
    unsigned short unknown_10d_5_ : 3;
    char unknown_10e_[0x114 - 0x10e];
};

struct Struct_ov023_021fff08_8
{
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    void* unknown_4_;
    char* unknown_8_;
    Struct_ov023_021f5ad8_3* unknown_c_;
    const char* unknown_10_;
};

struct Struct_ov023_021f5ad8
{
    char unknown_0_[Enum_ov023_021f5ad8_2112];
    struct Struct_ov023_021f5ad8_2
    {
        char unknown_0_[0x1b48];
        unsigned int unknown_1b48_;
        unsigned int unknown_1b4c_;
        char unknown_1b50_[0x11];
        unsigned char unknown_1b61_;
    } unknown_840_;
};

extern "C" ZoneData_021f5ad8* Zone3D_GetInstance();

extern "C" Struct_ov023_021fff08_8 data_ov023_021fff08;

// USA: func_ov023_021f5ad8
extern "C" ARM int func_ov023_021f5ad8(Script::Parameter* arg0, int arg1)
{
    ZoneData_021f5ad8::Unknown_840* zones = &Zone3D_GetInstance()->unk_840;
    for (int i = 0; i < count; i++)
    {
        int var2 = arg0->ToInt();
        arg0++;
        if (!(var0->unknown_1b48_ & (1 << var2)))
        {
            var0->unknown_1b48_ |= 1 << var2;
            var0->unknown_1b4c_ |= 1 << var2;
            var0->unknown_1b61_ = 1;
            data_ov023_021fff08.unknown_c_->unknown_10c_0_ |= 0x200;
        }
    }
    return 1;
}
