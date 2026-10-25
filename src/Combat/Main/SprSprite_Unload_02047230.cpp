#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// Main, originally MaybeInvoke0204719c_02047230 (USA 0x02047230, EUR 0x02047240, JPN 0x02048050)
ARM void SprSprite_Unload(Foo02048004* obj)
{
    if (obj->bit0)
        SprSprite_Init(obj);
}
