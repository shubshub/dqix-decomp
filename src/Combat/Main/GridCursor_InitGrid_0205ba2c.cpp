#include <globaldefs.h>
#include "Resource/GridCursor.h"

// Main, originally InitStruct_0205ba2c (USA 0x0205ba2c, EUR 0x0205ba3c, JPN 0x0205cd8c)
ARM void GridCursor_InitGrid(struct GridCursor* cursor) {
    cursor->count = 0;
    cursor->pageCount = 1;
    cursor->columns = 1;
    cursor->rows = 1;
    cursor->order = 0;
    cursor->page = 0;
    cursor->column = 0;
    cursor->row = 0;
    cursor->primaryDimension = 0;
    cursor->secondaryDimension = 0;
    cursor->primaryCursor = 0;
    cursor->secondaryCursor = 0;
}
