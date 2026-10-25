#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* arg0);
extern "C" int func_ov017_021d60f4(void* arg0);
extern "C" int func_ov001_0215ad2c(int arg0);
extern "C" unsigned int func_ov001_0215a750(const char* arg0, void** arg1);

extern const char data_ov001_02165745[];
extern SafeAllocator* data_ov001_021658b8[8];

// USA: func_ov001_0215bb3c
extern "C" ARM int func_ov001_0215bb3c(char* arg0, int arg1) {
    char var0[0x50];
    ObjectArchiveLoadInfo var1;
    void* var2;
    unsigned int var3;
    GameState* var4;
    BackgroundLoader* var5;
    SafeAllocator* var6;
    int var7;
    void* var8;
    int var9;
    int var10;

    var4 =GameState::GetInstance();
    var5 = BackgroundLoader::GetInstance();
    var8 = func_ov017_021d612c(arg0);
    char* var11 = arg0 + 0x8;
    arg0 += 0x10;
    var9 = func_ov001_0215ad2c(func_ov017_021d60f4(var11));

    var10 = 0;
    if (arg1 >= 3) {
        var10 = func_ov017_021d60f4(arg0);
        arg0 += 0x8;
    }
    var6 = data_ov001_021658b8[var10];

    var7 = 3;
    if (arg1 >= 4) {
        var7 = func_ov017_021d60f4(arg0);
    }

    GameObject* var12 = var4->GetGameObjectByIndex(var9);
    if (var12 == NULL) return 0;

    sprintf(var0, data_ov001_02165745, var8);
    int var13 = 0;
    var5->GetLoadedFileByName(var0, &var2, &var3);
    if (var2 == NULL) {
        BackgroundLoader::AddLockGlobal();
        var13 = 1;
        if (func_ov001_0215a750(var0, &var2) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }

    AnimationPackage* var14 = var12->obj3D_.loadedAnimationPackageList_;
    int var15 = 0;
    if (var14 != NULL) {
        var15 = var14->animationType;
    }

    loadInfo.allocator = allocator;
    loadInfo.fileData = fileData;
    loadInfo.fileSize = fileSize;
    loadInfo.unk_10 = 1;
    loadInfo.packageID = packageID;

    if (var15 == 0) {
        var12->obj3D_.LoadFromCHRArchive(&var1);
    } else if (var15 == 1) {
        var12->obj3D_.LoadFromCCHROrCMOTArchive(&var1, NULL);
    }

    if (var13) {
        BackgroundLoader::RemoveLockGlobal();
    }
    obj->obj3D_.SetAnimationByIndex(0, 0);
    return 1;
}
