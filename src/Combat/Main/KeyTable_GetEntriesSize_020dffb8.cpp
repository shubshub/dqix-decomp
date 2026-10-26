#include <globaldefs.h>

struct Header020dffb8 {
    unsigned int count : 12;
    unsigned int rest : 20;
};

// Main, originally GetArrayByteSize020dffb8 (USA 0x020dffb8, EUR 0x020dffc8, JPN 0x020e1b8c)
extern "C" ARM int KeyTable_GetEntriesSize(struct Header020dffb8 *obj) {
    return obj->count * 8;
}
