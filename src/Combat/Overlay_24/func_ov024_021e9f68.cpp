#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
struct Random;

struct Struct_ov024_021e9f68 {
    char pad0[0x14];
    unsigned int unknown_14_;
    char pad18[0x21 - 0x18];
    unsigned char unknown_21_;
};

struct Struct_ov024_021e9f68_2 {
    char pad0[0x138];
    struct Struct_ov024_021e9f68* stats;
#if defined(jpn)
    char unknown_13c_[0x144 - 0x13c];
#else
    char unknown1_13c_[0x150 - 0x13c];
#endif
    unsigned char* field150;
};

struct Struct_ov024_021e9f68_3 {
    char pad0[0xc];
    void* queue;
    struct Random* battle;
    char unknown_14_[0x20 - 0x14];
    short unknown_20_[4];
    short unknown_28_[8];
    unsigned char unknown_38_[4];
    unsigned char unknown_3c_[8];
    char unknown_44_[0x76 - 0x44];
    unsigned char unknown_76_;
    unsigned char unknown_77_;
};

struct Struct_ov024_021e9f68_4 {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int lo8 : 8;
    unsigned int kind : 2;
    unsigned int unknown_9_2_ : 22;
    unsigned int unknown_c_;
    unsigned int flags10;
};

struct Struct_ov024_021fe708 {
    short v[8];
};

extern const struct Struct_ov024_021fe708 data_ov024_021fe768;
extern const struct Struct_ov024_021fe708 data_ov024_021fe708;

struct Struct_ov024_021e9f68_2* GetCombatantByID(int, int);
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov024_021e6798(GameObject*);
struct GameObject;
extern "C" int func_ov024_021e7ba8(GameObject*);
extern "C" void func_ov000_0215ff50(void* obj, short val1, unsigned char val2);
extern "C" int func_02085474(unsigned char* obj);
int NextRandomMax(struct Random* random, int maximum);
extern "C" int func_ov000_02155f9c(struct Random* battle, int id, int arg2);
extern "C" int func_ov024_021ea500(struct Struct_ov024_021e9f68_3* ctx, struct Struct_ov024_021e9f68_4* action, int id);
extern "C" int func_ov000_0215eb1c(struct Random* battle, short* out, int max, int flags);
extern "C" int func_ov000_0215e9fc(struct Random* battle, short* out, int max, int flags);
extern "C" int func_ov000_02156558(struct Random* battle, int id);

static inline int inline_ov024_021e9f68(struct Struct_ov024_021e9f68_2* c, int kind) {
    return c->stats->unknown_21_ == kind;
}

// USA: func_ov024_021e9f68
extern "C" ARM int func_ov024_021e9f68(struct Struct_ov024_021e9f68_3* ctx, short* a, short* b, struct Struct_ov024_021e9f68_4* action,
                                       unsigned char* out) {
    struct Struct_ov024_021e9f68_2* self;
    GameState* gs;
    short saved;
    void* queue;
    struct Random* var4;
    unsigned char* state;
    short* target;
    if (ctx->queue == 0) {
        return 0;
    }
    self = GetCombatantByID((int)ctx->battle, *b);
    if (!self) {
        return 0;
    }
    if (func_02010088((struct S_10088*)self) || func_ov024_021e6798((GameObject*)self)) {
        return 0;
    }
    gs = GameState::GetInstance();
    var4 = ctx->battle;
    saved = *a;
    queue = ctx->queue;
    *out = 0;
    if (func_ov024_021e7ba8((GameObject*)self)) {
        return 0;
    }
    if ((action->flags10 & 0x400) && action->kind == 1 && *a != *b) {
        if (self->stats->unknown_14_ & 0x200) {
            func_ov000_0215ff50(queue, *a, 1);
            *a = *b;
            *b = saved;
            ctx->unknown_76_ = 0;
            *out = 1;
            return 0;
        }
        int inRange = *b >= 0 && *b <= 3;
        if (inRange) {
            struct Struct_ov024_021e9f68_2* c = (Struct_ov024_021e9f68_2*)func_0200ff1c(gs, *b);
            if (c && func_02085474(c->field150) && NextRandomMax(var4, 4) == 0) {
                func_ov000_0215ff50(queue, *a, 1);
                *a = *b;
                *b = saved;
                ctx->unknown_76_ = 0;
                *out = 1;
                return 0;
            }
        }
    }
    if ((action->flags10 & 4) && action->kind == 1 && (self->stats->unknown_14_ & 0x4000000)) {
        func_ov000_0215ff50(queue, *a, 2);
        *a = *b;
        *b = saved;
        ctx->unknown_76_ = 0;
        return 0;
    }
    if (func_ov000_02155f9c(ctx->battle, *b, 0)) {
        return 0;
    }
    int inRange = 0;
    int id = *b;
    if (id >= 0 && id <= 3) {
        inRange = 1;
    }
    if (inRange) {
        state = &ctx->unknown_38_[*b];
        target = &ctx->unknown_20_[*b];
    } else {
        state = &ctx->unknown_3c_[id - 0xc0];
        target = &ctx->unknown_28_[id - 0xc0];
    }
    int busy = func_ov024_021ea500(ctx, action, *a);
    if ((action->flags10 & 0x80) && busy == 0) {
        if (inline_ov024_021e9f68(self, 4)) {
            func_ov000_0215ff50(queue, *a, 3);
            *a = *b;
            *b = saved;
            ctx->unknown_76_ = 0;
            *state = 1;
            return 1;
        }
        if (inline_ov024_021e9f68(self, 5)) {
            struct Struct_ov024_021fe708 ids = data_ov024_021fe768;
            int isParty = *b >= 0 && *b <= 3;
            int count;
            if (isParty) {
                count = func_ov000_0215eb1c(ctx->battle, ids.v, 8, 1);
            } else {
                count = func_ov000_0215e9fc(ctx->battle, ids.v, 8, 1);
            }
            if (*target < 0) {
                *target = ids.v[NextRandomMax(var4, count)];
            }
            func_ov000_0215ff50(queue, *target, 4);
            *a = *b;
            *b = *target;
            ctx->unknown_76_ = 0;
            ctx->unknown_77_ = 1;
            return 0;
        }
        if (inline_ov024_021e9f68(self, 9)) {
            int roll = NextRandomMax(var4, 5);
            struct Struct_ov024_021fe708 ids = data_ov024_021fe708;
            int isParty = *b >= 0 && *b <= 3;
            int count;
            if (isParty) {
                if (roll < 2) {
                    count = func_ov000_0215e9fc(ctx->battle, ids.v, 8, 1);
                } else {
                    count = func_ov000_0215eb1c(ctx->battle, ids.v, 8, 1);
                }
            } else {
                if (roll < 2) {
                    count = func_ov000_0215eb1c(ctx->battle, ids.v, 8, 1);
                } else {
                    count = func_ov000_0215e9fc(ctx->battle, ids.v, 8, 1);
                }
            }
            if (*target < 0) {
                *target = ids.v[NextRandomMax(var4, count)];
            }
            if (*b == *target) {
                func_ov000_0215ff50(queue, *target, 10);
            } else {
                func_ov000_0215ff50(queue, *target, 5);
                *a = *b;
                ctx->unknown_76_ = 0;
                ctx->unknown_77_ = 1;
            }
            *b = *target;
            return 0;
        }
        int isParty = *b >= 0 && *b <= 3;
        if (isParty) {
            struct Random* battle = ctx->battle;
            if (*state == 0) {
                if (!func_ov000_02156558(battle, *b)) {
                    *state = 2;
                    return 0;
                }
                func_ov000_0215ff50(queue, *a, 3);
                *a = *b;
                *b = saved;
                *state = 1;
                ctx->unknown_76_ = 0;
                return 1;
            } else if (*state == 1) {
                func_ov000_0215ff50(queue, *a, 3);
                *a = *b;
                *b = saved;
                ctx->unknown_76_ = 0;
                return 1;
            }
        }
    }
    return 0;
}
