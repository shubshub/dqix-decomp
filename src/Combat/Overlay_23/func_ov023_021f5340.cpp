#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_020534ac;

extern "C" void func_ov023_021f5448(void* obj, int a, int b, int c);
extern "C" int func_ov023_021f5410(void* obj);
extern "C" int func_ov023_021f5340(void* obj);

extern int data_ov023_021fe334;

// USA: func_ov023_021f5340
extern "C" ARM int func_ov023_021f5340(void* objRaw) {
    char* obj = (char*)objRaw;
    int var1 = (int)BackgroundLoader::GetInstance();
    short state = *(short*)(obj + 0xc);
    switch (state) {
    case 1:
        *(int*)(obj + 0x10) = ((BackgroundLoader*)(var1))->QueueLoadFile((const char*)(data_ov023_021fe334), (SafeAllocator*)(0));
        *(short*)(obj + 0xc) = 2;
        return func_ov023_021f5340(obj);
    case 2:
        if (((BackgroundLoader*)(var1))->GetTaskStatus((int)(*(int*)(obj + 0x10))) == 0) return 0;
        *(short*)(obj + 0xc) = 3;
        return func_ov023_021f5340(obj);
    case 3: {
        int out1 = 0, out2 = 0;
        ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(*(int*)(obj + 0x10)), (void**)(&out1), (unsigned int*)(&out2));
        func_ov023_021f5448(obj, *(int*)(obj + 0x14), out1, out2);
        func_ov023_021f5410(obj);
        return 1;
    }
    default:
        return 1;
    }
}
