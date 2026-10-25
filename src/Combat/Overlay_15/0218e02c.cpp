#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "NitroSDK/Matrix.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "NitroSDK/Filesystem/NitroVM.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/Filesystem/FileAccessor.h"

extern "C" void* __clear(void* arg0, int arg1);

struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);

struct Struct_0203d028_11;
extern "C" void func_0203dafc(struct Struct_0203d028_11* arg0);

struct Struct_02055718;
extern "C" int func_02055718(struct Struct_02055718* arg0, int arg1, int arg2);

extern "C" void func_02054f80(void* arg0);
extern "C" int func_02055180(void* arg0, void* arg1, void* arg2, void* arg3);

struct Struct_ov015_0218e02c {
    unsigned int unknown_0_[3];
    void* unknown_c_;
};

struct Struct_02053634 {
    int unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    void* unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
};

extern char data_ov015_0219413f[];
extern char data_ov015_02194152[];
extern char data_ov015_02194156[];
extern Vector3i data_ov015_02193d08;

// USA: func_ov015_0218e02c
extern "C" ARM int func_ov015_0218e02c(void* arg0, int* arg1) {
    if (arg1[1] == 0) {
        return 0;
    }

    NarcHandle var0;
    NitroVM var1;
    char var2[0x50];
    char var3[0x20];

    __clear(var3, 0x20);

    (*(SafeAllocator**)((char*)arg0 + 8))->Reset();

    int ok = 1;
    struct Foo0207df50* palette = *(struct Foo0207df50**)*(void**)((char*)self + 4);
    VramState_Rewind(palette);
    VramState_Restore((char*)palette);

    sprintf(var3, data_ov015_0219413f, arg1[1]);

    BackgroundLoader::AddLockGlobal();

    unsigned int length = 0;
    if (LoadFileIntoMemory(path, g_fileLoadBuffer, &length) != 0) {
        if (narc.Initialize(data_ov015_02194152, g_fileLoadBuffer)) {
            NitroVM_Initialize(&vm);
            for (unsigned int index = 0; PrepareReadFileInNARCByID(&vm, &narc, index); ++index) {
                __clear(tmp, 0x50);
                NitroVM_WriteOutFilePath(&vm, tmp, 0x50);
                if (strstr(tmp, data_ov015_02194156) != 0) {
                    const void* file = narc.GetFileByIndex(index);
                    unsigned int size = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
                    unsigned int len = length;
                    if (len & 3) {
                        len += 4 - (len & 3);
                    }
                    void* var11 = (*(SafeAllocator**)((char*)arg0 + 8))->Allocate(var10);
                    if (var11 == 0) {
                        NitroVM_FinishRead(&var1);
                        var0.Destroy();
                        var4 = 0;
                    } else {
                        memcpy(var11, var8, var10);
                        (*(struct Struct_ov015_0218e02c**)((char*)arg0 + 0x28))->unknown_c_ =
                            (*(SafeAllocator**)((char*)arg0 + 8))->Allocate(0x128);
                        func_02054f80((*(struct Struct_ov015_0218e02c**)((char*)arg0 + 0x28))->unknown_c_);
                        if (func_02055180((*(struct Struct_ov015_0218e02c**)((char*)arg0 + 0x28))->unknown_c_,
                                          (*(SafeAllocator**)((char*)arg0 + 8)),
                                          var11, (void*)var9) == 0) {
                            var4 = 0;
                        }
                    }
                    NitroVM_FinishRead(&var1);
                    break;
                }
                NitroVM_FinishRead(&var1);
            }
        }
        var0.Destroy();

        Params02036804 info;
        ClearEightWords_0203dafc((struct Struct_203dafc*)&info);
        void* allocPtr = *(void**)((char*)self + 8);
        void* dataPtr = &g_fileLoadBuffer;
        unsigned int sz = length;
        int onePtr = 1;
        info.alloc = allocPtr;
        info.data = dataPtr;
        info.size = sz;
        info.one = onePtr;
        (*(Object3D**)((char*)self + 0x24))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)&info);

        func_02055718(*(struct Struct_02055718**)((char*)arg0 + 0x28),
                                    *(int*)((char*)arg0 + 0x24), *(int*)((char*)arg0 + 8));

        Vector3i v = data_ov015_02193d08;
        (*(Object3D**)((char*)self + 0x24))->SetScale(&v);
        (*(Object3D**)((char*)self + 0x24))->SetAnimationByIndex(0, *(int*)((char*)self + 0x44));
    } else {
        var4 = 0;
    }

    BackgroundLoader::RemoveLockGlobal();
    VramState_Save((char*)palette);

    if (var4 == 0) {
        return 0;
    }
    *(int*)((char*)arg0 + 0xc) = arg1[0];
    return 1;
}
