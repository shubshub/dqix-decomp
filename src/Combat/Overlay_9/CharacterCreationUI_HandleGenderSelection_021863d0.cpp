#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov009_021863d0 {
    char unknown_0_[0xc12];
    unsigned char unknown_c12_;
};

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI* self);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int choice);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI* self);
extern "C" void CharacterModel_InvalidatePart(CharacterModel* character, int part);
#if defined(jpn)
extern "C" void func_ov009_021867bc(unsigned char*, int);
#define func_ov009_021855dc func_ov009_021867bc
#else
extern "C" void func_ov009_021855dc(unsigned char* arg0, int arg1);
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
            SetBrightness(var1, 0, 15);
        }
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        CharacterCreationUI_MoveCursorToSlot(self, self->sex);
        self->step++;
    }

    //Looks like Step 1 and Step 2 Trigger when we enter the Gender Tab
    if (self->step == 1)
    {
        if (IsBrightnessTransitionActive(var1))
            return;
        self->flags |= CreationFlag_StylusRotation;
        self->step++;
    }
    else if (arg0->unknown_c59_ == 2)
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
            Struct_ov009_021863d0* var3 = (Struct_ov009_021863d0*)arg0->unknown_7fc_;
            if (var3->unknown_c12_ == 0)
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
        if (var2 == -2)
        {
            func_ov009_021855dc((unsigned char*)arg0, 2);
            return;
        }
        if (var2 == -3)
        {
            if (arg0->unknown_d95_ == 1)
                arg0->unknown_d9c_ &= ~0x400;
            else if (arg0->unknown_d95_ == 0)
                #if defined(jpn)
                *((unsigned char*)var0 + 0x6174) = 0;
#else
                *((unsigned char*)var0 + 0x63d4) = 0;
#endif
            func_ov009_021855dc((unsigned char*)arg0, 11);
            return;
        }
        if (var2 >= 101 && var2 <= 108)
        {
            int var4 = var2 - 100;
            if (var4 <= arg0->unknown_da0_[arg0->unknown_da3_] && var4 != arg0->unknown_c58_)
                func_ov009_021855dc((unsigned char*)arg0, (unsigned char)var4);
        }
    }
}
