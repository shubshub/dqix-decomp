#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Node0205bacc;

struct MenuList {
    int unk_0;
    int active_;
    char unk_8[0x3c - 0x8];
    unsigned char unk_3c;
    unsigned char unk_3d;
};

struct EquipmentMenu {
    char unk_0[R(0x196c, 0x19f4)];
    MenuList cursor_;
    char unk_1a32[0x3db8 - 0x19f4 - sizeof(MenuList)];
    unsigned char state_;
    char unk_3db9[0x3dbb - 0x3db9];
    signed char slot_;
    unsigned char kind_;
};

void GridCursor_Init(Struct_0205bef8* s);
void GridCursor_SetDimensions(Struct_0205ba68* s, int a, int count, int mode);
void GridCursor_SetCount(Node0205bacc* s, int val);
extern "C" void GridCursor_SetSelectedIndex(void* s, int index);

// USA: func_ov005_021571d0
extern "C" ARM void func_ov005_021571d0(EquipmentMenu* self) {
    int cols;
    short rows;
    int mode;
    int count;
    int active;
    short index;
    unsigned char flagA;
    unsigned char flagB;
    switch (self->state_) {
    case 0:
        rows = 8;
        cols = 1;
        mode = 0;
        count = 8;
        active = 1;
        flagA = 0;
        flagB = 1;
        index = self->kind_;
        break;
    case 2:
        rows = 1;
        cols = 8;
        mode = 0;
        active = 1;
        count = 8;
        flagA = 1;
        flagB = 0;
        index = self->kind_;
        break;
    case 3:
        rows = 1;
        cols = 8;
        mode = 0;
        active = 1;
        count = 8;
        flagA = 1;
        flagB = 0;
        index = self->kind_;
        break;
    case 4:
    case 6:
        mode = 1;
        cols = 4;
        rows = 4;
        active = 1;
        flagA = 1;
        index = self->slot_ - 8;
        count = 0x10;
        flagB = 0;
        break;
    }
    GridCursor_Init((Struct_0205bef8*)&self->cursor_);
    GridCursor_SetDimensions((Struct_0205ba68*)&self->cursor_, cols, rows, mode);
    GridCursor_SetCount((Node0205bacc*)&self->cursor_, count);
    self->cursor_.active_ = active;
    GridCursor_SetSelectedIndex(&self->cursor_, index);
    self->cursor_.unk_3c = flagA;
    self->cursor_.unk_3d = flagB;
}
