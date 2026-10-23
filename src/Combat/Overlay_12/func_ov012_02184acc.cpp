#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Input/Input.h"

#if defined(jpn)
#define func_ov012_02185cf8 func_ov012_0218634c
#define func_ov012_02184d80 func_ov012_02185db4
#define data_ov012_0218b188 data_ov012_0218bea8
#endif

struct Struct_ov012_02184acc_2
{
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    int unknown_998_;
};

struct Struct_ov012_02184acc_3
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
};

struct Struct_01ff91ac_12
{
    char unknown_0_[0x5400];
    Struct_ov012_02184acc_3 unknown_5400_;
};

struct Struct_01ff91ac_13
{
    char unknown_0_[0x29c];
    Struct_01ff91ac_12 unknown_29c_;
};

struct Struct_ov012_02184acc
{
#if defined(jpn)
    char unknown_0_[0x90];
    char unknown_ac_[0xd0c - 0x90];
    char unknown_d28_[0x608];
    char unknown_1314_[0x1340 - 0x1314];
    unsigned char unknown1_1370_;
    unsigned char unknown_1371_;
    char unknown_1342_[0x1350 - 0x1342];
    int unknown_1380_[4];
    int unknown_1398_;
    int unknown_139c_;
    unsigned char unknown_13a0_;
    char unknown_1369_[3];
    int unknown_13a4_;
    char unknown_1370_[0x1428 - 0x1370];
    char* unknown_13d0_;
    unsigned int unknown_13d4_;
    char unknown_1430_[0x144c - 0x1430];
    unsigned int unknown_144c_;
    char unknown_1450_[0x14d8 - 0x1450];
    unsigned char unknown_1480_[0x20];
    unsigned char unknown_14bc_;
#else
    char unknown1_0_[0xac];
    char unknown_ac_[0xd28 - 0xac];
    char unknown_d28_[0x60c];
    unsigned char unknown_1334_;
    char unknown_1335_[0x1370 - 0x1335];
    unsigned char unknown1_1370_;
    unsigned char unknown_1371_;
    char unknown_1372_[0x1380 - 0x1372];
    int unknown_1380_[6];
    int unknown_1398_;
    int unknown_139c_;
    unsigned char unknown_13a0_;
    char unknown_13a1_[3];
    int unknown_13a4_;
    char unknown_13a8_[0x13d0 - 0x13a8];
    char* unknown_13d0_;
    unsigned int unknown_13d4_;
    char unknown_13d8_[0x13f4 - 0x13d8];
    unsigned int unknown_13f4_;
    char unknown_13f8_[0x1480 - 0x13f8];
    unsigned char unknown_1480_[0x3c];
    unsigned char unknown_14bc_;
    unsigned char unknown_14bd_;
    char unknown_14be_[2];
#endif
};

typedef void (Struct_ov012_02184acc::*Type_01ff91ac_5)();

struct Struct_ov012_0218b188
{
    Type_01ff91ac_5 unknown_0_[17];
};

struct Struct_0205def8;
struct Struct_0205d6a0;

extern "C" void func_ov023_021e7404(void* card, int input);
extern "C" int Window_Update(void* window, int input);
extern "C" void func_ov012_02185cf8(ProfileEditor02184acc* self);
Messages02184acc* GetGlobalField0x1c020421a0();
extern "C" void func_ov012_0218adac(ProfileEditor02184acc* self, int animate, int design, int keepPage);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov012_021845f8(void* arg0);
extern "C" int func_ov012_02184d80(void* arg0, char* arg1);
#if defined(jpn)
struct Struct_0202b2f0;
extern "C" Struct_0202b2f0* func_0202ae18();
extern "C" int func_0202c578(Struct_0202b2f0*, int);
#endif
extern "C" void func_0205def8(Struct_0205def8* arg0, int arg1, int arg2);
extern "C" void func_0205d6a0(Struct_0205d6a0* arg0, int arg1);
extern "C" void func_02043204(char* arg0);

extern "C" const StateTable02184acc data_ov012_0218b188;
extern "C" StateFn02184acc __ptmf_null;

static inline Struct_ov012_02184acc_3* inline_ov012_02184acc(GameState* arg0)
{
    return &((Struct_01ff91ac_13*)arg0)->unknown_29c_.unknown_5400_;
}

// USA: func_ov012_02184acc
extern "C" ARM int func_ov012_02184acc(Struct_ov012_02184acc* arg0, int arg1)
{
    self->unk_13a4 = input;
    func_ov023_021e7404(self->card_, input);
    self->unk_1398 = Window_Update(self->window_, input);
    StateTable02184acc states = data_ov012_0218b188;
    states.states[16] = __ptmf_null;
    if (states.states[self->state_] != 0)
        (self->*states.states[self->state_])();
    func_ov012_02185cf8(self);

    Struct_ov012_02184acc_2* var1 = func_020421a0();
#if !defined(jpn)
    GameState* var2 = GameState::GetInstance();
#endif
    if ((arg0->unknown_1371_ != 0 && arg0->unknown_1371_ < 15) || (arg0->unknown_1371_ == 0 && var1->unknown_998_ != 0))
    {
#if !defined(jpn)
        if (var1->unknown_998_ == 0 && g_keyManager.TestKeysPressed(0x800))
        {
            arg0->unknown_14bd_ = ++arg0->unknown_14bd_ & 1;
            arg0->unknown_1334_ = arg0->unknown_14bd_;
            if (arg0->unknown_1371_ == 13 && arg0->unknown1_1370_ == 3)
                func_ov012_0218adac(arg0, 0, inline_ov012_02184acc(var2)->unknown_3_1_ + arg0->unknown_13f4_ * 2, 1);
            else
                func_ov012_0218adac(arg0, 0, -1, 1);
        }

#endif
#if defined(jpn)
        if ((var1->unknown_998_ == 0 && g_keyManager.TestKeysPressed(0x800)) ||
            func_0202c578(func_0202ae18(), 0))
#else
        if (func_ov017_021959b4())
#endif
        {
#if defined(jpn)
            if (arg0->unknown_1371_ == 14 && arg0->unknown1_1370_ == 4)
#else
            if (arg0->unknown_1371_ == 14 && arg0->unknown1_1370_ == 4 && *arg0->unknown_13d0_ != 0)
#endif
            {
                GameState::GetInstance();
#if !defined(jpn)
                BackgroundLoader::AddLockGlobal();
                BackgroundLoader::FreeAllocationsGlobal();
                func_ov012_021845f8(arg0->unknown_1480_);
#endif
                int var3 = func_ov012_02184d80(arg0->unknown_1480_, arg0->unknown_13d0_);
#if !defined(jpn)
                BackgroundLoader::RemoveLockGlobal();
#endif
                if (var3)
                {
                    func_0205def8((Struct_0205def8*)arg0->unknown_ac_, 0, 14);
                    arg0->unknown1_1370_ = 10;
                    return 0;
                }
            }

            arg0->unknown_14bc_ = 1;
            arg0->unknown_13a0_ = 0;
            arg0->unknown_13d4_ = 0;
            func_0205d6a0((Struct_0205d6a0*)arg0->unknown_ac_, 1);
            arg0->unknown_1371_ = 15;
            arg0->unknown1_1370_ = 0;
            if (var1->unknown_998_ != 0)
                func_02043204((char*)var1);

            BackgroundLoader* var4 = BackgroundLoader::GetInstance();
            for (int var5 = 0; var5 < (int)(sizeof(arg0->unknown_1380_) / sizeof(arg0->unknown_1380_[0])); var5++)
            {
                if (arg0->unknown_1380_[var5] > BackgroundLoader::TaskStatus_Invalid)
                {
                    var4->RemoveTask(arg0->unknown_1380_[var5]);
                    arg0->unknown_1380_[var5] = -1;
                }
            }
        }
    }
    return arg0->unknown_139c_;
}
