#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xbf0
#else
#define REGION_OFFSET_0 0xaf0
#endif

#include "Memory/SafeAllocator.h"

extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov000_02172944(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void func_ov000_02172978(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);

struct Struct_ov000_02172850 {
    unsigned short priority : 2;
    unsigned short charBase : 4;
    unsigned short pad1 : 1;
    unsigned short colorMode : 1;
    unsigned short screenBase : 5;
    unsigned short bit13 : 1;
    unsigned short screenSize : 2;
};

// USA: func_ov000_02172850
extern "C" ARM void func_ov000_02172850(char* obj) {
    class SafeAllocator* alloc = *(class SafeAllocator**)(obj + 0x1000 + REGION_OFFSET_0);
    if (alloc) alloc->Reset();

    int var1 = *(int*)(obj + 0x184);
    if (var1) MapVRAMBanksToSubBG(var1);

    struct Struct_ov000_02172850* val2 = (struct Struct_ov000_02172850*)(obj + 0x180);
    struct Struct_ov000_02172850* val1 = (struct Struct_ov000_02172850*)(obj + 0x182);
    func_ov000_02172944(val2->screenSize, val2->colorMode, val2->screenBase, val2->charBase, val1->bit13);
    func_ov000_02172978(val1->screenSize, val1->colorMode, val1->screenBase, val1->charBase, val1->bit13);

    unsigned short* var4 = (unsigned short*)0x4001008;
    var4[0] = (var4[0] & ~3) | val2->priority;
    var4[1] = (var4[1] & ~3) | val1->priority;
    MapVRAMBanksToSubObj(0x100);
}
