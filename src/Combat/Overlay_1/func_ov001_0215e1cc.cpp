#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
struct Struct_ov001_0215e1cc;
extern "C" unsigned int func_ov001_0215a750(const char* path, void** outPtr);
extern "C" void func_ov001_021537b0(void* p0, int p1, int p2, int p3);

extern const char data_ov001_02165745[];

struct Struct_ov001_021658b8_7 {
    int field0;
    char pad[0x8c - 0x4];
    unsigned char unknown_8c_;
};
extern Struct_ov001_021658b8_7 data_ov001_021658b8;
extern int data_ov001_021658d8;

// USA: func_ov001_0215e1cc
extern "C" ARM int func_ov001_0215e1cc(void* param0) {
    char buf[0x28];
    int out1;
    int out2;
    int flag;

    sprintf(buf, data_ov001_02165745, func_ov017_021d612c(param0));
    flag = 0;
    ((BackgroundLoader*)((Struct_ov001_0215e1cc*)(int)BackgroundLoader::GetInstance()))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 == 0) {
        BackgroundLoader::AddLockGlobal();
        flag = 1;
        if (func_ov001_0215a750(buf, (void**)&out1) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    func_ov001_021537b0(&data_ov001_021658d8, data_ov001_021658b8.field0, out1, out2);
    if (flag != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    data_ov001_021658b8.unknown_8c_ = 0;
    return 1;
}
