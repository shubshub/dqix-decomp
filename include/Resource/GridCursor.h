#ifndef RESOURCE_GRIDCURSOR_H
#define RESOURCE_GRIDCURSOR_H

// How a GridCursor numbers its cells: GridCursor_SetDimensions's last argument.
enum GridCursorOrder
{
    GridCursorOrder_ColumnMajor = 0, // index = column * rows + row
    GridCursorOrder_RowMajor = 1,    // index = row * columns + column
};

// The auto-repeat of a held D-pad key: GridCursor_Init's initialDelay and repeatDelay, in ticks.
enum GridCursorRepeat
{
    GridCursorRepeat_InitialDelay = 20, // the first repeat, after the key has been held this long
    GridCursorRepeat_Delay = 10,        // each repeat after that
};

// The menu grid cursor (0x40 bytes): the selected cell of a columns x rows grid, paged, moved by the D-pad
// (GridCursor_Update). Menus across the game embed one.
struct GridCursor {
    int count;                      // cells that hold something (GridCursor_SetCount)
    int pageCount;
    int columns, rows;
    unsigned char order;            // GridCursorOrder
    unsigned char unknown11[3];
    int page;
    int column, row;
    int* primaryDimension;          // GridCursor_SetDimensions points these at columns/rows and column/row,
    int* secondaryDimension;        // swapped by order
    int* primaryCursor;
    int* secondaryCursor;
    int step;                       // -1 or 1, the direction of the held key
    unsigned short heldKey;         // KEY_UP, KEY_DOWN, KEY_LEFT or KEY_RIGHT
    unsigned char rowRepeat, columnRepeat;
    unsigned char countdown;        // ticks to the next repeat
    unsigned char initialDelay;     // GridCursorRepeat_InitialDelay
    unsigned char repeatDelay;      // GridCursorRepeat_Delay
    unsigned char unknown3b;
    unsigned char wrapColumns, wrapRows;
    unsigned char unknown3e[2];
};

#endif
