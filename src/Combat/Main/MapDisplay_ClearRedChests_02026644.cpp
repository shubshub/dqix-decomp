#include <globaldefs.h>
#include "NitroSDK/Memory.h"

// MapDisplay offsets (header: field12, refreshRecords, field9ba, and the red chest list at 0x780; see
// MapDisplay_SetMapKey and func_02026780)
#if defined(jpn)
enum { kRedChestsLoadedOffset = 0x6cd, kRedChestsShownOffset = 0x90e, kRedChestCountOffset = 0x6d4, kRedChestsOffset = 0x6d8 };
#else
enum { kRedChestsLoadedOffset = 0x779, kRedChestsShownOffset = 0x9ba, kRedChestCountOffset = 0x780, kRedChestsOffset = 0x784 };
#endif
enum {
    kMapChangedOffset = 0x12,
    kRedChestsSize = 20 * 0x1c, // func_020269e4 keeps up to 20 records of 0x1c bytes
};

// Empties the red chest list; after a map change also forgets that they were loaded and shown
// Main, originally ClearRecords02026644 (USA 0x02026644, EUR 0x02026654, JPN 0x02025fa8)
extern "C" ARM void MapDisplay_ClearRedChests(char* mapDisplay) {
    if (((unsigned char*)mapDisplay)[kMapChangedOffset] != 0) {
        mapDisplay[kRedChestsLoadedOffset] = 0;
        mapDisplay[kRedChestsShownOffset] = 0;
    }
    mapDisplay[kRedChestCountOffset] = 0;
    VectorizedMemset(mapDisplay + kRedChestsOffset, 0, kRedChestsSize);
}
