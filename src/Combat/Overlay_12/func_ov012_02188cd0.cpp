#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Input/Input.h"

struct TableA68;
struct Entry_0205d6a0;
struct KeyboardLayout;
struct Struct0215efb8;
struct Struct0205de24;
struct Struct_0205def8;
struct SePlayer;

struct Struct_ov012_02188cd0_2
{
    void* key_;
    void* layout_;
    char* text_;
    int unk_c;
    int size_;
    int unk_14;
    int unknown_18_;
    short unk_1c;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned char unk_20;
    unsigned char unknown_21_;
    unsigned char unk_22;
    unsigned char unknown_23_;
    unsigned char unk_24;
    char unknown_25_[3];
};

struct Struct_ov012_02188cd0_3
{
    char unk_0[8];
    char unk_8[0x74];
};

struct Struct_01ff8b48_10
{
    char unk_0[0x5400];
    Struct_ov012_02188cd0_3 unknown_5400_;
};

struct Struct_01ff8b48_11
{
    char unk_0[0x29c];
    Struct_01ff8b48_10 unknown_29c_;
};

struct Messages02188cd0
{
    char unk_0[0x998];
    int busy_;
};

struct Struct_ov012_02188cd0
{
    void* unk_0;
    void* unk_4;
    char unk_8[0x20 - 0x8];
    char allocators_[7][0x14];
    char window_[0xd28 - 0xac];
    char card_[0x600];
    char* unknown_1328_;
    char unknown_132c_[0x133c - 0x132c];
    char strings_[0x1370 - 0x133c];
    unsigned char step_;
    unsigned char state_;
    char unknown_1372_[0x1380 - 0x1372];
    int tasks_[6];
    int unk_1398;
    int unknown_139c_;
    unsigned char unknown_13a0_;
    char unknown_13a1_[3];
    int unk_13a4;
    char unknown_13a8_[4];
    void* unknown_13ac_;
    char unknown_13b0_[0x13d0 - 0x13b0];
    char* message_;
    char unknown_13d4_[0x1480 - 0x13d4];
    unsigned char unknown_1480_[0x14bc - 0x1480];
};

extern "C" void Window_ClosePane(Entry_0205d6a0* window, int a);
extern "C" void Font_DecodeText(const void* codes, char* text, int a);
extern "C" void KeyboardLayout_Init(KeyboardLayout* layout);
extern "C" void KeyboardLayout_Load(void* layout, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" void Keyboard_Init(Struct0215efb8* keyboard);
extern "C" int func_ov012_0218ae74(Struct_ov012_02188cd0* self, Struct_ov012_02188cd0_3* profile);
extern "C" void func_0205de24(Struct0205de24* window, unsigned char a, unsigned char b);
extern "C" void func_ov023_021e6e60(Struct_ov012_02188cd0* self);
extern "C" void func_ov012_0218aabc(char* self);
extern "C" void Keyboard_ResetToKey(void* keyboard, const char* text);
extern "C" void func_ov012_0218ab34(Struct_ov012_02188cd0* self, char* text, int hidden);
extern "C" int func_0205d97c(void* window);
extern "C" int Keyboard_Update(void* keyboard, int input);
extern "C" void SePlayer_Play(SePlayer* sound, int effect, int a);
extern "C" void func_ov023_021e8270(void* arg0);
extern "C" void func_ov012_021845f8(void* checker);
extern "C" int func_ov012_02184d80(void* checker, char* text);
extern "C" void func_0205def8(Struct_0205def8* window, int a, int b);
extern "C" void Font_EncodeText(const char* text, char* codes, int a);
extern "C" void func_ov012_0218943c(Struct_ov012_02188cd0* self);
extern "C" Messages02188cd0* MessageSystem_GetInstance();
extern "C" const char* func_02072a68(TableA68* texts, int id);
extern "C" void func_0204500c(Messages02188cd0* messages, const char* text, int a, int b);

extern "C" const char data_ov012_0218b2ea[];
extern "C" const char data_ov012_0218b303[];
extern "C" char g_sePlayer[];

static inline Struct_ov012_02188cd0_3* GetProfile02188cd0(GameState* gameState)
{
    return &((Struct_01ff8b48_11*)gameState)->unknown_29c_.unknown_5400_;
}

// USA: func_ov012_02188cd0
extern "C" ARM void func_ov012_02188cd0(Struct_ov012_02188cd0* self)
{
    if (self->step_ == 0)
    {
        Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
        Struct_ov012_02188cd0_3* profile = GetProfile02188cd0(GameState::GetInstance());
        memset(self->message_, 0, 0x400);
        self->unknown_1328_ = self->message_;
        Font_DecodeText(profile->unk_8, self->message_, 1);
        self->tasks_[0] = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov012_0218b2ea, 0);
        self->step_++;
        return;
    }
    else if (self->step_ == 1)
    {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->tasks_[0]))
        {
            if (loader->GetDetailedTaskStatus(self->tasks_[0]) != 2)
            {
                loader->RemoveTask(self->tasks_[0]);
                self->tasks_[0] = -1;
            }
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->tasks_[0], &file, &size);
            if (file != 0 && size != 0)
            {
                ((SafeAllocator*)self->allocators_[4])->Reset();
                KeyboardLayout_Init((KeyboardLayout*)self->unk_4);
                KeyboardLayout_Load(self->unk_4, (SafeAllocator*)self->allocators_[4], file, size);
                Keyboard_Init((Struct0215efb8*)self->unk_0);
                ((Struct_ov012_02188cd0_2*)self->unk_0)->layout_ = self->unk_4;
                ((Struct_ov012_02188cd0_2*)self->unk_0)->key_ = 0;
            }
            loader->RemoveTask(self->tasks_[0]);
            self->tasks_[0] = -1;
            self->step_++;
            return;
        }
        return;
    }
    else if (self->step_ == 2)
    {
        func_ov012_0218ae74(self, GetProfile02188cd0(GameState::GetInstance()));
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        self->unknown_13a0_ = 0;
        func_0205de24((Struct0205de24*)self->window_, 0, 2);
        func_ov023_021e6e60(self);
        func_ov012_0218aabc((char*)self);
        memcpy(self->unknown_13ac_, GetProfile02188cd0(GameState::GetInstance())->unk_8, 0x72);
        Struct_ov012_02188cd0_2* keyboard = (Struct_ov012_02188cd0_2*)self->unk_0;
        keyboard->text_ = self->message_;
        keyboard->size_ = 0x400;
        ((Struct_ov012_02188cd0_2*)self->unk_0)->unk_14 = 0x39;
        ((Struct_ov012_02188cd0_2*)self->unk_0)->unknown_1f_ = 1;
        ((Struct_ov012_02188cd0_2*)self->unk_0)->unknown_21_ = 1;
        ((Struct_ov012_02188cd0_2*)self->unk_0)->unk_24 = 1;
        Keyboard_ResetToKey(self->unk_0, data_ov012_0218b303);
        ((Struct_ov012_02188cd0_2*)self->unk_0)->unk_22 = 1;
        ((Struct_ov012_02188cd0_2*)self->unk_0)->unknown_23_ = 0;
        func_ov012_0218ab34(self, 0, 0);
        self->step_++;
        return;
    }
    else if (self->step_ == 4)
    {
        if ((g_keyManager.TestKeysPressed(2) || func_0205d97c(self->window_) == 2) && *self->message_ == 0)
        {
            Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
            self->step_++;
        }
        Struct_ov012_02188cd0_2* keyboard = (Struct_ov012_02188cd0_2*)self->unk_0;
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
                if (page != ((Struct_ov012_02188cd0_2*)self->unk_0)->unk_20)
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
                    func_ov012_021845f8(self->unknown_1480_);
                    int var7 = func_ov012_02184d80(self->unknown_1480_, self->message_);
                    BackgroundLoader::RemoveLockGlobal();
                    if (var7)
                    {
                        func_0205def8((Struct_0205def8*)self->window_, 0, 14);
                        self->step_ = 10;
                        return;
                    }
                }
                Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
                self->step_++;
                return;
        }
    }
    else if (self->step_ == 5)
    {
        Font_EncodeText(self->message_, GetProfile02188cd0(GameState::GetInstance())->unk_8, 1);
        self->unknown_1328_ = 0;
        memset(self->message_, 0, 0x400);
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
        self->step_ = 1;
        return;
    }
    else if (self->step_ == 10)
    {
        Messages02188cd0* messages = MessageSystem_GetInstance();
        func_0204500c(messages, func_02072a68((TableA68*)self->strings_, 501), 0, 0xe3);
        messages->busy_ = 1;
        self->step_++;
        return;
    }
    else if (self->step_ == 11)
    {
        if (MessageSystem_GetInstance()->busy_ == 0)
        {
            func_0205def8((Struct_0205def8*)self->window_, 1, 14);
            self->step_ = 4;
            ((Struct_ov012_02188cd0_2*)self->unk_0)->unknown_18_ = 0;
            ((Struct_ov012_02188cd0_2*)self->unk_0)->unk_1c = 0;
        }
    }
}
