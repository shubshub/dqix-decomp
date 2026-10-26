#include <globaldefs.h>
#include "GameState/GameState.h"

struct BattleEquipmentEntry {
    unsigned char unknown_0_[8];
    unsigned int category : 4;
    unsigned int unknown_8_4_ : 28;
    unsigned char unknown_c_[0xc];
    short itemId;
    unsigned char unknown_1a_[6];
};
struct Struct_ov000_02171c04_2 {
    unsigned char unknown_0_[0x194];
    BattleEquipmentEntry entries[8];
};
struct ItemTable;
struct Struct_ov000_02171c04_3 {
    ItemTable* inventory;
    unsigned char unknown_4_[0x4c - 0x4];
    int partyIndex;
};

extern "C" BattleEquipmentEntry* ItemTable_Find(ItemTable* c, int key);
extern "C" unsigned char data_ov000_02183388[8];

// USA: func_ov000_02171d90
extern "C" ARM BattleEquipmentEntry* func_ov000_02171d90(Struct_ov000_02171c04_3* list, int itemId) {
    if (itemId < 0) {
        return NULL;
    }
    char* actor = (char*)func_0200ff1c(GameState::GetInstance(), list->partyIndex);
    if (actor) {
        unsigned char var1[8];
        unsigned int bytes = sizeof(var1);
        unsigned char* output = var1;
        const unsigned char* input = data_ov000_02183388;
        do {
            unsigned char value = *input;
            *output = value;
            ++input;
            ++output;
        } while (--bytes);
        for (unsigned char slot = 0; slot < 8; ++slot) {
#if defined(jpn)
            Struct_ov000_02171c04_2* equipment = *reinterpret_cast<Struct_ov000_02171c04_2**>(actor + 0x144);
#else
            Struct_ov000_02171c04_2* equipment = *reinterpret_cast<Struct_ov000_02171c04_2**>(actor + 0x150);
#endif
            BattleEquipmentEntry* entry = &equipment->entries[var1[slot]];
            if (entry && entry->itemId > 0) {
                int var9 = entry->category <= 7;
                if (var9 && entry->itemId == itemId) {
                    return entry;
                }
            }
        }
    }
    return ItemTable_Find(list->inventory, itemId);
}
