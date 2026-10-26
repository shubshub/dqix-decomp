#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct Field150Holder02052e2c;
struct Field150Holder02052e14;
extern "C" short* func_02052e2c(Field150Holder02052e2c* obj);
extern "C" short* func_02052e14(Field150Holder02052e14* obj);

struct Struct_020e8878 {
    int entries[11];
};
extern Struct_020e8878 data_020e8878;

// USA: func_02072afc
extern "C" ARM void func_02072afc(int combatantId, int* outIds, short* arg2) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == NULL) return;
    short* var1 = func_02052e2c((Field150Holder02052e2c*)combatant);
    if (var1 == NULL) return;
    short* effects = func_02052e14((Field150Holder02052e14*)combatant);
    Struct_020e8878 ids = data_020e8878;
    int base = combatantId * 12;
    ids.entries[0] = combatantId;
    ids.entries[1] = base + 19;
    ids.entries[2] = base + 20;
    ids.entries[3] = base + 21;
    ids.entries[4] = base + 22;
    ids.entries[5] = base + 23;
    ids.entries[6] = base + 25;
    ids.entries[7] = base + 27;
    ids.entries[8] = base + 28;
    ids.entries[9] = base + 29;
    short values[11] = {
        effects[0], effects[1], effects[2], effects[3], effects[3],
        effects[4], effects[5], effects[6], effects[7], effects[8], effects[9]
    };
    for (int i = 0; i < 11; i++) {
        outIds[i] = ids.entries[i];
        arg2[i] = values[i];
    }
    if (arg2[0] < 0) arg2[0] = 1000;
    if (arg2[1] < 0) arg2[1] = 8001;
    if (arg2[6] < 0) arg2[6] = 994;
    if (arg2[5] < 0) {
        arg2[5] = var1[11];
        if (arg2[5] < 0) arg2[5] = 8010;
    }
}
