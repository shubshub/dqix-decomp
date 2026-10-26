#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"

extern "C" int KeyTable_Get(Container020e0310*, int);
struct Ctx0205d304;
extern "C" void Window_OpenPane(Ctx0205d304* renderer, const char* text, int mode,
                            unsigned char border, unsigned char flagBit3,
                            unsigned char fullWidth, void* extraStyle
#if !defined(jpn)
                            , unsigned char font
#endif
);

// USA: 021d9c7c; JPN: 021da52c.
extern "C" ARM void func_ov023_021d9c7c(void* objRaw) {
    CharacterCreationUI* self = (CharacterCreationUI*)objRaw;
#if defined(jpn)
    self->windows[1].paneWidth = 0xd;
    self->windows[1].paneHeight = 2;
    self->windows[1].unknownA4[0] = 2;
    self->windows[1].unknownA4[1] = 0x13;
    self->windows[1].paneTextX = 2;
    self->windows[1].unknownAa[0] = 2;
    self->windows[1].unknownAa[1] = 0xa;
    self->windows[1].unknownAa[2] = 0xc;
    self->windows[1].nextWindow = 2;
    self->windows[1].fontHeight = 0xa;
    self->windows[1].flags = 1;
    self->windows[1].noHorizontalInset = 1;
    memset(self->textBuffer, 0, 0x800);
    int fmt = KeyTable_Get(&self->texts, CreationText_WidthTag);
    sprintf(self->textBuffer, (const char*)fmt);
    Window_OpenPane((Ctx0205d304*)&self->windows[1], self->textBuffer, 0, 0, 0, 1, 0);
#else
    CreationWindow* tag = &self->windows[1];
    tag->paneWidth = 0xd;
    tag->paneHeight = 2;
    tag->unknownA4[0] = 2;
    tag->unknownA4[1] = 0x13;
    tag->paneTextX = 2;
    tag->unknownAa[0] = 2;
    tag->unknownAa[1] = 0xa;
    tag->unknownAa[2] = 0xc;
    tag->nextWindow = 2;
    tag->fontHeight = 0xa;
    tag->flags = 1;
    tag->noHorizontalInset = 1;
    char* buf = self->textBuffer;
    memset(buf, 0, 0x960);
    int fmt = KeyTable_Get(&self->texts, CreationText_WidthTag);
    sprintf(buf, (const char*)fmt);
    Window_OpenPane((Ctx0205d304*)tag, buf, 0, 0, 0, 1, 0, 0);
#endif
}
