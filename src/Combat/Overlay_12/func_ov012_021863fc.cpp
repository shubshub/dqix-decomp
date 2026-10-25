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


struct Struct_ov012_021863fc_3
{
    char unknown_0_[0x5c];
    void* unknown_5c_;
    char unknown_60_[0x998 - 0x60];
    int unknown_998_;
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
void* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int* word, unsigned int bits);
Messages021863fc* MessageSystem_GetInstance();
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
int GameState_GetProtagonistIndex(GameState* gameState);
extern "C" void func_ov023_021e7b34(void* card, int design);
extern "C" void func_ov012_0218adac(ProfileEditor021863fc* self, int animate, int design, int keepPage);
extern "C" void* Scenario_GetInstance();
int Scenario_TestFlag(int a, unsigned char* bits, int index);
const char* FindEntryByKey_02072a68(TableA68* table, int key);
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
    FontBankLoader_GetInstance();
    if (self->step_ == 0)
    {
        if (func_02046b08(*(void***)((char*)var1 + 0x34f0)))
        {
            SetFlags00(resources, 0x10);
            FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0xf);
            self->text_ = (char*)((MessagesJ021863fc*)MessageSystem_GetInstance())->unk_28;
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
        FontBankLoader* music = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(music);
        BlankFunction02094b34(music, 0x6e, 0x1ff, 0, 0);
        SetSubBrightness(resources, -16, 15);
        self->step_++;
        return;
    }
    else if (arg0->unknown_1340_ == 3)
    {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()) && !IsSubBrightnessTransitionActive(resources))
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
            func_ov023_021e7b34(&self->card_, GameState_GetProtagonistIndex(gameState));
            func_ov012_0218bba0(self, 1, -1);
            SetSubBrightness(resources, 0, 15);
            void* unk = Scenario_GetInstance();
            for (int i = 0; i < 0x12; i++)
            {
                if (Scenario_TestFlag((int)unk, (unsigned char*)unk + 0x8c, i + 0x200))
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
        MessagesJ021863fc* messages = (MessagesJ021863fc*)MessageSystem_GetInstance();
        func_0204500c(messages, FindEntryByKey_02072a68((TableA68*)self->strings_, 500), 0);
        messages->busy_ = 1;
        self->step_++;
        return;
    }
    else if (arg0->unknown_1340_ == 6)
    {
        if (((MessagesJ021863fc*)MessageSystem_GetInstance())->busy_ == 0)
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
    FontBankLoader_GetInstance();
    if (self->step_ == 0)
    {
        if (func_02046b08(*(void***)((char*)var16 + 0x3700)))
        {
            SetFlags00(resources, 0x10);
            FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0xf);
            self->text_ = (char*)MessageSystem_GetInstance()->unk_5c;
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
        FontBankLoader* music = FontBankLoader_GetInstance();
        FontBankLoader_CancelLoads(music);
        BlankFunction02094b34(music, 0x6e, 0x1ff, 0, 0);
        SetSubBrightness(resources, -16, 15);
        self->step_++;
        return;
    }
    else if (arg0->unknown_1370_ == 3)
    {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()) && !IsSubBrightnessTransitionActive(resources))
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
            func_ov023_021e7b34(&self->card_, GameState_GetProtagonistIndex(gameState));
            func_ov012_0218adac(self, 1, -1, 0);
            SetSubBrightness(resources, 0, 15);
            void* unk = Scenario_GetInstance();
            for (int i = 0; i < 0x12; i++)
            {
                if (Scenario_TestFlag((int)unk, (unsigned char*)unk + 0x8c, i + 0x200))
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
        Messages021863fc* messages = MessageSystem_GetInstance();
        func_0204500c(messages, FindEntryByKey_02072a68((TableA68*)self->strings_, 500), 0, 0xe3);
        messages->busy_ = 1;
        self->step_++;
        return;
    }
    else if (arg0->unknown_1370_ == 6)
    {
        if (MessageSystem_GetInstance()->busy_ == 0)
        {
            Struct_ov012_021863fc_13* var34 = inline_ov012_021863fc(var15);
            var34->unknown_7_6_ = 1;
            arg0->unknown_1371_ = 1;
            arg0->unknown_1370_ = 0;
        }
    }
}
#endif
