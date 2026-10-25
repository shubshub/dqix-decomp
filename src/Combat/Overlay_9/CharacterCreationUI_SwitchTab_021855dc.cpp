#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

// Overlay 9, originally func_ov009_021855dc (USA/EUR 0x021855dc, JPN 0x021867bc)
ARM void CharacterCreationUI_SwitchTab(unsigned char* storage, int tab) {
    CharacterCreationUI* self = (CharacterCreationUI*)storage;
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
