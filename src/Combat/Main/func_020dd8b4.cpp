#include <globaldefs.h>
#if defined(jpn)
enum { Enum_020dd8b4_336 = 0x144 };
#else
enum { Enum_020dd8b4_336 = 0x150 };
#endif
#include "GameState/GameState.h"
struct Struct_020dd8b4 { unsigned int unknown_0_; unsigned int unknown_4_0_ : 10; unsigned int unknown_5_2_ : 22; };
struct Struct_020dd8b4_2 { char unknown_0_[0x134]; BaseCombatStats* unknown_134_; char unknown_138_[Enum_020dd8b4_336 - 0x138]; Struct_020dd8b4* unknown_150_; };
struct Struct_020dd8b4_3 { int unknown_0_; char unknown_4_[0x30]; };
struct Struct_020dd8b4_4 {
    int unknown_0_;
    Struct_020dd8b4_3 unknown_4_;
    unsigned char unknown_38_;
    char unknown_39_[3];
    unsigned short unknown_3c_; short unknown_3e_;
    unsigned short unknown_40_; short unknown_42_;
    int unknown_44_; int unknown_48_;
    int unknown_4c_; int unknown_50_;
    int unknown_54_; int unknown_58_;
    int unknown_5c_; int unknown_60_;
    unsigned short unknown_64_; short unknown_66_;
    unsigned short unknown_68_; short unknown_6a_;
    unsigned short unknown_6c_; short unknown_6e_;
    unsigned short unknown_70_; short unknown_72_;
    unsigned short unknown_74_; short unknown_76_;
    unsigned short unknown_78_;
};
char* GetFieldAt0x150_02053c6c(unsigned char*);
int AccumulateSlotBits20To29AsTenths_02084fc8(char*);
int AccumulateCharm02084ee8(void*);
int AccumulateMagicalMight02084f58(void*);
int AccumulateMagicalMending02084e78(void*);
extern "C" void PartyMember_RecalculateStats(char*, Details020dd8b4*);
static inline int IsPartyMember020dd8b4(int id) { return id >= 0 && id <= 3; }
// USA: func_020dd8b4
extern "C" ARM void func_020dd8b4(Summary020dd8b4* obj, int id, int arg, unsigned char flag) {
    if (!IsPartyMember020dd8b4(id)) return;
    obj->id = id;
    obj->details.arg = arg;
    obj->flag = flag;
    Combatant020dd8b4* combatant = (Combatant020dd8b4*)GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), obj->id);
    if (!combatant) return;
    char* data = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    obj->attack = combatant->stats->primaryStats.attack;
    obj->defense = combatant->stats->primaryStats.defense;
    obj->slotBonus = AccumulateSlotBits20To29AsTenths_02084fc8(data);
    obj->charmBonus = AccumulateCharm02084ee8(data);
    obj->mightBonus = AccumulateMagicalMight02084f58(data);
    obj->mendingBonus = AccumulateMagicalMending02084e78(data);
    obj->intrinsicAgility = combatant->intrinsic->agility;
    obj->agility = combatant->stats->primaryStats.agility;
    obj->might = combatant->stats->primaryStats.magicalMight;
    obj->mending = combatant->stats->primaryStats.magicalMending;
    obj->hp = combatant->stats->primaryStats.maxHP;
    obj->mp = combatant->stats->primaryStats.maxMP;
    PartyMember_RecalculateStats(data, &obj->details);
}
