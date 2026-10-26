#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov017_02191508 {
    unsigned int fieldA : 10;
    unsigned int fieldB : 10;
    unsigned int fieldC : 10;
    unsigned int reserved : 2;
};

struct Struct_ov017_02191508_2 {
#if defined(jpn)
    char name[0xd];
#else
    char name[0x12];
#endif

    unsigned char kind;
    unsigned char slot;
    Struct_ov017_02191508 triples[3];
};

struct Struct_ov017_02191508_3 {
    unsigned int header : 32;
    unsigned short kind : 7;
    unsigned short extra : 9;
    Struct_ov017_02191508 triples[3];
};

struct Struct_ov017_02191508_4 {
    unsigned int flags;
    unsigned short hp;
    unsigned short mp;
};

struct Struct_ov017_02191508_5 {
    unsigned char pad0[0x130];
    Struct_ov017_02191508_4* status;
    BaseCombatStats* baseStats;
};

struct Struct_ov017_02191508_6 {
    unsigned char pad0[0x3c];
    char name[0x16c - 0x3c];
    unsigned short kind;
    unsigned char unknown_16e_[0x56a - 0x16e];
    unsigned char state;
};

extern "C" Struct_ov017_02191508_6* func_02053c6c(unsigned char* obj);
extern "C" void PartyMember_ApplyLevelStats(void* dst, void* src, void* tail);
extern "C" void PartyMember_RecalculateStats(void* a, int arg1);
extern "C" void PartyMember_SetVocation(unsigned char* obj, int bit);
extern "C" void func_02083c18(char* obj);
extern "C" void PartyMember_LearnSpell(unsigned char* obj, int index);

extern char g_stringFormat[];

// USA: func_ov017_02191508
extern "C" ARM void func_ov017_02191508(int id, Struct_ov017_02191508_2* tmpl) {
    Struct_ov017_02191508_5* combatant =
        (Struct_ov017_02191508_5*)func_0200ff1c(GameState::GetInstance(), id);
    if (combatant == NULL) return;
    Struct_ov017_02191508_6* member = func_02053c6c((unsigned char*)combatant);
    if (member == NULL) return;

    int hp = -1;
    if (strcmp(member->name, tmpl->name) == 0) {
        hp = combatant->status->hp;
    }
#if defined(jpn)
    sprintf(member->name, g_stringFormat, tmpl->name);

#else
    if (tmpl != NULL) {
        sprintf(member->name, g_stringFormat, tmpl->name);
    } else {
        sprintf(member->name, g_stringFormat, member->name);
    }

#endif
    Struct_ov017_02191508_3 packed;
    packed.header = 0;
    packed.extra = 0;
    packed.kind = tmpl->kind;
    packed.triples[0].fieldA = tmpl->triples[0].fieldA;
    packed.triples[0].fieldB = tmpl->triples[0].fieldB;
    packed.triples[0].fieldC = tmpl->triples[0].fieldC;
    packed.triples[1].fieldA = tmpl->triples[1].fieldA;
    packed.triples[1].fieldB = tmpl->triples[1].fieldB;
    packed.triples[1].fieldC = tmpl->triples[1].fieldC;
    packed.triples[2].fieldA = tmpl->triples[2].fieldA;
    packed.triples[2].fieldB = tmpl->triples[2].fieldB;
    packed.triples[2].fieldC = tmpl->triples[2].fieldC;
    member->state = 0xb;
    PartyMember_ApplyLevelStats(member, &packed, NULL);
    PartyMember_RecalculateStats(member, 0);

    if (hp > -1) {
        combatant->status->hp = hp;
    } else {
        combatant->status->hp = combatant->baseStats->primaryStats.maxHP;
    }
    combatant->status->mp = combatant->baseStats->primaryStats.maxMP;
    PartyMember_SetVocation((unsigned char*)member, 0);
    func_02083c18((char*)member);
    member->kind = tmpl->kind;
    PartyMember_LearnSpell((unsigned char*)member, tmpl->slot);
}
