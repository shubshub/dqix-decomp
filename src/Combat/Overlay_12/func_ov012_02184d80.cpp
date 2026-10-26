#include <globaldefs.h>
#include <std_library_functions.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Filesystem/FileIO.h"

struct ForbiddenWordFile;
struct ForbiddenWordPattern;
extern "C" int func_ov012_0218558c(ForbiddenWordFile*, ForbiddenWordPattern*);

struct ForbiddenWordPattern {
    char* words_[5];
    signed char lengths_[5];
    unsigned char unknown_19_[5];
    unsigned char count_;
    char unknown_1f_;
};
struct ForbiddenWordHeader {
    unsigned int count_ : 12;
    unsigned int unknown_1_4_ : 19;
    unsigned int relocated_ : 1;
};
static inline unsigned int AlignUp(unsigned int value, unsigned int alignment) {
    unsigned int mask = alignment - 1;
    return (value + mask) & ~mask;
}
struct ForbiddenWordFile {
    ForbiddenWordHeader header_;
    ForbiddenWordPattern* patterns_;
    char* texts_;
};
struct CharacterInfo {
    char* text_;
    signed char unk_4;
    signed char length_ : 6;
    signed char unknown_5_6_ : 1;
    signed char unknown_5_7_ : 1;
    char pad6[2];
};
struct Struct_ov012_02184d80 {
    char unknown_0_[0x18];
    ForbiddenWordFile file_;
    void* secondFile_;
    unsigned short unknown_28_;
    char pad2a[4];
    unsigned char unknown_2e_, unknown_2f_, unknown_30_, unknown_31_, unknown_32_;
    unsigned char unknown_33_, unknown_34_, unknown_35_, unknown_36_, unknown_37_, unknown_38_;
    unsigned char pad39[3];
    inline ForbiddenWordFile* inline_ov012_02184d80() { return &file_; }
};
struct NameSpan {
    short begin_;
    short length_;
    unsigned char adjacent_;
    unsigned char active_;
};
struct Struct_ov012_02184d80_2 {
    unsigned int fileSize_;
    char unknown_4_[64];
    char unknown_44_[12];
    char character_[12];
};
extern const char* NameFilter_patternsFilePath;
extern char data_ov012_0218b220[];
extern "C" void __clear(void*, unsigned int);
extern "C" void func_ov012_021855f0(void*, char*, char*);
extern "C" int Font_FindCharacterIndex(int, int);
extern "C" CharacterInfo* Font_GetCharacter(int, int);
extern "C" int Font_EncodeText(const char*, unsigned char*, int);
extern "C" int func_ov012_02185634(void*, void*, int, int, int);
extern "C" int func_ov012_02185684(void*, unsigned char*, unsigned char*, int, int);

static inline ForbiddenWordPattern* GetFilePatterns(const ForbiddenWordFile* file) { return file->patterns_; }
static inline int GetFileCount(const ForbiddenWordFile* file) { return file->header_.count_; }

static inline unsigned int PatternOffset(unsigned int base, unsigned int count, unsigned int size, unsigned int alignment) {
    unsigned int stride = AlignUp(size, alignment);
    unsigned int amount = count * stride;
    return base + amount;
}

// USA: func_ov012_02184d80
extern "C" ARM int func_ov012_02184d80(Struct_ov012_02184d80* self, char* name, char* out) {
    int last;
    int count;
    unsigned char dollarId;
    unsigned char slashId;
    unsigned char atId;
    unsigned char ampersandId;
    int apostropheId;
    int var7;
    int positions;
    NameSpan* first;
    int patternCount;
    int i;
    ForbiddenWordPattern* var12;
    int var13;
    unsigned char work_patterns_[5][64];
    unsigned char work_tokens_[128];
    char work_normalized_[512];
    NameSpan var17[30];
    Struct_ov012_02184d80_2 work;
    unsigned short secondFileSize = 0;
    work.fileSize_ = 0;
    LoadFileIntoMemory(NameFilter_patternsFilePath, g_fileLoadBuffer, &work.fileSize_);
    memset(&self->file_, 0, 12);
    unsigned char* buffer = g_fileLoadBuffer;
    if (buffer) {
        memcpy(&self->file_, g_fileLoadBuffer, 4);
        unsigned int var21 = AlignUp(sizeof(ForbiddenWordHeader), 4);
        unsigned char* base = g_fileLoadBuffer;
        self->file_.patterns_ = (ForbiddenWordPattern*)(base + var21);
        unsigned int bytes = PatternOffset(0, self->file_.header_.count_, sizeof(ForbiddenWordPattern), 4);
        self->file_.texts_ = (char*)(base + (var21 + bytes));
        unsigned int relocated = self->file_.header_.relocated_;
        if (!relocated) {
            const ForbiddenWordFile* var25 = &self->file_;
            var12 = GetFilePatterns(var25);
            if (var12) {
                var13 = GetFileCount(var25);
                int (*callback)(ForbiddenWordFile*, ForbiddenWordPattern*);
                if (var13 && (callback = func_ov012_0218558c) != 0) {
                    for (i = 0; i < var13; ++i, ++var12) func_ov012_0218558c(self->inline_ov012_02184d80(), var12);
                }
            }
            self->file_.header_.relocated_ = 1;
            ((ForbiddenWordHeader*)g_fileLoadBuffer)->relocated_ = 1;
        }
    }
    self->secondFile_ = 0;
    self->unknown_28_ = 0;
    if (secondFileSize) {
        self->secondFile_ = g_fileLoadBuffer + secondFileSize;
        self->unknown_28_ = secondFileSize;
    }
    __clear(var17, 180);
    __clear(work_normalized_, 512);
    __clear(work_tokens_, 128);
    {
    dollarId = self->unknown_32_;
    slashId = self->unknown_33_;
    atId = self->unknown_34_;
    ampersandId = self->unknown_35_;
    apostropheId = self->unknown_38_;
    var7 = self->unknown_37_;
    out = work_normalized_;
    for (;;) {
        if (!*name) break;
        CharacterInfo* entry;
        int index = Font_FindCharacterIndex((int)name, 1);
        entry = Font_GetCharacter(index, 1);
        if (!entry) goto fallback_character;
        if (((index >= 8 && index <= 69) || index == 77 || index == 83 ||
                      (index >= 120 && index <= 169) || index == dollarId || index == atId ||
                      index == ampersandId || index == 107 || index == apostropheId)) {
            int advance = entry->length_;
            if (index == 107) entry = Font_GetCharacter(slashId, 1);
            __clear(work.character_, 12);
            int length = entry->length_;
            char* text = entry->text_;
            if (entry->unknown_5_7_) {
                func_ov012_021855f0(self, text, work.character_);
                text = work.character_;
            }
            if (index >= 120 && index <= 169) {
                int c = text[1];
                if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                    if (c != 's') goto copy_character;
                }
                c = text[2];
                if (c >= 'a' && c <= 'z') c = (char)(c - 32);
                memset(work.character_, 0, 12);
                work.character_[0] = c;
                text = work.character_;
                length = 1;
            }
        copy_character:
            memcpy(out, text, length);
            name += advance;
            out += length;
        } else if (index == var7) {
            int length = entry->length_;
            memcpy(out, data_ov012_0218b220, 1);
            name += length;
            out++;
        } else {
        fallback_character:
            int length = 1;
            if (entry) {
                length = entry->length_;
                *out = ',';
            } else *out = ' ';
            name += length;
            ++out;
        }
    }
    }
    int var35;
    int var36;
    int wordIndex;
    int var38;
    unsigned char* p;
    int var40;
    int var41;
    int signedCommaId;
    NameSpan* gapSpan;
    int gapCommaId;
    int commaId;
    int position;
    unsigned char* token;
    NameSpan* span;
    int var49;
    NameSpan* var50;
    ForbiddenWordPattern* pattern;
    short patternIndex;
    int spanCount;
    unsigned int c;
    Font_EncodeText(work_normalized_, work_tokens_, 1);
    var49 = 0;
    span = var17;
    commaId = self->unknown_36_;
    token = work_tokens_;
    position = var49;
    spanCount = var49;
    for (;;) {
        c = *token;
        if (span->active_) {
            if (c == 0 || c == 255 || c == commaId) {
                spanCount++;
                span->length_ = position - span->begin_;
                span->adjacent_ = c == 255 ? 1 : 0;
                span->active_ = 0;
                span++;
            }
        } else {
            if (c != 0 && c < 255 && c != commaId) {
                span->begin_ = position;
                span->active_ = 1;
            }
            if (c == commaId && spanCount != 0) (var17 + (spanCount - 1))->adjacent_ = 0;
        }
        if (span->active_ && var49 == 18) {
            spanCount++;
            span->length_ = position - span->begin_ + 1;
            span->adjacent_ = 1;
            span++;
        }
        if (!c) break;
        var49++;
        token++;
        position++;
        if (var49 == 19) var49 = 0;
    }
    gapSpan = var17;
    gapCommaId = self->unknown_36_;
    for (var41 = 0; var41 < spanCount - 1; ++var41, ++gapSpan) {
        var35 = gapSpan->begin_ + gapSpan->length_;
        var40 = gapSpan[1].begin_;
        gapSpan->adjacent_ = 1;
        p = work_tokens_ + var35;
        while (var35 < var40) {
            if (gapCommaId == *p) { gapSpan->adjacent_ = 0; break; }
            ++var35;
            ++p;
        }
    }
    signedCommaId = (signed char)self->unknown_36_;
    for (var38 = 0; var38 < 128; ++var38) {
        if (signedCommaId == (signed char)work_tokens_[var38]) ((char*)work_tokens_)[var38] = -1;
    }
    patternCount = (short)self->file_.header_.count_;
    for (patternIndex = 0; patternIndex < patternCount; ++patternIndex) {
        pattern = self->file_.patterns_ + patternIndex;
        first = var17;
        __clear(work_patterns_, 320);
        for (wordIndex = 0; wordIndex < pattern->count_; ++wordIndex) {
            Font_EncodeText(pattern->words_[wordIndex], work_patterns_[wordIndex], 1);
            pattern->words_[wordIndex] = (char*)work_patterns_[wordIndex];
        }
        positions = spanCount - pattern->count_ + 1;
        for (var36 = 0; var36 < positions; ++var36, ++first) {
            int matched;
            {
                var50 = first;
                unsigned char* input = work_tokens_;
                count = pattern->count_;
                last = count - 1;
                for (var49 = 0; var49 < count; ++var49, ++var50) {
                    if (var49 < last && !var50->adjacent_) { matched = 0; goto match_done; }
                    int type;
                    int length = pattern->lengths_[var49];
                    int spanLength = var50->length_;
                    int positions = spanLength - length + 1;
                    type = pattern->unknown_19_[var49];
                    int text = (int)pattern->words_[var49];
                    switch (type) {
                    case 0:
                        if (length != spanLength) { matched = 0; goto match_done; }
                        if (!func_ov012_02185634(self, (void*)text, (int)(input + var50->begin_), length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 3:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!func_ov012_02185634(self, (void*)text, (int)(input + var50->begin_), length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 2:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!func_ov012_02185634(self, (void*)text, (int)(input + (var50->begin_ + var50->length_ - length)), length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 1:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!func_ov012_02185634(self, (void*)text, (int)(input + var50->begin_), length, positions)) { matched = 0; goto match_done; }
                        break;
                    case 4:
                        if (length != spanLength) { matched = 0; goto match_done; }
                        if (!func_ov012_02185684(self, (unsigned char*)text, input + var50->begin_, length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 7:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!func_ov012_02185684(self, (unsigned char*)text, input + var50->begin_, length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 6:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!func_ov012_02185684(self, (unsigned char*)text, input + (var50->begin_ + var50->length_ - length), length, 1)) { matched = 0; goto match_done; }
                        break;
                    case 5:
                        if (spanLength < length) { matched = 0; goto match_done; }
                        if (!func_ov012_02185684(self, (unsigned char*)text, input + var50->begin_, length, positions)) { matched = 0; goto match_done; }
                        break;
                    }
                }
                matched = 1;
            }
match_done:
            if (matched) {
                return 1;
            }
        }
    }
    return 0;
}
