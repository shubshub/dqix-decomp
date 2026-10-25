#pragma once

// One character of a font (8 bytes): its text and glyph width. Font_FindCharacter compares byteLength_ bytes of text_;
// lowercase_ is set on the lowercase letters, whose text CharacterCreationUI_CheckName uppercases.
struct FontCharacter {
    char* text_;
    signed char width_;
    signed char byteLength_ : 6;
    signed char unknownBit6_ : 1;
    signed char lowercase_ : 1;
    char pad6[2];
};

// A font's character table: characterCount_ FontCharacters at characters_.
struct FontCharacterTable {
    int unk_0;
    unsigned int characterCount_;
    char unk_8[8];
    FontCharacter* characters_;
};

// Each font's character table, by font id ([1] is data/pack_lv5/fi_me.bin). usa/eur only.
extern FontCharacterTable* Font_characterTables[];
