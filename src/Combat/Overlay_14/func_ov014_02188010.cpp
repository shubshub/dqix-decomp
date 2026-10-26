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

struct MonsterRecord;

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
    char unk_0[0x48];
    Struct_ov014_02184f78* unknown_48_;
    Struct_ov014_02184f78* unknown_4c_;
    char unk_50[0x31];
    unsigned char flags_;
    unsigned char unknown_82_0_ : 1;
    unsigned char unknown_82_1_ : 1;
    unsigned char unknown_82_2_ : 1;
    unsigned char unknown_82_3_ : 1;
    unsigned char unknown_82_4_ : 4;
    char unknown_83_[0x21];
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
struct Struct_02081f20_2;
struct Struct_ov014_02187450;
struct Struct_ov014_02187450_2;
struct Struct_ov014_02184f10;

extern "C" short func_02080468(void* obj, int id);
extern "C" void func_0208203c(Struct_02081f20_2*);
extern "C" void func_0207fdcc(Struct_0207fdcc_2*, int);
extern "C" int func_ov014_02186ff0(char*);
extern "C" MonsterRecord* func_ov014_02187450(Struct_ov014_02187450*, Struct_ov014_02187450_2*);
extern "C" void func_ov014_02184f10(Struct_ov014_02184f10*, int, int);
extern "C" void func_ov014_02184e3c(unsigned char*);

extern "C" {
void func_ov014_02188330(Struct_ov014_02186bc8* self);
void func_ov014_021884cc(Struct_ov014_02186bc8* self);
void func_ov014_0218854c(Struct_ov014_02186bc8* self);
void func_ov014_021885bc(Struct_ov014_02186bc8* self);
Struct_ov014_02184f78* func_ov014_021873a0(Struct_ov014_02186bc8* self);
void func_ov014_02184f78(Struct_ov014_02186bc8* self, Struct_ov014_02184f78* monster, MonsterRecord* record, bool arg3);
bool func_ov014_02187074(Struct_ov014_02186bc8* self);
void func_ov014_021872dc(Struct_ov014_02186bc8* self, int pages);
bool func_ov014_02186f10(Struct_ov014_02186bc8* self);
void func_ov014_02184dcc(Struct_ov014_02186bc8* self);
void func_ov014_02184d08(Struct_ov014_02186bc8* self);
}

static inline MonsterRecord* inline_ov014_02188010(Struct_ov014_02186bc8* self, Struct_ov014_02184f78* entry)
{
    return func_ov014_02187450((Struct_ov014_02187450*)self, (Struct_ov014_02187450_2*)entry);
}

static inline void inline_ov014_02188010_2(Struct_ov014_02186bc8* self, Struct_ov014_02184f78* entry, MonsterRecord* record)
{
    func_ov014_02184f10((Struct_ov014_02184f10*)self, (int)entry, (int)record);
}

// USA: func_ov014_02188010
extern "C" ARM void func_ov014_02188010(Struct_ov014_02186bc8* self)
{
    if (self->unknown_17b_ == 0)
    {
        if (self->unknown_17e_ & 0x10)
            return;
        self->unknown_bc_ = self->entries_;
        func_ov014_02188330(self);
        func_ov014_021884cc(self);
        func_ov014_0218854c(self);
        self->unknown_170_ = 5;
        self->unknown_176_ = func_02080468(self->menu_, self->unknown_170_);
        func_ov014_021885bc(self);
        func_0208203c((Struct_02081f20_2*)self->unknown_14c_);
        self->cursor_ = NULL;
        self->unknown_17b_++;
        self->unknown_48_ = NULL;
        self->unknown_4c_ = NULL;
        Struct_ov014_02184f78* entry = func_ov014_021873a0(self);
        func_ov014_02184f78(self, entry, inline_ov014_02188010(self, entry), true);
        self->unknown_82_3_ = true;
    }
    else if (self->unknown_17b_ == 1)
    {
        self->cursor_ = &self->unknown_176_;
        if (func_ov014_02187074(self))
        {
            if (self->unknown_178_ < 0)
            {
                Struct_ov014_02184f78* entry = func_ov014_021873a0(self);
                if (entry->unknown_13_1_)
                    inline_ov014_02188010_2(self, entry, inline_ov014_02188010(self, entry));
                self->unknown_178_ = *self->cursor_;
            }
            return;
        }
        if (self->unknown_160_ != 0 || self->unknown_178_ != *self->cursor_)
        {
            if (self->unknown_160_ & 0x10)
                func_ov014_021872dc(self, 1);
            else if (self->unknown_160_ & 0x20)
                func_ov014_021872dc(self, -1);
            func_ov014_021885bc(self);
            Struct_ov014_02184f78* entry = func_ov014_021873a0(self);
            inline_ov014_02188010_2(self, entry, inline_ov014_02188010(self, entry));
        }
        if (func_ov014_02186f10(self))
        {
            if (self->unknown_17e_ & 0x40)
            {
                Struct_ov014_02184f78* entry = func_ov014_021873a0(self);
                inline_ov014_02188010_2(self, entry, inline_ov014_02188010(self, entry));
            }
            else
                func_ov014_02184e3c((unsigned char*)self);
        }
        else if (g_keyManager.TestKeysPressed(0x800))
            func_ov014_02184dcc(self);
        else if (func_ov014_02186ff0((char*)self))
        {
            self->flags_ &= ~4;
            if (self->unknown_17d_ >= 0)
                self->unknown_17a_ = 3;
            if (self->unknown_17d_ < 0)
                self->unknown_17a_ = 2;
            self->unknown_48_ = NULL;
            self->unknown_4c_ = NULL;
            self->unknown_17e_ |= 0x10;
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, self->unknown_170_);
            self->unknown_17b_ = 0;
            self->cursor_ = NULL;
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, 4);
            func_0207fdcc((Struct_0207fdcc_2*)self->menu_, 3);
            func_ov014_02184d08(self);
        }
    }
}
