#include <globaldefs.h>

extern int data_02104b6c;

// Main, originally GetData02104b6c_02039e70 (USA 0x02039e70, EUR 0x02039e80, JPN 0x020398c8)
ARM void* NumberPopups_GetInstance(void) {
    return &data_02104b6c;
}
