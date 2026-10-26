#include <globaldefs.h>

struct SearchEntry {
    unsigned short key;
    char unk[0xe];
};

struct SearchTable {
    struct SearchEntry* entries;
    int count;
};

// Main, originally FindEntryByHalfwordKey_02099950 (USA 0x02099950, EUR 0x02099960, JPN 0x0209b684)
extern "C" ARM struct SearchEntry* ZoneTable_FindEntry(struct SearchTable* table, int key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (key == table->entries[i].key) {
            return &table->entries[i];
        }
    }
    return 0;
}
