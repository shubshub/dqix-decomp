#ifndef COMBAT_COMBATANTMOTION_H
#define COMBAT_COMBATANTMOTION_H

#include <globaldefs.h>
#include "std_library_functions.h"

class Object3D;
struct Struct_02040c2c;
struct Struct_02040c2c_2;
struct Struct_02040c2c_3;

struct Obj02040c2c {
    unsigned int flags;
    unsigned int unknown_4_;
    char unknown_8_[0x4];
    Struct_02040c2c* settings;
    Object3D* unknown_10_;
    Struct_02040c2c_2* spriteMotion;
    Struct_02040c2c_3* unknown_18_;
};

extern "C" void func_02040c2c(Obj02040c2c* entry, void* context,
                            int elapsedTicks, int movementTicks);


#endif
