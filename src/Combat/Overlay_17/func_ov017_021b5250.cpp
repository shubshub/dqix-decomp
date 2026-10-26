#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021b5250_68 = 0x40, Enum_ov017_021b5250_760 = 0x2f4 };
#else
enum { Enum_ov017_021b5250_68 = 0x44, Enum_ov017_021b5250_760 = 0x2f8 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int size);
struct Struct_0209c0c0 {
    unsigned short arr[12];
    unsigned short count;
};
extern "C" ARM unsigned short func_0209c0c0(struct Struct_0209c0c0* src, struct Struct_0209c0c0* dst);
extern "C" void* func_0206efc4(void* obj);
struct Struct_0206efd8;
#if defined(jpn)
extern "C" void func_0206f230(void* entries, SafeAllocator* allocator, Struct_0206efd8* source, int length, short* keys, int keyCount);
#else
extern "C" void func_0206f230(void* entries, SafeAllocator* allocator, Struct_0206efd8* source, int length, short* keys, int keyCount, SafeAllocator* arg6, unsigned char* arg7);
#endif

extern char data_ov017_021d7bc3;

struct Struct_ov017_021b5250_2 {
    char unknown0[0x10];
    SafeAllocator* allocator;
    SafeAllocator* unknown_14_;
    char unknown18[Enum_ov017_021b5250_68 - 0x18];
    Struct_0209c0c0 keys;
    char unknown_5e_[Enum_ov017_021b5250_760 - Enum_ov017_021b5250_68 - sizeof(Struct_0209c0c0)];
    char entries[12];
};

struct Struct_ov017_021b5250 {
    char unknown0[8];
    Struct_ov017_021b5250_2* resources;
    int taskId;
    unsigned char state;
    char unknown11[3];
    unsigned char* unknown_14_;
};

// USA: func_ov017_021b5250
extern "C" ARM void func_ov017_021b5250(Struct_ov017_021b5250* request) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(request->taskId)) {
        return;
    }

    if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int fileLength;
        void* fileData;
        loader->GetLoadedFileByID(request->taskId, &fileData, &fileLength);
        if (fileData != NULL) {
            Struct_ov017_021b5250_2* resources = request->resources;
            unsigned short keys[12];
            __clear(keys, sizeof(keys));
            short keyCount = (short)func_0209c0c0(&resources->keys, (Struct_0209c0c0*)keys);
            char* pending = request->resources->entries;
            func_0206efc4(pending);
            Struct_ov017_021b5250_2* var7 = request->resources;
            func_0206f230(pending, var7->allocator, (Struct_0206efd8*)fileData, fileLength, (short*)keys, keyCount
#if !defined(jpn)
                , var7->unknown_14_, request->unknown_14_
#endif
            );
        }
    }

    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->taskId = loader->QueueLoadFile(&data_ov017_021d7bc3, NULL);
    request->state = 7;
}
