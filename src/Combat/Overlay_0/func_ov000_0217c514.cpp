#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02054000;
extern "C" void* func_02054000(struct Struct_02054000* p);

struct Struct_ov000_0217c514 {
    unsigned int nibble : 4;
    unsigned int field48 : 5;
    unsigned int rest : 23;
};

struct Struct_ov000_0217c514_2 {
    char pad0[8];
    struct Struct_ov000_0217c514 bits;
    char pad1[0x18 - 0xc];
    short field18;
};

// USA: func_ov000_0217c514
extern "C" ARM int func_ov000_0217c514(int id, int flags) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = func_0200ff1c(bs, id);
    if (!c) return flags;
    struct Struct_ov000_0217c514_2* sub = (struct Struct_ov000_0217c514_2*)func_02054000((struct Struct_02054000*)c);
    if (!sub) return flags;
    if (sub->field18 > 0) {
        int ok = (sub->bits.nibble <= 7);
        if (ok) {
            if (sub->bits.field48 <= 11) {
                flags |= 1 << sub->bits.field48;
            }
        }
    }
    return flags;
}
