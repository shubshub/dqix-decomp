#include <globaldefs.h>
#include "Graphics/Background.h"

// Main, originally DispatchViaTable0204b5e8 (USA 0x0204b5e8, EUR 0x0204b5f8, JPN 0x0204c408)
ARM int Background_SetScroll(struct BackgroundGraphics* layer, int scrollX, int scrollY) {
    return Background_setScrollFunctions[layer->subScreen_][layer->bgNumber_](scrollX, scrollY);
}
