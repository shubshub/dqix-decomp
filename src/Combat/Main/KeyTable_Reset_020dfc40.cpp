#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj020dfe88;
int ResetHandleState020dfe88(struct Obj020dfe88*);

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    int field_10;
};

// Main, originally ResetStruct020dfc40 (USA 0x020dfc40, EUR 0x020dfc50, JPN 0x020e1814)
ARM void KeyTable_Reset(Struct020dfc40* p) {
    memset(p, 0, 0xc);
    p->field_c = -1;
    p->field_10 = -1;
    ResetHandleState020dfe88((struct Obj020dfe88*)p);
}
