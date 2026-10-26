#include <globaldefs.h>

struct Struct020dfc40;
void KeyTable_Reset(struct Struct020dfc40* p);

// Main, originally ResetAndReturnSelf020dfc2c (USA 0x020dfc2c, EUR 0x020dfc3c, JPN 0x020e1800)
ARM void* KeyTable_Construct(void* p) {
    KeyTable_Reset((struct Struct020dfc40*)p);
    return p;
}
