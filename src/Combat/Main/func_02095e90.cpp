#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern int data_020f1474;

struct Struct_02095e90 {
    char pad[0xa8];
    void* unknown_a8_;
    char pad2[0x4c4 - 0xa8 - 4];
    int unknown_4c4_;
};

// USA: func_02095e90
extern "C" ARM int func_02095e90(struct Struct_02095e90* obj, SafeAllocator* allocator) {
    void* ptr = allocator->Allocate(0x198);
    obj->unknown_a8_ = ptr;
    if (ptr == NULL) {
        return 0;
    }
    memset(ptr, 0, 0x198);
    obj->unknown_4c4_ = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)&data_020f1474), (SafeAllocator*)(0));
    return 1;
}
