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


struct Messages021863fc
{
    char unk_0[0x5c];
    void* unk_5c;
    char unknown_60_[0x998 - 0x60];
    int busy_;
};

struct Struct_ov012_021863fc_9
{
    short models_[10];
    unsigned char female_ : 1;
    unsigned char skinColor_ : 3;
    unsigned char eyeColor_ : 4;
};

struct Struct_ov012_021863fc_11
{
    char unk_0[0x488];
    Struct_ov012_021863fc_9 appearance_;
};

struct Struct_ov012_021863fc_12
{
    char unk_0[0x150];
    Struct_ov012_021863fc_11* unknown_150_;
};

struct Struct_ov012_021863fc_13
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

struct Struct_01ff8b48_6
{
    char unk_0[0x5400];
    Struct_ov012_021863fc_13 unknown_5400_;
};

struct Struct_01ff8b48_7
{
    char unk_0[0x29c];
    Struct_01ff8b48_6 unknown_29c_;
};

struct Struct_ov012_021863fc
{
    char unk_0[0x5f4];
    void* strings_;
    void* texts_;
    char* unknown_5fc_;
    char unknown_600_[4];
    void* renderer_;
    void* sprites_;
    char unknown_60c_[0x614 - 0x60c];
};

struct Struct_ov012_021863fc_2
{
    char unk_0[0x20];
    SafeAllocator allocators_[7];
    char unk_ac[0xd28 - 0xac];
    Struct_ov012_021863fc card_;
    char strings_[8];
    char texts_[0x18];
    void* renderer_;
    void* unk_1360;
    void* sprites_;
    void* unknown_1368_;
    void* unknown_136c_;
    unsigned char step_;
    unsigned char state_;
    char unknown_1372_[2];
    char* text_;
    const char* unk_1378;
    void* pixels_;
    int tasks_[6];
    char unk_1398[0x13bc - 0x1398];
    char* unknown_13bc_;
    signed char* unk_13c0;
    unsigned short unknown_13c4_0_ : 5;
    unsigned short unknown_13c4_5_ : 11;
    char unknown_13c6_[2];
    unsigned short* unk_13c8;
    unsigned int* unknown_13cc_;
};

struct TableA68;

extern "C" int FieldTaskQueue_IsEmpty(void** p);
extern "C" void* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int* word, unsigned int bits);
extern "C" Messages021863fc* MessageSystem_GetInstance();
extern "C" void func_020dc2bc();
extern "C" void func_ov012_02185e18(Struct_ov012_021863fc_2* self);
extern "C" void func_ov012_02185ea8(char* self);
extern "C" void func_ov012_02185f04(char* self);
extern "C" void func_ov012_02185f74(Struct_ov012_021863fc_2* self);
extern "C" void func_ov012_021861e0(Struct_ov012_021863fc_2* self);
extern "C" void func_ov012_021862fc(Struct_ov012_021863fc_2* self);
extern "C" void func_ov012_02184654(Struct_ov012_021863fc_2* self);
void SetSubBrightness(GameResources* resources, int brightness, int frames);
int IsSubBrightnessTransitionActive(GameResources* resources);
extern "C" void func_ov023_021e7220(void* arg0, int mode);
extern "C" void func_ov023_021e71b4(void* arg0, SafeAllocator* allocator);
extern "C" int func_ov023_021e76c4(void* arg0);
extern "C" int GameState_GetProtagonistIndex(GameState* gameState);
extern "C" void func_ov023_021e7b34(void* arg0, int arg1);
extern "C" void func_ov012_0218adac(Struct_ov012_021863fc_2* self, int arg1, int arg2, int arg3);
extern "C" void* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int a, unsigned char* bits, int index);
extern "C" const char* func_02072a68(TableA68* table, int key);
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

static inline Struct_ov012_021863fc_13* inline_ov012_021863fc(GameState* gameState)
{
    return &((Struct_01ff8b48_7*)gameState)->unknown_29c_.unknown_5400_;
}

#if defined(jpn)
struct MessagesJ021863fc
{
    char unk_0[0x28];
    void* unk_28;
    char unk_2c[0x868 - 0x2c];
    int busy_;
};

struct Struct_ov012_021863fc_5
{
    char unk_0[0x488];
    Struct_ov012_021863fc_9 appearance_;
};

struct Struct_ov012_021863fc_6
{
    char unk_0[0x144];
    Struct_ov012_021863fc_5* unknown_144_;
};

struct Struct_01ff8b48_8
{
    char unk_0[0x3c];
    Struct_01ff8b48_6 unknown_3c_;
};

struct Struct_ov012_021863fc_7
{
    char unk_0[0x5f4];
    void* strings_;
    void* texts_;
    char* unknown_5fc_;
    char unknown_600_[0x608 - 0x600];
};

struct Struct_ov012_021863fc_8
{
    char unk_0[0x12];
    unsigned short active_;
    char unk_14[0x1c - 0x14];
    SafeAllocator* allocators_;
};

struct Struct_ov012_021863fc_10
{
    char unk_0[0x18];
    SafeAllocator allocators_[7];
    char unknown_a4_[0xd0c - 0xa4];
    Struct_ov012_021863fc_7 card_;
    char strings_[8];
    char texts_[0x18];
    char unknown_1334_[0x1340 - 0x1334];
    unsigned char step_;
    unsigned char state_;
    char unknown_1342_[2];
    char* text_;
    char unknown_1348_[0x1350 - 0x1348];
    int tasks_[4];
    char unk_1360[0x1414 - 0x1360];
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

static inline Struct_ov012_021863fc_13* inline_ov012_021863fc_2(GameState* gameState)
{
    return &((Struct_01ff8b48_8*)gameState)->unknown_3c_.unknown_5400_;
}

extern "C" void func_ov012_021856c8(Struct_ov012_021863fc_8* pane);
extern "C" void func_ov012_02185690(Struct_ov012_021863fc_8* pane);
extern "C" int func_ov012_02186f3c(Struct_ov012_021863fc_8* pane);
extern "C" void func_ov012_0218bba0(void* self, int arg1, int arg2);
extern "C" void func_0204500c(MessagesJ021863fc* messages, const char* text, int a);
extern "C" const char data_ov012_0218bf66[];
extern "C" const char data_ov012_0218bf81[];
extern "C" const char data_ov012_0218bf9a[];
extern "C" const char data_ov012_0218bfad[];

// USA: func_ov012_021863fc
extern "C" ARM void func_ov012_021863fc(Struct_ov012_021863fc_10* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    FontBankLoader_GetInstance();
    if (self->step_ == 0)
    {
        if (FieldTaskQueue_IsEmpty(*(void***)((char*)resources + 0x34f0)))
        {
            SetFlags00(resources, 0x10);
            FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0xf);
            self->text_ = (char*)((MessagesJ021863fc*)MessageSystem_GetInstance())->unk_28;
            unsigned int female = 0;
            Struct_ov012_021863fc_6* protagonist = (Struct_ov012_021863fc_6*)gameState->GetProtagonist();
            if (protagonist != 0)
                female = protagonist->unknown_144_->appearance_.female_;
            char archive[0x40];
            sprintf(archive, data_ov012_0218bf66, female);
            self->tasks_[0] = loader->QueueLoadFile(data_ov012_0218bf81, 0);
            self->tasks_[1] = loader->QueueLoadFile(archive, 0);
            self->tasks_[2] = loader->QueueLoadFile(data_ov012_0218bf9a, 0);
            self->tasks_[3] = loader->QueueLoadFile(data_ov012_0218bfad, 0);
            func_020dc2bc();
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
                        func_ov012_02185e18((Struct_ov012_021863fc_2*)self);
                        break;
                    case 1:
                        func_ov012_02185f04((char*)self);
                        break;
                    case 2:
                        func_ov012_02185f74((Struct_ov012_021863fc_2*)self);
                        break;
                    case 3:
                        func_ov012_021861e0((Struct_ov012_021863fc_2*)self);
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
        func_ov012_02184654((Struct_ov012_021863fc_2*)self);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 0;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        FontBankLoader* music = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(music);
        func_02094b34(music, 0x6e, 0x1ff, 0, 0);
        SetSubBrightness(resources, -16, 15);
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        if (func_02094b4c(FontBankLoader_GetInstance()) && !IsSubBrightnessTransitionActive(resources))
        {
            func_020dc2bc();
            self->allocators_[2].Reset();
            func_ov023_021e7220(&self->card_, 2);
            func_ov023_021e71b4(&self->card_, &self->allocators_[2]);
            self->card_.strings_ = &self->strings_;
            self->card_.texts_ = &self->texts_;
            self->card_.unknown_5fc_ = self->unknown_1414_;
            func_ov012_021856c8(&self->unknown_14d8_);
            func_ov012_02185690(&self->unknown_14d8_);
            self->unknown_14d8_.allocators_ = &self->allocators_[0];
            self->unknown_14d8_.active_ = 1;
            func_ov012_02186f3c(&self->unknown_14d8_);
            self->step_++;
            return;
        }
    }
    else if (self->step_ == 4)
    {
        if (func_ov012_02186f3c(&self->unknown_14d8_) && func_ov023_021e76c4(&self->card_))
        {
            func_ov023_021e7b34(&self->card_, GameState_GetProtagonistIndex(gameState));
            func_ov012_0218bba0(self, 1, -1);
            SetSubBrightness(resources, 0, 15);
            void* unk = Scenario_GetInstance();
            for (int i = 0; i < 0x12; i++)
            {
                if (Scenario_TestFlag((int)unk, (unsigned char*)unk + 0x8c, i + 0x200))
                {
                    self->unknown_1418_[self->unknown_141c_0_] = i;
                    self->unknown_141c_0_++;
                }
            }
            for (int i = 0; i < 0x1e0; i++)
            {
                if (self->unknown_1424_[i / 32] & (1 << (i % 32)))
                {
                    self->unknown_1420_[self->unknown_141c_5_] = i;
                    self->unknown_141c_5_++;
                }
            }
            Struct_ov012_021863fc_13* profile = inline_ov012_021863fc_2(gameState);
            if (profile->unknown_7_6_ == 0)
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
        MessagesJ021863fc* messages = (MessagesJ021863fc*)MessageSystem_GetInstance();
        func_0204500c(messages, func_02072a68((TableA68*)self->strings_, 500), 0);
        messages->busy_ = 1;
        self->step_++;
        return;
    }
    else if (self->step_ == 6)
    {
        if (((MessagesJ021863fc*)MessageSystem_GetInstance())->busy_ == 0)
        {
            Struct_ov012_021863fc_13* profile = inline_ov012_021863fc_2(gameState);
            profile->unknown_7_6_ = 1;
            self->state_ = 1;
            self->step_ = 0;
        }
    }
}
#else
// USA: func_ov012_021863fc
extern "C" ARM void func_ov012_021863fc(Struct_ov012_021863fc_2* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    FontBankLoader_GetInstance();
    if (self->step_ == 0)
    {
        if (FieldTaskQueue_IsEmpty(*(void***)((char*)resources + 0x3700)))
        {
            SetFlags00(resources, 0x10);
            FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0xf);
            self->text_ = (char*)MessageSystem_GetInstance()->unk_5c;
            unsigned int female = 0;
            Struct_ov012_021863fc_12* protagonist = (Struct_ov012_021863fc_12*)gameState->GetProtagonist();
            if (protagonist != 0)
                female = protagonist->unknown_150_->appearance_.female_;
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
            func_020dc2bc();
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
                        func_ov012_02185ea8((char*)self);
                        break;
                    case 2:
                        func_ov012_02185f04((char*)self);
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
        FontBankLoader* music = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(music);
        func_02094b34(music, 0x6e, 0x1ff, 0, 0);
        SetSubBrightness(resources, -16, 15);
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        if (func_02094b4c(FontBankLoader_GetInstance()) && !IsSubBrightnessTransitionActive(resources))
        {
            func_020dc2bc();
            self->allocators_[2].Reset();
            func_ov023_021e7220(&self->card_, 2);
            func_ov023_021e71b4(&self->card_, &self->allocators_[2]);
            self->card_.strings_ = &self->strings_;
            self->card_.texts_ = &self->texts_;
            self->card_.unknown_5fc_ = self->unknown_13bc_;
            self->card_.renderer_ = self->unknown_1368_;
            self->card_.sprites_ = self->unknown_136c_;
            self->step_++;
            return;
        }
    }
    else if (self->step_ == 4)
    {
        if (func_ov023_021e76c4(&self->card_))
        {
            func_ov023_021e7b34(&self->card_, GameState_GetProtagonistIndex(gameState));
            func_ov012_0218adac(self, 1, -1, 0);
            SetSubBrightness(resources, 0, 15);
            void* unk = Scenario_GetInstance();
            for (int i = 0; i < 0x12; i++)
            {
                if (Scenario_TestFlag((int)unk, (unsigned char*)unk + 0x8c, i + 0x200))
                {
                    self->unk_13c0[self->unknown_13c4_0_] = i;
                    self->unknown_13c4_0_++;
                }
            }
            for (int i = 0; i < 0x1e0; i++)
            {
                if (self->unknown_13cc_[i / 32] & (1 << (i % 32)))
                {
                    self->unk_13c8[self->unknown_13c4_5_] = i;
                    self->unknown_13c4_5_++;
                }
            }
            Struct_ov012_021863fc_13* profile = inline_ov012_021863fc(gameState);
            if (profile->unknown_7_6_ == 0)
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
            unsigned short var31 = 0x1ce7;
            void* var32 = self->pixels_;
            memcpy(var32, &var31, sizeof(var31));
            CleanInvalidateCacheRange(var32, sizeof(var31));
            LoadToMainBGStandardPalette(var32, 8, sizeof(var31));
            CleanCacheRange(var32, sizeof(var31));
            return;
        }
    }
    else if (self->step_ == 5)
    {
        Messages021863fc* messages = MessageSystem_GetInstance();
        func_0204500c(messages, func_02072a68((TableA68*)self->strings_, 500), 0, 0xe3);
        messages->busy_ = 1;
        self->step_++;
        return;
    }
    else if (self->step_ == 6)
    {
        if (MessageSystem_GetInstance()->busy_ == 0)
        {
            Struct_ov012_021863fc_13* profile = inline_ov012_021863fc(gameState);
            profile->unknown_7_6_ = 1;
            self->state_ = 1;
            self->step_ = 0;
        }
    }
}
#endif
