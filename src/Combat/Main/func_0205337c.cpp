#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);

struct Vec3copy0202ec84 { int x; int y; int z; };
extern "C" ARM int Camera_WorldToScreen(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct StructAt020473c8;
extern "C" ARM void func_020473c8(struct StructAt020473c8* obj, int param1);

struct Struct_0205337c {
    unsigned char pad0[0x1c];
    int screenX;
    int screenY;
    int depth;
};

struct Struct_02000c9c_22 {
    signed char anim[5];
    signed char unknown_5_;
    signed char* inline_0205337c() { return anim; }
    int inline_0205337c_2() const { return unknown_5_; }
};

#if defined(jpn)
enum { Enum_0205337c_376 = 0x16c, regionalNode = 0x184 };
#else
enum { Enum_0205337c_376 = 0x178, regionalNode = 0x190 };
#endif

struct Struct_0205337c_2 {
    unsigned char pad0[0x44];
    struct Vec3copy0202ec84 pose;
    unsigned char pad1[Enum_0205337c_376 - 0x50];
    struct Struct_02000c9c_22 anim;
    unsigned char pad2[regionalNode - Enum_0205337c_376 - 6];
    struct Struct_0205337c* node;
};

// USA: func_0205337c
extern "C" ARM void func_0205337c(struct Struct_0205337c_2* obj) {
    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 2)) return;
    if (obj->node == NULL) return;

    void* target = GameState::GetInstance()->GetCamera();
    *(volatile int*)0x4000444 = 0;

    struct Vec3copy0202ec84 pose = obj->pose;
    pose.y += 0x1b33;

    int outB, outA;
    Camera_WorldToScreen(target, &pose, &outB, &outA);
    outB -= 0xc;
    outA -= 0xc;

    int idx = obj->anim.inline_0205337c_2();
    signed char* animations = obj->anim.inline_0205337c();
    int kind = animations[idx];
    if (!(kind != 0xc && kind != 0xd && kind != 0xe)) {
        outB -= 0xc;
        outA -= 6;
    } else if (kind == 0x1e) {
        outA += 4;
        outB += 4;
    }

    int var7 = outB;
    int var8 = outA;
    struct Struct_0205337c* node = obj->node;
    node->screenX = var7 << 12;
    node->screenY = var8 << 12;
    node->depth = -0xa000;

    func_020473c8((struct StructAt020473c8*)obj->node, 1);
    *(volatile int*)0x4000448 = 1;
}
