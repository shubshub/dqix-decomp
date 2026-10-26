#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "NitroSDK/Matrix.h"

#if defined(jpn)
enum { CameraBase = 0xb94, Enum_ov025_021dcf14_3208 = 0xc04, Enum_ov025_021dcf14_2864 = 0xaac, Enum_ov025_021dcf14_2192 = 0x80c, Enum_ov025_021dcf14_680 = 0x224, ModeByte = 0xdb4, Enum_ov025_021dcf14_28536 = 0x7168, Enum_ov025_021dcf14_24576 = 0x7000, Enum_ov025_021dcf14_3852 = 0xfc, Enum_ov025_021dcf14_28235 = 0x703b, Enum_ov025_021dcf14_28236 = 0x703c, Enum_ov025_021dcf14_28237 = 0x703d, Enum_ov025_021dcf14_28238 = 0x703e, Enum_ov025_021dcf14_28240 = 0x7040, Enum_ov025_021dcf14_28270 = 0x705e, Enum_ov025_021dcf14_28400 = 0x70e0, Enum_ov025_021dcf14_28410 = 0x70ea, Enum_ov025_021dcf14_28412 = 0x70ec, Enum_ov025_021dcf14_28414 = 0x70ee, Enum_ov025_021dcf14_28415 = 0x70ef, Enum_ov025_021dcf14_28416 = 0x70f0, Enum_ov025_021dcf14_28417 = 0x70f1, Enum_ov025_021dcf14_28418 = 0x70f2, Field6f04 = 0x70f4, Enum_ov025_021dcf14_28424 = 0x70f8, Enum_ov025_021dcf14_28436 = 0x7104, Enum_ov025_021dcf14_28548 = 0x7174, Enum_ov025_021dcf14_28556 = 0x717c, Enum_ov025_021dcf14_28568 = 0x7188, Field6f9a = 0x718a, Enum_ov025_021dcf14_28576 = 0x7190, Enum_ov025_021dcf14_28602 = 0x71aa, Enum_ov025_021dcf14_28612 = 0x71b4, Enum_ov025_021dcf14_28616 = 0x71b8, Enum_ov025_021dcf14_28620 = 0x71bc, Enum_ov025_021dcf14_28624 = 0x71c0, Enum_ov025_021dcf14_30533 = 0x7935, Enum_ov025_021dcf14_30534 = 0x7936 };
#else
enum { CameraBase = 0xc18, Enum_ov025_021dcf14_3208 = 0xc88, Enum_ov025_021dcf14_2864 = 0xb30, Enum_ov025_021dcf14_2192 = 0x890, Enum_ov025_021dcf14_680 = 0x2a8, ModeByte = 0xe38, Enum_ov025_021dcf14_28536 = 0x6f78, Enum_ov025_021dcf14_24576 = 0x6000, Enum_ov025_021dcf14_3852 = 0xf0c, Enum_ov025_021dcf14_28235 = 0x6e4b, Enum_ov025_021dcf14_28236 = 0x6e4c, Enum_ov025_021dcf14_28237 = 0x6e4d, Enum_ov025_021dcf14_28238 = 0x6e4e, Enum_ov025_021dcf14_28240 = 0x6e50, Enum_ov025_021dcf14_28270 = 0x6e6e, Enum_ov025_021dcf14_28400 = 0x6ef0, Enum_ov025_021dcf14_28410 = 0x6efa, Enum_ov025_021dcf14_28412 = 0x6efc, Enum_ov025_021dcf14_28414 = 0x6efe, Enum_ov025_021dcf14_28415 = 0x6eff, Enum_ov025_021dcf14_28416 = 0x6f00, Enum_ov025_021dcf14_28417 = 0x6f01, Enum_ov025_021dcf14_28418 = 0x6f02, Field6f04 = 0x6f04, Enum_ov025_021dcf14_28424 = 0x6f08, Enum_ov025_021dcf14_28436 = 0x6f14, Enum_ov025_021dcf14_28548 = 0x6f84, Enum_ov025_021dcf14_28556 = 0x6f8c, Enum_ov025_021dcf14_28568 = 0x6f98, Field6f9a = 0x6f9a, Enum_ov025_021dcf14_28576 = 0x6fa0, Enum_ov025_021dcf14_28602 = 0x6fba, Enum_ov025_021dcf14_28612 = 0x6fc4, Enum_ov025_021dcf14_28616 = 0x6fc8, Enum_ov025_021dcf14_28620 = 0x6fcc, Enum_ov025_021dcf14_28624 = 0x6fd0, Enum_ov025_021dcf14_30533 = 0x7745, Enum_ov025_021dcf14_30534 = 0x7746 };
#endif

struct Struct_ov025_021dcf14 {
    char pad0[4];
    int mode;
    char pad8[4];
    int unknown_c_;
    char pad10[8];
    short actorId;
    short targetId;
    unsigned short elapsed;
    unsigned short remaining;
};

struct Struct_ov025_021dcf14_2 {
    char pad0[0x20];
    unsigned short combatantId;
    char unknown_22_[4];
    unsigned char flags[6];
};

struct Struct_ov025_021dcf14_3 {
    char pad0[0xe];
    short ids[3];
    unsigned char codes[3];
    unsigned char count;
    unsigned char counts[3];
};

struct Struct_ov025_021dcf14_4 {
    char pad0[0x18];
    unsigned int unknown_18_0_ : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
};

struct Struct_ov025_021dcf14_5 {
    int f0;
    int f4;
    short id;
    short val;
    union {
        Vector3fix pos;
        short angle;
    };
    void* next;
};

struct Struct_ov025_021dcf14_6 {
    char pad0[0x20];
    short id;
    char unknown_22_[6];
    unsigned int flags;
    char pad2c[0x14];
};

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char unknown_11_;
    short f12;
    short objectId;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3fix offset;
    Vector3fix rotation;
    Vector3fix scale;
};

struct SePlayer;

extern "C" void* __clear(void* dst, int count);
extern "C" void func_ov000_0216d370(void* obj, int a, int b, int c);
extern "C" void func_ov000_0216df00(void* obj, int id, int b, int c, float scale);
struct Struct_ov000_02163a7c;
extern "C" void func_ov000_02163a7c(Struct_ov000_02163a7c*);
extern "C" void* func_ov000_02160f20(void* obj);
extern "C" void Camera_SetOrbitVector(void*, int*);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
struct Vector3i;
extern "C" void func_ov000_02167f10(void* obj);
struct Obj02033874;
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void func_ov025_021de110(void* obj);
struct Struct_ov025_021dcf14_7;
struct Struct_ov025_021dcf14_8;
extern "C" void func_ov025_021eee48(Struct_ov025_021dcf14_7*, Struct_ov025_021dcf14_8*);
struct Flags02033fcc;
extern "C" void GameObject_PauseMovement(Flags02033fcc*);
struct Flags02033fdc;
extern "C" void GameObject_ResumeMovement(Flags02033fdc*);
struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" struct Struct_ov025_021dcf14_4* func_02079e2c(char*, int);
struct Struct_ov000_0215440c;
extern "C" struct Struct_ov025_021dcf14_3* func_ov000_021600f8(Struct_ov000_0215440c*, int);
struct Struct_ov000_0215440c_2;
extern "C" struct Struct_ov025_021dcf14_2* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
struct Struct_ov025_021d8bfc;
extern "C" void func_ov025_021d8bfc(void*, Struct_ov025_021d8bfc*);
extern "C" int func_ov025_021ed444(void* obj, int id, int val2, int type, int val3, short arg5, unsigned short arg6);
extern "C" void Camera_Shake(unsigned char*, int, int);
extern "C" void func_ov000_02163440(void* obj, short a, unsigned short b, unsigned short c);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void* func_ov000_0215fff4(void*, int, int);
extern "C" int func_ov000_0215fd90(void* entry, int effect);
extern "C" int func_02048c68(unsigned char*);
extern "C" int func_02049ee8(unsigned char*);
extern "C" void func_0204a0c8(unsigned char*);
extern "C" int func_ov000_0215ffa0(void* node);
struct Struct_ov025_021dce7c;
extern "C" int func_ov025_021dce7c(unsigned char*, Struct_ov025_021dce7c*, int);
extern "C" void* func_02057924(void);
extern "C" void func_02078484(struct Struct_02078398_2* p);
extern "C" void func_02057fb4(void*, int, void*);
extern "C" void SePlayer_PlayExtra(void*, int, int);
extern "C" void func_ov025_021eabd0(void* obj, bool party);
extern "C" void func_ov025_021ead5c(void* obj, bool party);

extern Vector3fix data_ov025_021eeed4;
extern char data_ov025_021ef460[];
struct Struct_ov025_021dbe10 {
    int f0;
    unsigned short timer;
    unsigned short unknown_6_;
    int f8;
    int fc;
    int f10;
};
inline struct Struct_ov025_021dbe10& inline_ov025_021dcf14() {
    static struct Struct_ov025_021dbe10 s;
    return s;
}
extern struct SePlayer g_sePlayer;
extern Vector3fix data_ov025_021eeee0;
extern int data_ov025_021eeeec[];
extern int data_ov025_021eeef8[];

#define TIMER (inline_ov025_021dcf14().timer)

static inline void inline_ov025_021dcf14_2(unsigned char* sl, int phase, unsigned short time) {
    TIMER = time;
    sl[Enum_ov025_021dcf14_28235] = phase;
}

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

static inline struct Struct_ov025_021dcf14_6 inline_ov025_021dcf14_3(unsigned char* work) {
    return *(struct Struct_ov025_021dcf14_6*)(work + Enum_ov025_021dcf14_28536);
}

// USA: func_ov025_021dcf14
extern "C" ARM int func_ov025_021dcf14(unsigned char* sl) {
    GameState* battle = GameState::GetInstance();
    struct Struct_ov025_021dcf14* cur;
    GameObject* objs[5];

    if (sl[Enum_ov025_021dcf14_28235] != 0) {
        unsigned int var3 = battle->GetEffectiveDeltaTime();
        struct Struct_ov025_021dcf14* e = (struct Struct_ov025_021dcf14*)(sl + Enum_ov025_021dcf14_28240);
        for (int i = 0; i < sl[Enum_ov025_021dcf14_28237]; i++, e++) {
            if (var3 < e->remaining) {
                e->remaining -= var3;
            } else {
                e->remaining = 0;
            }
            e->elapsed += var3;
        }
    }

    cur = (struct Struct_ov025_021dcf14*)(sl + Enum_ov025_021dcf14_28240) + sl[Enum_ov025_021dcf14_28236];
    __clear(objs, sizeof(objs));

    if (sl[Enum_ov025_021dcf14_28235] == 0) {
        return 0;
    }

    if (sl[Enum_ov025_021dcf14_28235] == 1) {
        func_ov000_0216d370(sl + CameraBase, 1, 1, 1);
        func_ov000_0216df00(sl + CameraBase, cur->targetId, 0, 0, 1.8f);
        func_ov000_02163a7c((Struct_ov000_02163a7c*)sl);
        void* slot = func_ov000_02160f20(sl);
        if (*(unsigned short*)slot == 0x11b || *(unsigned short*)slot == 0x116) {
            Vector3fix cam = *(Vector3fix*)(sl + Enum_ov025_021dcf14_3208);
            cam.z = 0x847a;
            Camera_SetOrbitVector(sl + CameraBase, (int*)&cam);
        }
        func_ov000_021626a0(sl, 4, 0);
        for (int i = 0; i < *(short*)(sl + Enum_ov025_021dcf14_28410); i++) {
            GameObject* c = battle->GetCombatantByIndex(((short*)(sl + Enum_ov025_021dcf14_28400))[i]);
            objs[i] = c;
            if (c) {
                c->obj3D_.MakeVisible();
            }
        }

        GameObject* var10 = battle->GetCombatantByIndex(cur->targetId);
        if (var10) {
            var10->obj3D_.MakeVisible();
        }
        Vector3fix var11;
        if (var10) {
            var11 = var10->obj3D_.position_;
        }
        func_ov000_02167f10(sl);
        if (var10) {
            var10->obj3D_.position_ = var11;
            int radius = var10->obj3D_.GetRadius();
            Vector3fix base;
            __clear(&base, sizeof(base));
            base.x = radius / 4;
            base.z = radius;
            if (*(short*)(sl + Enum_ov025_021dcf14_28410) >= 2) {
                if (*(short*)(sl + Enum_ov025_021dcf14_28410) == 4) {
                    base.x = radius + radius / 8;
                }
                base.x = (int)(4096.0f * (0.6f * (radius / 4096.0f)));
            }

            int var14 = 0;
            for (int i = 0; i < *(short*)(sl + Enum_ov025_021dcf14_28410); i++) {
                GameObject* c = objs[i];
                if (c == NULL) {
                    continue;
                }
                Vector3fix off = base;
                Vector3fix face = data_ov025_021eeed4;
                if (*(short*)(sl + Enum_ov025_021dcf14_28410) >= 3) {
                    if (*(short*)(sl + Enum_ov025_021dcf14_28410) == 4) {
                        if (i >= 2) {
                            off.x = (int)(4096.0f * (0.2f * (radius / 4096.0f)));
                            off.z = radius + var14 / 2;
                        }
                    } else if (i == 2) {
                        off.x = 0;
                        off.z = radius + var14 / 2;
                    }
                }
                if (var14 < c->obj3D_.GetRadius()) {
                    var14 = objs[i]->obj3D_.GetRadius();
                }
                if (i % 2 != 0) {
                    off.x = -off.x;
                    face.x = -face.x;
                }
                Matrix4x3 rot = RotationMatrixY(var10->obj3D_.rotation_.y);
                Mat4x3_ApplyToVector(&off, &rot, &off);
                Vector3fix dst = objs[i]->obj3D_.position_;
                Vector3fix src = var10->obj3D_.position_;
                Vector3fix_Add(&src, &off, &dst);
                Matrix4x3 var22 = RotationMatrixY(var10->obj3D_.rotation_.y);
                Mat4x3_ApplyToVector(&face, &var22, &face);
                Vector3fix look;
                Vector3fix_Add(&dst, &face, &look);
                Vector3fix dir;
                Vector3fix_Subtract(&dst, &look, &dir);
                Vector3fix_Normalize(&dir, &dir);
                int angle = fix32_Atan2(dir.x, dir.z);
                objs[i]->obj3D_.position_ = look;
                GameObject_SnapFacing((Obj02033874*)objs[i], angle);
                struct Struct_ov025_021dcf14_5 rec;
                func_ov025_021de110(&rec);
                rec.f0 = 0;
                rec.id = ((short*)(sl + Enum_ov025_021dcf14_28400))[i];
                rec.val = 0x96;
                rec.pos = dst;
                func_ov025_021eee48((Struct_ov025_021dcf14_7*)(sl + Enum_ov025_021dcf14_2864), (Struct_ov025_021dcf14_8*)&rec);
                objs[i]->obj3D_.SetAnimationByName(data_ov025_021ef460, 0);
                GameObject_PauseMovement((Flags02033fcc*)objs[i]);
            }
        }

        int var27 = 0;
        for (int i = 0; i < *(short*)(sl + Enum_ov025_021dcf14_28410); i++) {
            GameObject* c = battle->GetCombatantByIndex(((short*)(sl + Enum_ov025_021dcf14_28400))[i]);
            if (c && var27 < c->obj3D_.GetHeight()) {
                var27 = c->obj3D_.GetHeight();
            }
        }
        if (var27 >= 0x1800) {
            float scale = 1.0f + 0.8f * (var27 / 4096.0f - 1.5f) / 2.5f;
            if (scale >= 1.8f) {
                scale = 1.8f;
            }
            Vector3fix cam = *(Vector3fix*)(sl + Enum_ov025_021dcf14_3208);
            cam.z = (int)(4096.0f * (cam.z / 4096.0f * scale));
            Camera_SetOrbitVector(sl + CameraBase, (int*)&cam);
        }
        inline_ov025_021dcf14_2(sl, 2, 0x9b);
    } else if (sl[Enum_ov025_021dcf14_28235] == 2) {
        unsigned int var32 = battle->GetEffectiveDeltaTime();
        if (var32 < TIMER) {
            TIMER -= var32;
        } else {
            TIMER = 0;
            for (int i = 0; i < *(short*)(sl + Enum_ov025_021dcf14_28410); i++) {
                objs[i] = battle->GetCombatantByIndex(((short*)(sl + Enum_ov025_021dcf14_28400))[i]);
            }
            int var34 = 0;
            int j;
            for (j = 0; j < *(short*)(sl + Enum_ov025_021dcf14_28410); j++) {
                if (objs[j] == NULL) {
                    continue;
                }
                if (var34 < objs[j]->obj3D_.GetHeight()) {
                    var34 = objs[j]->obj3D_.GetHeight();
                }
                int turn = 0x1922;
                if (j % 2 != 0) {
                    turn = -0x1922;
                }
                int rot = objs[j]->obj3D_.rotation_.y;
                GameObject_SnapFacing((Obj02033874*)objs[j], fix32ReduceAngle0To2Pi(rot + turn));
                GameObject_ForceMotionState((Bytes02033b88*)objs[j], 0);
            }
            float scale = 1.0f;
            if (var34 >= 0x1800) {
                scale = scale + 0.8f * (var34 / 4096.0f - 1.5f) / 2.5f;
                if (scale >= 1.8f) {
                    scale = 1.8f;
                }
            }
            Vector3fix cam = *(Vector3fix*)(sl + Enum_ov025_021dcf14_3208);
            fix32_Divide((int)(4096.0f * (6.0f * scale)), cam.z);
            TIMER = 0xc8;
            if (sl[Enum_ov025_021dcf14_28237] != 0) {
                sl[Enum_ov025_021dcf14_28235] = 6;
            } else {
                sl[Enum_ov025_021dcf14_28235] = 3;
            }
        }
        if (sl[Enum_ov025_021dcf14_28235] == 6) {
            void* slot = func_ov000_02160f20(sl);
            struct Struct_ov025_021dcf14_4* entry =
                func_02079e2c((char*)func_020797dc(), *(short*)slot);
            if (entry && entry->unknown_19_4_ == 2) {
                struct Struct_ov025_021dcf14_3* node = func_ov000_021600f8((Struct_ov000_0215440c*)slot, cur->unknown_c_);
                if (node == NULL) {
                    return 0;
                }
                if (node == NULL) {
                    return 0;
                }
                if (node->codes[2] != 1 && node->codes[2] != 2) {
                    unsigned int wait = *(unsigned int*)(sl + Enum_ov025_021dcf14_28556);
                    *(unsigned int*)(sl + Enum_ov025_021dcf14_28616) = wait;
                    if (wait > 0x9b) {
                        TIMER = wait - 0x9b;
                    }
                }
            }
        }
    } else if (sl[Enum_ov025_021dcf14_28235] == 6) {
        if (*(unsigned short*)(sl + Enum_ov025_021dcf14_28270) != 0) {
            return 0;
        }
        unsigned int var44 = battle->GetEffectiveDeltaTime();
        if (var44 < TIMER) {
            TIMER -= var44;
        } else {
            GameObject* actor = battle->GetCombatantByIndex(cur->actorId);
            if (actor) {
                GameObject_ResumeMovement((Flags02033fdc*)actor);
            }
            void* slot = func_ov000_02160f20(sl);
            struct Struct_ov025_021dcf14_2* first = func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0);
            if (first == NULL) {
                return 0;
            }
            if (first == NULL) {
                return 0;
            }
            struct Struct_ov025_021dcf14_3* node = func_ov000_021600f8((Struct_ov000_0215440c*)slot, cur->unknown_c_);
            if (node == NULL) {
                return 0;
            }
            if (node == NULL) {
                return 0;
            }
            int var49 = 0;
            int var50 = 0;
            if (node->codes[2] == 3 || node->codes[2] == 1) {
                if (node->codes[2] == 1) {
                    var50 = 1;
                } else {
                    var49 = 1;
                }
                cur->mode = 2;
            }
            if (!var49 && first->flags[4] != 0) {
                sl[Enum_ov025_021dcf14_28238] = 6;
            }
            func_ov025_021d8bfc(sl, (Struct_ov025_021d8bfc*)cur);
            if (sl[Enum_ov025_021dcf14_30533] != node->ids[1] || sl[Enum_ov025_021dcf14_30534] != node->ids[0]) {
                int msgId = 0x7f;
                int party = 0;
                if (node->ids[0] >= 0 && node->ids[0] <= 3) {
                    party = 1;
                }
                if (party) {
                    msgId = 0x7e;
                }
                func_ov025_021ed444(sl + Enum_ov025_021dcf14_2192, msgId, node->ids[0], 0, 0, node->ids[1], 0);
                sl[Enum_ov025_021dcf14_30533] = node->ids[1];
                sl[Enum_ov025_021dcf14_30534] = node->ids[0];
            }
            if (var49 || var50) {
                Camera_Shake((unsigned char*)(sl + CameraBase), 0xcc, 0x1f4);
                func_ov000_02163440(sl, 0x199, 0x1f4, 0x64);
                if (var50) {
                    SePlayer_Play(&g_sePlayer, 0x43, 0);
                }
            }
            cur->mode = 1;
            if (sl[Enum_ov025_021dcf14_28237] <= ++sl[Enum_ov025_021dcf14_28236]) {
                TIMER = 0x64;
                if (var49) {
                    TIMER = 0x96;
                }
                sl[Enum_ov025_021dcf14_28235] = 3;
            } else {
                TIMER = 0x12c;
                if (*(unsigned short*)slot == 1 || *(unsigned short*)slot == 2 || *(unsigned short*)slot == 0xdb) {
                    int k;
                    for (k = 0; k < 3; k++) {
                        int found = 0;
                        int d;
                        for (d = 0; d < node->counts[k]; d++) {
                            void* hit = func_ov000_0215fff4(node, d, (unsigned char)k);
                            if (hit && func_ov000_0215fd90(hit, 0x2a)) {
                                found = 1;
                                TIMER = 0;
                                break;
                            }
                        }
                        if (found) {
                            break;
                        }
                    }
                }
            }
        }
    } else if (sl[Enum_ov025_021dcf14_28235] == 3) {
        if (sl[Enum_ov025_021dcf14_28237] > sl[Enum_ov025_021dcf14_28236]) {
            sl[Enum_ov025_021dcf14_28235] = 6;
        } else {
            unsigned int var57 = battle->GetEffectiveDeltaTime();
            if (var57 < TIMER) {
                TIMER -= var57;
            } else {
                TIMER = 0;
            }
        }
    } else if (sl[Enum_ov025_021dcf14_28235] == 4) {
        unsigned int var58 = battle->GetEffectiveDeltaTime();
        if (var58 < TIMER) {
            TIMER -= var58;
        } else {
            void* slot = func_ov000_02160f20(sl);
            struct Struct_ov025_021dcf14_2* first = func_ov000_02160094((Struct_ov000_0215440c_2*)slot, 0);
            if (first == NULL) {
                return 0;
            }
            if (first == NULL) {
                return 0;
            }
            struct Struct_ov025_021dcf14_3* node = func_ov000_021600f8((Struct_ov000_0215440c*)slot, cur->unknown_c_);
            if (node == NULL) {
                return 0;
            }
            if (node == NULL) {
                return 0;
            }
            int var62 = 0;
            int var63 = 0;
            unsigned char found = 0;
            unsigned short var65 = 0;
            if (node->codes[2] == 3) {
                var62 = 1;
            } else if (node->codes[2] == 1) {
                var63 = 1;
            }
            int any = 0;
            if (!var62 && !var63) {
                int k;
                for (k = 0; k < 6; k++) {
                    if (first->flags[k] != 0) {
                        any = 1;
                        if (k == 4) {
                            var65 = first->combatantId;
                            found = 1;
                            sl[Enum_ov025_021dcf14_28238] = 4;
                        }
                    }
                }
            }
            if (!var62 && !found && !var63) {
                for (int i = 0; i < *(short*)(sl + Enum_ov025_021dcf14_28410); i++) {
                    GameObject* c = battle->GetCombatantByIndex(((short*)(sl + Enum_ov025_021dcf14_28400))[i]);
                    if (c && !func_02048c68((unsigned char*)c)) {
                        objs[i] = c;
                        if (!any && objs[i]) {
                            objs[i]->obj3D_.MakeVisible();
                        }
                    }
                }
                for (int i = 0; i < *(short*)(sl + Enum_ov025_021dcf14_28410); i++) {
                    int rotY;
                    GameObject* c = objs[i];
                    if (c == NULL) {
                        continue;
                    }
                    if (func_02049ee8((unsigned char*)c) == 0 || func_02048c68((unsigned char*)c) != 0) {
                        c->obj3D_.TransitionInheritedAlpha(0, 0x12c);
                        int party = 0;
                        if (c->obj3D_.actorIndex_ >= 0 && c->obj3D_.actorIndex_ <= 3) {
                            party = 1;
                        }
                        if (party || func_02048c68((unsigned char*)c)) {
                            func_0204a0c8((unsigned char*)c);
                        }
                    } else {
                        Vector3fix off = data_ov025_021eeee0;
                        off.x = data_ov025_021eeeec[i];
                        rotY = c->obj3D_.rotation_.y;
                        Matrix4x3 rot = RotationMatrixY(rotY);
                        Mat4x3_ApplyToVector(&off, &rot, &off);
                        Vector3fix pos = c->obj3D_.position_;
                        Vector3fix dst;
                        Vector3fix_Add(&pos, &off, &dst);
                        struct Struct_ov025_021dcf14_5 rec;
                        func_ov025_021de110(&rec);
                        rec.f0 = 1;
                        rec.id = cur->actorId;
                        rec.val = 0x64;
                        rec.angle = fix32ReduceAngle0To2Pi(rotY + data_ov025_021eeef8[i]);
                        func_ov025_021eee48((Struct_ov025_021dcf14_7*)(sl + Enum_ov025_021dcf14_2864), (Struct_ov025_021dcf14_8*)&rec);
                        func_ov025_021de110(&rec);
                        rec.f0 = 0;
                        rec.id = ((short*)(sl + Enum_ov025_021dcf14_28400))[i];
                        rec.val = 0x12c;
                        rec.pos = dst;
                        func_ov025_021eee48((Struct_ov025_021dcf14_7*)(sl + Enum_ov025_021dcf14_2864), (Struct_ov025_021dcf14_8*)&rec);
                        objs[i]->obj3D_.SetAnimationByName(data_ov025_021ef460, 0);
                        GameObject_PauseMovement((Flags02033fcc*)objs[i]);
                    }
                }
                sl[Enum_ov025_021dcf14_28238] = 0;
                inline_ov025_021dcf14_2(sl, 5, 0x12c);
            } else {
                func_ov000_021626a0(sl, 4, 0);
                GameObject* target = NULL;
                int id = func_ov000_0215ffa0(node);
                if (var62 || var63) {
                    if (!func_ov025_021dce7c((unsigned char*)sl, (Struct_ov025_021dce7c*)slot, id)) {
                        func_ov000_0216df00(sl + CameraBase, id, 0, 0, 1.8f);
                    }
                    target = battle->GetCombatantByIndex(id);
                } else if (found) {
                    func_ov000_0216df00(sl + CameraBase, var65, 0, 0, 1.8f);
                    target = battle->GetCombatantByIndex(var65);
                    cur->mode = 0;
                }
                target->obj3D_.MakeVisible();
                if (var63) {
                    int objectId = func_ov000_0215ffa0(node);
                    struct Struct_ov025_021dcf14_6 pending = inline_ov025_021dcf14_3(sl);
                    void* list = func_02057924();
                    struct Struct_02078398_2 req;
                    func_02078484(&req);
                    req.objectId = objectId;
                    if (pending.flags & 1) {
                        req.offset.y += target->obj3D_.GetHeight() / 2;
                    }
                    func_02057fb4(list, pending.id, &req);
                    SePlayer_PlayExtra(&g_sePlayer, *(short*)(sl + Field6f9a), 0);
                }
                if (!var63) {
                    if (var62) {
                        cur->mode = 3;
                    }
                    func_ov025_021d8bfc(sl, (Struct_ov025_021d8bfc*)cur);
                    cur->mode = 1;
                    if (sl[Enum_ov025_021dcf14_28237] <= ++sl[Enum_ov025_021dcf14_28236]) {
                        sl[Enum_ov025_021dcf14_28238] = 0;
                        inline_ov025_021dcf14_2(sl, 5, 1000);
                    }
                } else {
                    unsigned int wait = *(unsigned int*)(sl + Enum_ov025_021dcf14_28556);
                    *(unsigned int*)(sl + Enum_ov025_021dcf14_28616) = wait;
                    sl[Enum_ov025_021dcf14_28238] = 0;
                    inline_ov025_021dcf14_2(sl, 7, wait);
                }
            }
        }
    } else if (sl[Enum_ov025_021dcf14_28235] == 7) {
        unsigned int var86 = battle->GetEffectiveDeltaTime();
        if (var86 < TIMER) {
            TIMER -= var86;
        } else {
            struct Struct_ov025_021dcf14_3* node =
                func_ov000_021600f8((Struct_ov000_0215440c*)func_ov000_02160f20(sl), cur->unknown_c_);
            if (node == NULL) {
                return 0;
            }
            if (node == NULL) {
                return 0;
            }
            int id = func_ov000_0215ffa0(node);
            func_ov025_021eabd0(sl + Enum_ov025_021dcf14_680, IsPartyMember(id));
            func_ov025_021d8bfc(sl, (Struct_ov025_021d8bfc*)cur);
            func_ov025_021ead5c(sl + Enum_ov025_021dcf14_680, IsPartyMember(id));
            inline_ov025_021dcf14_2(sl, 5, 1000);
        }
    } else if (sl[Enum_ov025_021dcf14_28235] == 5) {
        unsigned int var89 = battle->GetEffectiveDeltaTime();
        if (var89 < TIMER) {
            TIMER -= var89;
        } else {
            TIMER = 0;
            for (int i = 0; i < sl[Enum_ov025_021dcf14_28237]; i++) {
                GameObject* c = battle->GetCombatantByIndex(((struct Struct_ov025_021dcf14*)(sl + Enum_ov025_021dcf14_28240))[i].actorId);
                if (c) {
                    GameObject_ResumeMovement((Flags02033fdc*)c);
                }
                ((struct Struct_ov025_021dcf14*)(sl + Enum_ov025_021dcf14_28240))[i].actorId = -1;
                ((struct Struct_ov025_021dcf14*)(sl + Enum_ov025_021dcf14_28240))[i].targetId = -1;
            }
            sl[Enum_ov025_021dcf14_28237] = 0;
            sl[Enum_ov025_021dcf14_28235] = 0;
        }
    }
    return 0;
}

// USA: func_ov025_021de110
extern "C" ARM void func_ov025_021de110(void* obj) {
    *(int*)((char*)obj + 0x0) = 0;
    *(int*)((char*)obj + 0x4) = 0;
    *(int*)((char*)obj + 0x18) = 0;
}

struct Struct_ov025_021de124 {
    unsigned short id;
    char unknown_2_[7];
    unsigned char count;
};

struct Struct_ov025_021de124_2 {
    struct Struct_ov025_021de124* list;
    int mode;
    char pad8[4];
    int unknown_c_;
    char pad10[8];
    unsigned short elapsed;
    unsigned short remaining;
};

struct Struct_ov025_021de124_3 {
    char pad0[0x2c];
    unsigned short flags;
    short a;
    short b;
    char unknown_32_[6];
    unsigned char mode;
};

extern "C" void func_ov000_0216d370(void* obj, int a, int b, int c);
extern "C" void func_ov000_0216df00(void* obj, int id, int b, int c, float scale);
extern "C" void func_ov000_0216dbf0(void* obj, int* id, int a, int b);
extern "C" void* func_ov000_02160f20(void* obj);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
extern "C" void func_ov000_02167f10(void* obj);
extern "C" int func_ov025_021ed444(void* obj, int id, int val2, int type, int val3, short arg5, unsigned short arg6);
extern "C" int func_ov025_021ed564(void* obj, int id, int val2, int type, int val3, short arg5, unsigned short arg6);
extern "C" void func_ov000_02163440(void* obj, short a, unsigned short b, unsigned short c);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" int func_ov000_0215ff80(char*, int);
extern "C" void* func_ov000_02160130(void);
extern "C" int func_ov000_0215ffa0(void* node);
extern "C" void func_ov025_021eabd0(void* obj, bool party);
extern "C" void func_ov025_021ead5c(void* obj, bool party);
extern "C" void func_ov025_021ed344(void* obj, int val);
extern "C" int func_ov025_021ed2f4(void* obj);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(int obj);
extern "C" void* func_02057924(void);
extern "C" void func_02078484(struct Struct_02078398_2* p);
extern "C" short func_ov000_0216352c(int id, float a, float b);
extern "C" int func_ov000_021635e4(int id, int mode);

extern Vector3fix data_ov025_021eef04;
extern struct SePlayer g_sePlayer;

#undef TIMER
#define TIMER (inline_ov025_021dcf14().unknown_6_)

static inline int inline_ov025_021de124(void* node) {
    return func_ov000_0215ff80((char*)node, 0) >= 0 && func_ov000_0215ff80((char*)node, 0) <= 3;
}

static inline int inline_ov025_021dfbfc(int id) {
    return id >= 0xc0 && id <= 0xc7;
}

// USA: func_ov025_021de124
extern "C" ARM int func_ov025_021de124(unsigned char* sl) {
    GameState* battle = GameState::GetInstance();
    struct Struct_ov025_021de124* list;
    struct Struct_ov025_021de124_2* cur;

    if (sl[Enum_ov025_021dcf14_28414] != 0) {
        unsigned int var3 = battle->GetEffectiveDeltaTime();
        struct Struct_ov025_021de124_2* e = (struct Struct_ov025_021de124_2*)(sl + Enum_ov025_021dcf14_28424);
        for (int i = 0; i < sl[Enum_ov025_021dcf14_28416]; i++, e++) {
            if (var3 < e->remaining) {
                e->remaining -= var3;
            } else {
                e->remaining = 0;
            }
            e->elapsed += var3;
        }
    }

    if (sl[Enum_ov025_021dcf14_28414] == 0) {
        return 0;
    }
    cur = (struct Struct_ov025_021de124_2*)(sl + Enum_ov025_021dcf14_28424) + sl[Enum_ov025_021dcf14_28415];

    if (sl[Enum_ov025_021dcf14_28414] == 1) {
        list = cur->list;
        struct Struct_ov025_021dcf14_3* node = func_ov000_021600f8((Struct_ov000_0215440c*)list, cur->unknown_c_);
        int n = list->count - 1;
        if (n <= 0) {
            n = 1;
        }
        *(unsigned int*)(sl + Enum_ov025_021dcf14_28616) = *(unsigned int*)(sl + Enum_ov025_021dcf14_28556);
        if (list->count > 1) {
            if (*(unsigned int*)(sl + Enum_ov025_021dcf14_28556) > *(unsigned int*)(sl + Enum_ov025_021dcf14_28548)) {
                *(unsigned int*)(sl + Enum_ov025_021dcf14_28616) = *(unsigned int*)(sl + Enum_ov025_021dcf14_28556) - *(unsigned int*)(sl + Enum_ov025_021dcf14_28548);
            }
        }
        *(unsigned int*)(sl + Enum_ov025_021dcf14_28620) = *(unsigned int*)(sl + Enum_ov025_021dcf14_28548) / n;
        *(unsigned int*)(sl + Enum_ov025_021dcf14_28612) = 0;
        if (*(unsigned int*)(sl + Enum_ov025_021dcf14_28620) > *(unsigned int*)(sl + Enum_ov025_021dcf14_28616)) {
            *(unsigned int*)(sl + Enum_ov025_021dcf14_28612) = *(unsigned int*)(sl + Enum_ov025_021dcf14_28620) - *(unsigned int*)(sl + Enum_ov025_021dcf14_28616);
        }
        if (!(sl[ModeByte] != 0 && list->id != 0x246 && list->id != 0x30d)
            && !(list->id == 0x30f || list->id == 0x243)) {
            func_ov000_0216d370(sl + CameraBase, 0, 1, 1);
            func_ov000_0216df00(sl + CameraBase, node->ids[0], 0, 0, 1.8f);
            func_ov000_02163a7c((Struct_ov000_02163a7c*)sl);
            func_ov000_021626a0(sl, 4, 0);
            GameObject* obj = battle->GetCombatantByIndex(node->ids[0]);
            if (obj) {
                obj->obj3D_.MakeVisible();
            }
        }
        sl[Enum_ov025_021dcf14_28414] = 2;
    } else if (sl[Enum_ov025_021dcf14_28414] == 2) {
        list = cur->list;
        int index = cur->unknown_c_;
        int found = 0;
        TIMER = 0;
        struct Struct_ov025_021dcf14_3* node = func_ov000_021600f8((Struct_ov000_0215440c*)list, index);
        for (int i = 1; i < node->count; i++) {
            if (node->codes[i] == 1 || node->codes[i] == 2) {
                found = 1;
            }
        }
        int id = node->ids[0];
        if (node->count > 1) {
            if (node->codes[1] == 8 || node->codes[1] == 7 || node->codes[1] == 6) {
                id = node->ids[1];
            }
        }
        GameObject* obj = battle->GetCombatantByIndex(id);
        if (obj && !found) {
            void* fx = func_02057924();
            struct Struct_02078398_2 req;
            func_02078484(&req);
            req.objectId = id;
            if (*(unsigned int*)(sl + Enum_ov025_021dcf14_28576) & 1) {
                req.offset.y += obj->obj3D_.GetHeight() / 2;
            }
            SePlayer_PlayExtra(&g_sePlayer, *(short*)(sl + Field6f9a), 0);
            func_02057fb4(fx, *(short*)(sl + Enum_ov025_021dcf14_28568), &req);
            TIMER = *(unsigned int*)(sl + Enum_ov025_021dcf14_28616);
        }
        sl[Enum_ov025_021dcf14_28414] = 3;
    } else if (sl[Enum_ov025_021dcf14_28414] == 3) {
        unsigned int var17 = battle->GetEffectiveDeltaTime();
        if (var17 < TIMER) {
            TIMER -= var17;
        } else {
            struct Struct_ov025_021de124* list = cur->list;
            struct Struct_ov025_021dcf14_3* node;
            int hit = 0;
            int flag8;
            int index = cur->unknown_c_;
            TIMER = 0;
            node = func_ov000_021600f8((Struct_ov000_0215440c*)list, index);
            int i = 1;
            flag8 = 0;
            for (; i < node->count; i++) {
                if (node->codes[i] == 8 || node->codes[i] == 7 || node->codes[i] == 6) {
                    flag8 = 1;
                }
                if (node->codes[i] == 1 || node->codes[i] == 2) {
                    cur->mode = 2;
                    hit = 1;
                    break;
                }
            }
            func_ov025_021d8bfc(sl, (Struct_ov025_021d8bfc*)cur);
            if (flag8) {
                int msgId = 0x7f;
                int party = 0;
                if (node->ids[1] >= 0 && node->ids[1] <= 3) {
                    party = 1;
                }
                if (party) {
                    msgId = 0x7e;
                }
                unsigned short msg = msgId;
                if (func_ov025_021ed564(sl + Enum_ov025_021dcf14_2192, msg, node->ids[0], 0, 0, node->ids[1], 0) < 0) {
                    func_ov025_021ed444(sl + Enum_ov025_021dcf14_2192, msg, node->ids[0], 0, 0, node->ids[1], 0);
                }
            }
            sl[Enum_ov025_021dcf14_28415]++;
            sl[Enum_ov025_021dcf14_28414] = 4;
            TIMER = *(unsigned int*)(sl + Enum_ov025_021dcf14_28612);
            if (hit) {
                if (sl[ModeByte] != 2) {
                    func_ov000_02163440(sl, 0xcc, 0xc8, 0x64);
                }
                SePlayer_Play(&g_sePlayer, 0x43, 0);
                TIMER = *(unsigned int*)(sl + Enum_ov025_021dcf14_28612) + 0x1f4;
            }
            if (list->count <= sl[Enum_ov025_021dcf14_28415]) {
                sl[Enum_ov025_021dcf14_28417] = 1;
                bool party = inline_ov025_021de124(node);
                struct Struct_ov025_021de124* slot = (struct Struct_ov025_021de124*)func_ov000_02160f20(func_ov000_02160130());
                int found = -1;
                for (int i = 0; i < slot->count; i++) {
                    struct Struct_ov025_021dcf14_3* n = func_ov000_021600f8((Struct_ov000_0215440c*)slot, i);
                    if (n == 0) {
                        continue;
                    }
                    int v = func_ov000_0215ffa0(n);
                    if (party) {
                        int m = v >= 0 && v <= 3;
                        if (m) {
                            found = v;
                            break;
                        }
                    } else {
                        int m = v >= 0 && v <= 3;
                        if (!m) {
                            found = v;
                            break;
                        }
                    }
                }
                if (found >= 0) {
                    func_ov025_021eabd0(sl + Enum_ov025_021dcf14_680, party);
                    func_ov025_021ead5c(sl + Enum_ov025_021dcf14_680, party);
                    func_ov025_021ed344(sl + Enum_ov025_021dcf14_2192, 0);
                }
                TIMER = 0x5dc;
            }
        }
    } else if (sl[Enum_ov025_021dcf14_28414] == 4) {
        unsigned int var35 = battle->GetEffectiveDeltaTime();
        if (var35 < TIMER) {
            TIMER -= var35;
        } else {
            TIMER = 0;
            if (func_ov025_021ed2f4(sl + Enum_ov025_021dcf14_2192)) {
                if (sl[Enum_ov025_021dcf14_28416] > sl[Enum_ov025_021dcf14_28415]) {
                    sl[Enum_ov025_021dcf14_28414] = 2;
                }
                if (sl[Enum_ov025_021dcf14_28417] == 1) {
                    sl[Enum_ov025_021dcf14_28414] = 5;
                    sl[Enum_ov025_021dcf14_28417] = 0;
                    sl[Enum_ov025_021dcf14_28415] = 0;
                }
            }
        }
    } else if (sl[Enum_ov025_021dcf14_28414] == 5) {
        if (!func_ov025_021ed2f4(sl + Enum_ov025_021dcf14_2192)) {
            return 1;
        }
        MessageSystem_Stop(MessageSystem_GetInstance());
        func_ov000_021626a0(sl, 4, 0);
        GameObject* var36 = battle->GetCombatantByIndex(*(short*)(sl + Enum_ov025_021dcf14_28412));
        if (var36) {
            var36->obj3D_.MakeVisible();
        }
        list = cur->list;
        struct Struct_ov025_021dcf14_4* row =
            func_02079e2c((char*)func_020797dc(), *(short*)list);
        int var38 = 0;
        int var39 = 0;
        int var40 = 0;
        if (row) {
            if (row->unknown_19_4_ == 2) {
                var38 = 1;
            }
        }
        if (list->id == 0x246 || list->id == 0x30d) {
            var39 = 1;
        }
        if (list->id == 0x30f || list->id == 0x243) {
            var40 = 1;
        }
        void* fx = func_02057924();
        struct Struct_02078398_2 req;
        func_02078484(&req);
        if (var39 || (sl[ModeByte] != 3 && var38 != 0 && var40 == 0)) {
            func_ov000_0216d370(sl + CameraBase, 1, 1, 1);
            if (!func_ov025_021dce7c((unsigned char*)sl, (Struct_ov025_021dce7c*)list, *(short*)(sl + Enum_ov025_021dcf14_28412))) {
                func_ov000_0216df00(sl + CameraBase, *(short*)(sl + Enum_ov025_021dcf14_28412), 0, 0, 1.8f);
            }
            req.objectId = *(short*)(sl + Enum_ov025_021dcf14_28412);
            if (*(unsigned int*)(sl + Enum_ov025_021dcf14_28576) & 1) {
                req.offset.y += var36->obj3D_.GetHeight() / 2;
            }
            struct Struct_ov025_021de124_3* p;
            int id = *(short*)(sl + Enum_ov025_021dcf14_28412);
            int inRange = 0;
            if (id >= 0xc0) {
                inRange = id <= 0xc7;
            }
            if (inRange) {
                p = (struct Struct_ov025_021de124_3*)(sl + Enum_ov025_021dcf14_28536);
                if (p->flags & 1) {
                    int v = 0x1000;
                    switch (p->mode) {
                    case 0:
                        v = func_ov000_0216352c(id, p->a / 4096.0f, p->b / 4096.0f);
                        break;
                    case 1:
                        v = func_ov000_021635e4(id, (unsigned char)p->a);
                        if (p->b <= v) {
                            v = p->b;
                        }
                        break;
                    }
                    Vector3fix var47;
                    var47.x = v;
                    var47.y = v;
                    var47.z = v;
                    req.scale = var47;
                }
            }
            func_02057fb4(fx, *(short*)(sl + Enum_ov025_021dcf14_28568), &req);
            if (*(short*)(sl + Field6f9a) != -1) {
                SePlayer_PlayExtra(&g_sePlayer, *(short*)(sl + Field6f9a), 0);
            } else if (*(unsigned short*)(sl + Field6f04) != -1) {
                SePlayer_PlayExtra(&g_sePlayer, *(unsigned short*)(sl + Field6f04), 0);
            }
            TIMER = *(unsigned int*)(sl + Enum_ov025_021dcf14_28616);
        } else if (sl[ModeByte] == 3 || var38 == 0 || var40 != 0) {
            int var48;
            func_ov000_0216d370(sl + CameraBase, 1, 1, 1);
            var48 = *(short*)(sl + Enum_ov025_021dcf14_28412);
            if (var38) {
                func_ov000_0216dbf0(sl + CameraBase, &var48, 1, 1);
            } else {
                func_ov000_0216df00(sl + CameraBase, *(short*)(sl + Enum_ov025_021dcf14_28412), 0, 0, 1.8f);
            }
            func_ov000_021626a0(sl, 4, 0);
            GameObject* obj = battle->GetCombatantByIndex(var48);
            if (obj) {
                func_ov000_02167f10(sl);
                Vector3fix v = data_ov025_021eef04;
                obj->obj3D_.position_ = v;
                obj->obj3D_.MakeVisible();
            }
            SePlayer_PlayExtra(&g_sePlayer, *(unsigned short*)(sl + Field6f04), 0);
            req.objectId = var48;
            func_02057fb4(fx, *(unsigned short*)(sl + Enum_ov025_021dcf14_28418), &req);
            TIMER = *(unsigned int*)(sl + Enum_ov025_021dcf14_28624);
            if (TIMER == 0) {
                TIMER = 0x1f4;
            }
        }
        sl[Enum_ov025_021dcf14_28414] = 6;
    } else if (sl[Enum_ov025_021dcf14_28414] == 6) {
        unsigned int var51 = battle->GetEffectiveDeltaTime();
        if (var51 < TIMER) {
            TIMER -= var51;
        } else {
            struct Struct_ov025_021de124* list;
            struct Struct_ov025_021dcf14_3* node;
            int v, first, i;
            i = 0;
            list = cur->list;
            TIMER = i;
            v = -1;
            first = 1;
            for (; i < list->count; i++) {
                int off = i * 0x1c;
                node = func_ov000_021600f8((Struct_ov000_0215440c*)list, *(int*)(sl + off + Enum_ov025_021dcf14_28436));
                for (int j = 1; j < node->count; j++) {
                    if (node->codes[j] == 1 || node->codes[j] == 2) {
                        *(int*)(sl + Enum_ov025_021dcf14_24576 + off + Enum_ov025_021dcf14_3852) = 1;
                        if (v < 0) {
                            v = func_ov000_0215ffa0(node);
                        }
                        if (first) {
                            bool party = IsPartyMember(v);
                            func_ov025_021eabd0(sl + Enum_ov025_021dcf14_680, party);
                            first = 0;
                        }
                        func_ov025_021d8bfc(sl, (Struct_ov025_021d8bfc*)(sl + Enum_ov025_021dcf14_28424 + off));
                    }
                }
            }
            bool party = IsPartyMember(v);
            func_ov025_021ead5c(sl + Enum_ov025_021dcf14_680, party);
            TIMER = *(unsigned int*)(sl + Enum_ov025_021dcf14_28616);
            sl[Enum_ov025_021dcf14_28414] = 8;
        }
    } else if (sl[Enum_ov025_021dcf14_28414] == 8) {
        unsigned int var61 = battle->GetEffectiveDeltaTime();
        if (var61 < TIMER) {
            TIMER -= var61;
        } else {
            TIMER = 0;
            for (int i = 0; i < 4; i++) {
                GameObject* obj = battle->GetCombatantByIndex(((short*)(sl + Enum_ov025_021dcf14_28602))[i]);
                if (obj) {
                    GameObject_ResumeMovement((Flags02033fdc*)obj);
                }
                ((short*)(sl + Enum_ov025_021dcf14_28602))[i] = -1;
            }
            GameObject* obj = battle->GetCombatantByIndex(*(short*)(sl + Enum_ov025_021dcf14_28412));
            if (obj) {
                GameObject_ResumeMovement((Flags02033fdc*)obj);
            }
            sl[Enum_ov025_021dcf14_28417] = 0;
            sl[Enum_ov025_021dcf14_28415] = 0;
            sl[Enum_ov025_021dcf14_28414] = 0;
            *(unsigned short*)(sl + Enum_ov025_021dcf14_28418) = 0;
            *(unsigned short*)(sl + Field6f04) = 0xffff;
            *(unsigned int*)(sl + Enum_ov025_021dcf14_28624) = 0;
        }
    }
    return 0;
}
