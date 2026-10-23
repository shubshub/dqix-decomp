#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

char* GetGlobalField0x1c020421a0(void);
struct Foo0207df50;
void CopyInternalFields0207df50(Foo0207df50*);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
void CallFunc0202f310AtField0x19e0_020440b8(char* base, void* alloc, void* data);

extern char data_ov017_021d7504[];
extern char data_ov017_021d7510[];
extern char data_ov017_021d751b[];
extern char data_ov017_021d7577[];
extern char data_ov017_021d7584[];
extern char data_ov017_021d758d[];
extern char data_ov017_021d75a2[];

// USA: func_ov017_0219ba0c
extern "C" ARM void func_ov017_0219ba0c(GameResources* res, int skipModels) {
    const void* file;
    unsigned int fileSize;
    unsigned int length;
    unsigned int size;
    char* controller = GetGlobalField0x1c020421a0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* alloc = &res->allocator_array_38[6];
    char* tables = res->unknown_2cc + 0x2a0;
    loader->AddLockGlobal();
    alloc->Reset();
    CopyInternalFields0207df50((Foo0207df50*)tables);
    VramState_Restore(tables);

    char var8[0x50];
    sprintf(var8, data_ov017_021d7504, data_ov017_021d7510);
    if (!LoadFileIntoMemory(var8, data_0211e33c, &var2)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }

    NarcHandle var9;
    if (!var9.Initialize(data_ov017_021d751b, data_0211e33c)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    CallFunc0202f310AtField0x19e0_020440b8(controller, alloc, data_0211e33c);
    if (skipModels) {
        narc.Destroy();
        VramState_Save(tables);
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    var9.Destroy();

    ((Model3D*)arg0->unknown_ptr_36c8)->Clear();
    if (GetFileInNarc(data_0211e33c, data_ov017_021d7577, &var0, &var1, 0)) {
        ((Model3D*)arg0->unknown_ptr_36c8)->CopyAndProcessRawFile(&var6->allocUnion, var0, var1, Model3D::TextureStagingMode_Normal);
    }
    ((Object3D*)arg0->unknown_ptr_36cc)->Initialize();
    if (GetFileInNarc(data_0211e33c, data_ov017_021d7584, &var0, &var1, 0)) {
        ObjectArchiveLoadInfo var10;
        var10.fileData = var0;
        var10.unk_8 = var1;
        var10.allocator = var6;
        var10.unk_10 = 1;
        ((Object3D*)arg0->unknown_ptr_36cc)->LoadFromCHRArchive(&var10);
    }
    VramState_Save(tables);

    if (!LoadFileIntoMemory(data_ov017_021d758d, data_0211e33c, &var3)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* var11 = var6->Allocate(var3);
    if (var11 == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    memcpy(var11, data_0211e33c, var3);
    *(void**)((char*)arg0 + 0x30) = var11;
    *(unsigned int*)((char*)arg0 + 0x34) = var3;
    if (!LoadFileIntoMemory(data_ov017_021d75a2, data_0211e33c, &var3)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    var11 = var6->Allocate(var3);
    if (var11 == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    memcpy(var11, data_0211e33c, var3);
    *(void**)((char*)arg0 + 0x2c) = var11;
    BackgroundLoader::RemoveLockGlobal();
}
