#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov006_0215b7e8_54 = 0x2a, Enum_ov006_0215b7e8_76 = 0x48, Enum_ov006_0215b7e8_4180 = 0x1054 };
#else
enum { Enum_ov006_0215b7e8_54 = 0x36, Enum_ov006_0215b7e8_76 = 0x4c, Enum_ov006_0215b7e8_4696 = 0x1258 };
#endif

struct Struct_02081f20_2;
struct SePlayer;
struct Struct_0207fdcc_2;
struct Struct_ov006_0215b7e8_2;
struct Struct_0207fe44;
struct Struct_ov006_02154614;

struct Struct_ov006_0215b7e8 {
    char unk_0[0x16];
    unsigned char flags_;
};

struct Struct_ov000_0217ab8c {
    char unk_0[Enum_ov006_0215b7e8_54];
    short cursor_;
};

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
    int layout_[Enum_ov006_0215b7e8_76 / 4];
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[0xc];
#if defined(jpn)
    char unknown1_170_[0xc];
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

extern "C" void func_ov006_021570fc(Struct_ov006_02154614* arg0, int shown);
extern "C" short func_02080468(void* menu, int group);
extern "C" void func_020813ec(void* menu, int group);
extern "C" void func_ov006_0215f348(Struct_ov006_0215b7e8_2* self);
extern "C" void func_02081ea4(Struct_0207fdcc_2* menu, int group, int value);
extern "C" void func_0208203c(Struct_02081f20_2* repeat);
extern "C" void func_02080c04(Struct_0207fdcc_2* menu, int id);
extern "C" void func_02080c20(Struct_0207fdcc_2* menu, int id);
extern "C" unsigned char func_ov006_02158a28(Struct_ov006_02157a60* self);
extern "C" unsigned char func_ov006_02158b78(Struct_ov006_02157a60* self);
extern "C" void SePlayer_Play(SePlayer* sound, int, int);
extern "C" void func_0207fe44(Struct_0207fe44* menu);
extern "C" Struct_ov006_0215b7e8* func_ov006_02157368(void* layout, short id);
extern "C" void func_ov006_02158de0(Struct_ov006_02157a60* self);
extern "C" void func_0207fdcc(Struct_0207fdcc_2* menu, int group);

extern "C" char g_sePlayer[];

// USA: func_ov006_0215b7e8
extern "C" ARM void func_ov006_0215b7e8(Struct_ov006_02157a60* self) {
    Struct_ov000_0217ab8c* menu = self->menu_;
    if (self->step_ == 0)
    {
        func_ov006_021570fc(self->pot_, 1);
        self->background_ = 0;
        self->unknown_36e_ = 2;
        if (self->unknown_360_ < 0)
            self->unknown_360_ = func_02080468(menu, self->unknown_36e_);
        menu->cursor_ = self->unknown_360_;
        func_020813ec(menu, self->unknown_36e_);
        func_ov006_0215f348((Struct_ov006_0215b7e8_2*)self);
        func_02081ea4((Struct_0207fdcc_2*)menu, self->unknown_36e_, 0);
        func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
        self->cursor_ = 0;
        self->step_++;
        if (self->unknown_360_ == 4)
            func_02080c04((Struct_0207fdcc_2*)menu, 3);
        else
            func_02080c20((Struct_0207fdcc_2*)menu, 3);
    }
    else if (self->step_ == 1)
    {
        self->cursor_ = &self->unknown_360_;
        if (self->unknown_35e_ != *self->cursor_)
        {
            if (self->unknown_360_ == 4)
                func_02080c04((Struct_0207fdcc_2*)menu, 3);
            else
                func_02080c20((Struct_0207fdcc_2*)menu, 3);
            func_ov006_0215f348((Struct_ov006_0215b7e8_2*)self);
        }
        self->unknown_42c_ = 0;
        if (func_ov006_02158a28(self))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            self->cursor_ = 0;
            switch (self->unknown_360_)
            {
            case 2:
                self->unknown_366_ = -1;
                func_0207fe44((Struct_0207fe44*)menu);
                self->state_ = 9;
                self->step_ = 0;
                {
                    Struct_ov006_0215b7e8* element = func_ov006_02157368(self->layout_, 0x50);
                    if (element != 0)
                        element->flags_ &= ~1;
                }
                {
                    Struct_ov006_0215b7e8* element = func_ov006_02157368(self->layout_, 0x4f);
                    if (element != 0)
                        element->flags_ |= 1;
                }
                {
                    Struct_ov006_0215b7e8* element = func_ov006_02157368(self->layout_, 0xe);
                    if (element != 0)
                        element->flags_ &= ~1;
                }
                {
                    Struct_ov006_0215b7e8* element = func_ov006_02157368(self->layout_, 0xf);
                    if (element != 0)
                        element->flags_ |= 1;
                }
                {
                    Struct_ov006_0215b7e8* element = func_ov006_02157368(self->layout_, 0x15);
                    if (element != 0)
                        element->flags_ &= ~1;
                }
                break;
            case 3:
            {
                func_ov006_02158de0(self);
                unsigned short* sizes = self->sizes_;
                unsigned char i;
                int found = 0;
                if (sizes != 0)
                {
                    for (i = 0; i < 9; i++)
                    {
                        if (sizes[i] != 0)
                        {
                            found = 1;
                            break;
                        }
                    }
                    if (sizes[8] != 0)
                        found = 1;
                }
                if (found)
                {
                    self->unknown_362_ = -1;
                    self->unknown_364_ = -1;
                    func_0207fe44((Struct_0207fe44*)menu);
                    self->state_ = 5;
                    self->step_ = 0;
                    func_ov006_021570fc(self->pot_, 1);
                    self->message_ = 0x24;
                    self->unknown_392_ = 0;
                    self->flags_ |= 0x20 | 0x100;
                    break;
                }
                self->flags_ |= 0x20;
                self->message_ = 0x35;
                self->unknown_392_ = 0;
                func_02081ea4((Struct_0207fdcc_2*)menu, self->unknown_36e_, 1);
                self->step_ = 0;
                func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
                self->cursor_ = 0;
                return;
            }
            case 4:
                self->state_ = 0xc;
                self->step_ = 0;
                break;
            }
            func_0207fdcc((Struct_0207fdcc_2*)menu, 3);
            func_0207fdcc((Struct_0207fdcc_2*)menu, self->unknown_36e_);
            return;
        }
        if (func_ov006_02158b78(self) || g_keyManager.TestKeysPressed(0x800))
        {
            func_0207fe44((Struct_0207fe44*)menu);
            self->state_ = 0xc;
            self->step_ = 0;
        }
    }
}
