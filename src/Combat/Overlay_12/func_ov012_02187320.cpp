#if defined(jpn)
#define R(j,u) (j)
#define func_ov012_02185bf0 func_ov012_02186248
#define func_ov012_0218943c func_ov012_02189d18
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov023_021e6de4 func_ov023_021e7148
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Messages02187320
{
    char unk_0[R(0x868,0x998)];
    int busy_;
    int unknown_99c_;
    int unknown_9a0_;
    char unknown_9a4_[R(0x17de,0x19ae) - R(0x874,0x9a4)];
    unsigned char unknown_19ae_;
};

struct Struct_ov012_02187320_2
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

struct Struct_ov012_02187320_3
{
    char unk_0[R(0x90,0xac)];
    char window_[R(0x1314,0x133c) - R(0x90,0xac)];
    char strings_[R(0x1340,0x1370) - R(0x1314,0x133c)];
    unsigned char step_;
    unsigned char state_;
    char unknown_1372_[R(0x1368,0x13a0) - R(0x1342,0x1372)];
    unsigned char unknown_13a0_;
    char unknown_13a1_[R(0x1370,0x13a8) - R(0x1369,0x13a1)];
    signed char unknown_13a8_;
    signed char unknown_13a9_;
    char unknown_13aa_[R(0x1450,0x13f8) - R(0x1372,0x13aa)];
    unsigned int unk_13f8;
};

struct TableA68;
struct Entry_0205d6a0;
struct Struct0205de24;
struct SePlayer;
struct Struct_0205c570;
struct Struct_ov012_02186a7c;

extern "C" Messages02187320* MessageSystem_GetInstance();
extern "C" const char* func_02072a68(TableA68* table, int key);
#if defined(jpn)
extern "C" void func_0204500c(Messages02187320* messages, const char* text, int a);
#else
extern "C" void func_0204500c(Messages02187320* messages, const char* text, int a, int b);
#endif
extern "C" void Window_ClosePane(Entry_0205d6a0* window, int a);
extern "C" void func_0205de24(Struct0205de24* window, unsigned char a, unsigned char b);
extern "C" void func_ov023_021e6e60(Struct_ov012_02187320_3* self);
extern "C" void func_ov012_02189f38(char* self);
extern "C" void SePlayer_Play(SePlayer* sound, int effect, int a);
extern "C" int Window_GetSelectedIndex(Struct_0205c570* window);
extern "C" int func_ov023_021e6de4(Struct_ov012_02187320_3* self);
extern "C" int func_ov023_021e6e20(Struct_ov012_02186a7c* self);
extern "C" void func_ov012_02185bf0(Struct_ov012_02187320_3* self, unsigned char item, int selected);
#if defined(jpn)
extern "C" void func_ov012_0218adac(Struct_ov012_02187320_3* self, int arg1, int arg2);
#else
extern "C" void func_ov012_0218adac(Struct_ov012_02187320_3* self, int arg1, int arg2, int arg3);
#endif
extern "C" void MessageSystem_Reset(char* messages);
extern "C" void func_ov012_0218943c(Struct_ov012_02187320_3* self);
extern "C" int func_020457e0(Messages02187320* messages);

extern "C" char g_sePlayer[];

static inline Struct_ov012_02187320_2* inline_ov012_02187320(GameState* gameState)
{
    return (Struct_ov012_02187320_2*)((char*)gameState + R(0x543c,0x569c));
}

// USA: func_ov012_02187320
extern "C" ARM void func_ov012_02187320(Struct_ov012_02187320_3* self)
{
    Messages02187320* messages = MessageSystem_GetInstance();
    int var1 = messages->unknown_9a0_;
    if (var1 == 3)
        messages->unknown_19ae_ = 0;
    if (self->step_ == 0)
    {
#if defined(jpn)
        func_0204500c(messages, func_02072a68((TableA68*)self->strings_, 0xf), 0);
#else
        func_0204500c(messages, func_02072a68((TableA68*)self->strings_, 0xf), 0, 0xe3);
#endif
        messages->busy_ = 1;
        Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
        self->step_ = 10;
        return;
    }
    else if (self->step_ == 1)
    {
        if (var1 == 0 || var1 == 3)
            self->step_++;
        return;
    }
    else if (self->step_ == 2)
    {
        self->unknown_13a0_ = 0;
        self->unk_13f8 = 0;
        func_0205de24((Struct0205de24*)self->window_, 0, 2);
        func_ov023_021e6e60(self);
        func_ov012_02189f38((char*)self);
        SePlayer_Play((SePlayer*)g_sePlayer, 5, 0);
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        self->unknown_13a0_ = 1;
        self->unk_13f8 = Window_GetSelectedIndex((Struct_0205c570*)self->window_);
        int done = 0;
        if (func_ov023_021e6de4(self) || func_ov023_021e6e20((Struct_ov012_02186a7c*)self))
        {
            func_ov012_02185bf0(self, self->state_, 1);
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            Struct_ov012_02187320_2* profile = inline_ov012_02187320(GameState::GetInstance());
            switch (self->unk_13f8)
            {
                case 1:
                    profile->unknown_3_7_ = 1;
                    break;
                case 0:
                    profile->unknown_3_7_ = 0;
                    break;
            }
            if (func_ov023_021e6e20((Struct_ov012_02186a7c*)self))
                profile->unknown_3_7_ = 1;
#if defined(jpn)
            func_ov012_0218adac(self, 0, -1);
#else
    #if defined(jpn)
        func_ov012_0218adac(self, 0, -1);
#else
        func_ov012_0218adac(self, 0, -1, 0);
#endif
#endif
            done = 1;
        }
        if (!done)
            return;
        Messages02187320* system = MessageSystem_GetInstance();
        int busy = system->busy_ == 0 ? 1 : 0;
        if (!busy)
            MessageSystem_Reset((char*)system);
        Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
        self->step_++;
        return;
    }
    else if (self->step_ == 4)
    {
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
        self->state_ = 1;
        func_ov023_021e6e60(self);
        func_ov012_0218943c(self);
        self->unknown_13a0_ = 1;
        self->unknown_13a8_ = -1;
        self->unknown_13a9_ = 0;
        self->step_ = 1;
        return;
    }
    else if (self->step_ == 10 && messages->busy_ == 0)
    {
        Struct_ov012_02187320_2* profile = inline_ov012_02187320(GameState::GetInstance());
        if (func_020457e0(messages) == 0)
            profile->unknown_3_7_ = 0;
        else
            profile->unknown_3_7_ = 1;
#if defined(jpn)
        func_ov012_0218adac(self, 0, -1);
#else
        func_ov012_0218adac(self, 0, -1, 0);
#endif
        Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
        self->step_ = 5;
    }
}
