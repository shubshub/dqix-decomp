#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"

int KeyTable_Get(Container020e0310*, int);
extern "C" void Window_OpenPane(CreationWindow* window, const char* text, int mode,
                            unsigned char border, unsigned char flagBit3,
                            unsigned char fullWidth, void* extraStyle
#if !defined(jpn)
                            , unsigned char font
#endif
);

// Overlay 23, originally SetupTag021d9da4 (USA/EUR 0x021d9da4, JPN 0x021da63c)
ARM void CharacterCreationUI_CreateNamePane(void* objRaw) {
    CharacterCreationUI* self = (CharacterCreationUI*)objRaw;
#if defined(jpn)
    self->windows[1].paneWidth = 0xa;
    self->windows[1].paneHeight = 2;
    self->windows[1].unknownA4[0] = 0xb;
    self->windows[1].unknownA4[1] = 4;
    self->windows[1].paneTextX = 0;
    self->windows[1].unknownAa[0] = 2;
    self->windows[1].unknownAa[1] = 0x11;
    self->windows[1].unknownAa[2] = 0x10;
    self->windows[1].nextWindow = 3;
    self->windows[1].fontHeight = 0xa;
    self->windows[1].flags = 1;
    self->windows[1].noHorizontalInset = 1;
    memset(self->textBuffer, 0, 0x800);
    int fmt = KeyTable_Get(&self->texts, CreationText_WidthTag);
    sprintf(self->textBuffer, (const char*)fmt);
    Window_OpenPane(&self->windows[1], self->textBuffer, 0, 0, 0, 0, 0);
#else
    CreationWindow* window = &self->windows[1];
    window->paneWidth = 0xa;
    window->paneHeight = 2;
    window->unknownA4[0] = 0xb;
    window->unknownA4[1] = 4;
    window->paneTextX = 0;
    window->unknownAa[0] = 2;
    window->unknownAa[1] = 0x11;
    window->unknownAa[2] = 0x10;
    window->nextWindow = 3;
    window->fontHeight = 0xa;
    window->flags = 1;
    window->noHorizontalInset = 1;
    char* buf = self->textBuffer;
    memset(buf, 0, 0x960);
    int fmt = KeyTable_Get(&self->texts, CreationText_WidthTag);
    sprintf(buf, (const char*)fmt);
    Window_OpenPane(window, buf, 0, 0, 0, 0, 0, 0);
#endif
}
