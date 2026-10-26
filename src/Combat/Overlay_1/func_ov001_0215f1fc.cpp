#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
struct Struct_ov001_0215e1cc;
extern "C" unsigned int func_ov001_0215a750(const char* path, void** outPtr);
extern "C" void func_ov001_021538c8(void);
extern "C" void func_ov001_021538d4(int p0, void* unused1, SafeAllocator* alloc);

extern const char data_ov001_02165745[];
extern SafeAllocator* data_ov001_021658b8[8];

// USA: func_ov001_0215f1fc
extern "C" ARM int func_ov001_0215f1fc(void* param0) {
    char buf[0x20];
    int out1;
    int out2;
    SafeAllocator* allocator;
    int flag;

    void* name = func_ov017_021d612c(param0);
    if (GameState::GetInstance() == NULL) {
        return 0;
    }
    sprintf(buf, data_ov001_02165745, name);
    allocator = data_ov001_021658b8[0];
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
    void* newObj = allocator->Allocate(out2);
    if (newObj == NULL) {
        if (flag != 0) {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    memcpy(newObj, (void*)out1, out2);
    if (flag != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    func_ov001_021538c8();
    func_ov001_021538d4((int)newObj, NULL, allocator);
    return 1;
}
