#include <globaldefs.h>
#include "Resource/KeyTable.h"

extern "C" int KeyTable_EndLoad(struct Struct020dfc40*);

extern "C" void KeyTable_Reset(struct Struct020dfc40* p);

// Main, originally ResetAndDetach020dfc6c (USA 0x020dfc6c, EUR 0x020dfc7c, JPN 0x020e1840)
extern "C" ARM void KeyTable_Destroy(struct Struct020dfc40* p) {
    KeyTable_EndLoad(p);
    KeyTable_Reset(p);
}
