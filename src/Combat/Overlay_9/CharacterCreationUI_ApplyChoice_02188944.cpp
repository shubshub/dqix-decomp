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

extern "C" void CharacterModel_InvalidatePart(void* character, int part);
void CharacterCreationUI_GetBodyDimensions(unsigned char* self, int bodyType, short* width, short* height);
extern "C" void CharacterModel_SetScale(void* character, int width, int height);
extern "C" int CharacterCreationUI_SlotToStyleIndex(void* self, int state, int choice);
extern "C" void CharacterModel_ApplyColors(void* character);

// Overlay 9, originally func_ov009_02188944 (USA/EUR 0x02188944, JPN 0x02189704)
#if defined(jpn)
extern "C" ARM void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice)
{
    PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance_;
    int characterCreationStep = self->state;
    if (characterCreationStep == 1)
    {
        appearance->female_ = choice;
        CharacterModel_InvalidatePart(self->nextCharacter, 0);
        CharacterModel_InvalidatePart(self->nextCharacter, 2);
        CharacterModel_InvalidatePart(self->nextCharacter, 3);
        CharacterModel_InvalidatePart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 2)
    {
        CharacterCreationUI_GetBodyDimensions((unsigned char*)self, choice, &appearance->width_, &appearance->height_);
        CharacterModel_SetScale(self->character, appearance->width_, appearance->height_);
        CharacterModel_SetScale(self->nextCharacter, appearance->width_, appearance->height_);
    }
    else if (characterCreationStep == 5)
    {
        appearance->models_[2] = CharacterCreationUI_SlotToStyleIndex(self, 5, choice) + 0x233c;
        CharacterModel_InvalidatePart(self->nextCharacter, 2);
        self->flags |= 2;
    }
    else if (characterCreationStep == 3)
    {
        appearance->models_[3] = CharacterCreationUI_SlotToStyleIndex(self, 3, choice) + 0x2328;
        CharacterModel_InvalidatePart(self->nextCharacter, 3);
        CharacterModel_InvalidatePart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 4)
    {
        appearance->hairColor_ = choice;
        CharacterModel_InvalidatePart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 6)
    {
        appearance->eyeColor_ = choice;
        CharacterModel_ApplyColors(self->character);
    }
    else if (characterCreationStep == 7)
    {
        appearance->skinColor_ = choice;
        CharacterModel_ApplyColors(self->character);
    }
}
#else
extern "C" ARM void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice)
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
        CharacterModel_InvalidatePart(next, 0);
        CharacterModel_InvalidatePart(next, 2);
        CharacterModel_InvalidatePart(next, 3);
        CharacterModel_InvalidatePart(next, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 2) //Select Body Type
    {
        CharacterCreationUI_GetBodyDimensions((unsigned char*)self, choice, &appearance->width_, &appearance->height_);
        CharacterModel_SetScale(current, appearance->width_, appearance->height_);
        CharacterModel_SetScale(next, appearance->width_, appearance->height_);
    }
    else if (characterCreationStep == 5) //Select Face Type
    {
        appearance->models_[2] = CharacterCreationUI_SlotToStyleIndex(self, 5, choice) + 0x233c;
        CharacterModel_InvalidatePart(next, 2);
        self->flags |= 2;
    }
    else if (characterCreationStep == 3) //Select Hair Style
    {
        appearance->models_[3] = CharacterCreationUI_SlotToStyleIndex(self, 3, choice) + 0x2328;
        CharacterModel_InvalidatePart(next, 3);
        CharacterModel_InvalidatePart(next, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 4)
    {
        appearance->hairColor_ = choice;
        CharacterModel_InvalidatePart(next, 4);
        self->flags |= 2;
    }
    else if (characterCreationStep == 6)
    {
        appearance->eyeColor_ = choice;
        CharacterModel_ApplyColors(current);
    }
    else if (characterCreationStep == 7)
    {
        appearance->skinColor_ = choice;
        CharacterModel_ApplyColors(current);
    }
}
#endif
