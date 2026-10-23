#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Input/Input.h"

struct Struct_02072a68_2;
struct Struct_0205d6a0;
struct Struct_ov003_0215e6d8;
struct Struct_ov003_0215efb8;
struct Struct_0205de24_2;
struct Struct_0205def8;
struct SePlayer;

struct Struct_ov012_02188cd0_2
{
    void* unknown_0_;
    void* unknown_4_;
    char* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    short unknown_1c_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned char unknown_20_;
    unsigned char unknown_21_;
    unsigned char unknown_22_;
    unsigned char unknown_23_;
    unsigned char unknown_24_;
    char unknown_25_[3];
};

struct Struct_ov012_02188cd0_3
{
    char unknown_0_[8];
    char unknown_8_[0x74];
};

struct Struct_01ff8b48_10
{
    char unknown_0_[0x5400];
    Struct_ov012_02188cd0_3 unknown_5400_;
};

struct Struct_01ff8b48_11
{
    char unknown_0_[0x29c];
    Struct_01ff8b48_10 unknown_29c_;
};

struct Struct_ov012_02188cd0_4
{
    char unknown_0_[0x998];
    int unknown_998_;
};

struct Struct_ov012_02188cd0
{
    void* unknown_0_;
    void* unknown_4_;
    char unknown_8_[0x20 - 0x8];
    char unknown_20_[7][0x14];
    char unknown_ac_[0xd28 - 0xac];
    char unknown_d28_[0x600];
    char* unknown_1328_;
    char unknown_132c_[0x133c - 0x132c];
    char unknown_133c_[0x1370 - 0x133c];
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    char unknown_1372_[0x1380 - 0x1372];
    int unknown_1380_[6];
    int unknown_1398_;
    int unknown_139c_;
    unsigned char unknown_13a0_;
    char unknown_13a1_[3];
    int unknown_13a4_;
    char unknown_13a8_[4];
    void* unknown_13ac_;
    char unknown_13b0_[0x13d0 - 0x13b0];
    char* unknown_13d0_;
    char unknown_13d4_[0x1480 - 0x13d4];
    unsigned char unknown_1480_[0x14bc - 0x1480];
};

void ResetEntryList0205d6a0(Entry_0205d6a0* window, int a);
extern "C" void func_02042764(const void* codes, char* text, int a);
void KeyboardLayout_Init(ResetLayout_0215e6d8* layout);
extern "C" void KeyboardLayout_Load(void* layout, SafeAllocator* allocator, void* file, unsigned int size);
void Keyboard_Init(Struct0215efb8* keyboard);
extern "C" int func_ov012_0218ae74(ProfileEditor02188cd0* self, Profile02188cd0* profile);
void FindAndLinkMatchingEntry0205de24(Struct0205de24* window, unsigned char a, unsigned char b);
extern "C" void func_ov023_021e6e60(ProfileEditor02188cd0* self);
void SetupBattleTag0218aabc(char* self);
extern "C" void Keyboard_ResetToKey(void* keyboard, const char* text);
extern "C" void func_ov012_0218ab34(ProfileEditor02188cd0* self, char* text, int hidden);
extern "C" int func_0205d97c(void* window);
extern "C" int Keyboard_Update(void* keyboard, int input);
void SePlayer_Play(SePlayer* sound, int effect, int a);
extern "C" void func_ov023_021e8270(void* card);
extern "C" void func_ov012_021845f8(void* checker);
extern "C" int func_ov012_02184d80(void* checker, char* text);
void SetElementFlag0x20ByKey0205def8(Struct_0205def8* window, int a, int b);
extern "C" void Font_EncodeText(const char* text, char* codes, int a);
extern "C" void func_ov012_0218943c(ProfileEditor02188cd0* self);
Messages02188cd0* GetGlobalField0x1c020421a0();
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
extern "C" void func_0204500c(Messages02188cd0* messages, const char* text, int a, int b);

extern "C" const char data_ov012_0218b2ea[];
extern "C" const char data_ov012_0218b303[];
extern "C" char g_sePlayer[];

static inline Struct_ov012_02188cd0_3* inline_ov012_02188cd0(GameState* arg0)
{
    return &((Struct_01ff8b48_11*)arg0)->unknown_29c_.unknown_5400_;
}

// USA: func_ov012_02188cd0
extern "C" ARM void func_ov012_02188cd0(Struct_ov012_02188cd0* arg0)
{
    if (arg0->unknown_1370_ == 0)
    {
        func_0205d6a0((Struct_0205d6a0*)arg0->unknown_ac_, 1);
        Struct_ov012_02188cd0_3* var0 = inline_ov012_02188cd0(GameState::GetInstance());
        memset(arg0->unknown_13d0_, 0, 0x400);
        arg0->unknown_1328_ = arg0->unknown_13d0_;
        func_02042764(var0->unknown_8_, arg0->unknown_13d0_, 1);
        arg0->unknown_1380_[0] = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov012_0218b2ea, 0);
        arg0->unknown_1370_++;
        return;
    }
    else if (arg0->unknown_1370_ == 1)
    {
        BackgroundLoader* var1 = BackgroundLoader::GetInstance();
        if (var1->GetTaskStatus(arg0->unknown_1380_[0]))
        {
            if (var1->GetDetailedTaskStatus(arg0->unknown_1380_[0]) != 2)
            {
                var1->RemoveTask(arg0->unknown_1380_[0]);
                arg0->unknown_1380_[0] = -1;
            }
            void* var2;
            unsigned int var3;
            var1->GetLoadedFileByID(arg0->unknown_1380_[0], &var2, &var3);
            if (var2 != 0 && var3 != 0)
            {
                ((SafeAllocator*)self->allocators_[4])->Reset();
                KeyboardLayout_Init((ResetLayout_0215e6d8*)self->unk_4);
                KeyboardLayout_Load(self->unk_4, (SafeAllocator*)self->allocators_[4], file, size);
                Keyboard_Init((Struct0215efb8*)self->unk_0);
                ((Keyboard02188cd0*)self->unk_0)->layout_ = self->unk_4;
                ((Keyboard02188cd0*)self->unk_0)->key_ = 0;
            }
            var1->RemoveTask(arg0->unknown_1380_[0]);
            arg0->unknown_1380_[0] = -1;
            arg0->unknown_1370_++;
            return;
        }
        return;
    }
    else if (arg0->unknown_1370_ == 2)
    {
        func_ov012_0218ae74(arg0, inline_ov012_02188cd0(GameState::GetInstance()));
        arg0->unknown_1370_++;
        return;
    }
    else if (arg0->unknown_1370_ == 3)
    {
        self->unk_13a0 = 0;
        FindAndLinkMatchingEntry0205de24((Struct0205de24*)self->window_, 0, 2);
        func_ov023_021e6e60(self);
        SetupBattleTag0218aabc((char*)self);
        memcpy(self->unk_13ac, GetProfile02188cd0(GameState::GetInstance())->unk_8, 0x72);
        Keyboard02188cd0* keyboard = (Keyboard02188cd0*)self->unk_0;
        keyboard->text_ = self->message_;
        keyboard->size_ = 0x400;
        ((Keyboard02188cd0*)self->unk_0)->unk_14 = 0x39;
        ((Keyboard02188cd0*)self->unk_0)->unk_1f = 1;
        ((Keyboard02188cd0*)self->unk_0)->unk_21 = 1;
        ((Keyboard02188cd0*)self->unk_0)->unk_24 = 1;
        Keyboard_ResetToKey(self->unk_0, data_ov012_0218b303);
        ((Keyboard02188cd0*)self->unk_0)->unk_22 = 1;
        ((Keyboard02188cd0*)self->unk_0)->unk_23 = 0;
        func_ov012_0218ab34(self, 0, 0);
        self->step_++;
        return;
    }
    else if (arg0->unknown_1370_ == 4)
    {
        if ((g_keyManager.TestKeysPressed(2) || func_0205d97c(arg0->unknown_ac_) == 2) && *arg0->unknown_13d0_ == 0)
        {
            func_0205d6a0((Struct_0205d6a0*)arg0->unknown_ac_, 1);
            arg0->unknown_1370_++;
        }
        Keyboard02188cd0* keyboard = (Keyboard02188cd0*)self->unk_0;
        unsigned char page = keyboard->unk_20;
        switch (Keyboard_Update(keyboard, self->unk_13a4))
        {
            case 1:
                SePlayer_Play((SePlayer*)g_sePlayer, 2, 0);
                return;

            case 2:
            case 3:
            case 8:
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
                if (page != ((Keyboard02188cd0*)self->unk_0)->unk_20)
                    func_ov012_0218ab34(self, 0, 0);
                func_ov023_021e8270(self->card_);
                return;

            case 4:
            case 5:
            case 6:
            case 7:
            case 11:
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
                func_ov012_0218ab34(self, 0, 0);
                return;

            case 9:
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
                return;

            case 10:
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
                if (*self->message_ != 0)
                {
                    GameState::GetInstance();
                    BackgroundLoader::AddLockGlobal();
                    BackgroundLoader::FreeAllocationsGlobal();
                    func_ov012_021845f8(arg0->unknown_1480_);
                    int var7 = func_ov012_02184d80(arg0->unknown_1480_, arg0->unknown_13d0_);
                    BackgroundLoader::RemoveLockGlobal();
                    if (var7)
                    {
                        func_0205def8((Struct_0205def8*)arg0->unknown_ac_, 0, 14);
                        arg0->unknown_1370_ = 10;
                        return;
                    }
                }
                func_0205d6a0((Struct_0205d6a0*)arg0->unknown_ac_, 1);
                arg0->unknown_1370_++;
                return;
        }
    }
    else if (arg0->unknown_1370_ == 5)
    {
        Font_EncodeText(self->message_, GetProfile02188cd0(GameState::GetInstance())->unk_8, 1);
        self->cardMessage_ = 0;
        memset(self->message_, 0, 0x400);
        self->step_++;
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
        arg0->unknown_1370_ = 1;
        return;
    }
    else if (arg0->unknown_1370_ == 10)
    {
        Struct_ov012_02188cd0_4* var8 = func_020421a0();
        func_0204500c(var8, func_02072a68((Struct_02072a68_2*)arg0->unknown_133c_, 501), 0, 0xe3);
        var8->unknown_998_ = 1;
        arg0->unknown_1370_++;
        return;
    }
    else if (arg0->unknown_1370_ == 11)
    {
        if (func_020421a0()->unknown_998_ == 0)
        {
            func_0205def8((Struct_0205def8*)arg0->unknown_ac_, 1, 14);
            arg0->unknown_1370_ = 4;
            ((Struct_ov012_02188cd0_2*)arg0->unknown_0_)->unknown_18_ = 0;
            ((Struct_ov012_02188cd0_2*)arg0->unknown_0_)->unknown_1c_ = 0;
        }
    }
}
