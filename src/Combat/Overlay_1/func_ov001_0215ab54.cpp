#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"

struct Struct_02000c9c_37 { int unknown_0_; int unknown_4_; int unknown_8_; int unknown_c_; };
struct Struct_ov001_02165880_7 { char unknown_0_[4]; Struct_02000c9c_37* unknown_4_; };
extern Struct_ov001_02165880_7 data_ov001_02165880;

struct Struct_ov001_0215ab54 { char unknown_0_[0x90]; fix32_t unknown_90_; };

struct Entry_203dce4;
struct EntryList_203dce4;
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c(void);
Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4* list, int id);
int GameState_GetProtagonistIndex(GameState* state);
void SetQueueEntryChecked_02164214(void* table, int slot, int mode, int id, int target);
void SetQueueEntryChecked_02164248(void* table, int slot, int mode, int id, int target);

extern "C" void func_ov001_0215acb4(Struct_02000c9c_37* arg0);
extern "C" Struct_ov001_0215ab54* func_ov001_0215ab20(int arg0);
extern "C" void func_ov001_02159d9c(void* arg0);
extern "C" void func_ov001_02159ea8(void* arg0, int arg1);

// USA: func_ov001_0215ab54
extern "C" ARM void func_ov001_0215ab54(int arg0, int arg1, int arg2) {
    GameState* var0 = GameState::GetInstance();
    fix32_t var1 = 0x1000;
    func_ov001_0215acb4(&data_ov001_02165880.unknown_4_[arg2]);

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
        if (var2 == NULL) return;
        func_ov001_02164214(data_ov001_02165880.unknown_4_, arg2, arg0, arg1, (int)var2);
        var1 = var2->obj3D_.GetRadius();
    } else if (arg0 == 2 || arg0 == 6) {
        Struct_0203dce4* var3 = func_0203dce4(func_0203cf4c(), arg1);
        if (var3 == NULL) return;
        func_ov001_02164248(data_ov001_02165880.unknown_4_, arg2, arg0, arg1, (int)var3);
    }

    Struct_ov001_0215ab54* var4 = func_ov001_0215ab20(arg2);
    if (var4 == NULL) return;
    func_ov001_02159d9c(var4);
    func_ov001_02159ea8(var4, arg2);
    var4->unknown_90_ = var1;
}
