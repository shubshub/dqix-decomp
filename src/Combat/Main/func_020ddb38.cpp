#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020ddb38_336 = 0x144 };
#else
enum { Enum_020ddb38_336 = 0x150 };
#endif
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_020ddb38 { unsigned int v[8]; };
struct Struct_020ddb38_2 {
    unsigned int kind : 4;
    unsigned int : 27;
    unsigned int unknown_3_7_ : 1;
};
struct Struct_020ddb38_3 {
    char pad[0x2c];
    short kind;
};
struct Struct_02061c04_22 { unsigned char pad[0x454]; short slots[8]; };
struct Struct_020a0504;

extern "C" int func_020ddb20(unsigned int* obj);
extern "C" void func_0208386c(struct Struct_02061c04_22* s, int idx);
extern "C" void* func_ov000_02171b9c(void* obj, int idx);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_020ac4c0(void* dst);
extern "C" void func_020a0504(struct Struct_020a0504* p, unsigned int amount);
extern "C" int func_020ac494(void* src);
extern "C" void func_02083738(void* o, int a1);

// USA: func_020ddb38
extern "C" ARM int func_020ddb38(int n, int idx, struct Struct_020ddb38_3* container, struct Random* rng) {
    int inRange;
    GameObject* combatant;
    struct Struct_020ddb38* elem;
    char localBuf[0xb0];

    combatant = func_0200ff1c(GameState::GetInstance(), n);
    inRange = (n >= 0 && n <= 3);
    if (!inRange) return 0;
    if (combatant == 0) return 0;
    if (container == 0) return 0;
    if (container->kind != 0x4667) {
        if (idx < 0) goto fail;
        if (idx < 0x10) goto ok;
    fail:
        return 0;
    ok:
        elem = (struct Struct_020ddb38*)func_ov000_02171b9c(container, idx);
    } else {
        elem = (struct Struct_020ddb38*)((char*)(*(struct Struct_02061c04_22**)((char*)combatant + Enum_020ddb38_336)) + 0x2d4);
    }
    if (elem == 0) return 0;
    if (!func_020ddb20(elem->v)) return 0;
    switch (((struct Struct_020ddb38_2*)&elem->v[2])->kind) {
    case 8:
    case 9:
    case 0xa:
        func_0208386c(*(struct Struct_02061c04_22**)((char*)combatant + Enum_020ddb38_336), (signed char)idx);
        break;
    default:
        if (*(short*)((char*)elem + 0x18) == 0x4667) {
            if (rng == 0) rng = GetBTRandom();
            if (NextRandomMax(rng, 100) < 0x19) {
                func_02083738((void*)(int)func_02053c6c((unsigned char*)combatant), 7);
                return 2;
            }
        }
        return 0;
    }
    if (((struct Struct_020ddb38_2*)&elem->v[2])->unknown_3_7_) {
        func_020ac4c0(localBuf);
        func_020a0504((struct Struct_020a0504*)localBuf, 1);
        func_020ac494(localBuf);
    }
    return 1;
}
