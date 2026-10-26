#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Memory/PlacementNew.h"

// Main, originally ResetNameTableThenNotify_0201c0e8 (USA 0x0201c0e8, EUR 0x0201c0f8, JPN 0x0201be60)
ARM void* SprSprite_Construct(void* storage)
{
    Foo02048004* sprite = new (storage) Foo02048004;
    ClearNameTable(&sprite->nameTable);
    SprSprite_Init(sprite);
    return storage;
}
