#include <globaldefs.h>
#include "Graphics/Background.h"

// USA: func_0204acb0
ARM void ClearRecordFields(struct BackgroundScreen* screen) {
    screen->width_ = 0;
    screen->height_ = 0;
    screen->unk_4 = 0;
    screen->unk_5 = 0;
    screen->tilesSize_ = 0;
    screen->tiles_ = 0;
}
