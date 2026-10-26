#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void __clear(void* buf, int n);

extern "C" int LinkSession_IsActive(int* obj);
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct U16Field0x6_020375f8;

struct Object3D;
extern "C" int func_02079238(Object3D* obj, int arg);
extern "C" short func_020793c0(Object3D* obj, int arg1);
extern "C" int func_02076ccc(void* obj, int mode);

struct Struct_020790ac { int a; int b; int c; };
extern "C" void func_ov017_021c95ec(int c1, int rem, int arg2, int tag, int phase,
                                    struct Struct_020790ac v, int a8, int a9, int arg8);

struct Struct_020790ac_2 {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0x130 - 6];
    int f130;
    char unknown_134_[0x13a - 0x134];
    unsigned char unknown_13a_;
    char unknown_13b_[0x154 - 0x13b];
    unsigned int f154;
    char unknown_158_[0x166 - 0x158];
    short f166;
    char unknown_168_[0x17b - 0x168];
    unsigned char unknown_17b_;
};

// USA: func_020790ac
extern "C" ARM void func_020790ac(struct Struct_020790ac_2* obj) {
    if (obj->f130 != 1 && obj->f130 != 2) return;

    void* g = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) != 0) {
        return;
    }
    if (obj->f154 < 0x7d0) return;
    if (obj->unknown_17b_ != 0) return;

    int phase = -1;
    switch (obj->unknown_13a_) {
    case 1: phase = func_02079238((Object3D*)obj, 0x3800); break;
    case 2: phase = func_02079238((Object3D*)obj, 0x7800); break;
    case 3: phase = func_020793c0((Object3D*)obj, 0x3800); break;
    case 4: phase = func_020793c0((Object3D*)obj, 0x7800); break;
    default: break;
    }
    if (phase == -1) return;

    obj->f166 = phase;
    func_02076ccc(obj, 0xa);

    void* g2 = LinkSession_GetInstance();
    if (!LinkSession_IsActive((int*)g2) || LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g2) != 0) {
        return;
    }

    int id = ((Object3D*)((struct U16Field0x6_020375f8*)obj))->GetField06();
    int var4 = obj->f2;
    int rem = (obj->f4 - 0x70) % 0xc;
    if (rem >= 0 && rem < 0xc) {
        struct Struct_020790ac v;
        __clear(&v, 0xc);
        func_ov017_021c95ec(id, rem, var4, 0xa, phase, v, 0, 0, 0);
    }
}
