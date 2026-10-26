#include <globaldefs.h>

#include "World/Object3D.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "Resource/ResourceMutex.h"
#include "std_library_functions.h"

struct Struct_020553ac {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    Object3D object3d;
    char unknown_c0_[0x1e8 - 0xc0];
    int unknown_1e8_;
    int unknown_1ec_;
};

extern "C" void func_02054f80(void* obj);
extern "C" ARM int func_02055180(void* obj, void* a1, void* a2, void* a3);

extern const char data_020f04b4[];
extern const char data_020f04b8[];

// USA: func_020553ec
extern "C" ARM int func_020553ec(void* arg0, int a1, void* alloc, void* fileData, unsigned int fileSize) {
    Struct_020553ac* obj = (Struct_020553ac*)arg0;

    ObjectArchiveLoadInfo li;
    NarcHandle narc;
    NitroVM machine;
    char filename[0x50];

    obj->field0 = a1;
    obj->unknown_1e8_ = 0;
    obj->object3d.Initialize();
    func_02054f80(&obj->unknown_c0_);
    if (alloc != 0) {
        obj->field4 = (int)alloc;
    }

    li.unk_0 = 0;
    li.unk_10 = 0;
    li.unk_14 = 0;
    li.unk_18 = 0;
    li.packageID = 0;
    li.fileData = fileData;
    li.fileSize = (int)fileSize;
    li.allocator = (SafeAllocator*)alloc;
    obj->object3d.LoadFromCHRArchive(&li);

    LockResourceMutex();
    if (narc.Initialize(data_020f04b4, (const unsigned char*)fileData)) {
        NitroVM_Initialize(&machine);
        unsigned int fileID;
        for (fileID = 0; PrepareReadFileInNARCByID(&machine, &narc, fileID); fileID++) {
            NitroVM_WriteOutFilePath(&machine, filename, sizeof(filename));
            if (strstr(filename, data_020f04b8)) {
                const void* fileBytes = narc.GetFileByIndex(fileID);
                unsigned int fileLength = machine.fileInfo.endOffset - machine.fileInfo.startOffset;
                unsigned int len2 = fileLength;
                func_02055180((void*)&obj->unknown_c0_, alloc, (void*)fileBytes, (void*)len2);
                obj->unknown_1e8_ = 1;
                NitroVM_FinishRead(&machine);
                break;
            }
            NitroVM_FinishRead(&machine);
        }
        narc.Destroy();
    }
    UnlockResourceMutex();
    if (obj->unknown_1e8_ == 0) {
        obj->object3d.SetAnimationByIndex(0, 0);
    }
    return 1;
}