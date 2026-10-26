#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_02000c9c_29 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    unsigned char* status;
};

struct Struct_ov000_02156cc4 {
    char pad0[4];
    unsigned int deftness : 10;
    unsigned int rest : 22;
};

struct Struct_02085ab8 {
    char pad0[8];
    unsigned int lo8 : 29;
    unsigned int unknown_b_5_ : 1;
    unsigned int unknown_b_6_ : 2;
    char pad1[0x14 - 0xc];
    unsigned int unknown_14_0_ : 21;
    unsigned int unknown_16_5_ : 7;
    unsigned int unknown_17_4_ : 4;
};

extern "C" unsigned char* func_02053c6c(unsigned char* obj);
extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" float func_02084e78(void* param0);
extern "C" int func_02085ab8(unsigned char* actor, Struct_02085ab8* action);
float CalculateCritRate(int deftness, float accessoryBonus, float bookBonus, float skillBonus, unsigned char hitCount);
extern "C" float func_020748f8(float a, unsigned int b);
extern "C" float func_ov000_02155a04(GameObject* obj);

static inline unsigned char* inline_ov000_02156cc4(GameObject* c) {
    return ((Struct_02000c9c_29*)c)->status;
}

static inline int inline_ov000_02156cc4_2(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov000_02156cc4
extern "C" ARM int func_ov000_02156cc4(struct Random* arg0, int arg1, Struct_02085ab8* action, int arg3) {
    if (action->unknown_b_5_) {
        return 1;
    }
    GameState* bs = GameState::GetInstance();
    float rate;
    if (inline_ov000_02156cc4_2(arg1)) {
        GameObject* attacker = func_0200ff1c(bs, arg1);
        unsigned char* var3 = func_02053c6c((unsigned char*)attacker);
        int deftness = ((Struct_ov000_02156cc4*)var3)->deftness;
        float var5 = func_02084e78(var3);
        float bonus = func_02085ab8(var3, action);
        rate = CalculateCritRate(deftness, var5, bonus, action->unknown_16_5_ / 100.0f, (unsigned char)arg3);
        if (func_02083b00(inline_ov000_02156cc4(attacker), 0x11d)) {
            if (func_ov000_02155a04(attacker) < 0.25f) {
                rate *= 2.0f;
            }
        }
    } else {
        rate = func_020748f8(action->unknown_16_5_ / 100.0f, (unsigned char)arg3);
    }
    rate = 100.0f * rate;
    return NextRandomMax(arg0, 10000) < (int)rate;
}
