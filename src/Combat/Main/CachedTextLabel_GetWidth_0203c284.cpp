#include <globaldefs.h>

#if defined(jpn)
struct CachedTextEntry {
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
};
struct TextOamEntry {
    unsigned int attributes01;
    unsigned short attribute2;
    unsigned short affineParameter;
};

struct CachedTextTable {
    TextOamEntry* drawingBuffer;
    CachedTextEntry entries[96];
    unsigned char unknown604[8];
    unsigned int paletteControl;
    unsigned short nextOamEntry;
};
struct Struct0203c1c8 {
#if defined(jpn)
    short textSlots[10];
#endif
    int x;
    int y;
#if defined(jpn)
    int lineHeight;
    int characterAdvance;
#endif
    int paletteOffset;
    int alignment;
    int priority;
#if defined(jpn)
    signed int affineIndex : 16;
    unsigned int unknown32 : 8;
    unsigned int unknown33 : 8;
    int affineMode;
#else
    short entryIndex;
#endif
};
extern CachedTextTable* data_02105244;
int STD_GetStringLength(const char* text);

// Main, originally GetEntryByteField0203c284 (USA 0x0203c284, EUR 0x0203c294, JPN 0x0203be6c)
ARM int CachedTextLabel_GetWidth(const Struct0203c1c8* label) {
    CachedTextTable* cache = data_02105244;
    if (cache == NULL) return 0;
    CachedTextEntry* entries;
    int cells = 0;
    entries = cache->entries;
    for (int slot = 0; slot < 10; ++slot) {
        short index = label->textSlots[slot];
        if (index >= 0) ++cells;
        int length = STD_GetStringLength(entries[index].text);
        switch (length) {
            case 2: ++slot; break;
            case 4: ++slot; ++cells; break;
            case 6: ++slot; cells += 2; break;
        }
    }
    return cells * label->characterAdvance;
}
#else

extern void* data_02105244;  // the CachedTextTable

// A CachedTextTable entry (0x28 bytes): its width in pixels at +0x21
struct Entry0203c284 {
    char pad[0x21];
    unsigned char width;
    char pad2[6];
};

enum {
    kEntries = 4,       // the table's entries follow its drawing buffer pointer
    kEntryIndex = 0x14  // the label's cached entry index
};

// USA: func_0203c284
ARM unsigned char CachedTextLabel_GetWidth(char* label) {
    char* table = (char*)data_02105244;
    if (table == NULL) return 0;
    {
        struct Entry0203c284* entries = (struct Entry0203c284*)(table + kEntries);
        short index = *(short*)(label + kEntryIndex);
        if (index < 0) return 0;
        return entries[index].width;
    }
}

#endif
