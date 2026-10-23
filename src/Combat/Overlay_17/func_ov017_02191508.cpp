#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov017_02191508 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_ov017_02191508_2 {
#if defined(jpn)
    char unknown_0_[0xd];
#else
    char unknown_0_[0x12];
#endif

    unsigned char unknown_12_;
    unsigned char unknown_13_;
    Struct_ov017_02191508 unknown_14_[3];
};

struct Struct_ov017_02191508_3 {
    unsigned int unknown_0_0_ : 32;
    unsigned short unknown_4_0_ : 7;
    unsigned short unknown_4_7_ : 9;
    Struct_ov017_02191508 unknown_8_[3];
};

struct Struct_ov017_02191508_4 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_ov017_02191508_5 {
    unsigned char unknown_0_[0x130];
    Struct_ov017_02191508_4* unknown_130_;
    BaseCombatStats* unknown_134_;
};

struct Struct_ov017_02191508_6 {
    unsigned char unknown_0_[0x3c];
    char unknown_3c_[0x16c - 0x3c];
    unsigned short unknown_16c_;
    unsigned char unknown_16e_[0x56a - 0x16e];
    unsigned char unknown_56a_;
};

Member02191508* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void PartyMember_ApplyLevelStats(void* dst, void* src, void* tail);
extern "C" void func_02083e28(void* a, int arg2);
void PartyMember_SetVocation(unsigned char* obj, int bit);
void ClearTwoRegions02083c18(char* obj);
void PartyMember_LearnSpell(unsigned char* obj, int index);

extern char g_stringFormat[];

// USA: func_ov017_02191508
extern "C" ARM void func_ov017_02191508(int arg0, Struct_ov017_02191508_2* arg1) {
    Struct_ov017_02191508_5* var0 =
        (Struct_ov017_02191508_5*)func_0200ff1c(GameState::GetInstance(), arg0);
    if (var0 == NULL) return;
    Struct_ov017_02191508_6* var1 = func_02053c6c((unsigned char*)var0);
    if (var1 == NULL) return;

    int var2 = -1;
    if (strcmp(var1->unknown_3c_, arg1->unknown_0_) == 0) {
        var2 = var0->unknown_130_->unknown_4_;
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
    Packed02191508 packed;
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
    func_02083e28(member, 0);

    if (var2 > -1) {
        var0->unknown_130_->unknown_4_ = var2;
    } else {
        var0->unknown_130_->unknown_4_ = var0->unknown_134_->primaryStats.maxHP;
    }
    combatant->status->mp = combatant->baseStats->primaryStats.maxMP;
    PartyMember_SetVocation((unsigned char*)member, 0);
    ClearTwoRegions02083c18((char*)member);
    member->kind = tmpl->kind;
    PartyMember_LearnSpell((unsigned char*)member, tmpl->slot);
}
