#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"

// Main, originally Init0205a198 (USA 0x0205a198, EUR 0x0205a1a8, JPN 0x0205b510)
extern "C" ARM void Sprite_Init(Struct0205a198 *sprite) {
    memset(sprite, 0, 8);
    sprite->copy = 0;
    sprite->field0c = sprite->field10 = 0x1000;
    sprite->field14 = sprite->field18 = 0;
    sprite->field1c = 0;
    sprite->index = 0;
    sprite->field20 = 0;
    sprite->firstCell = 0;
    sprite->field23 = 0;
    sprite->field24 = 0;
    int minusOne = sprite->field24 - 1;
    sprite->field25 = minusOne;
    sprite->field26 = minusOne;
}
