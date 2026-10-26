#include <globaldefs.h>
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/GamecardBusOwnership.h"

struct Struct_ov031_0223b4d4 {
    void* allocation;
    char pad04[0x84];
    NitroHandle handle;
    unsigned short owner;
};
extern "C" Struct_ov031_0223b4d4* data_ov031_02290d24;
namespace DuplicatePool {
    extern "C" Struct_ov031_0223b4d4* data_ov031_02290d24;
}
extern char data_ov031_0224c564[];
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_0223b4d4
extern "C" ARM void func_ov031_0223b4d4(void) {
    SetROMFilesystemRoot(data_ov031_0224c564);
    NitroHandle_ReleaseFileTables(&data_ov031_02290d24->handle);
    NitroHandle_Destroy(&data_ov031_02290d24->handle);
    NitroHandle_RemoveFromHandleList(&data_ov031_02290d24->handle);
    ReleaseLockOwnerID(data_ov031_02290d24->owner);
    data_ov031_02290d24->owner = 0;
    func_ov031_0223cf70(&data_ov031_02290d24->allocation);
    data_ov031_02290d24->allocation = NULL;
    func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290d24);
}
