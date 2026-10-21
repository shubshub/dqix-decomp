#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct PartyMemberAppearance {
    short models_[10];
    unsigned char female_ : 1;
    unsigned char eyeColor_ : 3;
    unsigned char skinColor_ : 4;
    unsigned char hairColor_ : 4;
    unsigned char unk_15_4 : 4;
    short unk_16;
    short width_;
    short height_;
};

struct PartyMemberData {
    char unk_0[0x488];
    PartyMemberAppearance appearance_;
};

extern "C" void clearModelPart(void* character, int part);
void getCharacterDimensions(unsigned char* self, int bodyType, short* width, short* height);
extern "C" void setCharacterScale(void* character, int width, int height);
extern "C" int menuSlotToStyleIndex(void* self, int state, int choice);
extern "C" void func_ov023_021e540c(void* character);

// USA: func_ov009_02188944
#if defined(jpn)
extern "C" ARM void func_ov009_02188944(CharacterCreationUI* self, int choice)
{
    PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance_;
    int state = self->state;
    if (state == 1)
    {
        appearance->female_ = choice;
        clearModelPart(self->nextCharacter, 0);
        clearModelPart(self->nextCharacter, 2);
        clearModelPart(self->nextCharacter, 3);
        clearModelPart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (state == 2)
    {
        getCharacterDimensions((unsigned char*)self, choice, &appearance->width_, &appearance->height_);
        setCharacterScale(self->character, appearance->width_, appearance->height_);
        setCharacterScale(self->nextCharacter, appearance->width_, appearance->height_);
    }
    else if (state == 5)
    {
        appearance->models_[2] = menuSlotToStyleIndex(self, 5, choice) + 0x233c;
        clearModelPart(self->nextCharacter, 2);
        self->flags |= 2;
    }
    else if (state == 3)
    {
        appearance->models_[3] = menuSlotToStyleIndex(self, 3, choice) + 0x2328;
        clearModelPart(self->nextCharacter, 3);
        clearModelPart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (state == 4)
    {
        appearance->hairColor_ = choice;
        clearModelPart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (state == 6)
    {
        appearance->eyeColor_ = choice;
        func_ov023_021e540c(self->character);
    }
    else if (state == 7)
    {
        appearance->skinColor_ = choice;
        func_ov023_021e540c(self->character);
    }
}
#else
extern "C" ARM void func_ov009_02188944(CharacterCreationUI* self, int choice)
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
    else if (characterCreationStep == 5)
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
        func_ov023_021e540c(current);
    }
    else if (characterCreationStep == 7)
    {
        appearance->skinColor_ = choice;
        func_ov023_021e540c(current);
    }
}
#endif
