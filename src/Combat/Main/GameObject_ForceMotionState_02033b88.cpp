#include <globaldefs.h>

extern "C" int GameObject_ApplyMotionState(void* obj, int val);

struct Bytes02033b88 {
    char pad[0xbe];
    unsigned char motionState;
    unsigned char previousMotionState;
};

// Main, originally SetByte0xbeShiftPrev (USA 0x02033b88, EUR 0x02033b98, JPN 0x020336c0)
extern "C" ARM int GameObject_ForceMotionState(struct Bytes02033b88* self, int state) {
    self->previousMotionState = self->motionState;
    self->motionState = (unsigned char)state;
    return GameObject_ApplyMotionState(self, state);
}
