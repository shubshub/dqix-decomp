#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct GridCursor;

struct Struct_ov005_021571d0 {
    int unk_0;
    int active_;
    char unk_8[0x3c - 0x8];
    unsigned char unk_3c;
    unsigned char unknown_3d_;
};

struct EquipmentMenu {
    char unk_0[R(0x196c, 0x19f4)];
    Struct_ov005_021571d0 cursor_;
    char unknown_1a34_[0x3db8 - 0x19f4 - sizeof(Struct_ov005_021571d0)];
    unsigned char state_;
    char unknown_3db9_[0x3dbb - 0x3db9];
    signed char slot_;
    unsigned char kind_;
};

extern "C" void GridCursor_Init(GridCursor* s);
extern "C" void GridCursor_SetDimensions(GridCursor* s, int a, int count, int mode);
extern "C" void GridCursor_SetCount(GridCursor* s, int val);
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
    unsigned char var7;
    switch (self->state_) {
    case 0:
        rows = 8;
        cols = 1;
        mode = 0;
        count = 8;
        active = 1;
        flagA = 0;
        var7 = 1;
        index = self->kind_;
        break;
    case 2:
        rows = 1;
        cols = 8;
        mode = 0;
        active = 1;
        count = 8;
        flagA = 1;
        var7 = 0;
        index = self->kind_;
        break;
    case 3:
        rows = 1;
        cols = 8;
        mode = 0;
        active = 1;
        count = 8;
        flagA = 1;
        var7 = 0;
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
        var7 = 0;
        break;
    }
    GridCursor_Init((GridCursor*)&self->cursor_);
    GridCursor_SetDimensions((GridCursor*)&self->cursor_, cols, rows, mode);
    GridCursor_SetCount((GridCursor*)&self->cursor_, count);
    self->cursor_.active_ = active;
    GridCursor_SetSelectedIndex(&self->cursor_, index);
    self->cursor_.unk_3c = flagA;
    self->cursor_.unknown_3d_ = var7;
}
