#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

// The part of an NPC that walks it (the NPC's +0x20; Npc_WalkTo reaches it through the NPC's +0x14).
struct NpcWalker {
    int unknown0;
    Vector3i position;          // the NPC's position (the NPC's +0x24)
    char pad10[0x5c - 0x10];
    int flags;                  // 1: walking to target; 4: walks without turning
    char pad60[0x64 - 0x60];
    int facing;                 // NpcWalker_SetFacing
    char pad68[0x78 - 0x68];
    Vector3i target;            // where it walks to
};
extern "C" void NpcWalker_SetFacing(NpcWalker* obj, int value);

// Main, originally func_0203ce14 (USA 0x0203ce14, EUR 0x0203ce24, JPN 0x0203d34c)
extern "C" ARM void NpcWalker_WalkTo(NpcWalker* self, Vector3i* target) {
    int distance = Vector3fix_Distance(target, &self->position);
    if (distance == 0) {
        return;
    }
    self->target = *target;
    int flags = self->flags;
    flags |= 1;
    self->flags = flags;
    if (flags & 4) {
        return;
    }
    Vector3i direction;
    Vector3fix_Subtract(&self->target, &self->position, &direction);
    int scale = fix32_Divide(0x1000, distance);
    Vector3fixMultiplyScalar(&direction, scale, &direction);
    int angle = fix32_Atan2(direction.x, direction.z);
    NpcWalker_SetFacing(self, angle);
}
