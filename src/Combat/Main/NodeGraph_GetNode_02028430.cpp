#include <globaldefs.h>

struct ListEntry_02028430 {
    unsigned char id;
    unsigned char unk[0xF];
};

struct List_02028430 {
    unsigned char unk0[2];
    unsigned char count;
    unsigned char unknown_3_;
    struct ListEntry_02028430* entries;
};

// Main, originally GetListEntryChecked (USA 0x02028430, EUR 0x02028440, JPN 0x02027c9c)
extern "C" ARM struct ListEntry_02028430* NodeGraph_GetNode(struct List_02028430* list, int index) {
    struct ListEntry_02028430* entries;
    if (index < 0 || list->count <= index) {
        return NULL;
    }
    entries = list->entries;
    if (entries != NULL) {
        return &entries[index];
    }
    return NULL;
}
