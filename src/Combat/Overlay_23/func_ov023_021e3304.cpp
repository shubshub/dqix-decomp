#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/SpriteEntry.h"

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void SpriteEntryList_SetFirstObject(struct Container0205a3d0*, int, int);
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0*, int);
extern "C" struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0*, int);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330*, int);


extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov023_021e3304
extern "C" ARM void func_ov023_021e3304(void* obj, int b, int c) {
    GameState* battleStruct = GameState::GetInstance();
    SpriteEntryList_SetFirstObject(*(struct Container0205a3d0**)((char*)obj + 0xd0), 0, 0);
    SpriteEntryList_PlayAnimation(*(struct Container0205a3d0**)((char*)obj + 0xd0), 0);
    struct Elem0205a3d0* entry = SpriteEntryList_Find(*(struct Container0205a3d0**)((char*)obj + 0xd0), 0);
    if (entry != NULL) {
        *(unsigned char*)((char*)entry + 0x15) |= SpriteEntryFlag_Shown;
    }
    int scaleCount = (int)battleStruct->GetTickCount();
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)(*(struct Container0205a3d0**)((char*)obj + 0xd0)), scaleCount);
    entry = SpriteEntryList_Find(*(struct Container0205a3d0**)((char*)obj + 0xd0), 0);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x4) = (short)b;
        *(short*)((char*)entry + 0x6) = (short)c;
    }
    SpriteContext_DrawEntries(*(void**)((char*)obj + 0xc8));
}
