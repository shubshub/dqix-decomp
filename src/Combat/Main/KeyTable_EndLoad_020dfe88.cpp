#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "Filesystem/BackgroundLoader.h"


// Main, originally ResetHandleState020dfe88 (USA 0x020dfe88, EUR 0x020dfe98, JPN 0x020e1a5c)
extern "C" ARM int KeyTable_EndLoad(struct Struct020dfc40* table) {
    int src = (int)BackgroundLoader::GetInstance();
    if (table->loadTask >= 0) {
        ((BackgroundLoader*)(src))->RemoveTask((int)(table->loadTask));
        table->loadTask = -1;
    }
    table->loadStep = KeyTableLoadStep_None;
    table->allocator = 0;
    return 1;
}
