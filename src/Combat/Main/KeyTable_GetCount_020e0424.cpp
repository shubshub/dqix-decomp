#include <globaldefs.h>

// The struct tag stays: this function's C++ symbol is mangled with it.
struct Header020e0424 {
    unsigned int count : 12;
    unsigned int textSize : 19;
    unsigned int relocated : 1;
};
typedef struct Header020e0424 KeyTableHeader;

// Main, originally GetLow12Bits020e0424 (USA 0x020e0424, EUR 0x020e0434; JPN not identified)
ARM unsigned int KeyTable_GetCount(KeyTableHeader* header) {
    return header->count;
}
