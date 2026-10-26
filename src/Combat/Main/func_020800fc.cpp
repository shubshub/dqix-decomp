#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_020800fc_3;
struct Struct_020800fc_4 {
    short* itemIds;
    unsigned int unknown4;
    short id;
    short tileX;
    short tileY;
    short tileWidth;
    short unknown_10_;
    unsigned char unknown12;
    unsigned char itemCount;
    char unknown14[4];
};
struct Struct_0207f524 {
    Struct_020800fc_3* entries;
    short count;
};
struct Struct_02012538 {
    Struct_020800fc_4* entries;
    short count;
};
struct Struct_020800fc_2 {
    void* table;
    Struct_0207f524 items;
    Struct_02012538 groups;
#if defined(jpn)
    char unknown14[0x2f - 0x14];
#else
    char unknown14[0x3b - 0x14];
#endif
    signed char unknown_3b_;
    signed char unknown_3c_;
};

struct Struct_020800fc_3 {
    char pad0[4];
    short f4;
    char pad1[0x18 - 6];
    struct Struct_020800fc_3* f18;
    struct Struct_020800fc_3* f1c;
    struct Struct_020800fc_3* f20;
    struct Struct_020800fc_3* f24;
    char pad2[0x2a - 0x28];
    unsigned char unknown_2a_;
};

struct Struct_020800fc {
    unsigned int f0;
};

extern "C" void* func_020810b4(unsigned char* self, short val);
extern "C" int func_02080e40(void* obj, int p1, int p2, int p3);
extern "C" struct Struct_020800fc_3* func_0207f6ac(struct Struct_0207f524* list, int id);
extern "C" struct Struct_020800fc_3* func_0208036c(void* unused, struct Struct_020800fc_3* start, int mode, struct Struct_020800fc* flags, unsigned char arg4);

// USA: func_020800fc
extern "C" ARM int func_020800fc(struct Struct_020800fc_2* self, short* arg1, short id, int mode, unsigned char sel, unsigned char arg5) {
    struct Struct_020800fc flags;
    struct Struct_020800fc_3* node;
    struct Struct_020800fc_3* e;
    struct Struct_020800fc_4* slot;
    int x;
    int y;
    int ret;

    flags.f0 = 0;
    *arg1 = id;
    if (g_touchInput.pressed_ != 0) {
        slot = (struct Struct_020800fc_4*)func_020810b4((unsigned char*)self, id);
        if (slot != NULL) {
            g_touchInput.GetTouchPoint(&x, &y);
            ret = func_02080e40(self, slot->id, (short)x, (short)y);
            if (ret >= 0) {
                *arg1 = (short)ret;
            }
            if (arg5 != 0) {
                short var7 = (short)(slot->tileX + slot->tileWidth);
                short var8 = (short)(slot->tileY + slot->unknown_10_);
                if ((short)(var8 << 3) - self->unknown_3c_ <= y && y < (short)(var8 << 3)) {
                    short var9 = (short)(slot->tileX << 3);
                    if (var9 <= x && x < var9 + self->unknown_3b_) {
                        flags.f0 |= 0x20;
                    }
                    if ((short)(var7 << 3) - self->unknown_3b_ <= x && x < (short)(var7 << 3)) {
                        flags.f0 |= 0x10;
                    }
                }
            }
        }
        return flags.f0;
    }

    if (sel == 0) {
        return flags.f0;
    }
    e = func_0207f6ac(&self->items, *arg1);
    if (e == NULL) {
        return flags.f0;
    }
    node = NULL;
    switch (mode) {
    case 0x10:
        node = e->f24;
        flags.f0 |= 8;
        break;
    case 0x20:
        node = e->f20;
        flags.f0 |= 4;
        break;
    case 0x40:
        node = e->f18;
        flags.f0 |= 1;
        break;
    case 0x80:
        node = e->f1c;
        flags.f0 |= 2;
        break;
    }
    if (node != NULL) {
        if (node->unknown_2a_ & 2) {
            node = func_0208036c(self, e, mode, &flags, arg5);
        }
        if (node != NULL) {
            *arg1 = node->f4;
        }
    } else {
        if (sel == 1) {
            e = func_0208036c(self, e, mode, &flags, arg5);
        } else if (sel == 2 && arg5 != 0) {
            switch (mode) {
            case 0x10:
                flags.f0 |= 0x10;
                break;
            case 0x20:
                flags.f0 |= 0x20;
                break;
            }
        }
        *arg1 = e->f4;
    }
    return flags.f0;
}
