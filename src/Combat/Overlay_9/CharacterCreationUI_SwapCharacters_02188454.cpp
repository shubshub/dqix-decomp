#include <globaldefs.h>
#include "World/Object3D.h"
#include "Resource/CharacterCreationUI.h"
#include "Graphics/CharacterModel.h"
#include "GameState/PartyMember.h"

extern "C" void CharacterModel_SetAngle(void*, unsigned int);
extern "C" Vector3i CharacterModel_GetRotation(void* character);
struct Words021e60c4;
extern "C" void CharacterModel_SetRotation(void*, Words021e60c4*);
extern "C" Object3D* CharacterModel_GetBody(void* character);
extern "C" void CharacterCreationUI_GetBodyDimensions(unsigned char*, int, short*, short*);
extern "C" void CharacterModel_SetScale(void* character, int width, int height);
extern "C" int STD_GetStringLength(const char* s);

// Overlay 9, originally func_ov009_02188454 (USA/EUR 0x02188454, JPN 0x02189214)
extern "C" ARM void CharacterCreationUI_SwapCharacters(CharacterCreationUI* self) {
    if (self->flags & CreationFlag_SwapCharacters) {
        CharacterModel* next = self->nextCharacter;
        if (next != NULL && next->loading_ != 0)
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
            nextNameLength = STD_GetStringLength(nextAnimation->name);
        if (currentAnimation != NULL)
            currentNameLength = STD_GetStringLength(currentAnimation->name);
        if (nextNameLength == currentNameLength && currentAnimation != NULL) {
            nextObject->SetAnimationByName(currentAnimation->name, 0);
            nextObject->SetCurrentAnimationTime(currentObject->animationTime_);
        }

        CharacterModel* previous = self->character;
        self->character = self->nextCharacter;
        self->nextCharacter = previous;

        if (self->flags & CreationFlag_RescaleOnSwap) {
            unsigned char sex = self->sex;
            PartyMemberAppearance* appearance = &self->characterData->appearance_;
            unsigned char bodyType = self->bodyType[sex];
            CharacterCreationUI_GetBodyDimensions((unsigned char*)self, bodyType, &appearance->width_, &appearance->height_);
            CharacterModel_SetScale(self->character, appearance->width_, appearance->height_);
            CharacterModel_SetScale(self->nextCharacter, appearance->width_, appearance->height_);
            self->flags &= ~CreationFlag_RescaleOnSwap;
        }
        self->flags &= ~CreationFlag_SwapCharacters;
    }
}
