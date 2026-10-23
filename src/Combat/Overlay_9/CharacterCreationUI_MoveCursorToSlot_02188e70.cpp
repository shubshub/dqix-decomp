#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

// Overlay 9, originally func_ov009_02188e70 (USA/EUR 0x02188e70, JPN 0x02189d30)
extern "C" ARM void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* self, int slot) {
    CreationSlotLayout* grid = &self->grid;
    int y;
    int width;
    int height;
    int stepY;
    int columns = grid->columns;
    y = grid->y;
    width = grid->width;
    height = grid->height;
    stepY = grid->stepY;
#if defined(jpn)
    int column = slot % columns;
    int row = slot / columns;
    self->cursorX = grid->stepX * column + grid->x;
    self->cursorY = stepY * row + y;
#else
    self->cursorX = grid->stepX * (slot % columns) + grid->x;
    self->cursorY = stepY * (slot / columns) + y;
#endif
    self->cursorWidth = width;
    self->cursorHeight = height;
#if defined(jpn)
    if (self->state == CreationTab_NameEntry) {
        if (column >= 5)
            self->cursorX += 8;
        if (column == columns - 1) {
            self->cursorX += 16;
            self->cursorWidth += 8;
            if (row == 5)
                self->cursorWidth += 8;
        }
    }
#endif
    self->lastCursorX = self->cursorX;
    self->lastCursorY = self->cursorY;
}
