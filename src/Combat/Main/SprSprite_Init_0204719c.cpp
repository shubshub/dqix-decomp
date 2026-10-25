#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// Main, originally func_0204719c (USA 0x0204719c, EUR 0x020471ac, JPN 0x02047fbc)
extern "C" ARM void SprSprite_Init(void* obj)
{
    Foo02048004* f = (Foo02048004*)obj;

    f->word0 = 0;
    f->f6 = 0;
    f->w8 = 0;
    f->wc = 0;
    f->nameTable.count = 0;
    f->f4 = 3;
    f->w10 = 0;
    f->bit0 = 0;
    f->words40[14] = f->words40[15] = 0;
    f->words40[12] = f->words40[13] = 0;
    f->position.x = 0;
    f->position.y = 0;
    f->position.z = 0;
    f->words28[0] = 0;
    f->words28[1] = 0;
    f->words28[2] = 0;
    f->scale.x = 0x1000;
    f->scale.y = 0x1000;
    f->scale.z = 0x1000;
    f->alpha = 0x1f;
    f->color = 0x7fff;
    f->bit1 = 0;
    f->bit2 = 0;
}
