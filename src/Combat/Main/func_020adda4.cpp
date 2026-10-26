#include <globaldefs.h>
#include <NitroSDK/Matrix.h>
#include <Graphics/Vector.h>

struct Struct_020adda4 {
    unsigned char unknown_0_[0x44];
    Vector3fix origin;
    unsigned char unknown_50_[0x5e];
    short unknown_ae_;
    unsigned char unknown_b0_[0xb4];
    Vector3fix pivot;
    fix32_t unknown_170_;
    Vector3fix unknown_174_;
    fix32_t unknown_180_;
};

struct Vector3i;
ARM void Vector3fixMultiplyScalar(const Vector3fix* in, fix32_t scale, Vector3fix* out);

// USA: func_020adda4
extern "C" ARM void func_020adda4(Struct_020adda4* self) {
    Vector3fix pos = self->origin;
    Vector3fix step;
    Vector3fix aim;
    Vector3fix dir;
    Vector3fix var4;
    Vector3fix var5;
    Vector3fix var6;
    short pitch = self->unknown_ae_;
    int var8;
    int var9;

    var8 = fix32cos(pitch);
    var9 = fix32sin(pitch);
    aim.y = 0;
    aim.z = var8;
    aim.x = var9;

    var8 = fix32cos(self->unknown_170_);
    var9 = fix32sin(self->unknown_170_);
    dir.y = 0;
    dir.z = var8;
    dir.x = var9;

    var8 = fix32cos(self->unknown_180_);
    var9 = fix32sin(self->unknown_180_);
    var4.y = 0;
    var4.z = var8;
    var4.x = var9;

    Vector3fix_Normalize(&aim, &aim);
    Vector3fix_Normalize(&dir, &dir);
    Vector3fix_Normalize(&var4, &var4);

    *(Vector3i*)((int*)&step) = *(Vector3i const*)((int*)&aim);
    Vector3fixMultiplyScalar(&step, 0xe66, &step);
    Vector3fix_Subtract(&pos, &step, &var5);
    Vector3fix_Subtract(&var5, &self->pivot, &dir);
    Vector3fix_Normalize(&dir, &dir);

    step.x = -dir.x;
    step.y = -dir.y;
    step.z = -dir.z;
    Vector3fixMultiplyScalar(&step, 0xe66, &step);
    Vector3fix_Add(&var5, &step, &self->pivot);

    self->unknown_170_ = fix32_Atan2(dir.x, dir.z);
    self->unknown_170_ = fix32ReduceAngle0To2Pi(self->unknown_170_);

    *(Vector3i*)((int*)&step) = *(Vector3i const*)((int*)&dir);
    Vector3fixMultiplyScalar(&step, 0xe66, &step);
    Vector3fix_Subtract(&self->pivot, &step, &var6);
    Vector3fix_Subtract(&var6, &self->unknown_174_, &var4);
    Vector3fix_Normalize(&var4, &var4);

    step.x = -var4.x;
    step.y = -var4.y;
    step.z = -var4.z;
    Vector3fixMultiplyScalar(&step, 0xe66, &step);
    Vector3fix_Add(&var6, &step, &self->unknown_174_);

    self->unknown_180_ = fix32_Atan2(var4.x, var4.z);
    self->unknown_180_ = fix32ReduceAngle0To2Pi(self->unknown_180_);
}
