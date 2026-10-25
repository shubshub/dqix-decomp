#include <globaldefs.h>

struct Elem0205a370 {
    char unk0[0x10];
    unsigned short unk10;
    unsigned short unk12;
    unsigned char unk14;
    unsigned char flags15;
    char unk16[2];
};

struct Container0205a3d0;

extern struct Elem0205a370* SpriteEntryList_Find(struct Container0205a3d0*, int);

// Main, originally SetEntryFlag2ByKey0205a370 (USA 0x0205a370, EUR 0x0205a380, JPN 0x0205b6e8)
ARM void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key) {
    struct Elem0205a370* e = SpriteEntryList_Find(c, key);
    if (e == NULL) return;
    if (e->flags15 & 1) {
        e->unk10 = 0;
        e->unk12 = 0;
    }
    e->flags15 &= ~7;
    e->flags15 |= 2;
}
