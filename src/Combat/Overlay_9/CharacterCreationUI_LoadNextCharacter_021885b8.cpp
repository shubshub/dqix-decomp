#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "GameState/PartyMember.h"

extern "C" int CharacterModel_Load(void*, void*, int, int, int);

struct Struct021885b8;
// Overlay 9, originally UpdateFlag021885b8 (USA/EUR 0x021885b8, JPN 0x02189378)
ARM void CharacterCreationUI_LoadNextCharacter(Struct021885b8* storage) {
    CharacterCreationUI* self = (CharacterCreationUI*)storage;
    if (self->flags & CreationFlag_LoadNextCharacter) {
        void* character = self->nextCharacter;
        PartyMemberData* member = self->characterData;
        CharacterModel_Load(character, member, member->unk_568, 0, 0);
        self->flags = (self->flags | CreationFlag_SwapCharacters) & ~CreationFlag_LoadNextCharacter;
    }
}
