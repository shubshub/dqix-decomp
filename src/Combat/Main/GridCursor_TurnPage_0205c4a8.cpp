#include <globaldefs.h>
#include "Resource/GridCursor.h"

extern "C" int GridCursor_GetSelectedIndex(struct GridCursor*);
extern "C" void GridCursor_SetSelectedIndex(void*, int);

// Main, originally AdvanceWrappedAccumulator0205c4a8 (USA 0x0205c4a8, EUR 0x0205c4b8, JPN 0x0205d808)
extern "C" ARM void GridCursor_TurnPage(struct GridCursor* cursor, int delta) {
    int count;
    cursor->page += delta;
    if (cursor->pageCount <= cursor->page) {
        cursor->page -= cursor->pageCount;
    } else if (cursor->page < 0) {
        cursor->page += cursor->pageCount;
    }
    count = cursor->count;
    if (count <= GridCursor_GetSelectedIndex(cursor)) {
        GridCursor_SetSelectedIndex(cursor, count - 1);
    }
}
