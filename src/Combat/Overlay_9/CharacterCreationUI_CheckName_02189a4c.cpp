#include "Resource/CreationEnums.h"
#include <globaldefs.h>
#include "Resource/Font.h"
#include <std_library_functions.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/NameFilter.h"

extern "C" int ForbiddenWordFile_RelocatePattern(ForbiddenWordFile*, ForbiddenWordPattern*);

// The font every lookup here uses: data/pack_lv5/fi_me.bin (func_02042944 loads "me" second).
enum FontId {
    FontId_Me = 1,
};

// Indexes of the "me" font's characters that the name filter treats specially.
enum MeFont {
    MeFont_Zero = 8,            // '0'-'9' are 8-17, 'A'-'Z' 18-43, 'a'-'z' 44-69
    MeFont_LowerZ = 69,
    MeFont_UpperOE = 77,        // <OE>
    MeFont_LowerOE = 83,        // <oe>
    MeFont_SlashTag = 107,      // </>
    MeFont_FirstAccented = 120, // <`A> ... <:u>, with <AE>, <,C>, <x>, <ss>, <ae>, <,c> among them. A tag whose
    MeFont_LastAccented = 169,  // second character is a letter stays whole (<AE>, <x>); the rest become their letter (<ss>: S)
};

// What Font_EncodeText writes for a character: its font index, NameToken_Space for ' ', NameToken_End after the last.
enum NameToken {
    NameToken_End = 0,
    NameToken_Space = 0xff,
};

// An open span is closed at every 19th token from the start of the text.
enum NameSpanChunk {
    NameSpanChunk_Length = 19,
};

// The two files loaded into g_fileLoadBuffer, indexing fileSizes.
enum NameFilterFile {
    NameFilterFile_Patterns = 0,      // data/bin/tv.nat
    NameFilterFile_ReservedNames = 1, // data/bin/res.nat, at the next 512-byte boundary after it
    NameFilterFile_Alignment = 512,
};

static inline unsigned int AlignUp(unsigned int value, unsigned int alignment) {
    unsigned int mask = alignment - 1;
    return (value + mask) & ~mask;
}
struct Header020e0424 { unsigned int count_ : 12; unsigned int textSize_ : 19; unsigned int relocated_ : 1; };
struct KeyTableEntry { int key_; char* text_; };
struct Container020e0310 : Header020e0424 { KeyTableEntry* entries_; char* texts_; };
struct Struct020dfc40 : Container020e0310 { short unknownC_; short unknownE_; int loaderTask_; void* unknown14_; };
struct CharacterCreation {
    char pad0[0xfc];
    NameFilter nameFilter_;
    char unknown_138_[0xd9c - 0x138];
    unsigned int flags_;
    signed char furthestState_[2];
    unsigned char vocation_;
    unsigned char sex_;
    unsigned char bodyType_[2], faceStyle_[2], eyeColor_[2], skinColor_[2], hairStyle_[2], hairColor_[2];
    char** names_;
    unsigned char nameFill_, keyboardResult_, nameTabFlushPass_;
    char padb7;
};
// A run of word tokens in the name.
struct NameSpan {
    short begin_;
    short length_;
    unsigned char joinedToNext_;
    unsigned char open_;
};
extern const char* NameFilter_patternsFilePath;
extern const char* NameFilter_reservedNamesFilePath;
extern char NameFilter_cSlashText[];
extern "C" void NameFilter_Reset(NameFilter*);
extern "C" void KeyTable_Reset(Struct020dfc40*);
extern "C" int KeyTable_LoadInPlace(void*, void*, int);
extern "C" void __clear(void*, unsigned int);
extern "C" FontCharacter* Font_FindCharacter(int, int);
extern "C" void NameFilter_CopyUppercase(int, char*, char*);
extern "C" unsigned int KeyTable_GetCount(Header020e0424*);
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" int Font_FindCharacterIndex(int, int);
extern "C" FontCharacter* Font_GetCharacter(int, int);
extern "C" int Font_EncodeText(const char*, unsigned char*, int);
extern "C" int NameFilter_FindWord(int, int, int, int, int);
extern "C" int NameFilter_MatchPattern(NameFilter*, const unsigned char*, const unsigned char*, int, int);

static inline ForbiddenWordPattern* GetFilePatterns(const ForbiddenWordFile* file) { return file->patterns_; }
static inline int GetFileCount(const ForbiddenWordFile* file) { return file->header_.count_; }

static inline unsigned int PatternOffset(unsigned int base, unsigned int count, unsigned int size, unsigned int alignment) {
    unsigned int stride = AlignUp(size, alignment);
    unsigned int amount = count * stride;
    return base + amount;
}

// Overlay 9, originally func_ov009_02189a4c (USA/EUR 0x02189a4c; JPN not identified)
extern "C" ARM void CharacterCreationUI_CheckName(CharacterCreation* self) {
    int i;
    ForbiddenWordPattern* relocating;
    int relocateCount;
    NameSpan spans[30];
    char normalizedName[512];
    unsigned char nameTokens[128];
    unsigned char wordTokens[ForbiddenWord_MaxWords][64];
    char upperName[64];
    char upperCharacter[12];
    char normalizedCharacter[12];
    unsigned int fileSizes[2];
    char* name = self->names_[self->sex_];
    if (!*name) return;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    NameFilter_Reset(&self->nameFilter_);
    fileSizes[NameFilterFile_Patterns] = 0;
    fileSizes[NameFilterFile_ReservedNames] = 0;
    LoadFileIntoMemory(NameFilter_patternsFilePath, g_fileLoadBuffer, &fileSizes[NameFilterFile_Patterns]);
    unsigned int reservedNamesOffset = (fileSizes[NameFilterFile_Patterns] + (NameFilterFile_Alignment - 1)) & ~(NameFilterFile_Alignment - 1);
    LoadFileIntoMemory(NameFilter_reservedNamesFilePath, g_fileLoadBuffer + reservedNamesOffset, &fileSizes[NameFilterFile_ReservedNames]);
    KeyTable_Reset((Struct020dfc40*)self->nameFilter_.reservedNames);
    KeyTable_LoadInPlace(self->nameFilter_.reservedNames, g_fileLoadBuffer + reservedNamesOffset, fileSizes[NameFilterFile_ReservedNames]);
    memset(&self->nameFilter_.patterns, 0, sizeof(ForbiddenWordFile));
    unsigned char* patternsFile = g_fileLoadBuffer;
    if (patternsFile) {
        memcpy(&self->nameFilter_.patterns, g_fileLoadBuffer, sizeof(ForbiddenWordHeader));
        unsigned int patternsOffset = AlignUp(sizeof(ForbiddenWordHeader), 4);
        unsigned char* base = g_fileLoadBuffer;
        self->nameFilter_.patterns.patterns_ = (ForbiddenWordPattern*)(base + patternsOffset);
        unsigned int patternsSize = PatternOffset(0, self->nameFilter_.patterns.header_.count_, sizeof(ForbiddenWordPattern), 4);
        self->nameFilter_.patterns.texts_ = (char*)(base + (patternsOffset + patternsSize));
        unsigned int relocated = self->nameFilter_.patterns.header_.relocated_;
        if (!relocated) {
            const ForbiddenWordFile* patterns = &self->nameFilter_.patterns;
            relocating = GetFilePatterns(patterns);
            if (relocating) {
                relocateCount = GetFileCount(patterns);
                int (*relocate)(ForbiddenWordFile*, ForbiddenWordPattern*);
                if (relocateCount && (relocate = ForbiddenWordFile_RelocatePattern) != 0) {
                    for (i = 0; i < relocateCount; ++i, ++relocating) ForbiddenWordFile_RelocatePattern(self->nameFilter_.GetPatterns(), relocating);
                }
            }
            self->nameFilter_.patterns.header_.relocated_ = 1;
            ((ForbiddenWordHeader*)g_fileLoadBuffer)->relocated_ = 1;
        }
    }
    self->nameFilter_.reservedNamesData = 0;
    self->nameFilter_.reservedNamesSize = 0;
    if (fileSizes[NameFilterFile_ReservedNames]) {
        self->nameFilter_.reservedNamesData = g_fileLoadBuffer + reservedNamesOffset;
        self->nameFilter_.reservedNamesSize = fileSizes[NameFilterFile_ReservedNames];
    }
    int rejected;
    int isReservedName;
    {
        __clear(upperName, sizeof(upperName));
        char* out = upperName;
        char* in = name;
        for (;;) {
            if (!*in) break;
            FontCharacter* character = Font_FindCharacter((int)in, FontId_Me);
            __clear(upperCharacter, sizeof(upperCharacter));
            int byteLength = character->byteLength_;
            char* text = character->text_;
            if (character->lowercase_) {
                NameFilter_CopyUppercase((int)&self->nameFilter_, text, upperCharacter);
                text = upperCharacter;
            }
            memcpy(out, text, byteLength);
            in += byteLength;
            out += byteLength;
        }
        int nameLength = strlen(upperName);
        int reservedIndex;
        int reservedCount = KeyTable_GetCount((Struct020dfc40*)self->nameFilter_.reservedNames);
        for (reservedIndex = 0; reservedIndex < reservedCount; ++reservedIndex) {
            char* reservedName = (char*)KeyTable_Get((Struct020dfc40*)self->nameFilter_.reservedNames, (short)reservedIndex);
            if (reservedName && *reservedName) {
                int reservedLength = strlen(reservedName);
                if (reservedLength == nameLength && strcmp(reservedName, upperName) == 0) { isReservedName = 1; goto reservedChecked; }
            }
        }
        isReservedName = 0;
    }
reservedChecked:
    if (isReservedName) {
        rejected = 1;
        goto finished;
    }
    int patternCount;
    NameSpan* firstSpan;
    int firstSpanCount;
    __clear(spans, sizeof(spans));
    __clear(normalizedName, sizeof(normalizedName));
    __clear(nameTokens, sizeof(nameTokens));
    {
        int cSlashId;
        int apostropheId;
        unsigned char ampersandId;
        unsigned char atId;
        unsigned char slashId;
        unsigned char dollarId;
        dollarId = self->nameFilter_.dollarId;
        slashId = self->nameFilter_.slashId;
        atId = self->nameFilter_.atId;
        ampersandId = self->nameFilter_.ampersandId;
        apostropheId = self->nameFilter_.apostropheId;
        cSlashId = self->nameFilter_.cSlashId;
        char* out = normalizedName;
        for (;;) {
            if (!*name) break;
            int index = Font_FindCharacterIndex((int)name, FontId_Me);
            FontCharacter* character = Font_GetCharacter(index, FontId_Me);
            if (!character) goto other_character;
            if (((index >= MeFont_Zero && index <= MeFont_LowerZ) || index == MeFont_UpperOE || index == MeFont_LowerOE ||
                 (index >= MeFont_FirstAccented && index <= MeFont_LastAccented) || index == dollarId || index == atId ||
                 index == ampersandId || index == MeFont_SlashTag || index == apostropheId)) {
                int typedLength = character->byteLength_;
                if (index == MeFont_SlashTag) character = Font_GetCharacter(slashId, FontId_Me);
                __clear(normalizedCharacter, sizeof(normalizedCharacter));
                int byteLength = character->byteLength_;
                char* text = character->text_;
                if (character->lowercase_) {
                    NameFilter_CopyUppercase((int)&self->nameFilter_, text, normalizedCharacter);
                    text = normalizedCharacter;
                }
                if (index >= MeFont_FirstAccented && index <= MeFont_LastAccented) {
                    int letter = text[1];
                    if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z')) {
                        if (letter != 's') goto copy_character;
                    }
                    letter = text[2];
                    if (letter >= 'a' && letter <= 'z') letter = (char)(letter - ('a' - 'A'));
                    memset(normalizedCharacter, 0, sizeof(normalizedCharacter));
                    normalizedCharacter[0] = letter;
                    text = normalizedCharacter;
                    byteLength = 1;
                }
            copy_character:
                memcpy(out, text, byteLength);
                name += typedLength;
                out += byteLength;
            } else if (index == cSlashId) {
                int typedLength = character->byteLength_;
                memcpy(out, NameFilter_cSlashText, 1);
                name += typedLength;
                out++;
            } else {
            other_character:
                int typedLength = 1;
                if (character) {
                    typedLength = character->byteLength_;
                    *out = ',';
                } else *out = ' ';
                name += typedLength;
                ++out;
            }
        }
    }
    short patternIndex;
    ForbiddenWordPattern* pattern;
    int spanCount;
    NameSpan* wordSpan;
    int sharedIndex; // one variable in the original: the chunk position, then the next span's start, then the word index
    Font_EncodeText(normalizedName, nameTokens, FontId_Me);
    sharedIndex = 0;
    unsigned int token;
    NameSpan* span;
    unsigned char* cursor;
    int position;
    int commaId;
    span = spans;
    commaId = self->nameFilter_.commaId;
    cursor = nameTokens;
    position = sharedIndex;
    spanCount = sharedIndex;
    for (;;) {
        token = *cursor;
        if (span->open_) {
            if (token == NameToken_End || token == NameToken_Space || token == commaId) {
                spanCount++;
                span->length_ = position - span->begin_;
                span->joinedToNext_ = token == NameToken_Space ? 1 : 0;
                span->open_ = 0;
                span++;
            }
        } else {
            if (token != NameToken_End && token < NameToken_Space && token != commaId) {
                span->begin_ = position;
                span->open_ = 1;
            }
            if (token == commaId && spanCount != 0) (spans + (spanCount - 1))->joinedToNext_ = 0;
        }
        if (span->open_ && sharedIndex == NameSpanChunk_Length - 1) {
            spanCount++;
            span->length_ = position - span->begin_ + 1;
            span->joinedToNext_ = 1;
            span++;
        }
        if (!token) break;
        sharedIndex++;
        cursor++;
        position++;
        if (sharedIndex == NameSpanChunk_Length) sharedIndex = 0;
    }
    int gapCommaId;
    NameSpan* gapSpan = spans;
    gapCommaId = self->nameFilter_.commaId;
    for (int i = 0; i < spanCount - 1; ++i, ++gapSpan) {
        unsigned char* gapToken;
        int position = gapSpan->begin_ + gapSpan->length_;
        sharedIndex = gapSpan[1].begin_;
        gapSpan->joinedToNext_ = 1;
        gapToken = nameTokens + position;
        while (position < sharedIndex) {
            if (gapCommaId == *gapToken) { gapSpan->joinedToNext_ = 0; break; }
            ++position;
            ++gapToken;
        }
    }
    int signedCommaId = (signed char)self->nameFilter_.commaId;
    for (int i = 0; i < (int)sizeof(nameTokens); ++i) {
        if (signedCommaId == (signed char)nameTokens[i]) ((char*)nameTokens)[i] = (char)NameToken_Space;
    }
    patternCount = (short)self->nameFilter_.patterns.header_.count_;
    for (patternIndex = 0; patternIndex < patternCount; ++patternIndex) {
        pattern = self->nameFilter_.patterns.patterns_ + patternIndex;
        firstSpan = spans;
        __clear(wordTokens, sizeof(wordTokens));
        for (int j = 0; j < pattern->count_; ++j) {
            Font_EncodeText(pattern->words_[j], wordTokens[j], FontId_Me);
            pattern->words_[j] = (char*)wordTokens[j];
        }
        firstSpanCount = spanCount - pattern->count_ + 1;
        for (int j = 0; j < firstSpanCount; ++j, ++firstSpan) {
            int matched;
            {
                wordSpan = firstSpan;
                unsigned char* tokens = nameTokens;
                int wordCount = pattern->count_;
                int lastWord = wordCount - 1;
                for (sharedIndex = 0; sharedIndex < wordCount; ++sharedIndex, ++wordSpan) {
                    if (sharedIndex < lastWord && !wordSpan->joinedToNext_) { matched = 0; goto patternChecked; }
                    int match;
                    int wordLength = pattern->lengths_[sharedIndex];
                    int spanLength = wordSpan->length_;
                    int offsetCount = spanLength - wordLength + 1;
                    match = pattern->matchTypes_[sharedIndex];
                    int word = (int)pattern->words_[sharedIndex];
                    switch (match) {
                    case ForbiddenWordMatch_Whole:
                        if (wordLength != spanLength) { matched = 0; goto patternChecked; }
                        if (!NameFilter_FindWord((int)&self->nameFilter_, word, (int)(tokens + wordSpan->begin_), wordLength, 1)) { matched = 0; goto patternChecked; }
                        break;
                    case ForbiddenWordMatch_Prefix:
                        if (spanLength < wordLength) { matched = 0; goto patternChecked; }
                        if (!NameFilter_FindWord((int)&self->nameFilter_, word, (int)(tokens + wordSpan->begin_), wordLength, 1)) { matched = 0; goto patternChecked; }
                        break;
                    case ForbiddenWordMatch_Suffix:
                        if (spanLength < wordLength) { matched = 0; goto patternChecked; }
                        if (!NameFilter_FindWord((int)&self->nameFilter_, word, (int)(tokens + (wordSpan->begin_ + wordSpan->length_ - wordLength)), wordLength, 1)) { matched = 0; goto patternChecked; }
                        break;
                    case ForbiddenWordMatch_Contains:
                        if (spanLength < wordLength) { matched = 0; goto patternChecked; }
                        if (!NameFilter_FindWord((int)&self->nameFilter_, word, (int)(tokens + wordSpan->begin_), wordLength, offsetCount)) { matched = 0; goto patternChecked; }
                        break;
                    case ForbiddenWordMatch_PatternWhole:
                        if (wordLength != spanLength) { matched = 0; goto patternChecked; }
                        if (!NameFilter_MatchPattern(&self->nameFilter_, (unsigned char*)word, tokens + wordSpan->begin_, wordLength, 1)) { matched = 0; goto patternChecked; }
                        break;
                    case ForbiddenWordMatch_PatternPrefix:
                        if (spanLength < wordLength) { matched = 0; goto patternChecked; }
                        if (!NameFilter_MatchPattern(&self->nameFilter_, (unsigned char*)word, tokens + wordSpan->begin_, wordLength, 1)) { matched = 0; goto patternChecked; }
                        break;
                    case ForbiddenWordMatch_PatternSuffix:
                        if (spanLength < wordLength) { matched = 0; goto patternChecked; }
                        if (!NameFilter_MatchPattern(&self->nameFilter_, (unsigned char*)word, tokens + (wordSpan->begin_ + wordSpan->length_ - wordLength), wordLength, 1)) { matched = 0; goto patternChecked; }
                        break;
                    case ForbiddenWordMatch_PatternContains:
                        if (spanLength < wordLength) { matched = 0; goto patternChecked; }
                        if (!NameFilter_MatchPattern(&self->nameFilter_, (unsigned char*)word, tokens + wordSpan->begin_, wordLength, offsetCount)) { matched = 0; goto patternChecked; }
                        break;
                    }
                }
                matched = 1;
            }
patternChecked:
            if (matched) {
                rejected = 1;
                goto finished;
            }
        }
    }
    rejected = 0;
finished:
    BackgroundLoader::RemoveLockGlobal();
    if (rejected) self->flags_ |= CreationFlag_NameRejected;
    else self->flags_ |= CreationFlag_NameAccepted;
}
