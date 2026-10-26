#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, RegionOffset160 = 0x154, RegionOffset16c = 0x160 };
#else
enum { RegionOffset6fc = 0x6fc, RegionOffset160 = 0x160, RegionOffset16c = 0x16c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct HeadNode02046b24 { signed char id; };
int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(struct ArrayContainsByteStruct* s, int val);

void* GameState_GetParty(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
struct Vector3i;

struct Obj02033834;
struct Obj02033874;
void GameObject_SetFacing(struct Obj02033834* obj, int arg);
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

extern "C" void __clear(void* buf, int n);

struct Info021ceee0 {
    char pad4[4];
    int vec[3];
    short field10;
    unsigned char field12;
    unsigned char field13;
};

// USA: func_ov017_021ceee0  (semantic: SyncOrAimCombatantByHeadState_021ceee0)
extern "C" ARM void func_ov017_021ceee0(void* unused0, struct Info021ceee0* info, GameState* battle, char* obj) {
    GameObject* held;
    struct HeadNode02046b24** list = *(struct HeadNode02046b24***)(obj + 0x3000 + RegionOffset6fc);
    held = battle->GetWanderingMonsterByIndex(info->field12);
    if (ArrayContainsByte_02086ef0((struct ArrayContainsByteStruct*)GameState_GetParty(battle), info->field12)) {
        return;
    }
    if (!held) {
        return;
    }
    if (FieldTaskQueue_GetCurrentKind(list) == 0xa) {
        int withinRange = info->field12 <= 3;
        if (!withinRange) {
            return;
        }
        if (!(held->obj3D_.unknown_0_ & 0x80)) {
            return;
        }
        GameObject* target = GetCombatantWithFlag0x100_0200ff1c(battle, info->field12);
        if (!target) {
            return;
        }
        int buf[3];
        __clear(buf, 0xc);
        buf[1] = info->field10;
        *(Vector3i*)((int*)((char*)target + RegionOffset160)) = *(Vector3i const*)info->vec;
        *(Vector3i*)((int*)((char*)target + RegionOffset16c)) = *(Vector3i const*)buf;
        return;
    }
    if (FieldTaskQueue_GetCurrentKind(list) == 4) {
        return;
    }
    *(Vector3i*)(&held->obj3D_.position_.x) = *(Vector3i const*)info->vec;
    if (info->field13 == 0) {
        GameObject_SetFacing((struct Obj02033834*)held, info->field10);
    } else {
        GameObject_SnapFacing((struct Obj02033874*)held, info->field10);
    }
}
