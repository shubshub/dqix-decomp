#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

struct Struct_020709ec;
extern "C" void func_02070a30(Struct_020709ec*, SafeAllocator*, void*, unsigned int);

extern char data_020f0b64;

// USA: func_020709ec
extern "C" ARM void func_020709ec(void* destination, void* allocator) {
    unsigned int size;
    BackgroundLoader::AddLockGlobal();
    void* buf = LoadFileIntoMemory(&data_020f0b64, g_fileLoadBuffer, &size);
    func_02070a30(static_cast<Struct_020709ec*>(destination),
                           static_cast<SafeAllocator*>(allocator), buf, size);
    BackgroundLoader::RemoveLockGlobal();
}
