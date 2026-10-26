#include <globaldefs.h>

// The part of an NPC that walks it (its facing is at +0x64).
struct NpcWalker {
    char pad[0x64];
    int facing;
};

// Main, originally SetField0x64RoundedTo256_0203cdd8 (USA 0x0203cdd8, EUR 0x0203cde8, JPN 0x0203d310)
// Sets the facing to angle, rounded down to a multiple of 0x100 (the rounding-up test can never pass).
extern "C" ARM void NpcWalker_SetFacing(struct NpcWalker* walker, int angle) {
    int rounded = angle & ~0xff;
    walker->facing = angle;
    if ((unsigned int)(angle & 0xff) >= (unsigned int)-128) {
        rounded += 0x100;
    }
    walker->facing = rounded;
}
