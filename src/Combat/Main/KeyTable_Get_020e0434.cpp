#include <globaldefs.h>

// The struct tag stays: this function's and KeyTable_Lookup's C++ symbols are mangled with it.
struct Container020e0310;
typedef struct Container020e0310 KeyTable;
extern "C" int KeyTable_Lookup(KeyTable *table, int key);

// Main, originally GetFieldByKey020e0434 (USA 0x020e0434, EUR 0x020e0444, JPN 0x020e2070)
extern "C" ARM int KeyTable_Get(KeyTable *table, int key) {
    return KeyTable_Lookup(table, key);
}
