#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(unsigned char* context, unsigned int key);
struct Struct_020a13c4;
extern "C" void func_020a13c4(Struct_020a13c4* table);
struct StreamHeader;
extern "C" void func_020a147c(void*, void*, StreamHeader*, int, int, unsigned short, unsigned char);
extern "C" int func_020ac460(void* destination);
extern "C" void __clear(void* destination, int length);
struct Struct_020a15bc;
struct Struct_020a15bc_2;
extern "C" Struct_020a15bc_2* func_020a15bc(Struct_020a15bc* table, int id);

extern void* data_ov004_021707c8;
#if defined(jpn)
extern char data_ov004_02170c94[];
#else
extern char data_ov004_0217039a[];
extern char data_ov004_021703af[];
#endif

// USA: func_ov004_021567f8
// KEEP-NAME
extern "C" ARM int func_ov004_021567f8(void* context) {
    char* base = (char*)func_ov011_021845f8((unsigned char*)context, 4);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* allocator = (SafeAllocator*)(base + 4);
#if defined(jpn)
    *(void**)((char*)&data_ov004_021707c8 + 8) = allocator->Allocate(0x14);
    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    void* file = LoadFileIntoMemory(data_ov004_02170c94, g_fileLoadBuffer, &length);
#else
    *(void**)((char*)&data_ov004_021707c8 + 12) = allocator->Allocate(0x14);
    int task = loader->QueueLoadFileInGP2(data_ov004_0217039a, data_ov004_021703af, 0);
    if (task < 0) return 0;
    while (!loader->GetTaskStatus(task)) {
        loader->RemoveAllLocks();
    }
    if (loader->GetDetailedTaskStatus(task) != 2) {
        loader->RemoveTask(task);
        return 0;
    }
    void* file;
    unsigned int length;
    loader->GetLoadedFileByID(task, &file, &length);
#endif
    if (file != 0) {
#if defined(jpn)
        func_020a13c4(*(Struct_020a13c4**)((char*)&data_ov004_021707c8 + 8));
        func_020a147c(*(void**)((char*)&data_ov004_021707c8 + 8), allocator, (StreamHeader*)file, length, 0, 0, 0xf);
#else
        func_020a13c4(*(Struct_020a13c4**)((char*)&data_ov004_021707c8 + 12));
        func_020a147c(*(void**)((char*)&data_ov004_021707c8 + 12), allocator, (StreamHeader*)file, length, 0, 0, 0xf);
#endif
    }
#if defined(jpn)
    BackgroundLoader::RemoveLockGlobal();
#else
    loader->RemoveTask(task);
#endif
    if (file == 0) return 0;

#if defined(jpn)
    short* var7 = (short*)allocator->Allocate(0x3c0);
    *(short**)((char*)&data_ov004_021707c8 + 4) = var7;
    memset(var7, 0, 0x3c0);
#else
    short* var8 = (short*)allocator->Allocate(0x3c0);
    *(short**)((char*)&data_ov004_021707c8 + 8) = var8;
    memset(var8, 0, 0x3c0);
#endif
    unsigned int var9[15];
    __clear(var9, sizeof(var9));
    func_020ac460(var9);

    int index, id, count;
    for (count = 0, index = 0; index < 0x1e0; index++) {
        id = index + 1;
#if defined(jpn)
        Struct_020a15bc* table = *(Struct_020a15bc**)((char*)&data_ov004_021707c8 + 8);
#else
        Struct_020a15bc* table = *(Struct_020a15bc**)((char*)&data_ov004_021707c8 + 12);
#endif
        if (func_020a15bc(table, (short)id)) {
            int word = id / 32;
            int bit = id % 32;
            if (var9[word] & (1u << bit)) {
#if defined(jpn)
                (*(short**)((char*)&data_ov004_021707c8 + 4))[count] = id;
#else
                (*(short**)((char*)&data_ov004_021707c8 + 8))[count] = id;
#endif
                count++;
            }
        }
    }
#if defined(jpn)
    data_ov004_021707c8 = allocator->Allocate(0x3c0);
    memset(data_ov004_021707c8, 0, 0x3c0);
#else
    short* var16 = (short*)allocator->Allocate(0x3c0);
    *(short**)((char*)&data_ov004_021707c8 + 4) = var16;
    memset(var16, 0, 0x3c0);
    data_ov004_021707c8 = allocator->Allocate(0x1000);
    memset(data_ov004_021707c8, 0, 0x1000);
#endif
    return 0;
}
