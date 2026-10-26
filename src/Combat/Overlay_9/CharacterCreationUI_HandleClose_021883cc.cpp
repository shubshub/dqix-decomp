#include <globaldefs.h>
#include "NitroSDK/HWRegisters.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/CharacterCreationUI.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"

struct Entry_0205d6a0;
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void CharacterCreationUI_SwitchTab(unsigned char* self, int tab);


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
    Window_ClosePane((Entry_0205d6a0*)&self->windows[0], 1);
    Window_ClosePane((Entry_0205d6a0*)&self->windows[1], 1);
    ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, BLEND_TARGET_BG0, Brightness_Normal);
    CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Done);
}
