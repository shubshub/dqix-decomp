#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "NitroSDK/OSLanguage.h"
#include "Resource/CharacterCreationUI.h"

struct GridCursor;
void GridCursor_SetDimensions(GridCursor*, int, int, int);
void GridCursor_SetCount(GridCursor*, int);
struct Struct_0205bcdc;
void GridCursor_SelectIfValid(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(void*, int);
struct Struct0200fb08;
unsigned char GameState_GetLanguage(Struct0200fb08*);
extern "C" void CharacterCreationUI_WriteYesNoText(char*, char*, int);
#if defined(jpn)
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#else
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int, int);
#endif

// Overlay 23, originally func_ov023_021d9f88 (USA/EUR 0x021d9f88, JPN 0x021da7ac)
extern "C" ARM void CharacterCreationUI_OpenYesNoWindow(void* objRaw) {
    CharacterCreationUI* self = (CharacterCreationUI*)objRaw;
    CreationWindow* win = &self->windows[CreationWindowIndex_Bottom];
    self->selection = 0;
    GridCursor_SetDimensions((GridCursor*)win->frame, 1, 2, 0);
    GridCursor_SetDimensions((GridCursor*)win->cursor, 1, 2, 0);
    GridCursor_SetCount((GridCursor*)win->frame, 2);
    GridCursor_SetCount((GridCursor*)win->cursor, 2);
    self->windows[CreationWindowIndex_Bottom].frame[1] = 1;
    self->windows[CreationWindowIndex_Bottom].cursor[1] = 1;
    signed char cursor = self->selection;
    GridCursor_SelectIfValid((Struct_0205bcdc*)win->frame, cursor);
    GridCursor_SetSelectedIndex(self->windows[CreationWindowIndex_Bottom].cursor, cursor);
    self->windows[CreationWindowIndex_Bottom].unknown94[0] = 1;
    self->windows[CreationWindowIndex_Bottom].unknown94[1] = 1;

#if defined(jpn)
    int textX = 0xe;
    self->windows[CreationWindowIndex_Bottom].paneWidth = 7;
    self->windows[CreationWindowIndex_Bottom].paneHeight = 5;
    self->windows[CreationWindowIndex_Bottom].unknownA4[0] = 0x18;
    self->windows[CreationWindowIndex_Bottom].unknownA4[1] = 0xa;
    self->windows[CreationWindowIndex_Bottom].paneTextX = textX;
    self->windows[CreationWindowIndex_Bottom].unknownAa[0] = 0;
    self->windows[CreationWindowIndex_Bottom].unknownAa[1] = 0xc;
    self->windows[CreationWindowIndex_Bottom].unknownAa[2] = 0x10;
    self->windows[CreationWindowIndex_Bottom].nextWindow = BottomWindow_YesNoPane;
    self->windows[CreationWindowIndex_Bottom].fontHeight = 0xc;
    self->windows[CreationWindowIndex_Bottom].flags = 1;
    self->windows[CreationWindowIndex_Bottom].noHorizontalInset = 0;
    memset(self->textBuffer, 0, 0x800);
    CharacterCreationUI_WriteYesNoText((char*)self, self->textBuffer, 0);
    Window_OpenPane(&self->windows[CreationWindowIndex_Bottom], self->textBuffer, 0, 0, 0, 0, 0);
#else
    int textX = 0x10;
    unsigned char language = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
    switch (language) {
        case OSLanguage_French: textX = 0xe; break;
        case OSLanguage_Italian: textX = 0x15; break;
        case OSLanguage_German: textX = 0xa; break;
        case OSLanguage_Spanish: textX = 0x15; break;
        default: break;
    }
    CreationWindow* yesNoWindow = &self->windows[CreationWindowIndex_Bottom];
    yesNoWindow->paneWidth = 6;
    yesNoWindow->paneHeight = 5;
    yesNoWindow->unknownA4[0] = 0x1a;
    yesNoWindow->unknownA4[1] = 0xa;
    yesNoWindow->paneTextX = textX;
    yesNoWindow->unknownAa[0] = 0;
    yesNoWindow->unknownAa[1] = 0xc;
    yesNoWindow->unknownAa[2] = 0x10;
    yesNoWindow->nextWindow = BottomWindow_YesNoPane;
    yesNoWindow->fontHeight = 0xc;
    yesNoWindow->flags = 1;
    yesNoWindow->noHorizontalInset = 0;
    void* buf = self->textBuffer;
    memset(buf, 0, 0x960);
    CharacterCreationUI_WriteYesNoText((char*)self, (char*)buf, 0);
    Window_OpenPane(yesNoWindow, buf, 0, 0, 0, 0, 0, 1);
#endif
}
