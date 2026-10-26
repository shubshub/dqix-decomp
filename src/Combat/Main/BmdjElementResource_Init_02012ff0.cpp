#include "World/ZoneResourceInitialization.h"
#include <globaldefs.h>


// Main, originally InitTrackerFields02012ff0 (USA 0x02012ff0, EUR 0x02013000, JPN 0x02012db8)
extern "C" ARM void BmdjElementResource_Init(struct Struct02012ff0* tracker) {
    tracker->field0 = -1;
    tracker->field2 = 0;
    tracker->field4 = 0;
    tracker->field8 = 0;
    tracker->fieldc = 0;
    tracker->field10 = 0;
    tracker->field14 = 0;
}
