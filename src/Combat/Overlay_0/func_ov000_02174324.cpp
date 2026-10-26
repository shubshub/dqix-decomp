#include <globaldefs.h>

#if defined(jpn)
#define data_ov000_02183460 data_ov000_021844e8
#define data_ov000_021833b0 data_ov000_0218445a
#endif
struct Struct_ov000_02174324 {
    char pad[0x25];
    unsigned char field_0x25;
    char pad2[0x28 - 0x26];
    unsigned int statusFlags;
    char pad3[0x2f - 0x2c];
    unsigned char unknown_2f_;
};

struct Slot02174324 {
    char pad[0x14];
    int x;
    int y;
    char pad2[0x22 - 0x1c];
    unsigned char palette;
    char pad3[0x26 - 0x23];
    unsigned char active;
    char pad4[0x28 - 0x27];
};

struct Struct_ov000_02174324_3 {
    char pad[0x11c];
    char queue[0x170 - 0x11c];
    struct Slot02174324* slots;
};

extern "C" struct Struct_ov000_02174324* func_ov000_02161318(struct Struct_ov000_02174324_3* obj, int id);
extern "C" int SpriteContext_DrawSprite(void* queue, struct Slot02174324* slot, int count);

extern unsigned int data_ov000_02183460[];
extern unsigned char data_ov000_021833b0[];

// USA: func_ov000_02174324
#if defined(jpn)
enum { Enum_ov000_02174324_92 = 0x58 };
#else
enum { Enum_ov000_02174324_92 = 0x5c };
#endif
extern "C" ARM int func_ov000_02174324(struct Struct_ov000_02174324_3* battle, int id, int x, int y) {
    struct Struct_ov000_02174324* c = func_ov000_02161318(battle, id);
    if (c == NULL) return 0;

    int i = 0;
    int found = 0;
    unsigned int flags = c->statusFlags;
    unsigned char var4;
    unsigned char palette;

    while (data_ov000_02183460[i] != 0) {
        unsigned int bit = data_ov000_02183460[i];
        if (c->statusFlags & bit) {
            if (bit == 2 && c->unknown_2f_ != 2 && i == 4) {
                i++;
                continue;
            }
            var4 = data_ov000_021833b0[i] + 0x15;
            palette = id + Enum_ov000_02174324_92;
            found = 1;
            break;
        }
        i++;
    }

    if ((flags & 0x80000) && i >= 4) {
        if (c->field_0x25 != 9) {
            palette = id + Enum_ov000_02174324_92;
            found = 1;
            var4 = 0x1f;
        }
    }

    if (!found) return 0;

    struct Slot02174324* slot = &battle->slots[var4];
    slot->x = x << 12;
    slot->y = y << 12;
    slot->palette = palette;
    slot->active = 1;
    SpriteContext_DrawSprite(battle->queue, slot, 1);
    return 1;
}
