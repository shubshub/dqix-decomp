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
extern "C" void GridCursor_Init(struct GridCursor* s);

extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);

extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);

extern "C" void GridCursor_SetSelectedIndex(void* s, int n);

struct Struct_ov003_021696f4 {
    int field0;
    int field4;
};

struct Struct_ov003_021696f4_2 {
    char pad0[Enum_ov003_021696f4_1263];
    signed char values[4];
    signed char unknown_4f3_[4];
    char unknown_4f7_[Enum_ov003_021696f4_1276 - Enum_ov003_021696f4_1271];
    struct Struct_ov003_021696f4 table;
};

// USA: func_ov003_021696f4
extern "C" ARM void func_ov003_021696f4(struct Struct_ov003_021696f4_2* self, int index) {
    int base = self->values[index];
    int var1 = 0;
    for (int i = 0; i < index; i++) {
        if (self->values[i] < self->unknown_4f3_[i]) break;
        if (i == index - 1) var1 = 1;
    }
    if (index == 0) var1 = 1;

    int first = 3;
    for (int i = 0; i < 4; i++) {
        if (self->unknown_4f3_[i] > 0) {
            first = i;
            break;
        }
    }
    if (index <= first) var1 = 0;

    GridCursor_Init((struct GridCursor*)&self->table);
    if (var1) {
        int limit = self->unknown_4f3_[index];
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
