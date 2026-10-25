#include <globaldefs.h>

// Main, originally CompareStrings_020d3018 (USA 0x020d3018, EUR 0x020d3028, JPN 0x020d4a7c)
ARM int STD_CompareString(const char* a, const char* b) {
    while (*a == *b && *a != 0) {
        a++;
        b++;
    }
    return *a - *b;
}
