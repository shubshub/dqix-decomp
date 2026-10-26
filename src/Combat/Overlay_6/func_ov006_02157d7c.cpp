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
extern "C" void func_ov006_021585ac(void* p);
extern "C" int func_0209ca2c(void* obj);
extern char g_bgmPlayer[];
extern "C" void func_ov006_021549ac(void* arg0, int ticks);
extern "C" void func_0207fc6c(struct Struct_0207fc6c* obj, int arg);
extern "C" void func_ov006_0215a00c(void* self, int n);
extern "C" int func_ov006_02158c70();
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* obj, int key);
extern "C" unsigned short func_02081f20(void* obj, int ticks);
extern "C" int func_020800fc(void* obj, short* key, short a, unsigned short b, unsigned char c, int d);
extern "C" int func_020804fc(void* obj, int id);
extern "C" int func_020813ec(void* obj, int id);
extern "C" int func_020e28dc(struct Struct_020e28dc* o);
extern "C" void func_020e263c(struct Struct_020e263c_2* c, int key);

typedef int (*Type_ov006_02157d7c)(void* self);

struct Struct_ov006_02157d7c {
    char pad0[Enum_ov006_02157d7c_16];
    void* pot_;
    void* menu_;
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

typedef void (Struct_ov006_02157d7c::*Type_02015554)();
struct Struct_ov006_021601fc { Type_02015554 e[14]; };
extern struct Struct_ov006_021601fc data_ov006_021601fc;
extern Type_02015554 __ptmf_null;
extern int data_ov006_02160398;

// USA: func_ov006_02157d7c
extern "C" ARM int func_ov006_02157d7c(struct Struct_ov006_02157d7c* self, int arg)
{
    self->unknown_34c_ = arg;
    if (func_ov017_021959b4() != 0)
        func_ov006_021585ac(self);

    if ((*(unsigned short*)((char*)self + 0x300 + 0x94) & 0x200) == 0)
    {
        if (self->unknown_433_ != 0)
        {
            if (self->unknown_44_ != 0)
                *self->unknown_44_ = -1;
            self->unknown_44_ = 0;
            self->unknown_38f_ = 0xc;
            self->unknown_390_ = 0;
            self->unknown_433_ = 0;
        }
    }

    unsigned int s = self->unknown_38f_;
    if (((s <= 4) ? 1 : 0) > s)
    {
    }
    else
    {
        self->unknown_42c_ = (signed char)(((signed char*)((char*)self + 0x400))[0x2c] + arg);
        self->unknown_42c_ = (signed char)(((signed char*)((char*)self + 0x400))[0x2c] & 0x3f);
    }

    if (func_0209ca2c(g_bgmPlayer) == 0)
        self->unknown_42f_ = 0;

    func_ov006_021549ac(self->pot_, arg);

    Struct_0207fc6c* menu = (Struct_0207fc6c*)self->menu_;
    if (menu != 0)
        func_0207fc6c(menu, arg);

    if (*(short*)((char*)self + 0x300 + 0x7e) >= 0)
    {
        self->unknown_42c_ = 0;
        func_ov006_0215a00c(self, 0);
        return 0;
    }

    if (*(unsigned short*)((char*)self + 0x300 + 0x94) & 0x100)
    {
        if (((Type_ov006_02157d7c)func_ov006_02158c70)(self) != 0)
        {
            func_0207fdcc((Struct_0207fdcc_2*)menu, 0);
            func_0207fdcc((Struct_0207fdcc_2*)menu, 1);
            *(unsigned short*)((char*)self + 0x300 + 0x94) &= ~0x100;
        }
        return 0;
    }

    if (*(unsigned short*)((char*)self->pot_ + Enum_ov006_02157d7c_2786) & 0x380)
    {
        self->unknown_42c_ = 0;
        return 0;
    }

    if (self->unknown_44_ != 0)
    {
        func_02081f20(self->unknown_9c_, arg);
        *(short*)((char*)self + 0x300 + 0x5e) = *self->unknown_44_;
        self->unknown_350_ = func_020800fc(menu, self->unknown_44_, *(short*)((char*)self + 0x300 + 0x5e),
                                   *(unsigned short*)((char*)self + Enum_ov006_02157d7c_168),
                                   *(unsigned char*)((char*)self + Enum_ov006_02157d7c_168 + 2),
                                   (*(unsigned short*)((char*)self + 0x300 + 0x94) & 4) != 0);
        *(short*)((char*)menu + Enum_ov006_02157d7c_54) = *self->unknown_44_;
        if (self->unknown_350_ != 0)
            func_020804fc(menu, *(short*)((char*)self + 0x300 + 0x6e));
        if (*(short*)((char*)self + 0x300 + 0x5e) != *self->unknown_44_)
            func_020813ec(menu, *(short*)((char*)self + 0x300 + 0x6e));
    }

    if (self->unknown_18_ != 0)
    {
        if (func_020e28dc((struct Struct_020e28dc*)self->unknown_18_) != 0)
            func_020e263c((struct Struct_020e263c_2*)self->unknown_18_, self->unknown_34c_);
    }

    if ((data_ov006_02160398 & 1) == 0)
    {
        data_ov006_021601fc.e[13] = __ptmf_null;
        data_ov006_02160398 |= 1;
    }

    if (data_ov006_021601fc.e[self->unknown_38f_] == 0)
        return 1;

    (self->*data_ov006_021601fc.e[self->unknown_38f_])();
    return 0;
}
