#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally Clear12Bytes020e46c4 (USA 0x020e46c4, EUR 0x020e46d4; JPN not identified)
ARM void* NameText_Clear(void* p) {
    return memset(p, 0, 0xc);
}
