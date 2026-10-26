#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);

struct Struct_0207df50 { unsigned int v[10]; };
struct Struct_0207df50_2 { unsigned int v[2]; };
struct Foo0207df50 {
    struct Struct_0207df50 a;
    struct Struct_0207df50 b;
    unsigned int c;
    unsigned int d;
    struct Struct_0207df50_2 p1;
    struct Struct_0207df50_2 p2;
};
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);

// USA: func_ov001_0215eab0
extern "C" ARM int func_ov001_0215eab0(void* self, int mode) {
#if defined(jpn)
 enum { Enum_ov001_0215eab0_716 = 0x27c };
#else
 enum { Enum_ov001_0215eab0_716 = 0x2cc };
#endif
    GameState* bs = GameState::GetInstance();
    if (bs == NULL) {
        return 0;
    }
    int base = (int)bs->GetResources();
    if (base == 0) {
        return 0;
    }
    int val = func_ov017_021d60f4(self);
    int addr;
    if (val < 0) {
        addr = base + Enum_ov001_0215eab0_716;
        addr = addr + 0xbd0;
    } else {
        addr = base + Enum_ov001_0215eab0_716 + val * 0x70;
    }
    if (addr == 0) {
        return 0;
    }
    int flag = 1;
    if (mode >= 2) {
        flag = func_ov017_021d60f4((char*)self + 0x8);
    }
    if (flag != 0) {
        VramState_Rewind((struct Foo0207df50*)addr);
    }
    VramState_Restore((char*)addr);
    return 1;
}
