#include <globaldefs.h>

struct ListEntry_020283fc {
    unsigned char id;
    unsigned char unk[0xF];
};

struct List_020283fc {
    unsigned char unk0[2];
    unsigned char count;
    unsigned char unk3;
    struct ListEntry_020283fc* entries;
};

// Main, originally FindListIndexById (USA 0x020283fc, EUR 0x0202840c, JPN 0x02027c68)
ARM int NodeGraph_FindNodeIndexById(struct List_020283fc* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (id == list->entries[i].id) {
            return i;
        }
    }
    return -1;
}
