#include <globaldefs.h>
#include "Util/Random.h"
#include "GameState/GameState.h"
#include "Combat/Main/CombatCalculations.h"

struct Struct_ov002_021538e4 {
    unsigned int : 8;
    unsigned int y : 10;
    unsigned int : 14;
    unsigned int : 10;
    unsigned int d : 10;
    unsigned int c : 10;
    unsigned int : 2;
};

struct Struct_ov002_021538e4_2 {
    int unused0;
    unsigned int : 12;
    unsigned int a : 10;
    unsigned int b : 10;
    char pad8[0x10 - 0x8];
    unsigned int field10;
    char unknown_14_[0x18 - 0x14];
    unsigned int : 16;
    unsigned int mode : 2;
    unsigned int : 14;
};

// USA: func_ov002_021538e4
extern "C" ARM int func_ov002_021538e4(void* unused, struct Struct_ov002_021538e4_2* p, struct Struct_ov002_021538e4* sb, int combatantId) {
    struct Random* rng = GetBTRandom();
    float result = 0.0f;

    if (sb != 0) {
    if (p->mode == 2) {
        GameState* bs = GameState::GetInstance();
        GameObject* combatant = func_0200ff1c(bs, combatantId);
        if (combatant == 0) {
            return 0;
        }
        if ((p->field10 & 0x8000) != 0) {
            unsigned short var4 = combatant->baseStats_->primaryStats.magicalMending;
            unsigned int a = p->a;
            if (var4 <= a) {
                unsigned int y = sb->y;
                float var7 = NextRandomFloatBetween(rng, (float)y * -1.0f, (float)y);
                unsigned int d = sb->d;
                result = (float)d + var7;
            } else {
                unsigned int b = p->b;
                if (var4 >= b) {
                    unsigned int y = sb->y;
                    float var11 = NextRandomFloatBetween(rng, (float)y * -1.0f, (float)y);
                    unsigned int c = sb->c;
                    result = (float)c + var11;
                } else {
                    unsigned int c = sb->c;
                    unsigned int d = sb->d;
                    float t = (float)(c - d) / (float)(p->b - a);
                    unsigned int var16 = (unsigned int)(int)(t * (float)(var4 - a)) + d;
                    float var17 = (float)var16;
                    unsigned int y = sb->y;
                    result = var17 + NextRandomFloatBetween(rng, (float)y * -1.0f, (float)y);
                }
            }
        } else {
            unsigned int d = sb->d;
            unsigned int c = sb->c;
            float r1 = NextRandomFloatBetween(rng, (float)d, (float)c);
            unsigned int y = sb->y;
            float r2 = NextRandomFloatBetween(rng, (float)y * -1.0f, (float)y);
            result = r1 + r2;
        }
    } else {
        unsigned int d = sb->d;
        unsigned int c = sb->c;
        float r1 = NextRandomFloatBetween(rng, (float)d, (float)c);
        unsigned int y = sb->y;
        float r2 = NextRandomFloatBetween(rng, (float)y * -1.0f, (float)y);
        result = r1 + r2;
    }
    }

    return RoundUp(result);
}
