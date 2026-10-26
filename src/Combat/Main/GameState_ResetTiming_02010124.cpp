#include <globaldefs.h>

struct S_02010124 {
    char unk[0x3b4];
    int effectiveDeltaTimeMilliseconds_;
    int trueDeltaTimeMilliseconds_;
    unsigned short gameSpeed_;
    char pad[2];
    int animationDeltaTime_;
    int numTicks_;
};

// Main, originally InitFields02010124 (USA 0x02010124, EUR 0x02010134, JPN 0x0200ff80)
ARM void GameState_ResetTiming(struct S_02010124* gameState) {
    gameState->effectiveDeltaTimeMilliseconds_ = 0x21;
    gameState->trueDeltaTimeMilliseconds_ = 0x21;
    gameState->gameSpeed_ = 0x1000;
    gameState->numTicks_ = 2;
    gameState->animationDeltaTime_ = 0x2000;
}
