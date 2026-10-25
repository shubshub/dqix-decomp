#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_ov025_021dc940 {
    char unknown_0_[0x8e14];
    signed char unknown_8e14_;
    char unknown_8e15_[0x8e24 - 0x8e15];
    int unknown_8e24_;
};

struct Struct_ov025_021dc940_3 {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
};

struct Struct_ov025_021dc940_4 {
    char unknown_0_[0xb];
    unsigned char unknown_b_0_ : 2;
    unsigned char unknown_b_2_ : 1;
    char unknown_c_[4];
    Struct_ov025_021dc940_3* unknown_10_;
};

struct Struct_ov025_021dc940_5 {
    char unknown_0_[RG(0x29c, 0x218)];
    Struct_ov025_021dc940* unknown_29c_;
    char unknown_2a0_[RG(0x4d4 - 0x2a0, 0x450 - 0x21c)];
    char unknown_4d4_[0x890 - 0x4d4];
    char unknown_890_[0xc18 - 0x890];
    char unknown_c18_[0xc88 - 0xc18];
    int unknown_c88_[3];
    char unknown_c94_[RG(0x3760 - 0xc94, 0x371c - 0xc10)];
    char unknown_3760_[RG(0x55d8 - 0x3760, 0x57c8 - 0x371c)];
    int unknown_55d8_;
    char unknown_55dc_[RG(0x6e4b - 0x55dc, 0x703b - 0x57cc)];
    unsigned char unknown_6e4b_;
    unsigned char unknown_6e4c_;
    char unknown_6e4d_[0x6efc - 0x6e4d];
    short unknown_6efc_;
    unsigned char unknown_6efe_;
    char unknown_6eff_[0x6fd4 - 0x6eff];
    unsigned char unknown_6fd4_;
    char unknown_6fd5_[3];
    unsigned char unknown_6fd8_;
    char unknown_6fd9_[3];
    Vector3i unknown_6fdc_;
    unsigned char unknown_6fe8_;
    char unknown_6fe9_[0x6ff8 - 0x6fe9];
    unsigned char unknown_6ff8_;
    unsigned char unknown_6ff9_;
    char unknown_6ffa_[0x7747 - 0x6ffa];
    unsigned char unknown_7747_;
};

struct Struct_02109bf4_5;

extern "C" void* func_02057924(void);
extern "C" int func_ov000_0215e9fc(void* party, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* party, short* buf, int max, int start);
int CountValidCombatants02058618(void* mgr);
unsigned char* GetData02104b6c_02039e70(void);
int CheckFields6d0And6d4Equal_0203a5d0(unsigned char* data);
int Check021ed2f4(void* obj);
int IsByteFieldZero_021ed0fc(void* obj);
int IsAnimationActive0209ca2c(void* obj);
struct Bytes02033b88;
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
extern "C" void __clear(void* dst, int size);
Slot_021dc940* GetSlotPtr02160f20(void* obj);
void SetFlag0x2_021754e0(int, int);
extern "C" void func_ov000_0218142c(void* list, int id);
void SetPosAndFields0216f1e4(void* obj, int* pos, int a, int b);
void* MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Stop(void* obj);
void StopAndReset0209c7fc(void* obj);
void DispatchActorState0209c73c(Actor0209c73c* actor);
void ClearGlobalBuffer02107850_02048994(void);

extern int g_bgmPlayer;

static inline unsigned char inline_ov025_021dc940(GameObject* arg0) {
    return *((unsigned char*)arg0 + 0xbe);
}

static inline int inline_ov025_021dc940_2(int arg0) {
    return arg0 >= 0 && arg0 <= 3;
}

struct Struct_ov025_021dc940_2 { char unknown_0_[RG(0x5d8, 0x7c8)]; int unknown_5d8_; };

// USA: func_ov025_021dc940
extern "C" ARM int func_ov025_021dc940(Struct_ov025_021dc940_5* arg0) {
    GameState* var0 = GameState::GetInstance();
    Struct_ov025_021dc940* var1 = arg0->unknown_29c_;
    void* var2 = func_02057924();

    unsigned char var3 = arg0->unknown_6e4b_;
    if (var3 != 0) {
        if (var3 == 3) {
            arg0->unknown_6e4b_ = 4;
            arg0->unknown_6e4c_ = 0;
        }
        return 0;
    }
    if ((int)arg0->unknown_6efe_ > 0) {
        return 0;
    }

    short var4[16];
    int var5 = 0;
    var5 = var5 + func_ov000_0215e9fc(var1, var4, 0x10, var5);
    var5 = var5 + func_ov000_0215ec1c(var1, var4 + var5, 0x10 - var5, 0);

    for (int var6 = 0; var6 < var5; var6++) {
        GameObject* var7 = var0->GetCombatantByIndex(var4[var6]);
        if (var7 != NULL && (inline_ov025_021dc940(var7) == 4 || inline_ov025_021dc940(var7) == 3)) {
            return 0;
        }
    }

    if (func_02058618(var2) > 0) {
        return 0;
    }
    if (func_0203a5d0(func_02039e70()) == 0) {
        return 0;
    }
    if (func_ov025_021ed2f4(arg0->unknown_890_) == 0) {
        return 0;
    }
    if (func_ov025_021ed0fc(arg0->unknown_4d4_) == 0) {
        return 0;
    }
    if (IsAnimationActive0209ca2c(&g_bgmPlayer) != 0) {
        return 0;
    }

    int var8 = 0;
    for (int var9 = 0; var9 < var5; var9++) {
        GameObject* var10 = var0->GetCombatantByIndex(var4[var9]);
        if (var10 == NULL) {
            continue;
        }
        var10->obj3D_.SetAnimationPlaybackSpeed(0x1000, 0);
        if (arg0->unknown_7747_ == 0) {
            unsigned char var11 = inline_ov025_021dc940(var10);
            if (var11 != 4 && var11 != 6) {
                func_02033b88((Struct_02010604*)var10, 0);
            }
        }
        if (var10->obj3D_.IsVisible() && var10->obj3D_.IsTransitioningAnimations()) {
            var8 = 1;
        }
    }
    arg0->unknown_7747_ = 1;
    if (var8) {
        return 0;
    }
    arg0->unknown_7747_ = 0;

    Vector3i var12;
    __clear(&var12, sizeof(var12));
    arg0->unknown_6fdc_ = var12;
    arg0->unknown_6fe8_ = 0;
    arg0->unknown_6fd8_ = 0;
    arg0->unknown_6ff9_ = 0;
    arg0->unknown_6efc_ = -1;
    arg0->unknown_6ff8_ = 0;
    arg0->unknown_6fd4_ = 0;

    Struct_ov025_021dc940_4* var13 = func_ov000_02160f20(arg0);
    Struct_ov025_021dc940_3* var14;
    if (var13 != NULL && (var14 = var13->unknown_10_) != NULL && !var13->unknown_b_2_) {
        int var15 = var14->unknown_20_;
        if (inline_ov025_021dc940_2(var15)) {
            func_ov000_021754e0((int)arg0->unknown_3760_, var15);
            func_ov000_0218142c(arg0->unknown_3760_, var15);
        }
    }
    SetPosAndFields0216f1e4(obj->cameraBase, obj->cameraPos, 0, 0);
    MessageSystem_Stop(MessageSystem_GetInstance());

    Battle_021dc940* battle = obj->battle;
    if (((TurnBlock_021dc940*)((int)obj + 0x5000))->turn == battle->f8e24 - 1 && battle->f8e14 != 0) {
        StopAndReset0209c7fc(&g_bgmPlayer);
    } else {
        DispatchActorState0209c73c((Actor0209c73c*)&g_bgmPlayer);
    }
    func_02048994();
    return 1;
}
