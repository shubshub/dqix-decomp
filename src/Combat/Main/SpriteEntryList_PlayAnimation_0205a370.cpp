#include <globaldefs.h>

struct Elem0205a370 {
    char unk0[0x10];
    unsigned short unk10;
    unsigned short unknown_12_;
    unsigned char unknown_14_;
    unsigned char unknown_15_;
    char unknown_16_[2];
};

struct Container0205a3d0;

extern "C" struct Elem0205a370* SpriteEntryList_Find(struct Container0205a3d0*, int);

// Main, originally SetEntryFlag2ByKey0205a370 (USA 0x0205a370, EUR 0x0205a380, JPN 0x0205b6e8)
extern "C" ARM void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key) {
    struct Elem0205a370* e = SpriteEntryList_Find(c, key);
    if (e == NULL) return;
    if (e->unknown_15_ & 1) {
        e->unk10 = 0;
        e->unknown_12_ = 0;
    }
    e->unknown_15_ &= ~7;
    e->unknown_15_ |= 2;
}
