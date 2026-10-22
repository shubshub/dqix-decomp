#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/CharacterCreationUI.h"
#include "NitroSDK/ColorEffects.h"

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
#if defined(jpn)
void CharacterCreationUI_SwitchTab(unsigned char*, int);
#else
void CharacterCreationUI_SwitchTab(unsigned char*, int);
#endif

// Overlay 9, originally func_ov009_021883cc (USA/EUR 0x021883cc, JPN 0x0218918c)
extern "C" ARM void CharacterCreationUI_HandleClose(unsigned char* storage) {
    CharacterCreationUI* editor = (CharacterCreationUI*)storage;
    GameResources* resources = GameState::GetInstance()->GetResources();
    unsigned char step = editor->step;
    if (step == 0) {
        SetBrightness(resources, -16, 15);
        ++editor->step;
        return;
    }
    if (step != 1 || IsBrightnessTransitionActive(resources))
        return;
    ResetEntryList0205d6a0((Entry_0205d6a0*)&editor->windows[0], 1);
    ResetEntryList0205d6a0((Entry_0205d6a0*)&editor->windows[1], 1);
    ColorEffect_ConfigureBrightnessAdjust(0x04001050, 1, 0);
#if defined(jpn)
    CharacterCreationUI_SwitchTab(storage, 12);
#else
    CharacterCreationUI_SwitchTab(storage, 12);
#endif
}
