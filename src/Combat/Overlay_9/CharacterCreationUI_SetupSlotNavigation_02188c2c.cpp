#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "Resource/GridCursor.h"
#include "Resource/Keyboard.h"

// The struct tags stay: these functions' C++ symbols are mangled with them.
struct GridCursor;
void GridCursor_Init(struct GridCursor* cursor);
void GridCursor_SetDimensions(struct GridCursor* cursor, int columns, int rows, int order);
void GridCursor_SetCount(struct GridCursor* cursor, int count);
extern "C" void GridCursor_SetSelectedIndex(GridCursor* cursor, int index);

// Overlay 9, originally func_ov009_02188c2c (USA/EUR 0x02188c2c, JPN 0x02189af0)
extern "C" ARM void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self) {
    int columns, rows, count, pageCount, selected;
    signed char tab = self->state;

    switch (tab) {
    case CreationTab_Gender:
        columns = 1;
        rows = 2;
        count = rows;
        pageCount = columns;
        selected = self->sex;
        break;
    case CreationTab_BodyType: {
        unsigned char sex = self->sex;
        columns = 5;
        rows = 1;
        count = columns;
        pageCount = rows;
        selected = self->bodyType[sex];
        break;
    }
    case CreationTab_HairStyle: {
        unsigned char sex = self->sex;
        columns = 5;
        rows = 2;
        selected = self->hairStyle[sex];
        count = 0xa;
        pageCount = 1;
        break;
    }
    case CreationTab_HairColor: {
        unsigned char sex = self->sex;
        columns = 5;
        rows = 2;
        selected = self->hairColor[sex];
        count = 0xa;
        pageCount = 1;
        break;
    }
    case CreationTab_Face: {
        unsigned char sex = self->sex;
        columns = 5;
        rows = 2;
        selected = self->faceStyle[sex];
        count = 0xa;
        pageCount = 1;
        break;
    }
    case CreationTab_SkinColor: {
        unsigned char sex = self->sex;
        columns = 4;
        rows = 2;
        selected = self->skinColor[sex];
        count = 8;
        pageCount = 1;
        break;
    }
    case CreationTab_EyeColor: {
        unsigned char sex = self->sex;
        columns = 4;
        rows = 2;
        selected = self->eyeColor[sex];
        count = 8;
        pageCount = 1;
        break;
    }
    case CreationTab_NameEntry:
        columns = KeyboardGrid_Columns;
        rows = KeyboardGrid_Rows;
        count = KeyboardGrid_Cells;
        pageCount = 1;
#if defined(jpn)
        selected = self->keyboardChoice;
#else
        selected = 0;
#endif
        break;
    default:
        break;
    }

    GridCursor* navigation = &self->navigation;
    GridCursor_Init((struct GridCursor*)navigation);
    GridCursor_SetDimensions((struct GridCursor*)navigation, columns, rows, GridCursorOrder_RowMajor);
    GridCursor_SetCount((struct GridCursor*)navigation, count);
    navigation->pageCount = pageCount;
    GridCursor_SetSelectedIndex(navigation, selected);
    navigation->wrapRows = 0;
}
