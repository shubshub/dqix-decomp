#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

// Overlay 9, originally func_ov009_02188e70 (USA/EUR 0x02188e70, JPN 0x02189d30)
extern "C" ARM void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI* editor, int choice) {
    CreationSlotLayout* grid = &editor->grid;
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
    int column = choice % columns;
    int row = choice / columns;
    editor->cursorX = grid->stepX * column + grid->x;
    editor->cursorY = stepY * row + y;
#else
    editor->cursorX = grid->stepX * (choice % columns) + grid->x;
    editor->cursorY = stepY * (choice / columns) + y;
#endif
    editor->cursorWidth = width;
    editor->cursorHeight = height;
#if defined(jpn)
    if (editor->state == 8) {
        if (column >= 5)
            editor->cursorX += 8;
        if (column == columns - 1) {
            editor->cursorX += 16;
            editor->cursorWidth += 8;
            if (row == 5)
                editor->cursorWidth += 8;
        }
    }
#endif
    editor->lastCursorX = editor->cursorX;
    editor->lastCursorY = editor->cursorY;
}
