#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct Struct_ov001_0215bcc0;

extern "C" void* __clear(void* dst, int count);
void* LoadFileIntoMemory(const char* path, void* buf, unsigned int* outLen);

struct Struct_203dafc;
extern "C" void func_0203dafc(struct Struct_203dafc* obj);

extern char data_ov015_02194078;
extern int g_fileLoadBuffer;

// USA: func_ov015_0218cb2c
extern "C" ARM void func_ov015_0218cb2c(void* self, int val) {
    unsigned char* base = (unsigned char*)self;
    ((Object3D*)((struct Struct_ov001_0215bcc0*)*(void**)(base + 0x24)))->RemoveAnimationPackageByID(3);
    if (val != 0) {
        SafeAllocator allocator;
        allocator.ResetAllocatorPointer();
        allocator.CreateTypeA(*(void**)(base + 0x14), *(unsigned int*)(base + 0x18));
        allocator.Reset();

        char buf[0x80];
        __clear(buf, 0x80);

        BackgroundLoader::AddLockGlobal();

        unsigned int length = 0;
        sprintf(buf, &data_ov015_02194078, val);
        void* buffer = LoadFileIntoMemory(buf, &g_fileLoadBuffer, &length);

        if (buffer != 0) {
            ObjectArchiveLoadInfo params;
            func_0203dafc((struct Struct_203dafc*)&params);
            params.allocator = &allocator;
            params.fileData = &g_fileLoadBuffer;
            params.fileSize = length;
            params.unk_10 = 1;
            params.packageID = 3;
            ((Object3D*)(*(void**)(base + 0x24)))->LoadFromCCHROrCMOTArchive(&params, 0);
        }

        BackgroundLoader::RemoveLockGlobal();
        allocator.Destroy();
    }
    ((Object3D*)(*(unsigned char**)(base + 0x24)))->StopCurrentAnimation();
    ((Object3D*)(*(void**)(base + 0x24)))->SetAnimationByIndex(0, *(int*)(base + 0x44));
}
