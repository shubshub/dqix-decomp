#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02083e28_10 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int : 2;
};

struct Struct_02083e28_4 {
    int unknown_0_0_ : 10;
    int unknown_1_2_ : 10;
    int unknown_2_4_ : 10;
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

struct ByteQuad {
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
    char unkC[0xc];
    short itemId;               // -1: nothing in the slot
    char unk1a[6];
};

struct Struct_02083e28_11 {
    char unknown_0_[0x14];
    struct Struct_02083e28_8 unknown_14_[5];
    short unknown_28_;
    char unknown_2a_[2];
};

struct Struct_02083e28 {
    unsigned char unknown_0_[0x18];
};

struct Struct_02083e28_2 {
    struct Struct_02083e28_10 unknown_0_[3];
};

struct BattleUnit {
    struct StatTriple stats[3];
    struct StatTriple style[3];     // the best style score, then the six scores
    char unk18[4];
    unsigned short hp;
    unsigned short mp;
    char unk20;
    unsigned char resistCopy[0x18];
    char unk39[0x33];
    unsigned short maxHp;
    unsigned short maxMp;
    unsigned short attack;
    unsigned short defence;
    unsigned short agility;
    char unk76[2];
    struct StatTriple derived;
    unsigned char resistances[0x18];
    char unk94[0x100];
    struct Record020836e4 records[11];
    struct EquipSlot equips[8];
#if defined(jpn)
    char unknown_454_[0x7b8 - 0x454];
#else
    char unknown1_454_[0x850 - 0x454];
#endif
    struct Struct_02083e28_2 unknown_850_[17];
    struct Struct_02083e28_10 unknown_91c_[3];
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
int AccumulateModeSlotBits02085f1c(unsigned char*, int);
int AccumulateSlotBits02085b88(unsigned char*);
struct ClampFieldPairStruct;
void ClampFieldPairToMax_020863e0(ClampFieldPairStruct*);
void ItemRecord_Copy(struct Record020836e4*, struct Record020836e4*);

static inline void inline_02083e28(unsigned char* arg0, struct Struct_02083e28 arg1) {
    memcpy(arg0, &arg1, sizeof(arg1));
}

static inline void inline_02083e28_2(struct Struct_02083e28_3* arg0, unsigned short arg1) {
    arg0->unknown_78_.unknown_0_0_ = arg1;
}

static inline void inline_02083e28_3(struct Struct_02083e28_3* arg0, unsigned short arg1) {
    arg0->unknown_78_.unknown_1_2_ = arg1;
}

static inline void inline_02083e28_4(struct Struct_02083e28_3* arg0, unsigned short arg1) {
    arg0->unknown_78_.unknown_2_4_ = arg1;
}

// Main, originally func_02083e28 (USA 0x02083e28, EUR 0x02083e38, JPN 0x02084740)
extern "C" ARM void PartyMember_RecalculateStats(struct BattleUnit* unit, struct StatOutputs* out) {
    int strength = AccumulateFlaggedSlotBits02085fb4((unsigned char*)unit) + unit->base[0].f0;
    int agility = AccumulateFlaggedSlotBits02086020((unsigned char*)unit) + unit->base[0].f1;
    int resilience = AccumulateFlaggedSlotBits0208608c((unsigned char*)unit) + unit->base[0].f2;
    int deftness = AccumulateFlaggedSlotBits020860f8((unsigned char*)unit) + unit->base[1].f0;
    int charm = AccumulateFlaggedSlotBits02086164((unsigned char*)unit) + unit->base[1].f1;
    int magicalMending = AccumulateFlaggedSlotBits020861d0((unsigned char*)unit) + unit->base[1].f2;
    int magicalMight = AccumulateFlaggedSlotBits0208623c((unsigned char*)unit) + unit->base[2].f0;
    int maxHp = AccumulateSlotBitsFromTable020862a8((unsigned char*)unit) + unit->base[2].f1;
    int maxMp = AccumulateSlotBitsFromTable02086314((unsigned char*)unit) + unit->base[2].f2;
    float rateA;
    float rateB;
    float evasionChance;
    float rateD;
    rateD = evasionChance = rateB = rateA = 0.0f;
    struct StatRow* row = &unit->rows[unit->rowIndex];
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
    struct Struct_0208358c_2* var16[11];
    for (int var17 = 0; var17 < 11; var17++) {
        var16[var17] = &arg0->unknown_194_[var17];
    }
    struct Struct_0208358c_2* var18;
    if (arg1 != NULL && (var18 = arg1->unknown_0_) != NULL) {
        switch (var18->unknown_8_0_) {
        case 0: var16[8] = var18; break;
        case 1: var16[9] = var18; break;
        case 4: var16[7] = var18; break;
        case 2: var16[0] = var18; break;
        case 5: var16[5] = var18; break;
        case 3: var16[1] = var18; break;
        case 6: var16[6] = var18; break;
        case 7: var16[10] = var18; break;
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
        int maxMpBase = unit->stats[2].f2;
        for (int i = 0; i < 11; i++) {
            struct Record020836e4* r = &unit->records[i];
            if (r != NULL && r->itemId > 0 && r->itemStats != NULL) {
                attack += r->itemStats->attackDefence.attack;
                defence += r->itemStats->attackDefence.defence;
            }
        }
        attack += func_02085cd0((unsigned char*)unit, -1);
        int maxMp = AccumulateModeSlotBits02085f1c((unsigned char*)unit, -1) + maxMpBase;
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
        ClampFieldPairToMax_020863e0((ClampFieldPairStruct*)unit);

        short var35[0x16] = {0};
        for (int var36 = 0; var36 < 0x16; var36++) {
            var35[var36] = arg0->unknown_934_[var36];
        }
        for (int var37 = 0; var37 < 8; var37++) {
            struct Struct_02083e28_11* var38 = &arg0->unknown_2f4_[var37];
            if (var38->unknown_28_ > 0) {
                var35[0] += var38->unknown_14_[0].unknown_0_0_;
                var35[1] += var38->unknown_14_[0].unknown_1_0_;
                var35[2] += var38->unknown_14_[0].unknown_2_0_;
                var35[3] += var38->unknown_14_[0].unknown_3_0_;
                var35[4] += var38->unknown_14_[1].unknown_0_0_;
                var35[5] += var38->unknown_14_[1].unknown_1_0_;
                var35[6] += var38->unknown_14_[1].unknown_2_0_;
                var35[8] += var38->unknown_14_[1].unknown_3_0_;
                var35[9] += var38->unknown_14_[2].unknown_0_0_;
                var35[10] += var38->unknown_14_[2].unknown_1_0_;
                var35[11] += var38->unknown_14_[2].unknown_2_0_;
                var35[12] += var38->unknown_14_[2].unknown_3_0_;
                var35[13] += var38->unknown_14_[3].unknown_0_0_;
                var35[14] += var38->unknown_14_[3].unknown_1_0_;
                var35[15] += var38->unknown_14_[3].unknown_2_0_;
                var35[16] += var38->unknown_14_[3].unknown_3_0_;
                var35[17] += var38->unknown_14_[4].unknown_0_0_;
                var35[18] += var38->unknown_14_[4].unknown_1_0_;
                var35[19] += var38->unknown_14_[4].unknown_2_0_;
                var35[20] += var38->unknown_14_[4].unknown_3_0_;
            }
        }
        struct Struct_02083e28 var39;
        memset(&var39, 100, 0x16);
        for (int var40 = 0; var40 < 0x16; var40++) {
            if (var35[var40] < 0) var35[var40] = 0;
            var39.unknown_0_[var40] = var35[var40];
        }
        inline_02083e28(arg0->unknown_7c_, var39);
        inline_02083e28(arg0->unknown_21_, var39);
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
            maxMp += AccumulateModeSlotBits02085f1c((unsigned char*)unit, weapon);
        }
        struct Record020836e4* shield;
        if (out->skipMode != 0 && (shield = recs[9]) != NULL && shield->itemId > 0) {
            struct Record020836e4 saved = unit->records[9];
            ItemRecord_Copy(&unit->records[9], shield);
            rateB += AccumulateSlotBits02085b88((unsigned char*)unit);
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
