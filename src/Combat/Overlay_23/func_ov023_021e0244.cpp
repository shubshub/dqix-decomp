#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
struct StructDE234_020de234;
extern "C" unsigned short ItemRecord_GetFileNumber(struct StructDE234_020de234* p, int preferMid);
struct Struct_02075d64;
extern "C" void func_02075d64(struct Struct_02075d64* p);

extern char data_ov023_021fdc23[];
extern char data_ov023_021fdc36[];

// USA: func_ov023_021e0244
extern "C" ARM int func_ov023_021e0244(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6f0, regionalOffset1=0x6b4};
#else
 enum {regionalOffset0=0x774, regionalOffset1=0x738};
#endif
    int var0 = (int)BackgroundLoader::GetInstance();
    int ok = 0;

    if (*(void**)((char*)obj + 0x4c) != 0) {
        char buf[0x40];
        __clear(buf, 0x40);

        if ((*(unsigned short*)((char*)obj + regionalOffset0) & 0x1000) != 0) {
            struct StructDE234_020de234* sp2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned short val = ItemRecord_GetFileNumber(sp2, 0);
            struct StructDE234_020de234* s2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned int var6 = *(unsigned int*)((char*)s2 + 0x10);
            int var7 = (var6 << 4) >> 0x18;
            sprintf(buf, data_ov023_021fdc23, var7, val);
        } else {
            struct StructDE234_020de234* sp2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned short val = ItemRecord_GetFileNumber(sp2, 0);
            struct StructDE234_020de234* s2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned int var11 = *(unsigned int*)((char*)s2 + 0x10);
            int var12 = (var11 << 4) >> 0x18;
            sprintf(buf, data_ov023_021fdc36, var12, val);
        }

        int r = ((BackgroundLoader*)(var0))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
        *(int*)((char*)obj + regionalOffset1) = r;
        ok = 1;
    }

    if (ok != 0) return 4;

    *(unsigned short*)((char*)obj + regionalOffset0) |= 8;
    func_02075d64(*(struct Struct_02075d64**)((char*)obj + 0xc8));
    return 6;
}
