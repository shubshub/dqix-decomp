#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* Zone3D_GetInstance(void);

struct Struct_0203de84 {
    unsigned int v[3];
};
struct Node020406f8;
struct Struct_0203de84_3;
struct Struct_0203de84_4;

extern "C" void func_020406f8(struct Struct_0203de84* dst, struct Node020406f8* n);
extern "C" int func_02040adc(struct Struct_0203de84_3* obj);
extern "C" int func_02040910(struct Struct_0203de84_4* obj, int arg1);
extern "C" void func_0208f87c(const void* self, int b, int c, int d, int polygonId);

struct Ctx02012fe4 {
#if defined(jpn)
    char pad[0x58];
#else
    char pad[0x38];
#endif
    unsigned short unknown_38_;
    char unknown_3a_[2];
    int f3c;
};

struct Struct_0203de84_6 {
    unsigned int flags;
    char pad4[0x10];
    void* f14;
    Object3D* f18;
};

struct Struct_0203de84_7 {
    char pad0[0xc];
    struct Struct_0203de84_6* nodes[0x20];
    char pad8c[0x98 - 0x8c];
    struct Struct_0203de84_4* unknown_98_;
};

// USA: func_0203de84
extern "C" ARM void func_0203de84(void* self) {
    struct Struct_0203de84_7* roster = (struct Struct_0203de84_7*)self;
    void* v = GameState::GetInstance()->GetCamera();
    GetGameResources();
    struct Ctx02012fe4* ctx = (struct Ctx02012fe4*)Zone3D_GetInstance();
    unsigned short a = ctx->unknown_38_;
    int b = ctx->f3c;
    struct Struct_0203de84 vec;
    int i;
    for (i = 0; i < 0x20; i++) {
        if (roster->nodes[i] == NULL) continue;
        unsigned int var7 = roster->nodes[i]->flags;
        if (var7 & 0x8000) continue;
        if (roster->unknown_98_ != NULL && !(var7 & 0x10000)) continue;
        if (!func_02040910((struct Struct_0203de84_4*)roster->nodes[i], (int)v))
            continue;
        if (var7 & 0x20) continue;
        if (var7 & 0x40) continue;
        Object3D* e = roster->nodes[i]->f18;
        if (e != NULL && e->GetFlag(0x10) != 0) continue;
        func_020406f8(&vec, (struct Node020406f8*)roster->nodes[i]);
        func_0208f87c(&vec, a, 0x1000, b,
            func_02040adc((struct Struct_0203de84_3*)roster->nodes[i]));
    }
}
