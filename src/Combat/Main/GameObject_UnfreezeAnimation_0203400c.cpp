#include <globaldefs.h>
#include "World/Object3D.h"
#include "Combat/ObjectStateInitialization.h"
struct ObjectStatePrefix;

enum {
    // Object3D flags_ bit 18: AdvanceAnimations_v0/_v1 stop the clock while it is set, except during "damage";
    // starting an animation clears it
    Object3DFlag_FreezeAnimation = 1 << 18,
    GameObject_flagsE0Offset = 0xe0,
};

// Main, originally ClearStateFlags0203400c (USA 0x0203400c, EUR 0x0203401c, JPN 0x02033b44)
ARM void GameObject_UnfreezeAnimation(ObjectStatePrefix* object) {
    unsigned char* bytes = (unsigned char*)object;
    object->object.DisableFlag(Object3DFlag_FreezeAnimation);
    bytes[GameObject_flagsE0Offset] &= ~0x2;  // set with the freeze by GameObject_FreezeAnimation; no reader found
}
