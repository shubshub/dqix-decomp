#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "Resource/GridCursor.h"
#include "Resource/Keyboard.h"

struct Struct_0205bef8;
void GridCursor_Init(struct Struct_0205bef8* s);
struct Struct_0205ba68;
void GridCursor_SetDimensions(struct Struct_0205ba68* s, int columns, int rows, int mode);
struct Node0205bacc;
void GridCursor_SetCount(struct Node0205bacc* s, int val);
struct SelfBB04;
extern "C" void GridCursor_SetSelectedIndex(struct SelfBB04* self, int value);

// Overlay 9, originally func_ov009_02188c2c (USA/EUR 0x02188c2c, JPN 0x02189af0)
extern "C" ARM void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI* self) {
    int columns, rows, count, pageCount, selected;
    signed char id = self->state;

    switch (id) {
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

    CreationNavigation* navigation = &self->navigation;
    GridCursor_Init((struct Struct_0205bef8*)navigation);
    GridCursor_SetDimensions((struct Struct_0205ba68*)navigation, columns, rows, GridCursorOrder_RowMajor);
    GridCursor_SetCount((struct Node0205bacc*)navigation, count);
    navigation->pageCount = pageCount;
    GridCursor_SetSelectedIndex((struct SelfBB04*)navigation, selected);
    navigation->wrapRows = 0;
}
