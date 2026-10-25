#include <globaldefs.h>
#include "Resource/Font.h"
extern "C" int memcmp(const void* a, const void* b, unsigned int length); // memcmp

// Main, originally FindEntryByKey0204254c (USA 0x0204254c, EUR 0x0204255c; JPN not identified)
ARM struct FontCharacter* Font_FindCharacter(int text, int font) {
    FontCharacterTable* table;
    unsigned int i;
    if (text == 0) {
        return NULL;
    }
    table = Font_characterTables[font];
    for (i = 0; i < table->characterCount_; i++) {
        struct FontCharacter* character = &table->characters_[i];
        if (memcmp(character->text_, (const void*)text, character->byteLength_) == 0) {
            return character;
        }
    }
    return NULL;
}
