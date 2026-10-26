#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* func_02057924(void);
extern "C" void __clear(void* buf, int n);

struct Struct020372b8;

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short f12;
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20; int f24; int f28; int unknown_2c_; int unknown_30_;
    int f34; int unknown_38_; int f3c; int f40;
    int unknown_44_; int unknown_48_; int unknown_4c_;
};
extern "C" void func_02078484(struct Struct_02078398_2* p);

struct Vector3i;

extern "C" void func_02057fb4(void* list, int id, void* config);

extern "C" int LinkSession_IsActive(int* obj);

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct U16Field0x6_020375f8;

struct Struct_0207853c { int a; int b; int c; };
extern "C" void func_ov017_021c95ec(int c1, int rem, int arg2, int tag, int arg4, struct Struct_0207853c v, int a8, int a9, int arg8);

struct Struct_0207853c_2 {
    char pad0[0x2];
    short f2;
    short f4;
    unsigned short unknown_6_;
    char pad1[0x3c];
    int unknown_44_; int unknown_48_; int unknown_4c_;
    char pad2[0x62];
    short unknown_b2_;
    char pad3[0xc4];
    short unknown_178_;
};

// USA: func_0207853c
extern "C" ARM int func_0207853c(struct Struct_0207853c_2* obj) {
    void* g = LinkSession_GetInstance();
    obj->unknown_b2_ = 0;
    ((Object3D*)((struct Struct020372b8*)obj))->TransitionInheritedAlpha(0, 0x7d);

    if (obj->unknown_178_ > 0) {
        void* list = func_02057924();
        struct Struct_02078398_2 s;
        func_02078484(&s);
        *(Vector3i*)&s.unknown_2c_ = *(Vector3i const*)&obj->unknown_44_;
        const Vector3fix& tmp = ((Object3D*)obj)->GetScale();
        *(Vector3i*)&s.unknown_44_ = *(Vector3i const*)((int*)&tmp);
        func_02057fb4(list, obj->unknown_178_, &s);
    }

    if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
        int c1 = ((Object3D*)((struct U16Field0x6_020375f8*)obj))->GetField06();
        int var5 = obj->f2;
        int rem = (obj->f4 - 0x70) % 0xc;
        if (rem >= 0 && rem < 0xc) {
            struct Struct_0207853c v;
            __clear(&v, 0xc);
            func_ov017_021c95ec(c1, rem, var5, 0xb, -1, v, 0, 0, 0);
        }
    }

    return 1;
}
