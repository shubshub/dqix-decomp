#include <globaldefs.h>

// One CachedTextTable entry
struct Entry0xc6fc {
#if defined(jpn)
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
#else
    char unk0[0x24];
    unsigned char references;
    char unknown_25_[3];
#endif
};

// The CachedTextTable
struct RefArray0xc6fc {
#if defined(jpn)
    void* drawingBuffer;
    Entry0xc6fc entries[96];
    int engine;
    char* bitmapStorage;
    unsigned int unknown_60c_;
    unsigned short nextOamEntry;
    unsigned short allocatedEntries;
    unsigned char workBuffer[256];
#else
    int drawingBuffer;
    struct Entry0xc6fc entries[32];
    char pad[0xE];
    unsigned short allocatedEntries;
#endif
};

// USA: func_0203c6fc
#if defined(jpn)
extern "C" ARM void func_0203cbe4(struct RefArray0xc6fc* table, const short* indices)
#else
extern "C" ARM void func_0203c6fc(struct RefArray0xc6fc* table, short index)
#endif
{
#if defined(jpn)
    if (indices == NULL) return;
    for (int i = 0; i < 10; ++i) {
        short index = indices[i];
        if (index < 0) continue;
        Entry0xc6fc* entry = &table->entries[index];
        Entry0xc6fc* next = &table->entries[index + 1];
        if (entry->references != 0 && next->references != 0) {
            --entry->references;
            --next->references;
            if (entry->references == 0 && next->references == 0) {
                table->allocatedEntries -= 2;
            }
        }
    }
#else
    struct Entry0xc6fc* entry;
    int references;
    if (index < 0) {
        return;
    }
    entry = &table->entries[index];
    references = entry->references;
    if (references == 0) {
        return;
    }
    entry->references = references - 1;
    if (((references - 1) & 0xff) == 0) {
        table->allocatedEntries--;
    }
#endif
}
