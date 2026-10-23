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
void CopyInternalFields0207df50(Foo0207df50*);
void VramState_Restore(char*);
void VramState_Save(char*);
struct Struct_203dafc;
void ClearEightWords_0203dafc(Struct_203dafc*);
struct Struct020A2CF0;
struct S020a3568;
Struct020A2CF0* GetFieldIfFlag2_020100cc(char*);
void ResetState020a2cf0(Struct020A2CF0*);
void SetField0x218(S020a3568*, int);
ModelRenderContext* GetModel3DContext(Model3D*);
extern "C" void func_ov015_0218bb3c(RenderCommandHandler*);
extern char data_ov015_02194078[];
extern char data_ov015_02194052[];
extern char data_ov015_0219415c[];
extern char data_ov015_02194160[];
extern char data_ov015_02194167[];
extern Vector3i data_ov015_02193d20;
#if defined(jpn)
struct Struct_ov015_02193fe0 { unsigned char unknown_2_; unsigned char unknown_1_; unsigned char unknown_0_; };
#else
struct Struct_ov015_02193fe0 { unsigned char unknown_0_; unsigned char unknown_1_; unsigned char unknown_2_; };
#endif
extern Struct_ov015_02193fe0 data_ov015_02193fe0;
struct Struct_ov015_0218e2a4 { Struct_0203d028* unknown_0_; };
struct Struct_ov015_0218e2a4_2 {
    int unknown_0_;
    Struct_ov015_0218e2a4* unknown_4_;
    SafeAllocator* unknown_8_;
    int unknown_c_;
    char unknown_10_[0xc];
    unsigned char unknown_1c_;
    char unknown_1d_[7];
    Object3D* unknown_24_;
    char unknown_28_[0x1c];
    int unknown_44_;
};
struct Struct_ov015_0218e2a4_3 { int unknown_0_; int unknown_4_; };

// USA: func_ov015_0218e2a4
extern "C" ARM int func_ov015_0218e2a4(BattleModelLoader* self, ModelDescription* description) {
    if (!description->archive) return 0;
    char path[0x20];
    __clear(path, 0x20);
    self->allocator->Reset();
    int loaded = 1;
    Foo0207df50* palette = self->manager->palette;
    CopyInternalFields0207df50(palette);
    VramState_Restore((char*)palette);
    if (self->mode == 5) sprintf(path, data_ov015_02194078, description->archive);
    else sprintf(path, data_ov015_02194052, description->archive);
    BackgroundLoader::AddLockGlobal();
    unsigned int var3 = 0;
    if (!LoadFileIntoMemory(var0, data_0211e33c, &var3)) var1 = 0;
    else {
        ObjectArchiveLoadInfo var4;
        func_0203dafc((Struct_0203d028_11*)&var4);
        SafeAllocator* var5 = arg0->unknown_8_;
        unsigned int var6 = var3;
        const void* var7 = data_0211e33c;
        int var8 = 1;
        var4.allocator = var5;
        var4.fileData = var7;
        var4.unk_8 = var6;
        var4.unk_10 = var8;
        arg0->unknown_24_->LoadFromCHRArchive(&var4);
        Model3D* var9 = arg0->unknown_24_->pModel_;
        data_ov015_02193fe0.unknown_1_ = var9->GetBoneIndex(data_ov015_0219415c);
        data_ov015_02193fe0.unknown_2_ = var9->GetBoneIndex(data_ov015_02194160);
        data_ov015_02193fe0.unknown_0_ = var9->GetBoneIndex(data_ov015_02194167);
        ModelRenderContext* var10 = GetModel3DContext(var9);
        SetModelRenderContextRenderCommandHook(var10, func_ov015_0218bb3c, 0, 6, 3);
        var10->flags_ |= 4;
        Vector3i var11 = data_ov015_02193d20;
        arg0->unknown_24_->SetScale(&var11);
        arg0->unknown_24_->MaybeSetBCFGAnimation(0, arg0->unknown_44_);
    }
    BackgroundLoader::RemoveLockGlobal();
    VramState_Save((char*)palette);
    if (!loaded) return 0;
    GameState* game = GameState::GetInstance();
    if (!game) return 0;
    Struct020A2CF0* camera = GetFieldIfFlag2_020100cc((char*)game);
    if (!camera) return 0;
    ResetState020a2cf0(camera);
    SetField0x218((S020a3568*)camera, 0);
    self->id = description->id;
    return 1;
}
