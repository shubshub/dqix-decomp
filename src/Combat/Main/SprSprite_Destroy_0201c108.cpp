#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// Main, originally NotifyThenResetNameTable_0201c108 (USA 0x0201c108, EUR 0x0201c118, JPN 0x0201be80)
extern "C" ARM void* SprSprite_Destroy(void* obj)
{
    Foo02048004* block = static_cast<Foo02048004*>(obj);
    SprSprite_Unload(block);
    func_02048080(&block->nameTable);
    block->~Foo02048004();
    return obj;
}
