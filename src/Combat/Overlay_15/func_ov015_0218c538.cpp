#include <globaldefs.h>
#if defined(jpn)
#define data_ov015_02194020 data_ov015_02194b60
#define data_ov015_0219403b data_ov015_02194b7b
#define data_ov015_02194042 data_ov015_02194b82
#define data_ov015_0219404a data_ov015_02194b8a
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194064 data_ov015_02194ba4
#define data_ov015_02194078 data_ov015_02194bb8
#endif
#include "std_library_functions.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Combat/Overlay15ViewerContext.h"

extern "C" void* __clear(void* arg0, int arg1);
extern "C" void func_02079a3c(void* arg0);

struct Struct_0203d028_11;
extern "C" void func_0203dafc(struct Struct_0203d028_11* arg0);

extern char data_ov015_02194020[27] __attribute__((aligned(4)));
extern char data_ov015_0219403b[7];
extern char data_ov015_02194042[8];
extern char data_ov015_0219404a[8];
extern char data_ov015_02194052[17];
extern char data_ov015_02194064[20];
extern char data_ov015_02194078[22];
extern char data_ov015_0219408e[6];

// USA: func_ov015_0218c538
extern "C" ARM void func_ov015_0218c538(Struct_ov015_0218bcb0* arg0, char* arg1) {
    arg0->unknown_24_[0].RemoveAllAnimationPackages();
    arg0->unknown_24_[1].RemoveAllAnimationPackages();

    SafeAllocator var0;
    var0.ResetAllocatorPointer();
    var0.CreateTypeA(arg0->unknown_14_, arg0->unknown_18_);
    var0.Reset();

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    char var1[0x80];
    char var2[0x80];
    __clear(var1, 0x80);
    __clear(var2, 0x80);

    unsigned int size = 0;
    unsigned char* buffer = g_fileLoadBuffer;
    unsigned int room = 0x30000;
    GPCReadPair pair;
    ResetObjectState02079a3c(&pair);

    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&var6.pGPCFile, var6.machine,
            data_ov015_02194020, var4, var3, var5, false, 0)) {
        var4 += var3;
        var5 -= var3;

        func_ov015_0218c274(self, status, 0);
        sprintf(name, data_ov015_0219403b, status);
        if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, name)) {
            ObjectArchiveLoadInfo info1;
            ClearEightWords_0203dafc((Struct_203dafc*)&info1);
            info1.allocator = &allocator;
            info1.fileSize = size;
            info1.fileData = buffer;
            info1.unk_10 = 1;
            self->objects_[0].LoadFromCCHROrCMOTArchive(&info1, 0);
            buffer += size;
            room -= size;
        }

        if (self->field48_ == 1) {
            sprintf(name, data_ov015_02194042, status);
            if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, name)) {
                ObjectArchiveLoadInfo info2;
                ClearEightWords_0203dafc((Struct_203dafc*)&info2);
info2.allocator = &allocator;
            info2.fileSize = size;
            info2.fileData = buffer;
            info2.unk_10 = 1;
                self->objects_[0].LoadFromCCHROrCMOTArchive(&info2, 0);
                buffer += size;
                room -= size;
            }
            sprintf(name, data_ov015_0219404a, status);
            if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, name)) {
                ObjectArchiveLoadInfo info3;
                ClearEightWords_0203dafc((Struct_203dafc*)&info3);
info3.allocator = &allocator;
            info3.fileSize = size;
            info3.fileData = buffer;
            info3.unk_10 = 1;
                self->objects_[0].LoadFromCCHROrCMOTArchive(&info3, 0);
                buffer += size;
                room -= size;
            }
        }

        func_ov015_0218c274(arg0, var1, 1);
        if (arg0->unknown_48_ == 0) {
            sprintf(var2, data_ov015_02194042, var1);
        } else {
            sprintf(var2, data_ov015_0219403b, var1);
        }
        if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer, size, room, name)) {
            ObjectArchiveLoadInfo info4;
            ClearEightWords_0203dafc((Struct_203dafc*)&info4);
            info4.allocator = &allocator;
            info4.fileSize = size;
            info4.fileData = buffer;
            info4.unk_10 = 1;
            self->objects_[0].LoadFromCCHROrCMOTArchive(&info4, 0);
        }

        var6.Reset();
    }

    if (arg1 != 0) {
        char var11 = 'w';
        if (arg0->unknown_3b_ == 0)
            var11 = 'm';
        if (*(int*)((char*)arg0->unknown_0_ + 0x1a4) == 0x1f) {
            sprintf(var2, data_ov015_02194052, arg1);
        } else if (*(int*)((char*)arg0->unknown_0_ + 0x1a4) == 0x20) {
            sprintf(var2, data_ov015_02194064, arg1, var11);
        } else {
            sprintf(var2, data_ov015_02194078, arg1);
        }
        if (LoadFileIntoMemory(name, g_fileLoadBuffer, &size)) {
            ObjectArchiveLoadInfo info5;
            ClearEightWords_0203dafc((Struct_203dafc*)&info5);
            info5.allocator = &allocator;
            info5.fileData = g_fileLoadBuffer;
            info5.fileSize = size;
            info5.unk_10 = 1;
            info5.packageID = 4;
            self->objects_[0].LoadFromCCHROrCMOTArchive(&info5, 0);
        }
    }

    var0.Destroy();
    BackgroundLoader::RemoveLockGlobal();
    self->objects_[0].StopCurrentAnimation();
    self->objects_[0].SetAnimationByName(data_ov015_0219408e, 0);
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
