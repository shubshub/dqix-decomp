#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"


struct Struct_ov031_0223b61c { unsigned char pad[0x84]; void* unknown_84_; };
struct Struct_ov031_02290d24_3 { Struct_ov031_0223b61c* p; };
extern struct Struct_ov031_02290d24_3 data_ov031_02290d24;

extern "C" void func_ov031_0223bfa0(void*);
extern "C" void HaltSystem(void);
extern "C" int func_ov031_0223b744(char*, char*, int);
extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void func_020ca7e8(void*, void*);
extern "C" unsigned int func_ov031_0223cf70(void** a);
extern char data_ov031_0224c56c[];

// USA: func_ov031_0223b61c
extern "C" ARM void* func_ov031_0223b61c(char* path, unsigned int* outSize, int align) {
    func_ov031_0223bfa0(data_ov031_02290d24.p->unknown_84_);

    NitroVM vm;
    NitroVM_Initialize(&vm);
    if (!NitroVM_PrepareReadFileByPath(&vm, path))
        HaltSystem();

    unsigned int size = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
    if (outSize) *outSize = size;

    int var2 = func_ov031_0223b744(path, data_ov031_0224c56c, 2) ? -4 : align;

    void* ptr = func_ov031_0223cf4c(size, var2);
    NitroVM_ReadSync(&vm, ptr, size);
    NitroVM_FinishRead(&vm);

    if (var2 > 0) {
        return ptr;
    }

    unsigned int var4 = *(unsigned int*)ptr >> 8;
    if (outSize) *outSize = var4;
    void* var5 = func_ov031_0223cf4c(var4, align);
    func_020ca7e8(ptr, var5);
    func_ov031_0223cf70(&ptr);
    return var5;
}
