#include <globaldefs.h>

struct PointerField330_ffd0 {
    char unk[0x330];
    void* field;
};

// Main, originally GetPointerAt0x330_0200ffd0 (USA 0x0200ffd0, EUR 0x0200ffe0, JPN 0x0200fe2c)
ARM void* GameState_GetStarflight(struct PointerField330_ffd0* gameState) {
    return gameState->field ? gameState->field : 0;
}
