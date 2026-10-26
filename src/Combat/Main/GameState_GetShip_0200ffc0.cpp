#include <globaldefs.h>

struct PointerField32c_ffc0 {
    char unk[0x32c];
    void* field;
};

// Main, originally GetPointerAt0x32c_0200ffc0 (USA 0x0200ffc0, EUR 0x0200ffd0, JPN 0x0200fe1c)
ARM void* GameState_GetShip(struct PointerField32c_ffc0* gameState) {
    return gameState->field ? gameState->field : 0;
}
