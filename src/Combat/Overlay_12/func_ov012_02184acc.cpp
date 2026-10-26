#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Input/Input.h"

#if defined(jpn)
#define func_ov012_02185cf8 func_ov012_0218634c
#define func_ov012_02184d80 func_ov012_02185db4
#define data_ov012_0218b188 data_ov012_0218bea8
#endif

struct Messages02184acc
{
#if defined(jpn)
    char unk_0[0x868];
#else
    char unk_0[0x998];
#endif
    int busy_;
};

struct Struct_ov012_02184acc_3
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
};

struct Struct_01ff91ac_12
{
    char unk_0[0x5400];
    Struct_ov012_02184acc_3 unknown_5400_;
};

struct Struct_01ff91ac_13
{
    char unk_0[0x29c];
    Struct_01ff91ac_12 unknown_29c_;
};

struct Struct_ov012_02184acc
{
#if defined(jpn)
    char unk_0[0x90];
    char window_[0xd0c - 0x90];
    char card_[0x608];
    char unknown_1314_[0x1340 - 0x1314];
    unsigned char step_;
    unsigned char state_;
    char unknown_1342_[0x1350 - 0x1342];
    int tasks_[4];
    int unk_1398;
    int unknown_139c_;
    unsigned char unknown_13a0_;
    char unknown_1369_[3];
    int unk_13a4;
    char unknown_1370_[0x1428 - 0x1370];
    char* message_;
    unsigned int selection_;
    char unknown_1430_[0x144c - 0x1430];
    unsigned int unknown_144c_;
    char unknown_1450_[0x14d8 - 0x1450];
    unsigned char unknown_1480_[0x20];
    unsigned char finished_;
#else
    char unk_0[0xac];
    char window_[0xd28 - 0xac];
    char card_[0x60c];
    unsigned char unknown_1334_;
    char unknown_1335_[0x1370 - 0x1335];
    unsigned char step_;
    unsigned char state_;
    char unknown_1372_[0x1380 - 0x1372];
    int tasks_[6];
    int unk_1398;
    int unknown_139c_;
    unsigned char unknown_13a0_;
    char unknown_13a1_[3];
    int unk_13a4;
    char unknown_13a8_[0x13d0 - 0x13a8];
    char* message_;
    unsigned int selection_;
    char unknown_13d8_[0x13f4 - 0x13d8];
    unsigned int unknown_13f4_;
    char unk_13f8[0x1480 - 0x13f8];
    unsigned char unknown_1480_[0x3c];
    unsigned char finished_;
    unsigned char unknown_14bd_;
    char unknown_14be_[2];
#endif
};

typedef void (Struct_ov012_02184acc::*Type_01ff91ac_5)();

struct Struct_ov012_0218b188
{
    Type_01ff91ac_5 states[17];
};

struct Struct_0205def8;
struct Entry_0205d6a0;

extern "C" void func_ov023_021e7404(void* arg0, int input);
extern "C" int Window_Update(void* window, int input);
extern "C" void func_ov012_02185cf8(Struct_ov012_02184acc* self);
extern "C" Messages02184acc* MessageSystem_GetInstance();
extern "C" void func_ov012_0218adac(Struct_ov012_02184acc* self, int arg1, int arg2, int arg3);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov012_021845f8(void* checker);
extern "C" int func_ov012_02184d80(void* checker, char* text);
#if defined(jpn)
struct SearchStruct;
extern "C" SearchStruct* LinkSession_GetInstance();
extern "C" int LinkSession_IsSlotLost(SearchStruct*, int);
#endif
extern "C" void func_0205def8(Struct_0205def8* window, int a, int b);
extern "C" void Window_ClosePane(Entry_0205d6a0* window, int a);
extern "C" void MessageSystem_Reset(char* messages);

extern "C" const Struct_ov012_0218b188 data_ov012_0218b188;
extern "C" Type_01ff91ac_5 __ptmf_null;

static inline Struct_ov012_02184acc_3* inline_ov012_02184acc(GameState* gameState)
{
    return &((Struct_01ff91ac_13*)gameState)->unknown_29c_.unknown_5400_;
}

// USA: func_ov012_02184acc
extern "C" ARM int func_ov012_02184acc(Struct_ov012_02184acc* self, int input)
{
    self->unk_13a4 = input;
    func_ov023_021e7404(self->card_, input);
    self->unk_1398 = Window_Update(self->window_, input);
    Struct_ov012_0218b188 states = data_ov012_0218b188;
    states.states[16] = __ptmf_null;
    if (states.states[self->state_] != 0)
        (self->*states.states[self->state_])();
    func_ov012_02185cf8(self);

    Messages02184acc* messages = MessageSystem_GetInstance();
#if !defined(jpn)
    GameState* gameState = GameState::GetInstance();
#endif
    if ((self->state_ != 0 && self->state_ < 15) || (self->state_ == 0 && messages->busy_ != 0))
    {
#if !defined(jpn)
        if (messages->busy_ == 0 && g_keyManager.TestKeysPressed(0x800))
        {
            self->unknown_14bd_ = ++self->unknown_14bd_ & 1;
            self->unknown_1334_ = self->unknown_14bd_;
            if (self->state_ == 13 && self->step_ == 3)
                func_ov012_0218adac(self, 0, inline_ov012_02184acc(gameState)->female_ + self->unknown_13f4_ * 2, 1);
            else
                func_ov012_0218adac(self, 0, -1, 1);
        }

#endif
#if defined(jpn)
        if ((messages->busy_ == 0 && g_keyManager.TestKeysPressed(0x800)) ||
            LinkSession_IsSlotLost(LinkSession_GetInstance(), 0))
#else
        if (func_ov017_021959b4())
#endif
        {
#if defined(jpn)
            if (self->state_ == 14 && self->step_ == 4)
#else
            if (self->state_ == 14 && self->step_ == 4 && *self->message_ != 0)
#endif
            {
                GameState::GetInstance();
#if !defined(jpn)
                BackgroundLoader::AddLockGlobal();
                BackgroundLoader::FreeAllocationsGlobal();
                func_ov012_021845f8(self->unknown_1480_);
#endif
                int var3 = func_ov012_02184d80(self->unknown_1480_, self->message_);
#if !defined(jpn)
                BackgroundLoader::RemoveLockGlobal();
#endif
                if (var3)
                {
                    func_0205def8((Struct_0205def8*)self->window_, 0, 14);
                    self->step_ = 10;
                    return 0;
                }
            }

            self->finished_ = 1;
            self->unknown_13a0_ = 0;
            self->selection_ = 0;
            Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
            self->state_ = 15;
            self->step_ = 0;
            if (messages->busy_ != 0)
                MessageSystem_Reset((char*)messages);

            BackgroundLoader* loader = BackgroundLoader::GetInstance();
            for (int i = 0; i < (int)(sizeof(self->tasks_) / sizeof(self->tasks_[0])); i++)
            {
                if (self->tasks_[i] > BackgroundLoader::TaskStatus_Invalid)
                {
                    loader->RemoveTask(self->tasks_[i]);
                    self->tasks_[i] = -1;
                }
            }
        }
    }
    return self->unknown_139c_;
}
