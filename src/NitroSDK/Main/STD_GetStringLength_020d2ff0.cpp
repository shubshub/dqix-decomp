#include <globaldefs.h>

// Main, originally StringLength_020d2ff0 (USA 0x020d2ff0, EUR 0x020d3000, JPN 0x020d4a54)
ARM int STD_GetStringLength(const char* s) {
    int i = 0;
    if (s[i] != 0) {
        do {
            i++;
        } while (s[i] != 0);
    }
    return i;
}
