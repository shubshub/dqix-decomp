#if defined(jpn)
enum {regionalOffset0=0x860};
#else
enum {regionalOffset0=0x840};
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
    short id_;
    char unk_2[2];
    unsigned int unknown_4_0_ : 7;
    unsigned int unknown_4_7_ : 25;
    char unk_8[0x28 - 8];
};

struct Struct_ov023_021f5ad8_3
{
    short unk_0;
    char unk_2[2];
    Struct_020117f0_5 entries_[6];
    Struct_020117f0_4 unknown_f4_;
    short itemId_;
    char unknown_fa_[2];
    unsigned short unknown_fc_;
    char unknown_fe_[2];
    Struct_020117f0_4 unknown_100_;
    char unknown_104_[8];
    unsigned short flags_ : 13;
    unsigned short unknown_10d_5_ : 3;
    char unknown_10e_[0x114 - 0x10e];
};

struct Struct_ov023_021fff08_8
{
    unsigned char count_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    void* items_;
    char* unknown_8_;
    Struct_ov023_021f5ad8_3* unknown_c_;
    const char* message_;
};

struct ZoneData_021f5ad8
{
    char unk_0[regionalOffset0];
    struct Unknown_840
    {
        char unk_0[0x1b48];
        unsigned int unknown_1b48_;
        unsigned int unknown_1b4c_;
        char unknown_1b50_[0x11];
        unsigned char unknown_1b61_;
    } unk_840;
};

extern "C" ZoneData_021f5ad8* Zone3D_GetInstance();

extern "C" Struct_ov023_021fff08_8 data_ov023_021fff08;

// USA: func_ov023_021f5ad8
extern "C" ARM int func_ov023_021f5ad8(Script::Parameter* params, int count)
{
    ZoneData_021f5ad8::Unknown_840* zones = &Zone3D_GetInstance()->unk_840;
    for (int i = 0; i < count; i++)
    {
        int zone = params->ToInt();
        params++;
        if (!(zones->unknown_1b48_ & (1 << zone)))
        {
            zones->unknown_1b48_ |= 1 << zone;
            zones->unknown_1b4c_ |= 1 << zone;
            zones->unknown_1b61_ = 1;
            data_ov023_021fff08.unknown_c_->flags_ |= 0x200;
        }
    }
    return 1;
}
