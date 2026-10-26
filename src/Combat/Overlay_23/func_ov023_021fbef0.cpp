#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6bb8(void*);
extern "C" void func_ov023_021f6bb0(void*, int);

extern int g_itemDataArchive;
extern int g_itemDataFile;

// USA: func_ov023_021fbef0
#if defined(jpn)
extern "C" ARM int func_ov023_021fbef0(void* a, void* b) {
    void* sub = func_ov011_021849c8(b);
    if (func_ov023_021f6bb8(sub) >= 0) {
        return *(int*)((char*)a + 0x1c);
    }
    int result = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadGP1((const char*)(g_itemDataArchive), (SafeAllocator*)(0));
    func_ov023_021f6bb0(sub, result);
    return 1;
}
#else
extern "C" ARM int func_ov023_021fbef0(void* a, void* b) {
    void* sub = func_ov011_021849c8(b);
    if (func_ov023_021f6bb8(sub) >= 0) {
        return *(int*)((char*)a + 0x1c);
    }
    int result = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFileInGP2((const char*)(g_itemDataArchive), (const char*)(g_itemDataFile), (SafeAllocator*)(0));
    func_ov023_021f6bb0(sub, result);
    return 1;
}
#endif
