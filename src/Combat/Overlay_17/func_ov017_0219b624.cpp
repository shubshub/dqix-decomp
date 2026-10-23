#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"

struct Struct_0203d028;
struct Struct_02000c9c_8;
#if defined(jpn)
enum { Enum_ov017_0219b624_1276 = 0x4ac };
#define data_ov017_021d656c data_ov017_021d69bc
#define data_ov017_021d751f data_ov017_021d797b
#define data_ov017_021d7544 data_ov017_021d7982
#define data_ov017_021d7555 data_ov017_021d7993
#define data_ov017_021d7567 data_ov017_021d79a5
#else
enum { Enum_ov017_0219b624_1276 = 0x4fc };
#endif
struct Struct_ov017_021d656c { int unknown_0_; const char* unknown_4_; };
extern const Struct_ov017_021d656c data_ov017_021d656c[];
extern int data_0211e33c __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
bool GetFileInNarc(const void*, const char*, const void**, unsigned int*, unsigned int);
extern const char data_ov017_021d7504[], data_ov017_021d7510[], data_ov017_021d751b[];
extern const char data_ov017_021d751f[], data_ov017_021d7526[], data_ov017_021d7530[], data_ov017_021d753a[];
extern const char data_ov017_021d7544[], data_ov017_021d7555[], data_ov017_021d7567[];
void CopyInternalFields0207df50(Foo0207df50*);
void VramState_Restore(char*);
void VramState_Save(char*);
int NormalizeField5_0200fb08(Struct0200fb08*);
void* GetData02109020_0208e9e8();
void InitFourNamedSubStructs_02096604(char*, int);
extern "C" {
Zone3D* func_02012fe4();
void func_02018d28(Zone3D*, SafeAllocator*, void*, unsigned int);
void func_0204719c(void*);
void func_02047b40(Struct_02012fa4*, const void*, SafeAllocator*);
void func_02057924();
void func_0208f36c(void*, Object3D*);
void func_02013d24(Zone3D*);
int sprintf(char*, const char*, ...);
}

// USA: func_ov017_0219b624
extern "C" ARM void func_ov017_0219b624(GameResources* arg0) {
    Struct_02012fa4* var0;
    Zone3D* var1;
    SafeAllocator* var2;
#if !defined(jpn)
    GameState* var3 = GameState::GetInstance();
#endif
    var1 = func_02012fe4();
    BackgroundLoader::GetInstance();
    var2 = &arg0->allocator_array_38[5];
    Struct_0203d028* var4 = reinterpret_cast<Struct_0203d028*>(reinterpret_cast<char*>(arg0) + Enum_ov017_0219b624_1276);
    var2->Reset();
    func_0207df50(var4);
    BackgroundLoader::AddLockGlobal();
    char var5[0x50];
    unsigned int var6;
    sprintf(var5, data_ov017_021d7504, data_ov017_021d7510);
    if (!LoadFileIntoMemory(var5, &data_0211e33c, &var6)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    VramState_Restore((char*)pairs);
    NarcHandle archive;
    if (!archive.Initialize(data_ov017_021d751b, (const unsigned char*)&data_0211e33c)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    func_02018d28(var1, var2, &data_0211e33c, var6);
    char var8[0x50];
    int var9 = 0;
    for (; data_ov017_021d656c[var9].unknown_0_ >= 0; var9++) {
        var0 = arg0->substruct_array_2b90;
        int var10 = data_ov017_021d656c[var9].unknown_0_;
        sprintf(var8, data_ov017_021d751f, data_ov017_021d656c[var9].unknown_4_);
        func_0204719c(&var0[var10]);
        const void* var11 = GetFileFromNARCInMemory(var8);
        if (var11 != 0) func_02047b40(&var0[var10], var11, var2);
    }
#if !defined(jpn)
    sprintf(var8, data_ov017_021d751f, data_ov017_021d7526);
    switch (func_0200fb08((Struct_02000c9c_8*)var3)) {
    case 3: sprintf(var8, data_ov017_021d751f, data_ov017_021d7530); break;
    case 5: sprintf(var8, data_ov017_021d751f, data_ov017_021d753a); break;
    }
    func_0204719c(&arg0->substruct_array_2b90[0]);
    {
        const void* var12 = GetFileFromNARCInMemory(var8);
        if (var12 != 0) func_02047b40(&arg0->substruct_array_2b90[0], var12, var2);
    }
#endif
    const void* var13;
    var13 = GetFileFromNARCInMemory(data_ov017_021d7544);
    if (var13 != 0) {
        func_0204719c(&arg0->unknown_3520);
        func_02047b40(&arg0->unknown_3520, var13, var2);
    }
    var13 = GetFileFromNARCInMemory(data_ov017_021d7555);
    if (var13 != 0) {
        func_0204719c(&(*reinterpret_cast<Struct_02012fa4*>(arg0->unknown_35a8)));
        func_02047b40(&(*reinterpret_cast<Struct_02012fa4*>(arg0->unknown_35a8)), var13, var2);
    }
    var7.Destroy();
    func_02057924();
    unsigned int var14;
    if (GetFileInNarc(&data_0211e33c, data_ov017_021d7567, &var13, &var14, 0)) {
        Object3D* var15 = (Object3D*)var2->Allocate(0xac);
        if (var15 != 0) {
            var15->Initialize();
            ObjectArchiveLoadInfo var16;
            var16.fileData = var13;
            var16.unk_8 = var14;
            var16.allocator = var2;
            var16.unk_10 = 1;
            var15->LoadFromCHRArchive(&var16);
            func_0208f36c(func_0208e9e8(), var15);
        }
    }
    BackgroundLoader::RemoveLockGlobal();
    InitFourNamedSubStructs_02096604(static_cast<char*>(self->unknown_ptr_4328), (int)allocator);
    VramState_Save((char*)pairs);
    globals->lootableTemplates_[0] = &self->substruct_array_2b90[5];
    globals->lootableTemplates_[1] = &self->substruct_array_2b90[6];
    globals->lootableTemplates_[2] = &self->substruct_array_2b90[7];
    globals->lootableTemplates_[3] = &self->substruct_array_2b90[8];
    globals->lootableTemplates_[4] = &self->substruct_array_2b90[9];
    globals->lootableTemplates_[5] = &self->substruct_array_2b90[10];
    func_02013d24(globals);
}
