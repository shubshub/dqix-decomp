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
extern "C" void func_ov023_021e540c(void* character);

// USA: func_ov009_02188944
#if defined(jpn)
extern "C" ARM void func_ov009_02188944(Struct_ov009_021842a0* arg0, int arg1)
{
    Struct_ov009_02187b34* var0 = &((Struct_ov005_0215840c_2*)arg0->unknown_d88_)->unknown_488_;
    int var1 = arg0->unknown_c58_;
    if (var1 == 1)
    {
        appearance->female_ = choice;
        clearModelPart(self->nextCharacter, 0);
        clearModelPart(self->nextCharacter, 2);
        clearModelPart(self->nextCharacter, 3);
        clearModelPart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (var1 == 2)
    {
        getCharacterDimensions((unsigned char*)self, choice, &appearance->width_, &appearance->height_);
        setCharacterScale(self->character, appearance->width_, appearance->height_);
        setCharacterScale(self->nextCharacter, appearance->width_, appearance->height_);
    }
    else if (var1 == 5)
    {
        appearance->models_[2] = menuSlotToStyleIndex(self, 5, choice) + 0x233c;
        clearModelPart(self->nextCharacter, 2);
        self->flags |= 2;
    }
    else if (var1 == 3)
    {
        appearance->models_[3] = menuSlotToStyleIndex(self, 3, choice) + 0x2328;
        clearModelPart(self->nextCharacter, 3);
        clearModelPart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (var1 == 4)
    {
        appearance->hairColor_ = choice;
        clearModelPart(self->nextCharacter, 4);
        self->flags |= 2;
    }
    else if (var1 == 6)
    {
        var0->unknown_14_1_ = arg1;
        func_ov023_021e540c(arg0->unknown_7f8_);
    }
    else if (var1 == 7)
    {
        var0->unknown_14_4_ = arg1;
        func_ov023_021e540c(arg0->unknown_7f8_);
    }
}
#else
extern "C" ARM void func_ov009_02188944(Struct_ov009_021842a0* arg0, int arg1)
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
        var2->unknown_14_1_ = arg1;
        func_ov023_021e540c(var5);
    }
    else if (characterCreationStep == 7)
    {
        var2->unknown_14_4_ = arg1;
        func_ov023_021e540c(var5);
    }
}
#endif
