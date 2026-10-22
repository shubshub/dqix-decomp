#include <globaldefs.h>

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bacc;

void GridCursor_Init(Struct_0205bef8* cursor);
void GridCursor_SetDimensions(Struct_0205ba68* s, int a, int b, int mode);
void GridCursor_SetCount(Node0205bacc* s, int val);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);

struct Struct_ov008_02186964 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov008_02186964_2 {
    char unknown_0_[0x744];
    unsigned char unknown_744_[8];
    unsigned char unknown_74c_;
    char unknown_74d_[0x750 - 0x74d];
    Struct_ov008_02186964 unknown_750_;
    char unknown_758_[0xb10 - 0x758];
    signed char unknown_b10_;
    char unknown_b11_[0xb18 - 0xb11];
    unsigned int unknown_b18_;
    char unknown_b1c_[0xb28 - 0xb1c];
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
};

// USA: func_ov008_02186964
extern "C" ARM void func_ov008_02186964(Struct_ov008_02186964_2* arg0) {
    int var0;
    int var1;
    int var2;
    int var3;
    var1 = 1;
    var3 = var1;
    var0 = var1;
    var2 = 0;
    if (arg0->unknown_b10_ == 3) {
        var1 = 1;
        var3 = arg0->unknown_74c_;
        var0 = var3;
        for (int var4 = 0; var4 < var3; var4++) {
            if (arg0->unknown_b28_ == arg0->unknown_744_[var4]) {
                var2 = var4;
                break;
            }
        }
        if (var3 > 6) {
            arg0->unknown_b18_ |= 0x10;
            if (var2 > arg0->unknown_b29_ + 5) {
                arg0->unknown_b29_ = var2 - 5;
            } else if (var2 < arg0->unknown_b29_) {
                arg0->unknown_b29_ = var2;
            }
        }
    }
    GridCursor_Init((Struct_0205bef8*)&self->cursor);
    GridCursor_SetDimensions((Struct_0205ba68*)&self->cursor, columns, count, 0);
    GridCursor_SetCount((Node0205bacc*)&self->cursor, visible);
    self->cursor.field4 = columns;
    GridCursor_SetSelectedIndex(&self->cursor, index);
}
