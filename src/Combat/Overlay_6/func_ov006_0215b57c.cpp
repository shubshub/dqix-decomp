#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215b57c_4696 = 0x1054, Enum_ov006_0215b57c_54 = 0x2a };
#else
enum { Enum_ov006_0215b57c_4696 = 0x1258, Enum_ov006_0215b57c_54 = 0x36 };
#endif

struct Struct_02081f20_2;
struct Struct_ov006_02157184;
struct SePlayer;
struct Struct_0207fdcc_2;
struct Struct_ov006_02158c28;

struct Struct_ov006_021537d0 {
    short id_;
    short item_;
    char unk_4[0x18];
    Struct_ov006_021537d0* unknown_1c_;
};

struct Struct_ov006_021555b0 {
    short id_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02154614 {
    char unk_0[Enum_ov006_0215b57c_4696];
    unsigned short unknown_1258_;
};

struct Struct_ov000_0217ab8c {
    char unk_0[Enum_ov006_0215b57c_54];
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

extern "C" void func_ov006_0215fa1c(Struct_ov006_02157a60* self, int total);
extern "C" void func_ov006_0215fb7c(Struct_ov006_02157a60* self);
extern "C" void func_ov006_0215fcf0(Struct_ov006_02157a60* self);
extern "C" void func_ov006_0215f7e8(Struct_ov006_02157a60* self);
extern "C" void func_0208203c(Struct_02081f20_2* repeat);
extern "C" Struct_ov006_021537d0* func_ov006_02158d8c(void* self, short index);
extern "C" Struct_ov006_021555b0* func_ov006_02153c6c(void* ingredients, short id);
extern "C" void func_ov006_02153b9c(void* ingredients, short id, unsigned char* arg2);
extern "C" void func_ov006_02157184(Struct_ov006_02157184* arg0);
extern "C" void func_ov006_021555b0(Struct_ov006_02154614* arg0, Struct_ov006_021537d0* arg1, Struct_ov006_021555b0* record, unsigned char* arg3);
extern "C" unsigned char func_ov006_02159bb0(Struct_ov006_02157a60* self);
extern "C" void func_ov006_02159c64(Struct_ov006_02157a60* self);
extern "C" void func_ov006_021570fc(Struct_ov006_02154614* arg0, int shown);
extern "C" void SePlayer_Play(SePlayer* sound, int, int);
extern "C" unsigned char func_ov006_02158a28(Struct_ov006_02157a60* self);
extern "C" unsigned char func_ov006_02158b78(Struct_ov006_02157a60* self);
extern "C" void func_0207fdcc(Struct_0207fdcc_2* menu, int group);
extern "C" void func_ov006_02158c28(Struct_ov006_02158c28* self);

extern "C" char g_sePlayer[];

// USA: func_ov006_0215b57c
extern "C" ARM void func_ov006_0215b57c(Struct_ov006_02157a60* self) {
    Struct_ov006_02154614* var0 = self->pot_;
    if (self->step_ == 0)
    {
        self->background_ = 1;
        func_ov006_0215fa1c(self, 0);
        func_ov006_0215fb7c(self);
        func_ov006_0215fcf0(self);
        self->unknown_36e_ = 9;
        if (self->unknown_36a_ < 0)
            self->unknown_36a_ = 0x29;
        self->menu_->cursor_ = self->unknown_36a_;
        func_ov006_0215f7e8(self);
        func_0208203c((Struct_02081f20_2*)self->unknown_9c_);
        self->cursor_ = 0;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        self->cursor_ = &self->unknown_36a_;
        int result = self->menuResult_;
        int var2 = 0;
        if (result & 0x10)
        {
            var2 = 1;
            self->page_++;
        }
        else if (result & 0x20)
        {
            var2 = 1;
            self->page_--;
        }
        if (self->page_ == 0xff)
            self->page_ = self->pages_ - 1;
        if (self->pages_ <= self->page_)
            self->page_ = 0;
        Struct_ov006_021537d0* var3 = func_ov006_02158d8c(self, self->unknown_36a_ - 0x29);
        Struct_ov006_021555b0* record = 0;
        if (var3 != 0)
        {
            record = func_ov006_02153c6c(self->ingredients_, var3->id_);
            func_ov006_02153b9c(self->ingredients_, var3->id_, self->unknown_398_);
        }
        else
        {
            func_ov006_02157184((Struct_ov006_02157184*)var0);
        }
        func_ov006_021555b0(var0, var3, record, self->unknown_398_);
        if (var2)
        {
            func_ov006_0215f7e8(self);
            return;
        }
        unsigned char var5 = func_ov006_02159bb0(self);
        if (var5 == 1)
        {
            func_ov006_02159c64(self);
            return;
        }
        if (var5 == 4)
        {
            if (var3 != 0 && record != 0)
            {
                func_ov006_021570fc(var0, (var0->unknown_1258_ & 0x800) ? 0 : 1);
                SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            }
            return;
        }
        if (!func_ov006_02158a28(self) && func_ov006_02158b78(self))
        {
            self->flags_ &= ~0x80;
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, self->unknown_36e_);
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, 0xe);
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, 0xf);
            self->state_ = 2;
            self->step_ = 0;
            self->background_ = 2;
            func_ov006_02157184((Struct_ov006_02157184*)var0);
            if (self->unknown_366_ == 0x25 || self->unknown_366_ == 0x26)
                self->step_ = 2;
        }
        func_ov006_02158c28((Struct_ov006_02158c28*)self);
    }
}
