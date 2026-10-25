#include <globaldefs.h>
#include "Resource/GridCursor.h"

int GridCursor_GetSelectedIndex(struct GridCursor* cursor);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);

// Main, originally SetField0AndPropagate0205bacc (USA 0x0205bacc, EUR 0x0205badc, JPN 0x0205ce2c)
ARM void GridCursor_SetCount(struct GridCursor* cursor, int count) {
    if (count < 0) return;
    cursor->count = count;
    if (GridCursor_GetSelectedIndex(cursor) < count) return;
    GridCursor_SetSelectedIndex(cursor, count - 1);
}
