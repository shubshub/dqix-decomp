#if defined(jpn)
enum { Enum_ov017_021b88d0_348 = 0x150 };
#else
enum { Enum_ov017_021b88d0_348 = 0x15c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215fab0;

struct Struct_ov017_021b88d0 {
    GameObject unknown_0_;
    char unknown_13c_[Enum_ov017_021b88d0_348 - 0x13c];
    int unknown_15c_;
    Vector3i unknown_160_;
    Vector3i unknown_16c_;
};

struct Struct_ov017_021b88d0_2 {
    unsigned char unknown_0_[3];
    unsigned char unknown_3_;
};

struct Struct_ov017_021b88d0_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[0x20 - 0x02];
    unsigned char unknown_20_;
    char unknown_21_[0x24 - 0x21];
    unsigned short unknown_24_;
    char unknown_26_[0x4c - 0x26];
    int unknown_4c_;
    char unknown_50_[0x6b0 - 0x50];
    struct Struct_ov000_0215fab0* unknown_6b0_;
    unsigned short unknown_6b4_;
    char unknown_6b6_[0x6c0 - 0x6b6];
    struct Struct_ov017_021b88d0_2 unknown_6c0_;
};

extern "C" void __clear(void* buf, int n);
int GameState_GetProtagonistIndex(GameState* gs);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* gs, int id);
int GetSignedByte0x2d0_020546a8(void* obj);
extern "C" void func_ov000_0215fab0(struct RingBuf0215fab0* ring, unsigned char val);
extern "C" void func_ov017_021b6f9c(struct Battle_021b88d0* self);

// USA: func_ov017_021b88d0
extern "C" ARM void func_ov017_021b88d0(struct Struct_ov017_021b88d0_3* arg0, int arg1, int arg2) {
    if (arg0->unknown_24_ != arg2) {
        return;
    }

    GameState* gs = GameState::GetInstance();
    if (id == GameState_GetProtagonistIndex(gs)) {
        if (self->state == 1) {
            self->field_0x4c = 1;
            self->state = 2;
        }
        return;
    }

    unsigned short var1 = arg0->unknown_6b4_;
    if (var1 != 3 && var1 != 5) {
        int var2[4];
        __clear(var2, sizeof(var2));
        var2[0] = arg1;
        int var3 = 1;
        for (int var4 = 0; var4 < 4; var4++) {
            GameObject* var5 = func_0200ff58(var0, var4);
            if (var5 != 0 && arg1 == func_020546a8(var5)) {
                var2[var3++] = var4;
            }
        }

        for (int var6 = 0; var6 < var3; var6++) {
            if (arg0->unknown_6b0_ != 0) {
                func_ov000_0215fab0(arg0->unknown_6b0_, var2[var6]);
            } else {
                arg0->unknown_6c0_.unknown_0_[arg0->unknown_6c0_.unknown_3_++] = var2[var6];
            }
            struct Struct_ov017_021b88d0* var7 =
                (struct Struct_ov017_021b88d0*)func_0200ff1c(var0, var2[var6]);
            if (var7 != 0) {
                var7->unknown_160_ = var7->unknown_0_.obj3D_.position_;
                var7->unknown_16c_ = var7->unknown_0_.obj3D_.rotation_;
                var7->unknown_15c_ = var7->unknown_0_.obj3D_.GetField06();
            }
        }
    } else if (arg0->unknown_20_ == 0) {
        func_ov017_021b6f9c(arg0);
        arg0->unknown_1_ = 1;
    }
}
