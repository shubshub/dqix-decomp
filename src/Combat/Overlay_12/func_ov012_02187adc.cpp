#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_ov012_02187adc_2
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

struct Struct_02000c9c_48
{
    char unknown_0_[0x5400];
    Struct_ov012_02187adc_2 unknown_5400_;
};

struct Struct_02000c9c_49
{
#if defined(jpn)
    char unknown_0_[0x3c];
#else
    char unknown1_0_[0x29c];
#endif
    Struct_02000c9c_48 unknown_29c_;
};

struct Struct_ov012_02187adc
{
#if defined(jpn)
    char unknown1_0_[0x90];
    char unknown_ac_[0x1340 - 0x90];
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    char unknown_1342_[0x1368 - 0x1342];
    unsigned char unknown_13a0_;
    char unknown_1369_[0x1370 - 0x1369];
    signed char unknown_13a8_;
    signed char unknown_13a9_;
    unsigned char unknown_13aa_;
    unsigned char unknown_13ab_;
    char unknown_1374_[0x1454 - 0x1374];
#else
    char unknown_0_[0xac];
    char unknown_ac_[0x1370 - 0xac];
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    char unknown_1372_[0x13a0 - 0x1372];
    unsigned char unknown_13a0_;
    char unknown_13a1_[0x13a8 - 0x13a1];
    signed char unknown_13a8_;
    signed char unknown_13a9_;
    unsigned char unknown_13aa_;
    unsigned char unknown_13ab_;
    char unknown_13ac_[0x13fc - 0x13ac];
#endif
    unsigned short unknown_13fc_;
    unsigned char unknown_13fe_;
    unsigned char unknown_13ff_;
};

struct Struct_ov012_0218af9e
{
    unsigned char unknown_0_[12];
};

struct Entry_0205d6a0;
struct SePlayer;
struct Obj021e6e20;

extern "C" int func_ov023_021e63bc(ProfileEditor02187adc* self);
extern "C" void func_ov023_021e61f4(ProfileEditor02187adc* self);
extern "C" void func_ov012_02185bf0(ProfileEditor02187adc* self, unsigned char item, int selected);
extern "C" int func_0205df38(void* window, int item);
void SetThreeElementFields_021e6378(void* self, int state, int year, int month, unsigned char day);
void SePlayer_Play(SePlayer* sound, int effect, int a);
extern "C" int func_ov023_021e6de4(ProfileEditor02187adc* self);
int CalculateAge_02098f20(int year, int month, int day);
extern "C" void func_ov012_0218adac(ProfileEditor02187adc* self, int animate, int design, int keepPage);
int TestFlagsAndActiveElement2_021e6e20(Obj021e6e20* self);
void Window_ClosePane(Entry_0205d6a0* window, int a);
extern "C" void func_ov023_021e6e60(ProfileEditor02187adc* self);
extern "C" void func_ov012_0218943c(ProfileEditor02187adc* self);

#if defined(jpn)
extern "C" void func_ov023_021e65e8(Struct_ov012_02187adc* arg0);
extern "C" void func_ov023_021e655c(Struct_ov012_02187adc* arg0);
extern "C" void func_ov012_02186248(Struct_ov012_02187adc* arg0, unsigned char arg1, int arg2);
extern "C" void func_ov012_0218bba0(Struct_ov012_02187adc* arg0, int arg1, int arg2);
extern "C" int func_ov023_021e7148(Struct_ov012_02187adc* arg0);
extern "C" void func_ov012_02189d18(Struct_ov012_02187adc* arg0);
#define func_ov012_02185bf0 func_ov012_02186248
#define func_ov012_0218adac(self, a, d, k) func_ov012_0218bba0(self, a, d)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218943c func_ov012_02189d18
#endif

extern "C" char g_sePlayer[];
extern "C" const MonthDays02187adc data_ov012_0218af9e;

static inline Struct_ov012_02187adc_2* inline_ov012_02187adc(GameState* arg0)
{
    return &((Struct_02000c9c_49*)arg0)->unknown_29c_.unknown_5400_;
}

// USA: func_ov012_02187adc
extern "C" ARM void func_ov012_02187adc(Struct_ov012_02187adc* arg0)
{
    if (arg0->unknown_1370_ == 4)
    {
        int var0 = 0;
        int var1 = 1;
        int var2 = func_ov023_021e63bc(arg0);
        if (g_keyManager.TestKeyRepeat(0x80) || var2 < 0)
        {
            if (arg0->unknown_13aa_ != 0)
                arg0->unknown_13a8_ = 3;
            if (arg0->unknown_13a9_ > -3)
                arg0->unknown_13a9_--;
        }
        else if (g_keyManager.TestKeyRepeat(0x40) || var2 > 0)
        {
            if (arg0->unknown_13aa_ != 0)
                arg0->unknown_13a8_ = 2;
            if (arg0->unknown_13a9_ < 3)
                arg0->unknown_13a9_++;
        }
        else
        {
            arg0->unknown_13a9_ = 0;
        }
        func_ov023_021e61f4(arg0);
        Struct_ov012_0218af9e var3 = data_ov012_0218af9e;
        if (arg0->unknown_13fc_ % 4 == 0)
            var3.unknown_0_[1] = 29;
        if (g_keyManager.TestKeysPressed(0x80) || arg0->unknown_13a9_ <= -3)
        {
            if (arg0->unknown_13ab_ & 8)
            {
                var0 = 1;
                arg0->unknown_13fe_--;
                arg0->unknown_13a8_ = 3;
                arg0->unknown_13aa_ = 1;
                signed char var4 = var3.unknown_0_[arg0->unknown_13fe_ - 1];
                if (arg0->unknown_13ff_ > var4)
                {
                    arg0->unknown_13ff_ = var4;
                    func_ov012_02185bf0(arg0, 9, 1);
                }
            }
            else
            {
                arg0->unknown_13aa_ = 0;
            }
            arg0->unknown_13a9_ = 0;
        }
        else if (g_keyManager.TestKeysPressed(0x40) || arg0->unknown_13a9_ >= 3)
        {
            if (arg0->unknown_13ab_ & 4)
            {
                var0 = 1;
                arg0->unknown_13fe_++;
                arg0->unknown_13a8_ = 2;
                arg0->unknown_13aa_ = 1;
                signed char var5 = var3.unknown_0_[arg0->unknown_13fe_ - 1];
                if (arg0->unknown_13ff_ > var5)
                {
                    arg0->unknown_13ff_ = var5;
                    func_ov012_02185bf0(arg0, 9, 1);
                }
            }
            else
            {
                arg0->unknown_13aa_ = 0;
            }
            arg0->unknown_13a9_ = 0;
        }
#if defined(jpn)
        else if (g_keyManager.TestKeysPressed(0x10) || func_0205df38(arg0->unknown_ac_, 9))
        {
            func_ov023_021e65e8(arg0);
#else
        else if (g_keyManager.TestKeysPressed(0x20) || func_0205df38(arg0->unknown_ac_, 9))
        {
            func_ov023_021e6378(arg0, 9, 1, 1, 0);
#endif
            var0 = 1;
            var1 = 0;
            func_ov012_02185bf0(arg0, 8, 1);
        }
#if defined(jpn)
        else if (g_keyManager.TestKeysPressed(0x20) || func_0205df38(arg0->unknown_ac_, 7))
        {
            GameState::GetInstance();
            func_ov023_021e655c(arg0);
#else
        else if (g_keyManager.TestKeysPressed(0x10) || func_0205df38(arg0->unknown_ac_, 7))
        {
            GameState::GetInstance();
            func_ov023_021e6378(arg0, 7, 0, 1, 1);
#endif
            var0 = 1;
            var1 = 0;
            func_ov012_02185bf0(arg0, 8, 1);
        }
        else if (func_0205df38(arg0->unknown_ac_, 8))
        {
            var1 = 0;
        }
        if (var0)
        {
            func_ov012_02185bf0(self, self->state_, 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 2, 0);
        }

        int var6 = 0;
        if (func_ov023_021e6de4(arg0) || func_0205df38(arg0->unknown_ac_, 0x10))
        {
            GameState* gameState = GameState::GetInstance();
            Profile02187adc* profile = GetProfile02187adc(gameState);
            func_ov012_02185bf0(self, self->state_, 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            profile->year_ = self->year_;
            profile->month_ = self->month_;
            profile->day_ = self->day_;
            profile->birthdayChosen_ = 1;
            profile->unk_4_0 = CalculateAge_02098f20(self->year_, self->month_, self->day_);
            func_ov012_0218adac(self, 0, -1, 0);
            self->state_ = 6;
            self->step_ = 0;
        }
        else if (func_ov023_021e6e20((Struct_ov012_02186a7c*)arg0) && var1)
        {
            var6 = 1;
        }
        if (var6)
        {
            Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
            self->step_++;
            return;
        }
        return;
    }
    else if (arg0->unknown_1370_ == 5)
    {
        arg0->unknown_1370_++;
        return;
    }
    else if (arg0->unknown_1370_ == 6)
    {
        arg0->unknown_1370_++;
        return;
    }
    else if (arg0->unknown_1370_ == 7)
    {
        arg0->unknown_1371_ = 1;
        func_ov023_021e6e60(arg0);
        func_ov012_0218943c(arg0);
        arg0->unknown_13a0_ = 1;
        arg0->unknown_13a8_ = -1;
        arg0->unknown_13a9_ = 0;
        arg0->unknown_1370_ = 1;
    }
}
