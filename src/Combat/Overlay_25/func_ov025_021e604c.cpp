#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02049b54_2;
struct Obj02033874;

struct Vec3 {
    fix32_t v[3];
};

extern "C" void* func_ov000_02160130();
extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" void func_02049f28(unsigned char* obj);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" void func_02049b54(struct Vec3* out, struct Struct_02049b54_2* obj);
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);
extern "C" void func_02049bac(unsigned char* obj, int* src);
extern "C" void func_ov000_02161c0c(void* work, int id);
extern "C" void func_ov000_02167fb0(void* work, GameObject* obj);
extern "C" void func_ov000_021677fc(void* work);
extern "C" void* func_ov000_02160f14(void* work);
extern "C" int func_ov000_0215eb1c(void* obj, short* ids, int count, int flag);
extern "C" void __clear(void* dst, int size);

extern char data_ov025_021ef802[];

struct Struct_ov025_021e604c {
    char pad[0x240];
    struct Vec3 center;
};

// USA: func_ov025_021e604c
extern "C" ARM int func_ov025_021e604c(void* unused0, int b, int arg2, void* c) {
    int ids[8];
    struct Vec3 pos;
    Vector3fix rot;
    Vector3fix dir;
    struct Vec3 from;
    Vector3fix target;
    struct Vec3 center;
    short var7[8];
    int j;
    int centerZ;
    int var10;
    GameState* battle;
    GameState* bs = GameState::GetInstance();
    void* work = func_ov000_02160130();
    if (work == NULL) {
        return 1;
    }
    int count = func_ov000_021820bc(c, b, 0x18, (int)ids);
    for (int i = 0; i < count; i++) {
        GameObject* obj = bs->GetCombatantByIndex(ids[i]);
        if (obj != NULL) {
            func_ov000_02161c0c(work, ids[i]);
            func_02049f28((unsigned char*)obj);
            func_ov000_02167fb0(work, obj);
            obj->obj3D_.SetAnimationByName(data_ov025_021ef802, 1);
        }
    }
    func_ov000_021677fc(work);
    struct Struct_ov025_021e604c* formation = (struct Struct_ov025_021e604c*)func_ov000_02160f14(work);
    battle = GameState::GetInstance();
    battle->GetResources();
    var10 = func_ov000_0215eb1c(c, var7, 8, 0);
    center = formation->center;
    centerZ = center.v[2];
    for (j = 0; j < var10; j++) {
        GameObject* enemy = func_0200fea4(battle, var7[j]);
        if (enemy != NULL) {
            __clear(&target, 0xc);
            target.z = centerZ;
            func_02049b54(&pos, (struct Struct_02049b54_2*)enemy);
            from = pos;
            from.v[1] = 0;
            Vector3fix_Subtract(&target, (Vector3fix*)&from, &dir);
            dir.y = 0;
            Vector3fix_Normalize(&dir, &dir);
            int angle = fix32_Atan2(dir.x, dir.z);
            GameObject_SnapFacing((struct Obj02033874*)enemy, angle);
            __clear(&rot, 0xc);
            rot.y = angle;
            func_02049bac((unsigned char*)enemy, (int*)&rot);
        }
    }
    return 1;
}
