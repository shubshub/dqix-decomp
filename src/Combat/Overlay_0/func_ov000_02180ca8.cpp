#if defined(jpn)
#define data_ov000_02183674 data_ov000_02184730
#define func_ov000_02171ffc func_ov000_02173834
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
struct Struct0203c1c8  {
#if defined(jpn)
    char unknown_0_[0x14];
#endif
    int x;
    int y;
#if defined(jpn)
    char unknown_1c_[8];
#endif
    int category;
    int alignment;
    int active;
    short unknown_14_;
#if defined(jpn)
    char unknown_32_[0x38 - 0x32];
#endif
};
struct Struct_ov000_02180ca8_4  {
    char padding0[0x14];
    int x;
    int y;
    char padding1c[6];
    unsigned char id;
    char unknown_23_[3];
    unsigned char active;
    char unknown_27_;
};
struct Struct_ov000_02180ca8_5  {
    int flags[3];
    short amount;
    char unknown_e_[2];
    signed char commands[8];
    signed char unknown_18_;
    char unknown_19_[3];
    signed char state;
    signed char unknown_1d_;
    char unknown_1e_[6];
    unsigned char unknown_24_;
    char unknown_25_[9];
    signed char slot;
    char unknown_2f_[0x44 - 0x2f];
    int x;
    int y;
    int actorId;
#if defined(jpn)
    char unknown_50_[0xc7 - 0x50];
#else
    char unknown1_50_[0x87 - 0x50];
#endif
    unsigned char busy;
#if defined(jpn)
    char unknown_c8_[0x483 - 0xc8];
#else
    char unknown_88_[0x443 - 0x88];
#endif
    signed char animation;
    char unknown_444_[4];
};
struct Struct_ov000_02180ca8  {
    char padding0[0x3b];
    unsigned char : 3;
    unsigned char special : 1;
    unsigned char : 4;
};
struct Struct_ov000_02180ca8_2  {
    char padding0[0x138];
    Struct_ov000_02180ca8* stats;
};
struct BackgroundGraphics;
struct Struct_0204b878;
struct Struct_ov000_02180ca8_3  {
    char padding0[0x11c];
    char display[0x54];
    Struct_ov000_02180ca8_4* unknown_170_;
    char unknown_174_[0x8c4 - 0x174];
    char entryList[0x930 - 0x8c4];
    char unknown_930_[0x940 - 0x930];
    int xOffset;
    int yOffset;
    char unknown_948_[8];
    int selected;
    unsigned char mode;
#if defined(jpn)
    char unknown_955_[0x1b64 - 0x955];
#else
    char unknown1_955_[0x1b0c - 0x955];
#endif
    Struct0203c1c8 groups[3];
    Struct0203c1c8 unknown_1b54_;
    Struct0203c1c8 unknown_1b6c_;
#if defined(jpn)
    char unknown_1c7c_[0x1d94 - 0x1c7c];
#else
    char unknown_1b84_[0x1c5c - 0x1b84];
#endif
    Struct0203c1c8 entries[8];
    int unknown_1d1c_[16];
    unsigned char unknown_1d5c_;
};
extern "C" int func_ov000_0217fe30(Struct_ov000_02180ca8_3*);
extern "C" void SpriteContext_DrawSprite(void*, void*);
extern "C" int func_ov000_021719f8(int*);
extern "C" int func_ov000_02174e34(int, int);
extern "C" Struct0203c1c8* func_ov000_02174e1c(void*, int);
extern "C" int func_ov000_02171ffc(Struct_ov000_02180ca8_5*);
#if defined(jpn)
extern "C" void CachedTextLabel_Draw(Struct0203c1c8*, int);
#else
extern "C" void CachedTextLabel_Draw(Struct0203c1c8*);
#endif
extern "C" void* Background_GetScreen(BackgroundGraphics*, unsigned int);
extern "C" void func_0204b878(Struct_0204b878*, int, int, int, short, short, short, short, unsigned short);
extern const int data_ov000_02183674[11];
static inline int inline_ov000_02180ca8(int slot)  { return slot >= 0 && slot <= 3; }
// USA: func_ov000_02180ca8
extern "C" ARM void func_ov000_02180ca8(Struct_ov000_02180ca8_3* self, Struct_ov000_02180ca8_5* action, Struct_0204b878* list)  {
    if (!action)  {
        return;
    }
    int xOffset = 0;
    int yOffset = 0;
    if (action->unknown_24_ & 8)  {
        yOffset = self->yOffset;
        xOffset = self->xOffset;
    }
    int x = action->x;
    int y = action->y;
    int tileX;
    int tileY;
    int category;
    int actorId = action->actorId;
    tileX = x >> 3;
    tileY = y >> 3;
    GameObject* actor = func_0200ff1c(GameState::GetInstance(), actorId);
    if (func_ov000_0217fe30(self) && actor && action->amount && ((Struct_ov000_02180ca8_2*)actor)->stats->special)  {
        Struct_ov000_02180ca8_4* display = &self->unknown_170_[30];
        display->x = 0;
        display->y = (y + 7) << 12;
#if defined(jpn)
        display->id = action->actorId + 0x40;
#else
        display->id = action->actorId + 0x44;
#endif
        display->active = 0;
        SpriteContext_DrawSprite(self->display, display);
    }
    signed char command = action->commands[action->unknown_18_];
    if (command == 0x67)  {
        return;
    }
    if (command >= 0x64)  {
        if (command != 0x66 && func_ov000_0217fe30(self) && action->amount)  {
            Struct_ov000_02180ca8_4* display = &self->unknown_170_[6];
            display->x = 0xe0000;
            display->y = (y + 7) << 12;
#if defined(jpn)
            display->id = action->actorId + 0x78;
#else
            display->id = action->actorId;
#endif
            display->active = 1;
            SpriteContext_DrawSprite(self->display, display);
        }
        if (action->state == 6 || action->amount == 0 || func_ov000_021719f8(action->flags) || action->state == 2 || action->animation != 5)  {
            return;
        }
        int slot;
        Struct0203c1c8* entry;
        int var14;
        var14 = action->unknown_1d_;
        slot = action->slot;
        category = 3;
        if (action->commands[action->unknown_18_] != 0x66)  {
            category = 0;
            int value = func_ov000_02174e34((int)self, slot);
            if (value != -1)  {
                category = value;
            }
        }
        entry = 0;
        if (var14 >= 0 && var14 < self->unknown_1d5c_)  {
            entry = &self->entries[var14];
        }
        if (inline_ov000_02180ca8(slot))  {
            entry = func_ov000_02174e1c(self, slot);
        }
        switch (func_ov000_02171ffc(action))  {
            case 3:
            entry = &self->unknown_1b6c_;
            break;
            case 4:             if (inline_ov000_02180ca8(slot))  {
                entry = &self->unknown_1b6c_;
            }
#if !defined(jpn)
            else  {
                Struct0203c1c8* group = self->groups;
                int var17 = self->unknown_1d1c_[0];
                for (int i = 1; i < var14 + 1; ++i)  {
                    int id = self->unknown_1d1c_[i];
                    if (var17 != id)  {
                        ++group;
                    }
                    var17 = id;
                }
                int count = 0;
                for (int i = 0; i < self->unknown_1d5c_; ++i)  {
                    if (var17 == self->unknown_1d1c_[i])  {
                        ++count;
                    }
                }
                if (count > 1)  {
                    entry = group;
                }
            }
#endif
            break;
            case 2:
            break;
            default:
            break;
        }
        if (!entry)  {
            return;
        }
        int xs[2];
        int ys[2];
        int var24[2];
        xs[0] = x + 0xb3 + xOffset;
        xs[1] = x + 0xb4 + xOffset;
        ys[0] = y + 0x17 + yOffset;
        ys[1] = y + 0x17 + yOffset;
        var24[1] = data_ov000_02183674[8];
        var24[0] = category;
        int* var25 = var24;
#if defined(jpn)
        for (int i = 0; i < 2; ++i)  {
#else
        for (int i = 0; i < 1; ++i)  {
#endif
            int value = var25[i];
            int positionX = xs[i];
            entry->category = value;
            entry->alignment = 2;
            entry->x = positionX;
            entry->y = ys[i];
#if defined(jpn)
            CachedTextLabel_Draw(entry, 0xa);
#else
            CachedTextLabel_Draw(entry);
#endif
            entry->active = 1;
        }
        entry->category = 0;
        void* selectedEntry = Background_GetScreen((BackgroundGraphics*)self->entryList, 3);
        func_0204b878(list, (int)selectedEntry, 0, 0,
#if defined(jpn)
            tileX + 16,
#else
            tileX + 15,
#endif
            tileY + 2, 0x20, 0x19, actorId + 2);
    }
    else  {
        Struct0203c1c8* entry = &self->unknown_1b54_;
        if (func_ov000_021719f8(action->flags) || action->busy)  {
            return;
        }
        if (self->selected == 0 && self->mode == 2)  {
            return;
        }
        int xs[2] =  {
            x + 0xb3, x + 0xb4
        };
        int ys[2] =  {
            y + 15, y + 15
        };
        int var33[2] =  {
            data_ov000_02183674[9], data_ov000_02183674[10]
        };
        entry->alignment = 2;
        int* var34;
        int* var35;
        int* var36;
#if defined(jpn)
        var36 = var33;
        int i = 0;
        var35 = xs;
        var34 = ys;
        for (; i < 2; ++i)  {
#else
        var36 = var33;
        var35 = xs;
        var34 = ys;
        for (int i = 1; i < 2; ++i)  {
#endif
            entry->x = var35[i];
            entry->y = var34[i];
#if defined(jpn)
            CachedTextLabel_Draw(entry, 0xa);
#else
            CachedTextLabel_Draw(entry);
#endif
            entry->category = var36[i];
            entry->active = 1;
        }
    }
}
