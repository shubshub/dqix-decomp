#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_020534ac;

extern "C" {
    void func_020df850(void* a, void* b, int out1, int out2, int arg4);
}

struct Struct_ov023_021e0b9c {
    char pad28[0x28];
    int field28;
    char unknown_2c_[0x4c - 0x2c];
    void* field4c;
    char unknown_50_[0x7c - 0x50];
    int field7c;
#if defined(jpn)
    char unknown_80_[0x6c8 - 0x80];
#else
    char unknown1_80_[0x74c - 0x80];
#endif

    int handle;
};

// USA: func_ov023_021e0b9c
extern "C" ARM int func_ov023_021e0b9c(struct Struct_ov023_021e0b9c* obj) {
    if (obj->handle == -1) {
        return -1;
    }

    int var0 = (int)BackgroundLoader::GetInstance();
    if (((BackgroundLoader*)(var0))->GetTaskStatus((int)(obj->handle))) {
        int out1, out2;
        ((BackgroundLoader*)((struct Struct_020534ac*)var0))->GetLoadedFileByID((int)(obj->handle), (void**)(&out1), (unsigned int*)(&out2));
#if defined(jpn)
        {
#else
        if (out1 != 0 && out2 != 0) {
#endif

            int v = *(short*)((char*)obj->field4c + 0x18);
            func_020df850(&obj->field7c, &obj->field28, out1, out2, v);
        }

        ((BackgroundLoader*)(var0))->RemoveTask((int)(obj->handle));
        obj->handle = -1;
        return 0xf;
    }

    return 0xd;
}
