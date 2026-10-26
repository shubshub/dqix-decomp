#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"

struct Struct_02000c9c_37 { int a; int b; int c; int d; };
struct Struct_ov001_02165880_7 { char pad0[4]; Struct_02000c9c_37* table; };
extern Struct_ov001_02165880_7 data_ov001_02165880;

struct Struct_ov001_0215ab54 { char pad0[0x90]; fix32_t radius; };

struct Struct_0203dce4;
struct Struct_0203dce4_2;
extern "C" Struct_0203dce4_2* func_0203cf4c(void);
extern "C" Struct_0203dce4* func_0203dce4(Struct_0203dce4_2* list, int id);
extern "C" int GameState_GetProtagonistIndex(GameState* state);
extern "C" void func_ov001_02164214(void* table, int slot, int mode, int id, int target);
extern "C" void func_ov001_02164248(void* table, int slot, int mode, int id, int target);

extern "C" void func_ov001_0215acb4(Struct_02000c9c_37* entry);
extern "C" Struct_ov001_0215ab54* func_ov001_0215ab20(int index);
extern "C" void func_ov001_02159d9c(void* obj);
extern "C" void func_ov001_02159ea8(void* obj, int v);

// USA: func_ov001_0215ab54
extern "C" ARM void func_ov001_0215ab54(int mode, int id, int slot) {
    GameState* state = GameState::GetInstance();
    fix32_t radius = 0x1000;
    func_ov001_0215acb4(&data_ov001_02165880.table[slot]);

    if (mode == 0 || mode == 1 || mode == 4 || mode == 5) {
        GameObject* object = NULL;
        if (mode == 0) {
            object = state->GetGameObjectByIndex(GameState_GetProtagonistIndex(state));
        } else if (mode == 1) {
            object = state->GetGameObjectByIndex(id);
        } else if (mode == 4) {
            object = state->GetGameObjectByIndex(0);
        } else if (mode == 5) {
            object = state->GetGameObjectByIndex(id);
        }
        if (object == NULL) return;
        func_ov001_02164214(data_ov001_02165880.table, slot, mode, id, (int)object);
        radius = object->obj3D_.GetRadius();
    } else if (mode == 2 || mode == 6) {
        Struct_0203dce4* entry = func_0203dce4(func_0203cf4c(), id);
        if (entry == NULL) return;
        func_ov001_02164248(data_ov001_02165880.table, slot, mode, id, (int)entry);
    }

    Struct_ov001_0215ab54* var4 = func_ov001_0215ab20(slot);
    if (var4 == NULL) return;
    func_ov001_02159d9c(var4);
    func_ov001_02159ea8(var4, slot);
    var4->radius = radius;
}
