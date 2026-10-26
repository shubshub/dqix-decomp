#include <globaldefs.h>

#include "Graphics/Vector.h"
#include "World/Object3D.h"

extern "C" void func_0203db34(unsigned char *object, int x, int y, int z);

struct Struct_02041378 {
    Object3D object;
    unsigned short unknown_ac_;
    unsigned short unknown_ae_;
    fix32_t unknown_b0_;
};

// USA: func_02041378
extern "C" ARM void func_02041378(void *object) {
    Struct_02041378 *controller = (Struct_02041378 *) object;
    fix32_t target                     = controller->unknown_b0_;
    fix32_t current                    = controller->object.rotation_.y;
    if (current == target) {
        return;
    }

    fix32_t distance;
    if (current < target) {
        distance = target - current;
        if (distance > 0x3244) {
            distance -= FIX_2PI;
        }
    } else if (target < current) {
        distance = -(current - target);
        if (distance < -0x3244) {
            distance += FIX_2PI;
        }
    }

    int var4 = 0;
    if (distance > 0) {
        if (distance < 0x333) {
            distance = target;
        } else {
            distance = fix32ReduceAngle0To2Pi(current + 0x333);
        }
        controller->unknown_ac_ |= 2;
        var4 = 1;
    } else if (distance < 0) {
        if (-distance < 0x333) {
            distance = target;
        } else {
            distance = fix32ReduceAngle0To2Pi(current - 0x333);
        }
        controller->unknown_ac_ |= 2;
        var4 = 1;
    }

    if (!var4) {
        controller->unknown_ac_ &= ~2;
    }
    func_0203db34((unsigned char *) object, controller->object.rotation_.x, distance, controller->object.rotation_.z);
}
