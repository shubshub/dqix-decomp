#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02033f5c(unsigned char* p);
extern "C" void* func_02033fc4(void* obj);
extern "C" int func_0204be78(unsigned short* obj);
struct BitFlag02033f44;
extern "C" void* GameObject_GetWallHit(BitFlag02033f44*);
extern "C" int func_0204bea0(unsigned short* obj);
extern "C" int func_0204be90(unsigned short* obj);

struct F02033f44 {
    char pad0[0x24];
    Vector3fix f24;
};

struct Struct_020a7d74_2 {
    char pad0[0x50];
    Vector3fix unknown_50_;
    char unknown_5c_[0x134 - 0x5c];
    int unknown_134_;
    int unknown_138_;
};

// USA: func_020a7d74
extern "C" ARM int func_020a7d74(struct Struct_020a7d74_2* self, int* out1, int* out2) {
    GameState* gameState = GameState::GetInstance();
    int ok = 1;
    if (self->unknown_134_ == 0) {
        ok = 0;
    }
    if (func_02033f5c((unsigned char*)self) == 0) {
        ok = 0;
    }
    unsigned short* p = (unsigned short*)func_02033fc4(self);
    if (p == 0) {
        ok = 0;
    }
    if (func_0204be78(p) == 0) {
        ok = 0;
    }
    if (ok == 0) {
        self->unknown_138_ = 0;
        return 0;
    }

    Vector3fix dir;
    Vector3fix t;
    Vector3fix src = self->unknown_50_;
    int angle = src.y;
    int var7 = fix32cos(angle);
    dir.x = fix32sin(angle);
    dir.y = 0;
    dir.z = var7;
    Vector3fix_Normalize(&dir, &dir);

    struct F02033f44* f = (struct F02033f44*)GameObject_GetWallHit((BitFlag02033f44*)self);
    int var9 = f->f24.z;
    int tx = f->f24.x;
    t.y = 0;
    t.x = tx;
    t.z = var9;
    Vector3fix_Normalize(&t, &t);

    int dot = Vector3fix_InnerProduct(&t, &dir);
    if (dot >= -0xc00) {
        self->unknown_138_ = 0;
    } else {
        self->unknown_138_ = self->unknown_138_ + (int)gameState->GetTickCount();
    }
    if (self->unknown_138_ < 0x28) {
        return 0;
    }
    *out1 = func_0204bea0(p);
    *out2 = func_0204be90(p);
    return 1;
}
