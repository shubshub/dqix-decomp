#include <globaldefs.h>
#include "World/Object3D.h"
#include "Resource/CharacterCreationUI.h"


struct CharacterModel {
    char unknown0[0xc12];
    unsigned char loading;
};

struct PartyMemberAppearance {
    short models[10];
    unsigned char unknown14[4];
    short width;
    short height;
};

struct PartyMemberData {
    char unknown0[0x488];
    PartyMemberAppearance appearance;
};

struct CharacterCreation {
#if defined(jpn)
    char unknown0[0x7bc];
#else
    char unknown0[0x7f8];
#endif
    CharacterModel* character;
    CharacterModel* nextCharacter;
    char unknown800[0xd88 - 0x800];
    PartyMemberData* member;
    char unknownD8c[0xd9c - 0xd8c];
    unsigned int flags;
    signed char lastStates[2];
    unsigned char vocation;
    unsigned char sex;
    unsigned char bodyTypes[2];
};

void CharacterModel_SetAngle(void*, unsigned int);
extern "C" Vector3i CharacterModel_GetRotation(CharacterModel* character);
struct Words021e60c4;
void CharacterModel_SetRotation(void*, Words021e60c4*);
extern "C" Object3D* CharacterModel_GetBody(CharacterModel* character);
void CharacterCreationUI_GetBodyDimensions(unsigned char*, int, short*, short*);
extern "C" void CharacterModel_SetScale(CharacterModel* character, int width, int height);
int StringLength_020d2ff0(const char* s);

// Overlay 9, originally func_ov009_02188454 (USA/EUR 0x02188454, JPN 0x02189214)
extern "C" ARM void CharacterCreationUI_SwapCharacters(CharacterCreation* self) {
    if (self->flags & CreationFlag_SwapCharacters) {
        CharacterModel* next = self->nextCharacter;
        if (next != NULL && next->loading != 0)
            return;

        if (self->flags & CreationFlag_ResetAngleOnSwap) {
            CharacterModel_SetAngle(self->character, CreationAngle_Default);
            self->flags &= ~CreationFlag_ResetAngleOnSwap;
        }
        const Vector3i& rotation = CharacterModel_GetRotation(self->character);
        CharacterModel_SetRotation(self->nextCharacter, (Words021e60c4*)&rotation);

        Object3D* currentObject = CharacterModel_GetBody(self->character);
        Object3D* nextObject = CharacterModel_GetBody(self->nextCharacter);
        const BCFG::AnimationRecord* nextAnimation = nextObject->activeAnimationRecord_;
        int nextNameLength = 0;
        int currentNameLength = 0;
        const BCFG::AnimationRecord* currentAnimation = currentObject->activeAnimationRecord_;
        if (nextAnimation != NULL)
            nextNameLength = StringLength_020d2ff0(nextAnimation->name);
        if (currentAnimation != NULL)
            currentNameLength = StringLength_020d2ff0(currentAnimation->name);
        if (nextNameLength == currentNameLength && currentAnimation != NULL) {
            nextObject->MaybeSetRegularAnimation(currentAnimation->name, 0);
            nextObject->SetCurrentAnimationTime(currentObject->animationTime_);
        }

        CharacterModel* previous = self->character;
        self->character = self->nextCharacter;
        self->nextCharacter = previous;

        if (self->flags & CreationFlag_RescaleOnSwap) {
            unsigned char sex = self->sex;
            PartyMemberAppearance* appearance = &self->member->appearance;
            unsigned char bodyType = self->bodyTypes[sex];
            CharacterCreationUI_GetBodyDimensions((unsigned char*)self, bodyType, &appearance->width, &appearance->height);
            CharacterModel_SetScale(self->character, appearance->width, appearance->height);
            CharacterModel_SetScale(self->nextCharacter, appearance->width, appearance->height);
            self->flags &= ~CreationFlag_RescaleOnSwap;
        }
        self->flags &= ~CreationFlag_SwapCharacters;
    }
}
