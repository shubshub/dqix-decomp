#include <globaldefs.h>

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Node0205bacc;

void GridCursor_Init(Struct_0205bef8* cursor);
void GridCursor_SetDimensions(Struct_0205ba68* s, int a, int b, int mode);
void GridCursor_SetCount(Node0205bacc* s, int val);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);

struct Cursor02186964 {
    int field0;
    int field4;
};

struct Menu02186964 {
    char pad0[0x744];
    unsigned char items[8];
    unsigned char itemCount;
    char pad1[0x750 - 0x74d];
    Cursor02186964 cursor;
    char pad2[0xb10 - 0x758];
    signed char state;
    char pad3[0xb18 - 0xb11];
    unsigned int flags;
    char pad4[0xb28 - 0xb1c];
    unsigned char selected;
    unsigned char scrollTop;
};

// USA: func_ov008_02186964
extern "C" ARM void func_ov008_02186964(Menu02186964* self) {
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
            if (index > self->scrollTop + 5) {
                self->scrollTop = index - 5;
            } else if (index < self->scrollTop) {
                self->scrollTop = index;
            }
        }
    }
    GridCursor_Init((Struct_0205bef8*)&self->cursor);
    GridCursor_SetDimensions((Struct_0205ba68*)&self->cursor, columns, count, 0);
    GridCursor_SetCount((Node0205bacc*)&self->cursor, visible);
    self->cursor.field4 = columns;
    GridCursor_SetSelectedIndex(&self->cursor, index);
}
