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
    char unknown_0_[0x2c];
    void* unknown_2c_;
    char unknown_30_[6];
    short unknown_36_;
    unsigned char unknown_38_;
    char unknown_39_;
    unsigned char unknown_3a_;
    char unknown_3b_[5];
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
    Struct_ov000_0217ab8c* unknown_c0_;
    void* unknown_c4_;
    void* unknown_c8_;
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
struct Obj0208203c;
struct ListHeadStruct021874f8;

short FindMappedMemberId02080468(void* obj, int id);
void ResetWithSub0208203c(Obj0208203c*);
void CallFunc0204c804OnMatchingKey_0207fdcc(Obj2081*, int);
int CheckFlagAndPointInElement_02186ff0(char*);
void SePlayer_Play(SePlayer*, int, int);
short CountLinkedListNodes_021874f8(ListHeadStruct021874f8*);

extern "C" {
Struct_ov014_02184f78* func_020974b0(Struct_020974b0* arg0, int arg1, int, bool arg3, int, short* arg5);
void func_ov014_02188330(Struct_ov014_02186bc8* arg0);
void func_020813ec(Struct_ov000_0217ab8c* arg0, short arg1);
bool func_ov014_02186f10(Struct_ov014_02186bc8* arg0);
}

extern char g_sePlayer[];

// USA: func_ov014_02187db8
extern "C" ARM void func_ov014_02187db8(Struct_ov014_02186bc8* arg0)
{
    if (arg0->unknown_17b_ == 0)
    {
        if (!(arg0->unknown_17e_ & 0x10))
        {
            arg0->unknown_170_ = 2;
            if (arg0->unknown_174_ < 0)
                arg0->unknown_174_ = func_02080468(arg0->unknown_c0_, arg0->unknown_170_);
            func_020813ec(arg0->unknown_c0_, arg0->unknown_170_);
            arg0->unknown_17d_ = arg0->unknown_174_ - 0xb;
            short var0 = 0;
            arg0->unknown_b8_ = func_020974b0(&arg0->unknown_a4_, arg0->unknown_17d_, -1, (arg0->unknown_17e_ & 8) != 0, 0x10, &var0);
            arg0->unknown_bc_ = arg0->unknown_b8_;
            func_ov014_02188330(arg0);
            arg0->unknown_17b_++;
        }
    }
    else if (arg0->unknown_17b_ == 1)
    {
        arg0->unknown_d0_ = &arg0->unknown_174_;
        arg0->unknown_17d_ = arg0->unknown_174_ - 0xb;
        if (arg0->unknown_160_ != 0 || arg0->unknown_178_ != *arg0->unknown_d0_)
        {
            short var1 = 0;
            arg0->unknown_b8_ = func_020974b0(&arg0->unknown_a4_, arg0->unknown_17d_, -1, (arg0->unknown_17e_ & 8) != 0, 0x10, &var1);
            arg0->unknown_bc_ = arg0->unknown_b8_;
            func_ov014_02188330(arg0);
        }
        if (func_ov014_02186f10(arg0))
        {
            SePlayer_Play((SePlayer*)g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            if (CountLinkedListNodes_021874f8((ListHeadStruct021874f8*)self) != 0)
            {
                func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_c0_, arg0->unknown_170_);
                arg0->unknown_d0_ = NULL;
                arg0->unknown_17a_ = 4;
                arg0->unknown_17b_ = 0;
                arg0->unknown_17e_ |= 0x10;
            }
        }
        else if (func_ov014_02186ff0((char*)arg0))
        {
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_c0_, arg0->unknown_170_);
            arg0->unknown_174_ = -1;
            arg0->unknown_17d_ = -1;
            arg0->unknown_17a_ = 2;
            arg0->unknown_17b_ = 0;
        }
        else if (g_keyManager.TestKeysPressed(0x800))
        {
            func_0207fdcc((Struct_0207fdcc_2*)arg0->unknown_c0_, arg0->unknown_170_);
            arg0->unknown_174_ = -1;
            arg0->unknown_17d_ = -1;
            arg0->unknown_17a_ = 5;
            arg0->unknown_17b_ = 0;
        }
    }
}
