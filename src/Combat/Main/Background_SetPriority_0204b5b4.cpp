#include <globaldefs.h>
#include "Graphics/Background.h"
#include "NitroSDK/Graphics.h"

static inline int (*tbl_at(int subScreen, int bgNumber))(int) {
    return Background_setPriorityFunctions[subScreen][bgNumber];
}

// Main, originally func_0204b5b4 (USA 0x0204b5b4, EUR 0x0204b5c4, JPN 0x0204c3d4)
extern "C" ARM void Background_SetPriority(struct BackgroundGraphics* layer, int priority) {
    tbl_at(layer->subScreen_, layer->bgNumber_)(priority & BGCNT_MASK_PRIORITY);
}
