#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_02046cc8_716 = 0x27c };
#else
enum { Enum_02046cc8_716 = 0x2cc };
#endif

extern "C" void NSBXX_Model_SetPolygonID(void* obj, unsigned int value);

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
struct Fields020407b4;
extern "C" void func_020407b4(struct Fields020407b4* obj, int a, int b, int c);

// USA: func_02046cc8
extern "C" ARM int func_02046cc8(void* self) {
    char* pool;
    void* base;
    BackgroundLoader* loader;
    SafeAllocator* allocator;
    void* fileData;
    unsigned int fileSize;
    ObjectArchiveLoadInfo info;

    if (*(int*)((char*)self + 0xe8) != 0) {
        return 1;
    }
    if (*(int*)((char*)self + 0xec) < 0) {
        return 0;
    }

    GameState::GetInstance();
    base = GetGameResources();
    allocator = *(SafeAllocator**)((char*)self + 0x38);
    if (allocator == NULL) {
        allocator = (SafeAllocator*)((char*)self + 0x24);
    }
    loader = BackgroundLoader::GetInstance();

    if (loader->GetTaskStatus(*(int*)((char*)self + 0xec)) != 0) {
        pool = (char*)base + Enum_02046cc8_716;
        if (*(unsigned char*)((char*)self + 0x1d) != 0) {
            VramState_Rewind((struct Foo0207df50*)(pool + 0xc40));
            VramState_Restore(pool + 0xc40);

            loader->GetLoadedFileByID(*(int*)((char*)self + 0xec), &fileData, &fileSize);
            if (fileData != NULL && allocator->GetSignedAllocator() != NULL) {
                Object3D* obj = (Object3D*)((char*)self + 0x3c);
                obj->Initialize();
                info.fileData = fileData;
                info.fileSize = fileSize;
                info.allocator = allocator;
                info.unk_10 = 1;
                obj->LoadFromCHRArchive(&info);
                void* var8 = *(void**)((char*)self + 0x44);
                NSBXX_Model_SetPolygonID(*(void**)((char*)var8 + 0x54), 0x3d);
                func_020407b4((struct Fields020407b4*)obj, 0, -0xa000, 0x1000);
                obj->SetAnimationByIndex(0, 0);
            }
            VramState_Save(pool + 0xc40);
        }
        loader->RemoveTask(*(int*)((char*)self + 0xec));
        *(int*)((char*)self + 0xec) = -1;
        return 1;
    }
    return 0;
}
