#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_021696f4_1263 = 0x4eb };
enum { Enum_ov003_021696f4_1276 = 0x4f8 };
enum { Enum_ov003_021696f4_1271 = 0x4f3 };
#else
enum { Enum_ov003_021696f4_1263 = 0x4ef };
enum { Enum_ov003_021696f4_1276 = 0x4fc };
enum { Enum_ov003_021696f4_1271 = 0x4f7 };
#endif

struct GridCursor;
void GridCursor_Init(struct GridCursor* s);

void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);

void GridCursor_SetCount(struct GridCursor* s, int val);

extern "C" void GridCursor_SetSelectedIndex(void* s, int n);

struct Struct_ov003_021696f4 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov003_021696f4_2 {
    char unknown_0_[Enum_ov003_021696f4_1263];
    signed char unknown_4ef_[4];
    signed char unknown_4f3_[4];
    char unknown_4f7_[Enum_ov003_021696f4_1276 - Enum_ov003_021696f4_1271];
    struct Struct_ov003_021696f4 unknown_4fc_;
};

// USA: func_ov003_021696f4
extern "C" ARM void func_ov003_021696f4(struct Struct_ov003_021696f4_2* arg0, int arg1) {
    int var0 = arg0->unknown_4ef_[arg1];
    int var1 = 0;
    for (int var2 = 0; var2 < arg1; var2++) {
        if (arg0->unknown_4ef_[var2] < arg0->unknown_4f3_[var2]) break;
        if (var2 == arg1 - 1) var1 = 1;
    }
    if (arg1 == 0) var1 = 1;

    int var3 = 3;
    for (int var4 = 0; var4 < 4; var4++) {
        if (arg0->unknown_4f3_[var4] > 0) {
            var3 = var4;
            break;
        }
    }
    if (arg1 <= var3) var1 = 0;

    GridCursor_Init((struct GridCursor*)&self->table);
    if (isLast) {
        int limit = self->limits[index];
        GridCursor_SetDimensions((struct GridCursor*)&self->table, 1, limit + 1, 0);
        self->table.field4 = 1;
        GridCursor_SetCount((struct GridCursor*)&self->table, limit + 1);
        GridCursor_SetSelectedIndex(&self->table, limit - base);
    } else {
        GridCursor_SetDimensions((struct GridCursor*)&self->table, 1, 10, 0);
        self->table.field4 = 1;
        GridCursor_SetCount((struct GridCursor*)&self->table, 10);
        GridCursor_SetSelectedIndex(&self->table, 9 - base);
    }
}
