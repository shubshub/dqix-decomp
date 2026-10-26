#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void func_020489e8(void* obj);
struct Bytes02033b88;
void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void* func_02057924(void);
extern "C" void func_02057fb4(void*, int, void*);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern unsigned char g_sePlayer;

struct Struct_02048690 {
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
    int unknown_20_; int unknown_24_; int unknown_28_; int unknown_2c_; int unknown_30_;
    int unknown_34_; int unknown_38_; int unknown_3c_; int unknown_40_;
    int unknown_44_; int unknown_48_; int unknown_4c_;
};

struct Struct_02048690_2 {
    char unknown_0_[0xe0];
    unsigned char unknown_e0_0_ : 3;
    unsigned char unknown_e0_3_ : 1;
    char unknown_e1_[0x183 - 0xe1];
    unsigned char unknown_183_;
    char unknown_184_[0x18e - 0x184];
};

// USA: func_02048690
extern "C" ARM void func_02048690(void* arg0) {
    struct Struct_02048690_2* var0 = (struct Struct_02048690_2*)arg0;

    func_020489e8(var0);

    if (self->countdown != 0) {
        self->countdown--;
        if (self->countdown == 0) {
            GameObject_ForceMotionState((Bytes02033b88*)self, 5);
        }
    }

    if (var0->unknown_e0_3_ == 0) return;

    void* var1 = func_02057924();
    ((Object3D*)var0)->TransitionInheritedAlpha(0, 0x1f4);

    int var2 = *(short*)((char*)var0 + 0x100 + 0x8e) - 0x1000;
    int var3 = (int)(((long long)var2 * 0x800 + 0x800) >> 12);
    var3 = var3 + 0x1000;
    var3 = (int)(((long long)var3 * 0x10a + 0x800) >> 12);

    struct Struct_02048690 var4;
    var4.unknown_0_ = 0;
    var4.unknown_10_ = 1;
    var4.unknown_12_ = 0;
    var4.unknown_14_ = -1;
    var4.unknown_16_ = -1;
    var4.unknown_18_ = -1;
    var4.unknown_1a_ = -1;
    var4.unknown_1c_ = -0x1000;
    var4.unknown_20_ = 0;
    var4.unknown_24_ = 0;
    var4.unknown_28_ = 0;
    var4.unknown_2c_ = 0;
    var4.unknown_30_ = 0;
    var4.unknown_34_ = 0;
    var4.unknown_38_ = 0;
    var4.unknown_3c_ = 0;
    var4.unknown_40_ = 0;
    var4.unknown_44_ = 0x1000;
    var4.unknown_48_ = 0x1000;
    var4.unknown_4c_ = 0x1000;
    var4.unknown_11_0_ = 0;
    var4.unknown_11_1_ = 0;
    var4.unknown_11_2_ = 1;
    var4.unknown_11_3_ = 0;
    var4.unknown_11_4_ = 0;
    var4.unknown_11_5_ = 0;
    var4.unknown_11_6_ = 0;
    var4.unknown_11_7_ = 0;

    const Vector3fix& var5 =((Object3D*)var0)->MaybeGetShadowSource();
    var4.unknown_2c_ = var5.x;
    var4.unknown_30_ = var5.y;
    var4.unknown_34_ = var5.z;
    var4.unknown_44_ = var3;
    var4.unknown_48_ = var3;
    var4.unknown_4c_ = var3;

    FindNodeAndProcess02057fb4(list, 2, &s);
    SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x32, 0);

    var0->unknown_e0_3_ = 0;
}
