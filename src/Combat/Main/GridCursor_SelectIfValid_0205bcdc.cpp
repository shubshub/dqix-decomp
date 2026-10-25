#include <globaldefs.h>

extern "C" void GridCursor_SetSelectedIndex(void*, int);

struct Struct_0205bcdc {
    int field0;
    char pad[0x2c];
    int field30;
};

// Main, originally SetIndexIfValid0205bcdc (USA 0x0205bcdc, EUR 0x0205bcec, JPN 0x0205d03c)
ARM void GridCursor_SelectIfValid(struct Struct_0205bcdc* s, int index) {
    if (index < 0) return;
    if (s->field0 <= index) return;
    s->field30 = -1;
    GridCursor_SetSelectedIndex(s, index);
}
