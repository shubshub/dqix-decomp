#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Struct_020a0e4c {
    int unknown_0_;
    Vector3i unknown_4_;
    Vector3i unknown_10_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
};

// USA: func_020a0e4c
extern "C" ARM void func_020a0e4c(struct Struct_020a0e4c* obj) {
    float var0 = (float)GameState::GetInstance()->GetEffectiveDeltaTime() / 1000.0f;
    int var1 = (int)(obj->unknown_24_ * var0);
    int var2 = (int)(obj->unknown_1c_ * var0);

    Vector3i dir;
    Vector3fix_Subtract(&obj->unknown_10_, &obj->unknown_4_, &dir);
    Vector3fix_Normalize(&dir, &dir);
    int dist = Vector3fix_Distance(&obj->unknown_10_, &obj->unknown_4_);

    float var5 = (float)var2 / 4096.0f;
    float num = var5 * var5;
    float var7 = (float)var1 / 4096.0f;
    float var8 = 2.0f * var7;
    float ratio = num / var8;

    if (dist < var1) {
        obj->unknown_4_ = obj->unknown_10_;
        obj->unknown_0_ = 0;
    } else if ((int)(4096.0f * ratio) < dist + 0x199) {
        int step = var2 + var1;
        int var11 = (int)(step / var0);
        obj->unknown_1c_ = var11;
        int maxSpeed = obj->unknown_20_;
        if (maxSpeed < var11) {
            obj->unknown_1c_ = maxSpeed;
            step = (int)(maxSpeed * var0);
        }
        Vector3i tmp;
        Vector3fixMultiplyScalar(&dir, step, &tmp);
        Vector3fix_Add(&obj->unknown_4_, &tmp, &obj->unknown_4_);
    } else {
        int step = var2 - var1;
        int half = dist / 2;
        if (step > half) {
            step = half;
        }
        obj->unknown_1c_ = (int)(step / var0);
        if (step < var1) {
            obj->unknown_4_ = obj->unknown_10_;
            obj->unknown_0_ = 0;
        } else {
            Vector3i tmp;
            Vector3fixMultiplyScalar(&dir, step, &tmp);
            Vector3fix_Add(&obj->unknown_4_, &tmp, &obj->unknown_4_);
        }
    }
}
