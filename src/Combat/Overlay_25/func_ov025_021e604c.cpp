#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02049b54_2;
struct Struct_02033834;

struct Struct_ov009_0218aa28 {
    fix32_t unknown_0_[3];
};

void* GetActiveCombatWork_ov000_02160130();
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
void SetSubstructByte0x56_02049f28(unsigned char* obj);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);
extern "C" void _Z20GetSubTriple02049b54P11Obj02049b54(struct Vec3* out, struct Obj02049b54* obj);
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);
void SetSubstructField0x8ClearFlag0x2_02049bac(unsigned char* obj, int* src);
extern "C" void func_ov000_02161c0c(void* work, int id);
extern "C" void func_ov000_02167fb0(void* work, GameObject* obj);
extern "C" void func_ov000_021677fc(void* work);
extern "C" void* func_ov000_02160f14(void* work);
extern "C" int func_ov000_0215eb1c(void* obj, short* ids, int count, int flag);
extern "C" void __clear(void* dst, int size);

extern char data_ov025_021ef802[];

struct Struct_ov025_021e604c {
    char unknown_0_[0x240];
    struct Struct_ov009_0218aa28 unknown_240_;
};

// USA: func_ov025_021e604c
extern "C" ARM int func_ov025_021e604c(void* arg0, int arg1, int arg2, void* arg3) {
    int var0[8];
    struct Struct_ov009_0218aa28 var1;
    Vector3fix var2;
    Vector3fix var3;
    struct Struct_ov009_0218aa28 var4;
    Vector3fix var5;
    struct Struct_ov009_0218aa28 var6;
    short var7[8];
    int var8;
    int var9;
    int var10;
    GameState* var11;
    GameState* var12 = GameState::GetInstance();
    void* var13 = func_ov000_02160130();
    if (var13 == NULL) {
        return 1;
    }
    int count = DispatchByIndex021820bc(c, b, 0x18, (int)ids);
    for (int i = 0; i < count; i++) {
        GameObject* obj = bs->GetCombatantByIndex(ids[i]);
        if (obj != NULL) {
            func_ov000_02161c0c(work, ids[i]);
            SetSubstructByte0x56_02049f28((unsigned char*)obj);
            func_ov000_02167fb0(work, obj);
            obj->obj3D_.SetAnimationByName(data_ov025_021ef802, 1);
        }
    }
    func_ov000_021677fc(work);
    struct Formation021e604c* formation = (struct Formation021e604c*)func_ov000_02160f14(work);
    battle = GameState::GetInstance();
    battle->GetResources();
    enemyCount = func_ov000_0215eb1c(c, enemyIds, 8, 0);
    center = formation->center;
    centerZ = center.v[2];
    for (j = 0; j < enemyCount; j++) {
        GameObject* enemy = GetCombatantWithFlag0x400_0200fea4(battle, enemyIds[j]);
        if (enemy != NULL) {
            __clear(&target, 0xc);
            target.z = centerZ;
            _Z20GetSubTriple02049b54P11Obj02049b54(&pos, (struct Obj02049b54*)enemy);
            from = pos;
            from.v[1] = 0;
            Vector3fix_Subtract(&target, (Vector3fix*)&from, &dir);
            dir.y = 0;
            Vector3fix_Normalize(&dir, &dir);
            int angle = fix32_Atan2(dir.x, dir.z);
            GameObject_SnapFacing((struct Obj02033874*)enemy, angle);
            __clear(&rot, 0xc);
            rot.y = angle;
            SetSubstructField0x8ClearFlag0x2_02049bac((unsigned char*)enemy, (int*)&rot);
        }
    }
    return 1;
}
