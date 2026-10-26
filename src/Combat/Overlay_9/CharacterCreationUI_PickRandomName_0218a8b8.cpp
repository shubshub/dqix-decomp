#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"

extern int CharacterCreationUI_randomNameCounts[];

extern "C" int KeyTable_Get(Container020e0310* c, int key);

// Overlay 9, originally ResetEntrySkill0218a8b8 (USA/EUR 0x0218a8b8; JPN 0x0218b850, a body of its own)
extern "C" ARM void CharacterCreationUI_PickRandomName(void* objRaw) {
    CharacterCreationUI* self = (CharacterCreationUI*)objRaw;
    char** names = self->names;
    char* name = names[self->sex];
    int pick;
    int textId;
    int text;
    unsigned char sex;
    memset(name, 0, CreationName_BufferSize);
    sex = self->sex;
    int count = CharacterCreationUI_randomNameCounts[sex];
    pick = rand() % count;
    sex = self->sex;
    int firstText = sex * CreationText_RandomNameStride;
    firstText += CreationText_FirstRandomName;
    textId = (short)(pick + firstText);
    text = KeyTable_Get(&self->texts, textId);
    sprintf(name, (const char*)(long)text);
}
