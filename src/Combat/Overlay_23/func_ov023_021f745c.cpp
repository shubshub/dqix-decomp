#include <globaldefs.h>
#if defined(jpn)
#define REGIONAL_PARAMETER
#else
#define REGIONAL_PARAMETER int p5,
#endif
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"

struct Struct_ov023_021f6ed8;
extern "C" ARM void func_ov023_021f6ed8(struct Struct_ov023_021f6ed8* obj);

extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void Background_SetMapSize(unsigned char* obj, int value);
extern "C" void Background_SetPriority(void*, int);

struct BackgroundGraphics;
extern "C" int Background_SetScroll(struct BackgroundGraphics*, int, int);

extern "C" void* func_ov011_021845f8(void* ctx, int v);

extern "C" void Background_AllocateMap(struct BackgroundGraphics* obj, SafeAllocator* alloc);

struct Struct_ov023_021f745c;
extern "C" ARM void func_ov023_021f7a08(struct Struct_ov023_021f745c* obj, void* keyObj);

// USA: func_ov023_021f745c
extern "C" ARM int func_ov023_021f745c(char* obj, void* arg1, int arg2, int arg3, REGIONAL_PARAMETER int p6, int p7, int p8, int p9) {
#if defined(jpn)
 enum {regionalOffset0=0x24, regionalOffset1=0x44, regionalOffset2=0x4c, regionalOffset3=0x4e};
#else
 enum {regionalOffset0=0x28, regionalOffset1=0x48, regionalOffset2=0x50, regionalOffset3=0x52};
#endif
    func_ov023_021f6ed8((struct Struct_ov023_021f6ed8*)obj);
    *(short*)(obj + 0x4) = 2;
    *(void**)(obj + 0x20) = arg1;
    *(short*)(obj + 0x6) = (short)arg2;
    *(short*)(obj + 0x8) = (short)arg3;
    *(short*)(obj + 0xa) = 0;
#if defined(jpn)

#else
    *(int*)(obj + 0x24) = p5;
#endif

    *(int*)(obj + 0x10) = p6;
    *(int*)(obj + regionalOffset1) = 0;
    Background_Init((struct BackgroundGraphics*)(obj + regionalOffset0));
    Background_SetMapSize((unsigned char*)(obj + regionalOffset0), 0);

    struct BackgroundGraphics* list = (struct BackgroundGraphics*)(obj + regionalOffset0);
    list->subScreen_ = (unsigned char)p7;
    list->bgNumber_ = (unsigned char)p8;

    Background_SetPriority(obj + regionalOffset0, p9);
    Background_SetScroll((struct BackgroundGraphics*)(obj + regionalOffset0), 0, 0);

    void* result = func_ov011_021845f8(arg1, *(unsigned short*)(obj + 0x8));
    if (result == 0) return 0;

    Background_AllocateMap((struct BackgroundGraphics*)(obj + regionalOffset0), (SafeAllocator*)((char*)result + 4));
    func_ov023_021f7a08((struct Struct_ov023_021f745c*)obj, arg1);
    *(short*)(obj + regionalOffset2) = 0;
    *(short*)(obj + regionalOffset3) = 0;
    return 1;
}
