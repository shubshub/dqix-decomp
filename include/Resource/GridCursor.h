#ifndef RESOURCE_GRIDCURSOR_H
#define RESOURCE_GRIDCURSOR_H

// How a GridCursor numbers its cells: GridCursor_SetDimensions's last argument.
enum GridCursorOrder
{
    GridCursorOrder_ColumnMajor = 0, // index = column * rows + row
    GridCursorOrder_RowMajor = 1,    // index = row * columns + column
};

#endif
