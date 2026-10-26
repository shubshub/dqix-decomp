#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(j, u) (j)
#else
#define REGION_VALUE(j, u) (u)
#endif

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void SpriteEntryList_SetFirstObject(struct Container0205a3d0* c, int key, int val);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_ov002_0215b0a8
// KEEP-NAME
extern "C" ARM void func_ov002_0215b0a8(char* obj) {
    if ((*(int*)(obj + REGION_VALUE(0x22ac, 0x247c)) & 8) == 0) {
        return;
    }
    struct Container0205a3d0* c = *(struct Container0205a3d0**)(*(char**)(obj + REGION_VALUE(0x19c0, 0x1a68)) + 0x3c);
    SpriteEntryList_PlayAnimation(c, 0);
    struct Elem0205a3d0* e = SpriteEntryList_Find(c, 0);
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) |= 8;
    }
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)c, *(int*)(obj + REGION_VALUE(0x1a68, 0x1ba0)));
    SpriteEntryList_SetPosition(c, 0, 0xd7, 0x96);
    SpriteEntryList_SetFirstObject(c, 0, 0);
    SpriteContext_DrawEntries(*(void**)(obj + REGION_VALUE(0x19c0, 0x1a68)));
}
