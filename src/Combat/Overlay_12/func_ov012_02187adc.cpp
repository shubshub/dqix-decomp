#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_ov012_02187adc_2
{
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int female_ : 1;
    unsigned int unknown_3_2_ : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    int accolade_ : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
};

struct Struct_02000c9c_48
{
    char unk_0[0x5400];
    Struct_ov012_02187adc_2 unknown_5400_;
};

struct Struct_02000c9c_49
{
#if defined(jpn)
    char unk_0[0x3c];
#else
    char unk_0[0x29c];
#endif
    Struct_02000c9c_48 unknown_29c_;
};

struct Struct_ov012_02187adc
{
#if defined(jpn)
    char unk_0[0x90];
    char window_[0x1340 - 0x90];
    unsigned char step_;
    unsigned char state_;
    char unknown_1342_[0x1368 - 0x1342];
    unsigned char unknown_13a0_;
    char unknown_1369_[0x1370 - 0x1369];
    signed char unknown_13a8_;
    signed char unknown_13a9_;
    unsigned char unknown_13aa_;
    unsigned char unknown_13ab_;
    char unknown_1374_[0x1454 - 0x1374];
#else
    char unk_0[0xac];
    char window_[0x1370 - 0xac];
    unsigned char step_;
    unsigned char state_;
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
struct Struct_ov012_02186a7c;

extern "C" int func_ov023_021e63bc(Struct_ov012_02187adc* self);
extern "C" void func_ov023_021e61f4(Struct_ov012_02187adc* self);
extern "C" void func_ov012_02185bf0(Struct_ov012_02187adc* self, unsigned char item, int selected);
extern "C" int func_0205df38(void* window, int item);
extern "C" void func_ov023_021e6378(void* self, int state, int year, int month, unsigned char day);
extern "C" void SePlayer_Play(SePlayer* sound, int effect, int a);
extern "C" int func_ov023_021e6de4(Struct_ov012_02187adc* self);
extern "C" int func_02098f20(int year, int month, int day);
extern "C" void func_ov012_0218adac(Struct_ov012_02187adc* self, int arg1, int arg2, int arg3);
extern "C" int func_ov023_021e6e20(Struct_ov012_02186a7c* self);
extern "C" void Window_ClosePane(Entry_0205d6a0* window, int a);
extern "C" void func_ov023_021e6e60(Struct_ov012_02187adc* self);
extern "C" void func_ov012_0218943c(Struct_ov012_02187adc* self);

#if defined(jpn)
extern "C" void func_ov023_021e65e8(Struct_ov012_02187adc* self);
extern "C" void func_ov023_021e655c(Struct_ov012_02187adc* self);
extern "C" void func_ov012_02186248(Struct_ov012_02187adc* self, unsigned char item, int selected);
extern "C" void func_ov012_0218bba0(Struct_ov012_02187adc* self, int arg1, int arg2);
extern "C" int func_ov023_021e7148(Struct_ov012_02187adc* self);
extern "C" void func_ov012_02189d18(Struct_ov012_02187adc* self);
#define func_ov012_02185bf0 func_ov012_02186248
#define func_ov012_0218adac(self, a, d, k) func_ov012_0218bba0(self, a, d)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218943c func_ov012_02189d18
#endif

extern "C" char g_sePlayer[];
extern "C" const Struct_ov012_0218af9e data_ov012_0218af9e;

static inline Struct_ov012_02187adc_2* inline_ov012_02187adc(GameState* gameState)
{
    return &((Struct_02000c9c_49*)gameState)->unknown_29c_.unknown_5400_;
}

// USA: func_ov012_02187adc
extern "C" ARM void func_ov012_02187adc(Struct_ov012_02187adc* self)
{
    if (self->step_ == 4)
    {
        int changed = 0;
        int var1 = 1;
        int scroll = func_ov023_021e63bc(self);
        if (g_keyManager.TestKeyRepeat(0x80) || scroll < 0)
        {
            if (self->unknown_13aa_ != 0)
                self->unknown_13a8_ = 3;
            if (self->unknown_13a9_ > -3)
                self->unknown_13a9_--;
        }
        else if (g_keyManager.TestKeyRepeat(0x40) || scroll > 0)
        {
            if (self->unknown_13aa_ != 0)
                self->unknown_13a8_ = 2;
            if (self->unknown_13a9_ < 3)
                self->unknown_13a9_++;
        }
        else
        {
            self->unknown_13a9_ = 0;
        }
        func_ov023_021e61f4(self);
        Struct_ov012_0218af9e var3 = data_ov012_0218af9e;
        if (self->unknown_13fc_ % 4 == 0)
            var3.unknown_0_[1] = 29;
        if (g_keyManager.TestKeysPressed(0x80) || self->unknown_13a9_ <= -3)
        {
            if (self->unknown_13ab_ & 8)
            {
                changed = 1;
                self->unknown_13fe_--;
                self->unknown_13a8_ = 3;
                self->unknown_13aa_ = 1;
                signed char maximum = var3.unknown_0_[self->unknown_13fe_ - 1];
                if (self->unknown_13ff_ > maximum)
                {
                    self->unknown_13ff_ = maximum;
                    func_ov012_02185bf0(self, 9, 1);
                }
            }
            else
            {
                self->unknown_13aa_ = 0;
            }
            self->unknown_13a9_ = 0;
        }
        else if (g_keyManager.TestKeysPressed(0x40) || self->unknown_13a9_ >= 3)
        {
            if (self->unknown_13ab_ & 4)
            {
                changed = 1;
                self->unknown_13fe_++;
                self->unknown_13a8_ = 2;
                self->unknown_13aa_ = 1;
                signed char maximum = var3.unknown_0_[self->unknown_13fe_ - 1];
                if (self->unknown_13ff_ > maximum)
                {
                    self->unknown_13ff_ = maximum;
                    func_ov012_02185bf0(self, 9, 1);
                }
            }
            else
            {
                self->unknown_13aa_ = 0;
            }
            self->unknown_13a9_ = 0;
        }
#if defined(jpn)
        else if (g_keyManager.TestKeysPressed(0x10) || func_0205df38(self->window_, 9))
        {
            func_ov023_021e65e8(self);
#else
        else if (g_keyManager.TestKeysPressed(0x20) || func_0205df38(self->window_, 9))
        {
            func_ov023_021e6378(self, 9, 1, 1, 0);
#endif
            changed = 1;
            var1 = 0;
            func_ov012_02185bf0(self, 8, 1);
        }
#if defined(jpn)
        else if (g_keyManager.TestKeysPressed(0x20) || func_0205df38(self->window_, 7))
        {
            GameState::GetInstance();
            func_ov023_021e655c(self);
#else
        else if (g_keyManager.TestKeysPressed(0x10) || func_0205df38(self->window_, 7))
        {
            GameState::GetInstance();
            func_ov023_021e6378(self, 7, 0, 1, 1);
#endif
            changed = 1;
            var1 = 0;
            func_ov012_02185bf0(self, 8, 1);
        }
        else if (func_0205df38(self->window_, 8))
        {
            var1 = 0;
        }
        if (changed)
        {
            func_ov012_02185bf0(self, self->state_, 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 2, 0);
        }

        int close = 0;
        if (func_ov023_021e6de4(self) || func_0205df38(self->window_, 0x10))
        {
            GameState* gameState = GameState::GetInstance();
            Struct_ov012_02187adc_2* profile = inline_ov012_02187adc(gameState);
            func_ov012_02185bf0(self, self->state_, 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            profile->unknown_0_0_ = self->unknown_13fc_;
            profile->unknown_1_4_ = self->unknown_13fe_;
            profile->unknown_2_0_ = self->unknown_13ff_;
            profile->unknown_3_4_ = 1;
            profile->unknown_4_0_ = func_02098f20(self->unknown_13fc_, self->unknown_13fe_, self->unknown_13ff_);
            func_ov012_0218adac(self, 0, -1, 0);
            self->state_ = 6;
            self->step_ = 0;
        }
        else if (func_ov023_021e6e20((Struct_ov012_02186a7c*)self) && var1)
        {
            close = 1;
        }
        if (close)
        {
            Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
            self->step_++;
            return;
        }
        return;
    }
    else if (self->step_ == 5)
    {
        self->step_++;
        return;
    }
    else if (self->step_ == 6)
    {
        self->step_++;
        return;
    }
    else if (self->step_ == 7)
    {
        self->state_ = 1;
        func_ov023_021e6e60(self);
        func_ov012_0218943c(self);
        self->unknown_13a0_ = 1;
        self->unknown_13a8_ = -1;
        self->unknown_13a9_ = 0;
        self->step_ = 1;
    }
}
