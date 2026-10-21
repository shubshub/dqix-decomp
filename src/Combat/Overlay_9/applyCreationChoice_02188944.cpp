#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_ov009_02187b34 {
    short unknown_0_[10];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
};

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x488];
    Struct_ov009_02187b34 unknown_488_;
};

extern "C" void clearModelPart(void* character, int part);
void getCharacterDimensions(unsigned char* self, int bodyType, short* width, short* height);
extern "C" void setCharacterScale(void* character, int width, int height);
extern "C" int menuSlotToStyleIndex(void* self, int state, int choice);
extern "C" void applyModelColors(void* character);

// Overlay 9, originally func_ov009_02188944 (USA/EUR 0x02188944, JPN 0x02189704)
#if defined(jpn)
extern "C" ARM void applyCreationChoice(CharacterCreationUI* self, int choice)
{
    PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance_;
    int characterCreationStep = self->state;
    if (characterCreationStep == 1)
    {
        appearance->female_ = choice;
        clearModelPart(self->nextCharacter, 0);
        clearModelPart(self->nextCharacter, 2);
        clearModelPart(self->nextCharacter, 3);
        clearModelPart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 2)
    {
        getCharacterDimensions((unsigned char*)self, choice, &appearance->width_, &appearance->height_);
        setCharacterScale(self->character, appearance->width_, appearance->height_);
        setCharacterScale(self->nextCharacter, appearance->width_, appearance->height_);
    }
    else if (characterCreationStep == 5)
    {
        appearance->models_[2] = menuSlotToStyleIndex(self, 5, choice) + 0x233c;
        clearModelPart(self->nextCharacter, 2);
        self->flags |= 2;
    }
    else if (characterCreationStep == 3)
    {
        appearance->models_[3] = menuSlotToStyleIndex(self, 3, choice) + 0x2328;
        clearModelPart(self->nextCharacter, 3);
        clearModelPart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 4)
    {
        appearance->hairColor_ = choice;
        clearModelPart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 6)
    {
        appearance->eyeColor_ = choice;
        applyModelColors(self->character);
    }
    else if (characterCreationStep == 7)
    {
        appearance->skinColor_ = choice;
        applyModelColors(self->character);
    }
}
#else
extern "C" ARM void applyCreationChoice(CharacterCreationUI* self, int choice)
{
    PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance_;
    int characterCreationStep = self->state; //Step of the Character Creation Menu
    void* next = self->nextCharacter;
    void* current = self->character;
    if (characterCreationStep == 1) //Gender Select
    {
        //This section of the code determines what Gender the Character is
        appearance->female_ = choice; //0 = Male, 1 = Female

        //Clear out specific Model Parts so they can be replaced with new ones
        clearModelPart(next, 0);
        clearModelPart(next, 2);
        clearModelPart(next, 3);
        clearModelPart(next, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 2) //Select Body Type
    {
        getCharacterDimensions((unsigned char*)self, choice, &appearance->width_, &appearance->height_);
        setCharacterScale(current, appearance->width_, appearance->height_);
        setCharacterScale(next, appearance->width_, appearance->height_);
    }
    else if (characterCreationStep == 5) //Select Face Type
    {
        appearance->models_[2] = menuSlotToStyleIndex(self, 5, choice) + 0x233c;
        clearModelPart(next, 2);
        self->flags |= 2;
    }
    else if (characterCreationStep == 3) //Select Hair Style
    {
        appearance->models_[3] = menuSlotToStyleIndex(self, 3, choice) + 0x2328;
        clearModelPart(next, 3);
        clearModelPart(next, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 4)
    {
        appearance->hairColor_ = choice;
        clearModelPart(next, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 6)
    {
        appearance->eyeColor_ = choice;
        applyModelColors(current);
    }
    else if (characterCreationStep == 7)
    {
        appearance->skinColor_ = choice;
        applyModelColors(current);
    }
}
#endif
