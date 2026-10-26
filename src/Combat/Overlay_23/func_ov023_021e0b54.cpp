#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void func_020df83c(void* p);

#if defined(jpn)
extern int data_020f2cb0;
#else
extern int data_020f2a1c;
#endif
extern int data_020f2a28;

// USA: func_ov023_021e0b54
extern "C" ARM int func_ov023_021e0b54(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6c8};
#else
 enum {regionalOffset0=0x74c};
#endif
    int var0 = (int)BackgroundLoader::GetInstance();
    func_020df83c((char*)obj + 0x7c);
#if defined(jpn)
    *(int*)((char*)obj + regionalOffset0) = ((BackgroundLoader*)(var0))->QueueLoadFileInGP2((const char*)(data_020f2cb0), (const char*)(data_020f2a28), (SafeAllocator*)(0));
#else
    *(int*)((char*)obj + regionalOffset0) = ((BackgroundLoader*)(var0))->QueueLoadFileInGP2((const char*)(data_020f2a1c), (const char*)(data_020f2a28), (SafeAllocator*)(0));
#endif

    return 0xe;
}
