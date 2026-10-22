#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct GameResources;
struct Struct_02048150;
struct Struct_0205d6a0;
struct Struct_02072a68_2;
struct Struct_ov002_021682c0;
struct Struct_ov023_021eeaac_2;

struct Struct_ov023_021f1234_4 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif

    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
#if defined(jpn)
    char unknown_874_[0x17df - 0x874];
#else
    char unknown_9a4_[0x19af - 0x9a4];
#endif

    unsigned char unknown_19af_;
#if defined(jpn)
    char unknown_17e0_[0x17e2 - 0x17e0];
#else
    char unknown_19b0_[0x19b2 - 0x19b0];
#endif

    unsigned char unknown_19b2_;
};

struct Struct_ov023_021f1234_5 {
    char unknown_0_[0x18];
    void* unknown_18_;
    short unknown_1c_;
#if defined(jpn)
    char unknown_1e_[0x5e4 - 0x1e];
#else
    char unknown1_1e_[0x65c - 0x1e];
#endif

    int unknown_65c_;
};

struct Struct_ov023_021f1234 {
#if defined(jpn)
    char unknown_0_[0x53];
#else
    char unknown1_0_[0x67];
#endif

    unsigned char unknown_67_;
};

struct Struct_ov023_021f1234_2 {
    int unknown_0_;
    char unknown_4_[0x18 - 4];
    int unknown_18_;
    char unknown_1c_[0x74 - 0x1c];
    unsigned short unknown_74_[55];
    unsigned char unknown_e2_;
    unsigned char unknown_e3_;
    char unknown_e4_[0xe8 - 0xe4];
    char unknown_e8_[8];
};

struct Struct_ov023_021f1234_3 {
    char unknown_0_[0x30];
    SafeAllocator unknown_30_;
#if defined(jpn)
    char unknown_44_[0xe28 - 0x44];
#else
    char unknown1_44_[0xeac - 0x44];
#endif

    int unknown_eac_;
#if defined(jpn)
    char unknown_e2c_[0x371c - 0xe2c];
#else
    char unknown_eb0_[0x3760 - 0xeb0];
#endif

#if defined(jpn)
    char unknown_3760_[0x52e4 - 0x371c];
#else
    char unknown_3760_[0x5228 - 0x3760];
#endif

    SafeAllocator unknown_5228_;
#if defined(jpn)
    char unknown_52f8_[0x5768 - 0x52f8];
#else
    char unknown_523c_[0x5574 - 0x523c];
#endif

    Struct_ov023_021f1234_5* unknown_5574_;
    Struct_ov023_021f1234* unknown_5578_;
#if defined(jpn)
    char unknown_5770_[0x5774 - 0x5770];
#else
    char unknown_557c_[0x5584 - 0x557c];
#endif

    unsigned char unknown_5584_;
    char unknown_5585_[3];
    void* unknown_5588_;
#if defined(jpn)
    char unknown_577c_[0x5af4 - 0x577c];
#else
    char unknown_558c_[0x5904 - 0x558c];
#endif

    char unknown_5904_[4];
};

extern "C" BattleEnd_021f1234* _ZZ17GetGlobal021ffefcvE1s;
extern char g_sePlayer[];

extern "C" Struct_ov023_021f1234_4* func_020421a0();
extern "C" int func_02086ef0(Struct_02048150* arg0, int arg1);
extern "C" void func_ov023_021d8b6c(void* arg0);
extern "C" void func_0205d6a0(Struct_0205d6a0* arg0, int arg1);
extern "C" int func_0206dfb0(int arg0, unsigned char* arg1, int arg2);
extern "C" void func_0206df6c(void* arg0, unsigned char* arg1, int arg2, int arg3);
extern "C" const char* func_02072a68(Struct_02072a68_2* arg0, int arg1);
extern "C" void func_02043204(char* arg0);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsMainBrightnessTransitionActive(GameResources* resources);
extern "C" void func_020de868(void* arg0);
extern "C" void func_ov013_02186e74(Struct_ov002_021682c0* arg0, SafeAllocator* arg1);
extern "C" void func_0205ea20(void* arg0, int arg1);
extern "C" unsigned char* func_02053c6c(unsigned char* arg0);
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2* arg0);

extern "C" {
void* func_0205ec34();
void func_ov023_021f1818(void* arg0, int arg1);
void func_ov023_021d8af8(void* arg0);
void func_ov013_02184360(Struct_ov023_021f1234_5* arg0, void* arg1);
void func_ov013_02184cf0(Struct_ov023_021f1234_5* arg0, SafeAllocator* arg1);
#if !defined(jpn)
void func_0204500c(Struct_ov023_021f1234_4* arg0, const char* arg1, int arg2, int arg3);
#endif
#if defined(jpn)
void func_0204500c(Struct_ov023_021f1234_4*,const char*,int);
#endif
int func_ov023_021f4fc8();
void func_ov013_02186eec(Struct_ov023_021f1234* arg0, int arg1);
void func_ov013_02184b4c(Struct_ov023_021f1234_5* arg0, void* arg1);
int func_ov013_021870f0(Struct_ov023_021f1234* arg0);
unsigned char func_ov013_021847c4(void* arg0, int arg1);
void func_ov013_0218782c(Struct_ov023_021f1234* arg0, int arg1, int arg2);
void func_ov013_02186fa0(Struct_ov023_021f1234* arg0);
void func_ov013_02184c8c(Struct_ov023_021f1234_5* arg0, void* arg1);
unsigned char func_0209a678(char* arg0, void* arg1, unsigned short* arg2);
void func_02083e28(unsigned char* arg0, int arg1);
void func_ov017_021cc730(int arg0, int arg1, int arg2, int arg3);
void func_ov017_021ccc34(int arg0);
void func_ov017_021c9e00(int arg0, int arg1, int arg2, int arg3);
void func_ov017_021cd0d8(int arg0, unsigned short* arg1, int arg2);
}

// USA: func_ov023_021f1234
extern "C" ARM int func_ov023_021f1234(Struct_ov023_021f1234_3* arg0)
{
    GameState* var0 = GameState::GetInstance();
    Struct_ov023_021f1234_2* var1 = _ZZ21inline_ov023_021f4c04vE1s;
    GameResources* var2 = GetGameResources();
    BackgroundLoader* var3 = BackgroundLoader::GetInstance();
    void* var4 = func_0205ec34();
    Struct_ov023_021f1234_4* var5 = func_020421a0();
    int var6 = var1->unknown_18_;
    int var7 = func_02086ef0((Struct_02048150*)func_02010828(var0), var6);
    if (arg0->unknown_5574_ == NULL)
    {
        if (arg0->unknown_5588_ != NULL)
        {
            func_ov023_021f1818(arg0->unknown_3760_, 1);
            func_ov023_021d8b6c(arg0->unknown_5588_);
            func_ov023_021d8af8(arg0->unknown_5588_);
            arg0->unknown_5588_ = NULL;
        }
        func_0205d6a0((Struct_0205d6a0*)&arg0->unknown_3760_[0x188], 1);
        arg0->unknown_30_.Reset();
#if defined(jpn)
        arg0->unknown_5574_ = (Struct_ov023_021f1234_5*)arg0->unknown_30_.Allocate(0x654);
#else
        arg0->unknown_5574_ = (Struct_ov023_021f1234_5*)arg0->unknown_30_.Allocate(0x6cc);
#endif
        func_ov013_02184360(arg0->unknown_5574_, arg0->unknown_3760_);
        func_ov013_02184cf0(arg0->unknown_5574_, &arg0->unknown_30_);
        Struct_ov023_021f1234_5* var8 = arg0->unknown_5574_;
        var8->unknown_18_ = &arg0->unknown_3760_[0x11c];
        var8->unknown_1c_ = 0;
        arg0->unknown_5584_ = 0;
    }
    else if (arg0->unknown_5574_ != NULL)
    {
        if (var1->unknown_0_ == 0)
        {
            if (!func_0206dfb0((int)var4, (unsigned char*)var4 + 0x8c, 0x119c))
            {
                func_0206df6c(var4, (unsigned char*)var4 + 0x8c, 0x119c, 1);
                if (var7)
                {
#if defined(jpn)
                    func_0204500c(var5, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x24), 1);
#else
                    func_0204500c(var5, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x24), 1, 0xe3);
#endif

                    var5->unknown_19b2_ = 0;
                    var5->unknown_998_ = 1;
                }
                var1->unknown_0_ = 100;
            }
            else
            {
                func_02043204((char*)var5);
                SetMainBrightness(var2, -0x10, 0x10);
                var1->unknown_0_++;
            }
        }
        else if (var1->unknown_0_ == 100)
        {
            if (var5->unknown_9a0_ == 3)
                var5->unknown_19af_ = 0;
            if (func_ov023_021f4fc8())
            {
                func_02043204((char*)var5);
                SetMainBrightness(var2, -0x10, 0x10);
                var1->unknown_0_ = 1;
            }
        }
        else if (var1->unknown_0_ == 1)
        {
            if (!IsMainBrightnessTransitionActive(var2))
            {
                var1->unknown_0_++;
                func_02043204((char*)var5);
                func_020de868(&arg0->unknown_3760_[0xd0]);
                SafeAllocator* var9 = &arg0->unknown_5228_;
                var9->Reset();
#if defined(jpn)
                arg0->unknown_5578_ = (Struct_ov023_021f1234*)var9->Allocate(0x58);
#else
                arg0->unknown_5578_ = (Struct_ov023_021f1234*)var9->Allocate(0x6c);
#endif

                func_ov013_02186eec(arg0->unknown_5578_, 0);
                func_ov013_02186e74((Struct_ov002_021682c0*)arg0->unknown_5578_, var9);
                GameObject* var10 = func_0200ff1c(var0, var6);
                if (var10 != NULL)
                {
                    func_ov013_02184b4c(arg0->unknown_5574_, var10);
                    arg0->unknown_5578_->unknown_67_ = var10->obj3D_.unknown_4_;
                }
            }
        }
        else if (var1->unknown_0_ == 2)
        {
            if (func_ov013_021870f0(arg0->unknown_5578_))
                var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 3)
        {
            SetMainBrightness(var2, 0, 0x10);
            var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 4)
        {
            if (!IsMainBrightnessTransitionActive(var2))
            {
                SetupContextForMode0205ea20(g_sePlayer, 100);
                end->step_++;
            }
        }
        else if (var1->unknown_0_ == 5)
        {
            GameObject* var11 = func_0200ff1c(var0, var6);
            if (func_ov013_021847c4(arg0->unknown_5574_, var0->GetTickCount()) == 6)
            {
                if (var3->GetNumQueuedTasks() > 0)
                    return arg0->unknown_eac_;
                var1->unknown_0_++;
                return arg0->unknown_eac_;
            }
            int var12 = arg0->unknown_5574_->unknown_65c_;
            if (var11 != NULL)
                func_ov013_0218782c(arg0->unknown_5578_, (signed char)var11->obj3D_.unknown_4_, (unsigned char)var12);
        }
        else if (var1->unknown_0_ == 6)
        {
            SetMainBrightness(var2, -0x10, 0);
            var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 7)
        {
            if (!IsMainBrightnessTransitionActive(var2))
                var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 8)
        {
            func_ov013_02186fa0(arg0->unknown_5578_);
            arg0->unknown_5578_ = NULL;
            var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 9)
        {
            SetMainBrightness(var2, 0, 0x10);
            var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 10)
        {
            if (!IsMainBrightnessTransitionActive(var2))
            {
                SetupContextForMode0205ea20(g_sePlayer, 0x65);
                GetCombatantWithFlag0x100_0200ff1c(gameState, id);
                GameObject* member = GetCombatantWithFlag0x100_0200ff1c(gameState, id);
                if (member != NULL)
                {
                    func_ov013_02184c8c(arg0->unknown_5574_, var13);
                    var1->unknown_e2_ = func_0209a678(var1->unknown_e8_, var13, var1->unknown_74_);
                    func_02083e28(func_02053c6c((unsigned char*)var13), 0);
                }
                func_ov017_021cc730(var6, 0, 0, 1);
                func_ov017_021ccc34(var6);
                func_ov017_021c9e00(var6, 0, 0, 0);
                if (var1->unknown_e2_ != 0)
                {
                    arg0->unknown_5574_ = NULL;
                    func_ov023_021eefac((Struct_ov023_021eeaac_2*)var1);
                    var1->unknown_e3_ = 0;
                    func_ov017_021cd0d8(var6, var1->unknown_74_, var1->unknown_e2_);
                    return 9;
                }
                var1->unknown_0_++;
            }
        }
        else if (var1->unknown_0_ == 11)
        {
            Struct_0208cb08* var14 = func_02094a00();
            func_02094b40(var14);
            func_02094b34(var14, 0x65, 500, 0, 0);
            var1->unknown_0_++;
        }
        else if (var1->unknown_0_ == 12)
        {
            if (func_02094b4c(func_02094a00()))
            {
                arg0->unknown_5574_ = NULL;
                func_ov023_021eefac((Struct_ov023_021eeaac_2*)var1);
                return 7;
            }
        }
    }
    return arg0->unknown_eac_;
}
