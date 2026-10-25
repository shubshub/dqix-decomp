#include <globaldefs.h>

struct Elem0205a3d0 {
    char unk0[8];
    unsigned short key;
    char unk2[0x18 - 0xa];
};

struct Container0205a3d0 {
    struct Elem0205a3d0* entries;
    unsigned short count;
};

// Main, originally FindEntryByHalfword0205a3d0 (USA 0x0205a3d0, EUR 0x0205a3e0, JPN 0x0205b76c)
ARM struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key) {
    struct Elem0205a3d0* result;
    unsigned short i;
    if (c->entries == NULL) {
        return NULL;
    }
    if (c->count == 0) {
        return NULL;
    }
    result = NULL;
    for (i = 0; i < c->count; i++) {
        if (key == c->entries[i].key) {
            result = &c->entries[i];
            break;
        }
    }
    return result;
}
