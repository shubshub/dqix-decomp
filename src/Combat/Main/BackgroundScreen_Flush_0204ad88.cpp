#include <globaldefs.h>
#include "std_library_functions.h"

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

// Main, originally CopyWordAndFlushCache0204ad88 (USA 0x0204ad88, EUR 0x0204ad98, JPN 0x0204bba8)
ARM void BackgroundScreen_Flush(void* a, void* b) {
    memcpy((char*)a + 8, (char*)b + 0xc, 4);
    CleanInvalidateCacheRange((const void*)((int)((char*)b + 0x10)), *(int*)((char*)a + 8));
}
