#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void SprSprite_Init(void* obj, int flag);
extern "C" void* __clear(void* dst, int count);
extern "C" void SprSprite_Parse(void* obj, void* handle, void* extra);

extern "C" int func_020429d4(void);
void* LoadFileIntoMemory(const char* path, void* dst, unsigned int* outCount);

extern int data_020f0118;

struct Struct_02047a78 {
    char pad0[0x84];
    unsigned char unknown_84_0_ : 1;
    unsigned char unknown_84_1_ : 7;
};

// USA: func_02047a78
extern "C" ARM void func_02047a78(struct Struct_02047a78* obj, const char* path, void* extra) {
    char buf[0x80];
    int flag;
    void* handle;

    if (path == 0) {
        return;
    }
    flag = obj->unknown_84_0_;
    if (flag) {
        if (flag) {
            SprSprite_Init(obj, flag);
        }
        obj->unknown_84_0_ = 0;
    }
    if ((path + strlen(path))[-1] != 'r') {
        return;
    }
    __clear(buf, 0x80);
    sprintf(buf, (const char*)&data_020f0118, path);
    handle = (void*)func_020429d4();
    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(buf, handle, 0) != 0) {
        SprSprite_Parse(obj, handle, extra);
    }
    BackgroundLoader::RemoveLockGlobal();
}
