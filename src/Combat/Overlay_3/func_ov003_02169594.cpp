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

struct GridCursor;
struct Struct_0205bcdc;

extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);
extern "C" void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);

struct Struct_ov003_02169594 {
    int field0;
    int field4;
    char pad8[0x3c - 0x8];
    unsigned char field3c;
    char unknown_3d_[0x50 - 0x3d];
};

struct Struct_ov003_02169594_2 {
    char pad0[Enum_ov003_02169594_232];
    struct Struct_ov003_02169594 grids[2];
    char unknown_188_[Enum_ov003_02169594_404 - Enum_ov003_02169594_392];
    unsigned char layout;
    char unknown_195_[Enum_ov003_02169594_1261 - Enum_ov003_02169594_405];
    signed char unknown_4ed_;
    signed char unknown_4ee_;
};

static inline struct Struct_ov003_02169594* GetGrid(struct Struct_ov003_02169594_2* ctx, int i) { return &ctx->grids[i]; }

// USA: func_ov003_02169594
extern "C" ARM void func_ov003_02169594(struct Struct_ov003_02169594_2* self) {
    int cols;
    int rows;
    int count;
    int field4;
    int index;

    switch (self->layout) {
    case 1:
        cols = 1;
        rows = 3;
        count = 3;
        field4 = 1;
        index = self->unknown_4ed_;
        break;
    case 2:
        index = self->unknown_4ee_;
        cols = 4;
        rows = 1;
        count = 4;
        field4 = 1;
        break;
    }

    GridCursor_SetDimensions((struct GridCursor*)GetGrid(self, 0), cols, rows, 0);
    GridCursor_SetDimensions((struct GridCursor*)GetGrid(self, 1), cols, rows, 0);
    GridCursor_SetCount((struct GridCursor*)GetGrid(self, 0), count);
    GridCursor_SetCount((struct GridCursor*)GetGrid(self, 1), count);
    GetGrid(self, 0)->field4 = field4;
    GetGrid(self, 1)->field4 = field4;
    GridCursor_SelectIfValid((struct Struct_0205bcdc*)GetGrid(self, 0), index);
    GridCursor_SetSelectedIndex(GetGrid(self, 1), index);
    struct Struct_ov003_02169594* grid = GetGrid(self, 1);
    grid->field3c = 0;
}
