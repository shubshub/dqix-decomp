#include <globaldefs.h>
#include <std_library_functions.h>
#include <NitroSDK/ColorEffects.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#define GUIDE_WINDOW_MAIN_SCREEN 8
#define GUIDE_WINDOW_NO_DIMMING 0x20
#define GUIDE_WINDOW_OPENING 0x40
#define GUIDE_WINDOW_TITLE_SCROLLING 0x80
#define GUIDE_WINDOW_SHOWN 0x100
#define GUIDE_WINDOW_UNK_400 0x400
#define GUIDE_WINDOW_UNK_800 0x800

#define REG_BLDCNT 0x04000050
#define REG_BLDCNT_SUB 0x04001050

struct GameResources;
struct Struct_0205d81c;
struct Struct_02109bf4_2;
struct Struct_0205d6a0;
struct Struct_0201099c_3;

struct Struct_ov023_021ec480_3 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov023_021ec480_4 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    int unknown_998_;
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
    void* unknown_0_;
    char unknown_4_[0x18];
    char* unknown_1c_;
    void* unknown_20_;
    int unknown_24_;
    unsigned char unknown_28_;
    char unknown_29_;
    char unknown_2a_[0x10];
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    unsigned int unknown_3c_;
    unsigned int unknown_40_;
    Struct_ov023_021ec480_3 unknown_44_[2];
    Struct_ov023_021ec480_3 unknown_84_[2];
    char unknown_c4_[0xbc];
    char unknown_180_[3][0xe0];
    void* unknown_420_;
    void* unknown_424_;
    void* unknown_428_;
    void* unknown_42c_;
    unsigned char unknown_430_;
    unsigned char unknown_431_;
    unsigned char unknown_432_;
    unsigned char unknown_433_;
    int unknown_434_;
    unsigned short unknown_438_;
};

struct Struct_ov023_021ec480_2 {
    unsigned char unknown_0_[2];
};

extern unsigned char data_ov023_021fd844[];
extern char g_sePlayer[];
extern char data_02109bf4[];

extern "C" Struct_ov023_021ec480_4* func_020421a0();
int IsBrightnessTransitionActive(GameResources* resources);
void SetForwardAndStore0205ebc0(void* sound, int a, int b);
void DispatchIfField0xc4NonNeg_0205ebfc(void* sound, int a, int b);
void SetElementFieldC2_0205deb4(Struct_0205d81c* window, int item, int value);
void SetValueAndActivate0209c830(Struct0209c830* obj, int value);
int TestBitInByteArray_0206dfb0(int a, unsigned char* b, int flag);
int IsAnimationActive0209ca2c(void* obj);
int DispatchIfFlagsOrByteSet_021ed014(struct GuideWindow_021ec480* window);
void ResetEntryList0205d6a0(Entry_0205d6a0* window, int value);
void ForwardField0xc0_0205ebec(void* sound);
const char* KeyTable_Get(Container020e0310* texts, int id);
void AppendString02042058(char* text, const char* append);
void ReinitController02043204(char* messages);

extern "C" {
int func_ov023_021ed064(Struct_ov023_021ec480* arg0);
void func_ov023_021ecbbc(Struct_ov023_021ec480* arg0);
void func_ov023_021ed194(Struct_ov023_021ec480* arg0);
void func_ov023_021ed354(Struct_ov023_021ec480* arg0);
void func_ov023_021ed4b8(Struct_ov023_021ec480* arg0);
void func_ov023_021ed600(Struct_ov023_021ec480* arg0);
void* func_0205ec34();
#if defined(jpn)
void func_0204500c(Struct_ov023_021ec480_4* arg0, const char* arg1, int arg2);
#else
void func_0204500c(Struct_ov023_021ec480_4* arg0, const char* arg1, int arg2, int arg3);
#endif
}

static inline int inline_ov023_021ec480(Struct_ov023_021ec480* arg0)
{
    return func_ov023_021ed014(arg0);
}

// USA: func_ov023_021ec480
extern "C" ARM void func_ov023_021ec480(Struct_ov023_021ec480* arg0)
{
#if defined(jpn)
 enum {Enum_ov023_021ec480_2400=0x800};
#else
 enum {Enum_ov023_021ec480_2400=0x960};
#endif
    GameResources* var0 = GetGameResources();
    Struct_ov023_021ec480_4* var1 = func_020421a0();
    if (arg0->unknown_432_ >= 1 && arg0->unknown_432_ <= 3 && func_ov023_021ed064(arg0))
    {
        arg0->unknown_432_ = 4;
        return;
    }
    unsigned char var2 = arg0->unknown_432_;
    if (var2 == 0)
    {
        if (IsBrightnessTransitionActive(var0))
            return;
        if (!(arg0->unknown_438_ & GUIDE_WINDOW_NO_DIMMING))
        {
            if (arg0->unknown_84_[1].unknown_1c_0_ == 0)
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x17, -8);
            else
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x17, -8);
        }
        int volume = 0x8c;
        if (self->type_ == 2 || (self->type_ == 7 && (self->flags_ & GUIDE_WINDOW_MAIN_SCREEN)))
            volume = 0x1b4;
        SetForwardAndStore0205ebc0(g_sePlayer, volume, volume);
        func_ov023_021ecbbc(self);
        self->step_++;
    }
    if (var2 == 1)
    {
        if (arg0->unknown_438_ & GUIDE_WINDOW_OPENING)
            return;
        func_ov023_021ed194(self);
        self->flags_ |= GUIDE_WINDOW_TITLE_SCROLLING;
        DispatchIfField0xc4NonNeg_0205ebfc(g_sePlayer, 0, 0);
        self->step_++;
    }
    if (var2 == 2)
    {
        if (arg0->unknown_438_ & GUIDE_WINDOW_TITLE_SCROLLING)
            return;
        func_ov023_021ed354(arg0);
        func_ov023_021ed4b8(arg0);
        unsigned char var4[2];
        *(Struct_ov023_021ec480_2*)var4 = *(Struct_ov023_021ec480_2*)&data_ov023_021fd844[0xa];
        for (int var5 = 0; var5 < 2; var5++)
            func_0205deb4((Struct_0205d81c*)arg0->unknown_c4_, var4[var5], 0);
        func_0209c830((Struct_02109bf4_2*)data_02109bf4, 0x40);
        arg0->unknown_432_++;
    }
    if (var2 == 3)
    {
        arg0->unknown_438_ |= GUIDE_WINDOW_SHOWN;
        var2++;
        arg0->unknown_432_++;
    }
    if (var2 == 4)
    {
        if (!(arg0->unknown_438_ & GUIDE_WINDOW_SHOWN))
            return;
        if (arg0->unknown_438_ & GUIDE_WINDOW_UNK_400)
        {
            void* var6 = func_0205ec34();
            if (arg0->unknown_28_ == arg0->unknown_24_ - 1 && func_0206dfb0((int)var6, (unsigned char*)var6 + 0x8c, 0x119a) &&
                func_0209ca2c(data_02109bf4))
                return;
        }
        if (inline_ov023_021ec480(arg0))
            arg0->unknown_432_++;
    }
    if (var2 == 5)
    {
        int var7 = arg0->unknown_28_ + 1;
        if (var7 < arg0->unknown_24_)
        {
            func_0205d6a0((Struct_0205d6a0*)arg0->unknown_c4_, 1);
            arg0->unknown_28_ = var7;
            arg0->unknown_432_ = 1;
            func_ov023_021ecbbc(arg0);
            return;
        }
        arg0->unknown_432_++;
    }
    if (var2 == 6)
    {
        ResetEntryList0205d6a0((Entry_0205d6a0*)self->window_, 0);
        ForwardField0xc0_0205ebec(g_sePlayer);
        if (!(self->flags_ & GUIDE_WINDOW_NO_DIMMING))
        {
            if (arg0->unknown_84_[1].unknown_1c_0_ == 0)
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x17, 0);
            else
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x17, 0);
        }
        if (arg0->unknown_430_ == 0 || arg0->unknown_430_ == 1)
            ColorEffect_ConfigureAlphaBlend(REG_BLDCNT, 1, 2, 0xf, 0x1f);
        if (arg0->unknown_438_ & GUIDE_WINDOW_UNK_400)
        {
            void* var8 = func_0205ec34();
            if (func_0206dfb0((int)var8, (unsigned char*)var8 + 0x8c, 0x119a))
            {
                arg0->unknown_432_++;
                return;
            }
        }
        else if (arg0->unknown_438_ & GUIDE_WINDOW_UNK_800)
        {
            arg0->unknown_432_ = 10;
            return;
        }
        arg0->unknown_431_ = 2;
        arg0->unknown_432_ = 0;
    }
    if (var2 == 7)
    {
        if (arg0->unknown_84_[1].unknown_1c_0_ == 0)
        {
            memset(self->text_, 0, regionalOffset0);
            AppendString02042058(self->text_, KeyTable_Get((Container020e0310*)self->texts_, 1000));
            AppendString02042058(self->text_, KeyTable_Get((Container020e0310*)self->texts_, 1002));
            messages->busy_ = 1;
#if defined(jpn)
            func_0204500c(var1, arg0->unknown_1c_, 0);
#else
            func_0204500c(var1, arg0->unknown_1c_, 0, 0xe3);
#endif
            var1->unknown_19b2_ = 0;
            var1->unknown_19c8_ = 0;
            var1->unknown_19ae_ = 0;
        }
        else
        {
            func_ov023_021ed600(arg0);
            unsigned char var9[2];
            *(Struct_ov023_021ec480_2*)var9 = *(Struct_ov023_021ec480_2*)&data_ov023_021fd844[4];
            for (int var10 = 0; var10 < 2; var10++)
                func_0205deb4((Struct_0205d81c*)arg0->unknown_c4_, var9[var10], 0);
        }
        func_0209c830((Struct_02109bf4_2*)data_02109bf4, 0x40);
        arg0->unknown_432_++;
    }
    if (var2 == 8)
    {
        var1->unknown_19ae_ = 0;
        if (func_0209ca2c(data_02109bf4))
            return;
        arg0->unknown_432_++;
        var2++;
    }
    if (var2 == 9)
    {
        if (arg0->unknown_438_ & GUIDE_WINDOW_UNK_800)
        {
            if (inline_ov023_021ec480(arg0))
            {
                arg0->unknown_432_++;
                var2++;
            }
        }
        else
        {
            var2 = 11;
            arg0->unknown_432_ = 11;
        }
    }
    if (var2 == 10)
    {
        memset(self->text_, 0, regionalOffset0);
        AppendString02042058(self->text_, KeyTable_Get((Container020e0310*)self->texts_, 1001));
        AppendString02042058(self->text_, KeyTable_Get((Container020e0310*)self->texts_, 1002));
        messages->busy_ = 1;
#if defined(jpn)
        func_0204500c(var1, arg0->unknown_1c_, 0);
#else
        func_0204500c(var1, arg0->unknown_1c_, 0, 0xe3);
#endif
        var1->unknown_19b2_ = 0;
        var1->unknown_19c8_ = 0;
        var1->unknown_19ae_ = 0;
        func_0209c830((Struct_02109bf4_2*)data_02109bf4, 0x40);
        arg0->unknown_432_++;
    }
    if (var2 == 11)
    {
        var1->unknown_19ae_ = 0;
        if (func_0209ca2c(data_02109bf4))
            return;
        if (!inline_ov023_021ec480(arg0))
            return;
        if (arg0->unknown_84_[1].unknown_1c_0_ == 0)
        {
            func_02043204((char*)var1);
            arg0->unknown_431_ = 2;
            arg0->unknown_432_ = 0;
            return;
        }
        func_0205d6a0((Struct_0205d6a0*)arg0->unknown_c4_, 0);
        arg0->unknown_431_ = 2;
        arg0->unknown_432_ = 0;
    }
}
