#include <globaldefs.h>
#include "Graphics/CharacterModel.h"
#include "Resource/CharacterCreationUI.h"

struct PartyMemberAppearance {
    short unk_0[2];
    short face_;
    short hairStyle_;
    short unk_8[6];
    unsigned char female_ : 1;
    unsigned char skinColor_ : 3;
    unsigned char eyeColor_ : 4;
    unsigned char hairColor_ : 4;
    unsigned char unk_15_4 : 4;
    short unk_16;
    short width_;
    short height_;
};

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x488];
    Struct_ov009_02187b34 unknown_488_;
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
    int tab = self->state;
    if (tab == CreationTab_Gender)
    {
        appearance->female_ = choice;
        CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_Body);
        CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_Face);
        CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_Hair);
        CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_HairTexture);
        self->flags |= CreationFlag_LoadNextCharacter;
    }
    else if (tab == CreationTab_BodyType)
    {
        CharacterCreationUI_GetBodyDimensions((unsigned char*)self, choice, &appearance->width_, &appearance->height_);
        CharacterModel_SetScale(self->character, appearance->width_, appearance->height_);
        CharacterModel_SetScale(self->nextCharacter, appearance->width_, appearance->height_);
    }
    else if (tab == CreationTab_Face)
    {
        appearance->face_ = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_Face, choice) + AppearanceModel_FirstFace;
        CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_Face);
        self->flags |= CreationFlag_LoadNextCharacter;
    }
    else if (tab == CreationTab_HairStyle)
    {
        appearance->hairStyle_ = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_HairStyle, choice) + AppearanceModel_FirstHairStyle;
        CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_Hair);
        CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_HairTexture);
        self->flags |= CreationFlag_LoadNextCharacter;
    }
    else if (tab == CreationTab_HairColor)
    {
        appearance->hairColor_ = choice;
        CharacterModel_InvalidatePart(self->nextCharacter, CharacterModelPart_HairTexture);
        self->flags |= CreationFlag_LoadNextCharacter;
    }
    else if (tab == CreationTab_SkinColor)
    {
        appearance->skinColor_ = choice;
        CharacterModel_ApplyColors(self->character);
    }
    else if (tab == CreationTab_EyeColor)
    {
        appearance->eyeColor_ = choice;
        CharacterModel_ApplyColors(self->character);
    }
}
#else
extern "C" ARM void CharacterCreationUI_ApplyChoice(CharacterCreationUI* self, int choice)
{
    PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance_;
    int tab = self->state;
    void* next = self->nextCharacter;
    void* current = self->character;
    if (tab == CreationTab_Gender)
    {
        appearance->female_ = choice;
        CharacterModel_InvalidatePart(next, CharacterModelPart_Body);
        CharacterModel_InvalidatePart(next, CharacterModelPart_Face);
        CharacterModel_InvalidatePart(next, CharacterModelPart_Hair);
        CharacterModel_InvalidatePart(next, CharacterModelPart_HairTexture);
        self->flags |= CreationFlag_LoadNextCharacter;
    }
    else if (tab == CreationTab_BodyType)
    {
        CharacterCreationUI_GetBodyDimensions((unsigned char*)self, choice, &appearance->width_, &appearance->height_);
        CharacterModel_SetScale(current, appearance->width_, appearance->height_);
        CharacterModel_SetScale(next, appearance->width_, appearance->height_);
    }
    else if (tab == CreationTab_Face)
    {
        appearance->face_ = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_Face, choice) + AppearanceModel_FirstFace;
        CharacterModel_InvalidatePart(next, CharacterModelPart_Face);
        self->flags |= CreationFlag_LoadNextCharacter;
    }
    else if (tab == CreationTab_HairStyle)
    {
        appearance->hairStyle_ = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_HairStyle, choice) + AppearanceModel_FirstHairStyle;
        CharacterModel_InvalidatePart(next, CharacterModelPart_Hair);
        CharacterModel_InvalidatePart(next, CharacterModelPart_HairTexture);
        self->flags |= CreationFlag_LoadNextCharacter;
    }
    else if (tab == CreationTab_HairColor)
    {
        appearance->hairColor_ = choice;
        CharacterModel_InvalidatePart(next, CharacterModelPart_HairTexture);
        self->flags |= CreationFlag_LoadNextCharacter;
    }
    else if (tab == CreationTab_SkinColor)
    {
        appearance->skinColor_ = choice;
        CharacterModel_ApplyColors(current);
    }
    else if (tab == CreationTab_EyeColor)
    {
        appearance->eyeColor_ = choice;
        CharacterModel_ApplyColors(current);
    }
}
#endif
