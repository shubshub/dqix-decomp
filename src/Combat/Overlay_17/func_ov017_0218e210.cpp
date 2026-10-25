#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_02033834_2;
struct Struct_02033f44;
struct Struct_ov017_0218e210 { char unknown_0_[0x24]; Vector3fix unknown_24_; };
struct Struct_ov017_0218e210_2 { char unknown_0_[0xae]; short unknown_ae_; };
extern "C" void func_02037d88(GameObject*);
int GameState_GetLeaderIndex(GameState*);
int NotifyEntriesFlag256_0218df50(void*, void*);
extern "C" int func_ov017_0218dfd8(GameObject*);
extern "C" void func_ov017_0219344c(GameObject*, int, const Vector3fix*, int, int*, int*);
CollisionNode0218e210* GetField0xe4IfFlag0x40(BitFlag02033f44*);
int IsFlag0x1ceBit0x8Set_02039dcc(unsigned char*);
void ClearFlag0x1ceBit0x8_02039dbc(unsigned char*);
void GameObject_SetFacing(Obj02033834*, int);

// USA: func_ov017_0218e210
extern "C" ARM void func_ov017_0218e210(int index, int enabled) {
    GameState* game = GameState::GetInstance();
    GameObject* object = game->GetGameObjectByIndex(index);
    if (!object || object->obj3D_.GetFlag(0x200)) return;
    Vector3fix original = object->obj3D_.position_;
    func_02037d88(object);
    if (!enabled) return;
    Vector3fix current = object->obj3D_.position_;
    int distance = Vector3fix_Distance(&original, &current);
    int id = object->obj3D_.actorIndex_;
    int mode = 1;
    if (id == GameState_GetLeaderIndex(game) && !(object->obj3D_.unknown_0_ & 0x8000) && distance > 0x333) mode = 2;
    int notified = 0;
    int combined = 0;
    if (mode == 1 && index == GameState_GetLeaderIndex(game)) {
        notified |= NotifyEntriesFlag256_0218df50(object, 0);
        combined |= notified;
        combined |= func_ov017_0218dfd8(object);
    }
    func_ov017_0219344c(var1, 1, &var2, var6, &var7, &var8);
    Struct_ov017_0218e210* var9 = func_02033f44((Struct_02033f44*)var1);
    int var10 = 0;
    int var11 = 0;
    if (var8 && var9) {
        if (!func_02039dcc((unsigned char*)var1)) {
            int var12 = 0;
            var11 |= func_ov017_0218df50(var1, 0);
            var12 |= var11;
            var12 |= func_ov017_0218dfd8(var1);
            var1->obj3D_.position_ = var1->obj3D_.position_;
            if (var12) var10 = 1;
            if (var10) {
                var1->obj3D_.position_ = var2;
                if (var10 && var7 && var11) {
                    int var13 = func_ov017_0218df50(var1, 0);
                    var1->obj3D_.position_ = var2;
                    if (var13) func_ov017_0218df50(var1, (void*)1);
                }
            }
        }
    } else {
        if (!var9) func_02039dbc((unsigned char*)var1);
        if (var9 && !func_02039dcc((unsigned char*)var1)) {
            int var14 = 0;
            var11 |= func_ov017_0218df50(var1, 0);
            var14 |= var11;
            var14 |= func_ov017_0218dfd8(var1);
            var1->obj3D_.position_ = var1->obj3D_.position_;
            if (var14) {
                var10 = 1;
                var1->obj3D_.position_ = var2;
            }
        }
        if (var9 && !var10) {
            int var15 = 0;
            int var16;
            if (Vector3fix_Distance(&var2, &var1->obj3D_.position_) >= 0x28) {
                Vector3fix var17;
                Vector3fix_Subtract(&var1->obj3D_.position_, &var2, &var17);
                Vector3fix_Normalize(&var17, &var17);
                var15 = 1;
                var16 = fix32_Atan2(var17.x, var17.z);
            }
            if (var15) {
                Vector3fix var18 = var9->unknown_24_;
                var18.y = 0;
                Vector3fix_Normalize(&var18, &var18);
                int var19 = fix32_Atan2(var18.x, var18.z);
                int var20 = ((Struct_ov017_0218e210_2*)var1)->unknown_ae_;
                int var21 = fix32SignedAngleDistance(var19, var20);
                int var22 = fix32abs(var21);
                if ((float)var22 < 10294.4f) {
                    if (var22 > 0x1922) {
                        if (var21 > 0) var20 = fix32ReduceAngle0To2Pi((int)(6772.632f + (float)var19));
                        else var20 = fix32ReduceAngle0To2Pi((int)((float)var19 - 6772.632f));
                    }
                    if ((float)fix32abs(fix32SignedAngleDistance(yaw, movementAngle)) < 643.4f) GameObject_SetFacing((Obj02033834*)object, yaw);
                }
            }
        }
    }
    Vector3fix var23;
    Vector3fix_Subtract(&var1->obj3D_.position_, &var2, &var23);
    if (fix32abs(var23.x) <= 4 && fix32abs(var23.y) <= 4 && fix32abs(var23.z) <= 4) var1->obj3D_.position_ = var2;
    int var24 = Vector3fix_Distance(&var2, &var1->obj3D_.position_);
    if (var4 > 0 && var4 < var24) {
        Vector3fix var25;
        Vector3fix_Subtract(&var1->obj3D_.position_, &var2, &var25);
        Vector3fix_Normalize(&var25, &var25);
        Vector3fixMultiplyScalar(&var25, var4, &var25);
        Vector3fix var26;
        Vector3fix_Add(&var2, &var25, &var26);
        var1->obj3D_.position_ = var26;
    }
}
