#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "NitroSDK/Memory.h"
#include "Combat/MapDisplay.h"
#include "Combat/CombatScriptContext.h"

struct BackgroundGraphics;
extern "C" ARM void Background_Init(struct BackgroundGraphics* obj);

extern "C" ARM void MapDisplay_CenterOnLeader(void* obj);

// Main, originally func_02020720 (USA 0x02020720, EUR 0x02020730, JPN 0x02020344)
extern "C" ARM void MapDisplay_ResetMap(MapDisplay* display) {
    display->forwardingX = 0;
    display->forwardingY = 0;
    display->names = 0;
    display->nameCount = 0;
    display->field28 = 0;
    display->forwarding = 0;
    display->forwardingCount = 0;
    display->field34 = 0;
    display->scale = 0x1000;
    int cameraBias = 0x1000 - 0x1400;
    display->cameraBiasX = cameraBias;
    display->cameraBiasZ = cameraBias;
    display->mapState = 0;
    display->mapPalette = 0;
    display->forwardingFill = 0;
    display->displayMode = 1;
    display->forwardingPending = 0;
    display->field754 = 0;
    display->flags = display->flags & 1;
    display->state = 0;
    display->fielda9c = 0;

    for (int i = 0; i < 4; i++) {
        display->slots[i] = -1;
        display->slotFlags[i] = 0;
        display->flags758[i] = 0;
        display->recordVisible[i] = 1;
    }

    Background_Init(&display->list4c);

    display->field75c = 0;
    display->field75d = 0;
    display->field77a = 0;
    display->field77c = 0;
    display->field9b4 = 0;
    display->field760 = 0;
    display->field764 = 0;
    display->field766 = 0;
    display->field768 = 1;

    MapDisplay_CenterOnLeader(display);

    display->field9bc = 0;
    display->actionState = 0;
    data_020fdc4c.unknown_c_ = 0;
    display->fieldaa0 = 0;

    VectorizedMemset(display->bytesaa2, 0, 0x100);
}
