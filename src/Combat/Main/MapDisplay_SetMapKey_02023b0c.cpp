#include <globaldefs.h>
// MapDisplay fields (header: headerName, field12, refreshRecords, field9ba). The red chest markers
// (MapDisplay_LoadRedChests, MapDisplay_DrawRedChestMarkers) are per map, so a new map name clears both red chest flags.
#if defined(jpn)
enum { kRedChestsLoadedOffset = 0x6cd };
enum { kRedChestsShownOffset = 0x90e };
#else
enum { kRedChestsLoadedOffset = 0x779 };
enum { kRedChestsShownOffset = 0x9ba };
#endif
enum { kMapNameOffset = 2, kMapChangedOffset = 0x12 };

#include "std_library_functions.h"

// Main, originally UpdateStringField02023b0c (USA 0x02023b0c, EUR 0x02023b1c, JPN 0x020234d4)
ARM void MapDisplay_SetMapKey(char* mapDisplay, char* mapName) {
    if (mapName == NULL) return;
    if (strcmp(mapName, mapDisplay + kMapNameOffset) == 0) {
        ((unsigned char*)mapDisplay)[kMapChangedOffset] = 0;
    } else {
        ((unsigned char*)mapDisplay)[kMapChangedOffset] = 1;
    }
    if (((unsigned char*)mapDisplay)[kMapChangedOffset] != 0) {
        mapDisplay[kRedChestsLoadedOffset] = 0;
        mapDisplay[kRedChestsShownOffset] = 0;
    }
    strcpy(mapDisplay + kMapNameOffset, mapName);
}
