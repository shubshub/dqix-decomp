#include <globaldefs.h>
#include "Input/Input.h"
#if defined(jpn)
#define REGION_MEMBER_SHORT_OFFSET 0x2a
#define REGION_MENU_LEADING_SIZE 0x20
#define func_ov014_02188330 func_ov014_02189234
#else
#define REGION_MEMBER_SHORT_OFFSET 0x36
#define REGION_MENU_LEADING_SIZE 0x2c
#endif

struct Struct_ov014_02184f78 {
    Struct_ov014_02184f78* unknown_0_;
};

struct Struct_ov000_0217ab8c {
    char unk_0[REGION_MENU_LEADING_SIZE];
    void* backgrounds_;
    char unknown_30_[6];
    short cursor_;
    unsigned char unknown_38_;
    char unknown_39_;
    unsigned char unknown_3a_;
    char unknown_3b_[5];
};

struct Struct_020974b0 {
    char unk_0[0x10];
};

struct Struct_ov014_02186bc8 {
    char unk_0[0xa4];
    Struct_020974b0 list_;
    void* unknown_b4_;
    Struct_ov014_02184f78* entries_;
    Struct_ov014_02184f78* unknown_bc_;
    Struct_ov000_0217ab8c* menu_;
    void* backgrounds_;
    void* canvases_;
    void* canvasBuffer_;
    short* cursor_;
    void* unknown_d4_;
    void* animations_;
    void* unknown_dc_;
    char textTable_[0x18];
    char spriteRenderer_[0x54];
    char unknown_14c_[0xc];
    unsigned short unknown_158_;
    unsigned char unknown_15a_;
    char unknown_15b_;
    int unknown_15c_;
    int unknown_160_;
    int ticks_;
    int unknown_168_;
    int unknown_16c_;
    short unknown_170_;
    short unknown_172_;
    short unknown_174_;
    short unknown_176_;
    short unknown_178_;
    unsigned char unknown_17a_;
    unsigned char unknown_17b_;
    unsigned char unknown_17c_;
    signed char unknown_17d_;
    unsigned char unknown_17e_;
    bool unknown_17f_;
    short unknown_180_;
    short unknown_182_[8];
};

struct Struct_0207fdcc_2;
struct SePlayer;
struct Struct_02081f20_2;

extern "C" short func_02080468(void* obj, int id);
extern "C" void func_0208203c(Struct_02081f20_2*);
extern "C" void func_0207fdcc(Struct_0207fdcc_2*, int);
extern "C" int func_ov014_02186ff0(char*);
extern "C" void SePlayer_Play(SePlayer*, int, int);

extern "C" {
Struct_ov014_02184f78* func_020974b0(Struct_020974b0* list, int arg1, int, bool arg3, int, short* outCount);
void func_ov014_02188330(Struct_ov014_02186bc8* self);
void func_020813ec(Struct_ov000_0217ab8c* menu, short group);
bool func_ov014_02186f10(Struct_ov014_02186bc8* self);
}

extern char g_sePlayer[];

// USA: func_ov014_02187c04
extern "C" ARM void func_ov014_02187c04(Struct_ov014_02186bc8* self)
{
    if (self->unknown_17b_ == 0)
    {
        if (!(self->unknown_17e_ & 0x10))
        {
            short count = 0;
            self->entries_ = func_020974b0(&self->list_, self->unknown_17d_, -1, (self->unknown_17e_ & 8) != 0, 0x10, &count);
            self->unknown_bc_ = self->entries_;
            func_ov014_02188330(self);
            self->unknown_170_ = 1;
            if (self->unknown_172_ < 0)
                self->unknown_172_ = func_02080468(self->menu_, self->unknown_170_);
            self->menu_->cursor_ = self->unknown_172_;
            func_020813ec(self->menu_, self->unknown_170_);
            func_0208203c((Struct_02081f20_2*)self->unknown_14c_);
            self->cursor_ = NULL;
            self->unknown_17b_++;
        }
    }
    else if (self->unknown_17b_ == 1)
    {
        self->cursor_ = &self->unknown_172_;
        if (func_ov014_02186f10(self))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_14c_);
            switch (*self->cursor_)
            {
            case 8:
                self->unknown_17e_ |= 0x10;
                self->unknown_17a_ = 4;
                self->unknown_17b_ = 0;
                break;
            case 9:
                self->unknown_17a_ = 3;
                self->unknown_17b_ = 0;
                break;
            }
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, self->unknown_170_);
            self->cursor_ = NULL;
        }
        else if (func_ov014_02186ff0((char*)self) || g_keyManager.TestKeysPressed(0x800))
        {
            self->unknown_17a_ = 5;
            self->unknown_17b_ = 0;
        }
    }
}
