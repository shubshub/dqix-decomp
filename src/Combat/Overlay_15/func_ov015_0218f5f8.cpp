#include <globaldefs.h>
#include "World/Object3D.h"
#include "Graphics/Vector.h"

struct Struct_ov015_0218c03c_2
{
    char unk_0[0x1c];
    unsigned char kind_;
    char unknown_1d_[3];
    int* parts_;
    Object3D* objects_;
};

static inline const Vector3fix& inline_ov015_0218f5f8(const Object3D* o)
{
    return o->rotation_;
}

static inline void inline_ov015_0218f5f8_2(Object3D* o, const Vector3fix& rotation)
{
    o->rotation_ = rotation;
}

// USA: func_ov015_0218f5f8
extern "C" ARM void func_ov015_0218f5f8(Struct_ov015_0218c03c_2* self, int angle)
{
    Vector3fix rotation = {0};
    switch (self->kind_)
    {
    case 0:
        rotation = inline_ov015_0218f5f8(&self->objects_[1]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        inline_ov015_0218f5f8_2(&self->objects_[1], rotation);
        rotation = inline_ov015_0218f5f8(&self->objects_[0]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        inline_ov015_0218f5f8_2(&self->objects_[0], rotation);
        break;
    case 1:
        rotation = inline_ov015_0218f5f8(&self->objects_[6]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        inline_ov015_0218f5f8_2(&self->objects_[6], rotation);
        rotation = inline_ov015_0218f5f8(&self->objects_[1]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        inline_ov015_0218f5f8_2(&self->objects_[1], rotation);
        rotation = inline_ov015_0218f5f8(&self->objects_[5]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        inline_ov015_0218f5f8_2(&self->objects_[5], rotation);
        rotation = inline_ov015_0218f5f8(&self->objects_[0]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        inline_ov015_0218f5f8_2(&self->objects_[0], rotation);
        break;
    default:
        rotation = inline_ov015_0218f5f8(self->objects_);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        inline_ov015_0218f5f8_2(self->objects_, rotation);
        break;
    }
}
