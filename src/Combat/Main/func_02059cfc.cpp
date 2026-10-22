#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov009_0218aa28 { int unknown_0_; int unknown_4_; int unknown_8_; };

struct Struct_ov001_021592bc { int unknown_0_; int unknown_4_; int unknown_8_; };
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Struct_02059cfc_2;
struct Struct_02059cfc_3;
extern "C" void func_02059f38(struct Struct_02059cfc_2* arg0, struct Struct_02059cfc_3* arg1);

struct Struct_02059cfc_4;

extern "C" void func_02059cc8(unsigned char* arg0);
extern "C" void func_0200fd48(GameState* arg0, int arg1);

struct Struct_02057334_2;
extern "C" int func_02057854(struct Struct_02057334_2* arg0);

extern "C" int func_02055774(int* arg0);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

struct Struct_0200ffc0;
extern "C" unsigned char* func_0200ffc0(Struct_0200ffc0*);
struct Struct_0200ffd0;
extern "C" unsigned char* func_0200ffd0(Struct_0200ffd0*);

extern int g_sePlayer;

struct Struct_02059cfc_5 {
    unsigned char unknown_0_0_:1;
    unsigned char unknown_0_1_:1;
    unsigned char unknown_0_2_:1;
    unsigned char unknown_0_3_:1;
    unsigned char unknown_0_4_:1;
    unsigned char unknown_0_5_:1;
    unsigned char unknown_0_6_:1;
    unsigned char unknown_0_7_:1;
};

struct Struct_02059cfc {
    char unknown_0_[0x4];
    struct Struct_02057334_2* unknown_4_;
    char unknown_8_[0x11];
    unsigned char unknown_19_;
    char unknown_1a_[0xa];
    int unknown_24_;
    int unknown_28_;
    char unknown_2c_[0x18];
    struct Struct_ov009_0218aa28 unknown_44_;
    char unknown_50_[0x5c];
    int unknown_ac_;
    short unknown_b0_;
    char unknown_b2_[0x4];
    short unknown_b6_;
    int unknown_b8_;
    int unknown_bc_;
    struct Struct_ov009_0218aa28 unknown_c0_;
    struct Struct_02059cfc_5 unknown_cc_;
};

// USA: func_02059cfc
extern "C" ARM void func_02059cfc(unsigned char* arg0, int arg1, int arg2) {
    struct Struct_02059cfc* var0 = (struct Struct_02059cfc*)arg0;
    GameState* var1 = GameState::GetInstance();

    if (var0->unknown_b0_ > 0) {
        var0->unknown_b0_ -= arg1;
        return;
    }

    if (var0->unknown_ac_ == 0) {
        if (var1->GetGameObjectByIndex(arg2) == 0) {
            return;
        }

        if (c->field_b8 > 0) {
            int f28 = c->field28;
            int fbc = c->field_bc;
            if (f28 <= fbc) {
                int f24 = c->field24;
                if (fbc < f24) {
                    SePlayer_Play((struct SePlayer*)&g_sePlayer, c->field_b8, 0);
                }
            }
        }

        struct Struct_ov009_0218aa28 var5 = var0->unknown_44_;

        int var6 = 0;
        if (var0->unknown_cc_.unknown_0_4_) {
            unsigned char* var7 = func_0200ffc0((Struct_0200ffc0*)var1);
            if (var7 != 0) {
                var6 = *(int*)(var7 + 0x130);
            }
        } else if (var0->unknown_cc_.unknown_0_5_) {
            unsigned char* var8 = func_0200ffd0((Struct_0200ffd0*)var1);
            if (var8 != 0) {
                var6 = *(int*)(var8 + 0x130);
            }
        }

        if (var0->unknown_cc_.unknown_0_4_ || var0->unknown_cc_.unknown_0_5_) {
            if ((var6 & 1) && var5.unknown_0_ > 0) {
                var5.unknown_0_ -= 0x120000;
            } else if ((var6 & 2) && var5.unknown_0_ < 0) {
                var5.unknown_0_ += 0x120000;
            }
            if ((var6 & 4) && var5.unknown_8_ > 0) {
                var5.unknown_8_ -= 0xe0000;
            } else if ((var6 & 8) && var5.unknown_8_ < 0) {
                var5.unknown_8_ += 0xe0000;
            }
        }

        struct Struct_ov009_0218aa28 var9;
        Vector3fixMultiplyScalar((Vector3i const*)&var0->unknown_c0_, arg1 << 12, (Vector3i*)&var9);
        Vector3fix_Add((const Vector3fix*)&var5, (const Vector3fix*)&var9, (Vector3fix*)&var5);
        func_02059f38((struct Struct_02059cfc_2*)var0, (struct Struct_02059cfc_3*)&var5);

        ((Object3D*)var0)->AdvanceEffects();

        if (var0->unknown_19_ & 1) {
            if (((Object3D*)((struct Struct_02059cfc_4*)var0))->HasAnimationStopped()) {
                func_0200fd48(var1, arg2);
                func_02059cc8(arg0);
            }
        }

        if (var0->unknown_b6_ > 0) {
            var0->unknown_b6_ -= arg1;
            if (var0->unknown_b6_ <= 0) {
                func_0200fd48(var1, arg2);
                func_02059cc8(arg0);
            }
        }
    } else {
        if (var1->GetGameObjectByIndex(arg2) == 0) {
            return;
        }
        if (func_02057854(var0->unknown_4_) == 1) {
            func_0200fd48(var1, arg2);
            func_02059cc8(arg0);
        } else {
            func_02055774((int*)arg0);
        }
    }
}
