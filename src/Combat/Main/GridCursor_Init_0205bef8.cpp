#include <globaldefs.h>
#include "Resource/GridCursor.h"

extern "C" void GridCursor_InitGrid(struct GridCursor*);

// Main, originally Init0205bef8 (USA 0x0205bef8, EUR 0x0205bf08, JPN 0x0205d258)
extern "C" ARM void GridCursor_Init(struct GridCursor* cursor) {
    GridCursor_InitGrid(cursor);
    cursor->step = 0;
    cursor->heldKey = 0;
    cursor->rowRepeat = 0;
    cursor->columnRepeat = 0;
    cursor->countdown = 0;
    cursor->initialDelay = GridCursorRepeat_InitialDelay;
    cursor->repeatDelay = GridCursorRepeat_Delay;
    cursor->wrapColumns = 1;
    cursor->wrapRows = 1;
}
