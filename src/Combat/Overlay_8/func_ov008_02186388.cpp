#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define REGION_FLAG(obj,flag) ((obj)->unknown_b18_ & (flag))
#define data_ov008_0218b400 data_ov008_0218c080
#define func_ov008_0218712c func_ov008_02188008
#define func_ov008_02187f6c func_ov008_02188ccc
#else
#define REGION_LAYOUT(j,u) u
#define REGION_FLAG(obj,flag) ((obj)->inline_ov008_02185a70(flag))
#endif
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/MessageSystem.h>
#include "Input/Input.h"

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov008_021843f8_2 {
    Struct_01ff8b48_26 unknown_0_[2];
    unsigned int unknown_8_0_ : 17;
    unsigned int unknown_a_1_ : 7;
    unsigned int unknown_b_0_ : 7;
    unsigned int unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 17;
    unsigned int unknown_e_1_ : 7;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    unsigned int unknown_14_;
};

struct Struct_ov008_021843f8_3 {
    Struct_01ff8b48_26 unknown_0_;
    Struct_01ff8b48_26 unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
    char unknown_14_[0x90 - 0x14];
    Struct_ov008_021843f8_2 unknown_90_[1];
    unsigned int unknown_a8_;
    unsigned int unknown_ac_;
};

struct Struct_ov000_021735d0 {
    unsigned int unknown_0_[15];
};

struct Struct_ov008_021843f8 {
    Struct_ov000_021735d0 unknown_0_;
    Struct_ov008_021843f8_3 unknown_3c_;
};

struct Struct_01ff8b48_13 {
    int unknown_0_[0x18 / 4];
};

struct Struct_ov008_02185dc0 {
    int unknown_0_[2];
};

struct Struct_ov003_021594c4 {
    int unknown_0_[0x20 / 4];
};

struct Struct_02081870_2 {
    int unknown_0_[0xbc / 4];
};

struct Struct_ov006_02158478 {
    char unknown_0_[0xc2];
    unsigned short unknown_c2_;
    char unknown_c4_[0xe0 - 0xc4];
};

struct Struct_ov009_02186e00_2 {
    int unknown_0_[0x40 / 4];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    SafeAllocator unknown_8c_;
    Struct_01ff8b48_13 unknown_a0_;
    char* unknown_b8_;
    char unknown_bc_[0x14];
    Struct_ov003_021594c4 unknown_d0_[3];
    Struct_02081870_2 unknown_130_;
    Struct_ov006_02158478 unknown_1ec_[6];
    void* unknown_72c_;
    void* unknown_730_;
    void* unknown_734_;
    void* unknown_738_;
    void* unknown_73c_;
    void* unknown_740_;
    unsigned char unknown_744_[8];
    unsigned char unknown_74c_;
    Struct_ov009_02186e00_2 unknown_750_;
    Object3D unknown_790_;
    char unknown_83c_[0x2c8];
    void* unknown_b04_;
    void* unknown_b08_;
    void* unknown_b0c_;
    signed char unknown_b10_;
    unsigned char unknown_b11_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int unknown_b18_;
    int unknown_b1c_;
    int unknown_b20_;
    int unknown_b24_;
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int unknown_b2c_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
    void* unknown_b3c_;
    Struct_01ff8b48_26 unknown_b40_[2];

    int inline_ov008_02185a70(int arg0)
    {
        return unknown_b18_ & arg0 ? 1 : 0;
    }
};

struct Struct_ov000_02171ffc_2 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov000_02179cdc_4 : GameObject {
    char unknown_13c_[REGION_LAYOUT(0x144, 0x150) - 0x13c];
    Struct_ov000_02171ffc_2* unknown_150_;
};

struct GameResources;
struct Struct_020727d8;
struct Struct_02013fb4;
struct Struct_0201099c_3;
struct Struct_0205d81c;
struct Struct_02108760;

extern char data_ov008_0218b400[] __attribute__((aligned(4)));
extern unsigned char data_0211e33c[];
extern Struct_02108760 data_02108760;

MessageSystem* GetGlobalField0x1c020421a0();
void SetSubBrightness(GameResources* resources, int brightness, int frames);
int IsBrightnessTransitionActive(GameResources* resources);
void* LoadFileIntoMemory(const char* path, void* archive, unsigned int* size);
extern "C" void func_020727d8(Struct_020727d8* arg0);
extern "C" void func_02072928(void* arg0, Struct_02013fb4* arg1, int arg2, int arg3, void* arg4, unsigned char arg5);
extern "C" int func_020100a8(GameState* arg0);
extern "C" const char* func_020e0434(Struct_0201099c_3* arg0, int arg1);
extern "C" void func_02042058(char* arg0, const char* arg1);
extern "C" Struct_ov006_02158478* func_0205d81c(Struct_0205d81c* arg0, int arg1);
struct Struct_ov008_02184a4c_13;
extern "C" void func_ov008_02187664(Struct_ov008_02184a4c_13*, int);
extern "C" void func_0205eaa0(Struct_02108760* arg0, int arg1, int arg2);
#if defined(jpn)
extern "C" void func_020727f8(void* arg0, const char* arg1, int arg2, void* arg3, unsigned char arg4);
#endif

extern "C" {
void* ExtractFileFromGP2(char* arg0, char* arg1, unsigned int* arg2);
void func_0205bb04(Struct_ov009_02186e00_2* arg0, int arg1);
int func_ov008_02188a54(Struct_ov008_021842a0_2* arg0, int arg1);
void func_ov008_0218712c(Struct_ov008_021842a0_2* arg0, Struct_ov008_021843f8_2* arg1);
void func_ov008_02187a70(Struct_ov008_021842a0_2* arg0, Struct_ov008_021843f8_2* arg1);
void func_ov008_02187f6c(Struct_ov008_021842a0_2* arg0, Struct_ov008_021843f8_2* arg1);
void func_ov008_02186964(Struct_ov008_021842a0_2* arg0);
int func_ov008_02186b18(Struct_ov008_021842a0_2* arg0, int arg1, int arg2);
}

static inline Struct_ov008_021843f8* inline_ov008_021843f8(GameState* arg0)
{
    return (Struct_ov008_021843f8*)((char*)arg0 + REGION_LAYOUT(0x2c4, 0x104) + REGION_LAYOUT(0x7000, 0x7400));
}

static inline Struct_ov008_021843f8_2* inline_ov008_02186388(Struct_ov008_021843f8* arg0, int arg1)
{
    return &arg0->unknown_3c_.unknown_90_[arg1];
}

// USA: func_ov008_02186388
extern "C" ARM void func_ov008_02186388(Struct_ov008_021842a0_2* arg0)
{
#if defined(jpn)
    Struct_ov008_021843f8* var0;
#endif
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    BackgroundLoader::GetInstance();
    Struct_02021b84* var3 = func_020421a0();
#if defined(jpn)
    var0 = inline_ov008_021843f8(var1);
#define CLEAR_RECORDS inline_ov008_02186388(var0, 0)
#define CLEAR_TITLE var0->unknown_3c_.unknown_90_[0].unknown_12_7_
#else
    Struct_ov008_021843f8_2* var4 = inline_ov008_02186388(inline_ov008_021843f8(var1), 0);
#define CLEAR_RECORDS var4
#define CLEAR_TITLE var4->unknown_12_7_
#endif
    var3->unknown_19ae_ = 0;
    unsigned char var5 = arg0->unknown_b11_;
    if (var5 == 0)
    {
        SetSubBrightness(var2, -16, 15);
        arg0->unknown_b11_++;
        var5++;
    }
    if (var5 == 1 && func_ov008_02188a54(arg0, 1))
    {
        func_ov008_0218712c(arg0, CLEAR_RECORDS);
        func_ov008_02187664((Struct_ov008_02184a4c_13*)arg0, (int)CLEAR_RECORDS);
        func_ov008_02187a70(arg0, CLEAR_RECORDS);
        func_ov008_02187f6c(arg0, CLEAR_RECORDS);
        for (int var6 = 0; var6 < 5; var6++)
        {
            Struct_ov006_02158478* var7 = func_0205d81c((Struct_0205d81c*)&arg0->unknown_130_, (unsigned char)var6);
            if (var7 != NULL)
                var7->unknown_c2_ = 0;
        }
        arg0->unknown_b18_ |= 0x10000;
        arg0->unknown_b11_++;
    }
    if (var5 == 2)
    {
        SetSubBrightness(var2, 0, 15);
        arg0->unknown_b11_++;
    }
    if (var5 == 3)
    {
        if (IsBrightnessTransitionActive(var2))
            return;
        if (arg0->unknown_b14_ != CLEAR_TITLE)
        {
            memset(arg0->unknown_b8_, 0, REGION_LAYOUT(0x800, 0x960));
#if defined(jpn)
            char* var8 = arg0->unknown_b8_;
            char* var14 = var8 + 0x80;
            Struct_ov008_02185dc0 var9;
            func_020727d8((Struct_020727d8*)&var9);
            func_020727f8(&var9, data_ov008_0218b400, 1001, var8, 0);
            Struct_ov000_02179cdc_4* var10 = (Struct_ov000_02179cdc_4*)func_0200ff1c(var1, func_020100a8(var1));
            func_020727d8((Struct_020727d8*)&var9);
            unsigned char var11 = var10->unknown_150_->unknown_49c_0_;
            func_020727f8(&var9, var8, CLEAR_TITLE, var14, var11);
#else
            char* var12 = arg0->unknown_b8_;
            char* var13 = var12 + 0x80;
            char* var14 = var12 + 0x100;
            BackgroundLoader::AddLockGlobal();
            Struct_ov008_02185dc0 var15;
            unsigned int var16;
            void* var17 = LoadFileIntoMemory(data_ov008_0218b400, data_0211e33c, &var16);
            if (var17 != NULL)
            {
                func_020727d8((Struct_020727d8*)&var15);
                func_02072928(&var15, (Struct_02013fb4*)var17, var16, 1001, var12, 0);
                func_020727d8((Struct_020727d8*)&var15);
                func_02072928(&var15, (Struct_02013fb4*)var17, var16, 1001, var13, 1);
            }
            var17 = ExtractFileFromGP2(var12, var13, &var16);
            if (var17 != NULL)
            {
                Struct_ov000_02179cdc_4* var18 = (Struct_ov000_02179cdc_4*)func_0200ff1c(var1, func_020100a8(var1));
                func_020727d8((Struct_020727d8*)&var15);
                unsigned char var19 = var18->unknown_150_->unknown_49c_0_;
                func_02072928(&var15, (Struct_02013fb4*)var17, var16, CLEAR_TITLE, var14, var19);
            }
            BackgroundLoader::RemoveLockGlobal();
#endif
            func_02042058(var14, func_020e0434((Struct_0201099c_3*)&arg0->unknown_a0_, 1000));
#if defined(jpn)
            func_0204500c(var3, var14, 0);
#else
            func_0204500c(var3, var14, 0, 0xe3);
#endif
            var3->unknown_19b2_ = 1;
            var3->unknown_19c8_ = 1;
            var3->unknown_99c_ = 2;
            if (REGION_FLAG(arg0, 0x40000))
            {
                var3->unknown_19c5_ = 1;
                var3->unknown_19b2_ = 0;
            }
            else
            {
                var3->unknown_19c5_ = 0;
            }
            arg0->unknown_b18_ |= 0x40000;
        }
        arg0->unknown_b11_++;
        var5++;
    }
    if (var5 == 4)
    {
        if (var3->unknown_9a0_ != 3)
            return;
        int var20;
        int var21;
        int var22 = 0;
        if (g_keyManager.TestKeysPressed(0x403))
            var22 = 1;
        g_touchInput.GetTouchPoint(&var20, &var21);
        if (g_touchInput.pressed_)
        {
            int var23 = func_ov008_02186b18(arg0, var20, var21);
            if (var23 == -2)
                var22 = 1;
            if (arg0->unknown_744_[var23] == 7)
                var22 = 1;
        }
        if (var22)
        {
            func_0205eaa0(&data_02108760, 1, 0);
            arg0->unknown_b11_++;
        }
    }
    if (var5 == 5)
    {
        SetSubBrightness(var2, -16, 15);
        arg0->unknown_b11_++;
    }
    if (var5 == 6 && func_ov008_02188a54(arg0, 0))
    {
        func_ov008_0218712c(arg0, NULL);
        func_ov008_02187664((Struct_ov008_02184a4c_13*)arg0, (int)NULL);
        func_ov008_02187a70(arg0, NULL);
        func_ov008_02187f6c(arg0, NULL);
        for (int var24 = 0; var24 < 6; var24++)
        {
            Struct_ov006_02158478* var25 = func_0205d81c((Struct_0205d81c*)&arg0->unknown_130_, (unsigned char)var24);
            if (var25 != NULL)
                var25->unknown_c2_ = 0;
        }
        arg0->unknown_b18_ &= ~0x10000;
        arg0->unknown_b11_++;
    }
    if (var5 == 7)
    {
        SetSubBrightness(var2, 0, 15);
        arg0->unknown_b11_++;
    }
    if (var5 == 8 && !IsBrightnessTransitionActive(var2))
    {
        if (arg0->unknown_b14_ == CLEAR_TITLE)
        {
            arg0->unknown_b18_ |= 0x200;
        }
        else
        {
            arg0->unknown_b18_ |= 0x20000;
            arg0->unknown_b18_ &= ~0x200;
        }
        arg0->unknown_b10_ = 3;
        arg0->unknown_b11_ = 2;
        func_ov008_02186964(arg0);
        for (int var26 = 0; var26 < arg0->unknown_74c_; var26++)
        {
            if (arg0->unknown_744_[var26] == 7)
            {
                func_0205bb04(&arg0->unknown_750_, var26);
#if defined(jpn)
                int var27 = 5;
                int var28 = arg0->unknown_b29_;
                var27 += var28;
                if (var26 > var27)
                    arg0->unknown_b29_ = var26 - 5;
                else if (var26 < var28)
                    arg0->unknown_b29_ = var26;
#else
                if (var26 > arg0->unknown_b29_ + 5)
                    arg0->unknown_b29_ = var26 - 5;
                else if (var26 < arg0->unknown_b29_)
                    arg0->unknown_b29_ = var26;
#endif
                return;
            }
        }
    }
}
