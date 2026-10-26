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
    char unknown_0_[0x84];
    unsigned char unknown_84_0_ : 1;
    unsigned char unknown_84_1_ : 7;
};

// USA: func_02047a78
extern "C" ARM void func_02047a78(struct Struct_02047a78* arg0, const char* arg1, void* arg2) {
    char var0[0x80];
    int var1;
    void* var2;

    if (arg1 == 0) {
        return;
    }
    flag = obj->flag0;
    if (flag) {
        if (flag) {
            SprSprite_Init(obj, flag);
        }
        arg0->unknown_84_0_ = 0;
    }
    if ((arg1 + strlen(arg1))[-1] != 'r') {
        return;
    }
    __clear(var0, 0x80);
    sprintf(var0, (const char*)&data_020f0118, arg1);
    var2 = (void*)func_020429d4();
    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(buf, handle, 0) != 0) {
        SprSprite_Parse(obj, handle, extra);
    }
    BackgroundLoader::RemoveLockGlobal();
}
