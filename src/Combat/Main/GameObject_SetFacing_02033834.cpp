#include <globaldefs.h>

struct Obj02033874;

struct GameObjectTimerBits {
    unsigned short sinkTimer : 15;
    unsigned short turningInPlace : 1;
};

struct Obj02033834 {
    char pad0[0xae];
    short facing;
    char pad1[0x0e];
    unsigned char motionState;
    char pad2[0x05];
    struct GameObjectTimerBits timerBits;
};

short fix32ReduceAngle0To2Pi(int);
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);

// Main, originally SetVecYByMode02033834 (USA 0x02033834, EUR 0x02033844, JPN 0x0203336c)
extern "C" ARM void GameObject_SetFacing(struct Obj02033834* self, int angle) {
    if (self->motionState == 4 || self->motionState == 3) {
        GameObject_SnapFacing((struct Obj02033874*)self, angle);
    } else {
        self->facing = fix32ReduceAngle0To2Pi(angle);
    }
    self->timerBits.turningInPlace = 0;
}
