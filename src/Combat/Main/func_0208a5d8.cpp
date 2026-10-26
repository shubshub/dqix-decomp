#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_0208a03c(void* p0, int arg1, int id, int* outPtr, int p3);
extern "C" int func_ov000_02154a04(int field0, int id, int flag, int p3);

// USA: func_0208a5d8
extern "C" ARM int func_0208a5d8(int* p0, int id, int* outPtr, int p3) {
    unsigned char i;
    GameState* bs;
    GameObject* combatant;
    struct ModifiableCombatStats* stats;
    unsigned char* var4;
    char* var5;
    struct Random* var6;
    unsigned char bit;
    unsigned char var8;
    unsigned char base;
    unsigned char var10;
    unsigned char slotB;

    bs = GameState::GetInstance();
    combatant = func_0200fea4(bs, id);
    var5 = *(char**)((char*)combatant + 0x148);
    stats = combatant->currentStats_;
    var4 = (unsigned char*)((char*)stats + 0x38);
    *var4 = *var4 % 3u;
    i = 0;
    var6 = (struct Random*)*p0;

    while (i < 3) {
        bit = NextRandom(var6) & 1;
        var8 = bit ^ 1;
        base = *var4 * 2;
        var10 = base + bit;
        slotB = base + var8;
        *var4 = *var4 + 1;
        *var4 = *var4 % 3u;
        if (func_0208a03c(p0, var10, id, outPtr, p3) != 0) {
            return *(unsigned short*)(var5 + var10 * 2 + 0x18);
        }
        if (func_0208a03c(p0, slotB, id, outPtr, p3) != 0) {
            return *(unsigned short*)(var5 + slotB * 2 + 0x18);
        }
        i = i + 1;
    }
    *outPtr = 0;
    *outPtr = func_ov000_02154a04(*p0, id, 2, p3);
    return 2;
}
