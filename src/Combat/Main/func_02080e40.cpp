#include <globaldefs.h>

struct Struct_0207f0ac_2 {
    short* entries;
    char unknown_4_[4];
    short id;
    short tileX;
    short tileY;
    char unknown_e_[5];
    unsigned char count;
    char unknown_14_[4];
};

struct Struct_0207f6ac {
    char unknown_0_[4];
    short id;
    short x;
    short y;
    short width;
    short height;
    char unknown_e_[4];
    unsigned char kind;
    char unknown_13_[5];
    Struct_0207f6ac* down;
    Struct_0207f6ac* up;
    Struct_0207f6ac* right;
    Struct_0207f6ac* left;
    short xOffset;
    unsigned char flags;
    char unknown_2b_[5];
};

struct Struct_0207f0ac { Struct_0207f0ac_2* entries; short count; };
struct Struct_0207f524 { Struct_0207f6ac* entries; short count; };
struct Struct_0207fdcc_2 {
    void* table;
    Struct_0207f524 items;
    Struct_0207f0ac groups;
};

extern "C" int func_02080d54(Struct_0207fdcc_2*, int, int, int);
extern "C" Struct_0207f0ac_2* func_0207f0ac(Struct_0207f0ac*, int);
extern "C" Struct_0207f6ac* func_0207f6ac(Struct_0207f524*, int);

// USA: func_02080e40

extern "C" ARM int func_02080e40(Struct_0207fdcc_2* menu, int arg1, int arg2, int arg3) {
    if (!func_02080d54(menu, arg1, arg2, arg3)) return -1;
    Struct_0207f0ac_2* group = func_0207f0ac(&menu->groups, arg1);
    if (!group) return -1;
    short var1 = group->tileX * 8;
    short var2 = group->tileY * 8;
    for (unsigned char i = 0; i < group->count; i++) {
        int id = group->entries[i];
        Struct_0207f6ac* entry = func_0207f6ac(&menu->items, id);
        if (!entry || entry->kind == 1) continue;
        if (entry->flags & 1) continue;
        if (!entry->down && !entry->up && !entry->right && !entry->left) continue;
        short left = entry->x + entry->xOffset;
        short top = entry->y;
        short right = left + entry->width;
        short bottom = top + entry->height;
        left += var1;
        top += var2;
        right += var1;
        bottom += var2;
        if (arg3 < top) continue;
        if (bottom <= arg3) continue;
        if (arg2 < left) continue;
        if (right > arg2) return id;
    }
    return -1;
}
