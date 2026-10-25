#include <globaldefs.h>
#include "Resource/Font.h"

// Main, originally GetBoundedEntry020425b4 (USA 0x020425b4, EUR 0x020425c4; JPN not identified)
ARM void* Font_GetCharacter(int index, int font) {
    FontCharacterTable* table = Font_characterTables[font];
    if (index >= 0 && (unsigned int)index < table->characterCount_)
        return &table->characters_[index];
    return NULL;
}
