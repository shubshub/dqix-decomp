#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct_020534ac;

extern "C" void func_ov023_021e20f0(void* p, void* obj, int a, int b);

extern "C" void func_ov023_021dbd10(void* obj, void* p);

struct Struct_ov023_021e04e8 {
    char pad[8];
    unsigned int nibble : 4;
};

// USA: func_ov023_021e04e8
extern "C" ARM int func_ov023_021e04e8(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6b8, regionalOffset1=0x716};
#else
 enum {regionalOffset0=0x73c, regionalOffset1=0x79a};
#endif
    if (*(int*)((char*)obj + regionalOffset0) == -1) {
        void* var0 = *(void**)((char*)obj + 0x4c);
        if (var0 != 0) {
            func_ov023_021dbd10((char*)obj + 0xcc, var0);
        }
        return 7;
    }

    int var1 = (int)BackgroundLoader::GetInstance();
    if (((BackgroundLoader*)(var1))->GetTaskStatus((int)(*(int*)((char*)obj + regionalOffset0)))) {
        int out1, out2;
        ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(*(int*)((char*)obj + regionalOffset0)), (void**)(&out1), (unsigned int*)(&out2));

#if defined(jpn)
        {
#else
        if (out1 != 0 && out2 != 0) {
#endif

            ((SafeAllocator*)obj)->Reset();
            func_ov023_021e20f0((char*)obj + 0xcc, obj, out1, out2);
        }

        ((BackgroundLoader*)(var1))->RemoveTask((int)(*(int*)((char*)obj + regionalOffset0)));
        *(int*)((char*)obj + regionalOffset0) = -1;

        void* var4 = *(void**)((char*)obj + 0x4c);
        if (var4 != 0) {
            func_ov023_021dbd10((char*)obj + 0xcc, var4);
            int cond = ((struct Struct_ov023_021e04e8*)*(void**)((char*)obj + 0x4c))->nibble <= 7;
            *(unsigned char*)((char*)obj + regionalOffset1) = cond != 0;
        }

        return 7;
    }

    return 5;
}
