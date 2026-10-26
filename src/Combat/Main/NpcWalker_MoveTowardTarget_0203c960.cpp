#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

// The sprite part's animation speed (1.0 plays at normal speed)
struct Struct_0203fc5c {
    char pad[0x40];
    float field40;
};
ARM int SetField40IfPositive(struct Struct_0203fc5c* obj, float value);

extern "C" double _dflt(int);

// An NpcWalker
struct MoverObj0203c960 {
    char pad0[4];
    Vector3i position;
    char pad1[0x4c];
    int flags;          // kWalking
    char pad2[0x18];
    Vector3i target;
    char pad3[8];
    int speed;          // distance per step
};

enum { kWalking = 1 };

// The walk animation plays at 1x when the speed is 0.03 (fx32 0x7a, NpcWalker's initial speed)
#define WALK_ANIMATION_SPEED 0.03

// Main, originally AdvanceOrSnapToTarget0203c960 (USA 0x0203c960, EUR 0x0203c970, JPN 0x0203ce98)
ARM void NpcWalker_MoveTowardTarget(struct MoverObj0203c960* walker) {
    Vector3i step;
    Vector3fix_Subtract(&walker->target, &walker->position, &step);
    int distance = Vector3fix_Length(&step);
    if (walker->speed < distance) {
        int scale = fix32_Divide(walker->speed, distance);
        Vector3fixMultiplyScalar(&step, scale, &step);
        Vector3i newPosition;
        Vector3fix_Add(&walker->position, &step, &newPosition);
        walker->position = newPosition;
        double speed = _dflt(walker->speed);
        float animationSpeed = (float)(speed / WALK_ANIMATION_SPEED / 4096.0);
        SetField40IfPositive((struct Struct_0203fc5c*)walker, animationSpeed);
        return;
    }
    walker->position = walker->target;
    walker->flags &= ~kWalking;
}
