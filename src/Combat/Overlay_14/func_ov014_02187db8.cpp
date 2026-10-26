#if defined(jpn)
#define R(j,u) (j)
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov014_02184f78 {
    Struct_ov014_02184f78* unknown_0_;
};

struct Struct_ov000_0217ab8c {
    char unk_0[0x2c];
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
struct Struct_ov014_02186bc8_3;

extern "C" short func_02080468(void* obj, int id);
extern "C" void func_0208203c(Struct_02081f20_2*);
extern "C" void func_0207fdcc(Struct_0207fdcc_2*, int);
extern "C" int func_ov014_02186ff0(char*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" short func_ov014_021874f8(Struct_ov014_02186bc8_3*);

extern "C" {
Struct_ov014_02184f78* func_020974b0(Struct_020974b0* list, int arg1, int, bool arg3, int, short* outCount);
void func_ov014_02188330(Struct_ov014_02186bc8* self);
void func_020813ec(Struct_ov000_0217ab8c* menu, short group);
bool func_ov014_02186f10(Struct_ov014_02186bc8* self);
}

extern char g_sePlayer[];

// USA: func_ov014_02187db8
extern "C" ARM void func_ov014_02187db8(Struct_ov014_02186bc8* self)
{
    if (self->unknown_17b_ == 0)
    {
        if (!(self->unknown_17e_ & 0x10))
        {
            self->unknown_170_ = 2;
            if (self->unknown_174_ < 0)
                self->unknown_174_ = func_02080468(self->menu_, self->unknown_170_);
            func_020813ec(self->menu_, self->unknown_170_);
            self->unknown_17d_ = self->unknown_174_ - 0xb;
            short count = 0;
            self->entries_ = func_020974b0(&self->list_, self->unknown_17d_, -1, (self->unknown_17e_ & 8) != 0, 0x10, &count);
            self->unknown_bc_ = self->entries_;
            func_ov014_02188330(self);
            self->unknown_17b_++;
        }
    }
    else if (self->unknown_17b_ == 1)
    {
        self->cursor_ = &self->unknown_174_;
        self->unknown_17d_ = self->unknown_174_ - 0xb;
        if (self->unknown_160_ != 0 || self->unknown_178_ != *self->cursor_)
        {
            short count = 0;
            self->entries_ = func_020974b0(&self->list_, self->unknown_17d_, -1, (self->unknown_17e_ & 8) != 0, 0x10, &count);
            self->unknown_bc_ = self->entries_;
            func_ov014_02188330(self);
        }
        if (func_ov014_02186f10(self))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)self->unknown_14c_);
            if (func_ov014_021874f8((Struct_ov014_02186bc8_3*)self) != 0)
            {
                func_0207fdcc((Struct_0207fdcc_2*)self->menu_, self->unknown_170_);
                self->cursor_ = NULL;
                self->unknown_17a_ = 4;
                self->unknown_17b_ = 0;
                self->unknown_17e_ |= 0x10;
            }
        }
        else if (func_ov014_02186ff0((char*)self))
        {
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, self->unknown_170_);
            self->unknown_174_ = -1;
            self->unknown_17d_ = -1;
            self->unknown_17a_ = 2;
            self->unknown_17b_ = 0;
        }
        else if (g_keyManager.TestKeysPressed(0x800))
        {
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, self->unknown_170_);
            self->unknown_174_ = -1;
            self->unknown_17d_ = -1;
            self->unknown_17a_ = 5;
            self->unknown_17b_ = 0;
        }
    }
}
