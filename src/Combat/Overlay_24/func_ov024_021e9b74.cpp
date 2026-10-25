#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02010088;
struct Random;
struct Struct_02048150;

struct Struct_02000c9c_77 {
    char unknown_0_[0x21];
    unsigned char unknown_21_;
    char unknown_22_[0x2a - 0x22];
    short unknown_2a_;
};

struct Struct_ov024_021e9b74 {
    char unknown_0_[0x138];
    struct Struct_02000c9c_77* unknown_138_;
};

struct Struct_ov024_021e9b74_2 {
    char unknown_0_[0xc];
    void* unknown_c_;
    int unknown_10_;
    char unknown_14_[0x79 - 0x14];
    unsigned char unknown_79_;
};

struct Struct_ov024_021e9b74_3 {
    short unknown_0_;
};

struct Struct_ov024_021e9b74_4 {
    char unknown_0_[0x10];
    unsigned int unknown_10_;
};

struct Struct_ov024_021fe6f8 {
    short unknown_0_[8];
};

struct Struct_ov024_021fe7e0 {
    int unknown_0_[8];
};

extern const struct Struct_ov024_021fe6f8 data_ov024_021fe6f8;
extern const struct Struct_ov024_021fe7e0 data_ov024_021fe7e0;

struct Struct_ov024_021e9b74* GetCombatantByID(int unused, int id);
extern "C" int func_02010088(struct Struct_02010088* arg0);
extern "C" int func_ov024_021e6798(GameObject* arg0);
extern "C" int func_ov000_0215e9fc(int arg0, short* arg1, int arg2, int arg3);
extern "C" int func_ov000_0215eb1c(int arg0, short* arg1, int arg2, int arg3);
extern "C" int func_ov000_02155f9c(int arg0, int arg1, int arg2);
int NextRandomMax(struct Random* random, int maximum);
void PushEntry0215ff20(void* obj, short val1, unsigned char val2);
extern "C" float func_ov024_021db358(struct Cbt_021e9b74* obj);
void* GameState_GetParty(GameState* gameState);
int ArrayContainsByte_02086ef0(struct ArrayContainsByteStruct* s, int val);
void IncrementByteCounterCapped0x63_0215a8d4(unsigned char* obj, int idx);

static inline short inline_ov024_021e9b74(struct Struct_ov024_021e9b74* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_138_->unknown_2a_; }

static inline int inline_ov024_021e9b74_2(struct Struct_ov024_021e9b74* arg0, int arg1) {
    return arg0->unknown_138_->unknown_21_ == arg1;
}

// USA: func_ov024_021e9b74
extern "C" ARM int func_ov024_021e9b74(struct Struct_ov024_021e9b74_2* arg0, int arg1, struct Struct_ov024_021e9b74_3* arg2,
                                       struct Struct_ov024_021e9b74_4* arg3) {
    void* var0;
    int var1;
    int var2;
    struct Random* var3;
    if (arg0->unknown_c_ == 0) {
        return 0;
    }
    struct Struct_ov024_021e9b74* var4 = GetCombatantByID(arg0->unknown_10_, arg2->unknown_0_);
    if (!var4) {
        return 0;
    }
    if (func_02010088((struct Struct_02010088*)var4) || func_ov024_021e6798((GameObject*)var4)) {
        return 0;
    }
    GameState::GetInstance();
    var3 = (struct Random*)arg0->unknown_10_;
    var0 = arg0->unknown_c_;
    if (arg3->unknown_10_ & 0x1000) {
        struct Struct_ov024_021fe6f8 var5 = data_ov024_021fe6f8;
        int var6 = arg2->unknown_0_ >= 0 && arg2->unknown_0_ <= 3;
        int var7;
        if (var6) {
            var7 = func_ov000_0215e9fc(arg0->unknown_10_, var5.unknown_0_, 8, 1);
        } else {
            var7 = func_ov000_0215eb1c(arg0->unknown_10_, var5.unknown_0_, 8, 1);
        }
        struct Struct_ov024_021fe7e0 var8 = data_ov024_021fe7e0;
        var1 = 0;
        for (var2 = 0; var2 < var7; var2++) {
            struct Struct_ov024_021e9b74* var9 = GetCombatantByID(arg0->unknown_10_, var5.unknown_0_[var2]);
            if (var9 && arg2->unknown_0_ != var5.unknown_0_[var2] && !func_ov000_02155f9c(arg0->unknown_10_, var5.unknown_0_[var2], 0) &&
                inline_ov024_021e9b74_2(var9, 8)) {
                var8.unknown_0_[var1++] = var5.unknown_0_[var2];
            }
        }
        if (var1 > 0) {
            arg2->unknown_0_ = var8.unknown_0_[NextRandomMax(var3, var1)];
            func_ov000_0215ff20(var0, arg2->unknown_0_, 6);
            arg0->unknown_79_ = 1;
            return 1;
        }
        var1 = 0;
        memset(&var8, -1, sizeof(var8));
        if (func_ov024_021db358(var4) <= 0.08f) {
            for (var2 = 0; var2 < var7; var2++) {
                struct Struct_ov024_021e9b74* var10 = GetCombatantByID(arg0->unknown_10_, var5.unknown_0_[var2]);
                if (var10 && arg2->unknown_0_ != var5.unknown_0_[var2] && !func_ov000_02155f9c(arg0->unknown_10_, var5.unknown_0_[var2], 0) &&
                    inline_ov024_021e9b74_2(var10, 7)) {
                    var8.unknown_0_[var1++] = var5.unknown_0_[var2];
                }
            }
            if (var1 > 0) {
                arg2->unknown_0_ = var8.unknown_0_[NextRandomMax(var3, var1)];
                func_ov000_0215ff20(var0, arg2->unknown_0_, 7);
                arg0->unknown_79_ = 1;
                return 1;
            }
        }
        var1 = 0;
        memset(&var8, -1, sizeof(var8));
        for (var2 = 0; var2 < var7; var2++) {
            struct Struct_ov024_021e9b74* var11 = GetCombatantByID(arg0->unknown_10_, var5.unknown_0_[var2]);
            if (var11 && !func_ov000_02155f9c(arg0->unknown_10_, var5.unknown_0_[var2], 0) && inline_ov024_021e9b74_2(var11, 6) &&
                arg2->unknown_0_ == inline_ov024_021e9b74(var11)) {
                var8.unknown_0_[var1++] = var5.unknown_0_[var2];
            }
        }
        if (n > 0) {
            cmd->targetId = cands.v[NextRandomMax(rnd, n)];
            PushEntry0215ff20(queue, cmd->targetId, 8);
            ctx->redirected = 1;
            if (ArrayContainsByte_02086ef0((struct ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance()),
                                  cmd->targetId)) {
                IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)ctx->battle, 4);
            }
            return 1;
        }
        memset(&var8, -1, sizeof(var8));
    }
    return 0;
}
