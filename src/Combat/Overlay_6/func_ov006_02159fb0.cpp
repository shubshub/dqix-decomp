#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov006_02159fb0 {
    char unk[0x3a8];
    unsigned int unknown_3a8_;
    int unknown_3ac_;
    int unknown_3b0_;
};

extern "C" void func_ov006_02159f94(struct Struct_ov006_02159fb0* obj);
extern "C" void func_ov006_02159f0c(struct Struct_ov006_02159fb0* obj);

// USA: func_ov006_02159fb0
extern "C" ARM void func_ov006_02159fb0(struct Struct_ov006_02159fb0* obj) {
    if (obj->unknown_3b0_ < 0) {
        obj->unknown_3a8_ = 0;
        func_ov006_02159f94(obj);
        return;
    }
    if (obj->unknown_3a8_ > 0x3c) {
        obj->unknown_3a8_ = 0;
        func_ov006_02159f94(obj);
        func_ov006_02159f0c(obj);
    }
    obj->unknown_3a8_ += GameState::GetInstance()->GetEffectiveDeltaTime();
}
