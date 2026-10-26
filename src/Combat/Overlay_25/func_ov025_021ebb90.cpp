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
    int unknown_0_;
    unsigned char unknown_4_0_ : 6;
    unsigned char unknown_4_6_ : 2;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    int unknown_1c_;
    short unknown_20_;
    short unknown_22_;
    unsigned int unknown_24_;
    int unknown_28_;
    unsigned short unknown_2c_;
    short unknown_2e_;
    short unknown_30_;
    short unknown_32_;
    short unknown_34_;
    short unknown_36_;
    unsigned char unknown_38_;
    unsigned char unknown_39_;
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
};

struct Struct_ov025_021ee438;

struct Struct_ov025_021e9778_4 {
    struct Struct_ov025_021ebb90_6 unknown_0_[12];
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

struct Struct_ov000_0215440c { short unknown_0_; char unknown_2_[7]; unsigned char unknown_9_; };
struct Struct_ov000_021600f8 {
    char unknown_0_[0xe];
    short unknown_e_[3];
    unsigned char unknown_14_[3];
    unsigned char unknown_17_;
    unsigned char unknown_18_[3];
};
struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094 {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
    char unknown_22_[4];
    unsigned char unknown_26_, unknown_27_, unknown_28_, unknown_29_, unknown_2a_, unknown_2b_;
};
struct Struct_ov025_021ebb90 { char unknown_0_[0x14]; unsigned int unknown_14_; };

struct Struct_ov009_0218aa28 { int unknown_0_; int unknown_4_; int unknown_8_; };
struct Struct_ov025_021ebb90_2 { int unknown_0_[9]; };

struct Struct_ov025_021ebb90_3 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char unknown_0_2_ : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov025_021ebb90_4 {
    unsigned char unknown_0_;
    char unknown_1_[0xf];
    unsigned char unknown_10_;
    struct Struct_ov025_021ebb90_3 unknown_11_;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_[3];
    struct Struct_ov009_0218aa28 unknown_2c_;
    int unknown_38_[3];
    struct Struct_ov009_0218aa28 unknown_44_;
};

struct Struct_ov025_021ebb90_5 { unsigned char unknown_0_; unsigned char unknown_1_; };

struct Struct_02010604;
struct Struct_0203a588_2;

void* GetActiveCombatWork_ov000_02160130(void);
unsigned char GetByte_021dcc64_021dcc64(void* obj);
void SetByte_021dcc58(void* obj, unsigned char v);
int CheckCombatantStatusOrTable_02162954(void* self);
int Check021ed2f4(void* obj);
extern "C" void func_ov025_021ebb24(struct Struct021ecb90* obj);
struct ListNode021600f8* GetNodeAtIndex021600f8(struct List021600f8* list, int index);
struct ListNode02160094* GetNodeAtIndex02160094(struct List02160094* list, int index);
struct Row02079e2c* SearchBothTables02079e2c(char* table, int key);
void AppendUniqueShort0216346c(char* obj, int val);
void AppendUniqueShort021634c8(char* obj, int val);
extern "C" short func_ov000_0215ffa0(void* obj);
extern "C" int func_ov025_021d8c30(void* sl_, void* sb_, int kind, int category, int idx, int inner, int flag);
void ClearSubstructFlag0x4_02049ae4(unsigned char* obj);
int GetSubstructByte0x56_02049ee8(unsigned char* obj);
int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
void* MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(void* self);
struct Obj0203a588* NumberPopups_GetInstance(void);
void ResetLowFlagEntries0203a588(struct Obj0203a588* obj);
void ZeroFieldsAt0x6e8_ov000_02182a44(void* obj);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
extern "C" int func_02085078(unsigned char* arg0);
extern "C" int func_020850a4(unsigned char* arg0);
extern "C" void* func_02057924(void);
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);
extern "C" int fix32_CosFx64c(int);
extern "C" int fix32_SinFx64c(int);
extern "C" float _ll_sto_f(int);
short ClampScaledStat_0216352c(int id, float a, float b);
extern "C" int func_ov000_021635e4(int id, unsigned char mode);
int IsCombatantStateSpecial02163c0c(void* unused, int id);
void FindNodeAndProcess02057fb4(void* list, int id, void* config);
void SePlayer_PlayExtra(void* obj, int a, int b);
int IsIdUnique021ee438(struct Ctx021ee438* obj, int id);
extern "C" void func_ov025_021dcf14(void* combatWork);
extern "C" void* func_ov000_02160f14(void* combatWork);
extern "C" void func_ov000_0216df00(void* handle, int a, int b, int c, float scale);
extern "C" void func_ov000_021626a0(void* combatWork, int a, int b);
void CopyStructFields_021ecb90(struct Struct021ecb90* dst, struct Struct021ecb90* src);

extern int g_sePlayer;
extern "C" void __clear(void* dst, unsigned int n);

static inline int inline_ov025_021ebb90(unsigned int arg0) { return arg0 <= 3; }

#define FX_MUL_021ebb90(a, b) ((int)((((long long)(a) * (long long)(b)) + 0x800) >> 12))

// USA: func_ov025_021ebb90
static inline struct Struct_ov025_021ebb90_6* inline_ov025_021ebb90_2(struct Struct_ov025_021e9778_4* arg0, int arg1) { return (struct Struct_ov025_021ebb90_6*)arg0 + arg1; }

extern "C" ARM void func_ov025_021ebb90(struct Struct_ov025_021e9778_4* arg0) {
    struct Struct_ov025_021ebb90_4 var0;
    struct Struct_ov009_0218aa28 var1;
    struct Struct_ov009_0218aa28 var2;
    struct Struct_ov009_0218aa28 var3;
    struct Struct_ov009_0218aa28 var4;
    struct Struct_ov009_0218aa28 var5;
    struct Struct_ov009_0218aa28 var6;
    struct Struct_ov025_021ebb90_2 var7;
    int var8[6];
    struct Struct_ov025_021ebb90_5 var9[32];

    unsigned char* var10;

    GameState* var11 = GameState::GetInstance();
    unsigned char* var12 = (unsigned char*)func_ov000_02160130();
    GameResources* var13 = GetGameResources();

    if (func_ov025_021dcc64(var12) != 0 && func_ov025_021dcc64(var12) < 3) return;
    if (func_ov025_021dcc64(var12) > 5 && func_ov025_021dcc64(var12) < 7) return;

    unsigned int var14 = var11->GetEffectiveDeltaTime();

    if (arg0->unknown_301_ != 0 && func_ov000_02162954(var12) != 0) {
        for (int var15 = 0; var15 < 12; var15++) {
            if (arg0->unknown_0_[var15].unknown_0_ != 0) {
                if (var14 < arg0->unknown_0_[var15].unknown_c_) arg0->unknown_0_[var15].unknown_c_ -= var14;
                else arg0->unknown_0_[var15].unknown_c_ = 0;
                return;
            }
        }
        return;
    }

    int var16 = 0;
    for (int var17 = 0; var17 < 12; var17++) {
        if (arg0->unknown_0_[var17].unknown_0_ == 0) continue;
        struct Struct_ov025_021ebb90_6* var18 = inline_ov025_021ebb90_2(arg0, var17);

        if ((var18->unknown_6_ & 0xf) == 0xf) {
            if (var18->unknown_c_ <= var18->unknown_8_ || arg0->unknown_300_ == 1) {
                if (var18->unknown_6_ & 0x80) {
                    if (var12[Enum_ov025_021ebb90_28414] != 4) return;
                    if (func_ov025_021ed2f4(arg0->unknown_30c_) == 0) return;
                }
                func_ov025_021ebb24(&arg0->unknown_0_[var17]);
                if (arg0->unknown_300_ != 0) arg0->unknown_300_--;
                continue;
            }
            arg0->unknown_0_[var17].unknown_8_ += var14;
            return;
        }

        struct Struct_ov000_021600f8* var19 = 0;
        struct Struct_ov000_02160094* var20 = 0;
        if (var18->unknown_4_6_ == 1) {
            struct Struct_ov000_021600f8* var21 = func_ov000_021600f8((struct Struct_ov000_0215440c*)arg0->unknown_0_[var17].unknown_0_, var18->unknown_4_0_);
            if (var21 != 0) var19 = var21;
        } else if (var18->unknown_4_6_ == 0) {
            struct Struct_ov000_02160094* var22 = func_ov000_02160094((struct Struct_ov000_0215440c_2*)arg0->unknown_0_[var17].unknown_0_, 0);
            if (var22 != 0) var20 = var22;
        } else if (var18->unknown_4_6_ == 2 || var18->unknown_4_6_ == 3) {
            struct Struct_ov000_021600f8* var23 = func_ov000_021600f8((struct Struct_ov000_0215440c*)arg0->unknown_0_[var17].unknown_0_, var18->unknown_4_0_);
            if (var23 != 0) var19 = var23;
        }

        unsigned int var24 = arg0->unknown_0_[var17].unknown_8_;
        unsigned int var25 = var14 + arg0->unknown_0_[var17].unknown_8_;

        if (!(arg0->unknown_0_[var17].unknown_6_ & 0x10)) {
            struct Struct_ov025_021ebb90* var26 = func_02079e2c((char*)func_020797dc(),
                                                               ((struct Struct_ov000_0215440c*)arg0->unknown_0_[var17].unknown_0_)->unknown_0_);
            for (int var27 = 0; var27 < ((struct Struct_ov000_0215440c*)arg0->unknown_0_[var17].unknown_0_)->unknown_9_; var27++) {
                struct Struct_ov000_021600f8* var28 = func_ov000_021600f8((struct Struct_ov000_0215440c*)arg0->unknown_0_[var17].unknown_0_, var27);
                if (var28 != 0) {
                    unsigned char var29 = 0;
                    unsigned char var30 = 0;
                    for (int var31 = 0; var31 < var28->unknown_17_; var31++) {
                        var10 = var28->unknown_14_;
                        if (var10[var31] == 7 || var10[var31] == 8 || var10[var31] == 6) {
                            if (var26 != 0 && (var26->unknown_14_ >> 28 == 3 || var26->unknown_14_ >> 28 == 4)) {
                                var30 = 1;
                            } else {
                                func_ov000_0216346c((char*)var12, var28->unknown_e_[var31]);
                                var29 = 1;
                            }
                        } else if (var10[var31] == 1 || var10[var31] == 2) {
                            if (var29 == 0) {
                                if (var12[Enum_ov025_021ebb90_28414] == 0) var12[Enum_ov025_021ebb90_28414] = 1;
                                if (var30 != 0 && arg0->unknown_0_[var17].unknown_c_ != 0) arg0->unknown_0_[var17].unknown_6_ |= 0x80;
                                func_ov000_021634c8((char*)var12, var28->unknown_e_[var31 - 1]);
                                *(short*)(var12 + Enum_ov025_021ebb90_28412) = func_ov000_0215ffa0(var28);
                            }
                            arg0->unknown_306_ = 1;
                        }
                    }
                }
            }

            if (var26 == 0 || (var26->unknown_14_ >> 28 != 3 && var26->unknown_14_ >> 28 != 4)) {
                struct Struct_ov000_02160094* var32 = func_ov000_02160094((struct Struct_ov000_0215440c_2*)arg0->unknown_0_[var17].unknown_0_, 0);
                int var33 = 0;
                if (var32 != 0 && var32 != 0 && inline_ov025_021ebb90(var32->unknown_20_)) {
                    GameObject* var34 = func_0200ff1c(var11, var32->unknown_20_);
                    if (var34 != 0 &&
                        (func_02085078(*(unsigned char**)((char*)var34 + Enum_ov025_021ebb90_336)) != 0 ||
                         func_020850a4(*(unsigned char**)((char*)var34 + Enum_ov025_021ebb90_336)) != 0)) {
                        if (var26 != 0 && var26->unknown_14_ >> 28 != 2) var33 = 1;
                    }
                }
                if (var19 != 0 && var33 == 0) {
                    for (int var35 = 1; var35 < var19->unknown_17_; var35++) {
                        unsigned char* var36 = var19->unknown_14_;
                        if ((var36[var35] == 7 || var36[var35] == 8 || var36[var35] == 6) && func_ov025_021dcc64(var12) == 0) {
                            func_ov025_021dcc58(var12, 1);
                            struct Struct_ov025_021ebb90_6 var37 = arg0->unknown_0_[var17];
                            func_ov025_021ecb90((struct Struct_ov025_021ebb90_6*)(var12 + Enum_ov025_021ebb90_28536), &var37);
                            arg0->unknown_0_[var17].unknown_14_ = 0;
                            arg0->unknown_0_[var17].unknown_6_ |= 0x18;
                            if (arg0->unknown_306_ != 0) arg0->unknown_0_[var17].unknown_6_ |= 6;
                            arg0->unknown_306_ = 0;
                            var16 = 1;
                        }
                    }
                }
            }
        }

        if (arg0->unknown_306_ != 0) {
            struct Struct_ov025_021ebb90_6 var38 = arg0->unknown_0_[var17];
            func_ov025_021ecb90((struct Struct_ov025_021ebb90_6*)(var12 + Enum_ov025_021ebb90_28536), &var38);
            arg0->unknown_0_[var17].unknown_14_ = 0;
            arg0->unknown_0_[var17].unknown_6_ |= 0x10;
            arg0->unknown_0_[var17].unknown_6_ |= 0x08;
            arg0->unknown_0_[var17].unknown_6_ |= 0x04;
            arg0->unknown_0_[var17].unknown_6_ |= 0x02;
        }

        if (!(arg0->unknown_0_[var17].unknown_6_ & 8)) {
            if (arg0->unknown_302_ == 1) {
                if (arg0->unknown_0_[var17].unknown_0_ != 0) {
                    int var39 = arg0->unknown_0_[var17].unknown_4_0_;
                    int var40 = arg0->unknown_0_[var17].unknown_4_6_;
                    int var41 = -1;
                    if (var40 == 1) {
                        struct Struct_ov000_021600f8* var42 = func_ov000_021600f8((struct Struct_ov000_0215440c*)arg0->unknown_0_[var17].unknown_0_, var39);
                        if (var42 != 0) var41 = func_ov000_0215ffa0(var42);
                    } else if (var40 == 0) {
                        struct Struct_ov000_02160094* var43 = func_ov000_02160094((struct Struct_ov000_0215440c_2*)arg0->unknown_0_[var17].unknown_0_, var39);
                        if (var43 != 0) var41 = var43->unknown_20_;
                    }
                    if (targetId2 >= 0) {
                        func_ov000_0216df00(func_ov000_02160f14(cw), targetId2, 0, 0, 1.8f);
                        func_ov000_021626a0(cw, 4, 0);
                        GameObject* c2 = battle->GetCombatantByIndex(targetId2);
                        if (c2 != 0) {
                            ((Object3D*)((unsigned char*)c2))->MakeVisible();
                            ClearSubstructFlag0x4_02049ae4((unsigned char*)c2);
                            if (GetSubstructByte0x56_02049ee8((unsigned char*)c2) != 0) {
                                GameObject_ForceMotionState((struct Bytes02033b88*)c2, 0);
                            }
                        }
                        MessageSystem_Stop(MessageSystem_GetInstance());
                        ResetLowFlagEntries0203a588(NumberPopups_GetInstance());
                        ZeroFieldsAt0x6e8_ov000_02182a44(cw + Field6ffc);
                    }
                }
                arg0->unknown_0_[var17].unknown_6_ |= 8;
            } else {
                arg0->unknown_0_[var17].unknown_6_ |= 8;
            }
        }

        if (!(arg0->unknown_0_[var17].unknown_6_ & 2)) {
            int var45 = -1;
            struct Struct_ov000_02160094* var46 = func_ov000_02160094((struct Struct_ov000_0215440c_2*)arg0->unknown_0_[var17].unknown_0_, 0);
            if (var46 != 0) var45 = var46->unknown_20_;

            if (var24 <= arg0->unknown_0_[var17].unknown_10_ && arg0->unknown_0_[var17].unknown_10_ < var25) {
                int var47 = 0;
                if (var19 != 0) var47 = func_ov000_0215ffa0(var19);
                if (var16 != 0) var47 = var19->unknown_e_[0];

                GameObject* var48 = var11->GetGameObjectByIndex(var47);
                if (var48 != 0) {
                    void* var49 = func_02057924();
                    var0.unknown_14_ = var47;
                    var0.unknown_0_ = 0;
                    var0.unknown_12_ = 0;
                    var0.unknown_20_[0] = 0;
                    var0.unknown_20_[1] = 0;
                    var0.unknown_20_[2] = 0;
                    var0.unknown_2c_.unknown_0_ = 0;
                    var0.unknown_2c_.unknown_4_ = 0;
                    var0.unknown_2c_.unknown_8_ = 0;
                    var0.unknown_38_[0] = 0;
                    var0.unknown_38_[1] = 0;
                    var0.unknown_38_[2] = 0;
                    var0.unknown_1c_ = -0x1000;
                    var0.unknown_10_ = 1;
                    var0.unknown_16_ = -1;
                    var0.unknown_18_ = -1;
                    var0.unknown_1a_ = -1;
                    var0.unknown_44_.unknown_0_ = 0x1000;
                    var0.unknown_44_.unknown_4_ = 0x1000;
                    var0.unknown_11_.unknown_0_0_ = 0;
                    var0.unknown_11_.unknown_0_1_ = 0;
                    var0.unknown_11_.unknown_0_2_ = 1;
                    var0.unknown_11_.unknown_0_3_ = 0;
                    var0.unknown_11_.unknown_0_4_ = 0;
                    var0.unknown_11_.unknown_0_5_ = 0;
                    var0.unknown_11_.unknown_0_6_ = 0;
                    var0.unknown_11_.unknown_0_7_ = 0;
                    var0.unknown_44_.unknown_8_ = 0x1000;

                    if (arg0->unknown_0_[var17].unknown_28_ & 1) var0.unknown_2c_.unknown_4_ += var48->obj3D_.GetHeight() / 2;
                    if (var0.unknown_2c_.unknown_4_ < arg0->unknown_304_) var0.unknown_2c_.unknown_4_ = arg0->unknown_304_;
                    var0.unknown_11_.unknown_0_2_ = 0;

                    int var50 = (var47 >= 0xc0 && var47 <= 0xc7) ? 1 : 0;
                    if (var50) {
                        if (var18->unknown_2c_ & 1) {
                            int var51 = 0x1000;
                            switch (var18->unknown_38_) {
                            case 0:
                                var51 = func_ov000_0216352c(var47, var18->unknown_2e_ / 4096.0f, var18->unknown_30_ / 4096.0f);
                                break;
                            case 1:
                                var51 = func_ov000_021635e4(var47, var18->unknown_2e_);
                                if (var18->unknown_30_ <= var51) var51 = var18->unknown_30_;
                                break;
                            }
                            var1.unknown_0_ = var51;
                            var1.unknown_4_ = var51;
                            var1.unknown_8_ = var51;
                            *(Vector3i*)&var0.unknown_44_ = *(Vector3i const*)&var1;
                        }

                        if (var18->unknown_2c_ & 2) {
                            int var52 = var18->unknown_39_;
                            short var53 = 0x1000;
                            switch (var52) {
                            case 0:
                                var2.unknown_0_ = var18->unknown_32_;
                                var2.unknown_4_ = var18->unknown_34_;
                                var2.unknown_8_ = var18->unknown_36_;
                                break;
                            case 1:
                            case 4: {
                                dir.z = e->r;
                                float speed = e->s / 4096.0f;
                                sf = (short)(ClampScaledStat_0216352c(targetId3, speed, 1.0f) - (int)speed);
                                if (sf <= 0) sf = 0;
                                dir.y = 0;
                                dir.x = 0;
                                if (e->t != 0) {
                                    GameObject* owner = battle->GetGameObjectByIndex(ownerId);
                                    GameObject* victim = battle->GetGameObjectByIndex(targetId3);
                                    if (owner != 0 && victim != 0) {
                                        *(Vector3i*)&selfPos = *(Vector3i const*)((struct Vec3*)((char*)owner + 0x44));
                                        *(Vector3i*)&targetPos = *(Vector3i const*)((struct Vec3*)((char*)victim + 0x44));
                                        Vector3fix_Subtract((const Vector3fix*)&selfPos, (const Vector3fix*)&targetPos, (Vector3fix*)&toTarget);
                                        Vector3fix_Normalize((const Vector3fix*)&toTarget, (Vector3fix*)&toTarget);
                                        Vector3fixMultiplyScalar((Vector3i const*)&toTarget, dir.z, (Vector3i*)&dir);
                                        *(Vector3i*)&targetRot = *(Vector3i const*)((struct Vec3*)((char*)victim + 0x50));
                                        int yaw = -targetRot.y;
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
                                var2.unknown_0_ = var18->unknown_32_;
                                var2.unknown_4_ = var18->unknown_34_;
                                var2.unknown_8_ = var18->unknown_36_;
                                break;
                            case 3:
                                var53 = var18->unknown_32_;
                                var2.unknown_0_ = 0;
                                var2.unknown_4_ = 0;
                                var2.unknown_8_ = func_ov000_021635e4(var47, 3);
                                break;
                            }
                            var2.unknown_0_ = FX_MUL_021ebb90(var2.unknown_0_, var53);
                            var2.unknown_4_ = FX_MUL_021ebb90(var2.unknown_4_, var53);
                            var2.unknown_8_ = FX_MUL_021ebb90(var2.unknown_8_, var53);
                            if (var52 == 4) {
                                var0.unknown_2c_.unknown_0_ += var2.unknown_0_;
                                var0.unknown_2c_.unknown_4_ += var2.unknown_4_;
                                var0.unknown_2c_.unknown_8_ += var2.unknown_8_;
                            } else {
                                *(Vector3i*)&var0.unknown_2c_ = *(Vector3i const*)&var2;
                            }
                        }
                    }

                    if (var16 != 0) var0.unknown_2c_.unknown_8_ += 0x2000;
                    if (var12[Enum_ov025_021ebb90_28665] != 0 && func_ov000_02163c0c(var12, var47) != 0) {
                        var0.unknown_2c_.unknown_4_ += 0xe66;
                    }
                    func_02057fb4(var49, arg0->unknown_0_[var17].unknown_20_, &var0);
                }

                if (arg0->unknown_0_[var17].unknown_6_ & 0x20) SetMainBrightness(var13, 0x10, 0xf);
                arg0->unknown_0_[var17].unknown_6_ |= 2;
            }
        }

        if (!(obj->entries[i].d & 4) && sp14 <= obj->entries[i].m && obj->entries[i].m < sp4c) {
            SePlayer_PlayExtra(&g_sePlayer, obj->entries[i].l, 0);
            obj->entries[i].d |= 4;
        }

        unsigned int var60 = arg0->unknown_0_[var17].unknown_3c_;
        unsigned int var61 = var14 + var60;
        __clear(var8, sizeof(var8));
        int* var62 = var8;
        int var63 = 0;
        if (var19 != 0) {
            var62[0] = var19->unknown_18_[0];
            var62[1] = var19->unknown_18_[1];
            var62[2] = var19->unknown_18_[2];
        } else if (var20 != 0) {
            var62[0] = var20->unknown_26_;
            var62[1] = var20->unknown_28_;
            var62[2] = var20->unknown_29_;
            var62[3] = var20->unknown_2b_;
            var62[4] = var20->unknown_2a_;
            var62[5] = var20->unknown_27_;
        }
        if (arg0->unknown_0_[var17].unknown_5_ != 6) {
            for (int var64 = 0; var64 < 6; var64++) {
                if (var64 != arg0->unknown_0_[var17].unknown_5_) var62[var64] = 0;
            }
        }

        int var65 = 0;
        for (int var66 = 0; var66 < 6; var66++) {
            for (int var67 = 0; var67 < var62[var66]; var67++) {
                var9[var65].unknown_0_ = var67;
                var9[var65].unknown_1_ = var66;
                var65++;
            }
        }

        int var68 = 1;
        if (var18->unknown_4_6_ == 1) var68 = arg0->unknown_311_ == 0;

        if (var65 > 0) {
            for (int var69 = arg0->unknown_0_[var17].unknown_3a_; var69 < var65; var69++) {
                unsigned int var70 = arg0->unknown_0_[var17].unknown_14_ + var69 * arg0->unknown_0_[var17].unknown_18_;
                if (!(var60 <= var70 && var70 < var61)) continue;
                if (func_ov025_021ee438(arg0->unknown_30c_, arg0->unknown_308_) != 0 || var68 == 0) {
                    arg0->unknown_308_ = func_ov025_021d8c30(var12, (void*)arg0->unknown_0_[var17].unknown_0_, arg0->unknown_0_[var17].unknown_4_6_,
                                                    var9[var69].unknown_1_, arg0->unknown_0_[var17].unknown_4_0_, var9[var69].unknown_0_, 0);
                    arg0->unknown_0_[var17].unknown_3a_++;
                    if (arg0->unknown_0_[var17].unknown_6_ & 0x20) {
                        SetMainBrightness(var13, 0, 0xf);
                        arg0->unknown_0_[var17].unknown_6_ &= ~0x20;
                    }
                    if (func_ov025_021ee438(arg0->unknown_30c_, arg0->unknown_308_) == 0 && var68 != 0) {
                        var63 = 1;
                        break;
                    }
                    arg0->unknown_308_ = 0;
                    continue;
                }
                var63 = 1;
                break;
            }
            if (var65 == arg0->unknown_0_[var17].unknown_3a_) {
                if (func_ov025_021ee438(arg0->unknown_30c_, arg0->unknown_308_) != 0 || (arg0->unknown_0_[var17].unknown_6_ & 0x40) != 0 ||
                    var68 == 0) {
                    arg0->unknown_0_[var17].unknown_6_ |= 1;
                    arg0->unknown_308_ = 0;
                    if (arg0->unknown_300_ <= 1) arg0->unknown_310_ = 1;
                }
            }
        } else {
            arg0->unknown_0_[var17].unknown_6_ |= 1;
        }

        if (var16 != 0 && func_ov025_021dcc64(var12) == 1) func_ov025_021dcf14(var12);

        arg0->unknown_0_[var17].unknown_8_ += var14;
        if (var63 == 0) arg0->unknown_0_[var17].unknown_3c_ += var14;
        return;
    }
}
