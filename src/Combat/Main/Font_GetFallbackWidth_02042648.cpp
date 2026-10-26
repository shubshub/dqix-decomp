#include <globaldefs.h>

extern int data_020e7a94[];

// Main, originally GetWordFromTable02042648 (USA 0x02042648, EUR 0x02042658; JPN not identified)
extern "C" ARM int Font_GetFallbackWidth(int idx) {
    return data_020e7a94[idx];
}
