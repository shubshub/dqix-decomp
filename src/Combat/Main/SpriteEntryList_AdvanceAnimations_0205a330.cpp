#include <globaldefs.h>

struct Container0205a330 {
    char unk0[4];
    unsigned short count;
};

extern "C" void func_0205a254(struct Container0205a330*, int, int);

// Main, originally IterateEntries0205a330 (USA 0x0205a330, EUR 0x0205a340, JPN 0x0205b6a8)
extern "C" ARM void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg) {
    unsigned short i;
    for (i = 0; i < c->count; i++) {
        func_0205a254(c, i & 0xff, arg);
    }
}
