#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct020dfc40;
extern "C" void KeyTable_Destroy(struct Struct020dfc40*);


#if defined(jpn)
extern int data_020f2cb0;
#else
extern int data_020f2a1c;
#endif
#if defined(jpn)
extern int data_020f2cac;
#else
extern int data_020f2a10;
#endif


// USA: func_ov023_021e0a48
extern "C" ARM int func_ov023_021e0a48(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6c4};
#else
 enum {regionalOffset0=0x748};
#endif
    int var0 = (int)BackgroundLoader::GetInstance();
    KeyTable_Destroy((struct Struct020dfc40*)((char*)obj + 0x8c));
#if defined(jpn)
    *(int*)((char*)obj + regionalOffset0) = ((BackgroundLoader*)(var0))->QueueLoadFileInGP2((const char*)(data_020f2cb0), (const char*)(data_020f2cac), (SafeAllocator*)(0));
#else
    *(int*)((char*)obj + regionalOffset0) = ((BackgroundLoader*)(var0))->QueueLoadFileInGP2((const char*)(data_020f2a1c), (const char*)(data_020f2a10), (SafeAllocator*)(0));
#endif

    return 0xc;
}
