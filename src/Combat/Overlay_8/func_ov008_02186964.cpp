#include <globaldefs.h>

struct GridCursor;

extern "C" void GridCursor_Init(GridCursor* cursor);
extern "C" void GridCursor_SetDimensions(GridCursor* s, int a, int b, int mode);
extern "C" void GridCursor_SetCount(GridCursor* s, int val);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);

struct Struct_ov008_02186964 {
    int field0;
    int field4;
};

struct Struct_ov008_02186964_2 {
    char pad0[0x744];
    unsigned char items[8];
    unsigned char itemCount;
    char pad1[0x750 - 0x74d];
    Struct_ov008_02186964 cursor;
    char pad2[0xb10 - 0x758];
    signed char state;
    char pad3[0xb18 - 0xb11];
    unsigned int flags;
    char pad4[0xb28 - 0xb1c];
    unsigned char selected;
    unsigned char unknown_b29_;
};

// USA: func_ov008_02186964
extern "C" ARM void func_ov008_02186964(Struct_ov008_02186964_2* self) {
    int visible;
    int columns;
    int index;
    int count;
    columns = 1;
    count = columns;
    visible = columns;
    index = 0;
    if (self->state == 3) {
        columns = 1;
        count = self->itemCount;
        visible = count;
        for (int i = 0; i < count; i++) {
            if (self->selected == self->items[i]) {
                index = i;
                break;
            }
        }
        if (count > 6) {
            self->flags |= 0x10;
            if (index > self->unknown_b29_ + 5) {
                self->unknown_b29_ = index - 5;
            } else if (index < self->unknown_b29_) {
                self->unknown_b29_ = index;
            }
        }
    }
    GridCursor_Init((GridCursor*)&self->cursor);
    GridCursor_SetDimensions((GridCursor*)&self->cursor, columns, count, 0);
    GridCursor_SetCount((GridCursor*)&self->cursor, visible);
    self->cursor.field4 = columns;
    GridCursor_SetSelectedIndex(&self->cursor, index);
}
