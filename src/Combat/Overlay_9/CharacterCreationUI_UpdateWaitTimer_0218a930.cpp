#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
// Overlay 9, originally func_ov009_0218a930 (USA/EUR 0x0218a930, JPN 0x0218b908)
extern "C" ARM int CharacterCreationUI_UpdateWaitTimer(CharacterCreationUI* self, int ticks) {
    short timer = self->waitTimer;
    if (timer > ticks) {
        self->waitTimer = timer - ticks;
        goto ret1;
    }
    self->waitTimer = 0;
    return 0;
ret1:
    return 1;
}
