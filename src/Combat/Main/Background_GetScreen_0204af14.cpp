#include <globaldefs.h>

struct EntryList0204af14 {
    char pad0[0x10];     // 0x0..0xf
    char* entries;       // 0x10
    char pad1[9];        // 0x14..0x1c
    unsigned char count; // 0x1d
};

// Main, originally GetEntryByIndexStride0x10 (USA 0x0204af14, EUR 0x0204af24, JPN 0x0204bd34)
ARM void* Background_GetScreen(struct EntryList0204af14* list, unsigned int index) {
    char* entries = list->entries;
    if (entries == NULL) {
        return NULL;
    }
    return (list->count <= index) ? NULL : entries + index * 0x10;
}
