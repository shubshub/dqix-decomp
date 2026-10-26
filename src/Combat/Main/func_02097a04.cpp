#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_020534ac;

struct StreamHeader;
extern "C" void func_02097ac0(void* param0, void* param1, struct StreamHeader* param2, int param3);

extern "C" {
}

extern int data_020f14ec;

struct Struct_02097a04 {
    char pad0[0x18];
    int f18;
    unsigned char f1c;
    unsigned char unknown_1d_;
};

// USA: func_02097a04
extern "C" ARM int func_02097a04(struct Struct_02097a04* obj) {
    int var0 = (int)BackgroundLoader::GetInstance();
    unsigned char f1c = obj->f1c;
    if (f1c == 0) {
        obj->f18 = ((BackgroundLoader*)(var0))->QueueLoadFile((const char*)((int)&data_020f14ec), (SafeAllocator*)(0));
        obj->f1c = obj->f1c + 1;
        goto ret0;
    }
    if (f1c != 1 || !((BackgroundLoader*)(var0))->GetTaskStatus((int)(obj->f18))) {
        goto ret0;
    }
    {
        int out1, out2;
        ((BackgroundLoader*)((struct Struct_020534ac*)var0))->GetLoadedFileByID((int)(obj->f18), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            func_02097ac0(obj, (void*)obj->unknown_1d_, (struct StreamHeader*)out1, out2);
        }
    }
    ((BackgroundLoader*)(var0))->RemoveTask((int)(obj->f18));
    obj->f18 = -1;
    obj->f1c = 0;
    return 1;
ret0:
    return 0;
}
