#include <globaldefs.h>
#include "Resource/GridCursor.h"

// Main, originally ResetState0205bf3c (USA 0x0205bf3c, EUR 0x0205bf4c, JPN 0x0205d29c)
extern "C" ARM void GridCursor_ResetKeyRepeat(struct GridCursor* cursor) {
    cursor->step = 0;
    cursor->heldKey = 0;
    cursor->rowRepeat = 0;
    cursor->columnRepeat = 0;
    cursor->countdown = 0;
}
