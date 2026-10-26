#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

extern "C" int func_02053c6c(unsigned char* obj);
struct Field150Holder02052e2c;
extern "C" short* func_02052e2c(Field150Holder02052e2c* obj);
struct StructDE234_020de234 {
    int a, b, c, d;
    unsigned int unknown_10_0_ : 10;
    unsigned int unknown_11_2_ : 10;
    unsigned int field10High : 8;
    unsigned int unknown_13_4_ : 4;
    short e, f, g, h, i;
};
extern "C" unsigned short ItemRecord_GetFileNumber(StructDE234_020de234* p, int preferMid);
struct Struct_02072e94 {
    short values[10];
    unsigned char preferred : 1;
    unsigned char unknown_14_1_ : 7;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
};
struct Struct_020e8834 { char text[8]; };
struct Struct_020e883c { char text[10]; };
extern Struct_020e8834 data_020e8834;
extern Struct_020e883c data_020e883c;
extern char data_020f0d04[];
extern char data_020f0d0a[];

// USA: func_02072e94
extern "C" ARM int func_02072e94(char* out, int combatantId, int kind,
                                StructDE234_020de234* entry, void* arg4) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    unsigned char* fields = (unsigned char*)func_02053c6c((unsigned char*)combatant);
    Struct_02072e94* table = (Struct_02072e94*)func_02052e2c((Field150Holder02052e2c*)combatant);
    int preferred = table->preferred;
    int value = ItemRecord_GetFileNumber(entry, table->preferred);
    StructDE234_020de234* alternate = NULL;
    StructDE234_020de234* primary = NULL;
    if (arg4 != NULL) {
        primary = (StructDE234_020de234*)arg4;
        alternate = (StructDE234_020de234*)((char*)arg4 + 0xe0);
    }
    Struct_020e8834 suffix = data_020e8834;
    char letter[2] = {};
    char extra[2] = {};
    if (kind == 4) {
        strcpy(suffix.text, data_020f0d04);
        letter[0] = 'a';
        letter[1] = 0;
        value += table->unknown_15_0_;
    }
    int alternateValue = -1;
    if (alternate != NULL && alternate->g > -1) {
        alternateValue = ItemRecord_GetFileNumber(alternate, preferred);
    }
    if (kind == 3) {
        letter[0] = 'a';
        letter[1] = 0;
        if (alternateValue >= 0) {
            unsigned int category = alternateValue / 100;
            if (category < 10) {
                Struct_020e883c letters = data_020e883c;
                char c = letters.text[category];
                if (c == 0) return 0;
                letter[0] = c;
                if (category == 3 && preferred == 0 && table->values[3] == 9001) {
                    letter[0] = 'f';
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
        strcpy(suffix.text, data_020f0d04);
    }
    if (kind == 6) strcpy(suffix.text, data_020f0d04);
    if (entry->g == 1000) value += fields[0x56a];
    sprintf(out, data_020f0d0a, (char)entry->field10High, value, letter, extra, suffix.text);
    return 1;
}
