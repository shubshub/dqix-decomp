#include <globaldefs.h>

struct Struct_0205bb84 {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int* field24;
    int* field28;
    int* field2C;
};

// Main, originally func_0205bb84 (USA 0x0205bb84, EUR 0x0205bb94, JPN 0x0205cee4)
ARM int GridCursor_GetSelectedIndex(struct Struct_0205bb84* s) {
    int p = *s->field24 * *s->field28 + *s->field2C;
    int q = s->field14 * s->fieldC * s->field8;
    return (short)q + (short)p;
}
