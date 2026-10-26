#include <globaldefs.h>

extern "C" void GameObject_ApplyMotionState(void*);

struct Obj02033b68 {
    char pad[0xbe];
    unsigned char motionState;
    unsigned char previousMotionState;
};

// Main, originally SetByteIfChanged02033b68 (USA 0x02033b68, EUR 0x02033b78, JPN 0x020336a0)
ARM void GameObject_SetMotionState(struct Obj02033b68* self, int state) {
    if (self->motionState == state) return;
    self->previousMotionState = self->motionState;
    self->motionState = state;
    GameObject_ApplyMotionState(self);
}
