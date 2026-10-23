#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/CharacterCreationUI.h"
#include "NitroSDK/ColorEffects.h"

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
void CharacterCreationUI_SwitchTab(unsigned char* self, int tab);

#define REG_BLDCNT_SUB 0x04001050

// CharacterCreationUI::step on the close tab.
enum CloseStep
{
    CloseStep_FadeOut = 0,
    CloseStep_Finish = 1, // once the fade ends: empty both windows, undo the bottom screen's darkening
};

// Overlay 9, originally func_ov009_021883cc (USA/EUR 0x021883cc, JPN 0x0218918c)
extern "C" ARM void CharacterCreationUI_HandleClose(CharacterCreationUI* self) {
    GameResources* resources = GameState::GetInstance()->GetResources();
    unsigned char step = self->step;
    if (step == CloseStep_FadeOut) {
        SetBrightness(resources, Brightness_Black, CreationFade_Frames);
        ++self->step;
        return;
    }
    if (step != CloseStep_Finish || IsBrightnessTransitionActive(resources))
        return;
    ResetEntryList0205d6a0((Entry_0205d6a0*)&self->windows[0], 1);
    ResetEntryList0205d6a0((Entry_0205d6a0*)&self->windows[1], 1);
    ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 1, 0);
    CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Done);
}
