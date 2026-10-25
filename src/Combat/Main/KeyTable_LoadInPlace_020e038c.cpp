#include <globaldefs.h>
#include "Resource/KeyTable.h"

int UpdateNodeField4(void* a, struct Node020dfbdc* node);
extern "C" int KeyTable_LoadInPlaceWithCallback(void* table, void* fileData, void* outAlreadyRelocated, void* callback);

// Main, originally ApplyNodeUpdater020e038c (USA 0x020e038c, EUR 0x020e039c, JPN 0x020e1f60)
ARM int KeyTable_LoadInPlace(void* table, void* fileData, int size) {
    int alreadyRelocated;
    if (fileData == NULL || size == 0) return 0;
    KeyTable_LoadInPlaceWithCallback(table, fileData, &alreadyRelocated, (void*)UpdateNodeField4);
    return 1;
}
