#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae24(void);
extern "C" void func_0205e330(void* arg0, void* arg1, int arg2);
extern "C" void func_0202ae18(void);
void* GameState_GetParty(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);

struct Struct_ov017_021c8654 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    int unknown_4_[4];
};

// USA: func_ov017_021c8654
extern "C" ARM void func_ov017_021c8654(void) {
    GameState* var0 = GameState::GetInstance();
    func_0202ae18();
    void* var1 = func_0202ae24();
    struct Struct_ov017_021c8654 var2;
    var2.unknown_0_ = 0x77;
    int* var3 = var2.unknown_4_;
    for (int var4 = 0; var4 < 4; var4++) {
        var3[var4] = -1;
    }

    unsigned char* list = (unsigned char*)GameState_GetParty(bs);
    for (int i = 0; i < list[0xf7c]; i++) {
        unsigned char* row = list + i;
        unsigned char id = row[0xf78];
        GameObject* c = GetCombatantWithFlag0x1000_0200ff58(bs, id);
        if (c == NULL) {
            arr[id] = *(int*)(list + 0xf6c);
        }
    }

    func_0205e330(var1, &var2, 0);
}
