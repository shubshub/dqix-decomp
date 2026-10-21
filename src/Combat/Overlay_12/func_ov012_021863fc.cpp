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

struct Messages021863fc
{
    char unk_0[0x5c];
    void* unk_5c;
    char unk_60[0x998 - 0x60];
    int busy_;
};

struct Appearance021863fc
{
    short models_[10];
    unsigned char female_ : 1;
    unsigned char eyeColor_ : 3;
    unsigned char skinColor_ : 4;
};

struct Party021863fc
{
    char unk_0[0x488];
    Appearance021863fc appearance_;
};

struct Member021863fc
{
    char unk_0[0x150];
    Party021863fc* partyData_;
};

struct Profile021863fc
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

struct Save021863fc
{
    char unk_0[0x5400];
    Profile021863fc profile_;
};

struct GameStateSave021863fc
{
    char unk_0[0x29c];
    Save021863fc save_;
};

struct Card021863fc
{
    char unk_0[0x5f4];
    void* strings_;
    void* texts_;
    char* unk_5fc;
    char unk_600[4];
    void* renderer_;
    void* sprites_;
    char unk_60c[0x614 - 0x60c];
};

struct ProfileEditor021863fc
{
    char unk_0[0x20];
    SafeAllocator allocators_[7];
    char unk_ac[0xd28 - 0xac];
    Card021863fc card_;
    char strings_[8];
    char texts_[0x18];
    void* renderer_;
    void* unk_1360;
    void* sprites_;
    void* renderer2_;
    void* sprites2_;
    unsigned char step_;
    unsigned char state_;
    char unk_1372[2];
    char* text_;
    const char* unk_1378;
    void* pixels_;
    int tasks_[6];
    char unk_1398[0x13bc - 0x1398];
    char* unk_13bc;
    signed char* unk_13c0;
    unsigned short unk_13c4_0 : 5;
    unsigned short unk_13c4_5 : 11;
    char unk_13c6[2];
    unsigned short* unk_13c8;
    unsigned int* unk_13cc;
};

struct TableA68;

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
extern "C" void func_ov023_021e7220(void* card, int mode);
void CreateThreeAllocators_021e71b4(void* card, SafeAllocator* allocator);
extern "C" int func_ov023_021e76c4(void* card);
int GetField0x3acValue_020100a8(GameState* gameState);
extern "C" void func_ov023_021e7b34(void* card, int design);
extern "C" void func_ov012_0218adac(ProfileEditor021863fc* self, int animate, int design, int keepPage);
extern "C" void* func_0205ec34();
int TestBitInByteArray_0206dfb0(int a, unsigned char* bits, int index);
const char* FindEntryByKey_02072a68(TableA68* table, int key);
#if !defined(jpn)
extern "C" void func_0204500c(Messages021863fc* messages, const char* text, int a, int b);
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

static inline Profile021863fc* GetProfile021863fc(GameState* gameState)
{
    return &((GameStateSave021863fc*)gameState)->save_.profile_;
}

#if defined(jpn)
struct MessagesJ021863fc
{
    char unk_0[0x28];
    void* unk_28;
    char unk_2c[0x868 - 0x2c];
    int busy_;
};

struct PartyJ021863fc
{
    char unk_0[0x488];
    Appearance021863fc appearance_;
};

struct MemberJ021863fc
{
    char unk_0[0x144];
    PartyJ021863fc* partyData_;
};

struct GameStateSaveJ021863fc
{
    char unk_0[0x3c];
    Save021863fc save_;
};

struct CardJ021863fc
{
    char unk_0[0x5f4];
    void* strings_;
    void* texts_;
    char* unk_5fc;
    char unk_600[0x608 - 0x600];
};

struct PaneJ021863fc
{
    char unk_0[0x12];
    unsigned short active_;
    char unk_14[0x1c - 0x14];
    SafeAllocator* allocators_;
};

struct ProfileEditorJ021863fc
{
    char unk_0[0x18];
    SafeAllocator allocators_[7];
    char unk_a4[0xd0c - 0xa4];
    CardJ021863fc card_;
    char strings_[8];
    char texts_[0x18];
    char unk_1334[0x1340 - 0x1334];
    unsigned char step_;
    unsigned char state_;
    char unk_1342[2];
    char* text_;
    char unk_1348[0x1350 - 0x1348];
    int tasks_[4];
    char unk_1360[0x1414 - 0x1360];
    char* unk_1414;
    signed char* unk_1418;
    unsigned short unk_141c_0 : 5;
    unsigned short unk_141c_5 : 11;
    char unk_141e[2];
    unsigned short* unk_1420;
    unsigned int* unk_1424;
    char unk_1428[0x14d8 - 0x1428];
    PaneJ021863fc pane_;
};

static inline Profile021863fc* GetProfileJ021863fc(GameState* gameState)
{
    return &((GameStateSaveJ021863fc*)gameState)->save_.profile_;
}

extern "C" void func_ov012_021856c8(PaneJ021863fc* pane);
extern "C" void func_ov012_02185690(PaneJ021863fc* pane);
extern "C" int func_ov012_02186f3c(PaneJ021863fc* pane);
extern "C" void func_ov012_0218bba0(void* self, int animate, int design);
extern "C" void func_0204500c(MessagesJ021863fc* messages, const char* text, int a);
extern "C" const char data_ov012_0218bf66[];
extern "C" const char data_ov012_0218bf81[];
extern "C" const char data_ov012_0218bf9a[];
extern "C" const char data_ov012_0218bfad[];

// USA: func_ov012_021863fc
extern "C" ARM void func_ov012_021863fc(ProfileEditorJ021863fc* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GetGlobal02109400_02094a00();
    if (self->step_ == 0)
    {
        if (IsField0Null_02046b08(*(void***)((char*)resources + 0x34f0)))
        {
            SetFlags00(resources, 0x10);
            OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 0xf);
            self->text_ = (char*)((MessagesJ021863fc*)GetGlobalField0x1c020421a0())->unk_28;
            unsigned int female = 0;
            MemberJ021863fc* protagonist = (MemberJ021863fc*)gameState->GetProtagonist();
            if (protagonist != 0)
                female = protagonist->partyData_->appearance_.female_;
            char archive[0x40];
            sprintf(archive, data_ov012_0218bf66, female);
            self->tasks_[0] = loader->QueueLoadFile(data_ov012_0218bf81, 0);
            self->tasks_[1] = loader->QueueLoadFile(archive, 0);
            self->tasks_[2] = loader->QueueLoadFile(data_ov012_0218bf9a, 0);
            self->tasks_[3] = loader->QueueLoadFile(data_ov012_0218bfad, 0);
            OrGlobalFlag0x40_020dc2bc();
            self->step_++;
        }
        return;
    }
    else if (self->step_ == 1)
    {
        int i;
        int done = 0;
        for (i = 0; i < 4; i++)
        {
            if (self->tasks_[i] == -1)
            {
                done++;
            }
            else if (loader->GetTaskStatus(self->tasks_[i]))
            {
                switch (i)
                {
                    case 0:
                        func_ov012_02185e18((ProfileEditor021863fc*)self);
                        break;
                    case 1:
                        ResetAndRebuildEntry_02185f04((char*)self);
                        break;
                    case 2:
                        func_ov012_02185f74((ProfileEditor021863fc*)self);
                        break;
                    case 3:
                        func_ov012_021861e0((ProfileEditor021863fc*)self);
                        break;
                }
                break;
            }
        }
        if (done == 4)
            self->step_++;
        return;
    }
    else if (self->step_ == 2)
    {
        func_ov012_02184654((ProfileEditor021863fc*)self);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 0;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        FontBankLoader* music = GetGlobal02109400_02094a00();
        func_02094ab0(music);
        BlankFunction02094b34(music, 0x6e, 0x1ff, 0, 0);
        SetSubBrightness(resources, -16, 15);
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) && !IsSubBrightnessTransitionActive(resources))
        {
            OrGlobalFlag0x40_020dc2bc();
            self->allocators_[2].Reset();
            func_ov023_021e7220(&self->card_, 2);
            CreateThreeAllocators_021e71b4(&self->card_, &self->allocators_[2]);
            self->card_.strings_ = &self->strings_;
            self->card_.texts_ = &self->texts_;
            self->card_.unk_5fc = self->unk_1414;
            func_ov012_021856c8(&self->pane_);
            func_ov012_02185690(&self->pane_);
            self->pane_.allocators_ = &self->allocators_[0];
            self->pane_.active_ = 1;
            func_ov012_02186f3c(&self->pane_);
            self->step_++;
            return;
        }
    }
    else if (self->step_ == 4)
    {
        if (func_ov012_02186f3c(&self->pane_) && func_ov023_021e76c4(&self->card_))
        {
            func_ov023_021e7b34(&self->card_, GetField0x3acValue_020100a8(gameState));
            func_ov012_0218bba0(self, 1, -1);
            SetSubBrightness(resources, 0, 15);
            void* unk = func_0205ec34();
            for (int i = 0; i < 0x12; i++)
            {
                if (TestBitInByteArray_0206dfb0((int)unk, (unsigned char*)unk + 0x8c, i + 0x200))
                {
                    self->unk_1418[self->unk_141c_0] = i;
                    self->unk_141c_0++;
                }
            }
            for (int i = 0; i < 0x1e0; i++)
            {
                if (self->unk_1424[i / 32] & (1 << (i % 32)))
                {
                    self->unk_1420[self->unk_141c_5] = i;
                    self->unk_141c_5++;
                }
            }
            Profile021863fc* profile = GetProfileJ021863fc(gameState);
            if (profile->edited_ == 0)
            {
                self->step_++;
                return;
            }
            self->state_ = 1;
            self->step_ = 0;
            return;
        }
    }
    else if (self->step_ == 5)
    {
        MessagesJ021863fc* messages = (MessagesJ021863fc*)GetGlobalField0x1c020421a0();
        func_0204500c(messages, FindEntryByKey_02072a68((TableA68*)self->strings_, 500), 0);
        messages->busy_ = 1;
        self->step_++;
        return;
    }
    else if (self->step_ == 6)
    {
        if (((MessagesJ021863fc*)GetGlobalField0x1c020421a0())->busy_ == 0)
        {
            Profile021863fc* profile = GetProfileJ021863fc(gameState);
            profile->edited_ = 1;
            self->state_ = 1;
            self->step_ = 0;
        }
    }
}
#else
// USA: func_ov012_021863fc
extern "C" ARM void func_ov012_021863fc(ProfileEditor021863fc* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GetGlobal02109400_02094a00();
    if (self->step_ == 0)
    {
        if (IsField0Null_02046b08(*(void***)((char*)resources + 0x3700)))
        {
            SetFlags00(resources, 0x10);
            OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 0xf);
            self->text_ = (char*)GetGlobalField0x1c020421a0()->unk_5c;
            unsigned int female = 0;
            Member021863fc* protagonist = (Member021863fc*)gameState->GetProtagonist();
            if (protagonist != 0)
                female = protagonist->partyData_->appearance_.female_;
            char archive[0x40];
            char file[0x20];
            sprintf(archive, data_ov012_0218b224, female);
            sprintf(file, data_ov012_0218b23b, female);
            self->tasks_[0] = loader->QueueLoadFileInGP2(data_ov012_0218b24e, data_ov012_0218b263, 0);
            self->tasks_[1] = loader->QueueLoadFileInGP2(data_ov012_0218b274, data_ov012_0218b289, 0);
            self->tasks_[2] = loader->QueueLoadFileInGP2(archive, file, 0);
            self->tasks_[3] = loader->QueueLoadFile(data_ov012_0218b29a, 0);
            self->tasks_[4] = loader->QueueLoadFileInGP2(data_ov012_0218b2ad, data_ov012_0218b2c2, 0);
            self->tasks_[5] = loader->QueueLoadFile(data_ov012_0218b2d3, 0);
            OrGlobalFlag0x40_020dc2bc();
            self->step_++;
        }
        return;
    }
    else if (self->step_ == 1)
    {
        int i;
        int done = 0;
        for (i = 0; i < 6; i++)
        {
            if (self->tasks_[i] == -1)
            {
                done++;
            }
            else if (loader->GetTaskStatus(self->tasks_[i]))
            {
                switch (i)
                {
                    case 0:
                        func_ov012_02185e18(self);
                        break;
                    case 1:
                        ClearAndCopyEntry_02185ea8((char*)self);
                        break;
                    case 2:
                        ResetAndRebuildEntry_02185f04((char*)self);
                        break;
                    case 3:
                        func_ov012_02185f74(self);
                        break;
                    case 4:
                        func_ov012_021861e0(self);
                        break;
                    case 5:
                        func_ov012_021862fc(self);
                        break;
                }
                break;
            }
        }
        if (done == 6)
            self->step_++;
        return;
    }
    else if (self->step_ == 2)
    {
        func_ov012_02184654(self);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 0;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        FontBankLoader* music = GetGlobal02109400_02094a00();
        func_02094ab0(music);
        BlankFunction02094b34(music, 0x6e, 0x1ff, 0, 0);
        SetSubBrightness(resources, -16, 15);
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) && !IsSubBrightnessTransitionActive(resources))
        {
            OrGlobalFlag0x40_020dc2bc();
            self->allocators_[2].Reset();
            func_ov023_021e7220(&self->card_, 2);
            CreateThreeAllocators_021e71b4(&self->card_, &self->allocators_[2]);
            self->card_.strings_ = &self->strings_;
            self->card_.texts_ = &self->texts_;
            self->card_.unk_5fc = self->unk_13bc;
            self->card_.renderer_ = self->renderer2_;
            self->card_.sprites_ = self->sprites2_;
            self->step_++;
            return;
        }
    }
    else if (self->step_ == 4)
    {
        if (func_ov023_021e76c4(&self->card_))
        {
            func_ov023_021e7b34(&self->card_, GetField0x3acValue_020100a8(gameState));
            func_ov012_0218adac(self, 1, -1, 0);
            SetSubBrightness(resources, 0, 15);
            void* unk = func_0205ec34();
            for (int i = 0; i < 0x12; i++)
            {
                if (TestBitInByteArray_0206dfb0((int)unk, (unsigned char*)unk + 0x8c, i + 0x200))
                {
                    self->unk_13c0[self->unk_13c4_0] = i;
                    self->unk_13c4_0++;
                }
            }
            for (int i = 0; i < 0x1e0; i++)
            {
                if (self->unk_13cc[i / 32] & (1 << (i % 32)))
                {
                    self->unk_13c8[self->unk_13c4_5] = i;
                    self->unk_13c4_5++;
                }
            }
            Profile021863fc* profile = GetProfile021863fc(gameState);
            if (profile->edited_ == 0)
            {
                self->step_++;
            }
            else
            {
                self->state_ = 1;
                self->step_ = 0;
            }
            unsigned short color = 0x294a;
            void* pixels = self->pixels_;
            memcpy(pixels, &color, sizeof(color));
            CleanInvalidateCacheRange(pixels, sizeof(color));
            LoadToMainBGStandardPalette(pixels, 4, sizeof(color));
            CleanCacheRange(pixels, sizeof(color));
            unsigned short color2 = 0x1ce7;
            void* pixels2 = self->pixels_;
            memcpy(pixels2, &color2, sizeof(color2));
            CleanInvalidateCacheRange(pixels2, sizeof(color2));
            LoadToMainBGStandardPalette(pixels2, 8, sizeof(color2));
            CleanCacheRange(pixels2, sizeof(color2));
            return;
        }
    }
    else if (self->step_ == 5)
    {
        Messages021863fc* messages = GetGlobalField0x1c020421a0();
        func_0204500c(messages, FindEntryByKey_02072a68((TableA68*)self->strings_, 500), 0, 0xe3);
        messages->busy_ = 1;
        self->step_++;
        return;
    }
    else if (self->step_ == 6)
    {
        if (GetGlobalField0x1c020421a0()->busy_ == 0)
        {
            Profile021863fc* profile = GetProfile021863fc(gameState);
            profile->edited_ = 1;
            self->state_ = 1;
            self->step_ = 0;
        }
    }
}
#endif
