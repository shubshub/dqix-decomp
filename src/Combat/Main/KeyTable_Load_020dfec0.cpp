#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

// The struct tags stay: KeyTable_GetEntriesSize's and KeyTable_ForEachEntry's C++ symbols are mangled with them.
struct Header020dffb8 {
    unsigned int count : 12;
    unsigned int textSize : 19;
    unsigned int relocated : 1;
};
typedef struct Header020dffb8 KeyTableHeader;

extern "C" int KeyTable_GetEntriesSize(KeyTableHeader* header);

struct Container020dffc8 {
    unsigned int count : 12;
    unsigned int textSize : 19;
    unsigned int relocated : 1;
    void* entries;
    void* texts;
};
typedef struct Container020dffc8 KeyTable;

struct Element020dffc8;
typedef int (*KeyTableEntryCallback)(KeyTable*, struct Element020dffc8*);
extern "C" int KeyTable_ForEachEntry(KeyTable* table, KeyTableEntryCallback callback);

struct Node020dfbdc;
extern "C" int func_020dfbdc(void* a, struct Node020dfbdc* node);

// Main, originally func_020dfec0 (USA 0x020dfec0, EUR 0x020dfed0, JPN 0x020e1a94)
extern "C" ARM int KeyTable_Load(KeyTable* table, SafeAllocator* allocator, void* fileData, unsigned int size) {
    KeyTableEntryCallback relocate;
    unsigned int entriesSize;
    unsigned int textSize;

    if (allocator == 0 || fileData == 0 || size == 0) {
        return 0;
    }
    if (allocator == 0 || fileData == 0) {
        return 0;
    }
    memcpy(table, fileData, sizeof(KeyTableHeader));
    entriesSize = KeyTable_GetEntriesSize((KeyTableHeader*)table);
    textSize = table->textSize;
    if (entriesSize) {
        table->entries = allocator->Allocate(entriesSize);
    } else {
        table->entries = 0;
    }
    table->texts = textSize ? allocator->Allocate(textSize) : 0;
    if (table->entries) {
        memcpy(table->entries, (char*)fileData + sizeof(KeyTableHeader), entriesSize);
    }
    if (table->texts) {
        memcpy(table->texts, (char*)fileData + (KeyTable_GetEntriesSize((KeyTableHeader*)table) + sizeof(KeyTableHeader)), textSize);
    }
    relocate = (KeyTableEntryCallback)func_020dfbdc;
    if (relocate) {
        KeyTable_ForEachEntry(table, relocate);
    }
    table->relocated = 1;
    return 1;
}
