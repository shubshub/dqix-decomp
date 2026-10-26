#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_020534ac;

struct Struct_02075d64;
extern "C" void func_02075d64(struct Struct_02075d64* p);

extern "C" void func_02076080(void* a, void* b, int c, int d);

// USA: func_ov023_021e0328
extern "C" ARM int func_ov023_021e0328(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6b4, regionalOffset1=0x6f0};
#else
 enum {regionalOffset0=0x738, regionalOffset1=0x774};
#endif
    if (*(int*)((char*)obj + regionalOffset0) == -1) {
        return 5;
    }

    int var0 = (int)BackgroundLoader::GetInstance();
    if (((BackgroundLoader*)(var0))->GetTaskStatus((int)(*(int*)((char*)obj + regionalOffset0)))) {
        int out1, out2;
        ((BackgroundLoader*)((struct Struct_020534ac*)var0))->GetLoadedFileByID((int)(*(int*)((char*)obj + regionalOffset0)), (void**)(&out1), (unsigned int*)(&out2));
        func_02075d64(*(struct Struct_02075d64**)((char*)obj + 0xc8));

#if defined(jpn)
        if (out1 != 0) {
#else
        if (out1 != 0 && out2 != 0) {
#endif

            ((SafeAllocator*)(*(void**)((char*)obj + 0x40)))->Reset();
            func_02076080(*(void**)((char*)obj + 0xc8), *(void**)((char*)obj + 0x40), out1, out2);
            *(unsigned short*)((char*)obj + regionalOffset1) &= ~8;
        }

        ((BackgroundLoader*)(var0))->RemoveTask((int)(*(int*)((char*)obj + regionalOffset0)));
        *(int*)((char*)obj + regionalOffset0) = -1;

        int var3 = *(int*)((char*)obj + 0xc4);
        *(int*)((char*)obj + 0xc4) = *(int*)((char*)obj + 0xc8);
        *(int*)((char*)obj + 0xc8) = var3;

        int var4 = *(int*)((char*)obj + 0x3c);
        *(int*)((char*)obj + 0x3c) = *(int*)((char*)obj + 0x40);
        *(int*)((char*)obj + 0x40) = var4;

        *(unsigned short*)((char*)obj + regionalOffset1) |= 2;
        return 5;
    }

    return 3;
}
