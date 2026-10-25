#include <globaldefs.h>

struct Container0205a3d0;
struct Container0205a330;
struct AdjustedPosObj020e2604;

extern "C" void func_020e269c(void* obj);
void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);
void ComputeAdjustedElementPosition(struct AdjustedPosObj020e2604* self);

struct Elem020e263c {
    char pad[0x15];
    unsigned char flags15;
};
struct Elem020e263c* SpriteEntryList_Find(struct Container0205a3d0* c, int key);

struct Ctx020e263c {
    char pad[0x1c];
    unsigned short key;
    unsigned char flag;
    char pad2;
    struct Container0205a3d0* container;
};

// USA: func_020e263c
ARM void UpdateEntryStateAndPosition(struct Ctx020e263c* obj, int value) {
    if (obj->container == NULL) {
        return;
    }
    func_020e269c(obj);
    SpriteEntryList_PlayAnimation(obj->container, obj->key);
    unsigned char flag = obj->flag;
    struct Elem020e263c* entry = SpriteEntryList_Find(obj->container, obj->key);
    if (entry != NULL) {
        entry->flags15 |= flag;
    }
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)obj->container, value);
    ComputeAdjustedElementPosition((struct AdjustedPosObj020e2604*)obj);
}
