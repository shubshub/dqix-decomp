#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void* func_ov011_021849c8(int a);
extern "C" int func_ov023_021f6bb8(void* thing);
extern "C" void func_ov023_021f6bb0(void* thing, int v);
extern char data_ov023_021fec3c;

// USA: func_ov023_021fa8fc
#if defined(jpn)
extern char data_ov023_021fdef4;

extern "C" ARM int func_ov023_021fa8fc(void* obj, int a) {
    void* thing = func_ov011_021849c8(a);
    if (func_ov023_021f6bb8(thing) >= 0) {
        return *(int*)((char*)obj + 0x1c);
    }
    int var1 = (int)BackgroundLoader::GetInstance();
    char buf[0x50];
    sprintf(buf, &data_ov023_021fdef4, *(int*)((char*)obj + 0x10));
    int result = ((BackgroundLoader*)(var1))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
    func_ov023_021f6bb0(thing, result);
    return 1;
}
#else
extern "C" ARM int func_ov023_021fa8fc(void* obj, int a) {
    void* thing = func_ov011_021849c8(a);
    int state = func_ov023_021f6bb8(thing);
    if (state < 0) {
        int var6 = (int)BackgroundLoader::GetInstance();
        char buf[0x50];
        if (*(int*)((char*)obj + 0x20) != 0) {
            sprintf(buf, &data_ov023_021fec3c, *(int*)((char*)obj + 0x20));
        } else {
            sprintf(buf, &data_ov023_021fec3c, *(int*)((char*)obj + 0x10));
        }
        int result;
        if (*(int*)((char*)obj + 0x20) != 0) {
            result = ((BackgroundLoader*)(var6))->QueueLoadFileInGP2((const char*)((int)buf), (const char*)(*(int*)((char*)obj + 0x10)), (SafeAllocator*)(0));
        } else {
            result = ((BackgroundLoader*)(var6))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
        }
        func_ov023_021f6bb0(thing, result);
        return 1;
    }
    return *(int*)((char*)obj + 0x1c);
}
#endif
