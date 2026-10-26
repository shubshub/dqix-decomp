#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "Resource/CreationEnums.h"
#include "Resource/CreationSlotLayout.h"

// CharacterCreationUI's usa/eur layout; jpn's copy of this function (0x0218a8b4) is still asm. The pads stand for
// the header's fields (allocators ... camera; step ... unknownBeforeFlags).
struct CharacterCreation {
    unsigned char pad000[0xbec];
    GridCursor navigation;
    CreationSlotLayout grid;
    short cursorX, cursorY, cursorWidth, cursorHeight;
    short lastCursorX, lastCursorY;
    signed char state;
    unsigned char padC59[0xd9c - 0xc59];
    unsigned int flags;
};

// The Confirm and Back buttons at the bottom right of the touchscreen (CharacterCreationUI_PlaceSprites puts
// their usa sprites at x 0x8e and 0xc8, y 0xa9). Seen in-game: touching (166, 173) and (150, 173) confirmed, (220, 173) and (214, 173) went back.
enum CreationButton
{
    CreationButton_Top = 0xa9,
    CreationButton_Bottom = 0xb1,
    CreationButton_ConfirmStart = 0x8e,
    CreationButton_ConfirmEnd = 0xbe,
    CreationButton_BackStart = 0xc8,
    CreationButton_BackEnd = 0xf0,
};

// The row of tab icons at the top of the touchscreen, one per tab from Gender to NameEntry: icon N is the
// 16 x 16 square at x = 0x78 + N * 16, y = 8 (where CharacterCreationUI_PlaceSprites puts their sprites).

// A touch on nothing: not a button, a tab icon or a slot. CharacterCreationUI_HandleInput ignores it.

struct GridCursor;
extern "C" int GridCursor_GetCount(void*);
extern "C" int GridCursor_GetSelectedIndex(GridCursor*);

extern "C" {
    void GridCursor_SetSelectedIndex(void*, int);
    void CharacterCreationUI_SetupSlotNavigation(CharacterCreation*);
    void CharacterCreationUI_MoveCursorToSlot(CharacterCreation*, int);

// Overlay 9, originally func_ov009_02189854 (USA/EUR 0x02189854, JPN 0x0218a8b4)
    ARM int CharacterCreationUI_GetTouchedInput(CharacterCreation* self, int touchX, int touchY) {
        if (touchY >= CreationButton_Top && touchY <= CreationButton_Bottom) {
            if (touchX >= CreationButton_ConfirmStart && touchX <= CreationButton_ConfirmEnd)
                return CreationInput_Confirm;
            if (touchX >= CreationButton_BackStart && touchX <= CreationButton_BackEnd)
                return CreationInput_Back;
        }
        if (touchY >= CreationTabIcon_Y && touchY <= CreationTabIcon_Y + CreationTabIcon_Size) {
            for (int icon = 0; icon < CreationTabIcon_Count; ++icon) {
                int x = icon * CreationTabIcon_Size + CreationTabIcon_FirstX;
                int maxX = x + CreationTabIcon_Size;
                if (touchX >= x && touchX <= maxX)
                    return icon + CreationInput_FirstTabIcon;
            }
        }

        CreationSlotLayout* layout = &self->grid;
        int width = layout->width;
        int height = layout->height;
        int stepX = layout->stepX;
        int stepY = layout->stepY;
        int columns = layout->columns;
        int rows = layout->rows;
        int slot = CreationInput_NothingTouched;
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                int x = layout->x + stepX * column;
                if (self->state == CreationTab_NameEntry)
                    break;
                int maxX = x + width;
                if (touchX >= x && touchX <= maxX) {
                    int y = layout->y + stepY * row;
                    int var16 = y + height;
                    if (touchY >= y && touchY <= var16) {
                        slot = column + row * columns;
                        self->cursorX = x;
                        self->cursorY = y;
                        self->cursorWidth = width;
                        self->cursorHeight = height;
                        break;
                    }
                }
            }
            if (slot >= 0)
                break;
        }

        int navigationRows = self->navigation.rows;
        int navigationCount = GridCursor_GetCount(&self->navigation);
        if (navigationRows == 1 && navigationCount == CreationTabIcon_Count && slot >= 0 &&
            slot != CreationInput_FirstTabIcon && slot != CreationInput_LastTabIcon) {
            CharacterCreationUI_SetupSlotNavigation(self);
            GridCursor_SetSelectedIndex(&self->navigation, slot);
            self->flags |= CreationFlag_RedrawPanel;
            int selectedSlot = GridCursor_GetSelectedIndex((GridCursor*)&self->navigation);
            CharacterCreationUI_MoveCursorToSlot(self, selectedSlot);
        }
        return slot;
    }
}
