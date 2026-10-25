#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Obj0205d2bc;
void Window_TransferLayers(Obj0205d2bc*);
extern "C" void Background_TransferMap(BackgroundGraphics*, void*);
extern "C" void CharacterCreationUI_ApplyTabGraphics(unsigned char*);
extern "C" void CharacterCreationUI_RefreshSummary(char*);
void RefreshFieldIfFlag4000_021d9d34(char*);
void CharacterCreationUI_RefreshNameText(char*);
extern "C" void CharacterCreationUI_RefreshYesNoMenu(unsigned char*);

// Overlay 9, originally func_ov009_02184ca4 (USA/EUR 0x02184ca4, JPN 0x02185fd0)
extern "C" ARM void CharacterCreationUI_UpdateVBlank(unsigned char* storage) {
    CharacterCreationUI* self = (CharacterCreationUI*)storage;
    CharacterCreationUI_ApplyTabGraphics(storage);
    signed char tab = self->state;
    if (tab == CreationTab_Setup || tab == CreationTab_Done)
        return;
    if (self->flags & CreationFlag_TabLoading)
        return;
    Window_TransferLayers((Obj0205d2bc*)&self->windows[CreationWindowIndex_Summary]);
    Window_TransferLayers((Obj0205d2bc*)&self->windows[CreationWindowIndex_Bottom]);
    if (self->flags & CreationFlag_RedrawTabHighlight) {
        Background_TransferMap(&self->layers[CreationLayer_TabHighlight], 0);
        self->flags &= ~CreationFlag_RedrawTabHighlight;
    }
    if (self->flags & CreationFlag_RedrawPanel) {
        Background_TransferMap(&self->layers[CreationLayer_Selection], 0);
#if defined(jpn)
        if (self->state == CreationTab_NameEntry || self->state == CreationTab_Confirm)
#else
        signed char fromNameEntry = tab - CreationTab_NameEntry; // name entry or confirm: the keyboard page layer too
        if ((unsigned char)fromNameEntry <= 1)
#endif
            Background_TransferMap(&self->layers[CreationLayer_Page], 0);
        self->flags &= ~CreationFlag_RedrawPanel;
    }
    CharacterCreationUI_RefreshSummary((char*)storage);
    RefreshFieldIfFlag4000_021d9d34((char*)storage);
    CharacterCreationUI_RefreshNameText((char*)storage);
    CharacterCreationUI_RefreshYesNoMenu(storage);
}
