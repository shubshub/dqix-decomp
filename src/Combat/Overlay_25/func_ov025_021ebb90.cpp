#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov025_021ebb90_336 = 0x144, Enum_ov025_021ebb90_28412 = 0x70ec, Enum_ov025_021ebb90_28414 = 0x70ee, Enum_ov025_021ebb90_28536 = 0x7168, Enum_ov025_021ebb90_28665 = 0x71e9, Enum_ov025_021ebb90_28668 = 0x71ec };
#else
enum { Enum_ov025_021ebb90_336 = 0x150, Enum_ov025_021ebb90_28412 = 0x6efc, Enum_ov025_021ebb90_28414 = 0x6efe, Enum_ov025_021ebb90_28536 = 0x6f78, Enum_ov025_021ebb90_28665 = 0x6ff9, Enum_ov025_021ebb90_28668 = 0x6ffc };
#endif

struct Struct_ov025_021ebb90_6 {
    int a;
    unsigned char idx : 6;
    unsigned char mode : 2;
    unsigned char c;
    unsigned char d;
    unsigned char unknown_7_;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    int j;
    short k;
    short l;
    unsigned int m;
    int n;
    unsigned short o;
    short p;
    short q;
    short r;
    short s;
    short t;
    unsigned char u;
    unsigned char v;
    unsigned char w;
    unsigned char unknown_3b_;
    unsigned short x;
    unsigned short unknown_3e_;
};

struct Struct_ov025_021ee438;

struct Struct_ov025_021e9778_4 {
    struct Struct_ov025_021ebb90_6 entries[12];
    unsigned char unknown_300_;
    unsigned char unknown_301_;
    unsigned short unknown_302_;
    short unknown_304_;
    unsigned char unknown_306_;
    unsigned char unknown_307_;
    int unknown_308_;
    struct Struct_ov025_021ee438* unknown_30c_;
    unsigned char unknown_310_;
    unsigned char unknown_311_;
};

struct Struct_ov000_0215440c { short id; char unknown_2_[7]; unsigned char count; };
struct Struct_ov000_021600f8 {
    char unknown_0_[0xe];
    short unknown_e_[3];
    unsigned char codes[3];
    unsigned char unknown_17_;
    unsigned char counts[3];
};
struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094 {
    char unknown_0_[0x20];
    unsigned short id;
    char unknown_22_[4];
    unsigned char unknown_26_, unknown_27_, f28, unknown_29_, unknown_2a_, unknown_2b_;
};
struct Struct_ov025_021ebb90 { char pad[0x14]; unsigned int flags; };

struct Vec3 { int x; int y; int z; };
struct Struct_ov025_021ebb90_2 { int m[9]; };

struct Struct_ov025_021ebb90_3 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov025_021ebb90_4 {
    unsigned char unknown_0_;
    char unknown_1_[0xf];
    unsigned char f10;
    struct Struct_ov025_021ebb90_3 flags;
    short f12;
    short targetId;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20[3];
    struct Vec3 pos;
    int unknown_38_[3];
    struct Vec3 scale;
};

struct Struct_ov025_021ebb90_5 { unsigned char idx; unsigned char unknown_1_; };

struct Bytes02033b88;
struct Obj0203a588;

extern "C" void* func_ov000_02160130(void);
extern "C" unsigned char func_ov025_021dcc64(void* obj);
extern "C" void func_ov025_021dcc58(void* obj, unsigned char v);
extern "C" int func_ov000_02162954(void* self);
extern "C" int func_ov025_021ed2f4(void* obj);
extern "C" void func_ov025_021ebb24(struct Struct_ov025_021ebb90_6* obj);
extern "C" struct Struct_ov000_021600f8* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
extern "C" struct Struct_ov025_021ebb90* func_02079e2c(char* table, int key);
extern "C" void func_ov000_0216346c(char* obj, int val);
extern "C" void func_ov000_021634c8(char* obj, int val);
extern "C" short func_ov000_0215ffa0(void* obj);
extern "C" int func_ov025_021d8c30(void* arg0, void* arg1, int kind, int category, int idx, int inner, int flag);
extern "C" void func_02049ae4(unsigned char* obj);
extern "C" int func_02049ee8(unsigned char* obj);
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
extern "C" void* MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(void* self);
extern "C" struct Obj0203a588* NumberPopups_GetInstance(void);
extern "C" void func_0203a588(struct Obj0203a588* obj);
extern "C" void func_ov000_02182a44(void* obj);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
extern "C" int func_02085078(unsigned char* obj);
extern "C" int func_020850a4(unsigned char* obj);
extern "C" void* func_02057924(void);
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);
extern "C" int fix32_CosFx64c(int);
extern "C" int fix32_SinFx64c(int);
extern "C" float _ll_sto_f(int);
extern "C" short func_ov000_0216352c(int id, float a, float b);
extern "C" int func_ov000_021635e4(int id, unsigned char mode);
extern "C" int func_ov000_02163c0c(void* unused, int id);
extern "C" void func_02057fb4(void* list, int id, void* config);
extern "C" void SePlayer_PlayExtra(void* obj, int a, int b);
extern "C" int func_ov025_021ee438(struct Struct_ov025_021ee438* obj, int id);
extern "C" void func_ov025_021dcf14(void* arg0);
extern "C" void* func_ov000_02160f14(void* arg0);
extern "C" void func_ov000_0216df00(void* handle, int a, int b, int c, float scale);
extern "C" void func_ov000_021626a0(void* arg0, int a, int b);
extern "C" void func_ov025_021ecb90(struct Struct_ov025_021ebb90_6* dst, struct Struct_ov025_021ebb90_6* src);

extern int g_sePlayer;
extern "C" void __clear(void* dst, unsigned int n);

static inline int inline_ov025_021ebb90(unsigned int id) { return id <= 3; }

#define FX_MUL_021ebb90(a, b) ((int)((((long long)(a) * (long long)(b)) + 0x800) >> 12))

// USA: func_ov025_021ebb90
static inline struct Struct_ov025_021ebb90_6* inline_ov025_021ebb90_2(struct Struct_ov025_021e9778_4* o, int n) { return (struct Struct_ov025_021ebb90_6*)o + n; }

extern "C" ARM void func_ov025_021ebb90(struct Struct_ov025_021e9778_4* obj) {
    struct Struct_ov025_021ebb90_4 params;
    struct Vec3 scale;
    struct Vec3 dir;
    struct Vec3 var3;
    struct Vec3 selfPos;
    struct Vec3 var5;
    struct Vec3 var6;
    struct Struct_ov025_021ebb90_2 rot;
    int counts[6];
    struct Struct_ov025_021ebb90_5 slots[32];

    unsigned char* codes;

    GameState* battle = GameState::GetInstance();
    unsigned char* var12 = (unsigned char*)func_ov000_02160130();
    GameResources* var13 = GetGameResources();

    if (func_ov025_021dcc64(var12) != 0 && func_ov025_021dcc64(var12) < 3) return;
    if (func_ov025_021dcc64(var12) > 5 && func_ov025_021dcc64(var12) < 7) return;

    unsigned int var14 = battle->GetEffectiveDeltaTime();

    if (obj->unknown_301_ != 0 && func_ov000_02162954(var12) != 0) {
        for (int j = 0; j < 12; j++) {
            if (obj->entries[j].a != 0) {
                if (var14 < obj->entries[j].f) obj->entries[j].f -= var14;
                else obj->entries[j].f = 0;
                return;
            }
        }
        return;
    }

    int var16 = 0;
    for (int i = 0; i < 12; i++) {
        if (obj->entries[i].a == 0) continue;
        struct Struct_ov025_021ebb90_6* e = inline_ov025_021ebb90_2(obj, i);

        if ((e->d & 0xf) == 0xf) {
            if (e->f <= e->e || obj->unknown_300_ == 1) {
                if (e->d & 0x80) {
                    if (var12[Enum_ov025_021ebb90_28414] != 4) return;
                    if (func_ov025_021ed2f4(obj->unknown_30c_) == 0) return;
                }
                func_ov025_021ebb24(&obj->entries[i]);
                if (obj->unknown_300_ != 0) obj->unknown_300_--;
                continue;
            }
            obj->entries[i].e += var14;
            return;
        }

        struct Struct_ov000_021600f8* var19 = 0;
        struct Struct_ov000_02160094* node2 = 0;
        if (e->mode == 1) {
            struct Struct_ov000_021600f8* n = func_ov000_021600f8((struct Struct_ov000_0215440c*)obj->entries[i].a, e->idx);
            if (n != 0) var19 = n;
        } else if (e->mode == 0) {
            struct Struct_ov000_02160094* n = func_ov000_02160094((struct Struct_ov000_0215440c_2*)obj->entries[i].a, 0);
            if (n != 0) node2 = n;
        } else if (e->mode == 2 || e->mode == 3) {
            struct Struct_ov000_021600f8* n = func_ov000_021600f8((struct Struct_ov000_0215440c*)obj->entries[i].a, e->idx);
            if (n != 0) var19 = n;
        }

        unsigned int var24 = obj->entries[i].e;
        unsigned int var25 = var14 + obj->entries[i].e;

        if (!(obj->entries[i].d & 0x10)) {
            struct Struct_ov025_021ebb90* row = func_02079e2c((char*)func_020797dc(),
                                                               ((struct Struct_ov000_0215440c*)obj->entries[i].a)->id);
            for (int var27 = 0; var27 < ((struct Struct_ov000_0215440c*)obj->entries[i].a)->count; var27++) {
                struct Struct_ov000_021600f8* node = func_ov000_021600f8((struct Struct_ov000_0215440c*)obj->entries[i].a, var27);
                if (node != 0) {
                    unsigned char found = 0;
                    unsigned char blocked = 0;
                    for (int j = 0; j < node->unknown_17_; j++) {
                        codes = node->codes;
                        if (codes[j] == 7 || codes[j] == 8 || codes[j] == 6) {
                            if (row != 0 && (row->flags >> 28 == 3 || row->flags >> 28 == 4)) {
                                blocked = 1;
                            } else {
                                func_ov000_0216346c((char*)var12, node->unknown_e_[j]);
                                found = 1;
                            }
                        } else if (codes[j] == 1 || codes[j] == 2) {
                            if (found == 0) {
                                if (var12[Enum_ov025_021ebb90_28414] == 0) var12[Enum_ov025_021ebb90_28414] = 1;
                                if (blocked != 0 && obj->entries[i].f != 0) obj->entries[i].d |= 0x80;
                                func_ov000_021634c8((char*)var12, node->unknown_e_[j - 1]);
                                *(short*)(var12 + Enum_ov025_021ebb90_28412) = func_ov000_0215ffa0(node);
                            }
                            obj->unknown_306_ = 1;
                        }
                    }
                }
            }

            if (row == 0 || (row->flags >> 28 != 3 && row->flags >> 28 != 4)) {
                struct Struct_ov000_02160094* n0 = func_ov000_02160094((struct Struct_ov000_0215440c_2*)obj->entries[i].a, 0);
                int var33 = 0;
                if (n0 != 0 && n0 != 0 && inline_ov025_021ebb90(n0->id)) {
                    GameObject* member = func_0200ff1c(battle, n0->id);
                    if (member != 0 &&
                        (func_02085078(*(unsigned char**)((char*)member + Enum_ov025_021ebb90_336)) != 0 ||
                         func_020850a4(*(unsigned char**)((char*)member + Enum_ov025_021ebb90_336)) != 0)) {
                        if (row != 0 && row->flags >> 28 != 2) var33 = 1;
                    }
                }
                if (var19 != 0 && var33 == 0) {
                    for (int j = 1; j < var19->unknown_17_; j++) {
                        unsigned char* codes = var19->codes;
                        if ((codes[j] == 7 || codes[j] == 8 || codes[j] == 6) && func_ov025_021dcc64(var12) == 0) {
                            func_ov025_021dcc58(var12, 1);
                            struct Struct_ov025_021ebb90_6 var37 = obj->entries[i];
                            func_ov025_021ecb90((struct Struct_ov025_021ebb90_6*)(var12 + Enum_ov025_021ebb90_28536), &var37);
                            obj->entries[i].unknown_14_ = 0;
                            obj->entries[i].d |= 0x18;
                            if (obj->unknown_306_ != 0) obj->entries[i].d |= 6;
                            obj->unknown_306_ = 0;
                            var16 = 1;
                        }
                    }
                }
            }
        }

        if (obj->unknown_306_ != 0) {
            struct Struct_ov025_021ebb90_6 var38 = obj->entries[i];
            func_ov025_021ecb90((struct Struct_ov025_021ebb90_6*)(var12 + Enum_ov025_021ebb90_28536), &var38);
            obj->entries[i].unknown_14_ = 0;
            obj->entries[i].d |= 0x10;
            obj->entries[i].d |= 0x08;
            obj->entries[i].d |= 0x04;
            obj->entries[i].d |= 0x02;
        }

        if (!(obj->entries[i].d & 8)) {
            if (obj->unknown_302_ == 1) {
                if (obj->entries[i].a != 0) {
                    int idx = obj->entries[i].idx;
                    int mode = obj->entries[i].mode;
                    int var41 = -1;
                    if (mode == 1) {
                        struct Struct_ov000_021600f8* n = func_ov000_021600f8((struct Struct_ov000_0215440c*)obj->entries[i].a, idx);
                        if (n != 0) var41 = func_ov000_0215ffa0(n);
                    } else if (mode == 0) {
                        struct Struct_ov000_02160094* n = func_ov000_02160094((struct Struct_ov000_0215440c_2*)obj->entries[i].a, idx);
                        if (n != 0) var41 = n->id;
                    }
                    if (var41 >= 0) {
                        func_ov000_0216df00(func_ov000_02160f14(var12), var41, 0, 0, 1.8f);
                        func_ov000_021626a0(var12, 4, 0);
                        GameObject* c2 = battle->GetCombatantByIndex(var41);
                        if (c2 != 0) {
                            ((Object3D*)((unsigned char*)c2))->MakeVisible();
                            func_02049ae4((unsigned char*)c2);
                            if (func_02049ee8((unsigned char*)c2) != 0) {
                                GameObject_ForceMotionState((struct Bytes02033b88*)c2, 0);
                            }
                        }
                        MessageSystem_Stop(MessageSystem_GetInstance());
                        func_0203a588(NumberPopups_GetInstance());
                        func_ov000_02182a44(var12 + Enum_ov025_021ebb90_28668);
                    }
                }
                obj->entries[i].d |= 8;
            } else {
                obj->entries[i].d |= 8;
            }
        }

        if (!(obj->entries[i].d & 2)) {
            int ownerId = -1;
            struct Struct_ov000_02160094* n1 = func_ov000_02160094((struct Struct_ov000_0215440c_2*)obj->entries[i].a, 0);
            if (n1 != 0) ownerId = n1->id;

            if (var24 <= obj->entries[i].g && obj->entries[i].g < var25) {
                int var47 = 0;
                if (var19 != 0) var47 = func_ov000_0215ffa0(var19);
                if (var16 != 0) var47 = var19->unknown_e_[0];

                GameObject* target = battle->GetGameObjectByIndex(var47);
                if (target != 0) {
                    void* var49 = func_02057924();
                    params.targetId = var47;
                    params.unknown_0_ = 0;
                    params.f12 = 0;
                    params.f20[0] = 0;
                    params.f20[1] = 0;
                    params.f20[2] = 0;
                    params.pos.x = 0;
                    params.pos.y = 0;
                    params.pos.z = 0;
                    params.unknown_38_[0] = 0;
                    params.unknown_38_[1] = 0;
                    params.unknown_38_[2] = 0;
                    params.f1c = -0x1000;
                    params.f10 = 1;
                    params.unknown_16_ = -1;
                    params.f18 = -1;
                    params.unknown_1a_ = -1;
                    params.scale.x = 0x1000;
                    params.scale.y = 0x1000;
                    params.flags.bit0 = 0;
                    params.flags.unknown_0_1_ = 0;
                    params.flags.bit2 = 1;
                    params.flags.unknown_0_3_ = 0;
                    params.flags.unknown_0_4_ = 0;
                    params.flags.unknown_0_5_ = 0;
                    params.flags.unknown_0_6_ = 0;
                    params.flags.unknown_0_7_ = 0;
                    params.scale.z = 0x1000;

                    if (obj->entries[i].n & 1) params.pos.y += target->obj3D_.GetHeight() / 2;
                    if (params.pos.y < obj->unknown_304_) params.pos.y = obj->unknown_304_;
                    params.flags.bit2 = 0;

                    int inRange = (var47 >= 0xc0 && var47 <= 0xc7) ? 1 : 0;
                    if (inRange) {
                        if (e->o & 1) {
                            int var51 = 0x1000;
                            switch (e->u) {
                            case 0:
                                var51 = func_ov000_0216352c(var47, e->p / 4096.0f, e->q / 4096.0f);
                                break;
                            case 1:
                                var51 = func_ov000_021635e4(var47, e->p);
                                if (e->q <= var51) var51 = e->q;
                                break;
                            }
                            scale.x = var51;
                            scale.y = var51;
                            scale.z = var51;
                            *(Vector3i*)&params.scale = *(Vector3i const*)&scale;
                        }

                        if (e->o & 2) {
                            int v = e->v;
                            short var53 = 0x1000;
                            switch (v) {
                            case 0:
                                dir.x = e->r;
                                dir.y = e->s;
                                dir.z = e->t;
                                break;
                            case 1:
                            case 4: {
                                dir.z = e->r;
                                float speed = e->s / 4096.0f;
                                var53 = (short)(func_ov000_0216352c(var47, speed, 1.0f) - (int)speed);
                                if (var53 <= 0) var53 = 0;
                                dir.y = 0;
                                dir.x = 0;
                                if (e->t != 0) {
                                    GameObject* owner = battle->GetGameObjectByIndex(ownerId);
                                    GameObject* victim = battle->GetGameObjectByIndex(var47);
                                    if (owner != 0 && victim != 0) {
                                        *(Vector3i*)&selfPos = *(Vector3i const*)((struct Vec3*)((char*)owner + 0x44));
                                        *(Vector3i*)&var3 = *(Vector3i const*)((struct Vec3*)((char*)victim + 0x44));
                                        Vector3fix_Subtract((const Vector3fix*)&selfPos, (const Vector3fix*)&var3, (Vector3fix*)&var5);
                                        Vector3fix_Normalize((const Vector3fix*)&var5, (Vector3fix*)&var5);
                                        Vector3fixMultiplyScalar((Vector3i const*)&var5, dir.z, (Vector3i*)&dir);
                                        *(Vector3i*)&var6 = *(Vector3i const*)((struct Vec3*)((char*)victim + 0x50));
                                        int yaw = -var6.y;
                                        int cosv = (int)(4096.0f * (_ll_sto_f(fix32_CosFx64c(yaw)) / 4294967296.0f));
                                        int sinv = (int)(4096.0f * (_ll_sto_f(fix32_SinFx64c(yaw)) / 4294967296.0f));
                                        Mat3x3_WriteRotationY((Matrix3x3*)&rot, (fix32_t)sinv, (fix32_t)cosv);
                                        Mat3x3_ApplyToVector((const Vector3fix*)&dir, (const Matrix3x3*)&rot, (Vector3fix*)&dir);
                                    }
                                }
                                break;
                            }
                            case 2:
                                var53 = func_ov000_0216352c(var47, 1.0f, 0.5f);
                                dir.x = e->r;
                                dir.y = e->s;
                                dir.z = e->t;
                                break;
                            case 3:
                                var53 = e->r;
                                dir.x = 0;
                                dir.y = 0;
                                dir.z = func_ov000_021635e4(var47, 3);
                                break;
                            }
                            dir.x = FX_MUL_021ebb90(dir.x, var53);
                            dir.y = FX_MUL_021ebb90(dir.y, var53);
                            dir.z = FX_MUL_021ebb90(dir.z, var53);
                            if (v == 4) {
                                params.pos.x += dir.x;
                                params.pos.y += dir.y;
                                params.pos.z += dir.z;
                            } else {
                                *(Vector3i*)&params.pos = *(Vector3i const*)&dir;
                            }
                        }
                    }

                    if (var16 != 0) params.pos.z += 0x2000;
                    if (var12[Enum_ov025_021ebb90_28665] != 0 && func_ov000_02163c0c(var12, var47) != 0) {
                        params.pos.y += 0xe66;
                    }
                    func_02057fb4(var49, obj->entries[i].k, &params);
                }

                if (obj->entries[i].d & 0x20) SetMainBrightness(var13, 0x10, 0xf);
                obj->entries[i].d |= 2;
            }
        }

        if (!(obj->entries[i].d & 4) && var24 <= obj->entries[i].m && obj->entries[i].m < var25) {
            SePlayer_PlayExtra(&g_sePlayer, obj->entries[i].l, 0);
            obj->entries[i].d |= 4;
        }

        unsigned int var60 = obj->entries[i].x;
        unsigned int var61 = var14 + var60;
        __clear(counts, sizeof(counts));
        int* cnt = counts;
        int var63 = 0;
        if (var19 != 0) {
            cnt[0] = var19->counts[0];
            cnt[1] = var19->counts[1];
            cnt[2] = var19->counts[2];
        } else if (node2 != 0) {
            cnt[0] = node2->unknown_26_;
            cnt[1] = node2->f28;
            cnt[2] = node2->unknown_29_;
            cnt[3] = node2->unknown_2b_;
            cnt[4] = node2->unknown_2a_;
            cnt[5] = node2->unknown_27_;
        }
        if (obj->entries[i].c != 6) {
            for (int z = 0; z < 6; z++) {
                if (z != obj->entries[i].c) cnt[z] = 0;
            }
        }

        int var65 = 0;
        for (int var66 = 0; var66 < 6; var66++) {
            for (int k = 0; k < cnt[var66]; k++) {
                slots[var65].idx = k;
                slots[var65].unknown_1_ = var66;
                var65++;
            }
        }

        int var68 = 1;
        if (e->mode == 1) var68 = obj->unknown_311_ == 0;

        if (var65 > 0) {
            for (int cur = obj->entries[i].w; cur < var65; cur++) {
                unsigned int var70 = obj->entries[i].unknown_14_ + cur * obj->entries[i].unknown_18_;
                if (!(var60 <= var70 && var70 < var61)) continue;
                if (func_ov025_021ee438(obj->unknown_30c_, obj->unknown_308_) != 0 || var68 == 0) {
                    obj->unknown_308_ = func_ov025_021d8c30(var12, (void*)obj->entries[i].a, obj->entries[i].mode,
                                                    slots[cur].unknown_1_, obj->entries[i].idx, slots[cur].idx, 0);
                    obj->entries[i].w++;
                    if (obj->entries[i].d & 0x20) {
                        SetMainBrightness(var13, 0, 0xf);
                        obj->entries[i].d &= ~0x20;
                    }
                    if (func_ov025_021ee438(obj->unknown_30c_, obj->unknown_308_) == 0 && var68 != 0) {
                        var63 = 1;
                        break;
                    }
                    obj->unknown_308_ = 0;
                    continue;
                }
                var63 = 1;
                break;
            }
            if (var65 == obj->entries[i].w) {
                if (func_ov025_021ee438(obj->unknown_30c_, obj->unknown_308_) != 0 || (obj->entries[i].d & 0x40) != 0 ||
                    var68 == 0) {
                    obj->entries[i].d |= 1;
                    obj->unknown_308_ = 0;
                    if (obj->unknown_300_ <= 1) obj->unknown_310_ = 1;
                }
            }
        } else {
            obj->entries[i].d |= 1;
        }

        if (var16 != 0 && func_ov025_021dcc64(var12) == 1) func_ov025_021dcf14(var12);

        obj->entries[i].e += var14;
        if (var63 == 0) obj->entries[i].x += var14;
        return;
    }
}
