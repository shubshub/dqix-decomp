#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_ov012_021863fc_3
{
    char unknown_0_[0x5c];
    void* unknown_5c_;
    char unknown_60_[0x998 - 0x60];
    int unknown_998_;
};

struct Struct_ov012_021863fc_9
{
    short unknown_0_[10];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
};

struct Struct_ov012_021863fc_11
{
    char unknown_0_[0x488];
    Struct_ov012_021863fc_9 unknown_488_;
};

struct Struct_ov012_021863fc_12
{
    char unknown_0_[0x150];
    Struct_ov012_021863fc_11* unknown_150_;
};

struct Struct_ov012_021863fc_13
{
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int unknown_6_3_ : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
};

struct Struct_01ff8b48_6
{
    char unknown_0_[0x5400];
    Struct_ov012_021863fc_13 unknown_5400_;
};

struct Struct_01ff8b48_7
{
    char unknown_0_[0x29c];
    Struct_01ff8b48_6 unknown_29c_;
};

struct Struct_ov012_021863fc
{
    char unknown_0_[0x5f4];
    void* unknown_5f4_;
    void* unknown_5f8_;
    char* unknown_5fc_;
    char unknown_600_[4];
    void* unknown_604_;
    void* unknown_608_;
    char unknown_60c_[0x614 - 0x60c];
};

struct Struct_ov012_021863fc_2
{
    char unknown_0_[0x20];
    SafeAllocator unknown_20_[7];
    char unknown_ac_[0xd28 - 0xac];
    Struct_ov012_021863fc unknown_d28_;
    char unknown_133c_[8];
    char unknown_1344_[0x18];
    void* unknown_135c_;
    void* unknown_1360_;
    void* unknown_1364_;
    void* unknown_1368_;
    void* unknown_136c_;
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    char unknown_1372_[2];
    char* unknown_1374_;
    const char* unknown_1378_;
    void* unknown_137c_;
    int unknown_1380_[6];
    char unknown_1398_[0x13bc - 0x1398];
    char* unknown_13bc_;
    signed char* unknown_13c0_;
    unsigned short unknown_13c4_0_ : 5;
    unsigned short unknown_13c4_5_ : 11;
    char unknown_13c6_[2];
    unsigned short* unknown_13c8_;
    unsigned int* unknown_13cc_;
};

struct Struct_02072a68_2;

int IsField0Null_02046b08(void** p);
void* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int* word, unsigned int bits);
Messages021863fc* GetGlobalField0x1c020421a0();
void OrGlobalFlag0x40_020dc2bc();
extern "C" void func_ov012_02185e18(ProfileEditor021863fc* self);
void ClearAndCopyEntry_02185ea8(char* self);
void ResetAndRebuildEntry_02185f04(char* self);
extern "C" void func_ov012_02185f74(ProfileEditor021863fc* self);
extern "C" void func_ov012_021861e0(ProfileEditor021863fc* self);
extern "C" void func_ov012_021862fc(ProfileEditor021863fc* self);
extern "C" void func_ov012_02184654(ProfileEditor021863fc* self);
void SetSubBrightness(GameResources* resources, int brightness, int frames);
int IsSubBrightnessTransitionActive(GameResources* resources);
extern "C" void func_ov023_021e7220(void* arg0, int arg1);
extern "C" void func_ov023_021e71b4(void* arg0, SafeAllocator* arg1);
extern "C" int func_ov023_021e76c4(void* arg0);
extern "C" int func_020100a8(GameState* arg0);
extern "C" void func_ov023_021e7b34(void* arg0, int arg1);
extern "C" void func_ov012_0218adac(Struct_ov012_021863fc_2* arg0, int arg1, int arg2, int arg3);
extern "C" void* func_0205ec34();
extern "C" int func_0206dfb0(int arg0, unsigned char* arg1, int arg2);
extern "C" const char* func_02072a68(Struct_02072a68_2* arg0, int arg1);
#if !defined(jpn)
extern "C" void func_0204500c(Struct_ov012_021863fc_3* arg0, const char* arg1, int arg2, int arg3);
#endif

extern "C" const char data_ov012_0218b224[];
extern "C" const char data_ov012_0218b23b[];
extern "C" const char data_ov012_0218b24e[];
extern "C" const char data_ov012_0218b263[];
extern "C" const char data_ov012_0218b274[];
extern "C" const char data_ov012_0218b289[];
extern "C" const char data_ov012_0218b29a[];
extern "C" const char data_ov012_0218b2ad[];
extern "C" const char data_ov012_0218b2c2[];
extern "C" const char data_ov012_0218b2d3[];

static inline Struct_ov012_021863fc_13* inline_ov012_021863fc(GameState* arg0)
{
    return &((Struct_01ff8b48_7*)arg0)->unknown_29c_.unknown_5400_;
}

#if defined(jpn)
struct Struct_ov012_021863fc_4
{
    char unknown_0_[0x28];
    void* unknown_28_;
    char unknown_2c_[0x868 - 0x2c];
    int unknown_868_;
};

struct Struct_ov012_021863fc_5
{
    char unknown_0_[0x488];
    Struct_ov012_021863fc_9 unknown_488_;
};

struct Struct_ov012_021863fc_6
{
    char unknown_0_[0x144];
    Struct_ov012_021863fc_5* unknown_144_;
};

struct Struct_01ff8b48_8
{
    char unknown_0_[0x3c];
    Struct_01ff8b48_6 unknown_3c_;
};

struct Struct_ov012_021863fc_7
{
    char unknown_0_[0x5f4];
    void* unknown_5f4_;
    void* unknown_5f8_;
    char* unknown_5fc_;
    char unknown_600_[0x608 - 0x600];
};

struct Struct_ov012_021863fc_8
{
    char unknown_0_[0x12];
    unsigned short unknown_12_;
    char unknown_14_[0x1c - 0x14];
    SafeAllocator* unknown_1c_;
};

struct Struct_ov012_021863fc_10
{
    char unknown_0_[0x18];
    SafeAllocator unknown_18_[7];
    char unknown_a4_[0xd0c - 0xa4];
    Struct_ov012_021863fc_7 unknown_d0c_;
    char unknown_1314_[8];
    char unknown_131c_[0x18];
    char unknown_1334_[0x1340 - 0x1334];
    unsigned char unknown_1340_;
    unsigned char unknown_1341_;
    char unknown_1342_[2];
    char* unknown_1344_;
    char unknown_1348_[0x1350 - 0x1348];
    int unknown_1350_[4];
    char unknown_1360_[0x1414 - 0x1360];
    char* unknown_1414_;
    signed char* unknown_1418_;
    unsigned short unknown_141c_0_ : 5;
    unsigned short unknown_141c_5_ : 11;
    char unknown_141e_[2];
    unsigned short* unknown_1420_;
    unsigned int* unknown_1424_;
    char unknown_1428_[0x14d8 - 0x1428];
    Struct_ov012_021863fc_8 unknown_14d8_;
};

static inline Struct_ov012_021863fc_13* inline_ov012_021863fc_2(GameState* arg0)
{
    return &((Struct_01ff8b48_8*)arg0)->unknown_3c_.unknown_5400_;
}

extern "C" void func_ov012_021856c8(Struct_ov012_021863fc_8* arg0);
extern "C" void func_ov012_02185690(Struct_ov012_021863fc_8* arg0);
extern "C" int func_ov012_02186f3c(Struct_ov012_021863fc_8* arg0);
extern "C" void func_ov012_0218bba0(void* arg0, int arg1, int arg2);
extern "C" void func_0204500c(Struct_ov012_021863fc_4* arg0, const char* arg1, int arg2);
extern "C" const char data_ov012_0218bf66[];
extern "C" const char data_ov012_0218bf81[];
extern "C" const char data_ov012_0218bf9a[];
extern "C" const char data_ov012_0218bfad[];

// USA: func_ov012_021863fc
extern "C" ARM void func_ov012_021863fc(Struct_ov012_021863fc_10* arg0)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GetGlobal02109400_02094a00();
    if (self->step_ == 0)
    {
        if (func_02046b08(*(void***)((char*)var1 + 0x34f0)))
        {
            SetFlags00(var1, 0x10);
            func_020466e4((unsigned int*)func_020d6c00(), 0xf);
            arg0->unknown_1344_ = (char*)((Struct_ov012_021863fc_4*)func_020421a0())->unknown_28_;
            unsigned int var3 = 0;
            Struct_ov012_021863fc_6* var4 = (Struct_ov012_021863fc_6*)var0->GetProtagonist();
            if (var4 != 0)
                var3 = var4->unknown_144_->unknown_488_.unknown_14_0_;
            char var5[0x40];
            sprintf(var5, data_ov012_0218bf66, var3);
            arg0->unknown_1350_[0] = var2->QueueLoadFile(data_ov012_0218bf81, 0);
            arg0->unknown_1350_[1] = var2->QueueLoadFile(var5, 0);
            arg0->unknown_1350_[2] = var2->QueueLoadFile(data_ov012_0218bf9a, 0);
            arg0->unknown_1350_[3] = var2->QueueLoadFile(data_ov012_0218bfad, 0);
            func_020dc2bc();
            arg0->unknown_1340_++;
        }
        return;
    }
    else if (arg0->unknown_1340_ == 1)
    {
        int var6;
        int var7 = 0;
        for (var6 = 0; var6 < 4; var6++)
        {
            if (arg0->unknown_1350_[var6] == -1)
            {
                var7++;
            }
            else if (var2->GetTaskStatus(arg0->unknown_1350_[var6]))
            {
                switch (var6)
                {
                    case 0:
                        func_ov012_02185e18((Struct_ov012_021863fc_2*)arg0);
                        break;
                    case 1:
                        func_ov012_02185f04((char*)arg0);
                        break;
                    case 2:
                        func_ov012_02185f74((Struct_ov012_021863fc_2*)arg0);
                        break;
                    case 3:
                        func_ov012_021861e0((Struct_ov012_021863fc_2*)arg0);
                        break;
                }
                break;
            }
        }
        if (var7 == 4)
            arg0->unknown_1340_++;
        return;
    }
    else if (arg0->unknown_1340_ == 2)
    {
        func_ov012_02184654((Struct_ov012_021863fc_2*)arg0);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 0;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        Struct_0208cb08* var8 = func_02094a00();
        func_02094ab0(var8);
        func_02094b34(var8, 0x6e, 0x1ff, 0, 0);
        SetSubBrightness(var1, -16, 15);
        arg0->unknown_1340_++;
        return;
    }
    else if (arg0->unknown_1340_ == 3)
    {
        if (func_02094b4c(func_02094a00()) && !IsSubBrightnessTransitionActive(var1))
        {
            func_020dc2bc();
            arg0->unknown_18_[2].Reset();
            func_ov023_021e7220(&arg0->unknown_d0c_, 2);
            func_ov023_021e71b4(&arg0->unknown_d0c_, &arg0->unknown_18_[2]);
            arg0->unknown_d0c_.unknown_5f4_ = &arg0->unknown_1314_;
            arg0->unknown_d0c_.unknown_5f8_ = &arg0->unknown_131c_;
            arg0->unknown_d0c_.unknown_5fc_ = arg0->unknown_1414_;
            func_ov012_021856c8(&arg0->unknown_14d8_);
            func_ov012_02185690(&arg0->unknown_14d8_);
            arg0->unknown_14d8_.unknown_1c_ = &arg0->unknown_18_[0];
            arg0->unknown_14d8_.unknown_12_ = 1;
            func_ov012_02186f3c(&arg0->unknown_14d8_);
            arg0->unknown_1340_++;
            return;
        }
    }
    else if (arg0->unknown_1340_ == 4)
    {
        if (func_ov012_02186f3c(&arg0->unknown_14d8_) && func_ov023_021e76c4(&arg0->unknown_d0c_))
        {
            func_ov023_021e7b34(&arg0->unknown_d0c_, func_020100a8(var0));
            func_ov012_0218bba0(arg0, 1, -1);
            SetSubBrightness(var1, 0, 15);
            void* var9 = func_0205ec34();
            for (int var10 = 0; var10 < 0x12; var10++)
            {
                if (func_0206dfb0((int)var9, (unsigned char*)var9 + 0x8c, var10 + 0x200))
                {
                    arg0->unknown_1418_[arg0->unknown_141c_0_] = var10;
                    arg0->unknown_141c_0_++;
                }
            }
            for (int var11 = 0; var11 < 0x1e0; var11++)
            {
                if (arg0->unknown_1424_[var11 / 32] & (1 << (var11 % 32)))
                {
                    arg0->unknown_1420_[arg0->unknown_141c_5_] = var11;
                    arg0->unknown_141c_5_++;
                }
            }
            Struct_ov012_021863fc_13* var12 = inline_ov012_021863fc_2(var0);
            if (var12->unknown_7_6_ == 0)
            {
                arg0->unknown_1340_++;
                return;
            }
            arg0->unknown_1341_ = 1;
            arg0->unknown_1340_ = 0;
            return;
        }
    }
    else if (arg0->unknown_1340_ == 5)
    {
        Struct_ov012_021863fc_4* var13 = (Struct_ov012_021863fc_4*)func_020421a0();
        func_0204500c(var13, func_02072a68((Struct_02072a68_2*)arg0->unknown_1314_, 500), 0);
        var13->unknown_868_ = 1;
        arg0->unknown_1340_++;
        return;
    }
    else if (arg0->unknown_1340_ == 6)
    {
        if (((Struct_ov012_021863fc_4*)func_020421a0())->unknown_868_ == 0)
        {
            Struct_ov012_021863fc_13* var14 = inline_ov012_021863fc_2(var0);
            var14->unknown_7_6_ = 1;
            arg0->unknown_1341_ = 1;
            arg0->unknown_1340_ = 0;
        }
    }
}
#else
// USA: func_ov012_021863fc
extern "C" ARM void func_ov012_021863fc(Struct_ov012_021863fc_2* arg0)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GetGlobal02109400_02094a00();
    if (self->step_ == 0)
    {
        if (func_02046b08(*(void***)((char*)var16 + 0x3700)))
        {
            SetFlags00(var16, 0x10);
            func_020466e4((unsigned int*)func_020d6c00(), 0xf);
            arg0->unknown_1374_ = (char*)func_020421a0()->unknown_5c_;
            unsigned int var18 = 0;
            Struct_ov012_021863fc_12* var19 = (Struct_ov012_021863fc_12*)var15->GetProtagonist();
            if (var19 != 0)
                var18 = var19->unknown_150_->unknown_488_.unknown_14_0_;
            char var20[0x40];
            char var21[0x20];
            sprintf(var20, data_ov012_0218b224, var18);
            sprintf(var21, data_ov012_0218b23b, var18);
            arg0->unknown_1380_[0] = var17->QueueLoadFileInGP2(data_ov012_0218b24e, data_ov012_0218b263, 0);
            arg0->unknown_1380_[1] = var17->QueueLoadFileInGP2(data_ov012_0218b274, data_ov012_0218b289, 0);
            arg0->unknown_1380_[2] = var17->QueueLoadFileInGP2(var20, var21, 0);
            arg0->unknown_1380_[3] = var17->QueueLoadFile(data_ov012_0218b29a, 0);
            arg0->unknown_1380_[4] = var17->QueueLoadFileInGP2(data_ov012_0218b2ad, data_ov012_0218b2c2, 0);
            arg0->unknown_1380_[5] = var17->QueueLoadFile(data_ov012_0218b2d3, 0);
            func_020dc2bc();
            arg0->unknown_1370_++;
        }
        return;
    }
    else if (arg0->unknown_1370_ == 1)
    {
        int var22;
        int var23 = 0;
        for (var22 = 0; var22 < 6; var22++)
        {
            if (arg0->unknown_1380_[var22] == -1)
            {
                var23++;
            }
            else if (var17->GetTaskStatus(arg0->unknown_1380_[var22]))
            {
                switch (var22)
                {
                    case 0:
                        func_ov012_02185e18(arg0);
                        break;
                    case 1:
                        func_ov012_02185ea8((char*)arg0);
                        break;
                    case 2:
                        func_ov012_02185f04((char*)arg0);
                        break;
                    case 3:
                        func_ov012_02185f74(arg0);
                        break;
                    case 4:
                        func_ov012_021861e0(arg0);
                        break;
                    case 5:
                        func_ov012_021862fc(arg0);
                        break;
                }
                break;
            }
        }
        if (var23 == 6)
            arg0->unknown_1370_++;
        return;
    }
    else if (arg0->unknown_1370_ == 2)
    {
        func_ov012_02184654(arg0);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 0;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        Struct_0208cb08* var24 = func_02094a00();
        func_02094ab0(var24);
        func_02094b34(var24, 0x6e, 0x1ff, 0, 0);
        SetSubBrightness(var16, -16, 15);
        arg0->unknown_1370_++;
        return;
    }
    else if (arg0->unknown_1370_ == 3)
    {
        if (func_02094b4c(func_02094a00()) && !IsSubBrightnessTransitionActive(var16))
        {
            func_020dc2bc();
            arg0->unknown_20_[2].Reset();
            func_ov023_021e7220(&arg0->unknown_d28_, 2);
            func_ov023_021e71b4(&arg0->unknown_d28_, &arg0->unknown_20_[2]);
            arg0->unknown_d28_.unknown_5f4_ = &arg0->unknown_133c_;
            arg0->unknown_d28_.unknown_5f8_ = &arg0->unknown_1344_;
            arg0->unknown_d28_.unknown_5fc_ = arg0->unknown_13bc_;
            arg0->unknown_d28_.unknown_604_ = arg0->unknown_1368_;
            arg0->unknown_d28_.unknown_608_ = arg0->unknown_136c_;
            arg0->unknown_1370_++;
            return;
        }
    }
    else if (arg0->unknown_1370_ == 4)
    {
        if (func_ov023_021e76c4(&arg0->unknown_d28_))
        {
            func_ov023_021e7b34(&arg0->unknown_d28_, func_020100a8(var15));
            func_ov012_0218adac(arg0, 1, -1, 0);
            SetSubBrightness(var16, 0, 15);
            void* var25 = func_0205ec34();
            for (int var26 = 0; var26 < 0x12; var26++)
            {
                if (func_0206dfb0((int)var25, (unsigned char*)var25 + 0x8c, var26 + 0x200))
                {
                    arg0->unknown_13c0_[arg0->unknown_13c4_0_] = var26;
                    arg0->unknown_13c4_0_++;
                }
            }
            for (int var27 = 0; var27 < 0x1e0; var27++)
            {
                if (arg0->unknown_13cc_[var27 / 32] & (1 << (var27 % 32)))
                {
                    arg0->unknown_13c8_[arg0->unknown_13c4_5_] = var27;
                    arg0->unknown_13c4_5_++;
                }
            }
            Struct_ov012_021863fc_13* var28 = inline_ov012_021863fc(var15);
            if (var28->unknown_7_6_ == 0)
            {
                arg0->unknown_1370_++;
            }
            else
            {
                arg0->unknown_1371_ = 1;
                arg0->unknown_1370_ = 0;
            }
            unsigned short var29 = 0x294a;
            void* var30 = arg0->unknown_137c_;
            memcpy(var30, &var29, sizeof(var29));
            CleanInvalidateCacheRange(var30, sizeof(var29));
            LoadToMainBGStandardPalette(var30, 4, sizeof(var29));
            CleanCacheRange(var30, sizeof(var29));
            unsigned short var31 = 0x1ce7;
            void* var32 = arg0->unknown_137c_;
            memcpy(var32, &var31, sizeof(var31));
            CleanInvalidateCacheRange(var32, sizeof(var31));
            LoadToMainBGStandardPalette(var32, 8, sizeof(var31));
            CleanCacheRange(var32, sizeof(var31));
            return;
        }
    }
    else if (arg0->unknown_1370_ == 5)
    {
        Struct_ov012_021863fc_3* var33 = func_020421a0();
        func_0204500c(var33, func_02072a68((Struct_02072a68_2*)arg0->unknown_133c_, 500), 0, 0xe3);
        var33->unknown_998_ = 1;
        arg0->unknown_1370_++;
        return;
    }
    else if (arg0->unknown_1370_ == 6)
    {
        if (func_020421a0()->unknown_998_ == 0)
        {
            Struct_ov012_021863fc_13* var34 = inline_ov012_021863fc(var15);
            var34->unknown_7_6_ = 1;
            arg0->unknown_1371_ = 1;
            arg0->unknown_1370_ = 0;
        }
    }
}
#endif
