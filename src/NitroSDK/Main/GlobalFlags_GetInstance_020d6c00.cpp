#include <globaldefs.h>

extern int data_02114e04;

// Main, originally GetDataPtr02114e04_020d6c00 (USA 0x020d6c00, EUR 0x020d6c10, JPN 0x020d8608)
ARM void* GlobalFlags_GetInstance(void) {
    return (void*)&data_02114e04;
}
