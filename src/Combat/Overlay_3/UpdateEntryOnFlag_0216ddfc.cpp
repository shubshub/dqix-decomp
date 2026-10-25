#include <globaldefs.h>
#if defined(jpn)
enum { kRegion13ec = 0x127c };
enum { kRegion12a8 = 0x1138 };
enum { kRegion126c = 0x10fc };
enum { kRegiondf = 0xd7 };
#else
enum { kRegion13ec = 0x13ec };
enum { kRegion12a8 = 0x12a8 };
enum { kRegion126c = 0x126c };
enum { kRegiondf = 0xdf };
#endif

#include "GameState/GameState.h"

struct Container0205a3d0;
struct Elem0205a3d0;
void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);
void SpriteEntryList_SetFirstObject(struct Container0205a3d0* c, int key, int val);

struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

struct Struct0200fb08;
int GameState_GetLanguage(struct Struct0200fb08*);

extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_ov003_0216ddfc  (semantic: UpdateEntryOnFlag_0216ddfc)
extern "C" ARM void func_ov003_0216ddfc(char* obj) {
    GameState* battle = GameState::GetInstance();
    if (*(unsigned char*)(obj + kRegion13ec) & 4) {
        struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + kRegion12a8);
        if (cont != 0) {
            SpriteEntryList_PlayAnimation(cont, 1);
            struct Elem0205a3d0* e = SpriteEntryList_Find(cont, 1);
            if (e != 0) {
                *(unsigned char*)((char*)e + 0x15) |= 8;
            }
            SpriteEntryList_AdvanceAnimations((struct Container0205a330*)cont, battle->GetTickCount());
            SpriteEntryList_SetPosition(cont, 1, kRegiondf, 0x96);
            SpriteEntryList_SetFirstObject(cont, 1, 0x10);
#if !defined(jpn)
            if (GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance()) == 3) {
                SpriteEntryList_SetPosition(cont, 1, 0xd7, 0x96);
            }
#endif
        }
        SpriteContext_DrawEntries(obj + kRegion126c);
        return;
    }

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + kRegion12a8);
    if (cont == 0) return;
    struct Elem0205a3d0* e = SpriteEntryList_Find(cont, 1);
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}
