#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "World/Object3D.h"

ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

int fix32ReduceAngle0To2Pi(int angle);

extern char data_020efe6c;
extern char data_020efe71;

struct Obj02041470 : Object3D {
    unsigned short unknown_ac_;
    int unknown_b0_;
    Vector3i unknown_b4_;
    char pad2[0xd0 - 0xc0];
    int unknown_d0_;
    unsigned char unknown_d4_0_ : 1;
    unsigned char unknown_d4_1_ : 1;
    unsigned char unknown_d4_2_ : 6;
};

// Main, originally func_02041470 (USA 0x02041470, EUR 0x02041480, JPN 0x0204196c)
extern "C" ARM void NpcModel_WalkTo(struct Obj02041470* obj, Vector3i* target) {
    int dist = Vector3fix_Distance(target, &obj->position_);
    if (dist == 0) {
        return;
    }
    obj->unknown_b4_ = *target;
    obj->unknown_ac_ |= 1;
    int mode = obj->unknown_d0_;
    if (!obj->unknown_d4_1_) {
        obj->SetAnimationByName(&data_020efe6c, mode);
    } else {
        obj->SetAnimationByName(&data_020efe71, mode);
    }
    if (!(obj->unknown_ac_ & 4)) {
        Vector3i diff;
        Vector3fix_Subtract(&obj->unknown_b4_, &obj->position_, &diff);
        int scale = fix32_Divide(0x1000, dist);
        Vector3fixMultiplyScalar(&diff, scale, &diff);
        int angle = fix32_Atan2(diff.x, diff.z);
        obj->unknown_b0_ = fix32ReduceAngle0To2Pi(angle);
    }
}
