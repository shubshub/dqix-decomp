#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "NitroSDK/Matrix.h"

#if defined(jpn)
enum { Enum_ov025_021dcf14_3096 = 0xb94, Enum_ov025_021dcf14_3208 = 0xc04, Enum_ov025_021dcf14_2864 = 0xaac, Enum_ov025_021dcf14_2192 = 0x80c, Enum_ov025_021dcf14_680 = 0x224, Enum_ov025_021dcf14_3640 = 0xdb4, Enum_ov025_021dcf14_28536 = 0x7168, Enum_ov025_021dcf14_24576 = 0x7000, Enum_ov025_021dcf14_3852 = 0xfc, Enum_ov025_021dcf14_28235 = 0x703b, Enum_ov025_021dcf14_28236 = 0x703c, Enum_ov025_021dcf14_28237 = 0x703d, Enum_ov025_021dcf14_28238 = 0x703e, Enum_ov025_021dcf14_28240 = 0x7040, Enum_ov025_021dcf14_28270 = 0x705e, Enum_ov025_021dcf14_28400 = 0x70e0, Enum_ov025_021dcf14_28410 = 0x70ea, Enum_ov025_021dcf14_28412 = 0x70ec, Enum_ov025_021dcf14_28414 = 0x70ee, Enum_ov025_021dcf14_28415 = 0x70ef, Enum_ov025_021dcf14_28416 = 0x70f0, Enum_ov025_021dcf14_28417 = 0x70f1, Enum_ov025_021dcf14_28418 = 0x70f2, Enum_ov025_021dcf14_28420 = 0x70f4, Enum_ov025_021dcf14_28424 = 0x70f8, Enum_ov025_021dcf14_28436 = 0x7104, Enum_ov025_021dcf14_28548 = 0x7174, Enum_ov025_021dcf14_28556 = 0x717c, Enum_ov025_021dcf14_28568 = 0x7188, Enum_ov025_021dcf14_28570 = 0x718a, Enum_ov025_021dcf14_28576 = 0x7190, Enum_ov025_021dcf14_28602 = 0x71aa, Enum_ov025_021dcf14_28612 = 0x71b4, Enum_ov025_021dcf14_28616 = 0x71b8, Enum_ov025_021dcf14_28620 = 0x71bc, Enum_ov025_021dcf14_28624 = 0x71c0, Enum_ov025_021dcf14_30533 = 0x7935, Enum_ov025_021dcf14_30534 = 0x7936 };
#else
enum { Enum_ov025_021dcf14_3096 = 0xc18, Enum_ov025_021dcf14_3208 = 0xc88, Enum_ov025_021dcf14_2864 = 0xb30, Enum_ov025_021dcf14_2192 = 0x890, Enum_ov025_021dcf14_680 = 0x2a8, Enum_ov025_021dcf14_3640 = 0xe38, Enum_ov025_021dcf14_28536 = 0x6f78, Enum_ov025_021dcf14_24576 = 0x6000, Enum_ov025_021dcf14_3852 = 0xf0c, Enum_ov025_021dcf14_28235 = 0x6e4b, Enum_ov025_021dcf14_28236 = 0x6e4c, Enum_ov025_021dcf14_28237 = 0x6e4d, Enum_ov025_021dcf14_28238 = 0x6e4e, Enum_ov025_021dcf14_28240 = 0x6e50, Enum_ov025_021dcf14_28270 = 0x6e6e, Enum_ov025_021dcf14_28400 = 0x6ef0, Enum_ov025_021dcf14_28410 = 0x6efa, Enum_ov025_021dcf14_28412 = 0x6efc, Enum_ov025_021dcf14_28414 = 0x6efe, Enum_ov025_021dcf14_28415 = 0x6eff, Enum_ov025_021dcf14_28416 = 0x6f00, Enum_ov025_021dcf14_28417 = 0x6f01, Enum_ov025_021dcf14_28418 = 0x6f02, Enum_ov025_021dcf14_28420 = 0x6f04, Enum_ov025_021dcf14_28424 = 0x6f08, Enum_ov025_021dcf14_28436 = 0x6f14, Enum_ov025_021dcf14_28548 = 0x6f84, Enum_ov025_021dcf14_28556 = 0x6f8c, Enum_ov025_021dcf14_28568 = 0x6f98, Enum_ov025_021dcf14_28570 = 0x6f9a, Enum_ov025_021dcf14_28576 = 0x6fa0, Enum_ov025_021dcf14_28602 = 0x6fba, Enum_ov025_021dcf14_28612 = 0x6fc4, Enum_ov025_021dcf14_28616 = 0x6fc8, Enum_ov025_021dcf14_28620 = 0x6fcc, Enum_ov025_021dcf14_28624 = 0x6fd0, Enum_ov025_021dcf14_30533 = 0x7745, Enum_ov025_021dcf14_30534 = 0x7746 };
#endif

struct Struct_ov025_021dcf14 {
    char unknown_0_[4];
    int unknown_4_;
    char unknown_8_[4];
    int unknown_c_;
    char unknown_10_[8];
    short unknown_18_;
    short unknown_1a_;
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
};

struct Struct_ov025_021dcf14_2 {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
    char unknown_22_[4];
    unsigned char unknown_26_[6];
};

struct Struct_ov025_021dcf14_3 {
    char unknown_0_[0xe];
    short unknown_e_[3];
    unsigned char unknown_14_[3];
    unsigned char unknown_17_;
    unsigned char unknown_18_[3];
};

struct Struct_ov025_021dcf14_4 {
    char unknown_0_[0x18];
    unsigned int unknown_18_0_ : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
};

struct Struct_ov025_021dcf14_5 {
    int unknown_0_;
    int unknown_4_;
    short unknown_8_;
    short unknown_a_;
    union {
        Vector3fix unknown_c_;
        short unknown1_c_;
    };
    void* unknown_18_;
};

struct Struct_ov025_021dcf14_6 {
    char unknown_0_[0x20];
    short unknown_20_;
    char unknown_22_[6];
    unsigned int unknown_28_;
    char unknown_2c_[0x14];
};

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    Vector3fix unknown_2c_;
    Vector3fix unknown_38_;
    Vector3fix unknown_44_;
};

struct SePlayer;

extern "C" void* __clear(void* arg0, int arg1);
extern "C" void func_ov000_0216d370(void* arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov000_0216df00(void* arg0, int arg1, int arg2, int arg3, float arg4);
struct Struct_ov000_02163a7c;
extern "C" void func_ov000_02163a7c(Struct_ov000_02163a7c*);
extern "C" void* func_ov000_02160f20(void* arg0);
extern "C" void func_0202e694(void*, int*);
extern "C" void func_ov000_021626a0(void* arg0, int arg1, int arg2);
struct Vector3i;
extern "C" void func_ov000_02167f10(void* obj);
struct Obj02033874;
void SetVecYFromValue02033874(Obj02033874*, int);
void ResetFields_021de110(void* obj);
struct Obj021eee48;
struct Rec021eee48;
void PushNodeFromFreeList_021eee48(Obj021eee48*, Rec021eee48*);
struct Flags02033fcc;
void SetFlag0x4At0xe0(Flags02033fcc*);
struct Flags02033fdc;
void ClearFlag0x4At0xe0(Flags02033fdc*);
struct Bytes02033b88;
int SetByte0xbeShiftPrev(Bytes02033b88*, int);
struct TableEntry021dcf14* SearchBothTables02079e2c(char*, int);
struct List021600f8;
struct Node021dcf14* GetNodeAtIndex021600f8(List021600f8*, int);
struct List02160094;
struct First021dcf14* GetNodeAtIndex02160094(List02160094*, int);
struct PackedFields_021d8bfc;
void ForwardPackedFields_021d8bfc(void*, PackedFields_021d8bfc*);
extern "C" int func_ov025_021ed444(void* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
void StoreFields0x1e4And0x1e8IfNonZero_0202ea10(unsigned char*, int, int);
void SetShortTriple0x6e44_ov000_02163440(void* obj, short a, unsigned short b, unsigned short c);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void* FindNodeAtDepth0215fff4(void*, int, int);
extern "C" int func_ov000_0215fd90(void* entry, int effect);
int CheckSubstructFlag0x100_02048c68(unsigned char*);
int GetSubstructByte0x56_02049ee8(unsigned char*);
void SetSubstructFlag0x400_0204a0c8(unsigned char*);
extern "C" int func_ov000_0215ffa0(void* node);
struct In021dce7c;
int TryDispatch_021dce7c(unsigned char*, In021dce7c*, int);
extern "C" void* func_02057924(void);
extern "C" void func_02078484(struct Struct_02078398_2* arg0);
extern "C" void func_02057fb4(void*, int, void*);
extern "C" void func_0205ebfc(void*, int, int);
extern "C" void func_ov025_021eabd0(void* arg0, bool arg1);
extern "C" void func_ov025_021ead5c(void* arg0, bool arg1);

extern Vector3fix data_ov025_021eeed4;
extern char data_ov025_021ef460[];
struct Struct_ov025_021dbe10 {
    int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
};
inline struct Struct_ov025_021dbe10& inline_ov025_021dcf14() {
    static struct Struct_ov025_021dbe10 s;
    return s;
}
extern struct SePlayer g_sePlayer;
extern Vector3fix data_ov025_021eeee0;
extern int data_ov025_021eeeec[];
extern int data_ov025_021eeef8[];

#define TIMER (inline_ov025_021dcf14().unknown_4_)

static inline void inline_ov025_021dcf14_2(unsigned char* arg0, int arg1, unsigned short arg2) {
    TIMER = arg2;
    arg0[Enum_ov025_021dcf14_28235] = arg1;
}

static inline int inline_ov000_02169850(int arg0) {
    return arg0 >= 0 && arg0 <= 3;
}

static inline struct Struct_ov025_021dcf14_6 inline_ov025_021dcf14_3(unsigned char* arg0) {
    return *(struct Struct_ov025_021dcf14_6*)(arg0 + Enum_ov025_021dcf14_28536);
}

// USA: func_ov025_021dcf14
extern "C" ARM int func_ov025_021dcf14(unsigned char* arg0) {
    GameState* var0 = GameState::GetInstance();
    struct Struct_ov025_021dcf14* var1;
    GameObject* var2[5];

    if (arg0[Enum_ov025_021dcf14_28235] != 0) {
        unsigned int var3 = var0->GetEffectiveDeltaTime();
        struct Struct_ov025_021dcf14* var4 = (struct Struct_ov025_021dcf14*)(arg0 + Enum_ov025_021dcf14_28240);
        for (int var5 = 0; var5 < arg0[Enum_ov025_021dcf14_28237]; var5++, var4++) {
            if (var3 < var4->unknown_1e_) {
                var4->unknown_1e_ -= var3;
            } else {
                var4->unknown_1e_ = 0;
            }
            var4->unknown_1c_ += var3;
        }
    }

    var1 = (struct Struct_ov025_021dcf14*)(arg0 + Enum_ov025_021dcf14_28240) + arg0[Enum_ov025_021dcf14_28236];
    __clear(var2, sizeof(var2));

    if (arg0[Enum_ov025_021dcf14_28235] == 0) {
        return 0;
    }

    if (arg0[Enum_ov025_021dcf14_28235] == 1) {
        func_ov000_0216d370(arg0 + Enum_ov025_021dcf14_3096, 1, 1, 1);
        func_ov000_0216df00(arg0 + Enum_ov025_021dcf14_3096, var1->unknown_1a_, 0, 0, 1.8f);
        func_ov000_02163a7c((Struct_ov000_02163a7c*)arg0);
        void* var6 = func_ov000_02160f20(arg0);
        if (*(unsigned short*)var6 == 0x11b || *(unsigned short*)var6 == 0x116) {
            Vector3fix var7 = *(Vector3fix*)(arg0 + Enum_ov025_021dcf14_3208);
            var7.z = 0x847a;
            func_0202e694(arg0 + Enum_ov025_021dcf14_3096, (int*)&var7);
        }
        func_ov000_021626a0(arg0, 4, 0);
        for (int var8 = 0; var8 < *(short*)(arg0 + Enum_ov025_021dcf14_28410); var8++) {
            GameObject* var9 = var0->GetCombatantByIndex(((short*)(arg0 + Enum_ov025_021dcf14_28400))[var8]);
            var2[var8] = var9;
            if (var9) {
                var9->obj3D_.MakeVisible();
            }
        }

        GameObject* var10 = var0->GetCombatantByIndex(var1->unknown_1a_);
        if (var10) {
            var10->obj3D_.MakeVisible();
        }
        Vector3fix var11;
        if (var10) {
            var11 = var10->obj3D_.position_;
        }
        func_ov000_02167f10(arg0);
        if (var10) {
            var10->obj3D_.position_ = var11;
            int var12 = var10->obj3D_.GetRadius();
            Vector3fix var13;
            __clear(&var13, sizeof(var13));
            var13.x = var12 / 4;
            var13.z = var12;
            if (*(short*)(arg0 + Enum_ov025_021dcf14_28410) >= 2) {
                if (*(short*)(arg0 + Enum_ov025_021dcf14_28410) == 4) {
                    var13.x = var12 + var12 / 8;
                }
                var13.x = (int)(4096.0f * (0.6f * (var12 / 4096.0f)));
            }

            int var14 = 0;
            for (int var15 = 0; var15 < *(short*)(arg0 + Enum_ov025_021dcf14_28410); var15++) {
                GameObject* var16 = var2[var15];
                if (var16 == NULL) {
                    continue;
                }
                Vector3fix var17 = var13;
                Vector3fix var18 = data_ov025_021eeed4;
                if (*(short*)(arg0 + Enum_ov025_021dcf14_28410) >= 3) {
                    if (*(short*)(arg0 + Enum_ov025_021dcf14_28410) == 4) {
                        if (var15 >= 2) {
                            var17.x = (int)(4096.0f * (0.2f * (var12 / 4096.0f)));
                            var17.z = var12 + var14 / 2;
                        }
                    } else if (var15 == 2) {
                        var17.x = 0;
                        var17.z = var12 + var14 / 2;
                    }
                }
                if (var14 < var16->obj3D_.GetRadius()) {
                    var14 = var2[var15]->obj3D_.GetRadius();
                }
                if (var15 % 2 != 0) {
                    var17.x = -var17.x;
                    var18.x = -var18.x;
                }
                Matrix4x3 var19 = RotationMatrixY(var10->obj3D_.rotation_.y);
                Mat4x3_ApplyToVector(&var17, &var19, &var17);
                Vector3fix var20 = var2[var15]->obj3D_.position_;
                Vector3fix var21 = var10->obj3D_.position_;
                Vector3fix_Add(&var21, &var17, &var20);
                Matrix4x3 var22 = RotationMatrixY(var10->obj3D_.rotation_.y);
                Mat4x3_ApplyToVector(&var18, &var22, &var18);
                Vector3fix var23;
                Vector3fix_Add(&var20, &var18, &var23);
                Vector3fix var24;
                Vector3fix_Subtract(&var20, &var23, &var24);
                Vector3fix_Normalize(&var24, &var24);
                int var25 = fix32_Atan2(var24.x, var24.z);
                var2[var15]->obj3D_.position_ = var23;
                func_02033874((Struct_02033834*)var2[var15], var25);
                struct Struct_ov025_021dcf14_5 var26;
                func_ov025_021de110(&var26);
                var26.unknown_0_ = 0;
                var26.unknown_8_ = ((short*)(arg0 + Enum_ov025_021dcf14_28400))[var15];
                var26.unknown_a_ = 0x96;
                var26.unknown_c_ = var20;
                func_ov025_021eee48((Struct_ov025_021dcf14_7*)(arg0 + Enum_ov025_021dcf14_2864), (Struct_ov025_021dcf14_8*)&var26);
                var2[var15]->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef460, 0);
                func_02033fcc((Struct_02033fcc*)var2[var15]);
            }
        }

        int var27 = 0;
        for (int var28 = 0; var28 < *(short*)(arg0 + Enum_ov025_021dcf14_28410); var28++) {
            GameObject* var29 = var0->GetCombatantByIndex(((short*)(arg0 + Enum_ov025_021dcf14_28400))[var28]);
            if (var29 && var27 < var29->obj3D_.GetHeight()) {
                var27 = var29->obj3D_.GetHeight();
            }
        }
        if (var27 >= 0x1800) {
            float var30 = 1.0f + 0.8f * (var27 / 4096.0f - 1.5f) / 2.5f;
            if (var30 >= 1.8f) {
                var30 = 1.8f;
            }
            Vector3fix var31 = *(Vector3fix*)(arg0 + Enum_ov025_021dcf14_3208);
            var31.z = (int)(4096.0f * (var31.z / 4096.0f * var30));
            func_0202e694(arg0 + Enum_ov025_021dcf14_3096, (int*)&var31);
        }
        inline_ov025_021dcf14_2(arg0, 2, 0x9b);
    } else if (arg0[Enum_ov025_021dcf14_28235] == 2) {
        unsigned int var32 = var0->GetEffectiveDeltaTime();
        if (var32 < TIMER) {
            TIMER -= var32;
        } else {
            TIMER = 0;
            for (int var33 = 0; var33 < *(short*)(arg0 + Enum_ov025_021dcf14_28410); var33++) {
                var2[var33] = var0->GetCombatantByIndex(((short*)(arg0 + Enum_ov025_021dcf14_28400))[var33]);
            }
            int var34 = 0;
            int var35;
            for (var35 = 0; var35 < *(short*)(arg0 + Enum_ov025_021dcf14_28410); var35++) {
                if (var2[var35] == NULL) {
                    continue;
                }
                if (var34 < var2[var35]->obj3D_.GetHeight()) {
                    var34 = var2[var35]->obj3D_.GetHeight();
                }
                int var36 = 0x1922;
                if (var35 % 2 != 0) {
                    var36 = -0x1922;
                }
                int var37 = var2[var35]->obj3D_.rotation_.y;
                func_02033874((Struct_02033834*)var2[var35], fix32ReduceAngle0To2Pi(var37 + var36));
                func_02033b88((Struct_02010604*)var2[var35], 0);
            }
            float var38 = 1.0f;
            if (var34 >= 0x1800) {
                var38 = var38 + 0.8f * (var34 / 4096.0f - 1.5f) / 2.5f;
                if (var38 >= 1.8f) {
                    var38 = 1.8f;
                }
            }
            Vector3fix var39 = *(Vector3fix*)(arg0 + Enum_ov025_021dcf14_3208);
            fix32_Divide((int)(4096.0f * (6.0f * var38)), var39.z);
            TIMER = 0xc8;
            if (arg0[Enum_ov025_021dcf14_28237] != 0) {
                arg0[Enum_ov025_021dcf14_28235] = 6;
            } else {
                arg0[Enum_ov025_021dcf14_28235] = 3;
            }
        }
        if (arg0[Enum_ov025_021dcf14_28235] == 6) {
            void* var40 = func_ov000_02160f20(arg0);
            struct Struct_ov025_021dcf14_4* var41 =
                func_02079e2c((char*)func_020797dc(), *(short*)var40);
            if (var41 && var41->unknown_19_4_ == 2) {
                struct Struct_ov025_021dcf14_3* var42 = func_ov000_021600f8((Struct_ov000_0215440c*)var40, var1->unknown_c_);
                if (var42 == NULL) {
                    return 0;
                }
                if (var42 == NULL) {
                    return 0;
                }
                if (var42->unknown_14_[2] != 1 && var42->unknown_14_[2] != 2) {
                    unsigned int var43 = *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28556);
                    *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28616) = var43;
                    if (var43 > 0x9b) {
                        TIMER = var43 - 0x9b;
                    }
                }
            }
        }
    } else if (arg0[Enum_ov025_021dcf14_28235] == 6) {
        if (*(unsigned short*)(arg0 + Enum_ov025_021dcf14_28270) != 0) {
            return 0;
        }
        unsigned int var44 = var0->GetEffectiveDeltaTime();
        if (var44 < TIMER) {
            TIMER -= var44;
        } else {
            GameObject* var45 = var0->GetCombatantByIndex(var1->unknown_18_);
            if (var45) {
                func_02033fdc((Struct_02033fdc*)var45);
            }
            void* var46 = func_ov000_02160f20(arg0);
            struct Struct_ov025_021dcf14_2* var47 = func_ov000_02160094((Struct_ov000_0215440c_2*)var46, 0);
            if (var47 == NULL) {
                return 0;
            }
            if (var47 == NULL) {
                return 0;
            }
            struct Struct_ov025_021dcf14_3* var48 = func_ov000_021600f8((Struct_ov000_0215440c*)var46, var1->unknown_c_);
            if (var48 == NULL) {
                return 0;
            }
            if (var48 == NULL) {
                return 0;
            }
            int var49 = 0;
            int var50 = 0;
            if (var48->unknown_14_[2] == 3 || var48->unknown_14_[2] == 1) {
                if (var48->unknown_14_[2] == 1) {
                    var50 = 1;
                } else {
                    var49 = 1;
                }
                var1->unknown_4_ = 2;
            }
            if (!var49 && var47->unknown_26_[4] != 0) {
                arg0[Enum_ov025_021dcf14_28238] = 6;
            }
            func_ov025_021d8bfc(arg0, (Struct_ov025_021d8bfc*)var1);
            if (arg0[Enum_ov025_021dcf14_30533] != var48->unknown_e_[1] || arg0[Enum_ov025_021dcf14_30534] != var48->unknown_e_[0]) {
                int var51 = 0x7f;
                int var52 = 0;
                if (var48->unknown_e_[0] >= 0 && var48->unknown_e_[0] <= 3) {
                    var52 = 1;
                }
                if (var52) {
                    var51 = 0x7e;
                }
                func_ov025_021ed444(arg0 + Enum_ov025_021dcf14_2192, var51, var48->unknown_e_[0], 0, 0, var48->unknown_e_[1], 0);
                arg0[Enum_ov025_021dcf14_30533] = var48->unknown_e_[1];
                arg0[Enum_ov025_021dcf14_30534] = var48->unknown_e_[0];
            }
            if (miss || crit) {
                StoreFields0x1e4And0x1e8IfNonZero_0202ea10((unsigned char*)(sl + CameraBase), 0xcc, 0x1f4);
                SetShortTriple0x6e44_ov000_02163440(sl, 0x199, 0x1f4, 0x64);
                if (crit) {
                    SePlayer_Play(&g_sePlayer, 0x43, 0);
                }
            }
            var1->unknown_4_ = 1;
            if (arg0[Enum_ov025_021dcf14_28237] <= ++arg0[Enum_ov025_021dcf14_28236]) {
                TIMER = 0x64;
                if (var49) {
                    TIMER = 0x96;
                }
                arg0[Enum_ov025_021dcf14_28235] = 3;
            } else {
                TIMER = 0x12c;
                if (*(unsigned short*)var46 == 1 || *(unsigned short*)var46 == 2 || *(unsigned short*)var46 == 0xdb) {
                    int var53;
                    for (var53 = 0; var53 < 3; var53++) {
                        int var54 = 0;
                        int var55;
                        for (var55 = 0; var55 < var48->unknown_18_[var53]; var55++) {
                            void* var56 = func_ov000_0215fff4(var48, var55, (unsigned char)var53);
                            if (var56 && func_ov000_0215fd90(var56, 0x2a)) {
                                var54 = 1;
                                TIMER = 0;
                                break;
                            }
                        }
                        if (var54) {
                            break;
                        }
                    }
                }
            }
        }
    } else if (arg0[Enum_ov025_021dcf14_28235] == 3) {
        if (arg0[Enum_ov025_021dcf14_28237] > arg0[Enum_ov025_021dcf14_28236]) {
            arg0[Enum_ov025_021dcf14_28235] = 6;
        } else {
            unsigned int var57 = var0->GetEffectiveDeltaTime();
            if (var57 < TIMER) {
                TIMER -= var57;
            } else {
                TIMER = 0;
            }
        }
    } else if (arg0[Enum_ov025_021dcf14_28235] == 4) {
        unsigned int var58 = var0->GetEffectiveDeltaTime();
        if (var58 < TIMER) {
            TIMER -= var58;
        } else {
            void* var59 = func_ov000_02160f20(arg0);
            struct Struct_ov025_021dcf14_2* var60 = func_ov000_02160094((Struct_ov000_0215440c_2*)var59, 0);
            if (var60 == NULL) {
                return 0;
            }
            if (var60 == NULL) {
                return 0;
            }
            struct Struct_ov025_021dcf14_3* var61 = func_ov000_021600f8((Struct_ov000_0215440c*)var59, var1->unknown_c_);
            if (var61 == NULL) {
                return 0;
            }
            if (var61 == NULL) {
                return 0;
            }
            int var62 = 0;
            int var63 = 0;
            unsigned char var64 = 0;
            unsigned short var65 = 0;
            if (var61->unknown_14_[2] == 3) {
                var62 = 1;
            } else if (var61->unknown_14_[2] == 1) {
                var63 = 1;
            }
            int var66 = 0;
            if (!var62 && !var63) {
                int var67;
                for (var67 = 0; var67 < 6; var67++) {
                    if (var60->unknown_26_[var67] != 0) {
                        var66 = 1;
                        if (var67 == 4) {
                            var65 = var60->unknown_20_;
                            var64 = 1;
                            arg0[Enum_ov025_021dcf14_28238] = 4;
                        }
                    }
                }
            }
            if (!var62 && !var64 && !var63) {
                for (int var68 = 0; var68 < *(short*)(arg0 + Enum_ov025_021dcf14_28410); var68++) {
                    GameObject* var69 = var0->GetCombatantByIndex(((short*)(arg0 + Enum_ov025_021dcf14_28400))[var68]);
                    if (var69 && !func_02048c68((unsigned char*)var69)) {
                        var2[var68] = var69;
                        if (!var66 && var2[var68]) {
                            var2[var68]->obj3D_.MakeVisible();
                        }
                    }
                }
                for (int var70 = 0; var70 < *(short*)(arg0 + Enum_ov025_021dcf14_28410); var70++) {
                    int var71;
                    GameObject* var72 = var2[var70];
                    if (var72 == NULL) {
                        continue;
                    }
                    if (func_02049ee8((unsigned char*)var72) == 0 || func_02048c68((unsigned char*)var72) != 0) {
                        var72->obj3D_.TransitionInheritedAlpha(0, 0x12c);
                        int var73 = 0;
                        if (var72->obj3D_.unknown_4_ >= 0 && var72->obj3D_.unknown_4_ <= 3) {
                            var73 = 1;
                        }
                        if (var73 || func_02048c68((unsigned char*)var72)) {
                            func_0204a0c8((unsigned char*)var72);
                        }
                    } else {
                        Vector3fix var74 = data_ov025_021eeee0;
                        var74.x = data_ov025_021eeeec[var70];
                        var71 = var72->obj3D_.rotation_.y;
                        Matrix4x3 var75 = RotationMatrixY(var71);
                        Mat4x3_ApplyToVector(&var74, &var75, &var74);
                        Vector3fix var76 = var72->obj3D_.position_;
                        Vector3fix var77;
                        Vector3fix_Add(&var76, &var74, &var77);
                        struct Struct_ov025_021dcf14_5 var78;
                        func_ov025_021de110(&var78);
                        var78.unknown_0_ = 1;
                        var78.unknown_8_ = var1->unknown_18_;
                        var78.unknown_a_ = 0x64;
                        var78.unknown1_c_ = fix32ReduceAngle0To2Pi(var71 + data_ov025_021eeef8[var70]);
                        func_ov025_021eee48((Struct_ov025_021dcf14_7*)(arg0 + Enum_ov025_021dcf14_2864), (Struct_ov025_021dcf14_8*)&var78);
                        func_ov025_021de110(&var78);
                        var78.unknown_0_ = 0;
                        var78.unknown_8_ = ((short*)(arg0 + Enum_ov025_021dcf14_28400))[var70];
                        var78.unknown_a_ = 0x12c;
                        var78.unknown_c_ = var77;
                        func_ov025_021eee48((Struct_ov025_021dcf14_7*)(arg0 + Enum_ov025_021dcf14_2864), (Struct_ov025_021dcf14_8*)&var78);
                        var2[var70]->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef460, 0);
                        func_02033fcc((Struct_02033fcc*)var2[var70]);
                    }
                }
                arg0[Enum_ov025_021dcf14_28238] = 0;
                inline_ov025_021dcf14_2(arg0, 5, 0x12c);
            } else {
                func_ov000_021626a0(arg0, 4, 0);
                GameObject* var79 = NULL;
                int var80 = func_ov000_0215ffa0(var61);
                if (var62 || var63) {
                    if (!func_ov025_021dce7c((unsigned char*)arg0, (Struct_ov025_021dce7c*)var59, var80)) {
                        func_ov000_0216df00(arg0 + Enum_ov025_021dcf14_3096, var80, 0, 0, 1.8f);
                    }
                    var79 = var0->GetCombatantByIndex(var80);
                } else if (var64) {
                    func_ov000_0216df00(arg0 + Enum_ov025_021dcf14_3096, var65, 0, 0, 1.8f);
                    var79 = var0->GetCombatantByIndex(var65);
                    var1->unknown_4_ = 0;
                }
                var79->obj3D_.MakeVisible();
                if (var63) {
                    int var81 = func_ov000_0215ffa0(var61);
                    struct Struct_ov025_021dcf14_6 var82 = inline_ov025_021dcf14_3(arg0);
                    void* var83 = func_02057924();
                    struct Struct_02078398_2 var84;
                    func_02078484(&var84);
                    var84.unknown_14_ = var81;
                    if (var82.unknown_28_ & 1) {
                        var84.unknown_2c_.y += var79->obj3D_.GetHeight() / 2;
                    }
                    FindNodeAndProcess02057fb4(list, pending.id, &req);
                    DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, *(short*)(sl + Field6f9a), 0);
                }
                if (!var63) {
                    if (var62) {
                        var1->unknown_4_ = 3;
                    }
                    func_ov025_021d8bfc(arg0, (Struct_ov025_021d8bfc*)var1);
                    var1->unknown_4_ = 1;
                    if (arg0[Enum_ov025_021dcf14_28237] <= ++arg0[Enum_ov025_021dcf14_28236]) {
                        arg0[Enum_ov025_021dcf14_28238] = 0;
                        inline_ov025_021dcf14_2(arg0, 5, 1000);
                    }
                } else {
                    unsigned int var85 = *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28556);
                    *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28616) = var85;
                    arg0[Enum_ov025_021dcf14_28238] = 0;
                    inline_ov025_021dcf14_2(arg0, 7, var85);
                }
            }
        }
    } else if (arg0[Enum_ov025_021dcf14_28235] == 7) {
        unsigned int var86 = var0->GetEffectiveDeltaTime();
        if (var86 < TIMER) {
            TIMER -= var86;
        } else {
            struct Struct_ov025_021dcf14_3* var87 =
                func_ov000_021600f8((Struct_ov000_0215440c*)func_ov000_02160f20(arg0), var1->unknown_c_);
            if (var87 == NULL) {
                return 0;
            }
            if (var87 == NULL) {
                return 0;
            }
            int var88 = func_ov000_0215ffa0(var87);
            func_ov025_021eabd0(arg0 + Enum_ov025_021dcf14_680, inline_ov000_02169850(var88));
            func_ov025_021d8bfc(arg0, (Struct_ov025_021d8bfc*)var1);
            func_ov025_021ead5c(arg0 + Enum_ov025_021dcf14_680, inline_ov000_02169850(var88));
            inline_ov025_021dcf14_2(arg0, 5, 1000);
        }
    } else if (arg0[Enum_ov025_021dcf14_28235] == 5) {
        unsigned int var89 = var0->GetEffectiveDeltaTime();
        if (var89 < TIMER) {
            TIMER -= var89;
        } else {
            TIMER = 0;
            for (int var90 = 0; var90 < arg0[Enum_ov025_021dcf14_28237]; var90++) {
                GameObject* var91 = var0->GetCombatantByIndex(((struct Struct_ov025_021dcf14*)(arg0 + Enum_ov025_021dcf14_28240))[var90].unknown_18_);
                if (var91) {
                    func_02033fdc((Struct_02033fdc*)var91);
                }
                ((struct Struct_ov025_021dcf14*)(arg0 + Enum_ov025_021dcf14_28240))[var90].unknown_18_ = -1;
                ((struct Struct_ov025_021dcf14*)(arg0 + Enum_ov025_021dcf14_28240))[var90].unknown_1a_ = -1;
            }
            arg0[Enum_ov025_021dcf14_28237] = 0;
            arg0[Enum_ov025_021dcf14_28235] = 0;
        }
    }
    return 0;
}

// USA: func_ov025_021de110
extern "C" ARM void func_ov025_021de110(void* arg0) {
    *(int*)((char*)arg0 + 0x0) = 0;
    *(int*)((char*)arg0 + 0x4) = 0;
    *(int*)((char*)arg0 + 0x18) = 0;
}

struct Struct_ov025_021de124 {
    unsigned short unknown_0_;
    char unknown_2_[7];
    unsigned char unknown_9_;
};

struct Struct_ov025_021de124_2 {
    struct Struct_ov025_021de124* unknown_0_;
    int unknown_4_;
    char unknown_8_[4];
    int unknown_c_;
    char unknown_10_[8];
    unsigned short unknown_18_;
    unsigned short unknown_1a_;
};

struct Struct_ov025_021de124_3 {
    char unknown_0_[0x2c];
    unsigned short unknown_2c_;
    short unknown_2e_;
    short unknown_30_;
    char unknown_32_[6];
    unsigned char unknown_38_;
};

extern "C" void func_ov000_0216d370(void* obj, int a, int b, int c);
extern "C" void func_ov000_0216df00(void* obj, int id, int b, int c, float scale);
extern "C" void func_ov000_0216dbf0(void* obj, int* id, int a, int b);
void* GetSlotPtr02160f20(void* obj);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
extern "C" void func_ov000_02167f10(void* obj);
extern "C" int func_ov025_021ed444(void* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
extern "C" int func_ov025_021ed564(void* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
void SetShortTriple0x6e44_ov000_02163440(void* obj, short a, unsigned short b, unsigned short c);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
int GetShortAtField0xEBound3_ov000_0215ff80(char*, int);
void* GetActiveCombatWork_ov000_02160130(void);
extern "C" int func_ov000_0215ffa0(void* node);
extern "C" void func_ov025_021eabd0(void* obj, bool party);
extern "C" void func_ov025_021ead5c(void* obj, bool party);
extern "C" void func_ov025_021ed344(void* obj, int val);
int Check021ed2f4(void* obj);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02043124(int obj);
extern "C" void* func_02057924(void);
extern "C" void func_02078484(struct Struct_02078398_2* arg0);
extern "C" short func_ov000_0216352c(int arg0, float arg1, float arg2);
extern "C" int func_ov000_021635e4(int arg0, int arg1);

extern Vector3fix data_ov025_021eef04;
extern struct SePlayer g_sePlayer;

#undef TIMER
#define TIMER (inline_ov025_021dcf14().unknown_6_)

static inline int inline_ov025_021de124(void* arg0) {
    return func_ov000_0215ff80((char*)arg0, 0) >= 0 && func_ov000_0215ff80((char*)arg0, 0) <= 3;
}

static inline int inline_ov025_021dfbfc(int arg0) {
    return arg0 >= 0xc0 && arg0 <= 0xc7;
}

// USA: func_ov025_021de124
extern "C" ARM int func_ov025_021de124(unsigned char* arg0) {
    GameState* var0 = GameState::GetInstance();
    struct Struct_ov025_021de124* var1;
    struct Struct_ov025_021de124_2* var2;

    if (arg0[Enum_ov025_021dcf14_28414] != 0) {
        unsigned int var3 = var0->GetEffectiveDeltaTime();
        struct Struct_ov025_021de124_2* var4 = (struct Struct_ov025_021de124_2*)(arg0 + Enum_ov025_021dcf14_28424);
        for (int var5 = 0; var5 < arg0[Enum_ov025_021dcf14_28416]; var5++, var4++) {
            if (var3 < var4->unknown_1a_) {
                var4->unknown_1a_ -= var3;
            } else {
                var4->unknown_1a_ = 0;
            }
            var4->unknown_18_ += var3;
        }
    }

    if (arg0[Enum_ov025_021dcf14_28414] == 0) {
        return 0;
    }
    var2 = (struct Struct_ov025_021de124_2*)(arg0 + Enum_ov025_021dcf14_28424) + arg0[Enum_ov025_021dcf14_28415];

    if (arg0[Enum_ov025_021dcf14_28414] == 1) {
        var1 = var2->unknown_0_;
        struct Struct_ov025_021dcf14_3* var6 = func_ov000_021600f8((Struct_ov000_0215440c*)var1, var2->unknown_c_);
        int var7 = var1->unknown_9_ - 1;
        if (var7 <= 0) {
            var7 = 1;
        }
        *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28616) = *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28556);
        if (var1->unknown_9_ > 1) {
            if (*(unsigned int*)(arg0 + Enum_ov025_021dcf14_28556) > *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28548)) {
                *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28616) = *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28556) - *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28548);
            }
        }
        *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28620) = *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28548) / var7;
        *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28612) = 0;
        if (*(unsigned int*)(arg0 + Enum_ov025_021dcf14_28620) > *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28616)) {
            *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28612) = *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28620) - *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28616);
        }
        if (!(arg0[Enum_ov025_021dcf14_3640] != 0 && var1->unknown_0_ != 0x246 && var1->unknown_0_ != 0x30d)
            && !(var1->unknown_0_ == 0x30f || var1->unknown_0_ == 0x243)) {
            func_ov000_0216d370(arg0 + Enum_ov025_021dcf14_3096, 0, 1, 1);
            func_ov000_0216df00(arg0 + Enum_ov025_021dcf14_3096, var6->unknown_e_[0], 0, 0, 1.8f);
            func_ov000_02163a7c((Struct_ov000_02163a7c*)arg0);
            func_ov000_021626a0(arg0, 4, 0);
            GameObject* var8 = var0->GetCombatantByIndex(var6->unknown_e_[0]);
            if (var8) {
                var8->obj3D_.MakeVisible();
            }
        }
        arg0[Enum_ov025_021dcf14_28414] = 2;
    } else if (arg0[Enum_ov025_021dcf14_28414] == 2) {
        var1 = var2->unknown_0_;
        int var9 = var2->unknown_c_;
        int var10 = 0;
        TIMER = 0;
        struct Struct_ov025_021dcf14_3* var11 = func_ov000_021600f8((Struct_ov000_0215440c*)var1, var9);
        for (int var12 = 1; var12 < var11->unknown_17_; var12++) {
            if (var11->unknown_14_[var12] == 1 || var11->unknown_14_[var12] == 2) {
                var10 = 1;
            }
        }
        int var13 = var11->unknown_e_[0];
        if (var11->unknown_17_ > 1) {
            if (var11->unknown_14_[1] == 8 || var11->unknown_14_[1] == 7 || var11->unknown_14_[1] == 6) {
                var13 = var11->unknown_e_[1];
            }
        }
        GameObject* var14 = var0->GetCombatantByIndex(var13);
        if (var14 && !var10) {
            void* var15 = func_02057924();
            struct Struct_02078398_2 var16;
            func_02078484(&var16);
            var16.unknown_14_ = var13;
            if (*(unsigned int*)(arg0 + Enum_ov025_021dcf14_28576) & 1) {
                var16.unknown_2c_.y += var14->obj3D_.GetHeight() / 2;
            }
            DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, *(short*)(sl + Field6f9a), 0);
            FindNodeAndProcess02057fb4(fx, *(short*)(sl + Field6f98), &req);
            TIMER = *(unsigned int*)(sl + Field6fc8);
        }
        arg0[Enum_ov025_021dcf14_28414] = 3;
    } else if (arg0[Enum_ov025_021dcf14_28414] == 3) {
        unsigned int var17 = var0->GetEffectiveDeltaTime();
        if (var17 < TIMER) {
            TIMER -= var17;
        } else {
            struct Struct_ov025_021de124* var18 = var2->unknown_0_;
            struct Struct_ov025_021dcf14_3* var19;
            int var20 = 0;
            int var21;
            int var22 = var2->unknown_c_;
            TIMER = 0;
            var19 = func_ov000_021600f8((Struct_ov000_0215440c*)var18, var22);
            int var23 = 1;
            var21 = 0;
            for (; var23 < var19->unknown_17_; var23++) {
                if (var19->unknown_14_[var23] == 8 || var19->unknown_14_[var23] == 7 || var19->unknown_14_[var23] == 6) {
                    var21 = 1;
                }
                if (var19->unknown_14_[var23] == 1 || var19->unknown_14_[var23] == 2) {
                    var2->unknown_4_ = 2;
                    var20 = 1;
                    break;
                }
            }
            func_ov025_021d8bfc(arg0, (Struct_ov025_021d8bfc*)var2);
            if (var21) {
                int var24 = 0x7f;
                int var25 = 0;
                if (var19->unknown_e_[1] >= 0 && var19->unknown_e_[1] <= 3) {
                    var25 = 1;
                }
                if (var25) {
                    var24 = 0x7e;
                }
                unsigned short var26 = var24;
                if (func_ov025_021ed564(arg0 + Enum_ov025_021dcf14_2192, var26, var19->unknown_e_[0], 0, 0, var19->unknown_e_[1], 0) < 0) {
                    func_ov025_021ed444(arg0 + Enum_ov025_021dcf14_2192, var26, var19->unknown_e_[0], 0, 0, var19->unknown_e_[1], 0);
                }
            }
            arg0[Enum_ov025_021dcf14_28415]++;
            arg0[Enum_ov025_021dcf14_28414] = 4;
            TIMER = *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28612);
            if (var20) {
                if (arg0[Enum_ov025_021dcf14_3640] != 2) {
                    func_ov000_02163440(arg0, 0xcc, 0xc8, 0x64);
                }
                SePlayer_Play(&g_sePlayer, 0x43, 0);
                TIMER = *(unsigned int*)(sl + Field6fc4) + 0x1f4;
            }
            if (var18->unknown_9_ <= arg0[Enum_ov025_021dcf14_28415]) {
                arg0[Enum_ov025_021dcf14_28417] = 1;
                bool var27 = inline_ov025_021de124(var19);
                struct Struct_ov025_021de124* var28 = (struct Struct_ov025_021de124*)func_ov000_02160f20(func_ov000_02160130());
                int var29 = -1;
                for (int var30 = 0; var30 < var28->unknown_9_; var30++) {
                    struct Struct_ov025_021dcf14_3* var31 = func_ov000_021600f8((Struct_ov000_0215440c*)var28, var30);
                    if (var31 == 0) {
                        continue;
                    }
                    int var32 = func_ov000_0215ffa0(var31);
                    if (var27) {
                        int var33 = var32 >= 0 && var32 <= 3;
                        if (var33) {
                            var29 = var32;
                            break;
                        }
                    } else {
                        int var34 = var32 >= 0 && var32 <= 3;
                        if (!var34) {
                            var29 = var32;
                            break;
                        }
                    }
                }
                if (var29 >= 0) {
                    func_ov025_021eabd0(arg0 + Enum_ov025_021dcf14_680, var27);
                    func_ov025_021ead5c(arg0 + Enum_ov025_021dcf14_680, var27);
                    func_ov025_021ed344(arg0 + Enum_ov025_021dcf14_2192, 0);
                }
                TIMER = 0x5dc;
            }
        }
    } else if (arg0[Enum_ov025_021dcf14_28414] == 4) {
        unsigned int var35 = var0->GetEffectiveDeltaTime();
        if (var35 < TIMER) {
            TIMER -= var35;
        } else {
            TIMER = 0;
            if (func_ov025_021ed2f4(arg0 + Enum_ov025_021dcf14_2192)) {
                if (arg0[Enum_ov025_021dcf14_28416] > arg0[Enum_ov025_021dcf14_28415]) {
                    arg0[Enum_ov025_021dcf14_28414] = 2;
                }
                if (arg0[Enum_ov025_021dcf14_28417] == 1) {
                    arg0[Enum_ov025_021dcf14_28414] = 5;
                    arg0[Enum_ov025_021dcf14_28417] = 0;
                    arg0[Enum_ov025_021dcf14_28415] = 0;
                }
            }
        }
    } else if (arg0[Enum_ov025_021dcf14_28414] == 5) {
        if (!func_ov025_021ed2f4(arg0 + Enum_ov025_021dcf14_2192)) {
            return 1;
        }
        func_02043124(func_020421a0());
        func_ov000_021626a0(arg0, 4, 0);
        GameObject* var36 = var0->GetCombatantByIndex(*(short*)(arg0 + Enum_ov025_021dcf14_28412));
        if (var36) {
            var36->obj3D_.MakeVisible();
        }
        var1 = var2->unknown_0_;
        struct Struct_ov025_021dcf14_4* var37 =
            func_02079e2c((char*)func_020797dc(), *(short*)var1);
        int var38 = 0;
        int var39 = 0;
        int var40 = 0;
        if (var37) {
            if (var37->unknown_19_4_ == 2) {
                var38 = 1;
            }
        }
        if (var1->unknown_0_ == 0x246 || var1->unknown_0_ == 0x30d) {
            var39 = 1;
        }
        if (var1->unknown_0_ == 0x30f || var1->unknown_0_ == 0x243) {
            var40 = 1;
        }
        void* var41 = func_02057924();
        struct Struct_02078398_2 var42;
        func_02078484(&var42);
        if (var39 || (arg0[Enum_ov025_021dcf14_3640] != 3 && var38 != 0 && var40 == 0)) {
            func_ov000_0216d370(arg0 + Enum_ov025_021dcf14_3096, 1, 1, 1);
            if (!func_ov025_021dce7c((unsigned char*)arg0, (Struct_ov025_021dce7c*)var1, *(short*)(arg0 + Enum_ov025_021dcf14_28412))) {
                func_ov000_0216df00(arg0 + Enum_ov025_021dcf14_3096, *(short*)(arg0 + Enum_ov025_021dcf14_28412), 0, 0, 1.8f);
            }
            var42.unknown_14_ = *(short*)(arg0 + Enum_ov025_021dcf14_28412);
            if (*(unsigned int*)(arg0 + Enum_ov025_021dcf14_28576) & 1) {
                var42.unknown_2c_.y += var36->obj3D_.GetHeight() / 2;
            }
            struct Struct_ov025_021de124_3* var43;
            int var44 = *(short*)(arg0 + Enum_ov025_021dcf14_28412);
            int var45 = 0;
            if (var44 >= 0xc0) {
                var45 = var44 <= 0xc7;
            }
            if (var45) {
                var43 = (struct Struct_ov025_021de124_3*)(arg0 + Enum_ov025_021dcf14_28536);
                if (var43->unknown_2c_ & 1) {
                    int var46 = 0x1000;
                    switch (var43->unknown_38_) {
                    case 0:
                        var46 = func_ov000_0216352c(var44, var43->unknown_2e_ / 4096.0f, var43->unknown_30_ / 4096.0f);
                        break;
                    case 1:
                        var46 = func_ov000_021635e4(var44, (unsigned char)var43->unknown_2e_);
                        if (var43->unknown_30_ <= var46) {
                            var46 = var43->unknown_30_;
                        }
                        break;
                    }
                    Vector3fix var47;
                    var47.x = var46;
                    var47.y = var46;
                    var47.z = var46;
                    var42.unknown_44_ = var47;
                }
            }
            FindNodeAndProcess02057fb4(fx, *(short*)(sl + Field6f98), &req);
            if (*(short*)(sl + Field6f9a) != -1) {
                DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, *(short*)(sl + Field6f9a), 0);
            } else if (*(unsigned short*)(sl + Field6f04) != -1) {
                DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, *(unsigned short*)(sl + Field6f04), 0);
            }
            TIMER = *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28616);
        } else if (arg0[Enum_ov025_021dcf14_3640] == 3 || var38 == 0 || var40 != 0) {
            int var48;
            func_ov000_0216d370(arg0 + Enum_ov025_021dcf14_3096, 1, 1, 1);
            var48 = *(short*)(arg0 + Enum_ov025_021dcf14_28412);
            if (var38) {
                func_ov000_0216dbf0(arg0 + Enum_ov025_021dcf14_3096, &var48, 1, 1);
            } else {
                func_ov000_0216df00(arg0 + Enum_ov025_021dcf14_3096, *(short*)(arg0 + Enum_ov025_021dcf14_28412), 0, 0, 1.8f);
            }
            func_ov000_021626a0(arg0, 4, 0);
            GameObject* var49 = var0->GetCombatantByIndex(var48);
            if (var49) {
                func_ov000_02167f10(arg0);
                Vector3fix var50 = data_ov025_021eef04;
                var49->obj3D_.position_ = var50;
                var49->obj3D_.MakeVisible();
            }
            DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, *(unsigned short*)(sl + Field6f04), 0);
            req.objectId = savedId;
            FindNodeAndProcess02057fb4(fx, *(unsigned short*)(sl + Field6f02), &req);
            TIMER = *(unsigned int*)(sl + Field6fd0);
            if (TIMER == 0) {
                TIMER = 0x1f4;
            }
        }
        arg0[Enum_ov025_021dcf14_28414] = 6;
    } else if (arg0[Enum_ov025_021dcf14_28414] == 6) {
        unsigned int var51 = var0->GetEffectiveDeltaTime();
        if (var51 < TIMER) {
            TIMER -= var51;
        } else {
            struct Struct_ov025_021de124* var52;
            struct Struct_ov025_021dcf14_3* var53;
            int var54, var55, var56;
            var56 = 0;
            var52 = var2->unknown_0_;
            TIMER = var56;
            var54 = -1;
            var55 = 1;
            for (; var56 < var52->unknown_9_; var56++) {
                int var57 = var56 * 0x1c;
                var53 = func_ov000_021600f8((Struct_ov000_0215440c*)var52, *(int*)(arg0 + var57 + Enum_ov025_021dcf14_28436));
                for (int var58 = 1; var58 < var53->unknown_17_; var58++) {
                    if (var53->unknown_14_[var58] == 1 || var53->unknown_14_[var58] == 2) {
                        *(int*)(arg0 + Enum_ov025_021dcf14_24576 + var57 + Enum_ov025_021dcf14_3852) = 1;
                        if (var54 < 0) {
                            var54 = func_ov000_0215ffa0(var53);
                        }
                        if (var55) {
                            bool var59 = inline_ov000_02169850(var54);
                            func_ov025_021eabd0(arg0 + Enum_ov025_021dcf14_680, var59);
                            var55 = 0;
                        }
                        func_ov025_021d8bfc(arg0, (Struct_ov025_021d8bfc*)(arg0 + Enum_ov025_021dcf14_28424 + var57));
                    }
                }
            }
            bool var60 = inline_ov000_02169850(var54);
            func_ov025_021ead5c(arg0 + Enum_ov025_021dcf14_680, var60);
            TIMER = *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28616);
            arg0[Enum_ov025_021dcf14_28414] = 8;
        }
    } else if (arg0[Enum_ov025_021dcf14_28414] == 8) {
        unsigned int var61 = var0->GetEffectiveDeltaTime();
        if (var61 < TIMER) {
            TIMER -= var61;
        } else {
            TIMER = 0;
            for (int var62 = 0; var62 < 4; var62++) {
                GameObject* var63 = var0->GetCombatantByIndex(((short*)(arg0 + Enum_ov025_021dcf14_28602))[var62]);
                if (var63) {
                    func_02033fdc((Struct_02033fdc*)var63);
                }
                ((short*)(arg0 + Enum_ov025_021dcf14_28602))[var62] = -1;
            }
            GameObject* var64 = var0->GetCombatantByIndex(*(short*)(arg0 + Enum_ov025_021dcf14_28412));
            if (var64) {
                func_02033fdc((Struct_02033fdc*)var64);
            }
            arg0[Enum_ov025_021dcf14_28417] = 0;
            arg0[Enum_ov025_021dcf14_28415] = 0;
            arg0[Enum_ov025_021dcf14_28414] = 0;
            *(unsigned short*)(arg0 + Enum_ov025_021dcf14_28418) = 0;
            *(unsigned short*)(arg0 + Enum_ov025_021dcf14_28420) = 0xffff;
            *(unsigned int*)(arg0 + Enum_ov025_021dcf14_28624) = 0;
        }
    }
    return 0;
}
