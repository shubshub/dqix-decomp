#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct CharacterModel {
    char unk_0[0xc12];
    unsigned char loading_;
};

int GetWord0x0_0200fb8c(int* gameState);
extern "C" void func_ov009_02188c2c(CharacterCreationUI* self);
extern "C" void func_ov009_02188d9c(CharacterCreationUI* self);
extern "C" void func_ov009_02188e70(CharacterCreationUI* self, int choice);
extern "C" void applyCreationChoice(CharacterCreationUI* self, int choice);
extern "C" int func_ov009_02188ee8(CharacterCreationUI* self);
extern "C" void clearModelPart(CharacterModel* character, int part);
#if defined(jpn)
extern "C" void func_ov009_021867bc(unsigned char*, int);
#define SetStatValue021855dc func_ov009_021867bc
#else
void SetStatValue021855dc(unsigned char* self, int state);
#endif

// Overlay 9, originally func_ov009_021863d0 (USA/EUR 0x021863d0, JPN 0x02187500)
extern "C" ARM void handleGenderSelection(CharacterCreationUI* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = (GameResources*)GetWord0x0_0200fb8c((int*)gameState);
    if (self->step == 0)
    {
        if (GetBrightness((GameResources*)resources, false) == -16 &&
            GetBrightness((GameResources*)resources, true) == -16)
        {
            if (self->flags & 0x80)
                return;
            SetBrightness(resources, 0, 15);
        }
        func_ov009_02188c2c(self);
        func_ov009_02188d9c(self);
        func_ov009_02188e70(self, self->sex);
        self->step++;
    }
    if (self->step == 1)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        self->flags |= 1;
        self->step++;
    }
    else if (self->step == 2)
    {
        if (self->flags & 0x80)
            return;
        applyCreationChoice(self, self->sex);
        self->step++;
    }
    else if (self->step == 3) //Appears to be Idle Waiting for Input
    {
        int result = func_ov009_02188ee8(self);
        if (result != self->state)
        {
            CharacterModel* next = (CharacterModel*)self->nextCharacter;
            if (next->loading_ == 0)
            {
#if defined(jpn)
                clearModelPart((CharacterModel*)self->nextCharacter, 0);
                clearModelPart((CharacterModel*)self->nextCharacter, 2);
                clearModelPart((CharacterModel*)self->nextCharacter, 3);
                clearModelPart((CharacterModel*)self->nextCharacter, 4);
#else
                clearModelPart(next, 0);
                clearModelPart(next, 2);
                clearModelPart(next, 3);
                clearModelPart(next, 4);
#endif
            }
        }
        if (result == -2)
        {
            SetStatValue021855dc((unsigned char*)self, 2);
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
            SetStatValue021855dc((unsigned char*)self, 11);
            return;
        }
        if (result >= 101 && result <= 108)
        {
            int state = result - 100;
            if (state <= self->furthestState[self->sex] && state != self->state)
                SetStatValue021855dc((unsigned char*)self, (unsigned char)state);
        }
    }
}
