#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Struct_02074bf4;
extern "C" void func_02074bf4(struct Struct_02074bf4*);
extern "C" int DisableSubBGVRAMBanks(void);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void MapVRAMBanksToSubBG(int);

// USA: func_ov023_021e7340
extern "C" ARM void func_ov023_021e7340(void* obj) {
    char* o = (char*)obj;
    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(o + 0x5e4) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(o + 0x5e4)));
        *(int*)(o + 0x5e4) = -1;
    }

    volatile unsigned int* p1 = (volatile unsigned int*)0x4001010;
    p1[0] = 0;
    p1[1] = 0;
    func_02074bf4((struct Struct_02074bf4*)(o + 0x64));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0x1f00) | (*(int*)(o + 0x48) << 8);

    DisableSubBGVRAMBanks();
    MapVRAMBanksToSubBG(*(int*)(o + 0x40));
    MapVRAMBanksToSubObj(*(int*)(o + 0x44));

    SafeAllocator* arr[3] = { (SafeAllocator*)o, (SafeAllocator*)(o + 0x14), (SafeAllocator*)(o + 0x28) };
    for (int i = 0; i < 3; i++) {
        if (arr[i]->GetSignedAllocator() != 0) {
            arr[i]->Destroy();
        }
    }
}
