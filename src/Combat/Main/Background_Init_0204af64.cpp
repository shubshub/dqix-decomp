#include <globaldefs.h>
#include "Graphics/Background.h"

struct Struct0204a82c;
ARM void TileHeader_Clear(struct Struct0204a82c*);

// Main, originally ResetList0204af64 (USA 0x0204af64, EUR 0x0204af74, JPN 0x0204bd84)
ARM void Background_Init(struct BackgroundGraphics* layer) {
    TileHeader_Clear((struct Struct0204a82c*)layer);
    layer->unk_c = 0;
    layer->paletteMask_ = 0xffff;
    layer->screens_ = 0;
    layer->map_ = 0;
    layer->mapSize_ = 0;
    layer->subScreen_ = 0;
    layer->bgNumber_ = 0;
    layer->screenCount_ = 0;
    layer->screenCapacity_ = 0;
    layer->mapType_ = 0;
}
