#include <globaldefs.h>

#if defined(jpn)
enum { kFlagsOffset = 0x3c, kAnimationOffset = 0x44 };
#else
enum { kFlagsOffset = 0x4c, kAnimationOffset = 0x54 };
#endif

#include "GameState/GameState.h"

struct Container0205a3d0;
struct Container0205a330;

struct Entry0205a3d0 {
    char pad0[4];
    unsigned short f4;
    unsigned short unknown_6_;
    char pad8[0xd];
    unsigned char f15;
};

struct Struct_ov019_0218c178 {
    char pad0[kFlagsOffset];
    int flags;
    char unknown_50_[0x40];
    struct Container0205a3d0* container;
};

extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0*, int);
extern "C" struct Entry0205a3d0* SpriteEntryList_Find(struct Container0205a3d0*, int);
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330*, int);
extern "C" void SpriteEntryList_SetFirstObject(struct Container0205a3d0*, int, int);
extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov019_0218c178
extern "C" ARM void func_ov019_0218c178(struct Struct_ov019_0218c178* obj) {
    GameState* battle = GameState::GetInstance();
    if (obj->flags & 1) {
        struct Container0205a3d0* c = obj->container;
        if (c != NULL) {
            struct Entry0205a3d0* e;
            SpriteEntryList_PlayAnimation(c, 1);
            e = SpriteEntryList_Find(c, 1);
            if (e != NULL) {
                e->f15 = e->f15 | 8;
            }
            SpriteEntryList_AdvanceAnimations(
                (struct Container0205a330*)c, battle->GetTickCount());
            e = SpriteEntryList_Find(c, 1);
            if (e != NULL) {
                e->f4 = 0xd7;
                e->unknown_6_ = 0x96;
            }
            SpriteEntryList_SetFirstObject(c, 1, 0x24);
        }
        SpriteContext_DrawEntries((char*)obj + kAnimationOffset);
    } else {
        struct Container0205a3d0* c = obj->container;
        if (c != NULL) {
            struct Entry0205a3d0* e = SpriteEntryList_Find(c, 1);
            if (e != NULL) {
                e->f15 = e->f15 & ~8;
            }
        }
    }
}
