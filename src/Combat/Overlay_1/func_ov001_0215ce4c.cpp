#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void* arg0);
extern "C" int func_ov001_0215ad2c(int arg0);
extern "C" unsigned int func_ov001_0215a750(const char* arg0, void** arg1);
extern "C" void func_0200fd38(GameState* arg0, int arg1, GameObject* arg2);
extern "C" void NSBXX_Model_SetPolygonID(NSBXXInternalModel* model, int id);

extern SafeAllocator* data_ov001_021658b8[8];
extern const char data_ov001_02165775[];

// USA: func_ov001_0215ce4c
extern "C" ARM int func_ov001_0215ce4c(char* arg0, int arg1) {
    char var0[0x50];
    ObjectArchiveLoadInfo var1;
    void* var2;
    unsigned int var3;
    int var4;
    GameState* var5;
    BackgroundLoader* var6;
    SafeAllocator* var7;
    int var8;
    Object3D* var9;
    int var10;

    var5 = GameState::GetInstance();
    var6 = BackgroundLoader::GetInstance();
    var10 = func_ov001_0215ad2c(func_ov017_021d60f4(arg0));
    var4 = 0;
    if (arg1 >= 2) {
        var4 = func_ov017_021d60f4(arg0 + 8);
    }
    var7 = data_ov001_021658b8[var4];
    sprintf(var0, data_ov001_02165775);

    var8 = 0;
    var6->GetLoadedFileByName(var0, &var2, &var3);
    if (var2 == NULL) {
        BackgroundLoader::AddLockGlobal();
        var8 = 1;
        if (func_ov001_0215a750(var0, &var2) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }

    obj = (Object3D*)allocator->Allocate(0xac);
    obj->Initialize();
    loadInfo.allocator = allocator;
    loadInfo.fileData = fileData;
    loadInfo.fileSize = fileSize;
    loadInfo.unk_10 = 1;
    obj->LoadFromCHRArchive(&loadInfo);
    if (locked != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    NSBXX_Model_SetPolygonID(obj->pModel_->rawInternalModel_, 0x3d);
    obj->position_.x = 0;
    obj->position_.y = -0xa000;
    obj->position_.z = 0x1000;
    obj->SetAnimationByIndex(0, 0);
    obj->MakeHidden();
    RegisterCombatantSlot_0200fd38(bs, id, (GameObject*)obj);
    return 1;
}
