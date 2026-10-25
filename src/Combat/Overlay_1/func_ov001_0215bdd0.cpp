#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void* p);
extern int AbsPlus159IfNegative0215ad2c(int x);
extern "C" void func_ov001_0215acb4(void* entry);
int GameState_GetProtagonistIndex(GameState* gs);
int SetQueueEntryChecked_02164214(void* arr, int idx, int type, int val, int flag);
int SetQueueEntryChecked_02164248(void* arr, int idx, int type, int val, int flag);

#include "Combat/EntryGetterTypes.h"
struct Struct_0203dce4_2;
extern "C" void* func_0203cf4c(void);
extern "C" struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2* arg0, int arg1);

struct Struct_ov001_02165880_10 { void* unknown_0_; char* unknown_4_; };
extern Struct_ov001_02165880_10 data_ov001_02165880;

// USA: func_ov001_0215bdd0
extern "C" ARM int func_ov001_0215bdd0(char* arg0) {
    GameState* var0 = GameState::GetInstance();
    int var1;
    int var2 = func_ov017_021d60f4(arg0);
    var1 = func_ov017_021d60f4(arg0 + 0x8);
    int var3 = func_ov017_021d60f4(arg0 + 0x10);
    var1 = func_ov001_0215ad2c(var1);

    func_ov001_0215acb4(data_ov001_02165880.unknown_4_ + (var2 << 4));

    if (type == 0 || type == 1 || (unsigned)(type - 4) <= 1) {
        GameObject* obj = NULL;
        if (type == 0) {
            obj = gs->GetGameObjectByIndex(GameState_GetProtagonistIndex(gs));
        } else if (type == 1) {
            obj = gs->GetGameObjectByIndex(id);
        } else if (type == 4) {
            obj = gs->GetGameObjectByIndex(0);
        } else if (type == 5) {
            obj = gs->GetGameObjectByIndex(id);
        }
        if (var4 == NULL) return 0;
        return func_ov001_02164214(data_ov001_02165880.unknown_4_, var2, var3, var1, (int)var4);
    }

    if (var3 == 2 || var3 == 6) {
        struct Struct_0203dce4* var5 = func_0203dce4((struct Struct_0203dce4_2*)func_0203cf4c(), var1);
        if (var5 == NULL) return 0;
        var5->unknown_0_ |= 0x10000;
        return func_ov001_02164248(data_ov001_02165880.unknown_4_, var2, var3, var1, (int)var5);
    }
    return 0;
}
