#include <globaldefs.h>
#include "World/Zone3D.h"

// A chest's ZoneChestRenderRecord (this file's copy of the fields it uses)
struct UpdateStateStruct {
    Vector3i position;
    short angleY;
    short lidAngle;
    unsigned short counter;
    short iconTask;
    unsigned char opener;
    char pad15;
    unsigned char state;            // ZoneChestState
    unsigned char kind;
    unsigned char special;
};

// Main, originally UpdateActivationState_02015a98 (USA 0x02015a98, EUR 0x02015aa8, JPN 0x02015864)
ARM void ZoneChest_StartOpening(UpdateStateStruct* chest, int opener, int clearSpecial, int force) {
    if (chest->state == ZoneChestState_Closed) {
        chest->state = ZoneChestState_Opening;
        chest->opener = opener;
        chest->counter = 0;
    } else if (force) {
        chest->state = ZoneChestState_Opening;
        chest->opener = opener;
        chest->counter = 0;
    }
    if (clearSpecial) {
        chest->special = 0;
    }
}
