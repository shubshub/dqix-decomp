#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_020534ac;

extern "C" int func_020e0028(void* p, int b, int out1, int out2, void* p2, int arg5);

struct Struct_ov000_0216fd80 {
    int id;
    char pad4[0x84 - 0x4];
    int unknown_84_;
    char unknown_88_[0xa1 - 0x88];
    unsigned char unknown_a1_;
};

// USA: func_ov000_0216fd80
extern "C" ARM void func_ov000_0216fd80(struct Struct_ov000_0216fd80* obj, int b) {
    int handle = (int)BackgroundLoader::GetInstance();
    int out1, out2;
    ((BackgroundLoader*)((struct Struct_020534ac*)handle))->GetLoadedFileByID((int)(obj->id), (void**)(&out1), (unsigned int*)(&out2));
    func_020e0028((char*)obj + 0x88, b, out1, out2, &obj->pad4, (unsigned short)obj->unknown_84_);
    ((BackgroundLoader*)(handle))->RemoveTask((int)(obj->id));
    obj->id = -1;
    obj->unknown_a1_ = 1;
}
