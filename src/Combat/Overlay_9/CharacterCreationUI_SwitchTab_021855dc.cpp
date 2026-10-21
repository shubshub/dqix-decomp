#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct CharacterCreation {
#if defined(jpn)
    char unknown0[0xc1c];
#else
    char unknown0[0xc58];
#endif
    signed char state;
    unsigned char step;
    char unknownAfterStep[0xd9c - 0xc5a];
    unsigned int flags;
    signed char furthestState[2];
    unsigned char vocation;
    unsigned char sex;
};

// Overlay 9, originally func_ov009_021855dc (USA/EUR 0x021855dc, JPN 0x021867bc)
ARM void CharacterCreationUI_SwitchTab(unsigned char* storage, int state) {
    CharacterCreation* editor = (CharacterCreation*)storage;
    signed char selectedState = (signed char)state;
    editor->state = selectedState;
    editor->step = 0;
    int sex = editor->sex;
    if (editor->furthestState[sex] < state)
        editor->furthestState[sex] = selectedState;
    editor->flags |= 0x1100;
    if (state != 9 && state != 11 && state != 12)
        editor->flags |= CreationFlag_TabLoading;
}
