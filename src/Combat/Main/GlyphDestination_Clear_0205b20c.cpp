#include <globaldefs.h>

struct S_b20c {
    int field0;
    int field4;
    unsigned char field8;
};

// Main, originally ClearTwoWordsAndByte_0205b20c (USA 0x0205b20c, EUR 0x0205b21c, JPN 0x0205c5a8)
ARM void GlyphDestination_Clear(struct S_b20c* obj) {
    obj->field0 = 0;
    obj->field4 = 0;
    obj->field8 = 0;
}
