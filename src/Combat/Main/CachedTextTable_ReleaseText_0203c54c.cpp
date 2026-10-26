#include <globaldefs.h>

#if defined(jpn)
struct CachedTextEntryRelease {
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
};

struct CachedTextTableRelease {
    void* drawingBuffer;
    CachedTextEntryRelease entries[96];
    int engine;
    char* bitmapStorage;
    unsigned int paletteControl;
    unsigned short nextOamEntry;
    unsigned short allocatedEntries;
    unsigned char workBuffer[256];
};

void CachedTextEntry_Clear(char* entry);
#else
void CachedTextEntry_Clear(char* entry);

// CachedTextTable layout
enum {
    kEntries = 4,
    kEntrySize = 0x28,
    kReferences = 0x24,       // in an entry
    kAllocatedEntries = 0x512
};
#endif

// Main, originally ReleaseEntry0203c54c (USA 0x0203c54c, EUR 0x0203c55c, JPN 0x0203c758)
ARM void CachedTextTable_ReleaseText(char* table, short* indexPtr) {
#if defined(jpn)
    if (indexPtr == NULL) return;
    CachedTextTableRelease* cache = reinterpret_cast<CachedTextTableRelease*>(table);
    CachedTextEntryRelease* next;
    for (int i = 0; i < 10; ++i) {
        short index = indexPtr[i];
        if (index < 0) continue;
        CachedTextEntryRelease* entry = &cache->entries[index];
        next = &cache->entries[index + 1];
        if (entry->references == 0) continue;
        indexPtr[i] = -1;
        --entry->references;
        --next->references;
        if (entry->references != 0) continue;
        CachedTextEntry_Clear(reinterpret_cast<char*>(entry));
        CachedTextEntry_Clear(reinterpret_cast<char*>(next));
        cache->allocatedEntries -= 2;
    }
#else
    short index = *indexPtr;
    int references;
    char* entry;
    if (index < 0) return;
    entry = table + kEntries + index * kEntrySize;
    *indexPtr = -1;
    references = ((unsigned char*)entry)[kReferences];
    if (references == 0) return;
    references = references - 1;
    ((unsigned char*)entry)[kReferences] = references;
    if ((references & 0xff) != 0) return;
    CachedTextEntry_Clear(entry);
    *(unsigned short*)(table + kAllocatedEntries) -= 1;
#endif
}
