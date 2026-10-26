#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void FieldMonsterState_Init(unsigned char* p);

struct Struct_02033f44 {
    char unknown_0_[0xe0];
    unsigned char unknown_e0_0_ : 6;
    unsigned char unknown_e0_6_ : 1;
    unsigned char unknown_e0_7_ : 1;
    char unknown_e1_[3];
    int unknown_e4_;
};
int* GameObject_GetWallHit(struct BitFlag02033f44* p);

extern "C" void* func_02057924(void);

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_0_ : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char unknown_11_2_ : 1;
    unsigned char unknown_11_3_ : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_; int unknown_24_; int unknown_28_; Vector3i unknown_2c_;
    int unknown_38_; int unknown_3c_; int unknown_40_;
    Vector3i unknown_44_;
};
extern "C" void func_02078484(struct Struct_02078398_2* arg0);

extern "C" void func_02057fb4(void* arg0, int arg1, void* arg2);

struct Struct_02078398 : Object3D {
    char unknown_ac_[0x6];
    unsigned short unknown_b2_;
    char unknown_b4_[0xa4];
    Vector3fix unknown_158_;
    char unknown_164_[0x14];
    short unknown_178_;
};

// USA: func_02078398
extern "C" ARM void func_02078398(struct Actor02078398* obj) {
    if (obj->GetInheritedAlpha() == 0) {
        FieldMonsterState_Init((unsigned char*)obj);
        obj->MakeHidden();
        return;
    }

    if (obj->GetInheritedAlpha() == 0x1f) {
        int* fp = GameObject_GetWallHit((struct BitFlag02033f44*)obj);
        Vector3fix v = obj->position_;
        v.y = 0;
        if (Vector3fix_Distance(&v, &obj->f158) < 0x2000 || fp != 0) {
            obj->fb2 = 0;
            obj->TransitionInheritedAlpha(0, 0x7d);
            if (obj->f178 > 0) {
                void* list = func_02057924();
                struct InitStruct02078484Struct s;
                InitStruct02078484(&s);
                s.f2c = obj->position_;
                s.f44 = obj->GetScale();
                FindNodeAndProcess02057fb4(list, (int)obj->f178, &s);
            }
        }
    }
}
