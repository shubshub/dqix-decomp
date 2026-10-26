#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct Struct_0208a03c;
struct Struct_0208a03c_3 {
    struct Struct_0208a03c* unknown_0_;
};

struct Struct_0208a03c_4 {
    char unknown_0_[0x10];
    unsigned int unknown_10_0_ : 20;
    unsigned int unknown_12_4_ : 6;
    unsigned int unknown_13_2_ : 6;
    char unknown_14_[4];
    unsigned short unknown_18_[6];
};

struct Struct_0208a03c_5 {
    char unknown_0_[2];
    unsigned short unknown_2_;
    char unknown_4_[0x10];
    unsigned int unknown_14_;
    char unknown_18_[0x24];
    unsigned char unknown_3c_0_ : 3;
    unsigned char unknown_3c_3_ : 1;
    unsigned char unknown_3c_4_ : 1;
    unsigned char unknown_3c_5_ : 1;
};

struct Struct_0208a03c_6 {
    char unknown_0_[2];
    short unknown_2_;
    char unknown_4_[0x134];
    struct Struct_0208a03c_5* unknown_138_;
    char unknown_13c_[0xc];
    struct Struct_0208a03c_4* unknown_148_;
    char unknown_14c_[0x30];
    unsigned char unknown_17c_;
};

struct Struct_0208a03c_7 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 24;
    char unknown_c_[4];
    unsigned int unknown_10_;
    char unknown_14_[4];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
};

struct Struct_0208a03c_2 {
    char unknown_0_[0x25];
    unsigned char unknown_25_;
};

struct Struct_0208a03c {
    char unknown_0_[0x8e18];
    struct Struct_0208a03c_2* unknown_8e18_;
    char unknown_8e1c_[4];
    int unknown_8e20_;
    char unknown_8e24_[0x25];
    unsigned char unknown_8e49_;
};

struct Combatant0208a03c* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
void* GetData02108e10_020797dc(void);
int GameState_IsInGrotto(GameState*);
extern "C" char* Zone3D_GetInstance(void);
struct Move0208a03c* SearchBothTables02079e2c(char* table, int key);
int GetCombatantField0x148Bits3To4_ov000_02159d94(void* unused, int id);
void ClearFirstField_021f66c0(int* p);
extern "C" int func_ov024_021f66cc(int* obj, struct Battle0208a03c* battle, int moveId, int id, int* out, int arg);

#if defined(jpn)
enum { Enum_0208a03c_9196 = 0x240c };
#else
enum { Enum_0208a03c_9196 = 0x23ec };
#endif

// USA: func_0208a03c
extern "C" ARM int func_0208a03c(Struct_0208a03c_3* arg0, unsigned char arg1, unsigned short arg2, int* arg3, int arg4) {
    GameState* var0 = GameState::GetInstance();
    struct Struct_0208a03c_6* var1 = func_0200fea4(var0, arg2);
    char* var2 = (char*)func_020797dc();
    struct Struct_0208a03c_4* var3 = var1->unknown_148_;
    if (arg0->unknown_0_->unknown_8e49_ == 2 && arg0->unknown_0_->unknown_8e20_ == 0 && var1->unknown_148_->unknown_18_[arg1] == 0xe1) {
        return 0;
    }
    unsigned int var4 = var3->unknown_12_4_;
    unsigned char* var5 = (unsigned char*)arg0->unknown_0_ + 0x81bf + (short)var1->unknown_17c_ * 0x18;
    if (var4 & (1 << arg1)) {
        if (*var5 & (1 << arg1)) {
            return 0;
        }
    }
    char* zone = Zone3D_GetInstance();
    if (GameState_IsInGrotto(gs) && ctx->battle->party->f25 != 0) {
        char* detail = (char*)((ActiveGrottoClass*)(zone + regionalOffset))->GetDetailedData();
        short kindId = c->kindId;
        unsigned short alt = ((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->MaybeGetCurrentAlternateID();
        if (alt == kindId) {
            if (!((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->CanUseLevelUpMove(set->moves[index])) {
                return 0;
            }
        }
    }
    struct Struct_0208a03c_7* var10 = func_02079e2c(var2, (short)var3->unknown_18_[arg1]);
    int var11 = 0;
    int var12 = func_ov000_02159d94(arg0->unknown_0_, (short)arg2);
    int var13;
    unsigned int var14 = var10->unknown_10_;
    if (var14 & 1) {
        var13 = 0;
        if (var12 == 2) {
            var13 = 1;
        } else if (var12 == 1) {
            if (var1->unknown_138_->unknown_3c_3_) {
                var13 = 1;
            }
        }
        if (var13) {
            struct Struct_0208a03c_5* var15 = var1->unknown_138_;
            if (var15->unknown_14_ & 0x100) {
                return 0;
            }
            unsigned int var16 = var15->unknown_2_;
            if (var16 == 0) {
                if (var10->unknown_8_0_ != 0) {
                    return 0;
                }
            }
            if (var10->unknown_8_0_ < 0xff && var16 < var10->unknown_8_0_) {
                return 0;
            }
        }
        var11 = 1;
    }
    if (var14 & 2) {
        int var17 = 0;
        if (var12 == 2) {
            var17 = 1;
        } else if (var12 == 1) {
            if (var1->unknown_138_->unknown_3c_4_) {
                var17 = 1;
            }
        }
        if (var17) {
            struct Struct_0208a03c_5* var18 = var1->unknown_138_;
            unsigned int var19 = var18->unknown_2_;
            if (var19 == 0) {
                if (var10->unknown_8_0_ != 0) {
                    return 0;
                }
            }
            if (var10->unknown_8_0_ < 0xff && var19 < var10->unknown_8_0_) {
                return 0;
            }
        }
        var11 = 1;
    }
    if (!var11) {
        int var20 = 0;
        if (var12 == 2) {
            var20 = 1;
        } else if (var12 == 1) {
            if (var1->unknown_138_->unknown_3c_5_) {
                var20 = 1;
            }
        }
        if (var20) {
            struct Struct_0208a03c_5* var21 = var1->unknown_138_;
            unsigned int var22 = var21->unknown_2_;
            if (var22 == 0) {
                if (var10->unknown_8_0_ != 0) {
                    return 0;
                }
            }
            if (var10->unknown_8_0_ < 0xff && var22 < var10->unknown_8_0_) {
                return 0;
            }
        }
    }
    int var23;
    func_ov024_021f66c0(&var23);
    if (!func_ov024_021f66cc(&var23, arg0->unknown_0_, var3->unknown_18_[arg1], arg2, arg3, arg4)) {
        return 0;
    }
    if (var10->unknown_18_5_ != 0x22) {
        *var5 |= 1 << arg1;
    } else {
        *var5 = 0;
    }
    return 1;
}
