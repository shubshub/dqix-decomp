#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov020_0218d854_1252 = 0x474 };
#else
enum { Enum_ov020_0218d854_1252 = 0x4e4 };
#endif

#include "GameState/GameState.h"

struct Struct_ov020_0218d854 {
    char pad[Enum_ov020_0218d854_1252];
    int unknown_4e4_;

    int inline_ov020_0218d854() const { return unknown_4e4_ > 0; }
};

// USA: func_ov020_0218d854
extern "C" ARM void func_ov020_0218d854(struct Struct_ov020_0218d854* obj) {
    int var0 = GameState::GetInstance()->GetEffectiveDeltaTime();
    if (!obj->inline_ov020_0218d854()) {
        return;
    }
    obj->unknown_4e4_ -= var0;
    if (obj->unknown_4e4_ <= 0) {
        obj->unknown_4e4_ = 0;
    }
}
