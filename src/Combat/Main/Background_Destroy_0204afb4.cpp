#include <globaldefs.h>
#include "Graphics/Background.h"

struct Struct0204a82c;
extern "C" void TileHeader_Clear(struct Struct0204a82c* s);
extern "C" void ClearRecordFields(struct BackgroundScreen* rec);

// Main, originally ResetRecordList0204afb4 (USA 0x0204afb4, EUR 0x0204afc4, JPN 0x0204bdd4)
extern "C" ARM void Background_Destroy(struct BackgroundGraphics* layer) {
    unsigned char i;
    layer->map_ = 0;
    TileHeader_Clear((struct Struct0204a82c*)layer);
    layer->unk_c = 0;
    layer->paletteMask_ = 0xffff;
    if (layer->screens_ == 0) return;
    i = 0;
    while (i < layer->screenCount_) {
        ClearRecordFields(&layer->screens_[i]);
        i++;
    }
}
