#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct FlagWord02046708;
void* GlobalFlags_GetInstance(void);
int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask);

struct List0202fe68;

struct List0202fec8;

struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);

extern "C" void SprSprite_Init(void);
extern "C" void SprSprite_Parse(void* a, int b, void* c);
extern "C" void func_0205308c(void* ctx, int val);

// USA: func_020534ac
ARM void ProcessCombatState020534ac(char* ctx) {
    int base;
    char* blockA;
    char* blockB;
    void* obj;
    void* allocated;
    int out1;
    int out2;

    if (FlagWord_TestBits((struct FlagWord02046708*)GlobalFlags_GetInstance(), 2)) {
        return;
    }
    if (*(unsigned char*)(ctx + (IS_JPN ? 0x179 : 0x185)) == 0) {
        return;
    }

    obj = (void*)(int)BackgroundLoader::GetInstance();

    if (((BackgroundLoader*)((struct List0202fe68*)obj))->GetDetailedTaskStatus((int)(*(int*)(ctx + (IS_JPN ? 0x188 : 0x194)))) == 2) {
        ((BackgroundLoader*)((struct List0202fec8*)obj))->GetLoadedFileByID((int)(*(int*)(ctx + (IS_JPN ? 0x188 : 0x194))), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            base = *(int*)(ctx + (IS_JPN ? 0x148 : 0x154));
            blockA = (char*)(base + 0x168);
            blockB = (char*)(base + 0x154);
            VramState_Rewind((struct Foo0207df50*)(blockA + 0x400));
            VramState_Restore(blockA + 0x400);
            allocated = ((SafeAllocator*)(blockB + 0x400))->Allocate(0x88);
            *(void**)(ctx + (IS_JPN ? 0x184 : 0x190)) = allocated;
            if (allocated != NULL) {
                SprSprite_Init();
                *(unsigned char*)((char*)(*(void**)(ctx + (IS_JPN ? 0x184 : 0x190))) + 0x84) |= 4;
                SprSprite_Parse(*(void**)(ctx + (IS_JPN ? 0x184 : 0x190)), out1, blockB + 0x400);
            }
            VramState_Save(blockA + 0x400);
        }
    }

    ((BackgroundLoader*)(obj))->RemoveTask((int)(*(int*)(ctx + (IS_JPN ? 0x188 : 0x194))));
    *(int*)(ctx + (IS_JPN ? 0x188 : 0x194)) = -1;
    *(unsigned char*)(ctx + (IS_JPN ? 0x179 : 0x185)) = 0;

    if (*(unsigned char*)(ctx + (IS_JPN ? 0x17a : 0x186)) != 0) {
        signed char idx = *(signed char*)(ctx + (IS_JPN ? 0x171 : 0x17d));
        char* p = ctx + (idx + 1);
        func_0205308c(ctx, *(signed char*)(p + 0x100 + (IS_JPN ? 0x6c : 0x78)));
        *(unsigned char*)(ctx + (IS_JPN ? 0x17a : 0x186)) = 0;
    }
}
