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

extern "C" void* __clear(void* dst, int count);

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);

struct Struct_203dafc;
extern "C" void func_0203dafc(struct Struct_203dafc* obj);

struct Struct_02055718;
extern "C" int func_02055718(struct Struct_02055718* p, int a, int b);

extern "C" void func_02054f80(void* obj);
extern "C" int func_02055180(void* a, void* b, void* c, void* d);

struct Struct_ov015_0218e02c {
    unsigned int unknown_0_[3];
    void* obj;
};

struct Struct_02053634 {
    int flag;
    void* data;
    unsigned int size;
    void* alloc;
    int one;
    int pad18;
    int unknown_18_;
    int pad20;
};

extern char data_ov015_0219413f[];
extern char data_ov015_02194152[];
extern char data_ov015_02194156[];
extern Vector3i data_ov015_02193d08;

// USA: func_ov015_0218e02c
extern "C" ARM int func_ov015_0218e02c(void* self, int* desc) {
    if (desc[1] == 0) {
        return 0;
    }

    NarcHandle narc;
    NitroVM vm;
    char tmp[0x50];
    char path[0x20];

    __clear(path, 0x20);

    (*(SafeAllocator**)((char*)self + 8))->Reset();

    int ok = 1;
    struct Foo0207df50* palette = *(struct Foo0207df50**)*(void**)((char*)self + 4);
    VramState_Rewind(palette);
    VramState_Restore((char*)palette);

    sprintf(path, data_ov015_0219413f, desc[1]);

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
                    void* buf = (*(SafeAllocator**)((char*)self + 8))->Allocate(len);
                    if (buf == 0) {
                        NitroVM_FinishRead(&vm);
                        narc.Destroy();
                        ok = 0;
                    } else {
                        memcpy(buf, file, len);
                        (*(struct Struct_ov015_0218e02c**)((char*)self + 0x28))->obj =
                            (*(SafeAllocator**)((char*)self + 8))->Allocate(0x128);
                        func_02054f80((*(struct Struct_ov015_0218e02c**)((char*)self + 0x28))->obj);
                        if (func_02055180((*(struct Struct_ov015_0218e02c**)((char*)self + 0x28))->obj,
                                          (*(SafeAllocator**)((char*)self + 8)),
                                          buf, (void*)size) == 0) {
                            ok = 0;
                        }
                    }
                    NitroVM_FinishRead(&vm);
                    break;
                }
                NitroVM_FinishRead(&vm);
            }
        }
        narc.Destroy();

        Struct_02053634 info;
        func_0203dafc((struct Struct_203dafc*)&info);
        void* var13 = *(void**)((char*)self + 8);
        void* dataPtr = &g_fileLoadBuffer;
        unsigned int sz = length;
        int var16 = 1;
        info.alloc = var13;
        info.data = dataPtr;
        info.size = sz;
        info.one = var16;
        (*(Object3D**)((char*)self + 0x24))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)&info);

        func_02055718(*(struct Struct_02055718**)((char*)self + 0x28),
                                    *(int*)((char*)self + 0x24), *(int*)((char*)self + 8));

        Vector3i v = data_ov015_02193d08;
        (*(Object3D**)((char*)self + 0x24))->SetScale(&v);
        (*(Object3D**)((char*)self + 0x24))->SetAnimationByIndex(0, *(int*)((char*)self + 0x44));
    } else {
        ok = 0;
    }

    BackgroundLoader::RemoveLockGlobal();
    VramState_Save((char*)palette);

    if (ok == 0) {
        return 0;
    }
    *(int*)((char*)self + 0xc) = desc[0];
    return 1;
}
