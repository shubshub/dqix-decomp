#include <globaldefs.h>
#include "Resource/ItemTable.h"
#include "std_library_functions.h"

int ItemTable_LoadInPlace(void* table, void* itemData, void* size);
extern "C" int ItemTable_CopyIds(void* allocator, void* dest, void* source, void* keys, short keyCount);

// Main, originally func_020de9a4 (USA 0x020de9a4, EUR 0x020de9b4, JPN 0x020e0320)
extern "C" ARM int ItemTable_LoadIds(ItemTable* table, void* allocator, void* itemData, void* size, void* ids, unsigned short count) {
    memset(table, 0, 0x14);
    if (allocator == 0 || itemData == 0 || size == 0 || ids == 0 || count == 0) {
        return 0;
    }
    char fileTable[0x14];
    ItemTable_LoadInPlace(fileTable, itemData, size);
    int result = ItemTable_CopyIds(allocator, table, fileTable, ids, count);
    unsigned char useBinarySearch;
    if (result != 0 && table->count > 1) {
        useBinarySearch = 1;
    } else {
        useBinarySearch = 0;
    }
    table->useBinarySearch = useBinarySearch;
    return result;
}
