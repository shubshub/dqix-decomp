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
void CopyInternalFields0207df50(struct Foo0207df50* p);
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
    CopyInternalFields0207df50(palette);
    VramState_Restore((char*)palette);

    sprintf(var3, data_ov015_0219413f, arg1[1]);

    BackgroundLoader::AddLockGlobal();

    unsigned int var6 = 0;
    if (LoadFileIntoMemory(var3, data_0211e33c, &var6) != 0) {
        if (var0.Initialize(data_ov015_02194152, data_0211e33c)) {
            NitroVM_Initialize(&var1);
            for (unsigned int var7 = 0; PrepareReadFileInNARCByID(&var1, &var0, var7); ++var7) {
                __clear(var2, 0x50);
                NitroVM_WriteOutFilePath(&var1, var2, 0x50);
                if (strstr(var2, data_ov015_02194156) != 0) {
                    const void* var8 = var0.GetFileByIndex(var7);
                    unsigned int var9 = var1.fileInfo.unknown_8_ - var1.fileInfo.unknown_4_;
                    unsigned int var10 = var6;
                    if (var10 & 3) {
                        var10 += 4 - (var10 & 3);
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

        Struct_02053634 var12;
        func_0203dafc((struct Struct_0203d028_11*)&var12);
        void* var13 = *(void**)((char*)arg0 + 8);
        void* var14 = &data_0211e33c;
        unsigned int var15 = var6;
        int var16 = 1;
        var12.unknown_c_ = var13;
        var12.unknown_4_ = var14;
        var12.unknown_8_ = var15;
        var12.unknown_10_ = var16;
        (*(Object3D**)((char*)arg0 + 0x24))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)&var12);

        func_02055718(*(struct Struct_02055718**)((char*)arg0 + 0x28),
                                    *(int*)((char*)arg0 + 0x24), *(int*)((char*)arg0 + 8));

        Vector3i var17 = data_ov015_02193d08;
        (*(Object3D**)((char*)arg0 + 0x24))->SetScale(&var17);
        (*(Object3D**)((char*)arg0 + 0x24))->MaybeSetBCFGAnimation(0, *(int*)((char*)arg0 + 0x44));
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
