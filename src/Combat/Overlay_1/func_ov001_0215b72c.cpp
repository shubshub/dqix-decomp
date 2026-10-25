#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <std_library_functions.h>

struct Struct_ov001_0215b72c { char unknown_0_[8]; };
extern "C" const char* func_ov017_021d612c(Struct_ov001_0215b72c*);
extern "C" int func_ov017_021d60f4(Struct_ov001_0215b72c*);
extern "C" int func_ov001_0215ad2c(int);
extern "C" int func_ov001_0215ad3c(const char*, char*, char*);
extern "C" unsigned int func_ov001_0215a750(const char*, void**);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_02165745[];
extern const char data_ov001_0216574d[];
extern const char data_ov001_02165752[];
extern const char data_ov001_02165758[];
extern const char data_ov001_02165762[];

static inline int inline_ov001_0215b72c(Struct_ov001_0215b72c* arg0) {
    return func_ov001_0215ad2c(func_ov017_021d60f4(arg0));
}

// USA: func_ov001_0215b72c
extern "C" ARM int func_ov001_0215b72c(Struct_ov001_0215b72c* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    SafeAllocator* var1;
    int var2;
    Object3D* var3;
    BackgroundLoader* var4 = BackgroundLoader::GetInstance();
    const char* var5 = func_ov017_021d612c(arg0);
    int var6 = inline_ov001_0215b72c(arg0 + 1);
    int var7 = 0;
    if (arg1 >= 3) var7 = func_ov017_021d60f4(arg0 + 2);
    var1 = data_ov001_021658b8[var7];
    if (var6 < 160 || var6 > 191) return 0;
    char var8[80];
    char var9[80];
    void* var10 = 0;
    unsigned int var11 = 0;
    if (func_ov001_0215ad3c(var5, var8, var9)) {
        var4->GetLoadedFileInArchive(var9, var8, &var10, &var11);
    } else {
        sprintf(var8, data_ov001_02165745, var5);
        var4->GetLoadedFileByName(var8, &var10, &var11);
    }
    var2 = 0;
    if (!var10) {
        BackgroundLoader::AddLockGlobal();
        var2 = 1;
        if (!func_ov001_0215a750(var8, &var10)) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    var3 = (Object3D*)var1->Allocate(sizeof(Object3D));
    if (!var3) {
        if (var2) BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    object->Initialize();
    if (strstr(filename, data_ov001_0216574d)) {
        int compressed = 0;
        if (strstr(filename, data_ov001_02165752) || strstr(filename, data_ov001_02165758)) compressed = 1;
        ObjectArchiveLoadInfo info;
        info.allocator = allocator;
        info.fileData = data;
        info.fileSize = size;
        info.unk_10 = 1;
        if (compressed == 0) object->LoadFromCHRArchive(&info);
        else if (compressed == 1) object->LoadFromCCHROrCMOTArchive(&info, 0);
        object->SetAnimationByIndex(0, 0);
    } else if (strstr(filename, data_ov001_02165762)) {
        void* model = allocator->Allocate(size);
        memcpy(model, data, size);
        object->SetModelFromFile(allocator, model, size, Model3D::TextureStagingMode_Normal);
    } else {
        if (var2) BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    if (var2) BackgroundLoader::RemoveLockGlobal();
    func_0200fd38(var0, var6, (GameObject*)var3);
    var3->SetScale(266, 266, 266);
    return 1;
}
