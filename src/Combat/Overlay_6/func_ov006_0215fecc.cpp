#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Struct_02000c9c_92 {
    char unknown0[0x70];
};

struct Struct_ov006_02157a60 {
#if defined(jpn)
    char unknown0[4];
#else
    char unknown0[0xc];
#endif
    SafeAllocator* allocators;
#if defined(jpn)
    char unknown8[0x3b8 - 8];
#else
    char unknown10[0x3b8 - 0x10];
#endif
    Struct_02000c9c_92 unknown_3b8_;
    int unknown_428_;
};

extern "C" void func_02076080(Struct_02000c9c_92* sprite, SafeAllocator* allocator, void* file, unsigned int size);

// USA: func_ov006_0215fecc
extern "C" ARM int func_ov006_0215fecc(Struct_ov006_02157a60* menu) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(menu->unknown_428_))
        return 0;
    SafeAllocator* allocator = &menu->allocators[9];
    allocator->Reset();
    void* file = NULL;
    unsigned int fileSize = 0;
    loader->GetLoadedFileByID(menu->unknown_428_, &file, &fileSize);
    func_02076080(&menu->unknown_3b8_, allocator, file, fileSize);
    loader->RemoveTask(menu->unknown_428_);
    menu->unknown_428_ = -1;
    return 1;
}
