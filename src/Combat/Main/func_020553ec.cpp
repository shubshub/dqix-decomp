#include <globaldefs.h>

#include "World/Object3D.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "Resource/ResourceMutex.h"
#include "std_library_functions.h"

struct Struct_020553ac {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    Object3D unknown_14_;
    char unknown_c0_[0x1e8 - 0xc0];
    int unknown_1e8_;
    int unknown_1ec_;
};

extern "C" void func_02054f80(void* arg0);
extern "C" ARM int func_02055180(void* arg0, void* arg1, void* arg2, void* arg3);

extern const char data_020f04b4[];
extern const char data_020f04b8[];

// USA: func_020553ec
extern "C" ARM int func_020553ec(void* arg0, int arg1, void* arg2, void* arg3, unsigned int arg4) {
    Struct_020553ac* var0 = (Struct_020553ac*)arg0;

    ObjectArchiveLoadInfo var1;
    NarcHandle var2;
    NitroVM var3;
    char var4[0x50];

    var0->unknown_0_ = arg1;
    var0->unknown_1e8_ = 0;
    var0->unknown_14_.Initialize();
    func_02054f80(&var0->unknown_c0_);
    if (arg2 != 0) {
        var0->unknown_4_ = (int)arg2;
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
    if (var2.Initialize(data_020f04b4, (const unsigned char*)arg3)) {
        NitroVM_Initialize(&var3);
        unsigned int var5;
        for (var5 = 0; PrepareReadFileInNARCByID(&var3, &var2, var5); var5++) {
            NitroVM_WriteOutFilePath(&var3, var4, sizeof(var4));
            if (strstr(var4, data_020f04b8)) {
                const void* var6 = var2.GetFileByIndex(var5);
                unsigned int var7 = var3.fileInfo.unknown_8_ - var3.fileInfo.unknown_4_;
                unsigned int var8 = var7;
                func_02055180((void*)&var0->unknown_c0_, arg2, (void*)var6, (void*)var8);
                var0->unknown_1e8_ = 1;
                NitroVM_FinishRead(&var3);
                break;
            }
            NitroVM_FinishRead(&var3);
        }
        var2.Destroy();
    }
    UnlockResourceMutex();
    if (obj->field1e8 == 0) {
        obj->object3d.SetAnimationByIndex(0, 0);
    }
    return 1;
}