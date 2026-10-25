#include <globaldefs.h>

struct Struct_ov003_0215e9a4 {
    char unknown_0_;
    signed char unknown_1_;
    signed char unknown_2_;
    char unknown_3_;
    short* unknown_4_;
};

struct Struct_ov003_0215e930 {
    char unknown_0_;
    signed char unknown_1_;
    char unknown_2_;
    signed char unknown_3_;
    short* unknown_4_;
};

struct Struct_ov003_0215e824;

struct Struct_ov003_0215e9ec {
    char unknown_0_[0x10];
    short unknown_10_;
};

struct Keyboard {
    struct Cell0215e8f4* key;
    struct List0215e824* layout;
    char pad8[0x19];
    unsigned char wrap;
};

struct Table0215e9a4* Keyboard_GetPageGrid(struct Keyboard*);
extern "C" ARM int KeyboardPageGrid_FindKeyCell(struct LookupTable0215e930* obj, short target, unsigned char* outMod, unsigned char* outDiv);
int GetTableEntry0215e9a4(struct Table0215e9a4*, int, int);
struct Cell0215e8f4* FindElemByKey_0215e824(struct List0215e824*, int);

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

    var4 = arg0->unknown_21_;
    var2 += arg1;
    var3 += arg2;
    var5 = func_ov003_0215e9a4(var0, var2, var3);
    if (var3 < 0) {
        var3 = 0;
        if (var4) var3 = var0->unknown_2_ - 1;
        arg1 = -1;
        arg2 = 0;
        if (var5 == -2) arg1 = 1;
    } else if (var0->unknown_2_ <= var3) {
        var3 = var0->unknown_2_ - 1;
        if (var4) var3 = 0;
        arg1 = -1;
        arg2 = 0;
        if (var5 == -2) arg1 = 1;
    }

    var5 = func_ov003_0215e9a4(var0, var2, var3);
    if (arg2 != 0) {
        if (var5 == -2) {
            while (var5 < 0) {
                var2++;
                if (var0->unknown_1_ <= var2) break;
                var5 = func_ov003_0215e9a4(var0, var2, var3);
            }
            while (var5 < 0) {
                var2--;
                if (var2 < 0) break;
                var5 = func_ov003_0215e9a4(var0, var2, var3);
            }
        } else {
            while (var5 < 0) {
                var2--;
                if (var2 < 0) break;
                var5 = func_ov003_0215e9a4(var0, var2, var3);
            }
            while (var5 < 0) {
                var2++;
                if (var0->unknown_1_ <= var2) break;
                var5 = func_ov003_0215e9a4(var0, var2, var3);
            }
        }
    }

    var4 = 0;
    while (var5 < 0) {
        if (arg1 < 0) {
            var2--;
            if (var2 < 0) var2 = var0->unknown_1_ - 1;
            var5 = func_ov003_0215e9a4(var0, var2, var3);
        } else if (arg1 > 0) {
            var2++;
            if (var0->unknown_1_ <= var2) var2 = var4;
            var5 = func_ov003_0215e9a4(var0, var2, var3);
        }
    }

    self->key = FindElemByKey_0215e824(self->layout, v);
}
