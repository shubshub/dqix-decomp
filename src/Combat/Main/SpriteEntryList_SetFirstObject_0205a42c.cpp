#include <globaldefs.h>

struct Elem0205a42c {
    char unk0[0x14];
    unsigned char unk14;
    char unk15[3];
};

struct Container0205a3d0;

extern struct Elem0205a42c* SpriteEntryList_Find(struct Container0205a3d0*, int);

// Main, originally SetEntryByte14ByKey0205a42c (USA 0x0205a42c, EUR 0x0205a43c, JPN 0x0205b7c8)
ARM void SpriteEntryList_SetFirstObject(struct Container0205a3d0* c, int key, int val) {
    struct Elem0205a42c* e = SpriteEntryList_Find(c, key);
    if (e != NULL) {
        e->unk14 = val;
    }
}
