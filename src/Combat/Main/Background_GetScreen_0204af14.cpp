#include <globaldefs.h>
#include "Graphics/Background.h"

// Main, originally GetEntryByIndexStride0x10 (USA 0x0204af14, EUR 0x0204af24, JPN 0x0204bd34)
ARM void* Background_GetScreen(struct BackgroundGraphics* layer, unsigned int index) {
    BackgroundScreen* screens = layer->screens_;
    if (screens == NULL) {
        return NULL;
    }
    return (layer->screenCount_ <= index) ? NULL : screens + index;
}
