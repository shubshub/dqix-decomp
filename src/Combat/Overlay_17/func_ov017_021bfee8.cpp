#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021bff2c(void);

struct Struct_ov017_021bfee8 { unsigned char pad[8]; unsigned short field8; };

// USA: func_ov017_021bfee8
extern "C" ARM int func_ov017_021bfee8(Struct_ov017_021bfee8* p) {
    unsigned int t = (unsigned int)GameState::GetInstance()->GetEffectiveDeltaTime();
    if (t < p->field8) {
        p->field8 = (unsigned short)(p->field8 - t);
        return 6;
    }
    p->field8 = 0;
    func_ov017_021bff2c();
    return 8;
}
