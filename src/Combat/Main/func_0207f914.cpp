#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0207f914_32 = 0x1c };
#else
enum { Enum_0207f914_32 = 0x20 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);

extern char data_020f0fd0[];
extern char data_020f0fdc[];
extern char data_020f0fe7[];

struct Struct_0207f914 {
    char pad0[0x14];
    int unknown_14_;
    char pad1[Enum_0207f914_32 - 0x18];
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
};

#if defined(jpn)
extern "C" ARM void func_02080654(struct Struct_0207f914* obj, int p1, int p2) {
    if (p1 != 0 && p2 != 0) {
        obj->unknown_14_ = p1;
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        obj->unknown_20_ = loader->QueueLoadFile((const char*)p2, (SafeAllocator*)0);
    }
}
#else
// USA: func_0207f914
extern "C" ARM void func_0207f914(struct Struct_0207f914* obj, int p1, int p2, int p3) {
    if (p1 != 0 && p2 != 0 && p3 != 0) {
        obj->unknown_14_ = p1;
        int field4 = (int)BackgroundLoader::GetInstance();
        char bufA[0x20];
        __clear(bufA, 0x20);
        char var2[0x20];
        __clear(var2, 0x20);
        char var3[0x20];
        __clear(var3, 0x20);
        sprintf(var3, data_020f0fd0, p3);
        sprintf(var2, data_020f0fdc, p3);
        sprintf(bufA, data_020f0fe7, p3);
        obj->unknown_20_ = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(p2), (const char*)((int)var3), (SafeAllocator*)(0));
        obj->unknown_24_ = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(p2), (const char*)((int)var2), (SafeAllocator*)(0));
        obj->unknown_28_ = ((BackgroundLoader*)(field4))->QueueLoadFileInGP2((const char*)(p2), (const char*)((int)bufA), (SafeAllocator*)(0));
    }
}

#endif
