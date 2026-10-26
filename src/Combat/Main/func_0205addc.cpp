#include <globaldefs.h>
#include "Graphics/SpriteEntry.h"

struct Elem0205a3d0 {
    char unk0[8];
    unsigned short key;
    char unk2[0x18 - 0xa];
};

struct Container0205a3d0 {
    struct Elem0205a3d0* entries;
    unsigned short count;
};

extern "C" struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);

struct Struct_0205addc {
    unsigned short f0;
    unsigned short f2;
};

struct Entry0205addc {
    char pad0[4];
    short f4;
    short unknown_6_;
    char pad8[4];
    struct Struct_0205addc* fc;
    unsigned short f10;
    char pad12[2];
    unsigned char f14;
    unsigned char f15;
};

struct Slot0205addc {
    char pad0[0x14];
    int f14;
    int f18;
    char unknown_1c_[0x22 - 0x1c];
    unsigned char f22;
    char unknown_23_[0x28 - 0x23];
};

struct Context0205addc {
    char pad0[0x3c];
    struct Container0205a3d0* f3c;
    struct Slot0205addc* f40;
    char unknown_44_[0x4c - 0x44];
    unsigned short unknown_4c_;
};

extern "C" int SpriteContext_DrawSprite(struct Context0205addc* self, struct Slot0205addc* slot, int count);

// USA: func_0205addc
extern "C" ARM int func_0205addc(struct Context0205addc* self, int id) {
    struct Entry0205addc* e;
    struct Entry0205addc* e2;
    int ok;
    unsigned short count;

    if (self->f3c == 0) {
        return (int)self->f3c;
    }
    e = (struct Entry0205addc*)SpriteEntryList_Find(self->f3c, id);
    if (e == 0) {
        return (int)e;
    }
    e2 = (struct Entry0205addc*)SpriteEntryList_Find(self->f3c, id);
    if (e2 != 0) {
        ok = (e2->f15 & SpriteEntryFlag_Shown) ? 1 : 0;
    } else {
        ok = 0;
    }
    if (!ok) {
        return ok;
    }
    count = e->fc[e->f10].f2;
    if (count >= self->unknown_4c_) {
        return self->unknown_4c_;
    }
    struct Slot0205addc* slot = &self->f40[count];
    int v4 = e->f4, v6 = e->unknown_6_;
    slot->f14 = v4 << 0xc;
    slot->f18 = v6 << 0xc;
    if (e->f14 != 0xff) {
        slot->f22 = e->f14;
    }
    return SpriteContext_DrawSprite(self, slot, v6);
}
