#include <globaldefs.h>
#include "std_library_functions.h"

struct StatTriple {
    unsigned int f0 : 10;
    unsigned int f1 : 10;
    unsigned int f2 : 10;
    unsigned int : 2;
};

struct SignedTriple {
    int s0 : 10;
    int s1 : 10;
    int s2 : 10;
    int : 2;
};

struct ItemAttackDefence {   // shop panels: copper sword "Attack 7", pot lid "Defence 1"
    int attack : 10;
    int defence : 10;
    unsigned int u2 : 10;
    unsigned int : 2;
};

struct ItemRates {           // evasion chance in 0.1% (sandals 5: "Evasion Chance 0.5%", leather shoes 10: "1.0%")
    unsigned int f0 : 10;
    unsigned int evasion : 10;
    unsigned int f2 : 10;
    unsigned int : 2;
};

struct ItemStatBonusA {      // cotton gloves "Deftness 5"; agility and magical might by the stat each adds to
    int deftness : 10;
    int agility : 10;
    int magicalMight : 10;
    int : 2;
};

struct ItemStatBonusB {      // bandana "Magical Mending 2"; max HP and max MP by the stat each adds to
    int magicalMending : 10;
    int maxHp : 10;
    int maxMp : 10;
    int : 2;
};

struct Struct_02083e28_8 {
    int b0 : 8;
    int b1 : 8;
    int b2 : 8;
    int b3 : 8;
};

struct ItemStats {
    int unk0;
    int unk4;
    struct ItemAttackDefence attackDefence;
    struct ItemRates rates;
    struct ItemStatBonusA bonusA;
    struct ItemStatBonusB bonusB;
    struct SignedTriple styleA;  // style points: the six style scores add them (see styleScores)
    struct SignedTriple styleB;
};

struct Record020836e4 {
    struct ItemStats* itemStats;
    char* name;
    unsigned int kind : 4;
    unsigned int mode : 5;
    unsigned int : 23;
    char unknown_c_[0xc];
    short itemId;               // -1: nothing in the slot
    char unknown_1a_[6];
};

struct Struct_02083e28_11 {
    char unk0[0x14];
    struct Struct_02083e28_8 unknown_14_[5];
    short count;
    char unknown_2a_[2];
};

struct Struct_02083e28 {
    unsigned char values[0x18];
};

struct Struct_02083e28_2 {
    struct StatTriple w[3];
};

struct BattleUnit {
    struct StatTriple stats[3];
    struct StatTriple style[3];     // the best style score, then the six scores
    char unknown_18_[4];
    unsigned short hp;
    unsigned short mp;
    char unknown_20_;
    unsigned char unknown_21_[0x18];
    char unknown_39_[0x33];
    unsigned short maxHp;
    unsigned short maxMp;
    unsigned short attack;
    unsigned short defence;
    unsigned short agility;
    char unknown_76_[2];
    struct StatTriple unknown_78_;
    unsigned char unknown_7c_[0x18];
    char unknown_94_[0x100];
    struct Record020836e4 records[11];
    struct Struct_02083e28_11 unknown_2f4_[8];
#if defined(jpn)
    char unknown_454_[0x7b8 - 0x454];
#else
    char unknown1_454_[0x850 - 0x454];
#endif
    struct Struct_02083e28_2 rows[17];
    struct StatTriple base[3];
    char unknown_928_[0xc];
    unsigned char unknown_934_[0x16];
    char unknown_94a_[6];
    int unknown_950_;
};

struct StatOutputs {
    struct Record020836e4* record;
    short* attack;
    short* defence;
    float* rateA;
    float* rateB;
    float* evasionChance;
    float* rateD;
    short* deftness;
    short* agility;
    short* magicalMight;
    short* magicalMending;
    short* maxHp;
    short* maxMp;
    unsigned char skipMode;
};

extern "C" int func_02085fb4(unsigned char*);
extern "C" int func_02086020(unsigned char*);
extern "C" int func_0208608c(unsigned char*);
extern "C" int func_020860f8(unsigned char*);
extern "C" int func_02086164(unsigned char*);
extern "C" int func_020861d0(unsigned char*);
extern "C" int func_0208623c(unsigned char*);
extern "C" int func_020862a8(unsigned char*);
extern "C" int func_02086314(unsigned char*);
extern "C" int func_02085cd0(unsigned char*, int);
extern "C" int func_02085f1c(unsigned char*, int);
extern "C" int func_02085b88(unsigned char*);
struct Struct_02083e28_6;
extern "C" void func_020863e0(Struct_02083e28_6*);
extern "C" void ItemRecord_Copy(struct Record020836e4*, struct Record020836e4*);

static inline void inline_02083e28(unsigned char* dst, struct Struct_02083e28 set) {
    memcpy(dst, &set, sizeof(set));
}

static inline void SetDerivedLow(struct BattleUnit* unit, unsigned short value) {
    unit->unknown_78_.f0 = value;
}

static inline void SetDerivedMid(struct BattleUnit* unit, unsigned short value) {
    unit->unknown_78_.f1 = value;
}

static inline void SetDerivedHigh(struct BattleUnit* unit, unsigned short value) {
    unit->unknown_78_.f2 = value;
}

// Main, originally func_02083e28 (USA 0x02083e28, EUR 0x02083e38, JPN 0x02084740)
extern "C" ARM void PartyMember_RecalculateStats(struct BattleUnit* unit, struct StatOutputs* out) {
    int strength = func_02085fb4((unsigned char*)unit) + unit->base[0].f0;
    int agility = func_02086020((unsigned char*)unit) + unit->base[0].f1;
    int resilience = func_0208608c((unsigned char*)unit) + unit->base[0].f2;
    int deftness = func_020860f8((unsigned char*)unit) + unit->base[1].f0;
    int charm = func_02086164((unsigned char*)unit) + unit->base[1].f1;
    int magicalMending = func_020861d0((unsigned char*)unit) + unit->base[1].f2;
    int magicalMight = func_0208623c((unsigned char*)unit) + unit->base[2].f0;
    int maxHp = func_020862a8((unsigned char*)unit) + unit->base[2].f1;
    int maxMp = func_02086314((unsigned char*)unit) + unit->base[2].f2;
    float rateA;
    float rateB;
    float evasionChance;
    float rateD;
    rateD = evasionChance = rateB = rateA = 0.0f;
    struct Struct_02083e28_2* row = &unit->rows[unit->unknown_950_];
    strength += row->w[0].f0;
    agility += row->w[0].f1;
    resilience += row->w[0].f2;
    deftness += row->w[1].f0;
    charm += row->w[1].f1;
    magicalMending += row->w[1].f2;
    magicalMight += row->w[2].f0;
    maxHp += row->w[2].f1;
    maxMp += row->w[2].f2;
    if (strength > 999) strength = 999;
    if (resilience > 999) resilience = 999;
    if (charm > 999) charm = 999;
    if (strength < 0) strength = 0;
    if (resilience < 0) resilience = 0;
    if (charm < 0) charm = 0;

    int styleScores[6] = {0};
    for (int i = 0; i < 6; i++) {
        styleScores[i] = charm;
    }
    struct Record020836e4* recs[11];
    for (int i = 0; i < 11; i++) {
        recs[i] = &unit->records[i];
    }
    struct Record020836e4* rec;
    if (out != NULL && (rec = out->record) != NULL) {
        switch (rec->kind) {
        case 0: recs[8] = rec; break;
        case 1: recs[9] = rec; break;
        case 4: recs[7] = rec; break;
        case 2: recs[0] = rec; break;
        case 5: recs[5] = rec; break;
        case 3: recs[1] = rec; break;
        case 6: recs[6] = rec; break;
        case 7: recs[10] = rec; break;
        }
    }
    for (int i = 0; i < 11; i++) {
        struct Record020836e4* r = recs[i];
        struct ItemStats* blk;
        if (r != NULL && r->itemId > 0 && (blk = r->itemStats) != NULL) {
            agility += blk->bonusA.agility;
            deftness += blk->bonusA.deftness;
            magicalMight += blk->bonusA.magicalMight;
            magicalMending += blk->bonusB.magicalMending;
            maxHp += blk->bonusB.maxHp;
            maxMp += blk->bonusB.maxMp;
            rateA += blk->attackDefence.u2 / 10.0f;
            rateB += blk->rates.f0 / 10.0f;
            evasionChance += blk->rates.evasion / 10.0f;
            rateD += blk->rates.f2 / 10.0f;
            styleScores[0] += blk->styleA.s1;
            styleScores[1] += blk->styleA.s2;
            styleScores[2] += blk->styleB.s0;
            styleScores[3] += blk->styleB.s1;
            styleScores[4] += blk->styleB.s2;
            styleScores[5] += blk->styleA.s0;
        }
    }
    if (agility > 999) agility = 999;
    if (deftness > 999) deftness = 999;
    if (magicalMending > 999) magicalMending = 999;
    if (magicalMight > 999) magicalMight = 999;
    if (maxHp > 999) maxHp = 999;
    if (maxMp > 999) maxMp = 999;
    if (agility < 0) agility = 0;
    if (deftness < 0) deftness = 0;
    if (magicalMending < 0) magicalMending = 0;
    if (magicalMight < 0) magicalMight = 0;
    if (maxHp < 1) maxHp = 1;
    if (maxMp < 0) maxMp = 0;
    int style = 0;
    for (int i = 0; i < 6; i++) {
        if (styleScores[i] > 999) {
            styleScores[i] = 999;
        } else if (styleScores[i] < 0) {
            styleScores[i] = 0;
        }
        if (style < styleScores[i]) style = styleScores[i];
    }

    if (out == NULL) {
        unit->stats[0].f0 = strength;
        unit->stats[0].f1 = agility;
        unit->stats[0].f2 = resilience;
        unit->stats[1].f0 = deftness;
        unit->stats[1].f1 = charm;
        unit->stats[1].f2 = magicalMending;
        unit->stats[2].f0 = magicalMight;
        unit->stats[2].f1 = maxHp;
        unit->stats[2].f2 = maxMp;
        unit->style[0].f0 = style;
        unit->style[0].f1 = styleScores[0];
        unit->style[0].f2 = styleScores[1];
        unit->style[1].f0 = styleScores[2];
        unit->style[1].f1 = styleScores[3];
        unit->style[1].f2 = styleScores[4];
        unit->style[2].f0 = styleScores[5];

        int attack = unit->stats[0].f0;
        int defence = unit->stats[0].f2;
        int agility = unit->stats[0].f1;
        int charm = unit->stats[1].f1;
        int magicalMending = unit->stats[1].f2;
        int magicalMight = unit->stats[2].f0;
        int maxHp = unit->stats[2].f1;
        int var31 = unit->stats[2].f2;
        for (int i = 0; i < 11; i++) {
            struct Record020836e4* r = &unit->records[i];
            if (r != NULL && r->itemId > 0 && r->itemStats != NULL) {
                attack += r->itemStats->attackDefence.attack;
                defence += r->itemStats->attackDefence.defence;
            }
        }
        attack += func_02085cd0((unsigned char*)unit, -1);
        int maxMp = func_02085f1c((unsigned char*)unit, -1) + var31;
        if (attack > 999) attack = 999;
        if (defence > 999) defence = 999;
        if (maxMp > 999) maxMp = 999;
        if (attack < 0) attack = 0;
        if (defence < 0) defence = 0;
        if (maxMp < 0) maxMp = 0;
        unit->attack = attack;
        unit->defence = defence;
        unit->agility = agility;
        SetDerivedLow(unit, charm);
        SetDerivedHigh(unit, magicalMending);
        SetDerivedMid(unit, magicalMight);
        unit->maxHp = maxHp;
        unit->maxMp = maxMp;
        func_020863e0((Struct_02083e28_6*)unit);

        short totals[0x16] = {0};
        for (int i = 0; i < 0x16; i++) {
            totals[i] = unit->unknown_934_[i];
        }
        for (int i = 0; i < 8; i++) {
            struct Struct_02083e28_11* slot = &unit->unknown_2f4_[i];
            if (slot->count > 0) {
                totals[0] += slot->unknown_14_[0].b0;
                totals[1] += slot->unknown_14_[0].b1;
                totals[2] += slot->unknown_14_[0].b2;
                totals[3] += slot->unknown_14_[0].b3;
                totals[4] += slot->unknown_14_[1].b0;
                totals[5] += slot->unknown_14_[1].b1;
                totals[6] += slot->unknown_14_[1].b2;
                totals[8] += slot->unknown_14_[1].b3;
                totals[9] += slot->unknown_14_[2].b0;
                totals[10] += slot->unknown_14_[2].b1;
                totals[11] += slot->unknown_14_[2].b2;
                totals[12] += slot->unknown_14_[2].b3;
                totals[13] += slot->unknown_14_[3].b0;
                totals[14] += slot->unknown_14_[3].b1;
                totals[15] += slot->unknown_14_[3].b2;
                totals[16] += slot->unknown_14_[3].b3;
                totals[17] += slot->unknown_14_[4].b0;
                totals[18] += slot->unknown_14_[4].b1;
                totals[19] += slot->unknown_14_[4].b2;
                totals[20] += slot->unknown_14_[4].b3;
            }
        }
        struct Struct_02083e28 set;
        memset(&set, 100, 0x16);
        for (int i = 0; i < 0x16; i++) {
            if (totals[i] < 0) totals[i] = 0;
            set.values[i] = totals[i];
        }
        inline_02083e28(unit->unknown_7c_, set);
        inline_02083e28(unit->unknown_21_, set);
    } else {
        *out->rateA = rateA;
        *out->evasionChance = evasionChance;
        *out->rateD = rateD;
        *out->deftness = deftness;
        *out->agility = agility;
        *out->magicalMight = magicalMight;
        *out->magicalMending = magicalMending;
        *out->maxHp = maxHp;
        int attack = strength;
        int defence = resilience;
        for (int i = 0; i < 11; i++) {
            struct Record020836e4* r = recs[i];
            if (r != NULL && r->itemId > 0 && r->itemStats != NULL) {
                attack += r->itemStats->attackDefence.attack;
                defence += r->itemStats->attackDefence.defence;
            }
        }
        unsigned char mode = 0x21;
        if (recs[8]->itemId > 0) mode = recs[8]->mode;
        signed char weapon = mode;
        attack += func_02085cd0((unsigned char*)unit, weapon);
        if (out->skipMode == 0) {
            maxMp += func_02085f1c((unsigned char*)unit, weapon);
        }
        struct Record020836e4* shield;
        if (out->skipMode != 0 && (shield = recs[9]) != NULL && shield->itemId > 0) {
            struct Record020836e4 saved = unit->records[9];
            ItemRecord_Copy(&unit->records[9], shield);
            rateB += func_02085b88((unsigned char*)unit);
            ItemRecord_Copy(&unit->records[9], &saved);
        }
        if (attack > 999) attack = 999;
        if (defence > 999) defence = 999;
        if (maxMp > 999) maxMp = 999;
        if (attack < 0) attack = 0;
        *out->attack = attack;
        if (defence < 0) defence = 0;
        *out->defence = defence;
        if (maxMp < 0) maxMp = 0;
        *out->maxMp = maxMp;
        *out->rateB = rateB;
    }
}
