#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally InitStruct0205a444 (USA 0x0205a444, EUR 0x0205a454, JPN 0x0205b7e0)
ARM void SpriteContext_Init(char* obj) {
    memset(obj, 0, 0x24);
    memset(obj + 0x24, 0, 0x14);
    *(int*)(obj + 0x38) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    *(int*)(obj + 0x48) = 0;
    *(short*)(obj + 0x4c) = 0;
    *(short*)(obj + 0x4e) = 0;
    *(int*)(obj + 0x3c) = 0;
    *(char*)(obj + 0x50) = 1;
}
