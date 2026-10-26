#include <globaldefs.h>
#include "Resource/Font.h"
extern "C" int memcmp(const void* a, const void* b, unsigned int length); // memcmp

// Main, originally FindEntryIndexByKey020424e4 (USA 0x020424e4, EUR 0x020424f4; JPN not identified)
extern "C" ARM int Font_FindCharacterIndex(int text, int font) {
    FontCharacterTable* table;
    unsigned int i;
    if (text == 0) {
        return -1;
    }
    table = Font_characterTables[font];
    for (i = 0; i < table->characterCount_; i++) {
        FontCharacter* character = &table->characters_[i];
        if (memcmp(character->text_, (const void*)text, character->byteLength_) == 0) {
            return i;
        }
    }
    return -1;
}
