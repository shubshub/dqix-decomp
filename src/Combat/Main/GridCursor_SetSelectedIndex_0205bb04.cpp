#include <globaldefs.h>
#include "Resource/GridCursor.h"

// Main, originally func_0205bb04 (USA 0x0205bb04, EUR 0x0205bb14, JPN 0x0205ce64)
extern "C" ARM void GridCursor_SetSelectedIndex(struct GridCursor* cursor, int index) {
    if (index < 0) return;
    if (index >= cursor->count) return;
    int cellsPerPage = cursor->rows * cursor->columns;
    if (cellsPerPage == 0) return;
    cursor->page = index / cellsPerPage;
    index = index % cellsPerPage;
    *cursor->secondaryCursor = index % *cursor->secondaryDimension;
    *cursor->primaryCursor = index / *cursor->secondaryDimension;
}
