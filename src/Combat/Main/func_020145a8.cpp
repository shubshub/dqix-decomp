#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"

extern "C" int ZoneId_IsMainGrottoFloor(int id);
extern "C" int ZoneId_IsGrottoBossFloor(int id);

#if defined(jpn)
#define data_020ef156 data_020ef092
#define data_020ef166 data_020ef0a2
#define data_020ef176 data_020ef0b2
#define data_020ef182 data_020ef0be
#endif

extern char data_020ef116[];
extern char data_020ef156[];
extern char data_020ef166[];
extern char data_020ef176[];
extern char data_020ef182[];
extern char data_020ef18e[];

// data_020ef116 is "data/map"; the formats: "%s/Z0%dM01.amdj", "%s/Z0%dM99.amdj" (by grotto environment),
// "%s/%sb.amdj", "%s/%sa.amdj", "%s/%s.amdj" (by the zone table entry's map name)

// The range the Z0%dM01 path clamps GetActiveGrottoEnviron to (0 becomes 1, above 5 becomes 5)
enum { kFirstGrottoEnvironment = 1, kLastGrottoEnvironment = 5 };

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: QueueLoadMapAMDJ
// Main, originally Zone3D::LoadMapAMDJ_020145a8 (USA 0x020145a8, EUR 0x020145b8, JPN 0x02014374)
void Zone3D::QueueLoadMapAMDJ() {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char path[0x14];

    if (ZoneId_IsMainGrottoFloor(currentZoneID_)) {
        int environment = grotto_.GetActiveGrottoEnviron();
        if (environment == 0) environment = kFirstGrottoEnvironment;
        if (environment > kLastGrottoEnvironment) environment = kLastGrottoEnvironment;
        sprintf(path, data_020ef156, data_020ef116, environment);
    } else if (ZoneId_IsGrottoBossFloor(currentZoneID_)) {
        int environment = grotto_.GetActiveGrottoEnviron();
        sprintf(path, data_020ef166, data_020ef116, environment);
    } else if (currentZoneID_ == 10000 || currentZoneID_ == 10100) {
        // these two zones' maps come in two parts: "<name>b.amdj" first, then "<name>a.amdj" (unknown_42c_ counts the
        // parts queued; UnpackMapAMDJ queues the second)
        if (unknown_42c_ == 0) {
            sprintf(path, data_020ef176, data_020ef116, pUnknownStruct_8_->mapShortName_);
            unknown_42c_++;
        } else if (unknown_42c_ == 1) {
            sprintf(path, data_020ef182, data_020ef116, pUnknownStruct_8_->mapShortName_);
            unknown_42c_++;
        }
    } else {
        sprintf(path, data_020ef18e, data_020ef116, pUnknownStruct_8_->mapShortName_);
    }

    mapAMDJLoadHandle_ = loader->QueueLoadFile(path, NULL);
}
