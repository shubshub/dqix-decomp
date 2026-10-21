#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct CharacterModel {
    char unk_0[0xc12];
    unsigned char loading_;
};

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int choice);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI* self);
extern "C" void CharacterModel_InvalidatePart(CharacterModel* character, int part);
#if defined(jpn)
void CharacterCreationUI_SwitchTab(unsigned char*, int);
#else
void CharacterCreationUI_SwitchTab(unsigned char* self, int state);
#endif

// Overlay 9, originally func_ov009_021863d0 (USA/EUR 0x021863d0, JPN 0x02187500)
extern "C" ARM void CharacterCreationUI_HandleGenderSelection(CharacterCreationUI* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    if (self->step == 0) //First time setup, Runs one time when we switch into the Gender Tab
    {
        if (GetBrightness(resources, false) == -16 &&
            GetBrightness(resources, true) == -16)
        {
            if (self->flags & CreationFlag_TabLoading)
                return;
            SetBrightness(resources, 0, 15);
        }
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        CharacterCreationUI_MoveCursorToSlot(self, self->sex);
        self->step++;
    }

    //Looks like Step 1 and Step 2 Trigger when we enter the Gender Tab
    if (self->step == 1)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        self->flags |= CreationFlag_StylusRotation;
        self->step++;
    }
    else if (self->step == 2)
    {
        if (self->flags & CreationFlag_TabLoading)
            return;
        CharacterCreationUI_ApplyChoice(self, self->sex);
        self->step++;
    }
    else if (self->step == 3) //Appears to be Idle Waiting for Input
    {
        int result = CharacterCreationUI_HandleInput(self);
        if (result != self->state)
        {
            CharacterModel* next = (CharacterModel*)self->nextCharacter;
            if (next->loading_ == 0)
            {
#if defined(jpn)
                CharacterModel_InvalidatePart((CharacterModel*)self->nextCharacter, 0);
                CharacterModel_InvalidatePart((CharacterModel*)self->nextCharacter, 2);
                CharacterModel_InvalidatePart((CharacterModel*)self->nextCharacter, 3);
                CharacterModel_InvalidatePart((CharacterModel*)self->nextCharacter, 4);
#else
                CharacterModel_InvalidatePart(next, 0);
                CharacterModel_InvalidatePart(next, 2);
                CharacterModel_InvalidatePart(next, 3);
                CharacterModel_InvalidatePart(next, 4);
#endif
            }
        }
        if (result == -2)
        {
            CharacterCreationUI_SwitchTab((unsigned char*)self, 2);
            return;
        }
        if (result == -3)
        {
            if (self->mode == 1)
                self->flags &= ~0x400;
            else if (self->mode == 0)
                #if defined(jpn)
                *((unsigned char*)gameState + 0x6174) = 0;
#else
                *((unsigned char*)gameState + 0x63d4) = 0;
#endif
            CharacterCreationUI_SwitchTab((unsigned char*)self, 11);
            return;
        }
        if (result >= 101 && result <= 108)
        {
            int state = result - 100;
            if (state <= self->furthestState[self->sex] && state != self->state)
                CharacterCreationUI_SwitchTab((unsigned char*)self, (unsigned char)state);
        }
    }
}
