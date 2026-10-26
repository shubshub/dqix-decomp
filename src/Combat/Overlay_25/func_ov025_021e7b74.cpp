#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include <std_library_functions.h>

struct Struct_02070f98_2;
struct Struct_02070fe4;
struct Struct_02070f98 { unsigned short id : 15; unsigned short flag : 1; };
struct Struct_ov025_021e7b74 { char pad0[0x400]; unsigned int data[3]; };
struct Struct_ov025_021e7b74_2 { char pad0[0x284]; Struct_ov025_021e7b74 unknown_284_; };
struct CameraState { char pad0[0x240]; Vector3i position; };
struct Obj02033874;
extern "C" Struct_ov025_021e7b74_2* func_ov017_021b8478(void*);
extern "C" void* func_ov000_02160130();
extern "C" int func_ov000_0215eb1c(void*, short*, int, int);
extern "C" int func_ov000_0215ed34(void*, short*, int);
extern "C" int func_ov000_02167484(short*, int);
extern "C" int func_02070fe4(Struct_02070fe4*);
extern "C" Struct_02070f98* func_02070f98(Struct_02070f98_2*, int);
extern "C" void func_ov025_021e771c(short*, int, short*, int);
extern "C" void func_ov000_02161c0c(void*, int);
extern "C" void func_0200fd48(GameState*, int);
extern "C" void func_ov000_021677fc(void*);
extern "C" void func_ov000_02167e6c(unsigned char*);
extern "C" CameraState* func_ov000_02160f14(void*);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" unsigned char* func_ov000_02163524(void*);
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" int func_020493a4(unsigned char*);
extern "C" void func_ov000_02167fb0(void*, GameObject*);
extern "C" void func_020d7334(unsigned char*, int);

// USA: func_ov025_021e7b74
extern "C" ARM int func_ov025_021e7b74(void*, void*, void*, void* battle) {
    int var0;
    Struct_ov025_021e7b74* var1;
    GameResources* resources = GetGameResources();
    GameState* game = GameState::GetInstance();
    Struct_ov025_021e7b74_2* selection = func_ov017_021b8478(resources->unknown_ptr_3718);
    void* work = func_ov000_02160130();
    short var6[8];
    var0 = (unsigned char)func_ov000_0215eb1c(battle, var6, 8, 0x10);
    short ids[12];
    unsigned char var8 = func_ov000_0215ed34(battle, ids, 12);
    unsigned char count = func_ov000_02167484(ids, var8);
    var1 = &selection->unknown_284_;
    int size = func_02070fe4((Struct_02070fe4*)var1->data);
    for (int i = 0; i < size; ++i) {
        Struct_02070f98* definition = func_02070f98((Struct_02070f98_2*)var1->data, i);
        if (!definition) continue;
        int var13 = 1;
        short* id = ids;
        for (int j = 0; j < count; ++j, ++id) {
            if (definition->id == *id) { var13 = 0; break; }
        }
        if (var13) ids[count++] = definition->id;
    }
    func_ov025_021e771c(ids, var8, ids, count);
    unsigned char var16[8];
    memset(var16, 0, sizeof(var16));
    short* var17 = var6;
    for (int i = 0; i < var0; ++i) {
        int id = *var17;
        var17++;
        var16[id - 0xc0] = 1;
        func_ov000_02161c0c(work, id);
    }
    unsigned char* var20 = var16;
    for (short id = 0xc0; id <= 0xc7; ++id, ++var20) {
        if (!*var20) func_0200fd48(game, id);
    }
    func_ov000_021677fc(work);
    func_ov000_02167e6c((unsigned char*)work);
    Vector3i var22 = func_ov000_02160f14(work)->position;
    int cameraZ = var22.z;
    for (int id = 0xc0; id < 0xc8; ++id) {
        GameObject* actor = game->GetCombatantByIndex(id);
        if (!actor) continue;
        Vector3i target = {};
        target.z = cameraZ;
        Vector3i position = actor->obj3D_.position_;
        position.y = 0;
        Vector3i direction;
        Vector3fix_Subtract(&target, &position, &direction);
        direction.y = 0;
        Vector3fix_Normalize(&direction, &direction);
        GameObject_SnapFacing((Obj02033874*)actor, fix32_Atan2(direction.x, direction.z));
    }
    unsigned char* slots = func_ov000_02163524(work);
    short* var30 = var6;
    for (int i = 0; i < var0; ++var30, ++i) {
        GameObject* actor = func_0200fea4(game, *var30);
        if (actor && func_020493a4((unsigned char*)actor) == 0xff) {
            func_ov000_02167fb0(work, actor);
            func_020d7334(slots, *var30);
        }
    }
    return 1;
}
