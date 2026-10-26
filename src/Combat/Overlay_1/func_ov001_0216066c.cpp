#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void* a);
extern "C" int func_ov001_0215ad2c(int x);
extern "C" int func_ov017_021bbbe4(void* p);
extern "C" unsigned int func_ov001_0215a750(const char* path, void** outPtr);
extern SafeAllocator* data_ov001_021658b8[8];
extern char data_ov001_021657df[];
struct ObjectArchiveLoadInfo;
extern "C" void func_0200fd38(GameState* battleStruct, int id, GameObject* combatant);
struct Struct_0203d028_18;

struct Struct_ov001_0216066c {
    int unused0;
    void* dataPtr;
    unsigned int size;
    SafeAllocator* allocator;
    int flag;
    char pad[0xc];
};

// USA: func_ov001_0216066c
extern "C" ARM int func_ov001_0216066c(void* self) {
    char path[0x50];
    struct Struct_ov001_0216066c ctx;
    void* outPtr;
    unsigned int size;
    GameState* bs;
    SafeAllocator* allocator;
    void* newObj;
    int base;
    int id;

    bs = GameState::GetInstance();
    (int)BackgroundLoader::GetInstance();
    allocator = data_ov001_021658b8[0];
    id = func_ov001_0215ad2c(func_ov017_021d60f4(self));
    base = ((int)GetGameResources());
#if defined(jpn)
    base = *(int*)((char*)base + 0x3000 + 0x524);
#else
    base = *(int*)((char*)base + 0x3000 + 0x734);
#endif
    base = func_ov017_021bbbe4((void*)base);
    sprintf(path, data_ov001_021657df, base + 0x4);
    BackgroundLoader::AddLockGlobal();
    size = func_ov001_0215a750(path, &outPtr);
    if (size == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    newObj = allocator->Allocate(0xac);
    ((Object3D*)newObj)->Initialize();
    ctx.dataPtr = outPtr;
    ctx.allocator = allocator;
    ctx.size = size;
    ctx.flag = 1;
    ((Object3D*)((int)newObj))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)((int)&ctx));
    BackgroundLoader::RemoveLockGlobal();
    func_0200fd38(bs, id, (GameObject*)newObj);
    ((Object3D*)((struct Struct_0203d028_18*)newObj))->SetScale(0x10a, 0x10a, 0x10a);
    ((Object3D*)newObj)->SetAnimationByIndex(0, 0);
    return 1;
}
