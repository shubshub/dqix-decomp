#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_01ff8b48_2 {
    int x;
    int y;
    int z;
};

void Vector3fixDivideScalar(Vector3i const*, int, Vector3i*);

struct Struct_020a1034 {
    int unknown_0_;
    Vector3i unknown_4_;
    Vector3i unknown_10_;
    char unk_1c[0x8];
    int unknown_24_;
};

// USA: func_020a1034
extern "C" ARM void func_020a1034(struct Struct_020a1034* obj) {
    Vector3i diff;
    Vector3fix_Subtract(&obj->unknown_10_, &obj->unknown_4_, &diff);
    if (Vector3fix_Length(&diff) < 0x199) {
        obj->unknown_4_ = obj->unknown_10_;
        obj->unknown_0_ = 0;
    } else {
        Vector3i var1;
        Vector3fixDivideScalar(&diff, obj->unknown_24_, &var1);
        Vector3fix_Add(&obj->unknown_4_, &var1, &obj->unknown_4_);
    }
}
