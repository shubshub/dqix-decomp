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
void SetVecYFromValue02033874(Obj02033874* obj, int angle);
void SetSubstructField0x8ClearFlag0x2_02049bac(unsigned char* obj, int* rot);
int IsFlag10088Set_02010088(S_10088* obj);

extern "C" {
void __clear(void* arg0, int arg1);
int func_ov000_0215eb1c(Struct_ov000_02161e30*, short*, int, int);
void func_0203232c(int*, int);
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

            Vector3fix var11;
            Vector3fix_Subtract(&var9, &var10, &var11);
            var11.y = 0;
            Vector3fix_Normalize(&var11, &var11);
            fix32_t var12 = fix32_Atan2(var11.x, var11.z);
            func_02033874((Struct_02033834*)var8, var12);

            Vector3fix var13;
            __clear(&var13, sizeof(var13));
            var13.y = var12;
            func_02049bac((unsigned char*)var8, &var13.x);

            var5[var3++] = var0[var7];
        }
    }

    if (arg2 && arg0->unknown_8e20_ > 0) {
        func_0203232c(var5, var3);
        for (int var14 = 0; var14 < var3; var14++) {
            GameObject* var15 = func_0200fea4(var1, var5[var14]);
            if (var15 != NULL && !var15->obj3D_.IsTransitioningAnimations() && !func_02010088((Struct_02010088*)var15)) {
                var15->obj3D_.SetNormalizedAnimationTime(0x1000 / var3 * var14);
                var15->obj3D_.AdvanceAnimations();
            }
        }
    }
}
