#pragma once

// Where a character creation tab's options sit on the touchscreen: option n is at column n % columns,
// row n / columns, in a width x height box. Used for the highlight box and for touch hits.
struct ChoiceGrid {
    int x, y;
    int width, height;
    int stepX; // Distance from one column to the next
    int stepY; // Distance from one row to the next
    int columns, rows;
};
