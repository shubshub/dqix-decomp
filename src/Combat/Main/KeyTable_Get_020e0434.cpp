#include <globaldefs.h>

struct Container020e0310;
int LookupFieldByKey020e0440(struct Container020e0310 *c, int key);

// Main, originally GetFieldByKey020e0434 (USA 0x020e0434, EUR 0x020e0444, JPN 0x020e2070)
ARM int KeyTable_Get(struct Container020e0310 *c, int key) {
    return LookupFieldByKey020e0440(c, key);
}
