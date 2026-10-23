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
ARM void CharacterCreationUI_SwitchTab(unsigned char* storage, int tab) {
    CharacterCreation* self = (CharacterCreation*)storage;
    signed char newTab = (signed char)tab;
    self->state = newTab;
    self->step = 0;
    int sex = self->sex;
    if (self->furthestState[sex] < tab)
        self->furthestState[sex] = newTab;
    self->flags |= (CreationFlag_RedrawTabHighlight | CreationFlag_RefreshSummary);
    if (tab != CreationTab_Confirm && tab != CreationTab_Close && tab != CreationTab_Done)
        self->flags |= CreationFlag_TabLoading;
}
