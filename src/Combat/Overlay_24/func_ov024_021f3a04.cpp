#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>

struct Struct_ov024_021f3a04 { char pad[0x2c]; short unknown_2c_; };
extern "C" GameObject* func_ov000_021536f8(int, int);
extern "C" float func_ov024_021db358(GameObject*);
extern "C" int func_ov000_0215eb1c(int, short*, int, int);
extern const short data_ov024_021fee3c[8] __attribute__((aligned(4)));

// USA: func_ov024_021f3a04
extern "C" ARM int func_ov024_021f3a04(int* context, int id, void*, int* outCount, short* arg4) {
    GameObject* var0 = func_ov000_021536f8(*context, id);
    if (!var0) return 0;
    if (func_ov024_021db358(var0) < 0.5f) return 0;
    short table[8];
    const short* source = data_ov024_021fee3c;
    short* destination = table;
    int remaining = 8;
    do {
        *(unsigned short*)destination++ = *(const unsigned short*)source++;
    } while (--remaining);
    int count = func_ov000_0215eb1c(*context, table, 8, 1);
    if (count <= 0) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        if (table[i] == id) continue;
        GameObject* combatant = GetCombatantByID(*context, table[i]);
        if (!combatant) continue;
        if (func_ov024_021db358(combatant) >= 0.5f) continue;
        if (((Struct_ov024_021f3a04*)combatant->currentStats_)->unknown_2c_ > 0) continue;
        int index = *outCount;
        *outCount = index + 1;
        arg4[index] = table[i];
    }
    if (*outCount * 2 < count) return 0;
    *outCount = 1;
    arg4[0] = id;
    return 1;
}
