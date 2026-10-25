#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_02053c6c(unsigned char* arg0);
struct Struct_02052e2c;
extern "C" short* func_02052e2c(Struct_02052e2c* arg0);
struct Struct_02015ef4_4 {
    int unknown_0_, unknown_4_, unknown_8_, unknown_c_;
    unsigned int unknown_10_0_ : 10;
    unsigned int unknown_11_2_ : 10;
    unsigned int unknown_12_4_ : 8;
    unsigned int unknown_13_4_ : 4;
    short unknown_14_, unknown_16_, unknown_18_, unknown_1a_, unknown_1c_;
};
unsigned short ItemRecord_GetFileNumber(StructDE234_020de234* p, int preferMid);
struct EffectTable02072e94 {
    short values[10];
    unsigned char preferred : 1;
    unsigned char otherFlags : 7;
    unsigned char adjustment : 4;
    unsigned char otherAdjustment : 4;
};
struct Struct_020e8834 { char unknown_0_[8]; };
struct Struct_020e883c { char unknown_0_[10]; };
extern Struct_020e8834 data_020e8834;
extern Struct_020e883c data_020e883c;
extern char data_020f0d04[];
extern char data_020f0d0a[];

// USA: func_02072e94
extern "C" ARM int func_02072e94(char* out, int combatantId, int kind,
                                StructDE234_020de234* entry, void* optional) {
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), combatantId);
    unsigned char* fields = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    EffectTable02072e94* table = (EffectTable02072e94*)GetField150Ptr0x488_02052e2c((Field150Holder02052e2c*)combatant);
    int preferred = table->preferred;
    int value = ItemRecord_GetFileNumber(entry, table->preferred);
    StructDE234_020de234* alternate = NULL;
    StructDE234_020de234* primary = NULL;
    if (optional != NULL) {
        primary = (StructDE234_020de234*)optional;
        alternate = (StructDE234_020de234*)((char*)optional + 0xe0);
    }
    Struct_020e8834 var7 = data_020e8834;
    char var8[2] = {};
    char var9[2] = {};
    if (arg2 == 4) {
        strcpy(var7.unknown_0_, data_020f0d04);
        var8[0] = 'a';
        var8[1] = 0;
        var4 += var2->unknown_15_0_;
    }
    int alternateValue = -1;
    if (alternate != NULL && alternate->g > -1) {
        alternateValue = ItemRecord_GetFileNumber(alternate, preferred);
    }
    if (arg2 == 3) {
        var8[0] = 'a';
        var8[1] = 0;
        if (var10 >= 0) {
            unsigned int var11 = var10 / 100;
            if (var11 < 10) {
                Struct_020e883c var12 = data_020e883c;
                char var13 = var12.unknown_0_[var11];
                if (var13 == 0) return 0;
                var8[0] = var13;
                if (var11 == 3 && var3 == 0 && var2->unknown_0_[3] == 9001) {
                    var8[0] = 'f';
                }
            } else {
                return 0;
            }
        }
    }
    if (kind == 5 && primary != NULL) {
        if (table->values[4] == 8010 || table->values[4] < 0) {
            value = ItemRecord_GetFileNumber(primary, preferred);
        }
        strcpy(var7.unknown_0_, data_020f0d04);
    }
    if (arg2 == 6) strcpy(var7.unknown_0_, data_020f0d04);
    if (arg3->unknown_18_ == 1000) var4 += var1[0x56a];
    sprintf(arg0, data_020f0d0a, (char)arg3->unknown_12_4_, var4, var8, var9, var7.unknown_0_);
    return 1;
}
