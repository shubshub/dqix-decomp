#include <globaldefs.h>

struct Table0215e9a4 {
    char pad0;
    signed char width;
    signed char height;
    char pad3;
    short* data;
};

struct LookupTable0215e930 {
    char pad0;
    signed char unknown_1_;
    char pad2;
    signed char count;
    short* entries;
};

struct List0215e824;

struct Cell0215e8f4 {
    char pad0[0x10];
    short id;
};

struct Keyboard {
    struct Cell0215e8f4* key;
    struct List0215e824* layout;
    char pad8[0x19];
    unsigned char wrap;
};

extern "C" struct Table0215e9a4* Keyboard_GetPageGrid(struct Keyboard*);
extern "C" ARM int KeyboardPageGrid_FindKeyCell(struct LookupTable0215e930* obj, short target, unsigned char* outMod, unsigned char* outDiv);
extern "C" int func_ov003_0215e9a4(struct Table0215e9a4*, int, int);
extern "C" struct Cell0215e8f4* func_ov003_0215e824(struct List0215e824*, int);

// Overlay 3, originally func_ov003_0215e9ec (USA/EUR 0x0215e9ec; JPN not identified)
extern "C" ARM void Keyboard_MoveCursor(struct Keyboard* self, int dx, int dy) {
    struct Table0215e9a4* table = Keyboard_GetPageGrid(self);
    short target;
    signed char x;
    signed char y;
    unsigned char wrap;
    int v;

    if (table == 0 || self->key == 0) return;
    target = self->key->id;
    if (KeyboardPageGrid_FindKeyCell((struct LookupTable0215e930*)table, target, (unsigned char*)&x, (unsigned char*)&y) != 0) return;

    wrap = self->wrap;
    x += dx;
    y += dy;
    v = func_ov003_0215e9a4(table, x, y);
    if (y < 0) {
        y = 0;
        if (wrap) y = table->height - 1;
        dx = -1;
        dy = 0;
        if (v == -2) dx = 1;
    } else if (table->height <= y) {
        y = table->height - 1;
        if (wrap) y = 0;
        dx = -1;
        dy = 0;
        if (v == -2) dx = 1;
    }

    v = func_ov003_0215e9a4(table, x, y);
    if (dy != 0) {
        if (v == -2) {
            while (v < 0) {
                x++;
                if (table->width <= x) break;
                v = func_ov003_0215e9a4(table, x, y);
            }
            while (v < 0) {
                x--;
                if (x < 0) break;
                v = func_ov003_0215e9a4(table, x, y);
            }
        } else {
            while (v < 0) {
                x--;
                if (x < 0) break;
                v = func_ov003_0215e9a4(table, x, y);
            }
            while (v < 0) {
                x++;
                if (table->width <= x) break;
                v = func_ov003_0215e9a4(table, x, y);
            }
        }
    }

    wrap = 0;
    while (v < 0) {
        if (dx < 0) {
            x--;
            if (x < 0) x = table->width - 1;
            v = func_ov003_0215e9a4(table, x, y);
        } else if (dx > 0) {
            x++;
            if (table->width <= x) x = wrap;
            v = func_ov003_0215e9a4(table, x, y);
        }
    }

    self->key = func_ov003_0215e824(self->layout, v);
}
