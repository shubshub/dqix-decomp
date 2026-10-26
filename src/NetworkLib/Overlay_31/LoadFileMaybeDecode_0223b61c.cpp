#include <globaldefs.h>
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"


struct FileBlock_0223b61c { unsigned char pad[0x84]; void* slotArray; };
struct Outer_0223b61c { FileBlock_0223b61c* p; };
extern struct Outer_0223b61c data_ov031_02290d24;

extern "C" void func_ov031_0223bfa0(void*);
extern "C" void HaltSystem(void);
int EndsWithMatch_0223b744(char*, char*, int);
extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void func_020ca7e8(void*, void*);
extern "C" unsigned int func_ov031_0223cf70(void** a);
extern char data_ov031_0224c56c[];

// USA: func_ov031_0223b61c  (semantic: LoadFileMaybeDecode_0223b61c)
extern "C" ARM void* func_ov031_0223b61c(char* path, unsigned int* outSize, int align) {
    func_ov031_0223bfa0(data_ov031_02290d24.p->slotArray);

    NitroVM vm;
    NitroVM_Initialize(&vm);
    if (!NitroVM_PrepareReadFileByPath(&vm, path))
        HaltSystem();

    unsigned int size = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
    if (outSize) *outSize = size;

    int allocAlign = EndsWithMatch_0223b744(path, data_ov031_0224c56c, 2) ? -4 : align;

    void* ptr = func_ov031_0223cf4c(size, allocAlign);
    NitroVM_ReadSync(&vm, ptr, size);
    NitroVM_FinishRead(&vm);

    if (allocAlign > 0) {
        return ptr;
    }

    unsigned int derived = *(unsigned int*)ptr >> 8;
    if (outSize) *outSize = derived;
    void* newPtr = func_ov031_0223cf4c(derived, align);
    func_020ca7e8(ptr, newPtr);
    func_ov031_0223cf70(&ptr);
    return newPtr;
}
