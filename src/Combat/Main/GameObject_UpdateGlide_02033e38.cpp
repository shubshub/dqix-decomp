#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "World/Object3D.h"

ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

// The glide fields GameObject_Update's GameObjectFields names: GameObject_StartGlide sets both
struct GlidingObject {
    Object3D object;
    char unknownAc[0xc6 - 0xac];
    short glideSpeed;
    Vector3fix glideTarget;
};

// Main, originally AdjustPositionTowardTarget02033e38 (USA 0x02033e38, EUR 0x02033e48, JPN 0x02033970)
extern "C" ARM void GameObject_UpdateGlide(void* obj) {
    GlidingObject* self = (GlidingObject*)obj;
    short* glideSpeed = &self->glideSpeed;
    short speed = *glideSpeed;
    if (speed != 0) {
        Vector3i offset;
        Vector3fix_Subtract(&self->glideTarget, &self->object.position_, &offset);
        int distance = Vector3fix_Length(&offset);
        if (distance < speed) {
            self->object.position_ = self->glideTarget;
            *glideSpeed = 0;
        } else {
            int fraction = fix32_Divide(speed, distance);
            Vector3fixMultiplyScalar(&offset, fraction, &offset);
            Vector3i moved;
            Vector3fix_Add(&self->object.position_, &offset, &moved);
            self->object.position_ = moved;
        }
    }
}
