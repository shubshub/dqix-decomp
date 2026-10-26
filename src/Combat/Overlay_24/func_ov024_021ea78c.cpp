#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantByID(int unused, int id);

struct Struct_ov024_021e4604;
extern "C" int func_ov024_021e47dc(struct Struct_ov024_021e4604* obj);

extern short data_ov024_021fe6e0[];

struct Struct_ov024_021dd028_7 {
    char unk[0x10];
    int unknown_10_;
};

struct Struct_ov024_021dd028_6 {
    char unk0[0x4];
    int field4;
};

// USA: func_ov024_021ea78c
extern "C" ARM int func_ov024_021ea78c(struct Struct_ov024_021dd028_7* a, int id, struct Struct_ov024_021dd028_6* c) {
    GameObject* combatant = GetCombatantByID(a->unknown_10_, id);
    if (!combatant) return 0;
    if (!func_ov024_021e47dc((struct Struct_ov024_021e4604*)combatant)) return 0;
    int idx = 0;
    short v;
    goto test;
body:
    if (v == (int)((unsigned int)(c->field4 << 20) >> 20)) return 1;
    idx++;
test:
    v = data_ov024_021fe6e0[idx];
    if (v != -1) goto body;
    return 0;
}
