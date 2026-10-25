#include <globaldefs.h>

// Main, originally SetFieldAt0x30_0205bc24 (USA 0x0205bc24, EUR 0x0205bc34, JPN 0x0205cf84)
ARM void TouchGrid_SetTouchedCell(void* obj, int value) {
    *(int*)((char*)obj + 0x30) = value;
}
