#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215ec80(int battle, short* buf, int max, int group, int flag);

struct Struct_ov024_021ef074 {
    unsigned char b0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
};

struct Struct_ov024_021ef074_2 {
    struct Random rng;
    char pad[0x81b0 - sizeof(struct Random)];
    struct Struct_ov024_021ef074 groups;
};

struct Struct_ov024_021ef074_3 {
    struct Struct_ov024_021ef074_2* battle;
};

static inline struct Struct_ov024_021ef074* inline_ov024_021ef074(struct Struct_ov024_021ef074_2* battle) {
    return &battle->groups;
}

struct Struct_ov024_021fea1c_2 { short v[3]; };
struct Struct_ov024_021fed1c { short v[8]; };

extern struct Struct_ov024_021fea1c_2 data_ov024_021fea1c[];
extern struct Struct_ov024_021fed1c data_ov024_021fed1c;

// USA: func_ov024_021ef074
extern "C" ARM int func_ov024_021ef074(struct Struct_ov024_021ef074_3* ctx, int unused1, int arg2, int* out, short* outIds) {
    struct Struct_ov024_021ef074* groups = inline_ov024_021ef074(ctx->battle);
    if (groups == 0) return 0;
    struct Struct_ov024_021fea1c_2 var1 = data_ov024_021fea1c[1];
    short var2 = 0;
    for (int i = 0; i < groups->groupCount; i++) {
        struct Struct_ov024_021fed1c ids = data_ov024_021fed1c;
        int count = func_ov000_0215ec80((int)ctx->battle, ids.v, 8, i & 0xff, 1);
        if (count <= 0) continue;
        short var6 = 0;
        for (int j = 0; j < count; j++) {
            GameObject* c = GetCombatantByID((int)ctx->battle, ids.v[j]);
            if (c == 0) continue;
            ModifiableCombatStats* stats = c->currentStats_;
            if (stats->primaryStats.defense >= 0xffff) continue;
            if (stats->defenseBuff < 2) var6++;
        }
        if (var6 > 0) var1.v[var2++] = i;
    }
    if (var2 <= 0) return 0;
    int r = NextRandomMax(&ctx->battle->rng, var2);
    *out = func_ov000_0215ec80((int)ctx->battle, outIds, 8, var1.v[r] & 0xff, 1);
    return 1;
}
