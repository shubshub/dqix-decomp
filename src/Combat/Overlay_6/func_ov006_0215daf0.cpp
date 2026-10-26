#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215daf0_54 = 0x2a, Enum_ov006_0215daf0_76 = 0x48, Enum_ov006_0215daf0_4180 = 0x1054 };
#else
enum { Enum_ov006_0215daf0_54 = 0x36, Enum_ov006_0215daf0_76 = 0x4c, Enum_ov006_0215daf0_4696 = 0x1258 };
#endif

struct Struct_02081f20_2;
struct SePlayer;
struct Struct_0207fdcc_2;
struct Struct_0207fe44;
struct Struct_02071ffc_4;
struct Struct_ov006_02157184;
struct Struct_ov006_02158c28;
struct Struct_ov006_02154614;
struct Struct_ov006_021537d0;

struct Struct_ov000_0217ab8c {
    char unk_0[Enum_ov006_0215daf0_54];
    short cursor_;
};

struct Struct_ov006_0215b1a0 {
    Struct_ov006_021537d0* unk_0;
    int unk_4[2];
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
    Struct_ov006_021537d0* unknown_2c_;
    Struct_ov006_021537d0* unknown_30_;
    Struct_ov006_021537d0* unknown_34_;
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
    int layout_[Enum_ov006_0215daf0_76 / 4];
    Struct_ov006_0215b1a0 table_;
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

extern "C" void func_ov006_0215fa1c(Struct_ov006_02157a60* self, int total);
extern "C" void func_020813ec(void* menu, int group);
extern "C" void func_0208203c(Struct_02081f20_2* repeat);
extern "C" unsigned char func_ov006_02158a28(Struct_ov006_02157a60* self);
extern "C" unsigned char func_ov006_02158b78(Struct_ov006_02157a60* self);
extern "C" void SePlayer_Play(SePlayer* sound, int, int);
extern "C" void func_02071ffc(Struct_02071ffc_4* table, int category, int kind, int arg3, short max, short* count);
extern "C" void func_ov006_02158cac(void* self);
extern "C" void func_0207fdcc(Struct_0207fdcc_2* menu, int group);
extern "C" void func_0207fe44(Struct_0207fe44* menu);
extern "C" void func_ov006_02157184(Struct_ov006_02157184* arg0);
extern "C" void func_ov006_0215745c(short arg0, signed char* category, signed char* kind);
extern "C" void func_ov006_02158c28(Struct_ov006_02158c28* self);

extern "C" char g_sePlayer[];

// USA: func_ov006_0215daf0
extern "C" ARM void func_ov006_0215daf0(Struct_ov006_02157a60* self) {
    if (self->step_ == 0)
    {
        self->background_ = 2;
        func_ov006_0215fa1c(self, 1);
        self->unknown_36e_ = 8;
        if (self->unknown_366_ < 0)
            self->unknown_366_ = 0x24;
        self->menu_->cursor_ = self->unknown_366_;
        func_020813ec(self->menu_, self->unknown_36e_);
        func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
        self->cursor_ = 0;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        self->cursor_ = &self->unknown_366_;
        if (func_ov006_02158a28(self))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            int open = 0;
            self->cursor_ = 0;
            self->unknown_368_ = -1;
            self->unknown_36a_ = -1;
            self->unknown_384_ = -1;
            self->unknown_385_ = -1;
            switch (self->unknown_366_)
            {
            case 0x24:
                open = 1;
                break;
            case 0x25:
                self->unknown_384_ = 0;
                self->step_++;
                break;
            case 0x26:
                self->step_++;
                break;
            case 0x27:
                self->unknown_384_ = 7;
                open = 1;
                break;
            case 0x28:
                self->unknown_384_ = 8;
                open = 1;
                break;
            }
            if (open)
            {
                self->state_ = 0xa;
                self->step_ = 0;
                self->flags_ |= 0x80;
            }
            short count = 0;
            func_02071ffc((Struct_02071ffc_4*)&self->table_, self->unknown_384_, self->unknown_385_, self->unknown_386_, 0x10, &count);
            Struct_ov006_021537d0* var2 = self->table_.unk_0;
            self->unknown_2c_ = var2;
            self->unknown_30_ = var2;
            func_ov006_02158cac(self);
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, self->unknown_36e_);
            return;
        }
        if (func_ov006_02158b78(self))
        {
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            self->cursor_ = 0;
            func_0207fe44((Struct_0207fe44*)self->menu_);
            self->state_ = 4;
            self->step_ = 0;
            self->background_ = 0;
            self->flags_ |= 0x20;
            self->message_ = 0;
            self->unknown_392_ = 0;
            func_ov006_02157184((Struct_ov006_02157184*)self->pot_);
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)self);
    }
    else if (self->step_ == 2)
    {
        self->background_ = 2;
        func_ov006_0215fa1c(self, 0);
        short var3 = self->unknown_366_;
        if (var3 == 0x25)
        {
            self->unknown_36e_ = 0xc;
            if (self->unknown_368_ < 0)
                self->unknown_368_ = 0x48;
        }
        else if (var3 == 0x26)
        {
            self->unknown_36e_ = 0xb;
            if (self->unknown_368_ < 0)
                self->unknown_368_ = 0x40;
        }
        self->menu_->cursor_ = self->unknown_368_;
        func_020813ec(self->menu_, self->unknown_36e_);
        func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
        self->cursor_ = 0;
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        self->cursor_ = &self->unknown_368_;
        if (func_ov006_02158a28(self))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            self->cursor_ = 0;
            self->unknown_36a_ = -1;
            func_ov006_0215745c(self->unknown_368_, &self->unknown_384_, &self->unknown_385_);
            short count = 0;
            func_02071ffc((Struct_02071ffc_4*)&self->table_, self->unknown_384_, self->unknown_385_, self->unknown_386_, 0x10, &count);
            Struct_ov006_021537d0* var5 = self->table_.unk_0;
            self->unknown_2c_ = var5;
            self->unknown_30_ = var5;
            func_ov006_02158cac(self);
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, self->unknown_36e_);
            self->state_ = 0xa;
            self->step_ = 0;
            self->flags_ |= 0x80;
            return;
        }
        if (func_ov006_02158b78(self))
        {
            func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
            self->cursor_ = 0;
            self->unknown_368_ = -1;
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, self->unknown_36e_);
            self->step_ = 0;
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)self);
    }
}
