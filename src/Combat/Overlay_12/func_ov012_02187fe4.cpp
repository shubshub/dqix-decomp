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

struct Profile02187fe4
{
    unsigned int year_ : 12;
    unsigned int month_ : 4;
    unsigned int day_ : 5;
    unsigned int unk_0_21 : 4;
    unsigned int female_ : 1;
    unsigned int initialized_ : 1;
    unsigned int designChosen_ : 1;
    unsigned int birthdayChosen_ : 1;
    unsigned int accoladeChosen_ : 1;
    unsigned int vocationAccolade_ : 1;
    unsigned int showBirthday_ : 1;
    unsigned int unk_4_0 : 9;
    int title_ : 10;
    int accolade_ : 11;
    int edited_ : 1;
    unsigned int unk_4_31 : 1;
};

struct Save02187fe4
{
    char unk_0[0x5400];
    Profile02187fe4 profile_;
};

struct GameStateSave02187fe4
{
#if defined(jpn)
    char unk_0[0x3c];
#else
    char unk_0[0x29c];
#endif
    Save02187fe4 save_;
};

struct ProfileEditor02187fe4
{
#if defined(jpn)
    char unk_0[0x90];
    char window_[0x1340 - 0x90];
    unsigned char step_;
    unsigned char state_;
    char unk_1342[0x1368 - 0x1342];
    unsigned char unk_13a0;
    char unk_1369[0x1370 - 0x1369];
    signed char unk_13a8;
    signed char unk_13a9;
    unsigned char unk_13aa;
    unsigned char unk_13ab;
    char unk_1374[0x1454 - 0x1374];
#else
    char unk_0[0xac];
    char window_[0x1370 - 0xac];
    unsigned char step_;
    unsigned char state_;
    char unk_1372[0x13a0 - 0x1372];
    unsigned char unk_13a0;
    char unk_13a1[0x13a8 - 0x13a1];
    signed char unk_13a8;
    signed char unk_13a9;
    unsigned char unk_13aa;
    unsigned char unk_13ab;
    char unk_13ac[0x13fc - 0x13ac];
#endif
    unsigned short year_;
    unsigned char month_;
    unsigned char day_;
};

struct Entry_0205d6a0;
struct SePlayer;
struct Obj021e6e20;
struct Struct0205de24;

void FindAndLinkMatchingEntry0205de24(Struct0205de24* window, unsigned char a, unsigned char b);
extern "C" void func_ov012_0218a054(ProfileEditor02187fe4* self);
extern "C" int func_ov023_021e63bc(ProfileEditor02187fe4* self);
extern "C" void func_ov023_021e61f4(ProfileEditor02187fe4* self);
extern "C" void func_ov012_02185bf0(ProfileEditor02187fe4* self, unsigned char item, int selected);
extern "C" int func_0205df38(void* window, int item);
void SetThreeElementFields_021e6378(void* self, int state, int year, int month, unsigned char day);
void SePlayer_Play(SePlayer* sound, int effect, int a);
extern "C" int func_ov023_021e6de4(ProfileEditor02187fe4* self);
int CalculateAge_02098f20(int year, int month, int day);
#if defined(jpn)
extern "C" void func_ov023_021e65a0(ProfileEditor02187fe4* self);
extern "C" void func_ov023_021e655c(ProfileEditor02187fe4* self);
extern "C" void func_ov012_0218bba0(ProfileEditor02187fe4* self, int animate, int design);
#else
extern "C" void func_ov012_0218adac(ProfileEditor02187fe4* self, int animate, int design, int keepPage);
#endif
int TestFlagsAndActiveElement2_021e6e20(Obj021e6e20* self);
void ResetEntryList0205d6a0(Entry_0205d6a0* window, int a);
extern "C" void func_ov023_021e6e60(ProfileEditor02187fe4* self);
extern "C" void func_ov012_0218943c(ProfileEditor02187fe4* self);

extern "C" char g_sePlayer[];

static inline Profile02187fe4* GetProfile02187fe4(GameState* gameState)
{
    return &((GameStateSave02187fe4*)gameState)->save_.profile_;
}

// USA: func_ov012_02187fe4
extern "C" ARM void func_ov012_02187fe4(ProfileEditor02187fe4* self)
{
#if !defined(jpn)
    if (self->step_ == 0)
    {
        ResetEntryList0205d6a0((Entry_0205d6a0*)self->window_, 1);
        self->step_++;
        return;
    }
    else if (self->step_ == 1)
    {
        self->step_++;
        return;
    }
    else if (self->step_ == 2)
    {
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        GameState* gameState = GameState::GetInstance();
        self->year_ = GetProfile02187fe4(gameState)->year_;
        self->month_ = GetProfile02187fe4(gameState)->month_;
        self->day_ = GetProfile02187fe4(gameState)->day_;
        FindAndLinkMatchingEntry0205de24((Struct0205de24*)self->window_, 0, 2);
        func_ov023_021e6e60(self);
        func_ov012_0218a054(self);
        self->unk_13a0 = 0;
        self->step_++;
        return;
    }
    else
#endif
    if (self->step_ == 4)
    {
        int changed = 0;
        int canCancel = 1;
        int scroll = func_ov023_021e63bc(self);
        if (g_keyManager.TestKeyRepeat(0x80) || scroll < 0)
        {
            if (self->unk_13aa != 0)
                self->unk_13a8 = 5;
            if (self->unk_13a9 > -3)
                self->unk_13a9--;
        }
        else if (g_keyManager.TestKeyRepeat(0x40) || scroll > 0)
        {
            if (self->unk_13aa != 0)
                self->unk_13a8 = 4;
            if (self->unk_13a9 < 3)
                self->unk_13a9++;
        }
        else
        {
            self->unk_13a9 = 0;
        }
        func_ov023_021e61f4(self);
        if (g_keyManager.TestKeysPressed(0x80) || self->unk_13a9 <= -3)
        {
            if (!(self->unk_13ab & 0x20))
            {
                self->unk_13aa = 0;
            }
            else
            {
                changed = 1;
                self->day_--;
                self->unk_13a8 = 5;
                self->unk_13aa = 1;
            }
            self->unk_13a9 = 0;
        }
        else if (g_keyManager.TestKeysPressed(0x40) || self->unk_13a9 >= 3)
        {
            if (!(self->unk_13ab & 0x10))
            {
                self->unk_13aa = 0;
            }
            else
            {
                changed = 1;
                self->day_++;
                self->unk_13a8 = 4;
                self->unk_13aa = 1;
            }
            self->unk_13a9 = 0;
        }
        else if (g_keyManager.TestKeysPressed(R(0x20, 0x10)) || func_0205df38(self->window_, 8))
        {
#if defined(jpn)
            func_ov023_021e65a0(self);
#else
            SetThreeElementFields_021e6378(self, 8, 1, 0, 1);
#endif
            changed = 1;
            canCancel = 0;
            func_ov012_02185bf0(self, 9, 1);
        }
        else if (func_0205df38(self->window_, 7))
        {
            GameState::GetInstance();
#if defined(jpn)
            func_ov023_021e655c(self);
#else
            SetThreeElementFields_021e6378(self, 7, 0, 1, 1);
#endif
            changed = 1;
            canCancel = 0;
            func_ov012_02185bf0(self, 9, 1);
        }
        else if (func_0205df38(self->window_, 9))
        {
            canCancel = 0;
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
            Profile02187fe4* profile = GetProfile02187fe4(gameState);
            func_ov012_02185bf0(self, self->state_, 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            profile->year_ = self->year_;
            profile->month_ = self->month_;
            profile->day_ = self->day_;
            profile->birthdayChosen_ = 1;
            profile->unk_4_0 = CalculateAge_02098f20(self->year_, self->month_, self->day_);
#if defined(jpn)
            func_ov012_0218bba0(self, 0, -1);
#else
            func_ov012_0218adac(self, 0, -1, 0);
#endif
            self->state_ = 6;
            self->step_ = 0;
        }
        else if (TestFlagsAndActiveElement2_021e6e20((Obj021e6e20*)self) && canCancel)
        {
            close = 1;
        }
        if (!close)
            return;
        ResetEntryList0205d6a0((Entry_0205d6a0*)self->window_, 1);
        self->step_++;
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
        self->unk_13a0 = 1;
        self->unk_13a8 = -1;
        self->unk_13a9 = 0;
        self->step_ = 1;
        return;
    }
}
