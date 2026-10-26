#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" int Camera_GetKindFlags(int);

// Main, originally GetFieldIfFlag4_020100f8 (USA 0x020100f8, EUR 0x02010108, JPN 0x0200ff54)
extern "C" ARM int GameState_GetFollowCamera(char* gameState) {
    void* camera = ((GameState*)gameState)->camera_;
    if (camera != 0) {
        if (Camera_GetKindFlags((int)camera) & 4) {
            return (int)((GameState*)gameState)->camera_;
        }
    }
    return 0;
}
