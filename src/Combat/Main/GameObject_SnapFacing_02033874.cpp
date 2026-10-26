#include <globaldefs.h>

struct RotationVector {
    int x;
    int y;
    int z;
};

struct GameObjectTimerBits {
    unsigned short sinkTimer : 15;
    unsigned short turningInPlace : 1;
};

struct Obj02033874 {
    char pad[0x50];
    struct RotationVector rotation;
    char pad2[0x52];
    short facing;
    char pad3[0xc4 - 0xb0];
    struct GameObjectTimerBits timerBits;
};

short fix32ReduceAngle0To2Pi(int);

// Main, originally SetVecYFromValue02033874 (USA 0x02033874, EUR 0x02033884, JPN 0x020333ac)
ARM void GameObject_SnapFacing(struct Obj02033874* self, int angle) {
    struct RotationVector* rotationOut = (struct RotationVector*)((char*)self + 0x50);
    struct RotationVector* rotationIn = (struct RotationVector*)((char*)self + 0x50);
    int x, y, z;
    self->facing = fix32ReduceAngle0To2Pi(angle);
    z = rotationIn->z;
    y = self->facing;
    x = rotationIn->x;
    rotationOut->x = x;
    rotationOut->y = y;
    rotationOut->z = z;
    self->timerBits.turningInPlace = 0;
}
