#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_021584e8;

extern "C" void func_ov000_0215ccbc(int unused, struct Struct_ov000_021584e8* out, GameObject* combatant,
                            short arg3, short valA, short valB, unsigned long long words, unsigned char arg7);

static inline short inline_ov000_0215cd44(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }
static inline short inline_ov000_0215cd44_2(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

// USA: func_ov000_0215cd44
extern "C" ARM void func_ov000_0215cd44(int unused, struct Struct_ov000_021584e8* out, GameObject* combatant,
                                        short arg3, unsigned long long words, unsigned char arg5) {
    func_ov000_0215ccbc(unused, out, combatant, arg3, inline_ov000_0215cd44(combatant), inline_ov000_0215cd44_2(combatant), words, arg5);
}
