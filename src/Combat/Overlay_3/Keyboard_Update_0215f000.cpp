#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov003_0215f000_2 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[0xc - 4];
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    char unknown_f_;
    short unknown_10_;
    char unknown_12_[0x14 - 0x12];
};

struct Struct_ov003_0215f000 {
    struct Struct_ov003_0215f000_2* unknown_0_;
    char unknown_4_[2];
    short unknown_6_;
};

struct Self0215e8f4 {
    struct MenuCell0215f000* cell;
    struct CellList0215f000* list;
    char pad8[0x18 - 8];
    int repeatTimer;
    unsigned short repeatDir;
    unsigned char mask;
    char pad1f[0x22 - 0x1f];
    unsigned char allowAlt;
    unsigned char allowCancel;
    unsigned char autoRepeat;
};

struct Struct_ov003_0215e930;

struct LookupTable0215e930* FindEntryByMask_0215e8f4(struct Self0215e8f4* self);
extern "C" int func_ov003_0215e930(struct LookupTable0215e930* table, short id, signed char* col, signed char* row);
extern "C" void func_ov003_0215e9ec(struct Self0215e8f4* self, int dx, int dy);
extern "C" int Keyboard_HandleKey(struct Self0215e8f4* self);
extern "C" int func_ov003_0215eeb8(struct Self0215e8f4* self);
extern "C" void Keyboard_GetKeySize(int shape, short* w, short* h);

// Overlay 3, originally func_ov003_0215f000 (USA/EUR 0x0215f000; JPN not identified)
extern "C" ARM int Keyboard_Update(struct Self0215e8f4* self, int elapsed) {
    struct MenuCell0215f000* prev = self->cell;
    int i;
    short count;
    struct MenuCell0215f000* hit;
    unsigned char mask;
    int result;

    if (arg0->unknown_0_ == 0) {
        var5 = 0;
        arg0->unknown_18_ = 0;
        arg0->unknown_1c_ = 0;
    } else {
        if (g_keyManager.TestKeysPressed(0x40)) {
            func_ov003_0215e9ec(arg0, 0, -1);
            arg0->unknown_18_ = 0x14;
            arg0->unknown_1c_ = 0x40;
        } else if (g_keyManager.TestKeysPressed(0x80)) {
            func_ov003_0215e9ec(arg0, 0, 1);
            arg0->unknown_18_ = 0x14;
            arg0->unknown_1c_ = 0x80;
        } else if (g_keyManager.TestKeysPressed(0x20)) {
            func_ov003_0215e9ec(arg0, -1, 0);
            arg0->unknown_18_ = 0x14;
            arg0->unknown_1c_ = 0x20;
        } else if (g_keyManager.TestKeysPressed(0x10)) {
            func_ov003_0215e9ec(arg0, 1, 0);
            arg0->unknown_18_ = 0x14;
            arg0->unknown_1c_ = 0x10;
        }

        if (self->autoRepeat) {
            unsigned short dir = self->repeatDir;
            if (dir != 0 && g_keyManager.TestKeysHeld(0xf0)) {
                int timer = self->repeatTimer - elapsed;
                if (timer <= 0) {
                    timer = 10;
                    switch (dir) {
                    case 0x40:
                        func_ov003_0215e9ec(arg0, 0, -1);
                        break;
                    case 0x80:
                        func_ov003_0215e9ec(arg0, 0, 1);
                        break;
                    case 0x20:
                        func_ov003_0215e9ec(arg0, -1, 0);
                        break;
                    case 0x10:
                        func_ov003_0215e9ec(arg0, 1, 0);
                        break;
                    }
                    if (self->autoRepeat) {
                        signed char curRow;
                        signed char curCol;
                        signed char prevRow;
                        signed char prevCol;
                        struct LookupTable0215e930* table = FindEntryByMask_0215e8f4(self);
                        struct MenuCell0215f000* cur = self->cell;
                        if (func_ov003_0215e930(table, prev->id, &prevCol, &prevRow) == 0
                            && func_ov003_0215e930(table, cur->id, &curCol, &curRow) == 0) {
                            switch (dir) {
                            case 0x40:
                                if (var10 < var8) arg0->unknown_0_ = var0;
                                break;
                            case 0x80:
                                if (var10 > var8) arg0->unknown_0_ = var0;
                                break;
                            case 0x20:
                                if (var11 < var9) arg0->unknown_0_ = var0;
                                break;
                            case 0x10:
                                if (var11 > var9) arg0->unknown_0_ = var0;
                                break;
                            }
                        }
                    }
                }
                arg0->unknown_18_ = var7;
            } else {
                arg0->unknown_18_ = 0;
                arg0->unknown_1c_ = 0;
            }
        }
        if (var0 == arg0->unknown_0_) {
            var5 = 0;
        } else {
            var5 = 1;
        }
    }

    if (var5 == 0) {
        unsigned char var14 = arg0->unknown_22_;
        unsigned char var15 = arg0->unknown_23_;
        if (g_keyManager.TestKeysPressed(1)
            || (allowAlt && g_keyManager.TestKeysPressed(0x200))) {
            result = Keyboard_HandleKey(self);
        } else if (allowCancel && g_keyManager.TestKeysPressed(2)) {
            result = func_ov003_0215eeb8(self);
        } else {
            var5 = 0;
        }

        if (var5 == 0) {
            var4 = arg0->unknown_1e_;
            if (g_touchInput.pressed_) {
                int ty;
                int tx;
                g_touchInput.GetTouchPoint(&tx, &ty);
                struct CellList0215f000* list = self->list;
                hit = list->cells;
                count = list->count;
                for (i = 0; i < count; i++, hit++) {
                    if (hit->mask & mask) {
                        short h;
                        short w;
                        Keyboard_GetKeySize(hit->shape, &w, &h);
                        if (hit->y <= ty && ty < hit->y + h && hit->x <= tx && tx < hit->x + w) {
                            goto found;
                        }
                    }
                }
            }
            var3 = 0;
        found:
            if (hit != 0) {
                self->cell = hit;
                result = Keyboard_HandleKey(self);
            }
        }
    }
    return var5;
}
