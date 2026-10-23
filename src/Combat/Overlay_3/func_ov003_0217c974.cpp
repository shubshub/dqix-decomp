#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov003_0217c974_716 = 0x27c };
#else
enum { Enum_ov003_0217c974_716 = 0x2cc };
#endif

struct Struct_020534ac;

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
struct Vector3i;

extern char data_ov003_02180c1d;
extern char data_ov003_02180c23;

struct Struct_ov003_0217fb8c { unsigned int unknown_0_[3]; };
extern struct Struct_ov003_0217fb8c data_ov003_0217fb8c;

// USA: func_ov003_0217c974
extern "C" ARM void func_ov003_0217c974(char* arg0) {
    int var0 = (int)BackgroundLoader::GetInstance();
    int var1, var2;
    ((BackgroundLoader*)((struct Struct_020534ac*)var0))->GetLoadedFileByID((int)(*(int*)(arg0 + 0x130)), (void**)(&var1), (unsigned int*)(&var2));

    void* mgr = GetGameResources();
    CopyInternalFields0207df50((struct Foo0207df50*)((char*)mgr + kRegionValue2CC_27C));
    VramState_Restore((char*)mgr + kRegionValue2CC_27C);

    unsigned int var4;
    const void* var5;
    if (FindFilesInNarcBySubstring((const void*)var1, &data_ov003_02180c1d, &var5, &var4, 1) == 0) {
        return;
    }

    unsigned int var6;
    void* var7 = DecompressLZ77FileIntoAllocatedSpace(*(SafeAllocator*)(arg0 + 4), var5, var6);
    if (var7 == 0) {
        return;
    }

    ObjectArchiveLoadInfo var8;
    var8.unk_0 = 0;
    var8.fileData = var7;
    var8.unk_14 = 0;
    var8.unk_18 = 0;
    var8.packageID = 0;
    var8.allocator = (SafeAllocator*)(arg0 + 4);
    var8.unk_8 = var6;
    var8.unk_10 = 1;
    ((Object3D*)(arg0 + 0x80))->LoadFromCCHROrCMOTArchive(&var8, 0);

    VramState_Save((char*)mgr + kRegionValue2CC_27C);

    struct Struct_ov003_0217fb8c var9 = data_ov003_0217fb8c;
    *(int*)(arg0 + 0xc4) = 0;
    *(int*)(arg0 + 0xc8) = 0xfae;
    *(int*)(arg0 + 0xcc) = 0;
    ((Object3D*)((unsigned char*)(arg0 + 0x80)))->SetScale((Vector3i const*)&var9);

    ((Object3D*)(arg0 + 0x80))->MaybeSetRegularAnimation((char const*)&data_ov003_02180c23, 0);
}
