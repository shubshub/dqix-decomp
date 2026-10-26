#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov014_02184f78 {
    Struct_ov014_02184f78* unknown_0_;
    const char* unknown_4_;
    const char* name_;
    short unknown_c_;
    char unknown_e_[4];
    signed char unknown_12_;
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 6;
    char unk_14[6];
    short unknown_1a_;
    char unk_1c[4];
};

struct Canvas {
    Canvas* unk_0;
    void* background_;
    char unk_8[0xa0];
    short width_;
    short height_;
    short x_;
    short y_;
    char unk_b0[0x30];
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
    void* menu_;
    void* backgrounds_;
    Canvas* canvases_;
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

extern "C" Canvas* func_02081da8(Struct_0207fdcc_2*, int);
extern "C" bool WindowPane_IsOpen(unsigned char*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_020804fc(void*, int);

extern "C" {
Struct_ov014_02184f78* func_ov014_021873a0(Struct_ov014_02186bc8* self);
Struct_ov014_02184f78* func_020974b0(Struct_020974b0* list, int arg1, int, bool arg3, int, short* outCount);
void func_ov014_02187228(Struct_ov014_02186bc8* self, Struct_ov014_02184f78* entry);
void func_ov014_0218854c(Struct_ov014_02186bc8* self);
void func_ov014_021885bc(Struct_ov014_02186bc8* self);
}

extern char g_sePlayer[];

inline short inline_ov014_02187074(short tiles)
{
    return tiles * 8;
}

// USA: func_ov014_02187074
extern "C" ARM bool func_ov014_02187074(Struct_ov014_02186bc8* self)
{
    bool toggle = false;
    Canvas* canvas = func_02081da8((Struct_0207fdcc_2*)self->menu_, 4);
    if (canvas != NULL && WindowPane_IsOpen((unsigned char*)canvas))
    {
        short y = canvas->y_;
        short height = canvas->height_;
        y--;
        height++;
        short left = inline_ov014_02187074(canvas->x_);
        short top = inline_ov014_02187074(y);
        short right = left + inline_ov014_02187074(canvas->width_);
        short bottom = top + inline_ov014_02187074(height);
        if (g_touchInput.pressed_)
        {
            int x;
            int y;
            g_touchInput.GetTouchPoint(&x, &y);
            if (left <= x && x < right && top <= y && y < bottom)
                toggle = true;
        }
    }
    if (g_keyManager.TestKeysPressed(4))
        toggle = true;
    if (toggle)
    {
        Struct_ov014_02184f78* entry = func_ov014_021873a0(self);
        if (entry == NULL)
            return false;
        if (!entry->unknown_13_1_)
        {
            self->unknown_176_ = -1;
            self->unknown_178_ = -1;
            entry = NULL;
        }
        if (self->unknown_17e_ & 8)
            self->unknown_17e_ &= ~8;
        else
            self->unknown_17e_ |= 8;
        short count = 0;
        self->entries_ = func_020974b0(&self->list_, self->unknown_17d_, -1, (self->unknown_17e_ & 8) != 0, 0x10, &count);
        func_ov014_02187228(self, entry);
        SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
        func_020804fc(self->menu_, 5);
        func_ov014_0218854c(self);
        func_ov014_021885bc(self);
    }
    return toggle;
}
