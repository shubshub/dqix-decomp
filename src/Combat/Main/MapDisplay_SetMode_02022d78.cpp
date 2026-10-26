#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"


extern "C" void MapDisplay_CancelLoading(void* obj);

struct Obj02022d78 {
#if defined(jpn)
    char pad[0x915];
#else
    char pad[0x9c1];
#endif
    unsigned char mode;        // what MapDisplay_RunModeLoader loads
    unsigned char loadStage;
    unsigned char modeLoading;
    char pad2[0xa34 - 0x9c4];
    unsigned char previousMode;
};

// Main, originally SetActiveModeSavingPrevious02022d78 (USA 0x02022d78, EUR 0x02022d88, JPN 0x020227f8)
extern "C" ARM void MapDisplay_SetMode(struct Obj02022d78* obj, int mode) {
    if (obj->modeLoading != 0) {
        SetSubBrightness(GetGameResources(), Brightness_Black, 0);
    }
    MapDisplay_CancelLoading(obj);
    obj->previousMode = obj->mode;
    obj->mode = mode;
    obj->modeLoading = 1;
    obj->loadStage = 0;
}
