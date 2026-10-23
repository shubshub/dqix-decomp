#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"

// Main, originally Init0205a198 (USA 0x0205a198, EUR 0x0205a1a8, JPN 0x0205b510)
ARM void Sprite_Init(Struct0205a198 *p) {
    memset(p, 0, 8);
    p->copy = 0;
    p->field0c = p->field10 = 0x1000;
    p->field14 = p->field18 = 0;
    p->field1c = 0;
    p->index = 0;
    p->field20 = 0;
    p->firstCell = 0;
    p->field23 = 0;
    p->field24 = 0;
    int d = p->field24 - 1;
    p->field25 = d;
    p->field26 = d;
}
