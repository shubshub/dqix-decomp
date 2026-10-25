#include <globaldefs.h>
#include "Resource/GridCursor.h"

// Main, originally SetupPointerTable0205ba68 (USA 0x0205ba68, EUR 0x0205ba78, JPN 0x0205cdc8)
ARM void GridCursor_SetDimensions(struct GridCursor* cursor, int columns, int rows, int order) {
    cursor->columns = columns;
    cursor->rows = rows;
    cursor->order = order;
    if (order == GridCursorOrder_ColumnMajor) {
        cursor->primaryDimension = &cursor->columns;
        cursor->secondaryDimension = &cursor->rows;
        cursor->primaryCursor = &cursor->column;
        cursor->secondaryCursor = &cursor->row;
    } else if (order == GridCursorOrder_RowMajor) {
        cursor->primaryDimension = &cursor->rows;
        cursor->secondaryDimension = &cursor->columns;
        cursor->primaryCursor = &cursor->row;
        cursor->secondaryCursor = &cursor->column;
    }
}
