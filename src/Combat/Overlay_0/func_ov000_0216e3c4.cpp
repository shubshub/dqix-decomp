#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Util/Random.h"

struct Struct_020a212c_2 {
    unsigned char unknown_0_[0x10];
    Vector3i unknown_10_;
    unsigned char unknown_1c_[0x200];
    Random* unknown_21c_;
    unsigned char unknown_220_[0x18];
    int unknown_238_;
    unsigned char unknown_23c_[0x3c];
    unsigned char unknown_278_;
};
struct Struct_ov000_0216e3c4 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[0x16];
    unsigned char unknown_c2_0_ : 4;
    unsigned char unknown_c2_4_ : 1;
};
struct Struct_ov000_0216d368 { int unknown_0_, unknown_4_, unknown_8_; };
struct Struct_0202e6a8;
extern "C" void func_ov000_0216d370(Struct_020a212c_2*, int, int, int);
extern "C" int func_ov000_0215e9fc(Random*, short*, int, int);
extern "C" void func_0202e5d8(BattleCamera*, int, int, int);
CameraCombatant* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
void Camera_SetTarget(struct Camera*, int, int, int);
void StoreVec3Words0216d368(Vec3Ints0216d368*, int, int, int);
void ApplyField0x70Tail(GlobalObj0202e6a8*, int);

// USA: func_ov000_0216e3c4
extern "C" ARM void func_ov000_0216e3c4(Struct_020a212c_2* arg0) {
    if (!arg0->unknown_21c_) return;
    GameState* var0 = GameState::GetInstance();
    func_ov000_0216d370(arg0, 1, 1, 1);
    GameObject* var1 = var0->GetProtagonist();
    int var2 = -1;
    if (var1) var2 = var1->obj3D_.GetField06();
    short var3[4];
    int var4 = func_ov000_0215e9fc(arg0->unknown_21c_, var3, 4, 0);
    Vector3i var5 = {};
    int var6 = 0;
    for (int var7 = 0; var7 < var4; var7++) {
        GameObject* var8 = var0->GetGameObjectByIndex(var3[var7]);
        if (var8 && var2 == var8->obj3D_.GetField06()) {
            Vector3i var9 = var8->obj3D_.position_;
            Vector3fix_Add(&var5, &var9, &var5);
            var6++;
        }
    }
    if (var6 > 0) {
        int var10 = fix32_Divide(0x1000, var6 << 12);
        Vector3fixMultiplyScalar(&var5, var10, &var5);
    }
    int var11 = 0xc000 - Vector3fix_Length(&var5);
    if (var11 < 0x8000) {
        int var12 = fix32_Divide(var11, 0x8000);
        Vector3fixMultiplyScalar(&var5, var12, &var5);
        var11 = 0xc000;
    }
    int var13 = 0;
    var4 = func_ov000_0215e9fc(arg0->unknown_21c_, var3, 4, 1);
    if (var4 > 0) {
        int var14 = NextRandomMax(arg0->unknown_21c_, var4);
        GameObject* var15 = var0->GetGameObjectByIndex(var3[var14]);
        if (var15) var13 = var15->obj3D_.rotation_.y;
    }
    angle = fix32ReduceAngle0To2Pi(angle - 0x648);
    Camera_SetTarget((struct Camera*)camera, center.x, 0x800, center.z);
    func_0202e5d8(camera, angle, 0x1000, distance);
    int combatants = 0;
    camera->mode = 14;
    camera->active = 1;
    Vec3Ints0216d368 sum;
    StoreVec3Words0216d368(&sum, 0, 0, 0);
    for (int i = 0; i < 8; i++) {
        CameraCombatant* object = GetCombatantWithFlag0x400_0200fea4(game, i + 0xc0);
        if (object && object->included) {
            Vector3i position;
            position = object->object.position_;
            Vector3fix_Add(&position, (Vector3i*)&sum, (Vector3i*)&sum);
            combatants++;
        }
    }
    if (var16) {
        int var21 = fix32_Divide(0x1000, var16 << 12);
        Vector3fixMultiplyScalar((Vector3i*)&var17, var21, (Vector3i*)&var17);
        Vector3i var22;
        var22 = arg0->unknown_10_;
        int var23 = func_020c3544(var17.unknown_8_ - var22.z, var17.unknown_0_ - var22.x);
        func_0202e6a8((Struct_0202e6a8*)arg0, -0x999 + ((var23 / 0xffff) << 12));
    }
}
