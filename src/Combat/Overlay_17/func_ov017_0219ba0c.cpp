#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

char* MessageSystem_GetInstance(void);
struct Foo0207df50;
void VramState_Rewind(Foo0207df50*);
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
    char* controller = MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* alloc = &res->allocator_array_38[6];
    char* tables = res->vramStates_ + 0x2a0;
    loader->AddLockGlobal();
    alloc->Reset();
    VramState_Rewind((Foo0207df50*)tables);
    VramState_Restore(tables);

    char path[0x50];
    sprintf(path, data_ov017_021d7504, data_ov017_021d7510);
    if (!LoadFileIntoMemory(path, g_fileLoadBuffer, &length)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }

    NarcHandle narc;
    if (!narc.Initialize(data_ov017_021d751b, g_fileLoadBuffer)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    CallFunc0202f310AtField0x19e0_020440b8(controller, alloc, g_fileLoadBuffer);
    if (skipModels) {
        narc.Destroy();
        VramState_Save(tables);
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    var9.Destroy();

    ((Model3D*)res->unknown_ptr_36c8)->Clear();
    if (GetFileInNarc(g_fileLoadBuffer, data_ov017_021d7577, &file, &fileSize, 0)) {
        ((Model3D*)res->unknown_ptr_36c8)->CopyAndProcessRawFile(&alloc->allocUnion, file, fileSize, Model3D::TextureStagingMode_Normal);
    }
    ((Object3D*)res->unknown_ptr_36cc)->Initialize();
    if (GetFileInNarc(g_fileLoadBuffer, data_ov017_021d7584, &file, &fileSize, 0)) {
        ObjectArchiveLoadInfo info;
        info.fileData = file;
        info.fileSize = fileSize;
        info.allocator = alloc;
        info.unk_10 = 1;
        ((Object3D*)res->unknown_ptr_36cc)->LoadFromCHRArchive(&info);
    }
    VramState_Save(tables);

    if (!LoadFileIntoMemory(data_ov017_021d758d, g_fileLoadBuffer, &size)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* var11 = var6->Allocate(var3);
    if (var11 == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    memcpy(buf, g_fileLoadBuffer, size);
    *(void**)((char*)res + 0x30) = buf;
    *(unsigned int*)((char*)res + 0x34) = size;
    if (!LoadFileIntoMemory(data_ov017_021d75a2, g_fileLoadBuffer, &size)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    var11 = var6->Allocate(var3);
    if (var11 == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    memcpy(buf, g_fileLoadBuffer, size);
    *(void**)((char*)res + 0x2c) = buf;
    BackgroundLoader::RemoveLockGlobal();
}
