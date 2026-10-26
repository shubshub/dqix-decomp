#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "std_library_functions.h"
#include "World/Zone3D.h"

#if defined(jpn)
#define data_020ef19f data_020ef0db
#define data_020ef1a9 data_020ef0e5
#define data_020ef1b3 data_020ef0ef
#define data_020ef1bd data_020ef0f9
#define data_020ef1c7 data_020ef103
#endif
extern char data_020ef19f;  // "Z0%dM0100": a main grotto floor's BATS name, floors 1-4 (%d: the environment)
extern char data_020ef1a9;  // "Z0%dM0101": floors 5-8
extern char data_020ef1b3;  // "Z0%dM0102": floors 9-12
extern char data_020ef1bd;  // "Z0%dM0103": floors 13-16
extern char data_020ef1c7;  // "%s/ats_%c.ambl"
extern char data_020ef116;  // "data/map"

// Main, originally Zone3D::QueueLoadATS_AMBL_02014b04 (USA 0x02014b04, EUR 0x02014b14, JPN 0x020148d0)
extern "C" ARM void _ZN6Zone3D17QueueLoadATS_AMBLEv(Zone3D* zone) {
    if (zone->isInMainGrottoFloor_23b8_) {
        ActiveGrottoClass* grotto = zone->GetActiveGrotto();
        int environment = grotto->GetActiveGrottoEnviron();
        if (environment == 0) environment = 1;

        signed char floor = zone->currentGrottoFloor_23ba_;
        if (floor <= 0x4) {
            sprintf(zone->substruct_c_.buffer1, &data_020ef19f, environment);
        } else if (floor <= 0x8) {
            sprintf(zone->substruct_c_.buffer1, &data_020ef1a9, environment);
        } else if (floor <= 0xc) {
            sprintf(zone->substruct_c_.buffer1, &data_020ef1b3, environment);
        } else if (floor <= 0x10) {
            sprintf(zone->substruct_c_.buffer1, &data_020ef1bd, environment);
        }
    }

    if (strlen(zone->substruct_c_.buffer1) == 0) {
        zone->QueueLoadMapAMDJ();
        return;
    }

    int handle = (int)BackgroundLoader::GetInstance();
    signed char letter = zone->substruct_c_.buffer1[0];
    char path[0x28];
    sprintf(path, &data_020ef1c7, &data_020ef116, letter);
    zone->atsAMBLLoadHandle_ = ((BackgroundLoader*)(handle))->QueueLoadFile((const char*)((int)path), (SafeAllocator*)(0));
}
