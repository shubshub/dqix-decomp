#include <globaldefs.h>

struct Struct_0205d81c;

struct Struct_ov023_021e68cc_3 {
    char pad0[0xac];
    short x;
    short y;
};

struct Struct_ov023_021e68cc {
    char pad0[0x14];
    int posX;
    int unknown_18_;
    char unknown_1c_[0x22 - 0x1c];
    unsigned char tile;
    char unknown_23_[0x25 - 0x23];
    unsigned char palette;
    char unknown_26_[0x28 - 0x26];
};

#if defined(jpn)
struct Struct_ov023_021e68cc_2 {
    char pad0[0x90];
#else
struct Struct_ov023_021e68cc_2 {
    char pad0[0xac];
#endif

#if defined(jpn)
    char list_[0x1334 - 0x90];
#else
    char list_[0x135c - 0xac];
#endif

    void* renderer_;
    char unknown_1360_[0x1364 - 0x1360];
    Struct_ov023_021e68cc* sprites_;
#if defined(jpn)

#else
    char unknown_1368_[0x1370 - 0x1368];
#endif

    unsigned char mode_;
    unsigned char page_;
#if defined(jpn)
    char unknown_1342_[0x1370 - 0x1342];
#else
    char unknown_1372_[0x13a8 - 0x1372];
#endif

    signed char unknown_13a8_;
    char unknown_13a9_[0x13ab - 0x13a9];
    unsigned char unknown_13ab_;
};

extern "C" Struct_ov023_021e68cc_3* func_0205d81c(Struct_0205d81c* s, int key);
extern "C" void SpriteContext_DrawSprite(void* renderer, void* sprite);

// USA: func_ov023_021e68cc
extern "C" ARM void func_ov023_021e68cc(Struct_ov023_021e68cc_2* self) {
#if defined(jpn)
 enum {regionalOffset0=0x11};
#else
 enum {regionalOffset0=0x13};
#endif
    unsigned char page = self->page_;
    if (page != 7 && page != 8 && page != 9)
        return;
    if (self->mode_ != 4)
        return;

    int posX;
    signed char slot = 0;
    unsigned char tile = regionalOffset0;
    for (int row = 0; row < 3; row++) {
        Struct_ov023_021e68cc_3* e = func_0205d81c((Struct_0205d81c*)self->list_, (unsigned char)(row + 7));
        posX = ((short)(e->x * 8) + 10) << 12;
        short top = e->y * 8;
        for (int col = 0; col < 2; col++) {
            int offset = 0x10;
            int index = 0xd;
            int dir = 1;
            if (col == 1) {
                offset = 0x1c;
                index = 0xe;
                dir = -1;
            }
            Struct_ov023_021e68cc* sprite = &self->sprites_[index];
            int y = top + offset;
            sprite->posX = posX;
            sprite->unknown_18_ = y << 12;
            sprite->tile = tile++;
            sprite->palette = 7;
            if (slot == self->unknown_13a8_) {
                sprite->posX = posX;
                sprite->unknown_18_ = (y - dir) << 12;
            }
            if (!(self->unknown_13ab_ & (1 << slot)))
                sprite->palette = 0xd;
            SpriteContext_DrawSprite(self->renderer_, sprite);
            slot++;
        }
    }
    self->unknown_13a8_ = -1;
}
