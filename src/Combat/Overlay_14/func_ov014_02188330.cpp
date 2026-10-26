#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov014_02188330 func_ov014_02189234
#endif

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

struct Struct_02080fa8;
struct Struct_02081164;

extern "C" void func_02080bac(void* obj, int id);
extern "C" void func_0208103c(void* obj, int id, int value);
extern "C" void func_02080fa8(Struct_02080fa8* obj, int id, int value);
extern "C" int func_02080b2c(void* obj, int id);
extern "C" void func_02081164(Struct_02081164* owner, int id, int enable);

extern "C" {
#if !defined(jpn)
void func_020806d8(Struct_ov000_0217ab8c* menu, int, int, int, int);
#endif
void func_020813ec(Struct_ov000_0217ab8c* menu, short group);
}

extern const short data_ov014_021894cc[3][11];

// USA: func_ov014_02188330
extern "C" ARM void func_ov014_02188330(Struct_ov014_02186bc8* self)
{
    int hidden = 0;
    if (self->unknown_17a_ == 4)
        hidden = 1;
    if (self->unknown_17a_ == 3)
        hidden = 2;
#if !defined(jpn)
    func_020806d8(self->menu_, 0, 2, 1, 4);
#endif
    func_02080bac(self->menu_, 0);
    if (self->unknown_17d_ >= 0)
        func_0208103c(self->menu_, 0x2f, (short)(self->unknown_17d_ + 0x1e));

    short var1 = 0;
    Struct_ov014_02184f78* entry = self->entries_;
    if (entry != NULL)
    {
        for (; entry != NULL; entry = entry->unknown_0_)
            var1 += entry->unknown_13_1_;
    }

    short var3 = self->unknown_180_;
    short var4 = 0;
    if (var3 != 0)
    {
        float value = (float)var1 / (float)var3;
        value *= 10000.0f;
        if (value < 100.0f)
            value = 100.0f;
        if (var1 == 0)
            value = 0.0f;
        short var6 = value;
        var4 = var6 / 100;
    }
    func_02080fa8((Struct_02080fa8*)self->menu_, 4, var4);
    func_02080fa8((Struct_02080fa8*)self->menu_, 5, var1);
    for (unsigned char i = 0;; i++)
    {
        short item = data_ov014_021894cc[hidden][i];
        if (item < 0)
            break;
        func_02080b2c(self->menu_, item);
    }
    func_02081164((Struct_02081164*)self->menu_, 0, 1);
    func_020813ec(self->menu_, 0);
}
