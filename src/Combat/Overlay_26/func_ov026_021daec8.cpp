#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02049b54_2;
struct Struct_02033834;
struct Struct_02010088;

struct Struct_ov000_02161e30 {
    char unknown_0_[0x8e20];
    int unknown_8e20_;
};

struct Struct_ov026_021daec8 {
    char unknown_0_[0x240];
    Vector3fix unknown_240_;
};

struct Struct_02049b54_3 {
    Vector3fix unknown_0_;
};

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* gs, int id);
Triple02049b54 GetSubTriple02049b54(Obj02049b54* obj);
void GameObject_SnapFacing(Obj02033874* obj, int angle);
void SetSubstructField0x8ClearFlag0x2_02049bac(unsigned char* obj, int* rot);
int IsFlag10088Set_02010088(S_10088* obj);

extern "C" {
void __clear(void* dst, int size);
int func_ov000_0215eb1c(BattleState*, short*, int, int);
void IntArray_Shuffle(int*, int);
}

// USA: func_ov026_021daec8
extern "C" ARM void func_ov026_021daec8(BattleState* battle, BattleView* view, int animate) {
    short ids[8];
    GameState* gs = GameState::GetInstance();
    gs->GetResources();

    int var2 = func_ov000_0215eb1c(arg0, var0, 8, 0);
    int var3 = 0;
    Vector3fix var4 = arg1->unknown_240_;
    int var5[8];
    int var6 = var4.z;

    for (int var7 = 0; var7 < var2; var7++) {
        GameObject* var8 = func_0200fea4(var1, var0[var7]);
        if (var8 != NULL) {
            Vector3fix var9;
            __clear(&var9, sizeof(var9));
            var9.z = var6;

            Vector3fix var10 = func_02049b54((Struct_02049b54_2*)var8).unknown_0_;
            var10.y = 0;

            Vector3fix dir;
            Vector3fix_Subtract(&target, &pos, &dir);
            dir.y = 0;
            Vector3fix_Normalize(&dir, &dir);
            fix32_t angle = fix32_Atan2(dir.x, dir.z);
            GameObject_SnapFacing((Obj02033874*)member, angle);

            Vector3fix var13;
            __clear(&var13, sizeof(var13));
            var13.y = var12;
            func_02049bac((unsigned char*)var8, &var13.x);

            var5[var3++] = var0[var7];
        }
    }

    if (animate && battle->turns > 0) {
        IntArray_Shuffle(order, n);
        for (int i = 0; i < n; i++) {
            GameObject* member = GetCombatantWithFlag0x400_0200fea4(gs, order[i]);
            if (member != NULL && !member->obj3D_.IsTransitioningAnimations() && !IsFlag10088Set_02010088((S_10088*)member)) {
                member->obj3D_.SetNormalizedAnimationTime(0x1000 / n * i);
                member->obj3D_.AdvanceAnimations();
            }
        }
    }
}
