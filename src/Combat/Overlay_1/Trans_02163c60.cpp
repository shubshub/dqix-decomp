#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned int GetFieldPtrAt0x5ca4_02010768(void*);
unsigned int Zone3D_Unload(void*, int);
struct Foo0207df50;
unsigned int VramState_Rewind(Foo0207df50*);
extern "C" unsigned int Zone3D_GetInstance();

// USA: func_ov001_02163c60  (semantic: Trans_02163c60)
extern "C" ARM int func_ov001_02163c60(void) {
#if defined(jpn)
    enum { allocatorOffset = 0x6c, copyFieldsOffset = 0x70 };
#else
    enum { allocatorOffset = 0x4c, copyFieldsOffset = 0x50 };
#endif
    unsigned int allocator;
    unsigned int state = (unsigned int)GameState::GetInstance();
    unsigned int grotto = Zone3D_GetInstance();
    unsigned int* slot = (unsigned int*)GetFieldPtrAt0x5ca4_02010768((void*)state);
    unsigned int entry = *slot;
    if (entry != 0) {
        Zone3D_Unload((void*)entry, 1);
        allocator = *(unsigned int*)((char*)entry + allocatorOffset);
        if (allocator != 0) {
            ((SafeAllocator*)allocator)->Destroy();
        }
    }
    *slot = 0;
    allocator = *(unsigned int*)((char*)grotto + allocatorOffset);
    unsigned int fields = *(unsigned int*)((char*)grotto + copyFieldsOffset);
    ((SafeAllocator*)allocator)->Reset();
    VramState_Rewind((Foo0207df50*)fields);
    return 1;
}
