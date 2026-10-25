#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "NitroSDK/OSLanguage.h"
#include "Resource/CharacterCreationUI.h"

struct Struct0200fb08;
unsigned char GameState_GetLanguage(struct Struct0200fb08* obj);

extern int KeyTable_Get(struct Container020e0310*, int);

#if defined(jpn)
extern "C" void Window_OpenPane(void* window, void* text, int mode, int border, int flagBit3, int fullWidth, int extraStyle);
#else
extern "C" void Window_OpenPane(void* window, void* text, int mode, int border, int flagBit3, int fullWidth, int extraStyle, int font);
#endif


// Overlay 23, originally func_ov023_021d99a4 (USA/EUR 0x021d99a4, JPN 0x021da1b4)
extern "C" ARM void CharacterCreationUI_CreateSummaryPane(void* objRaw) {
    CharacterCreationUI* self = (CharacterCreationUI*)objRaw;
#if defined(jpn)
    int layout2 = 0x18;
    self->windows[0].paneWidth = 7;
    self->windows[0].paneHeight = 0x11;
    self->windows[0].unknownA4[0] = layout2;
    self->windows[0].unknownA4[1] = 5;
    self->windows[0].paneTextX = 6;
    self->windows[0].unknownAa[0] = 6;
    self->windows[0].unknownAa[1] = 0xa;
    self->windows[0].unknownAa[2] = 0x10;
    unsigned char zero = 0;
    self->windows[0].nextWindow = zero;
    self->windows[0].flags = 1;
    self->windows[0].noHorizontalInset = 1;
    memset(self->textBuffer, zero, 0x800);
    int fmt = KeyTable_Get(&self->texts, CreationText_WidthTag);
    sprintf(self->textBuffer, (const char*)(long)fmt);
    Window_OpenPane(&self->windows[0], self->textBuffer, 0, 0, 0, 0, 0);
#else
    struct Struct0200fb08* gameState = (struct Struct0200fb08*)GameState::GetInstance();
    int layout2 = 0x18;
    int language = GameState_GetLanguage(gameState);
    if (language == OSLanguage_Italian) layout2 = 0x19;
    CreationWindow* window = &self->windows[0];
    window->paneWidth = 7;
    window->paneHeight = 0x11;
    window->unknownA4[0] = layout2;
    window->unknownA4[1] = 5;
    window->paneTextX = 6;
    window->unknownAa[0] = 6;
    window->unknownAa[1] = 0xa;
    window->unknownAa[2] = 0x10;
    unsigned char zero = 0;
    window->nextWindow = zero;
    window->flags = 1;
    window->noHorizontalInset = 1;
    void* buf = self->textBuffer;
    memset(buf, zero, 0x960);
    int fmt = KeyTable_Get(&self->texts, CreationText_WidthTag);
    sprintf((char*)buf, (const char*)(long)fmt);
    Window_OpenPane(window, buf, 0, 0, 0, 0, 0, 0);
#endif
}
