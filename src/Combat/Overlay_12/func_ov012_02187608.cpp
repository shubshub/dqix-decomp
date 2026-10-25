#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
#define R(j, u) (j)
#define func_ov012_02185bf0 func_ov012_02186248
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218943c func_ov012_02189d18
#else
#define R(j, u) (u)
#endif

struct Struct_ov012_02187608_2
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

struct Struct_02000c9c_46
{
    char unknown_0_[0x5400];
    Struct_ov012_02187608_2 unknown_5400_;
};

struct Struct_02000c9c_47
{
#if defined(jpn)
    char unknown_0_[0x3c];
#else
    char unknown1_0_[0x29c];
#endif
    Struct_02000c9c_46 unknown_29c_;
};

#if defined(jpn)
struct Struct_ov012_02187608
{
    char unknown_0_[0x90];
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
    unsigned short unknown_13fc_;
    unsigned char unknown_13fe_;
    unsigned char unknown_13ff_;
};
#else
struct Struct_ov012_02187608
{
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
    unsigned short unknown_13fc_;
    unsigned char unknown_13fe_;
    unsigned char unknown_13ff_;
};
#endif

struct Entry_0205d6a0;
struct SePlayer;
struct Obj021e6e20;

extern "C" int func_ov023_021e63bc(ProfileEditor02187608* self);
extern "C" void func_ov023_021e61f4(ProfileEditor02187608* self);
extern "C" void func_ov012_02185bf0(ProfileEditor02187608* self, unsigned char item, int selected);
extern "C" int func_0205df38(void* window, int item);
void SetThreeElementFields_021e6378(void* self, int state, int year, int month, unsigned char day);
void SePlayer_Play(SePlayer* sound, int effect, int a);
extern "C" int func_ov023_021e6de4(ProfileEditor02187608* self);
int CalculateAge_02098f20(int year, int month, int day);
#if defined(jpn)
struct Struct_0205de24_2;
extern "C" void func_0205de24(Struct_0205de24_2*, unsigned char, unsigned char);
extern "C" void func_ov012_0218a054(Struct_ov012_02187608* arg0);
extern "C" void func_ov023_021e65a0(Struct_ov012_02187608* arg0);
extern "C" void func_ov023_021e65e8(Struct_ov012_02187608* arg0);
extern "C" void func_ov012_0218bba0(Struct_ov012_02187608* arg0, int arg1, int arg2);
#else
extern "C" void func_ov012_0218adac(Struct_ov012_02187608* arg0, int arg1, int arg2, int arg3);
#endif
int TestFlagsAndActiveElement2_021e6e20(Obj021e6e20* self);
void Window_ClosePane(Entry_0205d6a0* window, int a);
extern "C" void func_ov023_021e6e60(ProfileEditor02187608* self);
extern "C" void func_ov012_0218943c(ProfileEditor02187608* self);

extern "C" char g_sePlayer[];

static inline Struct_ov012_02187608_2* inline_ov012_02187608(GameState* arg0)
{
    return &((Struct_02000c9c_47*)arg0)->unknown_29c_.unknown_5400_;
}

// USA: func_ov012_02187608
extern "C" ARM void func_ov012_02187608(Struct_ov012_02187608* arg0)
{
#if defined(jpn)
    if (arg0->unknown_1370_ == 0)
    {
        Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
        self->step_++;
    }
    else if (arg0->unknown_1370_ == 1)
        arg0->unknown_1370_++;
    else if (arg0->unknown_1370_ == 2)
        arg0->unknown_1370_++;
    if (arg0->unknown_1370_ == 3)
    {
        GameState* var0 = GameState::GetInstance();
        arg0->unknown_13fc_ = inline_ov012_02187608(var0)->unknown_0_0_;
        arg0->unknown_13fe_ = inline_ov012_02187608(var0)->unknown_1_4_;
        arg0->unknown_13ff_ = inline_ov012_02187608(var0)->unknown_2_0_;
        func_0205de24((Struct_0205de24_2*)arg0->unknown_ac_, 0, 2);
        func_ov023_021e6e60(arg0);
        func_ov012_0218a054(arg0);
        arg0->unknown_13a0_ = 0;
        arg0->unknown_1370_++;
        return;
    }
    else
#endif
    if (arg0->unknown_1370_ == 4)
    {
        int var1 = 0;
        int var2 = 1;
        int var3 = func_ov023_021e63bc(arg0);
        if (g_keyManager.TestKeyRepeat(0x80) || var3 < 0)
        {
            if (arg0->unknown_13aa_ != 0)
                arg0->unknown_13a8_ = 1;
            if (arg0->unknown_13a9_ > -3)
                arg0->unknown_13a9_--;
        }
        else if (g_keyManager.TestKeyRepeat(0x40) || var3 > 0)
        {
            if (arg0->unknown_13aa_ != 0)
                arg0->unknown_13a8_ = 0;
            if (arg0->unknown_13a9_ < 3)
                arg0->unknown_13a9_++;
        }
        else
        {
            arg0->unknown_13a9_ = 0;
        }
        func_ov023_021e61f4(arg0);
        if (g_keyManager.TestKeysPressed(0x80) || arg0->unknown_13a9_ <= -3)
        {
            if (arg0->unknown_13ab_ & 2)
            {
                var1 = 1;
                arg0->unknown_13fc_--;
                arg0->unknown_13a8_ = 1;
                arg0->unknown_13aa_ = 1;
                if (arg0->unknown_13fc_ % 4 != 0 && arg0->unknown_13fe_ == 2 && arg0->unknown_13ff_ == 29)
                {
                    arg0->unknown_13ff_ = 28;
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
            if (arg0->unknown_13ab_ & 1)
            {
                var1 = 1;
                arg0->unknown_13fc_++;
                arg0->unknown_13a8_ = 0;
                arg0->unknown_13aa_ = 1;
                if (arg0->unknown_13fc_ % 4 != 0 && arg0->unknown_13fe_ == 2 && arg0->unknown_13ff_ == 29)
                {
                    arg0->unknown_13ff_ = 28;
                    func_ov012_02185bf0(arg0, 9, 1);
                }
            }
            else
            {
                arg0->unknown_13aa_ = 0;
            }
            arg0->unknown_13a9_ = 0;
        }
        else if (g_keyManager.TestKeysPressed(R(0x10, 0x20)) || func_0205df38(arg0->unknown_ac_, 8))
        {
#if defined(jpn)
            func_ov023_021e65a0(arg0);
#else
            func_ov023_021e6378(arg0, 8, 1, 0, 1);
#endif
            var1 = 1;
            var2 = 0;
            func_ov012_02185bf0(arg0, 7, 1);
        }
        else if (func_0205df38(arg0->unknown_ac_, 9))
        {
#if defined(jpn)
            func_ov023_021e65e8(arg0);
#else
            func_ov023_021e6378(arg0, 9, 1, 1, 0);
#endif
            var1 = 1;
            var2 = 0;
            func_ov012_02185bf0(arg0, 7, 1);
        }
        else if (func_0205df38(arg0->unknown_ac_, 7))
        {
            var2 = 0;
        }
        if (var1)
        {
            func_ov012_02185bf0(self, self->state_, 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 2, 0);
        }

        int var4 = 0;
        if (func_ov023_021e6de4(arg0) || func_0205df38(arg0->unknown_ac_, 0x10))
        {
            GameState* gameState = GameState::GetInstance();
            Profile02187608* profile = GetProfile02187608(gameState);
            func_ov012_02185bf0(self, self->state_, 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            profile->year_ = self->year_;
            profile->month_ = self->month_;
            profile->day_ = self->day_;
            profile->birthdayChosen_ = 1;
            profile->unk_4_0 = CalculateAge_02098f20(self->year_, self->month_, self->day_);
#if defined(jpn)
            func_ov012_0218bba0(arg0, 0, -1);
#else
            func_ov012_0218adac(arg0, 0, -1, 0);
#endif
            arg0->unknown_1371_ = 6;
            arg0->unknown_1370_ = 0;
        }
        else if (func_ov023_021e6e20((Struct_ov012_02186a7c*)arg0) && var2)
        {
            var4 = 1;
        }
        if (!var4)
            return;
        Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
        self->step_++;
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
        arg0->unknown_13aa_ = 0;
        arg0->unknown_1370_ = 1;
        return;
    }
}
