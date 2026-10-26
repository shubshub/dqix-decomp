#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct Struct_0208a03c;
struct Struct_0208a03c_3 {
    struct Struct_0208a03c* battle;
};

struct Struct_0208a03c_4 {
    char pad0[0x10];
    unsigned int unknown_10_0_ : 20;
    unsigned int unknown_12_4_ : 6;
    unsigned int unknown_13_2_ : 6;
    char unknown_14_[4];
    unsigned short unknown_18_[6];
};

struct Struct_0208a03c_5 {
    char pad0[2];
    unsigned short count;
    char pad4[0x10];
    unsigned int blocked;
    char pad18[0x24];
    unsigned char lo : 3;
    unsigned char flagA : 1;
    unsigned char unknown_3c_4_ : 1;
    unsigned char flagC : 1;
};

struct Struct_0208a03c_6 {
    char pad0[2];
    short unknown_2_;
    char pad4[0x134];
    struct Struct_0208a03c_5* unknown_138_;
    char unknown_13c_[0xc];
    struct Struct_0208a03c_4* unknown_148_;
    char unknown_14c_[0x30];
    unsigned char slot;
};

struct Struct_0208a03c_7 {
    char pad0[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int pad8 : 24;
    char unknown_c_[4];
    unsigned int flags;
    char unknown_14_[4];
    unsigned int unknown_18_0_ : 5;
    unsigned int effect : 7;
    unsigned int unknown_19_4_ : 20;
};

struct Struct_0208a03c_2 {
    char pad[0x25];
    unsigned char f25;
};

struct Struct_0208a03c {
    char pad0[0x8e18];
    struct Struct_0208a03c_2* party;
    char unknown_8e1c_[4];
    int unknown_8e20_;
    char unknown_8e24_[0x25];
    unsigned char mode;
};

extern "C" struct Struct_0208a03c_6* func_0200fea4(GameState*, int);
extern "C" void* func_020797dc(void);
extern "C" int GameState_IsInGrotto(GameState*);
extern "C" char* Zone3D_GetInstance(void);
extern "C" struct Struct_0208a03c_7* func_02079e2c(char* table, int key);
extern "C" int func_ov000_02159d94(void* unused, int id);
extern "C" void func_ov024_021f66c0(int* p);
extern "C" int func_ov024_021f66cc(int* obj, struct Struct_0208a03c* battle, int arg2, int id, int* out, int arg);

#if defined(jpn)
enum { regionalOffset = 0x240c };
#else
enum { regionalOffset = 0x23ec };
#endif

// USA: func_0208a03c
extern "C" ARM int func_0208a03c(Struct_0208a03c_3* ctx, unsigned char index, unsigned short id, int* out, int arg) {
    GameState* gs = GameState::GetInstance();
    struct Struct_0208a03c_6* c = func_0200fea4(gs, id);
    char* table = (char*)func_020797dc();
    struct Struct_0208a03c_4* set = c->unknown_148_;
    if (ctx->battle->mode == 2 && ctx->battle->unknown_8e20_ == 0 && c->unknown_148_->unknown_18_[index] == 0xe1) {
        return 0;
    }
    unsigned int var4 = set->unknown_12_4_;
    unsigned char* used = (unsigned char*)ctx->battle + 0x81bf + (short)c->slot * 0x18;
    if (var4 & (1 << index)) {
        if (*used & (1 << index)) {
            return 0;
        }
    }
    char* zone = Zone3D_GetInstance();
    if (GameState_IsInGrotto(gs) && ctx->battle->party->f25 != 0) {
        char* detail = (char*)((ActiveGrottoClass*)(zone + regionalOffset))->GetDetailedData();
        short var8 = c->unknown_2_;
        unsigned short var9 = ((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->MaybeGetCurrentAlternateID();
        if (var9 == var8) {
            if (!((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->CanUseLevelUpMove(set->unknown_18_[index])) {
                return 0;
            }
        }
    }
    struct Struct_0208a03c_7* move = func_02079e2c(table, (short)set->unknown_18_[index]);
    int var11 = 0;
    int kind = func_ov000_02159d94(ctx->battle, (short)id);
    int var13;
    unsigned int flags = move->flags;
    if (flags & 1) {
        var13 = 0;
        if (kind == 2) {
            var13 = 1;
        } else if (kind == 1) {
            if (c->unknown_138_->flagA) {
                var13 = 1;
            }
        }
        if (var13) {
            struct Struct_0208a03c_5* var15 = c->unknown_138_;
            if (var15->blocked & 0x100) {
                return 0;
            }
            unsigned int count = var15->count;
            if (count == 0) {
                if (move->unknown_8_0_ != 0) {
                    return 0;
                }
            }
            if (move->unknown_8_0_ < 0xff && count < move->unknown_8_0_) {
                return 0;
            }
        }
        var11 = 1;
    }
    if (flags & 2) {
        int var17 = 0;
        if (kind == 2) {
            var17 = 1;
        } else if (kind == 1) {
            if (c->unknown_138_->unknown_3c_4_) {
                var17 = 1;
            }
        }
        if (var17) {
            struct Struct_0208a03c_5* var18 = c->unknown_138_;
            unsigned int count = var18->count;
            if (count == 0) {
                if (move->unknown_8_0_ != 0) {
                    return 0;
                }
            }
            if (move->unknown_8_0_ < 0xff && count < move->unknown_8_0_) {
                return 0;
            }
        }
        var11 = 1;
    }
    if (!var11) {
        int var20 = 0;
        if (kind == 2) {
            var20 = 1;
        } else if (kind == 1) {
            if (c->unknown_138_->flagC) {
                var20 = 1;
            }
        }
        if (var20) {
            struct Struct_0208a03c_5* var21 = c->unknown_138_;
            unsigned int count = var21->count;
            if (count == 0) {
                if (move->unknown_8_0_ != 0) {
                    return 0;
                }
            }
            if (move->unknown_8_0_ < 0xff && count < move->unknown_8_0_) {
                return 0;
            }
        }
    }
    int handler;
    func_ov024_021f66c0(&handler);
    if (!func_ov024_021f66cc(&handler, ctx->battle, set->unknown_18_[index], id, out, arg)) {
        return 0;
    }
    if (move->effect != 0x22) {
        *used |= 1 << index;
    } else {
        *used = 0;
    }
    return 1;
}
