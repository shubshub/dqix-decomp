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
    char unknown_0_[R(0x20, 0x2c)];
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
void func_02081f20(void* arg0, int arg1);
int func_020800fc(Struct_ov000_0217ab8c* arg0, short* arg1, short arg2, unsigned short arg3, unsigned char, bool);
void func_020813ec(Struct_ov000_0217ab8c* arg0, short arg1);
void func_ov014_02184700(Struct_ov014_02186bc8* arg0);
void func_ov014_021886f8(Struct_ov014_02186bc8* arg0);
}

extern unsigned int data_ov014_0218981c;
extern ListStateFunc __ptmf_null;
extern ListStateFunc data_ov014_021896d4[7];
extern ListStateFunc data_ov014_021896d4_dup[7];

// USA: func_ov014_02186bc8
extern "C" ARM bool func_ov014_02186bc8(Struct_ov014_02186bc8* arg0, int arg1)
{
    if (arg1 == 0)
        arg1 = 1;
    arg0->unknown_164_ = arg1;
    if (func_ov017_021959b4())
        func_ov014_02186df0((Struct_ov014_02186bc8_2*)arg0);
    if (arg0->unknown_17a_ != 0)
    {
        func_0207fc6c((Struct_0207fc6c*)arg0->unknown_c0_, arg0->unknown_164_);
        if (arg0->unknown_d0_ != NULL)
        {
            func_02081f20(arg0->unknown_14c_, arg0->unknown_164_);
            arg0->unknown_178_ = *arg0->unknown_d0_;
            bool var0 = false;
            if (arg0->unknown_17a_ == 4)
                var0 = func_ov014_021874f8((Struct_ov014_02186bc8_3*)arg0) > 16;
            arg0->unknown_160_ = func_020800fc(arg0->unknown_c0_, arg0->unknown_d0_, arg0->unknown_178_, arg0->unknown_158_, arg0->unknown_15a_, var0);
            arg0->unknown_c0_->unknown_36_ = *arg0->unknown_d0_;
            if (arg0->unknown_160_ != 0)
                func_020804fc(arg0->unknown_c0_, arg0->unknown_170_);
            if (arg0->unknown_178_ != *arg0->unknown_d0_)
                func_020813ec(arg0->unknown_c0_, arg0->unknown_170_);
        }
    }
    func_ov014_02184700(arg0);
    func_ov014_021886f8(arg0);

    if (!(data_ov014_0218981c & 1))
    {
        data_ov014_021896d4_dup[6] = __ptmf_null;
        data_ov014_0218981c |= 1;
    }
    if (data_ov014_021896d4[arg0->unknown_17a_] == NULL)
        return true;
    (arg0->*data_ov014_021896d4[arg0->unknown_17a_])();
    return false;
}
