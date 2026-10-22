#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_02157d7c_16 = 8, Enum_ov006_02157d7c_2786 = 0x962, Enum_ov006_02157d7c_168 = 0xa0, Enum_ov006_02157d7c_54 = 0x2a };
#else
enum { Enum_ov006_02157d7c_16 = 0x10, Enum_ov006_02157d7c_2786 = 0xae2, Enum_ov006_02157d7c_168 = 0xa8, Enum_ov006_02157d7c_54 = 0x36 };
#endif

struct Struct_0207fc6c;
struct Struct_0207fdcc_2;
struct Struct_020e28dc;
struct Struct_020e263c_2;

extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov006_021585ac(void* arg0);
extern "C" int func_0209ca2c(void* arg0);
extern char data_02109bf4[];
extern "C" void func_ov006_021549ac(void* arg0, int arg1);
extern "C" void func_0207fc6c(struct Struct_0207fc6c* arg0, int arg1);
extern "C" void func_ov006_0215a00c(void* arg0, int arg1);
extern "C" int func_ov006_02158c70();
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* arg0, int arg1);
extern "C" unsigned short func_02081f20(void* arg0, int arg1);
extern "C" int func_020800fc(void* arg0, short* arg1, short arg2, unsigned short arg3, unsigned char arg4, int arg5);
extern "C" int func_020804fc(void* arg0, int arg1);
extern "C" int func_020813ec(void* arg0, int arg1);
extern "C" int func_020e28dc(struct Struct_020e28dc* arg0);
extern "C" void func_020e263c(struct Struct_020e263c_2* arg0, int arg1);

typedef int (*Type_ov006_02157d7c)(void* self);

struct Struct_ov006_02157d7c {
    char unknown_0_[Enum_ov006_02157d7c_16];
    void* unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
    char unknown_1c_[0x44 - 0x1c];
    short* unknown_44_;
    char unknown_48_[0x9c - 0x48];
    char unknown_9c_[0xa8 - 0x9c];
    unsigned short unknown_a8_;
    unsigned char unknown_aa_;
    char unknown_ab_[0x300 - Enum_ov006_02157d7c_168 - 3];
    char unknown_300_[0x34c - 0x300];
    int unknown_34c_;
    int unknown_350_;
    char unknown_354_[0x38f - 0x354];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    char unknown_391_[0x42c - 0x391];
    signed char unknown_42c_;
    char unknown_42d_[0x42f - 0x42d];
    unsigned char unknown_42f_;
    char unknown_430_[0x433 - 0x430];
    unsigned char unknown_433_;
};

typedef void (Obj02157d7c::*PMF02157d7c)();
struct HandlerTable02157d7c { PMF02157d7c e[14]; };
extern struct HandlerTable02157d7c data_ov006_021601fc;
extern PMF02157d7c __ptmf_null;
extern int data_ov006_02160398;

// USA: func_ov006_02157d7c
extern "C" ARM int func_ov006_02157d7c(struct Struct_ov006_02157d7c* arg0, int arg1)
{
    arg0->unknown_34c_ = arg1;
    if (func_ov017_021959b4() != 0)
        func_ov006_021585ac(arg0);

    if ((*(unsigned short*)((char*)arg0 + 0x300 + 0x94) & 0x200) == 0)
    {
        if (arg0->unknown_433_ != 0)
        {
            if (arg0->unknown_44_ != 0)
                *arg0->unknown_44_ = -1;
            arg0->unknown_44_ = 0;
            arg0->unknown_38f_ = 0xc;
            arg0->unknown_390_ = 0;
            arg0->unknown_433_ = 0;
        }
    }

    unsigned int var0 = arg0->unknown_38f_;
    if (((var0 <= 4) ? 1 : 0) > var0)
    {
    }
    else
    {
        arg0->unknown_42c_ = (signed char)(((signed char*)((char*)arg0 + 0x400))[0x2c] + arg1);
        arg0->unknown_42c_ = (signed char)(((signed char*)((char*)arg0 + 0x400))[0x2c] & 0x3f);
    }

    if (func_0209ca2c(data_02109bf4) == 0)
        arg0->unknown_42f_ = 0;

    func_ov006_021549ac(arg0->unknown_10_, arg1);

    Struct_0207fc6c* var1 = (Struct_0207fc6c*)arg0->unknown_14_;
    if (var1 != 0)
        func_0207fc6c(var1, arg1);

    if (*(short*)((char*)arg0 + 0x300 + 0x7e) >= 0)
    {
        arg0->unknown_42c_ = 0;
        func_ov006_0215a00c(arg0, 0);
        return 0;
    }

    if (*(unsigned short*)((char*)arg0 + 0x300 + 0x94) & 0x100)
    {
        if (((Type_ov006_02157d7c)func_ov006_02158c70)(arg0) != 0)
        {
            func_0207fdcc((Struct_0207fdcc_2*)var1, 0);
            func_0207fdcc((Struct_0207fdcc_2*)var1, 1);
            *(unsigned short*)((char*)arg0 + 0x300 + 0x94) &= ~0x100;
        }
        return 0;
    }

    if (*(unsigned short*)((char*)arg0->unknown_10_ + Enum_ov006_02157d7c_2786) & 0x380)
    {
        arg0->unknown_42c_ = 0;
        return 0;
    }

    if (arg0->unknown_44_ != 0)
    {
        func_02081f20(arg0->unknown_9c_, arg1);
        *(short*)((char*)arg0 + 0x300 + 0x5e) = *arg0->unknown_44_;
        arg0->unknown_350_ = func_020800fc(var1, arg0->unknown_44_, *(short*)((char*)arg0 + 0x300 + 0x5e),
                                   *(unsigned short*)((char*)arg0 + Enum_ov006_02157d7c_168),
                                   *(unsigned char*)((char*)arg0 + Enum_ov006_02157d7c_168 + 2),
                                   (*(unsigned short*)((char*)arg0 + 0x300 + 0x94) & 4) != 0);
        *(short*)((char*)var1 + Enum_ov006_02157d7c_54) = *arg0->unknown_44_;
        if (arg0->unknown_350_ != 0)
            func_020804fc(var1, *(short*)((char*)arg0 + 0x300 + 0x6e));
        if (*(short*)((char*)arg0 + 0x300 + 0x5e) != *arg0->unknown_44_)
            func_020813ec(var1, *(short*)((char*)arg0 + 0x300 + 0x6e));
    }

    if (arg0->unknown_18_ != 0)
    {
        if (func_020e28dc((struct Struct_020e28dc*)arg0->unknown_18_) != 0)
            func_020e263c((struct Struct_020e263c_2*)arg0->unknown_18_, arg0->unknown_34c_);
    }

    if ((data_ov006_02160398 & 1) == 0)
    {
        data_ov006_021601fc.e[13] = __ptmf_null;
        data_ov006_02160398 |= 1;
    }

    if (data_ov006_021601fc.unknown_0_[arg0->unknown_38f_] == 0)
        return 1;

    (arg0->*data_ov006_021601fc.unknown_0_[arg0->unknown_38f_])();
    return 0;
}
