#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally ZeroInit020de848 (USA 0x020de848, EUR 0x020de858, JPN 0x020e01c4)
extern "C" ARM void ItemTable_Init(void* obj) {
    memset(obj, 0, 0x14);
    *((unsigned char*)obj + 0x14) = 0;
}
