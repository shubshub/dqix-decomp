#include <globaldefs.h>
// CachedTextTable layout
#if defined(jpn)
enum {
    kEntryCount = 0x60,
    kEntrySize = 0x10,
    kEngine = 0x604,
    kBitmapStorage = 0x608,
    kPaletteOffset = 0x60c,
    kNextOamEntry = 0x610,
    kAllocatedEntries = 0x612,
    kFirstTextOamEntry = 0
};
#else
enum {
    kEntryCount = 0x20,
    kEntrySize = 0x28,
    kEngine = 0x504,
    kBitmapStorage = 0x508,
    kPaletteOffset = 0x50c,
    kNextOamEntry = 0x510,
    kAllocatedEntries = 0x512,
    kFirstTextOamEntry = 4
};
#endif
enum {
    kDrawingBuffer = 0,
    kEntries = 4,
    kEngineSub = 1  // texts go to the sub screen's OBJ VRAM and palette
};

extern "C" void CachedTextEntry_Clear(char* entry);

// Main, originally ResetBattleState0203c304 (USA 0x0203c304, EUR 0x0203c314, JPN 0x0203c464)
extern "C" ARM void CachedTextTable_Clear(char* table) {
    int i;
    for (i = 0; i < kEntryCount; i++) {
        CachedTextEntry_Clear(table + kEntries + i * kEntrySize);
    }
    *(int*)(table + kDrawingBuffer) = 0;
    *(short*)(table + kAllocatedEntries) = 0;
    *(int*)(table + kEngine) = kEngineSub;
    *(int*)(table + kPaletteOffset) = 0;
    *(int*)(table + kBitmapStorage) = 0;
    *(short*)(table + kNextOamEntry) = kFirstTextOamEntry;
}
