#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void GameState_CollectPartyObjectIndices(GameState* gameState, int* outList, int* outCount);

// The link session's party size byte, the last byte before the player name's length in the beacon's user game info.
enum { kPartySizeOffset = 0x1027 };

// Main, originally StoreValidCombatantCount0202c3e0 (USA 0x0202c3e0, EUR 0x0202c3f0, JPN 0x0202bf6c)
extern "C" ARM void LinkSession_UpdatePartySize(void* session) {
    GameState* gameState = GameState::GetInstance();
    int memberIndices[4];
    int memberCount;
    GameState_CollectPartyObjectIndices(gameState, memberIndices, &memberCount);
    *((unsigned char*)session + kPartySizeOffset) = (unsigned char)memberCount;
}
