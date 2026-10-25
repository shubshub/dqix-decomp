#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_020f12b8;
extern "C" int memcmp(const char*, const void*, int);

// Main, originally IsMatchingName0208e824 (USA 0x0208e824, EUR 0x0208e834, JPN 0x0208f134)
ARM int LootPointList_AppliesToMap(void* unused, char* str) {
    if (str[0] == 'F') {
        if (strlen(str) <= 3) return 1;
    }
    if (memcmp(str, &data_020f12b8, 6) == 0) return 1;
    return 0;
}
