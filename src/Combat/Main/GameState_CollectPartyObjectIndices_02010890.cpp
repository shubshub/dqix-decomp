#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff94(GameState* battleStruct, int combatantId);

// Main, originally CollectValidCombatants02010890 (USA 0x02010890, EUR 0x020108a0, JPN 0x020106ec)
extern "C" ARM void GameState_CollectPartyObjectIndices(GameState* gameState, int* outIndices, int* outCount) {
    int count = 0;
    int objectIndex;
    for (objectIndex = 0; objectIndex < 4; objectIndex++) {
        if (func_0200ff94(gameState, objectIndex)) {
            outIndices[count] = objectIndex;
            count++;
        }
    }
    *outCount = count;
}
