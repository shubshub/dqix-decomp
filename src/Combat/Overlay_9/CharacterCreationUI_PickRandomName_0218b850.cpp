#if defined(jpn)
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/CharacterCreationUI.h"

extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" int STD_GetStringLength(const char*);

// Overlay 9, originally func_ov009_0218b850 (JPN 0x0218b850; usa/eur have their own body at 0x0218a8b8)
extern "C" ARM void CharacterCreationUI_PickRandomName(CharacterCreationUI* self)
{
    const char* placeholder = (const char*)KeyTable_Get(&self->texts, CreationText_BlankName);
    memcpy(self->names[self->sex], placeholder, 11);
    int choice = rand() % 101;
    short key = (self->sex * 1000 + 0x4e20) + choice;
    int length = STD_GetStringLength((const char*)KeyTable_Get(&self->texts, key));
    const char* name = (const char*)KeyTable_Get(&self->texts, key);
    memcpy(self->names[self->sex], name, length);
    self->nameLengths[self->sex] = length / 2;
}
#endif
