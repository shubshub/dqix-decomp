#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov011_021849c8(int x);
extern "C" int func_ov023_021f6bb8(int handle);
extern "C" void func_ov023_021f6bb0(int handle, int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern char data_ov023_021fe4e0;

struct Struct_ov023_021f7010 {
    char pad0[0x10];
    int f10;
    char unknown_14_[0x1c - 0x14];
    int f1c;
};

// USA: func_ov023_021f7010
extern "C" ARM int func_ov023_021f7010(Struct_ov023_021f7010* obj, int x) {
    char buf[0x50];
    int handle = func_ov011_021849c8(x);
    int status = func_ov023_021f6bb8(handle);
    if (status >= 0) {
        return obj->f1c;
    }
    int h2 = (int)BackgroundLoader::GetInstance();
    sprintf(buf, &data_ov023_021fe4e0, obj->f10);
    int r = ((BackgroundLoader*)(h2))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
    func_ov023_021f6bb0(handle, r);
    return 1;
}
