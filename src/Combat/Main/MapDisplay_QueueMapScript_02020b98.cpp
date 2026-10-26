#include <globaldefs.h>
// data_020ef460 is the list of map display archive paths; "data/pack_lv5/minimap.gp2" is its third entry in usa
// (after mapname_<LG>.bin and data/map/mapname.gp2); jpn, which has no map name file, reads the second
#if defined(jpn)
enum { kMinimapArchiveOffset = 4 };
#else
enum { kMinimapArchiveOffset = 8 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"
#include "World/Zone3D.h"

extern "C" Zone3D* Zone3D_GetInstance(void);
extern int data_020ef460;
extern char data_020ef587; // "%s.bmmp"
extern char data_020ef58f; // "T99MAP01"

// Main, originally FormatAndCopyNames02020b98 (USA 0x02020b98, EUR 0x02020ba8, JPN 0x020207b4)
ARM int MapDisplay_QueueMapScript(void* mapDisplay) {
    char fileName[0x20];
    int loader = (int)BackgroundLoader::GetInstance();
    Zone3D* zone = Zone3D_GetInstance();
    sprintf(fileName, &data_020ef587, zone->substruct_c_.buffer3);
    int task = ((BackgroundLoader*)(loader))->QueueLoadFileInGP2((const char*)(*(int*)((char*)&data_020ef460 + kMinimapArchiveOffset)), (const char*)((int)fileName), (SafeAllocator*)(0));
    strcpy((char*)((MapDisplay*)mapDisplay)->bytesa35, zone->substruct_c_.buffer3);
    strcpy(((MapDisplay*)mapDisplay)->name, &data_020ef58f);
    return task;
}
