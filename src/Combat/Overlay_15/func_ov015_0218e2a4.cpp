#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/NSBXX/Animation.h"

extern "C" void __clear(void*, unsigned long);
struct Foo0207df50;
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
struct Struct_203dafc;
extern "C" void func_0203dafc(Struct_203dafc*);
struct Struct_0204a120_2;
struct Struct_020a3568;
extern "C" Struct_0204a120_2* func_020100cc(char*);
extern "C" void func_020a2cf0(Struct_0204a120_2*);
extern "C" void func_020a3568(Struct_020a3568*, int);
ModelRenderContext* GetModel3DContext(Model3D*);
extern "C" void func_ov015_0218bb3c(RenderCommandHandler*);
extern char data_ov015_02194078[];
extern char data_ov015_02194052[];
extern char data_ov015_0219415c[];
extern char data_ov015_02194160[];
extern char data_ov015_02194167[];
extern Vector3i data_ov015_02193d20;
#if defined(jpn)
struct Struct_ov015_02193fe0 { unsigned char second; unsigned char first; unsigned char third; };
#else
struct Struct_ov015_02193fe0 { unsigned char third; unsigned char first; unsigned char second; };
#endif
extern Struct_ov015_02193fe0 data_ov015_02193fe0;
struct Struct_ov015_0218e2a4 { Foo0207df50* palette; };
struct Struct_ov015_0218e2a4_2 {
    int field0;
    Struct_ov015_0218e2a4* manager;
    SafeAllocator* allocator;
    int id;
    char pad10[0xc];
    unsigned char mode;
    char unknown_1d_[7];
    Object3D* object;
    char pad28[0x1c];
    int animationFlags;
};
struct Struct_ov015_0218e2a4_3 { int id; int archive; };

// USA: func_ov015_0218e2a4
extern "C" ARM int func_ov015_0218e2a4(Struct_ov015_0218e2a4_2* self, Struct_ov015_0218e2a4_3* description) {
    if (!description->archive) return 0;
    char path[0x20];
    __clear(path, 0x20);
    self->allocator->Reset();
    int loaded = 1;
    Foo0207df50* palette = self->manager->palette;
    VramState_Rewind(palette);
    VramState_Restore((char*)palette);
    if (self->mode == 5) sprintf(path, data_ov015_02194078, description->archive);
    else sprintf(path, data_ov015_02194052, description->archive);
    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    if (!LoadFileIntoMemory(path, g_fileLoadBuffer, &length)) loaded = 0;
    else {
        ObjectArchiveLoadInfo info;
        func_0203dafc((Struct_203dafc*)&info);
        SafeAllocator* allocator = self->allocator;
        unsigned int archiveLength = length;
        const void* data = g_fileLoadBuffer;
        int one = 1;
        info.allocator = allocator;
        info.fileData = data;
        info.fileSize = archiveLength;
        info.unk_10 = one;
        self->object->LoadFromCHRArchive(&info);
        Model3D* model = self->object->pModel_;
        data_ov015_02193fe0.first = model->GetBoneIndex(data_ov015_0219415c);
        data_ov015_02193fe0.second = model->GetBoneIndex(data_ov015_02194160);
        data_ov015_02193fe0.third = model->GetBoneIndex(data_ov015_02194167);
        ModelRenderContext* context = GetModel3DContext(model);
        SetModelRenderContextRenderCommandHook(context, func_ov015_0218bb3c, 0, 6, 3);
        context->flags_ |= 4;
        Vector3i scale = data_ov015_02193d20;
        self->object->SetScale(&scale);
        self->object->SetAnimationByIndex(0, self->animationFlags);
    }
    BackgroundLoader::RemoveLockGlobal();
    VramState_Save((char*)palette);
    if (!loaded) return 0;
    GameState* game = GameState::GetInstance();
    if (!game) return 0;
    Struct_0204a120_2* camera = func_020100cc((char*)game);
    if (!camera) return 0;
    func_020a2cf0(camera);
    func_020a3568((Struct_020a3568*)camera, 0);
    self->id = description->id;
    return 1;
}
