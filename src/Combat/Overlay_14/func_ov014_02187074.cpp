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
    const char* unknown_8_;
    short unknown_c_;
    char unknown_e_[4];
    signed char unknown_12_;
    unsigned char unknown_13_0_ : 1;
    unsigned char unknown_13_1_ : 1;
    unsigned char unknown_13_2_ : 6;
    char unknown_14_[6];
    short unknown_1a_;
    char unknown_1c_[4];
};

struct Struct_ov006_02158478 {
    Struct_ov006_02158478* unknown_0_;
    void* unknown_4_;
    char unknown_8_[0xa0];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[0x30];
};

struct Struct_020974b0 {
    char unknown_0_[0x10];
};

struct Struct_ov014_02186bc8 {
    char unknown_0_[0xa4];
    Struct_020974b0 unknown_a4_;
    void* unknown_b4_;
    Struct_ov014_02184f78* unknown_b8_;
    Struct_ov014_02184f78* unknown_bc_;
    void* unknown_c0_;
    void* unknown_c4_;
    Struct_ov006_02158478* unknown_c8_;
    void* unknown_cc_;
    short* unknown_d0_;
    void* unknown_d4_;
    void* unknown_d8_;
    void* unknown_dc_;
    char unknown_e0_[0x18];
    char unknown_f8_[0x54];
    char unknown_14c_[0xc];
    unsigned short unknown_158_;
    unsigned char unknown_15a_;
    char unknown_15b_;
    int unknown_15c_;
    int unknown_160_;
    int unknown_164_;
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

struct Obj2081;
struct SePlayer;

Canvas* FindElementByByte0xc4_02081da8(Obj2081*, int);
bool CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char*);
void SePlayer_Play(SePlayer*, int, int);
void ClearSublistEntriesFlag4_020804fc(void*, int);

extern "C" {
Struct_ov014_02184f78* func_ov014_021873a0(Struct_ov014_02186bc8* arg0);
Struct_ov014_02184f78* func_020974b0(Struct_020974b0* arg0, int arg1, int, bool arg3, int, short* arg5);
void func_ov014_02187228(Struct_ov014_02186bc8* arg0, Struct_ov014_02184f78* arg1);
void func_ov014_0218854c(Struct_ov014_02186bc8* arg0);
void func_ov014_021885bc(Struct_ov014_02186bc8* arg0);
}

extern char g_sePlayer[];

inline short inline_ov014_02187074(short arg0)
{
    return arg0 * 8;
}

// USA: func_ov014_02187074
extern "C" ARM bool func_ov014_02187074(Struct_ov014_02186bc8* arg0)
{
    bool var0 = false;
    Struct_ov006_02158478* var1 = func_02081da8((Struct_0207fdcc_2*)arg0->unknown_c0_, 4);
    if (var1 != NULL && func_0204c7e0((unsigned char*)var1))
    {
        short var2 = var1->unknown_ae_;
        short var3 = var1->unknown_aa_;
        var2--;
        var3++;
        short var4 = inline_ov014_02187074(var1->unknown_ac_);
        short var5 = inline_ov014_02187074(var2);
        short var6 = var4 + inline_ov014_02187074(var1->unknown_a8_);
        short var7 = var5 + inline_ov014_02187074(var3);
        if (g_touchInput.pressed_)
        {
            int var8;
            int var9;
            g_touchInput.GetTouchPoint(&var8, &var9);
            if (var4 <= var8 && var8 < var6 && var5 <= var9 && var9 < var7)
                var0 = true;
        }
    }
    if (g_keyManager.TestKeysPressed(4))
        var0 = true;
    if (var0)
    {
        Struct_ov014_02184f78* var10 = func_ov014_021873a0(arg0);
        if (var10 == NULL)
            return false;
        if (!var10->unknown_13_1_)
        {
            arg0->unknown_176_ = -1;
            arg0->unknown_178_ = -1;
            var10 = NULL;
        }
        if (arg0->unknown_17e_ & 8)
            arg0->unknown_17e_ &= ~8;
        else
            self->listFlags_ |= 8;
        short count = 0;
        self->entries_ = func_020974b0(&self->list_, self->family_, -1, (self->listFlags_ & 8) != 0, 0x10, &count);
        func_ov014_02187228(self, entry);
        SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
        ClearSublistEntriesFlag4_020804fc(self->menu_, 5);
        func_ov014_0218854c(self);
        func_ov014_021885bc(self);
    }
    return var0;
}
