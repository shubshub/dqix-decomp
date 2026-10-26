#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Struct_ov000_02160094 { char pad0[0x20]; unsigned short id; };
struct Struct_ov000_021600f8 { char pad0[0xe]; short id; };
struct Struct_ov025_021ef9a8 { int fields[6]; };
struct Struct_ov025_021ef988_24 { char pad0[0x20]; int state; };
struct Struct_ov025_021e6a08 { int field0, field4, distance; };
struct Struct_02048c90;
struct Bytes02033b88 { Object3D object; char unknown_ac_[0x14]; unsigned char animation; };
struct Struct_ov023_021f2a48 { char pad0[0x14]; unsigned int flags; };
extern "C" Struct_ov000_02160094* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" void func_ov025_021e3158(Struct_ov025_021ef9a8*);
extern "C" void func_02049ae4(unsigned char*);
extern "C" int func_02048c10(unsigned char*);
extern "C" int func_020882f8(unsigned char*);
extern "C" void GameObject_FaceGameObject(GameObject*, int, int);
extern "C" int GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_02048c90(Struct_02048c90*);
extern Struct_ov025_021ef9a8 data_ov025_021ef9a8;
extern Struct_ov025_021ef988_24 data_ov025_021ef988;

// USA: func_ov025_021e6a08
extern "C" ARM int func_ov025_021e6a08(Struct_ov025_021e6a08* command, Struct_ov000_0215440c_2* list) {
    GameState* game = GameState::GetInstance();
    Struct_ov000_02160094* actorNode = func_ov000_02160094(list, 0);
    Struct_ov000_021600f8* var2 = func_ov000_021600f8((Struct_ov000_0215440c*)list, 0);
    if (!actorNode || !var2) { func_ov025_021e3158(&data_ov025_021ef9a8); return 1; }
    GameObject* actor = game->GetCombatantByIndex(actorNode->id);
    GameObject* target = game->GetCombatantByIndex(var2->id);
    if (!actor || !target) { func_ov025_021e3158(&data_ov025_021ef9a8); return 1; }
    int started = 0;
    if (data_ov025_021ef988.state == 0) {
        func_02049ae4((unsigned char*)actor);
        started = 1;
        if (!func_02048c10((unsigned char*)target) && !(((Struct_ov023_021f2a48*)target->currentStats_)->flags & 8) && !func_020882f8((unsigned char*)target->currentStats_)) {
            GameObject_FaceGameObject(target, actorNode->id, started);
        }
        data_ov025_021ef988.state = 1;
    }
    if (data_ov025_021ef988.state == 1) {
        Vector3i position = actor->obj3D_.position_;
        Vector3i targetPosition = target->obj3D_.position_;
        int radii = actor->obj3D_.GetRadius() + target->obj3D_.GetRadius();
        int var9 = command->distance + radii / 2;
        int distance = Vector3fix_Distance(&position, &targetPosition);
        if (!distance) { func_ov025_021e3158(&data_ov025_021ef9a8); return 1; }
        if (distance < var9) { func_ov025_021e3158(&data_ov025_021ef9a8); return 1; }
        Vector3i delta;
        Vector3fix_Subtract(&targetPosition, &position, &delta);
        var9 = distance - var9;
        Vector3i offset;
        Vector3fixMultiplyScalar(&delta, fix32_Divide(var9, distance), &offset);
        Vector3i destination;
        Vector3fix_Add(&position, &offset, &destination);
        Vector3i step;
        Vector3fix_Subtract(&destination, &position, &step);
        Vector3fixMultiplyScalar(&step, fix32_Divide(0x1000, 0x4000), &step);
        int length = Vector3fix_Length(&step);
        if (length > 0x333) Vector3fixMultiplyScalar(&step, fix32_Divide(0x333, length), &step);
        else if (((Bytes02033b88*)actor)->animation != 6) GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
        Vector3i nextPosition;
        Vector3fix_Add(&position, &step, &nextPosition);
        actor->obj3D_.position_ = nextPosition;
        if (var9 < 0x28 || (!started && ((Bytes02033b88*)actor)->animation == 0)) {
            GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
    }
    if (started) {
        func_02048c90((Struct_02048c90*)actor);
        if (((Bytes02033b88*)actor)->animation != 6) GameObject_ForceMotionState((Bytes02033b88*)actor, 1);
    }
    return 0;
}
