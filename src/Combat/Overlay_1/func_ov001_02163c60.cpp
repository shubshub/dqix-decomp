#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned int func_02010768(void*);
extern "C" unsigned int Zone3D_Unload(void*, int);
struct Foo0207df50;
extern "C" unsigned int VramState_Rewind(Foo0207df50*);
extern "C" unsigned int Zone3D_GetInstance();

// USA: func_ov001_02163c60
extern "C" ARM int func_ov001_02163c60(void) {
#if defined(jpn)
    enum { Enum_ov001_02163c60_76 = 0x6c, Enum_ov001_02163c60_80 = 0x70 };
#else
    enum { Enum_ov001_02163c60_76 = 0x4c, Enum_ov001_02163c60_80 = 0x50 };
#endif
    unsigned int allocator;
    unsigned int state = (unsigned int)GameState::GetInstance();
    unsigned int grotto = Zone3D_GetInstance();
    unsigned int* slot = (unsigned int*)func_02010768((void*)state);
    unsigned int entry = *slot;
    if (entry != 0) {
        Zone3D_Unload((void*)entry, 1);
        allocator = *(unsigned int*)((char*)entry + Enum_ov001_02163c60_76);
        if (allocator != 0) {
            ((SafeAllocator*)allocator)->Destroy();
        }
    }
    *slot = 0;
    allocator = *(unsigned int*)((char*)grotto + Enum_ov001_02163c60_76);
    unsigned int fields = *(unsigned int*)((char*)grotto + Enum_ov001_02163c60_80);
    ((SafeAllocator*)allocator)->Reset();
    VramState_Rewind((Foo0207df50*)fields);
    return 1;
}
