#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

struct Struct_ov001_021592bc { int x; int y; int z; };
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Struct_02059cfc_2;
struct Struct_02059cfc_3;
extern "C" void func_02059f38(struct Struct_02059cfc_2* dst, struct Struct_02059cfc_3* src);

struct Struct_02059cfc_4;

extern "C" void func_02059cc8(unsigned char* obj);
extern "C" void func_0200fd48(GameState* battleStruct, int id);

struct Struct_02057334_2;
extern "C" int func_02057854(struct Struct_02057334_2* node);

extern "C" int func_02055774(int* obj);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

struct PointerField32c_ffc0;
extern "C" unsigned char* GameState_GetShip(PointerField32c_ffc0*);
struct PointerField330_ffd0;
extern "C" unsigned char* GameState_GetStarflight(PointerField330_ffd0*);

extern int g_sePlayer;

struct Struct_02059cfc_5 {
    unsigned char bit0:1;
    unsigned char unknown_0_1_:1;
    unsigned char bit2:1;
    unsigned char unknown_0_3_:1;
    unsigned char unknown_0_4_:1;
    unsigned char unknown_0_5_:1;
    unsigned char unknown_0_6_:1;
    unsigned char unknown_0_7_:1;
};

struct Struct_02059cfc {
    char pad0[0x4];
    struct Struct_02057334_2* unknown_4_;
    char pad8[0x11];
    unsigned char unknown_19_;
    char pad1a[0xa];
    int field24;
    int field28;
    char pad2c[0x18];
    struct Vec3 pos;
    char unknown_50_[0x5c];
    int field_ac;
    short unknown_b0_;
    char unknown_b2_[0x4];
    short unknown_b6_;
    int field_b8;
    int unknown_bc_;
    struct Vec3 unknown_c0_;
    struct Struct_02059cfc_5 flags;
};

// USA: func_02059cfc
extern "C" ARM void func_02059cfc(unsigned char* p, int arg1, int id) {
    struct Struct_02059cfc* c = (struct Struct_02059cfc*)p;
    GameState* bs = GameState::GetInstance();

    if (c->unknown_b0_ > 0) {
        c->unknown_b0_ -= arg1;
        return;
    }

    if (c->field_ac == 0) {
        if (bs->GetGameObjectByIndex(id) == 0) {
            return;
        }

        if (c->field_b8 > 0) {
            int f28 = c->field28;
            int var3 = c->unknown_bc_;
            if (f28 <= var3) {
                int f24 = c->field24;
                if (var3 < f24) {
                    SePlayer_Play((struct SePlayer*)&g_sePlayer, c->field_b8, 0);
                }
            }
        }

        struct Vec3 pos = c->pos;

        int r5 = 0;
        if (c->flags.unknown_0_4_) {
            unsigned char* q = GameState_GetShip((PointerField32c_ffc0*)bs);
            if (q != 0) {
                r5 = *(int*)(q + 0x130);
            }
        } else if (c->flags.unknown_0_5_) {
            unsigned char* q = GameState_GetStarflight((PointerField330_ffd0*)bs);
            if (q != 0) {
                r5 = *(int*)(q + 0x130);
            }
        }

        if (c->flags.unknown_0_4_ || c->flags.unknown_0_5_) {
            if ((r5 & 1) && pos.x > 0) {
                pos.x -= 0x120000;
            } else if ((r5 & 2) && pos.x < 0) {
                pos.x += 0x120000;
            }
            if ((r5 & 4) && pos.z > 0) {
                pos.z -= 0xe0000;
            } else if ((r5 & 8) && pos.z < 0) {
                pos.z += 0xe0000;
            }
        }

        struct Vec3 var9;
        Vector3fixMultiplyScalar((Vector3i const*)&c->unknown_c0_, arg1 << 12, (Vector3i*)&var9);
        Vector3fix_Add((const Vector3fix*)&pos, (const Vector3fix*)&var9, (Vector3fix*)&pos);
        func_02059f38((struct Struct_02059cfc_2*)c, (struct Struct_02059cfc_3*)&pos);

        ((Object3D*)c)->AdvanceEffects();

        if (c->unknown_19_ & 1) {
            if (((Object3D*)((struct Struct_02059cfc_4*)c))->HasAnimationStopped()) {
                func_0200fd48(bs, id);
                func_02059cc8(p);
            }
        }

        if (c->unknown_b6_ > 0) {
            c->unknown_b6_ -= arg1;
            if (c->unknown_b6_ <= 0) {
                func_0200fd48(bs, id);
                func_02059cc8(p);
            }
        }
    } else {
        if (bs->GetGameObjectByIndex(id) == 0) {
            return;
        }
        if (func_02057854(c->unknown_4_) == 1) {
            func_0200fd48(bs, id);
            func_02059cc8(p);
        } else {
            func_02055774((int*)p);
        }
    }
}
