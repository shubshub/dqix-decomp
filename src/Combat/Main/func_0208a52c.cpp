#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_0208a03c(void* p0, int arg1, int id, int* outPtr, int p3);
extern "C" int func_ov000_02154a04(int field0, int id, int flag, int p3);

// USA: func_0208a52c
extern "C" ARM int func_0208a52c(int* p0, int id, int* outPtr, int p3) {
    GameState* bs;
    GameObject* combatant;
    char* var2;
    struct ModifiableCombatStats* stats;
    unsigned char* var4;
    unsigned char old;
    unsigned char i;

    bs = GameState::GetInstance();
    combatant = func_0200fea4(bs, id);
    var2 = *(char**)((char*)combatant + 0x148);
    stats = combatant->currentStats_;
    var4 = (unsigned char*)((char*)stats + 0x38);

    for (i = 0; i < 6; i++) {
        old = *var4;
        *var4 = old + 1;
        *var4 = *var4 % 6;
        if (func_0208a03c(p0, old, id, outPtr, p3) != 0) {
            return *(unsigned short*)(var2 + old * 2 + 0x18);
        }
    }
    *outPtr = 0;
    *outPtr = func_ov000_02154a04(*p0, id, 2, p3);
    return 2;
}
