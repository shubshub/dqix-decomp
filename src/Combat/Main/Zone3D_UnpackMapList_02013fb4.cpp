#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "World/Zone3D.h"

struct StreamHeader;

extern "C" void MapListScript_LookUpZone(int zoneId, void* mapList, StreamHeader* data, int size);

// mapListLoadHandle_: data/map/maplist9.bin, which Zone3D::SwitchZone queued

// Main, originally ApplyAndClearPendingEntry02013fb4 (USA 0x02013fb4, EUR 0x02013fc4, JPN 0x02013d80)
extern "C" ARM int Zone3D_UnpackMapList(Zone3D* zone) {
    if (zone->mapListLoadHandle_ < 0)
        return 1;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(zone->mapListLoadHandle_))
        return 0;

    void* fileData;
    unsigned int fileSize;
    loader->GetLoadedFileByID(zone->mapListLoadHandle_, &fileData, &fileSize);
    MapListScript_LookUpZone(zone->currentZoneID_, &zone->substruct_c_,
                 static_cast<StreamHeader*>(fileData), fileSize);
    loader->RemoveTask(zone->mapListLoadHandle_);
    zone->mapListLoadHandle_ = -1;
    zone->QueueLoadMapAMBL();
    return 1;
}
