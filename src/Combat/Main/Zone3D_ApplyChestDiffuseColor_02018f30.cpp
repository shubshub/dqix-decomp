#include <globaldefs.h>
#include "World/Zone3D.h"


// Main, originally NotifyActiveSlots02018f30 (USA 0x02018f30, EUR 0x02018f40, JPN 0x02018cd0)
ARM void Zone3D_ApplyChestDiffuseColor(unsigned char* zoneBytes) {
    Zone3D* zone = (Zone3D*)zoneBytes;
    int i;
    for (i = 0; i < 2; i++) {
        NSBXXInternalModel* model = zone->models_498_[i].rawInternalModel_;
        if (model != NULL) {
            NSBXX_Model_SetDiffuseReflectionColor(model, (unsigned short)zone->substruct_c_.unknown_2a_);
        }
    }
}
