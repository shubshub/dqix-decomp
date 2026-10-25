#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Graphics/Vector.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"

extern "C" float _fsub(float arg0, float arg1);
extern "C" int _fleq(float a, float b);
extern "C" float _fdiv(float arg0, float arg1);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float v);

extern "C" void func_0202e874(unsigned char* arg0, short arg1);

struct Struct_0202df68;
extern "C" void func_0202e9a4(struct Struct_0202df68* arg0, int arg1);

// USA: func_0204700c
extern "C" ARM int func_0204700c(char* arg0) {
    if (*(unsigned int*)arg0 > 0x23) {
        return 1;
    }

    GameState* var0 = GameState::GetInstance();
    int var1 = var0->GetTickCount();

    float var2 = _fsub(*(float*)(arg0 + 8), 8.0f);
    *(float*)(arg0 + 8) = var2;
    if (_fleq(var2, -180.0f)) {
        *(float*)(arg0 + 8) = 180.0f;
    }
    float var3 = _fmul(3.14f, _fdiv(*(float*)(arg0 + 8), 180.0f));

    *(float*)(arg0 + 0xc) = _fsub(*(float*)(arg0 + 0xc), 0.4333f);

    void* obj = gs->GetCamera();
    short ang16 = fix32ReduceAngle0To2Pi(_ffix(_fmul(4096.0f, ang)));
    _Z42SetField0x7cClearFields0x1ec0x1ee_0202e874Pht((unsigned char*)obj, ang16);
    SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)obj,
                                 _ffix(_fmul(4096.0f, *(float*)(self + 0xc))));

    Object3D* var6 = *(Object3D**)(arg0 + 0xe8);
    if (var6 != 0) {
        var6->AdvanceEffects();
    } else {
        ((Object3D*)(arg0 + 0x3c))->AdvanceEffects();
    }

    *(unsigned int*)arg0 = *(unsigned int*)arg0 + var1;
    if (*(unsigned int*)arg0 > 0xf && *(unsigned char*)(arg0 + 0x1c) != 0) {
        GameResources* var7 = GetGameResources();
        SetMainBrightness(var7, -16, 20);
        SetSubBrightness(var7, -16, 20);
        *(unsigned char*)(arg0 + 0x1c) = 0;
    }

    return *(unsigned int*)arg0 > 0x23;
}
