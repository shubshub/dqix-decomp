#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
struct Random;
struct ArrayContainsByteStruct;

struct Struct_02000c9c_77 {
    char pad0[0x21];
    unsigned char unknown_21_;
    char unknown_22_[0x2a - 0x22];
    short unknown_2a_;
};

struct Struct_ov024_021e9b74 {
    char pad0[0x138];
    struct Struct_02000c9c_77* stats;
};

struct Struct_ov024_021e9b74_2 {
    char pad0[0xc];
    void* queue;
    int battle;
    char unknown_14_[0x79 - 0x14];
    unsigned char unknown_79_;
};

struct Struct_ov024_021e9b74_3 {
    short targetId;
};

struct Struct_ov024_021e9b74_4 {
    char pad0[0x10];
    unsigned int flags10;
};

struct Struct_ov024_021fe6f8 {
    short v[8];
};

struct Struct_ov024_021fe7e0 {
    int v[8];
};

extern const struct Struct_ov024_021fe6f8 data_ov024_021fe6f8;
extern const struct Struct_ov024_021fe7e0 data_ov024_021fe7e0;

struct Struct_ov024_021e9b74* GetCombatantByID(int unused, int id);
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov024_021e6798(GameObject* combatant);
extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);
extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
extern "C" int func_ov000_02155f9c(int battle, int id, int v);
int NextRandomMax(struct Random* random, int maximum);
extern "C" void func_ov000_0215ff20(void* obj, short val1, unsigned char val2);
extern "C" float func_ov024_021db358(struct Struct_ov024_021e9b74* obj);
extern "C" void* GameState_GetParty(GameState* gameState);
extern "C" int func_02086ef0(struct ArrayContainsByteStruct* s, int val);
extern "C" void func_ov000_0215a8d4(unsigned char* obj, int idx);

static inline short inline_ov024_021e9b74(struct Struct_ov024_021e9b74* c) { SDK_NULL_ASSERT(c); return c->stats->unknown_2a_; }

static inline int inline_ov024_021e9b74_2(struct Struct_ov024_021e9b74* c, int kind) {
    return c->stats->unknown_21_ == kind;
}

// USA: func_ov024_021e9b74
extern "C" ARM int func_ov024_021e9b74(struct Struct_ov024_021e9b74_2* ctx, int unused, struct Struct_ov024_021e9b74_3* cmd,
                                       struct Struct_ov024_021e9b74_4* action) {
    void* queue;
    int n;
    int i;
    struct Random* var3;
    if (ctx->queue == 0) {
        return 0;
    }
    struct Struct_ov024_021e9b74* self = GetCombatantByID(ctx->battle, cmd->targetId);
    if (!self) {
        return 0;
    }
    if (func_02010088((struct S_10088*)self) || func_ov024_021e6798((GameObject*)self)) {
        return 0;
    }
    GameState::GetInstance();
    var3 = (struct Random*)ctx->battle;
    queue = ctx->queue;
    if (action->flags10 & 0x1000) {
        struct Struct_ov024_021fe6f8 ids = data_ov024_021fe6f8;
        int isParty = cmd->targetId >= 0 && cmd->targetId <= 3;
        int count;
        if (isParty) {
            count = func_ov000_0215e9fc(ctx->battle, ids.v, 8, 1);
        } else {
            count = func_ov000_0215eb1c(ctx->battle, ids.v, 8, 1);
        }
        struct Struct_ov024_021fe7e0 var8 = data_ov024_021fe7e0;
        n = 0;
        for (i = 0; i < count; i++) {
            struct Struct_ov024_021e9b74* c = GetCombatantByID(ctx->battle, ids.v[i]);
            if (c && cmd->targetId != ids.v[i] && !func_ov000_02155f9c(ctx->battle, ids.v[i], 0) &&
                inline_ov024_021e9b74_2(c, 8)) {
                var8.v[n++] = ids.v[i];
            }
        }
        if (n > 0) {
            cmd->targetId = var8.v[NextRandomMax(var3, n)];
            func_ov000_0215ff20(queue, cmd->targetId, 6);
            ctx->unknown_79_ = 1;
            return 1;
        }
        n = 0;
        memset(&var8, -1, sizeof(var8));
        if (func_ov024_021db358(self) <= 0.08f) {
            for (i = 0; i < count; i++) {
                struct Struct_ov024_021e9b74* c = GetCombatantByID(ctx->battle, ids.v[i]);
                if (c && cmd->targetId != ids.v[i] && !func_ov000_02155f9c(ctx->battle, ids.v[i], 0) &&
                    inline_ov024_021e9b74_2(c, 7)) {
                    var8.v[n++] = ids.v[i];
                }
            }
            if (n > 0) {
                cmd->targetId = var8.v[NextRandomMax(var3, n)];
                func_ov000_0215ff20(queue, cmd->targetId, 7);
                ctx->unknown_79_ = 1;
                return 1;
            }
        }
        n = 0;
        memset(&var8, -1, sizeof(var8));
        for (i = 0; i < count; i++) {
            struct Struct_ov024_021e9b74* c = GetCombatantByID(ctx->battle, ids.v[i]);
            if (c && !func_ov000_02155f9c(ctx->battle, ids.v[i], 0) && inline_ov024_021e9b74_2(c, 6) &&
                cmd->targetId == inline_ov024_021e9b74(c)) {
                var8.v[n++] = ids.v[i];
            }
        }
        if (n > 0) {
            cmd->targetId = var8.v[NextRandomMax(var3, n)];
            func_ov000_0215ff20(queue, cmd->targetId, 8);
            ctx->unknown_79_ = 1;
            if (func_02086ef0((struct ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance()),
                                  cmd->targetId)) {
                func_ov000_0215a8d4((unsigned char*)ctx->battle, 4);
            }
            return 1;
        }
        memset(&var8, -1, sizeof(var8));
    }
    return 0;
}
