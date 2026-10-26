#include <globaldefs.h>

// One CachedTextTable entry
struct Struct_0203c6b8 {
    char unk0[0x24];
    unsigned char references;
    char unknown_25_[3];
};

// The CachedTextTable
struct RefArray0xc6b8 {
    int drawingBuffer;
    struct Struct_0203c6b8 entries[32];
    char pad[0xE];
    unsigned short allocatedEntries;
};

// Main, originally IncrementEntryCount0x24_0203c6b8 (USA 0x0203c6b8, EUR 0x0203c6c8; JPN not identified)
extern "C" ARM void CachedTextTable_AddReference(struct RefArray0xc6b8* table, short index) {
    struct Struct_0203c6b8* entry;
    unsigned char references;
    if (index < 0) {
        return;
    }
    entry = &table->entries[index];
    references = entry->references;
    if (references == 0) {
        entry->references = 1;
        table->allocatedEntries++;
    } else {
        entry->references = references + 1;
    }
}
