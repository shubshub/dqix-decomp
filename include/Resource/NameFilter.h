#pragma once

// The name checker CharacterCreationUI_CheckName runs on a typed name (CharacterCreationUI::nameFilter), and the
// forbidden-word file (data/bin/tv.nat) it matches against.

// Where in a word of the name a pattern's word must sit. 4-7 are the same four with the word as a
// NameFilter_MatchPattern pattern instead of plain text.
enum ForbiddenWordMatch {
    ForbiddenWordMatch_Whole = 0,
    ForbiddenWordMatch_Contains = 1,
    ForbiddenWordMatch_Suffix = 2,
    ForbiddenWordMatch_Prefix = 3,
    ForbiddenWordMatch_PatternWhole = 4,
    ForbiddenWordMatch_PatternContains = 5,
    ForbiddenWordMatch_PatternSuffix = 6,
    ForbiddenWordMatch_PatternPrefix = 7,
};

enum ForbiddenWord {
    ForbiddenWord_MaxWords = 5,
};

// One entry of tv.nat: up to 5 words that must follow each other in the name, each with its own match type. In the
// file each word is an offset into the texts; ForbiddenWordFile_RelocatePattern turns them into pointers.
struct ForbiddenWordPattern {
    char* words_[ForbiddenWord_MaxWords];
    signed char lengths_[ForbiddenWord_MaxWords];        // in tokens; for a pattern, the fewest it matches
    unsigned char matchTypes_[ForbiddenWord_MaxWords];   // ForbiddenWordMatch
    unsigned char count_;
    char pad1f;
};

struct ForbiddenWordHeader {
    unsigned int count_ : 12;
    unsigned int textSize_ : 19;
    unsigned int relocated_ : 1;
};

struct ForbiddenWordFile {
    ForbiddenWordHeader header_;
    ForbiddenWordPattern* patterns_;
    char* texts_;
};

struct NameFilter {
#if defined(jpn)
    unsigned char patterns[0xc];        // jpn's checker is a different one, not worked out
#else
    unsigned char reservedNames[0x18];  // the key table of res.nat (CharacterCreationUI_CheckName's Struct020dfc40)
    ForbiddenWordFile patterns;         // tv.nat
#endif
    void* reservedNamesData;
    unsigned short reservedNamesSize;
#if defined(jpn)
    unsigned short field12;             // CharacterCreationUI_HandleSetup sets it to 1 after NameFilter_Reset
    int tasks[2];                       // set to -1 by NameFilter_Reset
    void* allocator;                    // CharacterCreationUI_HandleSetup: &allocators[CreationAllocator_NameFilter]
#else
    // The font-1 indexes of NameFilter_syntaxCharacters, in that order (NameFilter_Reset looks them up).
    unsigned char letterClassId, groupStartId, groupEndId, repeatStartId, repeatEndId, negateId, rangeId, wildcardId;
    unsigned char dollarId, slashId, atId, ampersandId, commaId, cSlashId, apostropheId;
    unsigned char pad39[3];
    inline ForbiddenWordFile* GetPatterns() { return &patterns; }
#endif
};
