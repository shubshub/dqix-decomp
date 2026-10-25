#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02171c04 {
    unsigned char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
    unsigned char unknown_c_[0xc];
    short unknown_18_;
    unsigned char unknown_1a_[6];
};
struct Struct_ov000_02171c04_2 {
    unsigned char unknown_0_[0x194];
    Struct_ov000_02171c04 unknown_194_[8];
};
struct ItemTable;
struct BattleEquipmentList {
    ItemTable* inventory;
    unsigned char unknown04[0x4c - 0x4];
    int partyIndex;
};

BattleEquipmentEntry* ItemTable_Find(ItemTable* c, int key);
extern "C" unsigned char data_ov000_02183388[8];

// USA: func_ov000_02171d90
extern "C" ARM Struct_ov000_02171c04* func_ov000_02171d90(Struct_ov000_02171c04_3* arg0, int arg1) {
    if (arg1 < 0) {
        return NULL;
    }
    char* var0 = (char*)func_0200ff1c(GameState::GetInstance(), arg0->unknown_4c_);
    if (var0) {
        unsigned char var1[8];
        unsigned int var2 = sizeof(var1);
        unsigned char* var3 = var1;
        const unsigned char* var4 = data_ov000_02183388;
        do {
            unsigned char var5 = *var4;
            *var3 = var5;
            ++var4;
            ++var3;
        } while (--var2);
        for (unsigned char var6 = 0; var6 < 8; ++var6) {
#if defined(jpn)
            Struct_ov000_02171c04_2* var7 = *reinterpret_cast<Struct_ov000_02171c04_2**>(var0 + 0x144);
#else
            Struct_ov000_02171c04_2* var7 = *reinterpret_cast<Struct_ov000_02171c04_2**>(var0 + 0x150);
#endif
            Struct_ov000_02171c04* var8 = &var7->unknown_194_[var1[var6]];
            if (var8 && var8->unknown_18_ > 0) {
                int var9 = var8->unknown_8_0_ <= 7;
                if (var9 && var8->unknown_18_ == arg1) {
                    return var8;
                }
            }
        }
    }
    return ItemTable_Find(list->inventory, itemId);
}
