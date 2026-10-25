#include <globaldefs.h>

#if defined(jpn)
#define data_ov000_02183460 data_ov000_021844e8
#define data_ov000_021833b0 data_ov000_0218445a
#endif
struct Struct_ov000_02174324 {
    char unknown_0_[0x25];
    unsigned char unknown_25_;
    char unknown_26_[0x28 - 0x26];
    unsigned int unknown_28_;
    char unknown_2c_[0x2f - 0x2c];
    unsigned char unknown_2f_;
};

struct Struct_ov000_02174324_2 {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[0x22 - 0x1c];
    unsigned char unknown_22_;
    char unknown_23_[0x26 - 0x23];
    unsigned char unknown_26_;
    char unknown_27_[0x28 - 0x27];
};

struct Struct_ov000_02174324_3 {
    char unknown_0_[0x11c];
    char unknown_11c_[0x170 - 0x11c];
    struct Struct_ov000_02174324_2* unknown_170_;
};

extern "C" struct Combatant02174324* func_ov000_02161318(struct Battle02174324* obj, int id);
extern "C" int SpriteContext_DrawSprite(void* queue, struct Slot02174324* slot, int count);

extern unsigned int data_ov000_02183460[];
extern unsigned char data_ov000_021833b0[];

// USA: func_ov000_02174324
#if defined(jpn)
enum { Enum_ov000_02174324_92 = 0x58 };
#else
enum { Enum_ov000_02174324_92 = 0x5c };
#endif
extern "C" ARM int func_ov000_02174324(struct Struct_ov000_02174324_3* arg0, int arg1, int arg2, int arg3) {
    struct Struct_ov000_02174324* var0 = func_ov000_02161318(arg0, arg1);
    if (var0 == NULL) return 0;

    int var1 = 0;
    int var2 = 0;
    unsigned int var3 = var0->unknown_28_;
    unsigned char var4;
    unsigned char var5;

    while (data_ov000_02183460[var1] != 0) {
        unsigned int var6 = data_ov000_02183460[var1];
        if (var0->unknown_28_ & var6) {
            if (var6 == 2 && var0->unknown_2f_ != 2 && var1 == 4) {
                var1++;
                continue;
            }
            var4 = data_ov000_021833b0[var1] + 0x15;
            var5 = arg1 + Enum_ov000_02174324_92;
            var2 = 1;
            break;
        }
        var1++;
    }

    if ((var3 & 0x80000) && var1 >= 4) {
        if (var0->unknown_25_ != 9) {
            var5 = arg1 + Enum_ov000_02174324_92;
            var2 = 1;
            var4 = 0x1f;
        }
    }

    if (!var2) return 0;

    struct Slot02174324* slot = &battle->slots[slotIdx];
    slot->x = x << 12;
    slot->y = y << 12;
    slot->palette = palette;
    slot->active = 1;
    SpriteContext_DrawSprite(battle->queue, slot, 1);
    return 1;
}
