#include <globaldefs.h>
#include "Resource/GridCursor.h"

// Main, originally func_0205bb84 (USA 0x0205bb84, EUR 0x0205bb94, JPN 0x0205cee4)
ARM int GridCursor_GetSelectedIndex(struct GridCursor* cursor) {
    int indexInPage = *cursor->secondaryDimension * *cursor->primaryCursor + *cursor->secondaryCursor;
    int pageOffset = cursor->page * cursor->rows * cursor->columns;
    return (short)pageOffset + (short)indexInPage;
}
