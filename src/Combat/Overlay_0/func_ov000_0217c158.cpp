#include <globaldefs.h>

struct Struct_0205bcdc;
struct GridCursor;

struct Struct_ov000_0217c158 {
    char unk_0[4];
    char selection[0x50];
    int unk_54;
    char unk_58[0x68 - 0x58];
    int rows;
};

struct Struct_ov000_0217c158_2 {
    char unk_0[0x18];
    short hp;
};

struct Struct_ov000_0217c158_3 {
    char unk_0[0x10];
    signed char unknown_10_[8];
    signed char depth;
    char unknown_19_[0x1e - 0x19];
    short unknown_1e_;
    unsigned char field_20;
    char unknown_21_;
    signed char unknown_22_;
    char unknown_23_[0x2c - 0x23];
    short unknown_2c_;
    char unknown_2e_[0x38 - 0x2e];
    Struct_ov000_0217c158* cursor;
#if defined(jpn)
    char unk_3c[0x430 - 0x3c];
#else
    char unk_3c[0x3f0 - 0x3c];
#endif
    Struct_ov000_0217c158_2* slots[0x10];
};

extern "C" int func_0205dd08(Struct_ov000_0217c158* cursor);
extern "C" void GridCursor_TurnPage(struct GridCursor* s, int delta);
extern "C" int GridCursor_GetSelectedIndex(struct GridCursor* s);
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int index);
extern "C" int abs(int);

// USA: func_ov000_0217c158
extern "C" ARM int func_ov000_0217c158(Struct_ov000_0217c158_3* menu) {
    int delta;
    int index;
    signed char rows;
    short prev;
    int var4;
    Struct_ov000_0217c158* cursor;

    delta = func_0205dd08(menu->cursor);
    if (delta == 0) {
        return 0;
    }
    cursor = menu->cursor;
    GridCursor_TurnPage((struct GridCursor*)&cursor->unk_54, delta);
    index = GridCursor_GetSelectedIndex((struct GridCursor*)&cursor->unk_54);
    GridCursor_SelectIfValid((struct Struct_0205bcdc*)cursor->selection, index);
    switch (menu->unknown_10_[menu->depth]) {
    case 0xf:
        menu->field_20 = index;
        break;
    case 0x10:
        menu->unknown_1e_ = index;
        break;
    case 0x11: {
        var4 = menu->unknown_22_ & 3;
        prev = index;
        rows = cursor->rows;
        short column = index & 3;
        if ((short)abs(column - var4) == 1 && var4 < column) {
            if (menu->slots[index] == 0) {
                index = rows * 4;
            }
        }
        while (menu->slots[index] == 0) {
            index--;
        }
        while (menu->slots[index] != 0) {
            if (menu->slots[index]->hp > 0) {
                break;
            }
            index--;
        }
        if (prev != index) {
            GridCursor_SelectIfValid((struct Struct_0205bcdc*)cursor->selection, index);
            GridCursor_SetSelectedIndex(&cursor->unk_54, index);
        }
        menu->unknown_22_ = index;
        menu->unknown_2c_ = -1;
        menu->unknown_22_ = index;
        break;
    }
    }
    return 1;
}
