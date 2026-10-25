#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct GridCursor;

struct Struct_ov005_021571d0 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x3c - 0x8];
    unsigned char unknown_3c_;
    unsigned char unknown_3d_;
};

struct Struct_ov005_02153954 {
    char unknown_0_[R(0x196c, 0x19f4)];
    Struct_ov005_021571d0 unknown_19f4_;
    char unknown_1a34_[0x3db8 - 0x19f4 - sizeof(Struct_ov005_021571d0)];
    unsigned char unknown_3db8_;
    char unknown_3db9_[0x3dbb - 0x3db9];
    signed char unknown_3dbb_;
    unsigned char unknown_3dbc_;
};

void GridCursor_Init(GridCursor* s);
void GridCursor_SetDimensions(GridCursor* s, int a, int count, int mode);
void GridCursor_SetCount(GridCursor* s, int val);
extern "C" void GridCursor_SetSelectedIndex(void* s, int index);

// USA: func_ov005_021571d0
extern "C" ARM void func_ov005_021571d0(Struct_ov005_02153954* arg0) {
    int var0;
    short var1;
    int var2;
    int var3;
    int var4;
    short var5;
    unsigned char var6;
    unsigned char var7;
    switch (arg0->unknown_3db8_) {
    case 0:
        var1 = 8;
        var0 = 1;
        var2 = 0;
        var3 = 8;
        var4 = 1;
        var6 = 0;
        var7 = 1;
        var5 = arg0->unknown_3dbc_;
        break;
    case 2:
        var1 = 1;
        var0 = 8;
        var2 = 0;
        var4 = 1;
        var3 = 8;
        var6 = 1;
        var7 = 0;
        var5 = arg0->unknown_3dbc_;
        break;
    case 3:
        var1 = 1;
        var0 = 8;
        var2 = 0;
        var4 = 1;
        var3 = 8;
        var6 = 1;
        var7 = 0;
        var5 = arg0->unknown_3dbc_;
        break;
    case 4:
    case 6:
        var2 = 1;
        var0 = 4;
        var1 = 4;
        var4 = 1;
        var6 = 1;
        var5 = arg0->unknown_3dbb_ - 8;
        var3 = 0x10;
        var7 = 0;
        break;
    }
    GridCursor_Init((GridCursor*)&self->cursor_);
    GridCursor_SetDimensions((GridCursor*)&self->cursor_, cols, rows, mode);
    GridCursor_SetCount((GridCursor*)&self->cursor_, count);
    self->cursor_.active_ = active;
    GridCursor_SetSelectedIndex(&self->cursor_, index);
    self->cursor_.unk_3c = flagA;
    self->cursor_.unk_3d = flagB;
}
