#include <globaldefs.h>
#include "NitroSDK/HWRegisters.h"
#include <std_library_functions.h>
#include <NitroSDK/ColorEffects.h>
#include "Resource/GameResources.h"


#define GUIDE_WINDOW_MAIN_SCREEN 8
#define GUIDE_WINDOW_NO_DIMMING 0x20
#define GUIDE_WINDOW_OPENING 0x40
#define GUIDE_WINDOW_TITLE_SCROLLING 0x80
#define GUIDE_WINDOW_SHOWN 0x100
#define GUIDE_WINDOW_UNK_400 0x400
#define GUIDE_WINDOW_UNK_800 0x800


struct GameResources;
struct Struct_0205d81c;
struct Struct0209c830;
struct Entry_0205d6a0;
struct Container020e0310;

struct Struct_ov023_021ec480_3 {
    char unk_0[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct MessageSystem_021ec480 {
#if defined(jpn)
    char unk_0[0x868];
#else
    char unk_0[0x998];
#endif
    int busy_;
#if defined(jpn)
    char unknown_86c_[0x17de - 0x86c];
#else
    char unknown_99c_[0x19ae - 0x99c];
#endif
    unsigned char unknown_19ae_;
    char unknown_19af_[0x19b2 - 0x19af];
    unsigned char unknown_19b2_;
#if defined(jpn)
    char unknown_17e3_[0x17f9 - 0x17e3];
#else
    char unknown_19b3_[0x19c8 - 0x19b3];
#endif
    unsigned char unknown_19c8_;
};

struct Struct_ov023_021ec480 {
    void* allocators_;
    char texts_[0x18];
    char* text_;
    void* pages_;
    int count_;
    unsigned char page_;
    char unknown_29_;
    char unknown_2a_[0x10];
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    unsigned int unknown_3c_;
    unsigned int unknown_40_;
    Struct_ov023_021ec480_3 backgrounds_[2];
    Struct_ov023_021ec480_3 unknown_84_[2];
    char window_[0xbc];
    char canvases_[3][0xe0];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    unsigned char type_;
    unsigned char state_;
    unsigned char step_;
    unsigned char unknown_433_;
    int task_;
    unsigned short flags_;
};

struct Struct_ov023_021ec480_2 {
    unsigned char b[2];
};

extern unsigned char data_ov023_021fd844[];
extern char g_sePlayer[];
extern char g_bgmPlayer[];

extern "C" MessageSystem_021ec480* MessageSystem_GetInstance();
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void SePlayer_LoadExtraArchiveB(void* sound, int a, int b);
extern "C" void SePlayer_PlayExtra(void* sound, int a, int b);
extern "C" void Window_SetPanePalette(Struct_0205d81c* window, int item, int value);
extern "C" void func_0209c830(Struct0209c830* obj, int value);
extern "C" int Scenario_TestFlag(int a, unsigned char* b, int flag);
extern "C" int func_0209ca2c(void* obj);
extern "C" int func_ov023_021ed014(struct Struct_ov023_021ec480* window);
extern "C" void Window_ClosePane(Entry_0205d6a0* window, int value);
extern "C" void SePlayer_UnloadExtraArchiveB(void* sound);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void Text_Append(char* text, const char* append);
extern "C" void MessageSystem_Reset(char* messages);

extern "C" {
int func_ov023_021ed064(Struct_ov023_021ec480* self);
void func_ov023_021ecbbc(Struct_ov023_021ec480* self);
void func_ov023_021ed194(Struct_ov023_021ec480* self);
void func_ov023_021ed354(Struct_ov023_021ec480* self);
void func_ov023_021ed4b8(Struct_ov023_021ec480* self);
void func_ov023_021ed600(Struct_ov023_021ec480* self);
void* Scenario_GetInstance();
#if defined(jpn)
void func_0204500c(MessageSystem_021ec480* messages, const char* text, int a);
#else
void func_0204500c(MessageSystem_021ec480* messages, const char* text, int a, int b);
#endif
}

static inline int inline_ov023_021ec480(Struct_ov023_021ec480* self)
{
    return func_ov023_021ed014(self);
}

// USA: func_ov023_021ec480
extern "C" ARM void func_ov023_021ec480(Struct_ov023_021ec480* self)
{
#if defined(jpn)
 enum {regionalOffset0=0x800};
#else
 enum {regionalOffset0=0x960};
#endif
    GameResources* resources = GetGameResources();
    MessageSystem_021ec480* messages = MessageSystem_GetInstance();
    if (self->step_ >= 1 && self->step_ <= 3 && func_ov023_021ed064(self))
    {
        self->step_ = 4;
        return;
    }
    unsigned char step = self->step_;
    if (step == 0)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        if (!(self->flags_ & GUIDE_WINDOW_NO_DIMMING))
        {
            if (self->unknown_84_[1].unknown_1c_0_ == 0)
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x17, -8);
            else
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x17, -8);
        }
        int volume = 0x8c;
        if (self->type_ == 2 || (self->type_ == 7 && (self->flags_ & GUIDE_WINDOW_MAIN_SCREEN)))
            volume = 0x1b4;
        SePlayer_LoadExtraArchiveB(g_sePlayer, volume, volume);
        func_ov023_021ecbbc(self);
        self->step_++;
    }
    if (step == 1)
    {
        if (self->flags_ & GUIDE_WINDOW_OPENING)
            return;
        func_ov023_021ed194(self);
        self->flags_ |= GUIDE_WINDOW_TITLE_SCROLLING;
        SePlayer_PlayExtra(g_sePlayer, 0, 0);
        self->step_++;
    }
    if (step == 2)
    {
        if (self->flags_ & GUIDE_WINDOW_TITLE_SCROLLING)
            return;
        func_ov023_021ed354(self);
        func_ov023_021ed4b8(self);
        unsigned char items[2];
        *(Struct_ov023_021ec480_2*)items = *(Struct_ov023_021ec480_2*)&data_ov023_021fd844[0xa];
        for (int i = 0; i < 2; i++)
            Window_SetPanePalette((Struct_0205d81c*)self->window_, items[i], 0);
        func_0209c830((Struct0209c830*)g_bgmPlayer, 0x40);
        self->step_++;
    }
    if (step == 3)
    {
        self->flags_ |= GUIDE_WINDOW_SHOWN;
        step++;
        self->step_++;
    }
    if (step == 4)
    {
        if (!(self->flags_ & GUIDE_WINDOW_SHOWN))
            return;
        if (self->flags_ & GUIDE_WINDOW_UNK_400)
        {
            void* unknown = Scenario_GetInstance();
            if (self->page_ == self->count_ - 1 && Scenario_TestFlag((int)unknown, (unsigned char*)unknown + 0x8c, 0x119a) &&
                func_0209ca2c(g_bgmPlayer))
                return;
        }
        if (inline_ov023_021ec480(self))
            self->step_++;
    }
    if (step == 5)
    {
        int next = self->page_ + 1;
        if (next < self->count_)
        {
            Window_ClosePane((Entry_0205d6a0*)self->window_, 1);
            self->page_ = next;
            self->step_ = 1;
            func_ov023_021ecbbc(self);
            return;
        }
        self->step_++;
    }
    if (step == 6)
    {
        Window_ClosePane((Entry_0205d6a0*)self->window_, 0);
        SePlayer_UnloadExtraArchiveB(g_sePlayer);
        if (!(self->flags_ & GUIDE_WINDOW_NO_DIMMING))
        {
            if (self->unknown_84_[1].unknown_1c_0_ == 0)
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x17, 0);
            else
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x17, 0);
        }
        if (self->type_ == 0 || self->type_ == 1)
            ColorEffect_ConfigureAlphaBlend(REG_BLDCNT, 1, 2, 0xf, 0x1f);
        if (self->flags_ & GUIDE_WINDOW_UNK_400)
        {
            void* unknown = Scenario_GetInstance();
            if (Scenario_TestFlag((int)unknown, (unsigned char*)unknown + 0x8c, 0x119a))
            {
                self->step_++;
                return;
            }
        }
        else if (self->flags_ & GUIDE_WINDOW_UNK_800)
        {
            self->step_ = 10;
            return;
        }
        self->state_ = 2;
        self->step_ = 0;
    }
    if (step == 7)
    {
        if (self->unknown_84_[1].unknown_1c_0_ == 0)
        {
            memset(self->text_, 0, regionalOffset0);
            Text_Append(self->text_, KeyTable_Get((Container020e0310*)self->texts_, 1000));
            Text_Append(self->text_, KeyTable_Get((Container020e0310*)self->texts_, 1002));
            messages->busy_ = 1;
#if defined(jpn)
            func_0204500c(messages, self->text_, 0);
#else
            func_0204500c(messages, self->text_, 0, 0xe3);
#endif
            messages->unknown_19b2_ = 0;
            messages->unknown_19c8_ = 0;
            messages->unknown_19ae_ = 0;
        }
        else
        {
            func_ov023_021ed600(self);
            unsigned char items2[2];
            *(Struct_ov023_021ec480_2*)items2 = *(Struct_ov023_021ec480_2*)&data_ov023_021fd844[4];
            for (int i = 0; i < 2; i++)
                Window_SetPanePalette((Struct_0205d81c*)self->window_, items2[i], 0);
        }
        func_0209c830((Struct0209c830*)g_bgmPlayer, 0x40);
        self->step_++;
    }
    if (step == 8)
    {
        messages->unknown_19ae_ = 0;
        if (func_0209ca2c(g_bgmPlayer))
            return;
        self->step_++;
        step++;
    }
    if (step == 9)
    {
        if (self->flags_ & GUIDE_WINDOW_UNK_800)
        {
            if (inline_ov023_021ec480(self))
            {
                self->step_++;
                step++;
            }
        }
        else
        {
            step = 11;
            self->step_ = 11;
        }
    }
    if (step == 10)
    {
        memset(self->text_, 0, regionalOffset0);
        Text_Append(self->text_, KeyTable_Get((Container020e0310*)self->texts_, 1001));
        Text_Append(self->text_, KeyTable_Get((Container020e0310*)self->texts_, 1002));
        messages->busy_ = 1;
#if defined(jpn)
        func_0204500c(messages, self->text_, 0);
#else
        func_0204500c(messages, self->text_, 0, 0xe3);
#endif
        messages->unknown_19b2_ = 0;
        messages->unknown_19c8_ = 0;
        messages->unknown_19ae_ = 0;
        func_0209c830((Struct0209c830*)g_bgmPlayer, 0x40);
        self->step_++;
    }
    if (step == 11)
    {
        messages->unknown_19ae_ = 0;
        if (func_0209ca2c(g_bgmPlayer))
            return;
        if (!inline_ov023_021ec480(self))
            return;
        if (self->unknown_84_[1].unknown_1c_0_ == 0)
        {
            MessageSystem_Reset((char*)messages);
            self->state_ = 2;
            self->step_ = 0;
            return;
        }
        Window_ClosePane((Entry_0205d6a0*)self->window_, 0);
        self->state_ = 2;
        self->step_ = 0;
    }
}
