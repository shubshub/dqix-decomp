#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02169594_232 = 0xe4 };
enum { Enum_ov003_02169594_404 = 0x190 };
enum { Enum_ov003_02169594_392 = 0x184 };
enum { Enum_ov003_02169594_1261 = 0x4e9 };
enum { Enum_ov003_02169594_405 = 0x191 };
#else
enum { Enum_ov003_02169594_232 = 0xe8 };
enum { Enum_ov003_02169594_404 = 0x194 };
enum { Enum_ov003_02169594_392 = 0x188 };
enum { Enum_ov003_02169594_1261 = 0x4ed };
enum { Enum_ov003_02169594_405 = 0x195 };
#endif

struct Struct_0205ba68;
struct Struct_0205bacc;
struct Struct_0205bcdc;

void GridCursor_SetDimensions(struct Struct_0205ba68* s, int a, int b, int mode);
void GridCursor_SetCount(struct Node0205bacc* s, int val);
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);

struct Struct_ov003_02169594 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x3c - 0x8];
    unsigned char unknown_3c_;
    char unknown_3d_[0x50 - 0x3d];
};

struct Struct_ov003_02169594_2 {
    char unknown_0_[Enum_ov003_02169594_232];
    struct Struct_ov003_02169594 unknown_e8_[2];
    char unknown_188_[Enum_ov003_02169594_404 - Enum_ov003_02169594_392];
    unsigned char unknown_194_;
    char unknown_195_[Enum_ov003_02169594_1261 - Enum_ov003_02169594_405];
    signed char unknown_4ed_;
    signed char unknown_4ee_;
};

static inline struct Struct_ov003_02169594* inline_ov003_02169594(struct Struct_ov003_02169594_2* arg0, int arg1) { return &arg0->unknown_e8_[arg1]; }

// USA: func_ov003_02169594
extern "C" ARM void func_ov003_02169594(struct Struct_ov003_02169594_2* arg0) {
    int var0;
    int var1;
    int var2;
    int var3;
    int var4;

    switch (arg0->unknown_194_) {
    case 1:
        var0 = 1;
        var1 = 3;
        var2 = 3;
        var3 = 1;
        var4 = arg0->unknown_4ed_;
        break;
    case 2:
        var4 = arg0->unknown_4ee_;
        var0 = 4;
        var1 = 1;
        var2 = 4;
        var3 = 1;
        break;
    }

    GridCursor_SetDimensions((struct Struct_0205ba68*)GetGrid(self, 0), cols, rows, 0);
    GridCursor_SetDimensions((struct Struct_0205ba68*)GetGrid(self, 1), cols, rows, 0);
    GridCursor_SetCount((struct Node0205bacc*)GetGrid(self, 0), count);
    GridCursor_SetCount((struct Node0205bacc*)GetGrid(self, 1), count);
    GetGrid(self, 0)->field4 = field4;
    GetGrid(self, 1)->field4 = field4;
    SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)GetGrid(self, 0), index);
    GridCursor_SetSelectedIndex(GetGrid(self, 1), index);
    struct Grid02169594* grid = GetGrid(self, 1);
    grid->field3c = 0;
}
