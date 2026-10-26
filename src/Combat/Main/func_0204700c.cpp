#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Graphics/Vector.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"

extern "C" float _fsub(float a, float b);
extern "C" int _fleq(float a, float b);
extern "C" float _fdiv(float a, float b);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float v);

extern "C" void Camera_SetRoll(unsigned char* obj, short val);

struct AngleTrig0202e9a4;
extern "C" void Camera_SetFieldOfView(struct AngleTrig0202e9a4* obj, int angle);

// USA: func_0204700c
extern "C" ARM int func_0204700c(char* self) {
    if (*(unsigned int*)self > 0x23) {
        return 1;
    }

    GameState* gs = GameState::GetInstance();
    int tick = gs->GetTickCount();

    float f8 = _fsub(*(float*)(self + 8), 8.0f);
    *(float*)(self + 8) = f8;
    if (_fleq(f8, -180.0f)) {
        *(float*)(self + 8) = 180.0f;
    }
    float var3 = _fmul(3.14f, _fdiv(*(float*)(self + 8), 180.0f));

    *(float*)(self + 0xc) = _fsub(*(float*)(self + 0xc), 0.4333f);

    void* obj = gs->GetCamera();
    short ang16 = fix32ReduceAngle0To2Pi(_ffix(_fmul(4096.0f, var3)));
    Camera_SetRoll((unsigned char*)obj, ang16);
    Camera_SetFieldOfView((struct AngleTrig0202e9a4*)obj,
                                 _ffix(_fmul(4096.0f, *(float*)(self + 0xc))));

    Object3D* var6 = *(Object3D**)(self + 0xe8);
    if (var6 != 0) {
        var6->AdvanceEffects();
    } else {
        ((Object3D*)(self + 0x3c))->AdvanceEffects();
    }

    *(unsigned int*)self = *(unsigned int*)self + tick;
    if (*(unsigned int*)self > 0xf && *(unsigned char*)(self + 0x1c) != 0) {
        GameResources* res = GetGameResources();
        SetMainBrightness(res, -16, 20);
        SetSubBrightness(res, -16, 20);
        *(unsigned char*)(self + 0x1c) = 0;
    }

    return *(unsigned int*)self > 0x23;
}
