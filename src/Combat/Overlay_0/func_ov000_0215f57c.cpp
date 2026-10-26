#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_020891b0 {
    unsigned char pad[0x3c];
    unsigned char bit0 : 1;
};

struct Struct_ov000_0215f57c {
    char pad[0x10];
    unsigned int unknown_10_0_ : 8;
    unsigned int slot : 3;
    unsigned int rest : 21;
};

struct Struct_ov000_0215f57c_2 {
    char pad0[0x138];
    struct Struct_020891b0* field138;
    char pad1[0x148 - 0x13c];
    struct Struct_ov000_0215f57c* field148;
};

struct Struct_ov000_02182a6c {
    signed char v[8];
};

extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" void func_020891b0(struct Struct_020891b0* obj);

extern struct Struct_ov000_02182a6c data_ov000_02182a6c;

static inline int inline_ov000_0215f57c(int i) { return i >= 0 && i <= 3; }

// USA: func_ov000_0215f57c
extern "C" ARM int func_ov000_0215f57c(struct Random* rng, int id) {
    if (inline_ov000_0215f57c(id)) {
        return 0;
    }
    struct Struct_ov000_0215f57c_2* c = (struct Struct_ov000_0215f57c_2*)func_0200fea4(GameState::GetInstance(), id);
    struct Struct_ov000_0215f57c* inner = c->field148;
    int flag = c->field138->bit0 ? 1 : 0;
    int r = NextRandomMax(rng, 2);
    struct Struct_ov000_02182a6c t = data_ov000_02182a6c;
    t.v[1] = r != 0;
    t.v[4] = flag != 0 ? 1 : 0;
    t.v[5] = flag == 0 ? 0 : 2;
    t.v[6] = flag != 0 ? 0 : 1;
    t.v[7] = flag == 0 ? 2 : 0;
    int result = t.v[inner->slot];
    func_020891b0(c->field138);
    return result;
}
