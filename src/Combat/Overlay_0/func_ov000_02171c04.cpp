#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02171c04_134 = 0xc6, Enum_ov000_02171c04_135 = 0xc7, Enum_ov000_02171c04_1008 = 0x430, Enum_ov000_02171c04_336 = 0x144 };
#else
enum { Enum_ov000_02171c04_134 = 0x86, Enum_ov000_02171c04_135 = 0x87, Enum_ov000_02171c04_1008 = 0x3f0, Enum_ov000_02171c04_336 = 0x150 };
#endif

#include <GameState/GameState.h>

struct BattleEquipmentEntry {
    unsigned char unknown_0_[8];
    unsigned int category : 4;
    unsigned int unknown_8_4_ : 28;
    unsigned char unknown_c_[0xc];
    short count;
    unsigned char unknown_1a_[6];
};
struct Struct_ov000_02171c04_2 {
    unsigned char unknown_0_[0x194];
    BattleEquipmentEntry entries[8];
};
struct Struct_ov000_02171c04_3 {
    unsigned char unknown_0_[0x4c];
    int partyIndex;
    unsigned char unknown50[Enum_ov000_02171c04_134 - 0x50];
    signed char unknown_86_;
    unsigned char unknown_87_[Enum_ov000_02171c04_1008 - Enum_ov000_02171c04_135];
    BattleEquipmentEntry* entries[16];
};
extern "C" {
    void* func_02053c6c(void*);
    extern unsigned char data_ov000_02183380[8];
    void func_ov000_02171b68(Struct_ov000_02171c04_3*, int, BattleEquipmentEntry*);
}

// USA: func_ov000_02171c04
extern "C" ARM void func_ov000_02171c04(Struct_ov000_02171c04_3* list)
{
    signed char partyIndex = list->partyIndex;
    int var1 = partyIndex >= 0 && partyIndex <= 3;
    if (var1) {
        char* actor = (char*)func_0200ff1c(GameState::GetInstance(), partyIndex);
        if (actor && func_02053c6c(actor)) {
            list->unknown_86_ = 0;
            for (signed char slot = 0; slot < 16; ++slot) {
                BattleEquipmentEntry* entry = list->entries[slot];
                if (!entry)
                    break;
                int var5 = entry->category <= 7;
                if (var5)
                    break;
                ++list->unknown_86_;
            }
            unsigned char var6 = (list->unknown_86_ + 3) & ~3;
            for (unsigned char slot = var6; slot < 16; ++slot)
                list->entries[slot] = NULL;
            unsigned char var8[8];
            unsigned int bytes = sizeof(var8);
            unsigned char* output = var8;
            const unsigned char* input = data_ov000_02183380;
            do {
                unsigned char value = *input;
                *output = value;
                ++input;
                ++output;
            } while (--bytes);
            for (unsigned char slot = 0; slot < 8; ++slot) {
                Struct_ov000_02171c04_2* equipment = *reinterpret_cast<Struct_ov000_02171c04_2**>(actor + Enum_ov000_02171c04_336);
                BattleEquipmentEntry* entry = &equipment->entries[var8[slot]];
                if (entry && entry->count > 0) {
                    int var16 = entry->category <= 7;
                    if (var16) {
                        func_ov000_02171b68(list, var6, entry);
                        ++var6;
                    }
                }
            }
        }
    }
}
