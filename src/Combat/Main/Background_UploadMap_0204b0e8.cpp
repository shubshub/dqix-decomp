#include <globaldefs.h>
#include "Graphics/Background.h"

extern "C" void Background_FlushMap(void*, int);
extern "C" void Background_TransferMap(void*, int);


// Main, originally FlushAndDispatchList0204b0e8 (USA 0x0204b0e8, EUR 0x0204b0f8, JPN 0x0204bf08)
extern "C" ARM void Background_UploadMap(struct BackgroundGraphics* layer, void* map) {
    if (map == NULL) map = layer->map_;
    if (map == NULL) return;
    Background_FlushMap(layer, (int)map);
    Background_TransferMap(layer, (int)map);
}
