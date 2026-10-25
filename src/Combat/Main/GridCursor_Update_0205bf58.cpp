#include <globaldefs.h>
#include "Resource/GridCursor.h"
#include "Input/Input.h"

struct NavigationSteps { int values[4]; };
struct NavigationKeys { unsigned short values[5]; };
struct NavigationRepeatDirections { unsigned char values[4]; };
void GridCursor_ResetKeyRepeat(GridCursor*);
int GridCursor_GetSelectedIndex(GridCursor*);
void GridCursor_TurnPage(GridCursor*, int);
extern "C" void GridCursor_SetSelectedIndex(GridCursor*, int);
extern const NavigationKeys GridCursor_directionKeys;
extern const NavigationSteps GridCursor_directionSteps;
extern const NavigationRepeatDirections GridCursor_directionRowRepeats, GridCursor_directionColumnRepeats;

// Main, originally func_0205bf58 (USA 0x0205bf58, EUR 0x0205bf68, JPN 0x0205d2b8)
extern "C" ARM int GridCursor_Update(GridCursor* cursor, unsigned int ticks) {
    if (cursor->count == 0) return 0;
    if (cursor->columns <= 0) return 0;
    if (cursor->rows <= 0) return 0;
    unsigned char initialDelay = cursor->initialDelay;
    unsigned char repeatDelay = cursor->repeatDelay;
    NavigationKeys keys = GridCursor_directionKeys;
    int direction = 0;
    while (keys.values[direction] != 0xffff && cursor->heldKey == 0) {
        unsigned short key = keys.values[direction];
        if (g_keyManager.TestKeysPressed(key)) {
            if (cursor->rowRepeat | cursor->columnRepeat) {
                GridCursor_ResetKeyRepeat(cursor);
                break;
            }
            NavigationSteps steps = GridCursor_directionSteps;
            NavigationRepeatDirections rowRepeats = GridCursor_directionRowRepeats;
            NavigationRepeatDirections columnRepeats = GridCursor_directionColumnRepeats;
            cursor->heldKey = key;
            cursor->countdown = initialDelay;
            cursor->step = steps.values[direction];
            cursor->rowRepeat = rowRepeats.values[direction];
            cursor->columnRepeat = columnRepeats.values[direction];
            if (cursor->heldKey == KEY_UP || cursor->heldKey == KEY_DOWN) {
                int previous = cursor->row;
                cursor->row += cursor->step;
                if (cursor->wrapRows) {
                    if (cursor->rows <= cursor->row) cursor->row = 0;
                    else if (cursor->row < 0) cursor->row = cursor->rows - 1;
                    if (cursor->heldKey == KEY_UP) {
                        int total = cursor->count;
                        if (total <= GridCursor_GetSelectedIndex(cursor))
                            GridCursor_SetSelectedIndex(cursor, total - 1);
                    } else if (cursor->heldKey == KEY_DOWN) {
                        if (cursor->count <= GridCursor_GetSelectedIndex(cursor))
                            cursor->row = 0;
                    }
                } else {
                    if (cursor->rows <= cursor->row) cursor->row = previous;
                    else if (cursor->row < 0) cursor->row = previous;
                    if (GridCursor_GetSelectedIndex(cursor) >= cursor->count)
                        cursor->row = previous;
                }
            } else if (cursor->heldKey == KEY_LEFT || cursor->heldKey == KEY_RIGHT) {
                int previous = cursor->column;
                cursor->column += cursor->step;
                if (cursor->columns <= cursor->column) {
                    if (cursor->wrapColumns) {
                        cursor->column = 0;
                        if (cursor->pageCount > 1) GridCursor_TurnPage(cursor, 1);
                    } else {
                        if (cursor->pageCount == 1) cursor->column = previous;
                        else {
                            cursor->column = 0;
                            GridCursor_TurnPage(cursor, 1);
                        }
                    }
                } else if (cursor->column < 0) {
                    if (cursor->wrapColumns) {
                        cursor->column = cursor->columns - 1;
                        if (cursor->pageCount > 1) GridCursor_TurnPage(cursor, -1);
                    } else {
                        if (cursor->pageCount == 1) cursor->column = previous;
                        else {
                            cursor->column = cursor->columns - 1;
                            GridCursor_TurnPage(cursor, -1);
                        }
                    }
                }
                if (GridCursor_GetSelectedIndex(cursor) >= cursor->count) {
                    if (cursor->pageCount == 1) cursor->column = previous;
                    else {
                        cursor->column = 0;
                        GridCursor_TurnPage(cursor, 1);
                    }
                }
            }
            return 1;
        }
        ++direction;
    }
    if (cursor->rowRepeat) {
        if (g_keyManager.TestKeysHeld(KEY_DPAD)) {
            unsigned char elapsed = ticks;
            if (elapsed < cursor->countdown) cursor->countdown -= elapsed;
            else {
                cursor->countdown = repeatDelay;
                cursor->rowRepeat = 1;
                cursor->columnRepeat = 0;
                cursor->row += cursor->step;
                if (cursor->rows <= cursor->row) cursor->row = cursor->rows - 1;
                else if (cursor->row < 0) cursor->row = 0;
                int total = cursor->count;
                if (total <= GridCursor_GetSelectedIndex(cursor))
                    GridCursor_SetSelectedIndex(cursor, total - 1);
                if (cursor->heldKey == KEY_UP || cursor->heldKey == KEY_LEFT) {
                    int total = cursor->count;
                    if (total <= GridCursor_GetSelectedIndex(cursor))
                        GridCursor_SetSelectedIndex(cursor, total - 1);
                } else if (cursor->heldKey == KEY_DOWN || cursor->heldKey == KEY_RIGHT) {
                    if (cursor->count <= GridCursor_GetSelectedIndex(cursor))
                        cursor->row = 0;
                }
            }
        }
        if (g_keyManager.TestKeysReleased(KEY_DPAD)) GridCursor_ResetKeyRepeat(cursor);
        return 1;
    } else if (cursor->columnRepeat) {
        if (g_keyManager.TestKeysHeld(KEY_DPAD)) {
            unsigned char elapsed = ticks;
            if (elapsed < cursor->countdown) cursor->countdown -= elapsed;
            else {
                cursor->countdown = repeatDelay;
                cursor->rowRepeat = 0;
                cursor->columnRepeat = 1;
                cursor->column += cursor->step;
                if (cursor->columns <= cursor->column) {
                    cursor->column = cursor->columns - 1;
                    GridCursor_TurnPage(cursor, 1);
                } else if (cursor->column < 0) {
                    cursor->column = 0;
                    GridCursor_TurnPage(cursor, -1);
                }
                if (GridCursor_GetSelectedIndex(cursor) >= cursor->count) {
                    if (cursor->pageCount == 1) cursor->column = 0;
                    else {
                        cursor->column = 0;
                        GridCursor_TurnPage(cursor, 1);
                    }
                }
            }
        }
        if (g_keyManager.TestKeysReleased(KEY_DPAD)) GridCursor_ResetKeyRepeat(cursor);
        return 1;
    }
    return 0;
}
