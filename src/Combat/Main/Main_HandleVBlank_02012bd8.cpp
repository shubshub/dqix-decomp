#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "NitroSDK/DTCM.h"
#include "NitroSDK/Interrupts.h"

int Overlay_IsLoaded(unsigned int idx);

// Main, originally InitOverlay17ObjAndBumpBattleCounter02012bd8 (USA 0x02012bd8, EUR 0x02012be8, JPN 0x020129a0)
ARM void Main_HandleVBlank() {
    if (Overlay_IsLoaded(OVERLAY_ID(17))) {
        GetGameResources();
        if (GetGameResources() != NULL) {
            ApplyBrightness(GetGameResources());
        }
    }
    GameState::GetInstance()->currentNumTicks_++;
    DTCM_DATA_INTERRUPTS_FIRED |= IRQ_MASK_LCD_VBLANK;
}
