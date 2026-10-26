#include <globaldefs.h>

struct Flags02033fcc {
    char unknown0[0xe0];
    unsigned char flagsE0;
};

// GameObject_Update skips the turn, the movement, the glide and the motion-state step while it is set
enum { GameObjectFlagsE0_Paused = 0x4 };

// Main, originally SetFlag0x4At0xe0 (USA 0x02033fcc, EUR 0x02033fdc, JPN 0x02033b04)
ARM void GameObject_PauseMovement(struct Flags02033fcc* object) {
    object->flagsE0 |= GameObjectFlagsE0_Paused;
}
