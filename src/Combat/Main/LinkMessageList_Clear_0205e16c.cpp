#include <globaldefs.h>

struct Struct0205e16c {
    int field0;
    int field4;
    int field8;
};

// Main, originally ClearThreeWords0205e16c (USA 0x0205e16c, EUR 0x0205e17c, JPN 0x0205f458)
ARM void LinkMessageList_Clear(struct Struct0205e16c* p) {
    p->field0 = 0;
    p->field4 = 0;
    p->field8 = 0;
}
