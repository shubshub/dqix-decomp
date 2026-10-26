#include <globaldefs.h>

struct Struct_ov023_021f9da8_3 {
    char pad0[0x20];
    unsigned short* table;
    unsigned short rows;
    unsigned short cols;
};

struct Struct_ov023_021f9da8 {
    char pad[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_ov023_021f9da8_2 {
    char pad[0x20];
    Struct_ov023_021f9da8 sub;
    Struct_ov023_021f9da8* inline_ov023_021f9da8() { return &sub; }
};

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* base, int key);
extern "C" Struct_ov023_021f9da8_2* func_ov023_021f9cb8(void* unused, void* other, void* node);

// USA: func_ov023_021f9da8
extern "C" ARM int func_ov023_021f9da8(Struct_ov023_021f9da8_3* self, void* other, int x, int y) {
    void* nodes = func_ov011_021849c8(other);
    unsigned short total = self->rows * self->cols;
    unsigned short i;
    for (i = 0; i < total; i++) {
        void* node = func_ov023_021f6880(nodes, self->table[i]);
        Struct_ov023_021f9da8_2* linked = func_ov023_021f9cb8(self, other, node);
        if (linked == 0) {
            continue;
        }
        Struct_ov023_021f9da8* sub = linked->inline_ov023_021f9da8();
        if (sub == 0) {
            continue;
        }
        short var6 = sub->unknown_ae_ * 8;
        short var7 = sub->unknown_ac_;
        short var8 = sub->unknown_a8_;
        var7 = var7 * 8;
        var8 = var8 * 8;
        short bottom = (short)(sub->unknown_aa_ * 8) + var6;
        short right = var7 + var8;
        short left = var7;
        int r = 0;
        if (bottom - 16 > y) {
            return 0;
        }
        if (y >= bottom) {
            return 0;
        }
        if (left <= x && x < left + 16) {
            r--;
        }
        if (right - 16 > x) {
            return r;
        }
        if (x < right) {
            r = 1;
        }
        return r;
    }
    return 0;
}
