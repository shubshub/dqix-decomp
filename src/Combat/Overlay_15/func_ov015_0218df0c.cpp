#if defined(jpn)
#define R(j,u) (j)
#define func_ov008_021889f8 func_ov008_0218973c
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
#include "World/Object3D.h"

extern "C" void* __clear(void* arg0, int arg1);
void* LoadFileIntoMemory(const char* path, void* buf, unsigned int* outLen);

struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
struct Vector3i;

struct Struct_0203d028_11;
extern "C" void func_0203dafc(struct Struct_0203d028_11* arg0);

struct Struct_ov015_02193cfc { unsigned int unknown_0_[3]; };

extern char data_ov015_02194129;
extern struct Vec3Words02193cfc data_ov015_02193cfc;
extern int g_fileLoadBuffer;

// USA: func_ov015_0218df0c
extern "C" ARM int func_ov015_0218df0c(void* arg0, int* arg1) {
    if (arg1[1] == 0) {
        return 0;
    }

    char var0[0x20];
    __clear(var0, 0x20);

    ((SafeAllocator*)(*(void**)((char*)arg0 + 8)))->Reset();

    int ok = 1;
    struct Foo0207df50* mgr = *(struct Foo0207df50**)*(void**)((char*)self + 4);
    VramState_Rewind(mgr);
    VramState_Restore((char*)mgr);

    sprintf(var0, &data_ov015_02194129, arg1[1]);

    BackgroundLoader::AddLockGlobal();

    unsigned int length = 0;
    void* buffer = LoadFileIntoMemory(buf, &g_fileLoadBuffer, &length);

    if (var4 == 0) {
        var1 = 0;
    } else {
        ObjectArchiveLoadInfo params;
        ClearEightWords_0203dafc((struct Struct_203dafc*)&params);
        SafeAllocator* allocPtr = *(SafeAllocator**)((char*)self + 8);
        unsigned int sz = length;
        void* dataPtr = &g_fileLoadBuffer;
        int onePtr = ok;
        params.fileData = dataPtr;
        params.fileSize = sz;
        params.allocator = allocPtr;
        params.unk_10 = onePtr;
        ((Object3D*)(*(void**)((char*)self + 0x24)))->LoadFromCCHROrCMOTArchive(&params, 0);

        struct Struct_ov015_02193cfc var10 = data_ov015_02193cfc;
        ((Object3D*)((unsigned char*)*(void**)((char*)arg0 + 0x24)))->SetScale((Vector3i const*)&var10);

        ((Object3D*)(*(void**)((char*)self + 0x24)))->SetAnimationByIndex(0, *(int*)((char*)self + 0x44));
    }

    BackgroundLoader::RemoveLockGlobal();
    VramState_Save((char*)mgr);

    int var11;
    if (var1 == 0) {
        var11 = 0;
    } else {
        *(int*)((char*)arg0 + 0xc) = arg1[0];
        var11 = 1;
    }
    return var11;
}
