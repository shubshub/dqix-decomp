#if !defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Cache.h"

extern "C" int MessageSystem_GetInstance(void);
extern "C" void OS_WaitVBlankIntr(void);
extern "C" void func_02023218(void* arg0, void* buf, int flag);
extern "C" int LoadToSubObjVRAM(void* buf, int a1, int a2);

// Main, originally InitAndCopyBuffer020233b8 (USA 0x020233b8, EUR 0x020233c8; JPN not identified)
extern "C" ARM int MapDisplay_UploadTreasureMapName(void* arg0, int flag1)
{
    void* base = (void*)MessageSystem_GetInstance();
    int offset = 0;
    int i = offset;
    void* buf = *(void**)((char*)base + 0x60);
    int copySize = 0x40;
    while (i < 0x13)
    {
        memcpy((char*)buf + offset, (char*)arg0 + 0xbf0, copySize);
        offset += 0x40;
        i++;
    }

    func_02023218(arg0, buf, 0);
    if (flag1 != 0)
    {
        OS_WaitVBlankIntr();
    }

    CleanInvalidateCacheRange(buf, 0x4c0);
    LoadToSubObjVRAM(buf, 0x2c00, 0x4c0);

    return 1;
}

#endif
