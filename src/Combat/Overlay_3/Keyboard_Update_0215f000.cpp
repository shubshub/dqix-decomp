#include <globaldefs.h>
#include "Input/Input.h"

struct MenuCell0215f000 {
    short x;
    short y;
    char pad4[0xc - 4];
    unsigned char mask;
    unsigned char key;
    unsigned char shape;
    char padf;
    short id;
    char pad12[0x14 - 0x12];
};

struct CellList0215f000 {
    struct MenuCell0215f000* cells;
    char pad4[2];
    short count;
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
    unsigned char wrap;
};

struct LookupTable0215e930;

struct LookupTable0215e930* FindEntryByMask_0215e8f4(struct Self0215e8f4* self);
extern "C" int func_ov003_0215e930(struct LookupTable0215e930* table, short id, signed char* col, signed char* row);
extern "C" void func_ov003_0215e9ec(struct Self0215e8f4* self, int dx, int dy);
extern "C" int func_ov003_0215ef54(struct Self0215e8f4* self);
extern "C" int func_ov003_0215eeb8(struct Self0215e8f4* self);
extern "C" void func_ov003_0215ec68(int shape, short* w, short* h);

// USA: func_ov003_0215f000
extern "C" ARM int func_ov003_0215f000(struct Self0215e8f4* self, int elapsed) {
    struct MenuCell0215f000* prev = self->cell;
    int i;
    short count;
    struct MenuCell0215f000* hit;
    unsigned char mask;
    int result;

    if (self->cell == 0) {
        result = 0;
        self->repeatTimer = 0;
        self->repeatDir = 0;
    } else {
        if (g_keyManager.TestKeysPressed(0x40)) {
            func_ov003_0215e9ec(self, 0, -1);
            self->repeatTimer = 0x14;
            self->repeatDir = 0x40;
        } else if (g_keyManager.TestKeysPressed(0x80)) {
            func_ov003_0215e9ec(self, 0, 1);
            self->repeatTimer = 0x14;
            self->repeatDir = 0x80;
        } else if (g_keyManager.TestKeysPressed(0x20)) {
            func_ov003_0215e9ec(self, -1, 0);
            self->repeatTimer = 0x14;
            self->repeatDir = 0x20;
        } else if (g_keyManager.TestKeysPressed(0x10)) {
            func_ov003_0215e9ec(self, 1, 0);
            self->repeatTimer = 0x14;
            self->repeatDir = 0x10;
        }

        if (self->wrap) {
            unsigned short dir = self->repeatDir;
            if (dir != 0 && g_keyManager.TestKeysHeld(0xf0)) {
                int timer = self->repeatTimer - elapsed;
                if (timer <= 0) {
                    timer = 10;
                    switch (dir) {
                    case 0x40:
                        func_ov003_0215e9ec(self, 0, -1);
                        break;
                    case 0x80:
                        func_ov003_0215e9ec(self, 0, 1);
                        break;
                    case 0x20:
                        func_ov003_0215e9ec(self, -1, 0);
                        break;
                    case 0x10:
                        func_ov003_0215e9ec(self, 1, 0);
                        break;
                    }
                    if (self->wrap) {
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
                                if (prevRow < curRow) self->cell = prev;
                                break;
                            case 0x80:
                                if (prevRow > curRow) self->cell = prev;
                                break;
                            case 0x20:
                                if (prevCol < curCol) self->cell = prev;
                                break;
                            case 0x10:
                                if (prevCol > curCol) self->cell = prev;
                                break;
                            }
                        }
                    }
                }
                self->repeatTimer = timer;
            } else {
                self->repeatTimer = 0;
                self->repeatDir = 0;
            }
        }
        if (prev == self->cell) {
            result = 0;
        } else {
            result = 1;
        }
    }

    if (result == 0) {
        unsigned char allowAlt = self->allowAlt;
        unsigned char allowCancel = self->allowCancel;
        if (g_keyManager.TestKeysPressed(1)
            || (allowAlt && g_keyManager.TestKeysPressed(0x200))) {
            result = func_ov003_0215ef54(self);
        } else if (allowCancel && g_keyManager.TestKeysPressed(2)) {
            result = func_ov003_0215eeb8(self);
        } else {
            result = 0;
        }

        if (result == 0) {
            mask = self->mask;
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
                        func_ov003_0215ec68(hit->shape, &w, &h);
                        if (hit->y <= ty && ty < hit->y + h && hit->x <= tx && tx < hit->x + w) {
                            goto found;
                        }
                    }
                }
            }
            hit = 0;
        found:
            if (hit != 0) {
                self->cell = hit;
                result = func_ov003_0215ef54(self);
            }
        }
    }
    return result;
}
