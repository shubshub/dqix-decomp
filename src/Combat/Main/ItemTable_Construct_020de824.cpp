#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally ZeroInitReturn020de824 (USA 0x020de824, EUR 0x020de834, JPN 0x020e01a0)
extern "C" ARM void* ItemTable_Construct(void* obj) {
    memset(obj, 0, 0x14);
    *((unsigned char*)obj + 0x14) = 0;
    return obj;
}
