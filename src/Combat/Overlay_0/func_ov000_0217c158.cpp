#include <globaldefs.h>

struct Struct_0205bcdc;
struct Struct_0205c4a8;
struct Struct_0205bb84;

struct Struct_ov000_0217c158 {
    char unknown_0_[4];
    char unknown_4_[0x50];
    int unknown_54_;
    char unknown_58_[0x68 - 0x58];
    int unknown_68_;
};

struct Struct_ov000_0217c158_2 {
    char unknown_0_[0x18];
    short unknown_18_;
};

struct Struct_ov000_0217c158_3 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x1e - 0x19];
    short unknown_1e_;
    unsigned char unknown_20_;
    char unknown_21_;
    signed char unknown_22_;
    char unknown_23_[0x2c - 0x23];
    short unknown_2c_;
    char unknown_2e_[0x38 - 0x2e];
    Struct_ov000_0217c158* unknown_38_;
#if defined(jpn)
    char unknown_3c_[0x430 - 0x3c];
#else
    char unknown1_3c_[0x3f0 - 0x3c];
#endif
    Struct_ov000_0217c158_2* unknown_3f0_[0x10];
};

extern "C" int func_0205dd08(Cursor0217c158* cursor);
void AdvanceWrappedAccumulator0205c4a8(struct Struct_0205c4a8* s, int delta);
int GridCursor_GetSelectedIndex(struct Struct_0205bb84* s);
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int index);
extern "C" int abs(int);

// USA: func_ov000_0217c158
extern "C" ARM int func_ov000_0217c158(Struct_ov000_0217c158_3* arg0) {
    int var0;
    int var1;
    signed char var2;
    short var3;
    int var4;
    Struct_ov000_0217c158* var5;

    var0 = func_0205dd08(arg0->unknown_38_);
    if (var0 == 0) {
        return 0;
    }
    cursor = menu->cursor;
    AdvanceWrappedAccumulator0205c4a8((struct Struct_0205c4a8*)&cursor->unk_54, delta);
    index = GridCursor_GetSelectedIndex((struct Struct_0205bb84*)&cursor->unk_54);
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)cursor->selection, index);
    switch (menu->modes[menu->depth]) {
    case 0xf:
        arg0->unknown_20_ = var1;
        break;
    case 0x10:
        arg0->unknown_1e_ = var1;
        break;
    case 0x11: {
        var4 = arg0->unknown_22_ & 3;
        var3 = var1;
        var2 = var5->unknown_68_;
        short var6 = var1 & 3;
        if ((short)abs(var6 - var4) == 1 && var4 < var6) {
            if (arg0->unknown_3f0_[var1] == 0) {
                var1 = var2 * 4;
            }
        }
        while (arg0->unknown_3f0_[var1] == 0) {
            var1--;
        }
        while (arg0->unknown_3f0_[var1] != 0) {
            if (arg0->unknown_3f0_[var1]->unknown_18_ > 0) {
                break;
            }
            var1--;
        }
        if (prev != index) {
            SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)cursor->selection, index);
            GridCursor_SetSelectedIndex(&cursor->unk_54, index);
        }
        arg0->unknown_22_ = var1;
        arg0->unknown_2c_ = -1;
        arg0->unknown_22_ = var1;
        break;
    }
    }
    return 1;
}
