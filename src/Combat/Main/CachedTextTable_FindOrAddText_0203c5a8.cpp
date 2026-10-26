#include <globaldefs.h>
#if defined(jpn)
#define func_02043110 func_02043884
#endif

extern "C" void __clear(void* buf, int size);
extern "C" int Font_EncodeText(void* text, void* encoded, int font);
extern "C" int memcmp(void* a, void* b, int size);
#if !defined(jpn)
extern "C" void CachedTextEntry_Render(void* entry, void* encodedText, void* vramOffset);
#endif

// One CachedTextTable entry
struct Entry0203c5a8 {
    char pad[0x20];          // the text as font character indices
    unsigned char length;    // characters
    char pad2[3];
    unsigned char references;
    char pad3[3];
};

// CachedTextTable layout
enum {
    kEntries = 4,
    kEntryCount = 0x20,
    kEntrySize = 0x28,
    kBitmapStorage = 0x508,     // OBJ VRAM byte offset of entry 0's bitmap
    kAllocatedEntries = 0x512,
    kBitmapSize = 0x400         // 128 x 16 pixels at 4bpp, per entry
};

// USA: CachedTextTable_FindOrAddText  (semantic: FindOrAllocateSlot0203c5a8)
#if defined(jpn)
struct CachedTextEntry0203c5a8 {
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
};

struct CachedTextTable0203c5a8 {
    void* drawingBuffer;
    CachedTextEntry0203c5a8 entries[96];
    int engine;
    char* bitmapStorage;
    unsigned int unknown_60c_;
    unsigned short nextOamEntry;
    unsigned short allocatedEntries;
};

enum { kFontPixelSize = 10 };  // the 10-pixel font (Font_GetGlyphTable)

extern "C" int func_02043014(int, unsigned short*);
extern "C" char* func_02043110(int, int);
extern "C" void CachedTextEntry_Render(void*, int, char*, char**, int, void*);
#endif

// Main, originally func_0203c5a8 (USA 0x0203c5a8, EUR 0x0203c5b8, JPN 0x0203c7f4)
#if defined(jpn)
extern "C" ARM void CachedTextTable_FindOrAddText(void* rawTable, void* rawText, void* output, int characterAdvance)
#else
extern "C" ARM void CachedTextTable_FindOrAddText(void* table, void* text, short* outIndex)
#endif
{
#if defined(jpn)
    CachedTextTable0203c5a8* cache = static_cast<CachedTextTable0203c5a8*>(rawTable);
    char* text = static_cast<char*>(rawText);
    short* slots = static_cast<short*>(output);
    if (text == NULL || slots == NULL) return;

    for (short position = 0; position < 20; position += 3) {
        if (text[position] == 0) break;
        char key[7];
        __clear(key, 7);
        key[0] = text[position];
        key[1] = text[position + 1];
        if (text[position + 2] != 0) {
            key[2] = text[position + 2];
            key[3] = text[position + 3];
            if (text[position + 4] != 0) {
                key[4] = text[position + 4];
                key[5] = text[position + 5];
            }
        }
        int first = func_02043014(kFontPixelSize, reinterpret_cast<unsigned short*>(key));
        int second = func_02043014(kFontPixelSize, reinterpret_cast<unsigned short*>(key + 2));
        int third = func_02043014(kFontPixelSize, reinterpret_cast<unsigned short*>(key + 4));
        if (first == -1 && second == -1 && third == -1) {
            position += 3;
            continue;
        }
        if (first == -1) {
            text[position] = text[position + 1] = 0;
        }
        if (second == -1) {
            text[position + 2] = text[position + 3] = 0;
        }
        if (third == -1) {
            text[position + 4] = text[position + 5] = 0;
        }

        short index;
        int checked = 0;
        bool var10 = true;
        for (index = 0; index < 95; index += 2) {
            CachedTextEntry0203c5a8* entry = &cache->entries[index];
            CachedTextEntry0203c5a8* next = &cache->entries[index + 1];
            if (entry->references != 0 &&
                entry->text[0] == text[position] && entry->text[1] == text[position + 1] &&
                entry->text[2] == text[position + 2] && entry->text[3] == text[position + 3] &&
                entry->text[4] == text[position + 4] && entry->text[5] == text[position + 5] &&
                characterAdvance == entry->advanceX) {
                ++entry->references;
                ++next->references;
                slots[position / 3] = index;
                var10 = false;
                break;
            }
            if (cache->allocatedEntries == ++checked) break;
        }

        if (var10) {
            for (index = 0; index < 95; ++index) {
                CachedTextEntry0203c5a8* entry = &cache->entries[index];
                CachedTextEntry0203c5a8* next = &cache->entries[index + 1];
                if (entry->references == 0 && next->references == 0) {
                    char* glyphs[3];
                    __clear(glyphs, 12);
                    glyphs[0] = func_02043110(kFontPixelSize, first);
                    glyphs[1] = func_02043110(kFontPixelSize, second);
                    glyphs[2] = func_02043110(kFontPixelSize, third);
                    CachedTextEntry_Render(entry, cache->engine, text + position, glyphs,
                        characterAdvance, cache->bitmapStorage + index * 128);
                    cache->allocatedEntries += 2;
                    entry->references = 1;
                    next->references = 1;
                    slots[position / 3] = index;
                    break;
                }
            }
        }
        position += 3;
    }
#else
    if (text == 0) return;
    char encoded[0x100];
    __clear(encoded, 0x100);
    int length = Font_EncodeText(text, encoded, 0);

    struct Entry0203c5a8* entry = (struct Entry0203c5a8*)((char*)table + kEntries);
    for (short i = 0; i < kEntryCount; entry = (struct Entry0203c5a8*)((char*)entry + kEntrySize), i++) {
        if (entry->references != 0 && entry->length == length) {
            if (memcmp(entry, encoded, length) == 0) {
                entry->references = entry->references + 1;
                *outIndex = i;
                return;
            }
        }
    }

    entry = (struct Entry0203c5a8*)((char*)table + kEntries);
    for (short j = 0; j < kEntryCount; entry = (struct Entry0203c5a8*)((char*)entry + kEntrySize), j++) {
        if (entry->references == 0) {
            unsigned short allocated = *(unsigned short*)((char*)table + kAllocatedEntries);
            void* bitmapStorage = *(void**)((char*)table + kBitmapStorage);
            allocated = allocated + 1;
            *(unsigned short*)((char*)table + kAllocatedEntries) = allocated;
            entry->references = 1;
            entry->length = (unsigned char)length;
            CachedTextEntry_Render(entry, encoded, (char*)bitmapStorage + j * kBitmapSize);
            *outIndex = j;
            return;
        }
    }
#endif
}
