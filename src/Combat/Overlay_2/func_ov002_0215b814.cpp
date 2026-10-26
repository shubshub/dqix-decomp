#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct Entry {
#if defined(jpn)
    char name[0xc];
#else
    char name[0x30];
#endif
    int unk30;
    unsigned short unk34;
    unsigned short unknown_36_;
    unsigned short unknown_38_;
    unsigned short unknown_3a_;
};
#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

extern "C" void *memset(void *dst, int c, unsigned int n);
extern "C" int sprintf(char *buf, const char *fmt, ...);

// USA: func_ov002_0215b814
extern "C" ARM void func_ov002_0215b814(char *self) {
    GameState *gs = GameState::GetInstance();
    struct Entry *e;
    int i;
    for (i = 0; i < 4; i++) {
        e = (struct Entry *) (self + RG(0x1ab0, 0x1a08)) + i;
        memset(e, 0, 4);
        GameObject *c = func_0200ff1c(gs, i);
        if (c != 0 && c->baseStats_->name[0] != 0) {
            sprintf(e->name, c->baseStats_->name);
            e->unk34 = c->combatFields_.savedState_130_->hp;
            e->unknown_36_ = c->baseStats_->primaryStats.maxHP;
            e->unknown_38_ = c->combatFields_.savedState_130_->mp;
            e->unknown_3a_ = c->baseStats_->primaryStats.maxMP;
            e->unk30 = c->combatFields_.savedState_130_->flags;
        }
    }
}
