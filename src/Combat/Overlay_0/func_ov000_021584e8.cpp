#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_021584e8;

extern "C" void func_ov000_0215a88c(void* world, void* entry, int value);
extern "C" void func_ov000_0215fe84(void* arg0, void* entry, int idx);
extern "C" void func_ov000_02159eac(void* world, void* buf, int kind);
extern "C" void func_ov000_0215ccbc(
    void* world, struct Struct_ov000_021584e8* out, GameObject* combatant, short arg3, short valA, short valB,
    unsigned long long words, unsigned char arg7);

static inline short inline_ov000_021584e8(ModifiableCombatStats* s) { return s->primaryStats.currHP; }
static inline short inline_ov000_021584e8_2(ModifiableCombatStats* s) { return s->primaryStats.currMP; }

// USA: func_ov000_021584e8
extern "C" ARM void func_ov000_021584e8(void* world, struct Struct_ov000_021584e8* entry, GameObject* combatant,
                                        void* arg3, int value, unsigned char kind) {
    func_ov000_0215a88c(world, entry, (unsigned short)value);
    func_ov000_0215fe84(arg3, entry, 1);
    ((unsigned char*)world)[0x8e02]++;
    unsigned long long words = 0;
    func_ov000_02159eac(world, &words, kind);
    func_ov000_0215ccbc(
        world, entry, combatant, 0, inline_ov000_021584e8(combatant->currentStats_), inline_ov000_021584e8_2(combatant->currentStats_), words, 0);
}
