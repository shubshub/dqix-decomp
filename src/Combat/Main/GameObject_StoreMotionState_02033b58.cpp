#include <globaldefs.h>

struct Foo02033b58 {
    char pad0[0xbe];
    unsigned char motionState;
    unsigned char previousMotionState;
};

// Main, originally SetByteSavingPrevious (USA 0x02033b58, EUR 0x02033b68, JPN 0x02033690)
ARM void GameObject_StoreMotionState(struct Foo02033b58* self, unsigned char state) {
    self->previousMotionState = self->motionState;
    self->motionState = state;
}
