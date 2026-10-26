#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "Graphics/CharacterModel.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int choice);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI* self);
extern "C" void CharacterModel_InvalidatePart(CharacterModel* character, int part);
#if defined(jpn)
extern "C" void CharacterCreationUI_SwitchTab(unsigned char*, int);
#else
extern "C" void CharacterCreationUI_SwitchTab(unsigned char* self, int state);
#endif

// CharacterCreationUI::step on the gender tab. Setup falls through into FadeIn in the same frame.
enum GenderStep
{
    GenderStep_Setup = 0,      // first entry (both screens black): wait for the tab's graphics, fade in
    GenderStep_FadeIn = 1,     // wait for the fade, then stylus rotation on
    GenderStep_ShowChoice = 2, // apply the stored sex to the preview
    GenderStep_Input = 3,
};

// Overlay 9, originally func_ov009_021863d0 (USA/EUR 0x021863d0, JPN 0x02187500)
extern "C" ARM void CharacterCreationUI_HandleGenderSelection(CharacterCreationUI* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();

    if (self->step == GenderStep_Setup)
    {
        if (GetBrightness(resources, false) == Brightness_Black &&
            GetBrightness(resources, true) == Brightness_Black)
        {
            if (self->flags & CreationFlag_TabLoading)
                return;
            SetBrightness(resources, Brightness_Normal, CreationFade_Frames);
        }
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        CharacterCreationUI_MoveCursorToSlot(self, self->sex);
        self->step++;
    }

    if (self->step == GenderStep_FadeIn)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        self->flags |= CreationFlag_StylusRotation;
        self->step++;
    }
    else if (self->step == GenderStep_ShowChoice)
    {
        if (self->flags & CreationFlag_TabLoading)
            return;
        CharacterCreationUI_ApplyChoice(self, self->sex);
        self->step++;
    }
    else if (self->step == GenderStep_Input)
    {
        int result = CharacterCreationUI_HandleInput(self);
        if (result != self->state)
        {
            CharacterModel* next = self->nextCharacter;
            if (next->loading_ == 0)
            {
#if defined(jpn)
                CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_Body);
                CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_Face);
                CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_Hair);
                CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_HairTexture);
#else
                CharacterModel_InvalidatePart(next, CharacterModelPart_Body);
                CharacterModel_InvalidatePart(next, CharacterModelPart_Face);
                CharacterModel_InvalidatePart(next, CharacterModelPart_Hair);
                CharacterModel_InvalidatePart(next, CharacterModelPart_HairTexture);
#endif
            }
        }
        if (result == CreationInput_Confirm)
        {
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_BodyType);
            return;
        }
        if (result == CreationInput_Back)
        {
            if (self->mode == CreationMode_PartyMemberCreation)
                self->flags &= ~CreationFlag_MemberCreated;
            else if (self->mode == CreationMode_NewGame)
                gameState->characterCreated_ = 0;
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Close);
            return;
        }

        if (result >= CreationInput_FirstTabIcon && result <= CreationInput_LastTabIcon)
        {
            int tab = result - CreationInput_TabIcon;
            bool reached = tab <= self->furthestState[self->sex];
            if (reached && tab != self->state)
                CharacterCreationUI_SwitchTab((unsigned char*)self, (unsigned char)tab);
        }
    }
}
