#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"

int ZoneId_IsMainGrottoFloor(int id);
int ZoneId_IsGrottoBossFloor(int x);

// The path formats under data_020ef116 ("data/map"): "%s/Z0%dM01.ambl" for a zone 40001-40096 (ZoneId_IsMainGrottoFloor) and
// "%s/Z0%dM99.ambl" for one 41101-41505 (ZoneId_IsGrottoBossFloor), by grotto environment; "%s/%s.ambl" by the zone
// table entry's map name otherwise
extern char data_020ef106;
extern char data_020ef116;
extern char data_020ef11f;
extern char data_020ef12f;

// The range the Z0%dM01 path clamps GetActiveGrottoEnviron to (0 becomes 1, above 5 becomes 5)
enum { kFirstGrottoEnvironment = 1, kLastGrottoEnvironment = 5 };

// USA: func_0201403c  (semantic: Format0201403c)
// Main, originally Zone3D::LoadMapAMBL_0201403c (USA 0x0201403c, EUR 0x0201404c, JPN 0x02013e08)
ARM void Zone3D::QueueLoadMapAMBL() {
    Zone3D* zone = this;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char path[0x14];

    if (ZoneId_IsMainGrottoFloor(zone->currentZoneID_)) {
        ActiveGrottoClass* grotto = &zone->grotto_;
        int environment = grotto->GetActiveGrottoEnviron();
        if (environment == 0) environment = kFirstGrottoEnvironment;
        if (environment > kLastGrottoEnvironment) environment = kLastGrottoEnvironment;
        sprintf(path, &data_020ef106, &data_020ef116, environment);
    } else if (ZoneId_IsGrottoBossFloor(zone->currentZoneID_)) {
        ActiveGrottoClass* grotto = &zone->grotto_;
        int environment = grotto->GetActiveGrottoEnviron();
        sprintf(path, &data_020ef11f, &data_020ef116, environment);
    } else {
        sprintf(path, &data_020ef12f, &data_020ef116, zone->pUnknownStruct_8_->mapShortName_);
    }

    zone->mapAMBLLoadHandle_ = loader->QueueLoadFile(path, NULL);
}
