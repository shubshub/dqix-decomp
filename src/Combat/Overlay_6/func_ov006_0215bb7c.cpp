#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov006_0215bb7c_2786 = 0x962 };
#else
enum { Enum_ov006_0215bb7c_2786 = 0xae2 };
#endif

struct Struct_02081f20_2;
struct SePlayer;
struct Struct_0207fdcc_2;
struct Struct_ov006_0215951c;
struct Struct_0207fe44;
struct Struct_ov006_02158c28;
struct Struct_ov006_021596f0;

struct Struct_ov006_02154614 {
    char unk_0[Enum_ov006_0215bb7c_2786];
    unsigned short unknown_ae2_;
};

struct Struct_ov000_0217ab8c;

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** texts_;
#endif
    void* canvasBuffer_;
    void* allocators_;
    Struct_ov006_02154614* pot_;
    Struct_ov000_0217ab8c* menu_;
    void* choice_;
    void* backgrounds_;
    void* canvases_;
    void* sprites_;
    void* animations_;
    void* unknown_2c_;
    void* unknown_30_;
    void* unknown_34_;
    void* unknown_38_;
    char unknown_3c_[8];
    short* cursor_;
    short** items_;
    unsigned char** unknown_4c_;
    unsigned short* sizes_;
    int subBackground_[0x20 / 4];
    int ingredients_[0x28 / 4];
    int unknown_9c_[0xc / 4];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    int renderer_[0x54 / 4];
    int layout_[0x4c / 4];
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[0xc];
#if defined(jpn)
    char unknown_174_[8];
#endif
    int results_[4][0x74 / 4];
    int ticks_;
    int menuResult_;
    int task_;
    int unknown_358_;
    short unknown_35c_;
    short unknown_35e_;
    short unknown_360_;
    short unknown_362_;
    short unknown_364_;
    short unknown_366_;
    short unknown_368_;
    short unknown_36a_;
    short unknown_36c_;
    short unknown_36e_;
    short item_;
    unsigned short unknown_372_[3];
    short unknown_378_[3];
    short message_;
    unsigned short unknown_380_;
    short unknown_382_;
    signed char unknown_384_;
    signed char unknown_385_;
    unsigned char unknown_386_;
    unsigned char unknown_387_;
    unsigned char page_;
    unsigned char pages_;
    unsigned char category_;
    unsigned char count_;
    unsigned char unknown_38c_[3];
    unsigned char state_;
    unsigned char step_;
    unsigned char unknown_391_;
    unsigned char unknown_392_;
    unsigned char unknown_393_;
    unsigned short flags_;
    unsigned char female_;
    unsigned char background_;
    unsigned char unknown_398_[3];
    int unknown_39c_;
    int unknown_3a0_;
    int unknown_3a4_;
    unsigned int unknown_3a8_;
    int unknown_3ac_;
    int unknown_3b0_;
    int unknown_3b4_;
    int unknown_3b8_[0x70 / 4];
    int unknown_428_;
    signed char unknown_42c_;
    unsigned char unknown_42d_;
    unsigned char unknown_42e_;
    unsigned char unknown_42f_;
    unsigned char unknown_430_;
    unsigned char unknown_431_;
    unsigned char unknown_432_;
    unsigned char unknown_433_;
    unsigned char unknown_434_;
};

extern "C" void func_02080c20(Struct_0207fdcc_2* menu, int id);
extern "C" void func_02080c68(void* menu, int group, int value);
extern "C" void func_0207fdcc(Struct_0207fdcc_2* menu, int group);
extern "C" short func_02080468(void* menu, int group);
extern "C" void func_02081ea4(Struct_0207fdcc_2* menu, int group, int value);
extern "C" void func_020813ec(void* menu, int group);
extern "C" void func_ov006_0215951c(Struct_ov006_0215951c* self);
extern "C" void func_020804fc(void* menu, int group);
extern "C" void func_ov006_0215f4dc(Struct_ov006_02157a60* self);
extern "C" void func_ov006_021573c8(void* layout);
extern "C" void func_ov006_021553bc(Struct_ov006_02154614* arg0, short* items, unsigned char* arg2);
extern "C" void func_0208203c(Struct_02081f20_2* repeat);
extern "C" void func_ov006_02155710(Struct_ov006_02154614* arg0, short arg1, unsigned char arg2);
extern "C" int func_ov006_021595b4(Struct_ov006_02157a60* self);
extern "C" unsigned char func_ov006_02158a28(Struct_ov006_02157a60* self);
extern "C" void SePlayer_Play(SePlayer* sound, int, int);
extern "C" int func_ov006_02159218(Struct_ov006_02157a60* self);
extern "C" unsigned char func_ov006_02158b78(Struct_ov006_02157a60* self);
extern "C" void func_0207fe44(Struct_0207fe44* menu);
extern "C" void func_ov006_02158c28(Struct_ov006_02158c28* self);
extern "C" void func_ov006_0215943c(Struct_ov006_02157a60* self);
extern "C" int func_ov006_02159564(void* self);
extern "C" void func_ov006_02159274(Struct_ov006_02157a60* self, unsigned char* category, short* item, unsigned char* count);
extern "C" void func_ov006_021596f0(Struct_ov006_021596f0* self);
extern "C" int func_ov006_02159834(Struct_ov006_02157a60* self);
extern "C" void func_ov006_02159108(Struct_ov006_02157a60* self, unsigned char category, short item, unsigned char count);

extern "C" char g_sePlayer[];

static inline unsigned char inline_ov006_0215bb7c(Struct_ov006_02157a60* self) { return self->category_; }

static inline unsigned char inline_ov003_0216e714(Struct_ov006_02157a60* self) { return self->count_; }

// USA: func_ov006_0215bb7c
extern "C" ARM void func_ov006_0215bb7c(Struct_ov006_02157a60* self) {
    Struct_ov000_0217ab8c* menu = self->menu_;
    if (self->step_ == 0)
    {
        func_02080c20((Struct_0207fdcc_2*)menu, 0x10);
        func_02080c20((Struct_0207fdcc_2*)menu, 0x11);
        func_02080c68(menu, 0x11, 1);
        self->pot_->unknown_ae2_ &= ~0x10;
        func_0207fdcc((Struct_0207fdcc_2*)menu, 0);
        func_0207fdcc((Struct_0207fdcc_2*)menu, 1);
        self->unknown_36e_ = 0x10;
        if (self->unknown_362_ < 0)
            self->unknown_362_ = func_02080468(menu, self->unknown_36e_);
        func_02081ea4((Struct_0207fdcc_2*)menu, self->unknown_36e_, 0);
        func_020813ec(menu, self->unknown_36e_);
        func_02080c68(menu, self->unknown_36e_, 0);
        unsigned char i;
        self->item_ = -1;
        self->count_ = 0;
        for (i = 0; i < 3; i++)
        {
            self->unknown_378_[i] = -1;
            self->unknown_38c_[i] = 0;
        }
        func_ov006_0215951c((Struct_ov006_0215951c*)self);
        func_02081ea4((Struct_0207fdcc_2*)menu, 0x11, 0);
        func_020804fc(menu, 0x11);
        func_ov006_0215f4dc(self);
        self->flags_ |= 0x10;
        func_ov006_021573c8(self->layout_);
        func_ov006_021553bc(self->pot_, self->unknown_378_, self->unknown_38c_);
        func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
        self->cursor_ = 0;
        func_ov006_02155710(self->pot_, -1, 0);
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        if (func_ov006_021595b4(self))
            return;
        self->cursor_ = &self->unknown_362_;
        if (self->unknown_35e_ != *self->cursor_)
        {
            func_ov006_0215951c((Struct_ov006_0215951c*)self);
            func_ov006_0215f4dc(self);
        }
        if (func_ov006_02158a28(self))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            self->cursor_ = 0;
            if (!func_ov006_02159218(self))
                return;
            func_02080c68(menu, self->unknown_36e_, 1);
            func_02081ea4((Struct_0207fdcc_2*)menu, self->unknown_36e_, 1);
            func_02080c68(menu, 0x11, 0);
            self->step_++;
        }
        else if (func_ov006_02158b78(self))
        {
            self->unknown_432_ = 1;
            func_0207fe44((Struct_0207fe44*)menu);
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            self->cursor_ = 0;
            self->unknown_364_ = -1;
            self->state_ = 4;
            self->step_ = 0;
            self->flags_ &= ~0x10;
            self->flags_ |= 0x20;
            self->message_ = 0;
            self->unknown_392_ = 0;
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)self);
    }
    else if (self->step_ == 2)
    {
        unsigned char i;
        for (i = 0; i < 3; i++)
        {
            self->unknown_378_[i] = -1;
            self->unknown_38c_[i] = 0;
        }
        func_ov006_0215943c(self);
        func_ov006_021553bc(self->pot_, self->unknown_378_, self->unknown_38c_);
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        if (func_ov006_02159564(self))
            return;
        if (func_ov006_02158a28(self) && self->unknown_35e_ == *self->cursor_)
        {
            unsigned char category = 0;
            unsigned char count = 0;
            short item = 0;
            func_ov006_02159274(self, &category, &item, &count);
            if (count)
            {
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
                func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
                self->cursor_ = 0;
                func_02081ea4((Struct_0207fdcc_2*)self->menu_, 0x11, 1);
                self->category_ = category;
                self->item_ = item;
                self->count_ = 1;
                self->step_++;
                self->flags_ &= ~0x10;
                self->flags_ |= 0x20;
                self->message_ = 9;
                self->unknown_392_ = 0;
                return;
            }
        }
        else if (func_ov006_02158b78(self))
        {
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            self->cursor_ = 0;
            self->unknown_364_ = -1;
            self->step_ = 0;
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)self);
    }
    else if (self->step_ == 4)
    {
        func_ov006_021596f0((Struct_ov006_021596f0*)self);
        self->unknown_393_ = 0;
        self->step_++;
    }
    else if (self->step_ == 5)
    {
        self->unknown_42c_ = 0;
        int result = func_ov006_02159834(self);
        if (result == 1)
            return;
        if (g_keyManager.TestKeysPressed(1) || result == 2)
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            self->cursor_ = 0;
            self->flags_ &= ~8;
            func_0207fdcc((Struct_0207fdcc_2*)menu, 6);
            unsigned char category = inline_ov006_0215bb7c(self);
            unsigned char count = inline_ov003_0216e714(self);
            func_ov006_02159108(self, category, self->item_, count);
            func_ov006_021553bc(self->pot_, self->unknown_378_, self->unknown_38c_);
            self->state_ = 6;
            self->step_ = 0;
#if !defined(jpn)
            self->unknown_387_ = self->count_;
#endif
            self->message_ = 0x39;
            self->unknown_392_ = 0;
            self->flags_ |= 0x20 | 0x100;
        }
        else if (func_ov006_02158b78(self) || result == 3)
        {
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            self->cursor_ = 0;
            self->flags_ &= ~8;
            func_0207fdcc((Struct_0207fdcc_2*)menu, 6);
            self->step_ = 0;
            self->message_ = 0x24;
            self->unknown_392_ = 0;
            self->flags_ |= 0x20 | 0x100;
        }
    }
}
