#include <globaldefs.h>

struct Elem0205a3ac {
    char unk0[0x15];
    unsigned char unknown_15_;
    char unknown_16_[2];
};

struct Container0205a3d0;

extern "C" struct Elem0205a3ac* SpriteEntryList_Find(struct Container0205a3d0*, int);

// USA: func_0205a3ac
extern "C" ARM void func_0205a3ac(struct Container0205a3d0* c, int key) {
    struct Elem0205a3ac* e = SpriteEntryList_Find(c, key);
    if (e != NULL) {
        e->unknown_15_ &= ~7;
        e->unknown_15_ |= 1;
    }
}
