#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "std_library_functions.h"

int KeyTable_EndLoad(struct Struct020dfc40*);

// Main, originally ResetStruct020dfc40 (USA 0x020dfc40, EUR 0x020dfc50, JPN 0x020e1814)
ARM void KeyTable_Reset(Struct020dfc40* table) {
    memset(table, 0, 0xc);
    table->singleKey = -1;
    table->loadTask = -1;
    KeyTable_EndLoad(table);
}
