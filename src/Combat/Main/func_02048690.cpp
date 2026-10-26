#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void func_020489e8(void* obj);
struct Bytes02033b88;
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void* func_02057924(void);
extern "C" void func_02057fb4(void*, int, void*);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern unsigned char g_sePlayer;

struct Struct_02048690 {
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

struct Struct_02048690_2 {
    char pad0[0xe0];
    unsigned char unknown_e0_0_ : 3;
    unsigned char unknown_e0_3_ : 1;
    char pad1[0x183 - 0xe1];
    unsigned char countdown;
    char pad2[0x18e - 0x184];
};

// USA: func_02048690
extern "C" ARM void func_02048690(void* arg0) {
    struct Struct_02048690_2* self = (struct Struct_02048690_2*)arg0;

    func_020489e8(self);

    if (self->countdown != 0) {
        self->countdown--;
        if (self->countdown == 0) {
            GameObject_ForceMotionState((Bytes02033b88*)self, 5);
        }
    }

    if (self->unknown_e0_3_ == 0) return;

    void* list = func_02057924();
    ((Object3D*)self)->TransitionInheritedAlpha(0, 0x1f4);

    int d = *(short*)((char*)self + 0x100 + 0x8e) - 0x1000;
    int f = (int)(((long long)d * 0x800 + 0x800) >> 12);
    f = f + 0x1000;
    f = (int)(((long long)f * 0x10a + 0x800) >> 12);

    struct Struct_02048690 s;
    s.unknown_0_ = 0;
    s.f10 = 1;
    s.f12 = 0;
    s.f14 = -1;
    s.unknown_16_ = -1;
    s.f18 = -1;
    s.unknown_1a_ = -1;
    s.f1c = -0x1000;
    s.f20 = 0;
    s.f24 = 0;
    s.f28 = 0;
    s.unknown_2c_ = 0;
    s.unknown_30_ = 0;
    s.f34 = 0;
    s.unknown_38_ = 0;
    s.f3c = 0;
    s.f40 = 0;
    s.unknown_44_ = 0x1000;
    s.unknown_48_ = 0x1000;
    s.unknown_4c_ = 0x1000;
    s.b0 = 0;
    s.b1 = 0;
    s.b2 = 1;
    s.b3 = 0;
    s.unknown_11_4_ = 0;
    s.unknown_11_5_ = 0;
    s.unknown_11_6_ = 0;
    s.unknown_11_7_ = 0;

    const Vector3fix& p =((Object3D*)self)->MaybeGetShadowSource();
    s.unknown_2c_ = p.x;
    s.unknown_30_ = p.y;
    s.f34 = p.z;
    s.unknown_44_ = f;
    s.unknown_48_ = f;
    s.unknown_4c_ = f;

    func_02057fb4(list, 2, &s);
    SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x32, 0);

    self->unknown_e0_3_ = 0;
}
