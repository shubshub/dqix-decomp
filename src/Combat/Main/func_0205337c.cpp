#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

void* GlobalFlags_GetInstance(void);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);

struct Vec3copy0202ec84 { int x; int y; int z; };
ARM int Camera_WorldToScreen(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct Struct_02015ef4_2;
extern "C" ARM void func_020473c8(struct Struct_02015ef4_2* arg0, int arg1);

struct Struct_0205337c {
    unsigned char unknown_0_[0x1c];
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
};

struct Struct_02000c9c_22 {
    signed char unknown_0_[5];
    signed char unknown_5_;
    signed char* inline_0205337c() { return unknown_0_; }
    int inline_0205337c_2() const { return unknown_5_; }
};

#if defined(jpn)
enum { Enum_0205337c_376 = 0x16c, Enum_0205337c_400 = 0x184 };
#else
enum { Enum_0205337c_376 = 0x178, Enum_0205337c_400 = 0x190 };
#endif

struct Struct_0205337c_2 {
    unsigned char unknown_0_[0x44];
    struct Struct_02015ef4 unknown_44_;
    unsigned char unknown_50_[Enum_0205337c_376 - 0x50];
    struct Struct_02000c9c_22 unknown_178_;
    unsigned char unknown_17e_[Enum_0205337c_400 - Enum_0205337c_376 - 6];
    struct Struct_0205337c* unknown_190_;
};

// USA: func_0205337c
extern "C" ARM void func_0205337c(struct Obj0205337c* obj) {
    if (TestFlags02046708((struct FlagWord02046708*)GlobalFlags_GetInstance(), 2)) return;
    if (obj->node == NULL) return;

    void* target = GameState::GetInstance()->GetCamera();
    *(volatile int*)0x4000444 = 0;

    struct Struct_02015ef4 var1 = arg0->unknown_44_;
    var1.unknown_4_ += 0x1b33;

    int outB, outA;
    Camera_WorldToScreen(target, &pose, &outB, &outA);
    outB -= 0xc;
    outA -= 0xc;

    int var4 = arg0->unknown_178_.inline_0205337c_2();
    signed char* var5 = arg0->unknown_178_.inline_0205337c();
    int var6 = var5[var4];
    if (!(var6 != 0xc && var6 != 0xd && var6 != 0xe)) {
        var2 -= 0xc;
        var3 -= 6;
    } else if (var6 == 0x1e) {
        var3 += 4;
        var2 += 4;
    }

    int var7 = var2;
    int var8 = var3;
    struct Struct_0205337c* var9 = arg0->unknown_190_;
    var9->unknown_1c_ = var7 << 12;
    var9->unknown_20_ = var8 << 12;
    var9->unknown_24_ = -0xa000;

    func_020473c8((struct Struct_02015ef4_2*)arg0->unknown_190_, 1);
    *(volatile int*)0x4000448 = 1;
}
