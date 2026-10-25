#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"
#include "Combat/TryApplyElemFields.h"

int KeyTable_Get(Container020e0310*, int);
int Text_Append(char*, const char*);

// USA: 021d9d34; JPN: 021da5d8.
ARM void RefreshFieldIfFlag4000_021d9d34(char* obj) {
    CharacterCreationUI* self = (CharacterCreationUI*)obj;
    if (!(self->flags & 0x4000)) return;
#if defined(jpn)
    memset(self->textBuffer, 0, 0x800);
    int fieldVal = KeyTable_Get(&self->texts, CreationText_WidthTag);
    Text_Append(self->textBuffer, (const char*)fieldVal);
    Window_SetPaneText((StructA0205d5d0*)&self->windows[1], 2,
                             (int)self->textBuffer, 1);
#else
    char* buf = self->textBuffer;
    memset(buf, 0, 0x960);
    int fieldVal = KeyTable_Get(&self->texts, CreationText_WidthTag);
    Text_Append(buf, (const char*)fieldVal);
    Window_SetPaneText((StructA0205d5d0*)&self->windows[1], 2, (int)buf, 1, 0);
#endif
    self->flags &= ~0x4000;
}
