#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov012_02188640 {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int female : 1;
    unsigned int initialized : 1;
    unsigned int unknown_3_3_ : 1;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown : 9;
    int title : 10;
    int accolade : 11;
    int unknown_7_6_ : 1;
    unsigned int unknown_7_7_ : 1;
};
struct TableA68;
struct SePlayer;
struct Struct_ov012_02186a7c;
struct Struct0205de24;
struct Struct_0205c570;
extern "C" void func_0205de24(Struct0205de24*, unsigned char, unsigned char);
extern "C" void func_ov023_021e6e60(void*);
extern "C" void func_ov012_0218a574(char*);
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" int func_ov023_021e6448(void*);
extern "C" int func_ov023_021e7148(void*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void LinkSession_GetInstance();
extern "C" int GameState_GetStoryChapter(char*);
extern "C" const char* func_02072a68(TableA68*, int);
extern "C" void func_ov012_0218bba0(void*, int, int);
extern "C" void func_ov012_02189be8(void*, int);
extern "C" int func_ov023_021e6e20(Struct_ov012_02186a7c*);
extern "C" char g_sePlayer[];

static inline Struct_ov012_02188640* inline_ov012_02188640(GameState* state) {
    return (Struct_ov012_02188640*)((char*)state + 0x543c);
}

extern "C" ARM void func_ov012_02188640(char* editor) {
    if (*(unsigned char*)(editor + 0x1340) == 0) {
        *(unsigned char*)(editor + 0x1368) = 0;
        GameState* state = GameState::GetInstance();
        Struct_ov012_02188640* var1 = inline_ov012_02188640(state);
        unsigned int index;
        if (!var1->unknown_3_6_ && var1->accolade >= 800 && var1->accolade < 860)
            index = var1->accolade - 799;
        else
            index = 0;
        *(unsigned int*)(editor + 0x1444) = index;
        func_0205de24((Struct0205de24*)(editor + 0x90), 0, 3);
        func_ov023_021e6e60(editor);
        func_ov012_0218a574(editor);
        ++*(unsigned char*)(editor + 0x1340);
        return;
    } else if (*(unsigned char*)(editor + 0x1340) == 1) {
        *(unsigned char*)(editor + 0x1368) = 1;
        *(int*)(editor + 0x1444) = Window_GetSelectedIndex((Struct_0205c570*)(editor + 0x90));
        if (func_ov023_021e6448(editor))
            *(int*)(editor + 0x1444) = Window_GetSelectedIndex((Struct_0205c570*)(editor + 0x90));
        if (func_ov023_021e7148(editor)) {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            Struct_ov012_02188640* profile = inline_ov012_02188640(GameState::GetInstance());
            GameState* state = GameState::GetInstance();
            LinkSession_GetInstance();
            if (*(int*)(editor + 0x1444) == 0) {
                char* character = *(char**)((char*)state->GetProtagonist() + 0x144);
                int vocation = *(int*)(character + 0x8b8);
                profile->unknown_3_6_ = 1;
                profile->accolade = vocation + 700;
                if (GameState_GetStoryChapter((char*)state) == 1)
                    profile->accolade = 713;
            } else {
                profile->accolade = *(int*)(editor + 0x1444) + 799;
                profile->unknown_3_6_ = 0;
            }
            const char* name = func_02072a68((TableA68*)(editor + 0x1314), (short)(profile->accolade + 20000));
            memset(editor + 0x1458, 0, 0x40);
            memcpy(editor + 0x1458, name, strlen(name));
            profile->unknown_3_5_ = 1;
            func_ov012_0218bba0(editor, 0, -1);
            func_ov012_02189be8(editor, 0);
            return;
        }
        if (func_ov023_021e6e20((Struct_ov012_02186a7c*)editor))
            func_ov012_02189be8(editor, 1);
        return;
    }
}

#else
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov012_02188640_2
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

struct Struct_ov012_02188640_3
{
    short models_[10];
    unsigned char female_ : 1;
    unsigned char skinColor_ : 3;
    unsigned char eyeColor_ : 4;
    char unknown_15_[0x1c - 0x15];
};

struct Struct_ov012_02188640_4
{
    char unk_0[0x488];
    Struct_ov012_02188640_3 appearance_;
    char unk_4a4[0x950 - 0x4a4];
    int vocation_;
};

struct Struct_ov012_02188640_5
{
    char unk_0[0x150];
    Struct_ov012_02188640_4* unknown_150_;
};

struct Struct_ov012_02188640_6
{
    char unk_0[0xac];
    char window_[0x133c - 0xac];
    char strings_[0x1370 - 0x133c];
    unsigned char step_;
    unsigned char state_;
    char unknown_1372_[0x13a0 - 0x1372];
    unsigned char unknown_13a0_;
    char unknown_13a1_[0x13d8 - 0x13a1];
    int selections_[6];
    char unknown_13f0_[0x1400 - 0x13f0];
    char unknown_1400_[0x40];
};

struct TableA68;
struct SePlayer;
struct Struct_ov012_02186a7c;
struct Struct0205de24;
struct Struct_0205c570;

extern "C" void func_0205de24(Struct0205de24* window, unsigned char a, unsigned char b);
extern "C" void func_ov023_021e6e60(Struct_ov012_02188640_6* self);
extern "C" void func_ov012_0218a574(char* self);
extern "C" int Window_GetSelectedIndex(Struct_0205c570* window);
extern "C" int func_ov023_021e6448(Struct_ov012_02188640_6* self);
extern "C" int func_ov023_021e6de4(Struct_ov012_02188640_6* self);
extern "C" void SePlayer_Play(SePlayer* sound, int effect, int a);
extern "C" void LinkSession_GetInstance();
extern "C" int GameState_GetStoryChapter(char* gameState);
extern "C" const char* func_02072a68(TableA68* table, int key);
extern "C" void func_ov012_0218adac(Struct_ov012_02188640_6* self, int arg1, int arg2, int arg3);
extern "C" void func_ov012_0218930c(Struct_ov012_02188640_6* self, int cancel);
extern "C" int func_ov023_021e6e20(Struct_ov012_02186a7c* self);

extern "C" char g_sePlayer[];

static inline Struct_ov012_02188640_2* inline_ov012_02188640_2(GameState* gameState)
{
    return (Struct_ov012_02188640_2*)((char*)gameState + 0x569c);
}

// USA: func_ov012_02188640
extern "C" ARM void func_ov012_02188640(Struct_ov012_02188640_6* self)
{
    if (self->step_ == 0)
    {
        self->unknown_13a0_ = 0;
        GameState* gameState = GameState::GetInstance();
        unsigned int index;
        if (!inline_ov012_02188640_2(gameState)->unknown_3_6_)
        {
            int accolade = inline_ov012_02188640_2(gameState)->accolade_;
            if (accolade >= 800 && accolade < 900)
            {
                index = accolade - 799;
                goto found;
            }
            if (accolade >= 900 && accolade < 1000)
            {
                index = accolade - 899;
                goto found;
            }
        }
        index = 0;
    found:
        self->selections_[5] = index;
        func_0205de24((Struct0205de24*)self->window_, 0, 3);
        func_ov023_021e6e60(self);
        func_ov012_0218a574((char*)self);
        self->step_++;
        return;
    }
    else if (self->step_ == 1)
    {
        self->unknown_13a0_ = 1;
        self->selections_[5] = Window_GetSelectedIndex((Struct_0205c570*)self->window_);
        if (func_ov023_021e6448(self))
            self->selections_[5] = Window_GetSelectedIndex((Struct_0205c570*)self->window_);
        if (func_ov023_021e6de4(self))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            Struct_ov012_02188640_2* profile = inline_ov012_02188640_2(GameState::GetInstance());
            GameState* gameState = GameState::GetInstance();
            LinkSession_GetInstance();
            Struct_ov012_02188640_5* protagonist = (Struct_ov012_02188640_5*)gameState->GetProtagonist();
            if (self->selections_[5] == 0)
            {
                Struct_ov012_02188640_4* data = protagonist->unknown_150_;
                int accolade = 0x50dc;
                if (data->appearance_.female_ == 1)
                    accolade = 0x510e;
                int vocation = data->vocation_;
                profile->unknown_3_6_ = 1;
                profile->accolade_ = accolade + vocation - 0x4e20;
                if (GameState_GetStoryChapter((char*)gameState) == 1)
                    profile->accolade_ = accolade + 13 - 0x4e20;
            }
            else
            {
                int accolade = 0x5140;
                if (protagonist->unknown_150_->appearance_.female_ == 1)
                    accolade = 0x51a4;
                profile->accolade_ = accolade + self->selections_[5] - 0x4e21;
                profile->unknown_3_6_ = 0;
            }
            const char* text = func_02072a68((TableA68*)self->strings_, (short)(profile->accolade_ + 20000));
            memset(self->unknown_1400_, 0, sizeof(self->unknown_1400_));
            memcpy(self->unknown_1400_, text, strlen(text));
            profile->unknown_3_5_ = 1;
            func_ov012_0218adac(self, 0, -1, 0);
            func_ov012_0218930c(self, 0);
            return;
        }
        if (func_ov023_021e6e20((Struct_ov012_02186a7c*)self))
            func_ov012_0218930c(self, 1);
        return;
    }
}

#endif
