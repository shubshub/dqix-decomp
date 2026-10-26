#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, Enum_ov017_021ceee0_352 = 0x154, Enum_ov017_021ceee0_364 = 0x160 };
#else
enum { RegionOffset6fc = 0x6fc, Enum_ov017_021ceee0_352 = 0x160, Enum_ov017_021ceee0_364 = 0x16c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct HeadNode02046b24 { signed char id; };
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(struct ArrayContainsByteStruct* s, int val);

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
struct Vector3i;

struct Obj02033834;
struct Obj02033874;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

extern "C" void __clear(void* buf, int n);

struct Struct_ov017_021ceee0 {
    char pad4[4];
    int vec[3];
    short field10;
    unsigned char field12;
    unsigned char unknown_13_;
};

// USA: func_ov017_021ceee0
extern "C" ARM void func_ov017_021ceee0(void* unused0, struct Struct_ov017_021ceee0* info, GameState* battle, char* obj) {
    GameObject* held;
    struct HeadNode02046b24** list = *(struct HeadNode02046b24***)(obj + 0x3000 + RegionOffset6fc);
    held = battle->GetWanderingMonsterByIndex(info->field12);
    if (func_02086ef0((struct ArrayContainsByteStruct*)GameState_GetParty(battle), info->field12)) {
        return;
    }
    if (!held) {
        return;
    }
    if (FieldTaskQueue_GetCurrentKind(list) == 0xa) {
        int var2 = info->field12 <= 3;
        if (!var2) {
            return;
        }
        if (!(held->obj3D_.unknown_0_ & 0x80)) {
            return;
        }
        GameObject* target = func_0200ff1c(battle, info->field12);
        if (!target) {
            return;
        }
        int buf[3];
        __clear(buf, 0xc);
        buf[1] = info->field10;
        *(Vector3i*)((int*)((char*)target + Enum_ov017_021ceee0_352)) = *(Vector3i const*)info->vec;
        *(Vector3i*)((int*)((char*)target + Enum_ov017_021ceee0_364)) = *(Vector3i const*)buf;
        return;
    }
    if (FieldTaskQueue_GetCurrentKind(list) == 4) {
        return;
    }
    *(Vector3i*)(&held->obj3D_.position_.x) = *(Vector3i const*)info->vec;
    if (info->unknown_13_ == 0) {
        GameObject_SetFacing((struct Obj02033834*)held, info->field10);
    } else {
        GameObject_SnapFacing((struct Obj02033874*)held, info->field10);
    }
}
