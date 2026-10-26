#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov014_02184f78 {
    Struct_ov014_02184f78* unknown_0_;
};

struct Struct_ov000_0217ab8c {
    char unk_0[R(0x20, 0x2c)];
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

typedef void (Struct_ov014_02186bc8::*Type_0207fc6c)();

struct Struct_ov014_02186bc8_2;
struct Struct_0207fc6c;
struct Struct_ov014_02186bc8_3;

extern "C" void func_ov014_02186df0(Struct_ov014_02186bc8_2*);
extern "C" void func_0207fc6c(Struct_0207fc6c*, int);
extern "C" short func_ov014_021874f8(Struct_ov014_02186bc8_3*);
extern "C" void func_020804fc(void*, int);

extern "C" {
bool func_ov017_021959b4();
void func_02081f20(void* repeat, int ticks);
int func_020800fc(Struct_ov000_0217ab8c* menu, short* cursor, short arg2, unsigned short arg3, unsigned char, bool);
void func_020813ec(Struct_ov000_0217ab8c* menu, short group);
void func_ov014_02184700(Struct_ov014_02186bc8* self);
void func_ov014_021886f8(Struct_ov014_02186bc8* self);
}

extern unsigned int data_ov014_0218981c;
extern Type_0207fc6c __ptmf_null;
extern Type_0207fc6c data_ov014_021896d4[7];
extern Type_0207fc6c data_ov014_021896d4_dup[7];

// USA: func_ov014_02186bc8
extern "C" ARM bool func_ov014_02186bc8(Struct_ov014_02186bc8* self, int ticks)
{
    if (ticks == 0)
        ticks = 1;
    self->ticks_ = ticks;
    if (func_ov017_021959b4())
        func_ov014_02186df0((Struct_ov014_02186bc8_2*)self);
    if (self->unknown_17a_ != 0)
    {
        func_0207fc6c((Struct_0207fc6c*)self->menu_, self->ticks_);
        if (self->cursor_ != NULL)
        {
            func_02081f20(self->unknown_14c_, self->ticks_);
            self->unknown_178_ = *self->cursor_;
            bool var0 = false;
            if (self->unknown_17a_ == 4)
                var0 = func_ov014_021874f8((Struct_ov014_02186bc8_3*)self) > 16;
            self->unknown_160_ = func_020800fc(self->menu_, self->cursor_, self->unknown_178_, self->unknown_158_, self->unknown_15a_, var0);
            self->menu_->cursor_ = *self->cursor_;
            if (self->unknown_160_ != 0)
                func_020804fc(self->menu_, self->unknown_170_);
            if (self->unknown_178_ != *self->cursor_)
                func_020813ec(self->menu_, self->unknown_170_);
        }
    }
    func_ov014_02184700(self);
    func_ov014_021886f8(self);

    if (!(data_ov014_0218981c & 1))
    {
        data_ov014_021896d4_dup[6] = __ptmf_null;
        data_ov014_0218981c |= 1;
    }
    if (data_ov014_021896d4[self->unknown_17a_] == NULL)
        return true;
    (self->*data_ov014_021896d4[self->unknown_17a_])();
    return false;
}
