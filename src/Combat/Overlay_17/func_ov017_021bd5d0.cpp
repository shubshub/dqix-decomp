#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct SearchStruct0202c1a4;
struct Foo02033b58;

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" int func_02048418(unsigned char* obj, unsigned short flag);
extern "C" void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);
extern "C" void func_ov017_021c9d2c(int slot, unsigned short a1, unsigned short a2, unsigned short a3, int a4, unsigned int a5, unsigned char a6, int flagA, int arg8);
extern "C" void Party_ReformLine(void* unused, int c, int d, int e, int flag);

static inline unsigned short inline_ov017_021bd5d0_4(const BaseCombatStats* stats) {
    return stats->primaryStats.maxMP;
}
static inline unsigned short inline_ov017_021bd5d0_5(const BaseCombatStats* stats) {
    return stats->primaryStats.maxHP;
}

// USA: func_ov017_021bd5d0
extern "C" ARM void func_ov017_021bd5d0(void) {
    GameState* battle = GameState::GetInstance();
    void* g = LinkSession_GetInstance();
    GameObject* combatant = battle->GetGameObjectByIndex(0);
    void* other = GetGameResources();
    struct Struct_020200c0* p = combatant->combatFields_.savedState_130_;

    if (p->inline_ov017_021bd5d0() & 1) {
        if (LinkSession_IsActive((int*)g) && LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)g) == 0) {
            func_02053fe4(combatant, 1, 0);
            func_02048418((unsigned char*)combatant, 1);

            p = combatant->combatFields_.savedState_130_;
            struct BaseCombatStats* q = combatant->baseStats_;
            unsigned char byte8 = p->inline_ov017_021bd5d0_3();
            unsigned int word0 = p->inline_ov017_021bd5d0();
            unsigned short maxMP = inline_ov017_021bd5d0_4(q);
            unsigned short maxHP = inline_ov017_021bd5d0_5(q);
            unsigned short half6 = p->inline_ov017_021bd5d0_2();
            func_ov017_021c9d2c(combatant->obj3D_.actorIndex_, 1, maxHP, half6, maxMP, word0, byte8, 1, 0);

            GameObject_StoreMotionState((struct Foo02033b58*)combatant, 0);
            combatant->combatFields_.unknown_b2_ = 0;
        } else if (LinkSession_IsActive((int*)g) == 0) {
            func_02053fe4(combatant, 1, 0);
            func_02048418((unsigned char*)combatant, 1);
            GameObject_StoreMotionState((struct Foo02033b58*)combatant, 0);
            combatant->combatFields_.unknown_b2_ = 0;
        }
        Party_ReformLine(other, 1, 1, 1, 0);
    }
}
