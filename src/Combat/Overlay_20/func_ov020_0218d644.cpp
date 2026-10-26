#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" void GXx_SetMasterBrightness_(short* out, int value);

struct Struct_ov020_0218d644 {
#if defined(jpn)
    char pad[0x478];
#else
    char pad[0x4e8];
#endif

    float f4e8;
    int unknown_4ec_;
    int unknown_4f0_;
    float f4f4;
    int unknown_4f8_;
    int unknown_4fc_;
};

// USA: func_ov020_0218d644
extern "C" ARM void func_ov020_0218d644(struct Struct_ov020_0218d644* obj) {
    int step = GameState::GetInstance()->GetEffectiveDeltaTime();
    int var1 = obj->unknown_4f0_ > 0;
    if (var1) {
        obj->f4e8 = obj->f4e8 + (float)step * (((float)obj->unknown_4ec_ - obj->f4e8) / (float)obj->unknown_4f0_);
        obj->unknown_4f0_ -= step;
        if (obj->unknown_4f0_ <= 0) {
            obj->f4e8 = (float)obj->unknown_4ec_;
            obj->unknown_4f0_ = 0;
        }
        GXx_SetMasterBrightness_((short*)0x400006c, (int)obj->f4e8);
    }
    int var2 = obj->unknown_4fc_ > 0;
    if (!var2) return;
    obj->f4f4 = obj->f4f4 + (float)step * (((float)obj->unknown_4f8_ - obj->f4f4) / (float)obj->unknown_4fc_);
    obj->unknown_4fc_ -= step;
    if (obj->unknown_4fc_ <= 0) {
        obj->f4f4 = (float)obj->unknown_4f8_;
        obj->unknown_4fc_ = 0;
    }
    GXx_SetMasterBrightness_((short*)0x400106c, (int)obj->f4f4);
}
