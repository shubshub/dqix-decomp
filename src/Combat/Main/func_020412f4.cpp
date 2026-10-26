#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_ov001_021592bc {
    int x;
    int y;
    int z;
};

struct Struct_02040bcc;

void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);
extern "C" void func_02041538(struct Struct_02040bcc* self);

struct Struct_020412f4 {
    char pad0[0x44];
    Vector3i pos;
    char pad1[0xb4 - 0x50];
    Vector3i target;
    char pad2[0xc8 - 0xc0];
    int step;
};

// USA: func_020412f4
extern "C" ARM void func_020412f4(struct Struct_020412f4* obj) {
    Vector3i diff;
    Vector3fix_Subtract(&obj->target, &obj->pos, &diff);
    int length = Vector3fix_Length(&diff);
    if (obj->step < length) {
        int scale = fix32_Divide(obj->step, length);
        Vector3fixMultiplyScalar(&diff, scale, &diff);
        Vector3i sum;
        Vector3fix_Add(&obj->pos, &diff, &sum);
        obj->pos = sum;
    } else {
        obj->pos = obj->target;
        func_02041538((struct Struct_02040bcc*)obj);
    }
}
