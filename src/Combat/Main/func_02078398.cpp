#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void FieldMonsterState_Init(unsigned char* p);

struct BitFlag02033f44 {
    char pad[0xe0];
    unsigned char unknown_e0_0_ : 6;
    unsigned char unknown_e0_6_ : 1;
    unsigned char unknown_e0_7_ : 1;
    char pad2[3];
    int unknown_e4_;
};
extern "C" int* GameObject_GetWallHit(struct BitFlag02033f44* p);

extern "C" void* func_02057924(void);

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
    int f20; int f24; int f28; Vector3i unknown_2c_;
    int unknown_38_; int f3c; int f40;
    Vector3i unknown_44_;
};
extern "C" void func_02078484(struct Struct_02078398_2* p);

extern "C" void func_02057fb4(void* list, int id, void* config);

struct Struct_02078398 : Object3D {
    char unknown_ac_[0x6];
    unsigned short unknown_b2_;
    char unknown_b4_[0xa4];
    Vector3fix unknown_158_;
    char unknown_164_[0x14];
    short unknown_178_;
};

// USA: func_02078398
extern "C" ARM void func_02078398(struct Struct_02078398* obj) {
    if (obj->GetInheritedAlpha() == 0) {
        FieldMonsterState_Init((unsigned char*)obj);
        obj->MakeHidden();
        return;
    }

    if (obj->GetInheritedAlpha() == 0x1f) {
        int* fp = GameObject_GetWallHit((struct BitFlag02033f44*)obj);
        Vector3fix v = obj->position_;
        v.y = 0;
        if (Vector3fix_Distance(&v, &obj->unknown_158_) < 0x2000 || fp != 0) {
            obj->unknown_b2_ = 0;
            obj->TransitionInheritedAlpha(0, 0x7d);
            if (obj->unknown_178_ > 0) {
                void* list = func_02057924();
                struct Struct_02078398_2 s;
                func_02078484(&s);
                s.unknown_2c_ = obj->position_;
                s.unknown_44_ = obj->GetScale();
                func_02057fb4(list, (int)obj->unknown_178_, &s);
            }
        }
    }
}
