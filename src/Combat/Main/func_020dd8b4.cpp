#include <globaldefs.h>
#if defined(jpn)
enum { Enum_020dd8b4_336 = 0x144 };
#else
enum { Enum_020dd8b4_336 = 0x150 };
#endif
#include "GameState/GameState.h"
struct Struct_020dd8b4 { unsigned int field_0; unsigned int agility : 10; unsigned int unknown_5_2_ : 22; };
struct Struct_020dd8b4_2 { char pad[0x134]; BaseCombatStats* stats; char unknown_138_[Enum_020dd8b4_336 - 0x138]; Struct_020dd8b4* unknown_150_; };
struct Details020dd8b4 { int arg; char fields[0x30]; };
struct Struct_020dd8b4_4 {
    int id;
    Details020dd8b4 details;
    unsigned char flag;
    char unknown_39_[3];
    unsigned short attack; short unknown_3e_;
    unsigned short unknown_40_; short unknown_42_;
    int unknown_44_; int unknown_48_;
    int unknown_4c_; int unknown_50_;
    int unknown_54_; int unknown_58_;
    int unknown_5c_; int unknown_60_;
    unsigned short unknown_64_; short unknown_66_;
    unsigned short agility; short unknown_6a_;
    unsigned short unknown_6c_; short unknown_6e_;
    unsigned short unknown_70_; short unknown_72_;
    unsigned short hp; short unknown_76_;
    unsigned short mp;
};
extern "C" char* func_02053c6c(unsigned char*);
extern "C" int func_02084fc8(char*);
extern "C" int func_02084ee8(void*);
extern "C" int func_02084f58(void*);
extern "C" int func_02084e78(void*);
extern "C" void PartyMember_RecalculateStats(char*, Details020dd8b4*);
static inline int inline_020dd8b4(int id) { return id >= 0 && id <= 3; }
// USA: func_020dd8b4
extern "C" ARM void func_020dd8b4(Struct_020dd8b4_4* obj, int id, int arg, unsigned char flag) {
    if (!inline_020dd8b4(id)) return;
    obj->id = id;
    obj->details.arg = arg;
    obj->flag = flag;
    Struct_020dd8b4_2* combatant = (Struct_020dd8b4_2*)func_0200ff1c(GameState::GetInstance(), obj->id);
    if (!combatant) return;
    char* data = func_02053c6c((unsigned char*)combatant);
    obj->attack = combatant->stats->primaryStats.attack;
    obj->unknown_40_ = combatant->stats->primaryStats.defense;
    obj->unknown_44_ = func_02084fc8(data);
    obj->unknown_4c_ = func_02084ee8(data);
    obj->unknown_54_ = func_02084f58(data);
    obj->unknown_5c_ = func_02084e78(data);
    obj->unknown_64_ = combatant->unknown_150_->agility;
    obj->agility = combatant->stats->primaryStats.agility;
    obj->unknown_6c_ = combatant->stats->primaryStats.magicalMight;
    obj->unknown_70_ = combatant->stats->primaryStats.magicalMending;
    obj->hp = combatant->stats->primaryStats.maxHP;
    obj->mp = combatant->stats->primaryStats.maxMP;
    PartyMember_RecalculateStats(data, &obj->details);
}
