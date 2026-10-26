#include <globaldefs.h>

struct Flags02033fdc {
    char unknown0[0xe0];
    unsigned char flagsE0;
};

// GameObject_Update skips the turn, the movement, the glide and the motion-state step while it is set
enum { GameObjectFlagsE0_Paused = 0x4 };

// Main, originally ClearFlag0x4At0xe0 (USA 0x02033fdc, EUR 0x02033fec, JPN 0x02033b14)
extern "C" ARM void GameObject_ResumeMovement(struct Flags02033fdc* object) {
    object->flagsE0 &= ~GameObjectFlagsE0_Paused;
}
