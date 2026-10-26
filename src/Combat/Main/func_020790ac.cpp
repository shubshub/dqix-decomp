#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void __clear(void* buf, int n);

int LinkSession_IsActive(int* obj);
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct Struct_02039df4;

struct Object3D;
extern "C" int func_02079238(Object3D* arg0, int arg1);
extern "C" short func_020793c0(Object3D* arg0, int arg1);
extern "C" int func_02076ccc(void* arg0, int arg1);

struct Struct_020790ac { int unknown_0_; int unknown_4_; int unknown_8_; };
extern "C" void func_ov017_021c95ec(int arg0, int arg1, int arg2, int arg3, int arg4,
                                    struct Struct_020790ac arg5, int arg6, int arg7, int arg8);

struct Struct_020790ac_2 {
    char unknown_0_[2];
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0x130 - 6];
    int unknown_130_;
    char unknown_134_[0x13a - 0x134];
    unsigned char unknown_13a_;
    char unknown_13b_[0x154 - 0x13b];
    unsigned int unknown_154_;
    char unknown_158_[0x166 - 0x158];
    short unknown_166_;
    char unknown_168_[0x17b - 0x168];
    unsigned char unknown_17b_;
};

// USA: func_020790ac
extern "C" ARM void func_020790ac(struct Struct_020790ac_2* arg0) {
    if (arg0->unknown_130_ != 1 && arg0->unknown_130_ != 2) return;

    void* g = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) != 0) {
        return;
    }
    if (arg0->unknown_154_ < 0x7d0) return;
    if (arg0->unknown_17b_ != 0) return;

    int var1 = -1;
    switch (arg0->unknown_13a_) {
    case 1: var1 = func_02079238((Object3D*)arg0, 0x3800); break;
    case 2: var1 = func_02079238((Object3D*)arg0, 0x7800); break;
    case 3: var1 = func_020793c0((Object3D*)arg0, 0x3800); break;
    case 4: var1 = func_020793c0((Object3D*)arg0, 0x7800); break;
    default: break;
    }
    if (var1 == -1) return;

    arg0->unknown_166_ = var1;
    func_02076ccc(arg0, 0xa);

    void* g2 = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)g2) || LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g2) != 0) {
        return;
    }

    int var3 = ((Object3D*)((struct Struct_02039df4*)arg0))->GetField06();
    int var4 = arg0->unknown_2_;
    int var5 = (arg0->unknown_4_ - 0x70) % 0xc;
    if (var5 >= 0 && var5 < 0xc) {
        struct Struct_020790ac var6;
        __clear(&var6, 0xc);
        func_ov017_021c95ec(var3, var5, var4, 0xa, var1, var6, 0, 0, 0);
    }
}
