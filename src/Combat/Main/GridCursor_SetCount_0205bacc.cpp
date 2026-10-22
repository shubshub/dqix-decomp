#include <globaldefs.h>

struct Struct_0205bb84;
int GridCursor_GetSelectedIndex(struct Struct_0205bb84* s);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);

struct Node0205bacc {
    int field0;
};

// Main, originally SetField0AndPropagate0205bacc (USA 0x0205bacc, EUR 0x0205badc, JPN 0x0205ce2c)
ARM void GridCursor_SetCount(struct Node0205bacc* s, int val) {
    if (val < 0) return;
    s->field0 = val;
    if (GridCursor_GetSelectedIndex((struct Struct_0205bb84*)s) < val) return;
    GridCursor_SetSelectedIndex(s, val - 1);
}
