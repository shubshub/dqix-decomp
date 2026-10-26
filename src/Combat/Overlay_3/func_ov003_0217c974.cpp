#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { kRegionValue2CC_27C = 0x27c };
#else
enum { kRegionValue2CC_27C = 0x2cc };
#endif

struct Struct_020534ac;

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
struct Vector3i;

extern char data_ov003_02180c1d;
extern char data_ov003_02180c23;

struct Struct_ov003_0217fb8c { unsigned int v[3]; };
extern struct Struct_ov003_0217fb8c data_ov003_0217fb8c;

// USA: func_ov003_0217c974
extern "C" ARM void func_ov003_0217c974(char* self) {
    int list = (int)BackgroundLoader::GetInstance();
    int out1, out2;
    ((BackgroundLoader*)((struct Struct_020534ac*)list))->GetLoadedFileByID((int)(*(int*)(self + 0x130)), (void**)(&out1), (unsigned int*)(&out2));

    void* mgr = GetGameResources();
    VramState_Rewind((struct Foo0207df50*)((char*)mgr + kRegionValue2CC_27C));
    VramState_Restore((char*)mgr + kRegionValue2CC_27C);

    unsigned int fileSize;
    const void* filePtr;
    if (FindFilesInNarcBySubstring((const void*)out1, &data_ov003_02180c1d, &filePtr, &fileSize, 1) == 0) {
        return;
    }

    unsigned int decompSize;
    void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*(SafeAllocator*)(self + 4), filePtr, decompSize);
    if (decompressed == 0) {
        return;
    }

    ObjectArchiveLoadInfo params;
    params.unk_0 = 0;
    params.fileData = decompressed;
    params.unk_14 = 0;
    params.unk_18 = 0;
    params.packageID = 0;
    params.allocator = (SafeAllocator*)(self + 4);
    params.fileSize = decompSize;
    params.unk_10 = 1;
    ((Object3D*)(self + 0x80))->LoadFromCCHROrCMOTArchive(&params, 0);

    VramState_Save((char*)mgr + kRegionValue2CC_27C);

    struct Struct_ov003_0217fb8c v = data_ov003_0217fb8c;
    *(int*)(self + 0xc4) = 0;
    *(int*)(self + 0xc8) = 0xfae;
    *(int*)(self + 0xcc) = 0;
    ((Object3D*)((unsigned char*)(self + 0x80)))->SetScale((Vector3i const*)&v);

    ((Object3D*)(self + 0x80))->SetAnimationByName((char const*)&data_ov003_02180c23, 0);
}
