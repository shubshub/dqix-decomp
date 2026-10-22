#ifndef RESOURCE_KEYBOARD_H
#define RESOURCE_KEYBOARD_H

// The software keyboard in overlay 3 that names are typed on.

// The pages of keys. Each key carries a mask of the pages it shows on: letters on both cases, the bottom row
// on every page.
enum KeyboardPage
{
    KeyboardPage_Lowercase = 0x1,
    KeyboardPage_Uppercase = 0x2,
    KeyboardPage_Accents = 0x4,
    KeyboardPage_Symbols = 0x8,
};

// A key's action: its slot in the key action table that Keyboard_HandleKey calls through.
enum KeyboardAction
{
    KeyboardAction_Type = 0,
    KeyboardAction_ToggleCaps = 1,
    KeyboardAction_Shift = 2,
    KeyboardAction_LettersPage = 3,
    KeyboardAction_AccentsPage = 4,
    KeyboardAction_Delete = 5,
    KeyboardAction_Ok = 6,
    KeyboardAction_SymbolsPage = 7,
    KeyboardAction_RandomName = 8,
};

// What Keyboard_Update returns for a frame.
enum KeyboardResult
{
    KeyboardResult_None = 0,
    KeyboardResult_CursorMoved = 1,
    KeyboardResult_Typed = 2,
    KeyboardResult_TypedFull = 3,
    KeyboardResult_CapsToggled = 4,
    KeyboardResult_Shifted = 5,
    KeyboardResult_LettersPage = 6,
    KeyboardResult_AccentsPage = 7,
    KeyboardResult_Deleted = 8,
    KeyboardResult_NothingToDelete = 9,
    KeyboardResult_Ok = 10,
    KeyboardResult_SymbolsPage = 11,
    KeyboardResult_RandomName = 12,
    KeyboardResult_KeyDisabled = 13,
};

// The name keyboard as a grid for a GridCursor: 11 columns by 6 rows.
enum KeyboardGrid
{
    KeyboardGrid_Columns = 11,
    KeyboardGrid_Rows = 6,
    KeyboardGrid_Cells = KeyboardGrid_Columns * KeyboardGrid_Rows,
};

#endif
