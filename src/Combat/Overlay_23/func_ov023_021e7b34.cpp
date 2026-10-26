#include <globaldefs.h>
#include "NitroSDK/Cache.h"

struct Struct_ov023_021e7b34_2 {
    char pad[0x5dc];
    int unknown_5dc_;
};

struct BackgroundGraphics;
extern "C" void* Background_GetScreen(BackgroundGraphics*, unsigned int);

struct Struct_0204ae44;
extern "C" void func_0204ae44(Struct_0204ae44*, int);

extern "C" int LoadToSubBG1ScreenData(int, int, unsigned int);

struct Struct_ov023_021e7b34 {
    char pad0[8];
    int size;
    void* buffer;
};

// USA: func_ov023_021e7b34
extern "C" ARM int func_ov023_021e7b34(Struct_ov023_021e7b34_2* obj, int idx) {
    if (obj->unknown_5dc_ == 0) return 1;
    int var0 = (idx >= 0 && idx <= 3) ? 1 : 0;
    if (!var0) return 1;
    BackgroundGraphics* list = (BackgroundGraphics*)((char*)obj + 0x154);
    void* entryPtr = Background_GetScreen(list, 0);
    if (entryPtr == NULL) return 1;
    func_0204ae44((Struct_0204ae44*)entryPtr, (unsigned short)(idx + 0xc));
    Struct_ov023_021e7b34* entry = (Struct_ov023_021e7b34*)entryPtr;
    void* buffer = entry->buffer;
    int size = entry->size;
    CleanInvalidateCacheRange(buffer, size);
    LoadToSubBG1ScreenData((int)buffer, 0, size);
    return 0;
}
