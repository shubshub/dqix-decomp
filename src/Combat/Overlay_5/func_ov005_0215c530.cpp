#include <globaldefs.h>
#include "Resource/GameResources.h"
#include <GameState/GameState.h>

enum Enum_ov005_0215c530
{
    Enum_ov005_0215c530_m1 = -1,
    Enum_ov005_0215c530_32767 = 0x7fff
};

struct Struct_ov005_0215c530_4
{
    unsigned int unknown_0_0_ : 7;
    unsigned int unknown_0_7_ : 4;
    unsigned int unknown_1_3_ : 18;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 2;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 15;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 1;
    unsigned int unknown_7_6_ : 2;
    char unknown_8_[0x20 - 8];
};

struct Struct_ov005_0215c530_6
{
    Struct_ov005_0215c530_4* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
    char unknown_c_[0x18 - 0xc];
    short unknown_18_;
    char unknown_1a_[0x20 - 0x1a];
};

struct Struct_ov005_0215c530_7
{
    short unknown_0_;
    unsigned short unknown_2_0_ : 4;
    unsigned short unknown_2_4_ : 12;
    unsigned int unknown_4_0_ : 7;
    unsigned int unknown_4_7_ : 4;
    unsigned int unknown_5_3_ : 12;
    unsigned int unknown_6_7_ : 1;
    unsigned int unknown_7_0_ : 2;
    unsigned int unknown_7_2_ : 1;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 3;
};

struct Struct_ov005_0215c530
{
    Struct_ov005_0215c530* unknown_0_;
    char unknown_4_[4];
    short unknown_8_;
};

struct Struct_ov005_0215c530_2
{
    short unknown_0_;
    char unknown_2_[0x1c - 2];
};

struct Struct_0201099c_10;
struct Struct_0201099c_9;
struct Struct_ov003_02178910 {
    char unknown_0_[0x48];
    Struct_0201099c_10* unknown_48_;
    Struct_0201099c_9* unknown_4c_;
#if defined(jpn)
    char unknown_50_[0x680];
#else
    char unknown1_50_[0x704];
#endif
    int unknown_754_;
    char unknown_758_[0x18];
    short unknown_770_;
    unsigned short unknown_772_;
    unsigned short unknown_774_;
    unsigned char unknown_776_;
};

struct Struct_01ff8b48_22 {
    Struct_ov005_0215c530_7* unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_ov005_0215c530_3
{
#if defined(jpn)
    char unknown_0_[0x1240];
#else
    char unknown1_0_[0x1244];
#endif
    Struct_ov003_02178910 unknown_1244_;
#if defined(jpn)
    char unknown_1934_[0x1958 - 0x1240 - sizeof(Struct_ov003_02178910)];
#else
    char unknown_19bc_[0x19e0 - 0x1244 - sizeof(Struct_ov003_02178910)];
#endif
    Struct_ov005_0215c530* unknown_19e0_;
    char unknown_19e4_[8];
    Struct_01ff8b48_22 unknown_19ec_;
    char unknown_19f4_[0x2d90 - 0x19f4];
    Struct_ov005_0215c530_2 unknown_2d90_[24];
    char unknown_3030_[0x3d98 - 0x3030];
    short unknown_3d98_[8];
    char unknown_3da8_[2];
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3db9 - 0x3dab];
    unsigned char unknown_3db9_;
    char unknown_3dba_[0x3dbb - 0x3dba];
    signed char unknown_3dbb_;
    unsigned char unknown_3dbc_;
    signed char unknown_3dbd_;
    char unknown_3dbe_;
    signed char unknown_3dbf_;
    char unknown_3dc0_[0x3dcc - 0x3dc0];
    unsigned int unknown_3dcc_;
    char unknown_3dd0_[0x3dd4 - 0x3dd0];
    unsigned char unknown_3dd4_[8];
};

struct Struct_ov005_0215c530_5
{
#if defined(jpn)
    char unknown_0_[0x4f8];
#else
    char unknown1_0_[0x4fc];
#endif
    int unknown_4fc_;
};

struct StructDE1D4;
struct SePlayer;

extern "C" short* func_0207c5f8(unsigned char*, unsigned int);
extern "C" signed char* func_0207c60c(void*, unsigned int);
extern "C" void func_0207c51c(unsigned char*, int);
extern "C" void func_ov023_021e1518(void*);
extern "C" void func_ov023_021e1b5c(void*, int, int, int);
extern "C" void func_ov023_021e1b0c(void*, int, int, int);
extern "C" Struct_ov005_0215c530_5* func_ov017_021a193c(int*);
extern "C" void func_020de1d4(Struct_02083508_2*);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
Entry0215c530* FindEntryById_021db08c(void*, int);
extern "C" int func_020dd4c4(int, Item0215c530*);
extern "C" void func_ov005_021579ec(Menu0215c530*, unsigned int, unsigned char);
extern "C" void GridCursor_SetSelectedIndex(void*, int);
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov005_021555c0(Menu0215c530*);
extern "C" void func_ov023_021dcae0(Obj021dcae0*, int);
extern "C" void func_ov005_0215792c(Menu0215c530*, unsigned char);

#if defined(jpn)
#define data_ov005_0215cd08 data_ov005_0215e0e8
#define data_ov005_0215cd00 data_ov005_0215e0e0
#endif
extern unsigned char data_ov005_0215cd08[];
extern unsigned char data_ov005_0215cd00[];
extern char g_sePlayer[];

// USA: func_ov005_0215c530
extern "C" ARM void func_ov005_0215c530(Struct_ov005_0215c530_3* arg0)
{
    unsigned char* var0 = (unsigned char*)func_02010828(GameState::GetInstance());
    int var1 = arg0->unknown_3d98_[arg0->unknown_3dbc_];
    short* var2 = func_0207c5f8(var0 + 0x1d4, data_ov005_0215cd08[arg0->unknown_3dbc_]);
    signed char* var3 = func_0207c60c(var0 + 0x1d4, data_ov005_0215cd08[arg0->unknown_3dbc_]);
    func_0207c51c(var0 + 0x1d4, data_ov005_0215cd00[arg0->unknown_3dbc_]);

    int var4 = 0;
    int var5 = 0;
    if (arg0->unknown_3dd4_[arg0->unknown_3dbc_] == 0 || arg0->unknown_3dd4_[arg0->unknown_3dbc_] == 1)
    {
        func_ov023_021e1518(&arg0->unknown_19e0_);
        func_ov023_021e1b5c(&arg0->unknown_19e0_, -1, data_ov005_0215cd00[arg0->unknown_3dbc_], -1);
        var4 = 1;
    }
    else if (arg0->unknown_3dd4_[arg0->unknown_3dbc_] == 3)
    {
        func_ov023_021e1518(&arg0->unknown_19e0_);
        func_ov023_021e1b0c(&arg0->unknown_19e0_, -1, data_ov005_0215cd00[arg0->unknown_3dbc_], -1);
        var4 = 1;
    }
    else if (arg0->unknown_3dd4_[arg0->unknown_3dbc_] == 2)
    {
        var5 = 1;
        var4 = 1;
    }

    if (var4)
    {
        int var6 = arg0->unknown_2d90_[arg0->unknown_3dbb_].unknown_0_;
        short var7[0x110];
        unsigned char var8[0x110];
        for (int var9 = 0; var9 < 0x110; var9++)
        {
            var7[var9] = Enum_ov005_0215c530_m1;
            var8[var9] = 0;
        }
        if (!var5)
        {
            Struct_ov005_0215c530* var10 = arg0->unknown_19e0_;
            int var11 = 0;
            while (var10)
            {
                for (int var12 = 0; var12 < var1; var12++)
                {
                    if (var10->unknown_8_ == var2[var12])
                    {
                        var7[var11] = var2[var12];
                        var8[var11] = var3[var12];
                        var11++;
                        var10 = var10->unknown_0_;
                        break;
                    }
                    if (var12 == var1 - 1)
                        var10 = var10->unknown_0_;
                }
            }
        }
        else
        {
            signed char var13 = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_36fc[3])->unknown_4fc_;
            Struct_ov005_0215c530_6 var14;
            Struct_ov005_0215c530_4 var15;
            func_020de1d4((Struct_02083508_2*)&var14);
            memset(&var15, 0, 0x20);
            var14.unknown_0_ = &var15;
            int var16 = 0;
            int var17 = 0;
            for (int var18 = 0; var18 < var1; var18++)
            {
                short var19 = var2[var18];
                if (var19 > 0)
                {
                    func_020de1d4((Struct_02083508_2*)&var14);
                    memset(&var15, 0, 0x20);
                    Struct_ov005_0215c530_7* var20;
                    var14.unknown_0_ = &var15;
                    var20 = func_ov023_021db08c(&arg0->unknown_19ec_, var19);
                    if (var20)
                    {
                        var14.unknown_18_ = var20->unknown_0_;
                        var14.unknown_8_0_ = var20->unknown_2_0_;
                        var15.unknown_0_0_ = var20->unknown_4_0_;
                        var15.unknown_0_7_ = var20->unknown_4_7_;
                        var15.unknown_4_0_ = var20->unknown_5_3_;
                        var15.unknown_3_5_ = var20->unknown_6_7_;
                        var15.unknown_3_6_ = var20->unknown_7_0_;
                        var15.unknown_7_3_ = var20->unknown_7_2_;
                        var15.unknown_7_4_ = var20->unknown_7_3_;
                        var15.unknown_7_5_ = var20->unknown_7_4_;
                    }
                    if (func_020dd4c4(var13, &var14))
                    {
                        var17++;
                    }
                    else
                    {
                        var7[var16] = var2[var18];
                        var8[var16] = var3[var18];
                        var16++;
                        var2[var18] = Enum_ov005_0215c530_m1;
                        var3[var18] = 0;
                    }
                }
            }
            func_0207c51c(var0 + 0x1d4, data_ov005_0215cd00[arg0->unknown_3dbc_]);
            memcpy(var7 + var16, var2, var17 * 2);
            memcpy(var8 + var16, var3, var17);
        }
        memcpy(var2, var7, var1 * 2);
        memcpy(var3, var8, var1);

        int var21 = arg0->unknown_3dbb_;
        if (var21 >= 8 && var21 < 0x18)
        {
            int var22 = -1;
            for (int var23 = 0; var23 < var1; var23++)
            {
                if (var6 == var2[var23])
                {
                    var22 = (short)var23;
                    break;
                }
            }
            if (var22 >= 0)
            {
                arg0->unknown_3dbf_ = arg0->unknown_3dbd_;
                arg0->unknown_3dbd_ = var22 / 16;
                int var24 = arg0->unknown_3dbb_;
                arg0->unknown_3dbb_ = var22 % 16 + 8;
                if (var24 != arg0->unknown_3dbb_)
                {
                    func_ov005_021579ec(self, 4, (unsigned char)self->selected);
                    GridCursor_SetSelectedIndex(self->cursor, self->selected - 8);
                }
            }
        }
        SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
    }

    if (arg0->unknown_3dd4_[arg0->unknown_3dbc_] == 0 || arg0->unknown_3dd4_[arg0->unknown_3dbc_] == 1)
    {
        arg0->unknown_3dd4_[arg0->unknown_3dbc_] = 3;
        arg0->unknown_3dcc_ |= 0x800;
    }
    else if (arg0->unknown_3dd4_[arg0->unknown_3dbc_] == 3)
    {
        arg0->unknown_3dd4_[arg0->unknown_3dbc_] = 2;
        arg0->unknown_3dcc_ |= 0x800;
    }
    else if (arg0->unknown_3dd4_[arg0->unknown_3dbc_] == 2)
    {
        arg0->unknown_3dd4_[arg0->unknown_3dbc_] = 1;
        arg0->unknown_3dcc_ |= 0x800;
    }
    func_ov005_021555c0(arg0);
    Enum_ov005_0215c530 var25 = (Enum_ov005_0215c530)arg0->unknown_2d90_[arg0->unknown_3dbb_].unknown_0_;
    func_ov023_021dcae0(&arg0->unknown_1244_, var25);
    arg0->unknown_3dcc_ |= 0x40;
    arg0->unknown_3daa_ = 0;
    func_ov005_0215792c(arg0, arg0->unknown_3db9_);
}
