#include <globaldefs.h>

struct Elem0205a3ac {
    char unk0[0x15];
    unsigned char flags15;
    char unk16[2];
};

struct Container0205a3d0;

extern struct Elem0205a3ac* SpriteEntryList_Find(struct Container0205a3d0*, int);

// USA: func_0205a3ac
ARM void SetEntryFlag1ByKey0205a3ac(struct Container0205a3d0* c, int key) {
    struct Elem0205a3ac* e = SpriteEntryList_Find(c, key);
    if (e != NULL) {
        e->flags15 &= ~7;
        e->flags15 |= 1;
    }
}
