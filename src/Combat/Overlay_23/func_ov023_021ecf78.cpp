#include <globaldefs.h>
#include "GameState/GameState.h"


struct Container0205a3d0;
struct Container0205a330;
extern "C" void SpriteEntryList_SetFirstObject(struct Container0205a3d0* c, int key, int val);
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
extern "C" void SpriteContext_DrawEntries(void* p);

struct Elem0205a3d0_021ecf78 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    char pad8[0x15 - 8];
    unsigned char unknown_15_;
};
extern "C" struct Elem0205a3d0_021ecf78* SpriteEntryList_Find(struct Container0205a3d0* c, int key);

struct Struct_ov023_021ecf78_2 {
    char pad0[0x424];
    void* f424;
    char unknown_428_[0x42c - 0x428];
    struct Container0205a3d0* container;
    char unknown_430_[0x438 - 0x430];
    unsigned short unknown_438_;
    char unknown_43a_[0x448 - 0x43a];
    short unknown_448_;
};

// USA: func_ov023_021ecf78
extern "C" ARM void func_ov023_021ecf78(struct Struct_ov023_021ecf78_2* obj) {
    if ((obj->unknown_438_ & 0x80) == 0) {
        return;
    }

    GameState* battleStruct = GameState::GetInstance();
    SpriteEntryList_SetFirstObject(obj->container, 0, 0x40);
    SpriteEntryList_PlayAnimation(obj->container, 0);

    struct Elem0205a3d0_021ecf78* entry = SpriteEntryList_Find(obj->container, 0);
    if (entry != NULL) {
        entry->unknown_15_ |= 8;
    }

    unsigned int scaleCount = battleStruct->GetTickCount();
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)obj->container, scaleCount);

    short pos = obj->unknown_448_;
    struct Elem0205a3d0_021ecf78* entry2 = SpriteEntryList_Find(obj->container, 0);
    if (entry2 != NULL) {
        entry2->field4 = pos;
        entry2->field6 = 0x24;
    }

    SpriteContext_DrawEntries(obj->f424);
}
