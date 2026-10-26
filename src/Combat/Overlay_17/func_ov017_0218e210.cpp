#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Obj02033834;
struct BitFlag02033f44;
struct CollisionNode0218e210 { char pad[0x24]; Vector3fix direction; };
struct Struct_ov017_0218e210_2 { char pad[0xae]; short yaw; };
extern "C" void GameObject_UpdatePartyMember(GameObject*);
extern "C" int GameState_GetLeaderIndex(GameState*);
extern "C" int func_ov017_0218df50(void*, void*);
extern "C" int func_ov017_0218dfd8(GameObject*);
extern "C" void func_ov017_0219344c(GameObject*, int, const Vector3fix*, int, int*, int*);
extern "C" CollisionNode0218e210* GameObject_GetWallHit(BitFlag02033f44*);
extern "C" int func_02039dcc(unsigned char*);
extern "C" void func_02039dbc(unsigned char*);
extern "C" void GameObject_SetFacing(Obj02033834*, int);

// USA: func_ov017_0218e210
extern "C" ARM void func_ov017_0218e210(int index, int enabled) {
    GameState* game = GameState::GetInstance();
    GameObject* object = game->GetGameObjectByIndex(index);
    if (!object || object->obj3D_.GetFlag(0x200)) return;
    Vector3fix original = object->obj3D_.position_;
    GameObject_UpdatePartyMember(object);
    if (!enabled) return;
    Vector3fix current = object->obj3D_.position_;
    int distance = Vector3fix_Distance(&original, &current);
    int id = object->obj3D_.actorIndex_;
    int mode = 1;
    if (id == GameState_GetLeaderIndex(game) && !(object->obj3D_.unknown_0_ & 0x8000) && distance > 0x333) mode = 2;
    int var7 = 0;
    int var8 = 0;
    if (mode == 1 && index == GameState_GetLeaderIndex(game)) {
        var7 |= func_ov017_0218df50(object, 0);
        var8 |= var7;
        var8 |= func_ov017_0218dfd8(object);
    }
    func_ov017_0219344c(object, 1, &original, mode, &var7, &var8);
    CollisionNode0218e210* node = GameObject_GetWallHit((BitFlag02033f44*)object);
    int restored = 0;
    int var11 = 0;
    if (var8 && node) {
        if (!func_02039dcc((unsigned char*)object)) {
            int handled = 0;
            var11 |= func_ov017_0218df50(object, 0);
            handled |= var11;
            handled |= func_ov017_0218dfd8(object);
            object->obj3D_.position_ = object->obj3D_.position_;
            if (handled) restored = 1;
            if (restored) {
                object->obj3D_.position_ = original;
                if (restored && var7 && var11) {
                    int changed = func_ov017_0218df50(object, 0);
                    object->obj3D_.position_ = original;
                    if (changed) func_ov017_0218df50(object, (void*)1);
                }
            }
        }
    } else {
        if (!node) func_02039dbc((unsigned char*)object);
        if (node && !func_02039dcc((unsigned char*)object)) {
            int handled = 0;
            var11 |= func_ov017_0218df50(object, 0);
            handled |= var11;
            handled |= func_ov017_0218dfd8(object);
            object->obj3D_.position_ = object->obj3D_.position_;
            if (handled) {
                restored = 1;
                object->obj3D_.position_ = original;
            }
        }
        if (node && !restored) {
            int var15 = 0;
            int movementAngle;
            if (Vector3fix_Distance(&original, &object->obj3D_.position_) >= 0x28) {
                Vector3fix direction;
                Vector3fix_Subtract(&object->obj3D_.position_, &original, &direction);
                Vector3fix_Normalize(&direction, &direction);
                var15 = 1;
                movementAngle = fix32_Atan2(direction.x, direction.z);
            }
            if (var15) {
                Vector3fix direction = node->direction;
                direction.y = 0;
                Vector3fix_Normalize(&direction, &direction);
                int var19 = fix32_Atan2(direction.x, direction.z);
                int yaw = ((Struct_ov017_0218e210_2*)object)->yaw;
                int difference = fix32SignedAngleDistance(var19, yaw);
                int var22 = fix32abs(difference);
                if ((float)var22 < 10294.4f) {
                    if (var22 > 0x1922) {
                        if (difference > 0) yaw = fix32ReduceAngle0To2Pi((int)(6772.632f + (float)var19));
                        else yaw = fix32ReduceAngle0To2Pi((int)((float)var19 - 6772.632f));
                    }
                    if ((float)fix32abs(fix32SignedAngleDistance(yaw, movementAngle)) < 643.4f) GameObject_SetFacing((Obj02033834*)object, yaw);
                }
            }
        }
    }
    Vector3fix delta;
    Vector3fix_Subtract(&object->obj3D_.position_, &original, &delta);
    if (fix32abs(delta.x) <= 4 && fix32abs(delta.y) <= 4 && fix32abs(delta.z) <= 4) object->obj3D_.position_ = original;
    int moved = Vector3fix_Distance(&original, &object->obj3D_.position_);
    if (distance > 0 && distance < moved) {
        Vector3fix direction;
        Vector3fix_Subtract(&object->obj3D_.position_, &original, &direction);
        Vector3fix_Normalize(&direction, &direction);
        Vector3fixMultiplyScalar(&direction, distance, &direction);
        Vector3fix var26;
        Vector3fix_Add(&original, &direction, &var26);
        object->obj3D_.position_ = var26;
    }
}
