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
void CopyInternalFields0207df50(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
struct Fields020407b4;
void SetFields0x44(struct Fields020407b4* obj, int a, int b, int c);

// USA: func_02046cc8
extern "C" ARM int func_02046cc8(void* arg0) {
    char* var0;
    void* var1;
    BackgroundLoader* var2;
    SafeAllocator* var3;
    void* var4;
    unsigned int var5;
    ObjectArchiveLoadInfo var6;

    if (*(int*)((char*)arg0 + 0xe8) != 0) {
        return 1;
    }
    if (*(int*)((char*)arg0 + 0xec) < 0) {
        return 0;
    }

    GameState::GetInstance();
    var1 = GetGameResources();
    var3 = *(SafeAllocator**)((char*)arg0 + 0x38);
    if (var3 == NULL) {
        var3 = (SafeAllocator*)((char*)arg0 + 0x24);
    }
    var2 = BackgroundLoader::GetInstance();

    if (loader->GetTaskStatus(*(int*)((char*)self + 0xec)) != 0) {
        pool = (char*)base + PoolOffset;
        if (*(unsigned char*)((char*)self + 0x1d) != 0) {
            CopyInternalFields0207df50((struct Foo0207df50*)(pool + 0xc40));
            VramState_Restore(pool + 0xc40);

            var2->GetLoadedFileByID(*(int*)((char*)arg0 + 0xec), &var4, &var5);
            if (var4 != NULL && var3->GetSignedAllocator() != NULL) {
                Object3D* var7 = (Object3D*)((char*)arg0 + 0x3c);
                var7->Initialize();
                var6.fileData = var4;
                var6.unk_8 = var5;
                var6.allocator = var3;
                var6.unk_10 = 1;
                var7->LoadFromCHRArchive(&var6);
                void* var8 = *(void**)((char*)arg0 + 0x44);
                NSBXX_Model_SetPolygonID(*(void**)((char*)var8 + 0x54), 0x3d);
                func_020407b4((struct Struct_02040774_2*)var7, 0, -0xa000, 0x1000);
                var7->MaybeSetBCFGAnimation(0, 0);
            }
            VramState_Save(pool + 0xc40);
        }
        var2->RemoveTask(*(int*)((char*)arg0 + 0xec));
        *(int*)((char*)arg0 + 0xec) = -1;
        return 1;
    }
    return 0;
}
