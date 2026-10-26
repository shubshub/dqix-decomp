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
struct ResourceFile0219b624 { int index; const char* name; };
extern const ResourceFile0219b624 data_ov017_021d656c[];
extern int g_fileLoadBuffer __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
bool GetFileInNarc(const void*, const char*, const void**, unsigned int*, unsigned int);
extern const char data_ov017_021d7504[], data_ov017_021d7510[], data_ov017_021d751b[];
extern const char data_ov017_021d751f[], data_ov017_021d7526[], data_ov017_021d7530[], data_ov017_021d753a[];
extern const char data_ov017_021d7544[], data_ov017_021d7555[], data_ov017_021d7567[];
void VramState_Rewind(Foo0207df50*);
void VramState_Restore(char*);
void VramState_Save(char*);
int GameState_GetLanguage(Struct0200fb08*);
void* GetData02109020_0208e9e8();
void InitFourNamedSubStructs_02096604(char*, int);
extern "C" {
Zone3D* Zone3D_GetInstance();
void Zone3D_LoadChestModels(Zone3D*, SafeAllocator*, void*, unsigned int);
void SprSprite_Init(void*);
void SprSprite_Parse(Foo02048004*, const void*, SafeAllocator*);
void func_02057924();
void func_0208f36c(void*, Object3D*);
void Zone3D_SetUpLootableModels(Zone3D*);
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
    globals = Zone3D_GetInstance();
    BackgroundLoader::GetInstance();
    allocator = &self->allocator_array_38[5];
    Foo0207df50* pairs = reinterpret_cast<Foo0207df50*>(reinterpret_cast<char*>(self) + PairTablesOffset);
    allocator->Reset();
    VramState_Rewind(pairs);
    BackgroundLoader::AddLockGlobal();
    char path[0x50];
    unsigned int length;
    sprintf(path, data_ov017_021d7504, data_ov017_021d7510);
    if (!LoadFileIntoMemory(path, &g_fileLoadBuffer, &length)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    VramState_Restore((char*)pairs);
    NarcHandle archive;
    if (!archive.Initialize(data_ov017_021d751b, (const unsigned char*)&g_fileLoadBuffer)) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    Zone3D_LoadChestModels(globals, allocator, &g_fileLoadBuffer, length);
    char name[0x50];
    int i = 0;
    for (; data_ov017_021d656c[i].index >= 0; i++) {
        sprites = self->substruct_array_2b90;
        int index = data_ov017_021d656c[i].index;
        sprintf(name, data_ov017_021d751f, data_ov017_021d656c[i].name);
        SprSprite_Init(&sprites[index]);
        const void* file = GetFileFromNARCInMemory(name);
        if (file != 0) SprSprite_Parse(&sprites[index], file, allocator);
    }
#if !defined(jpn)
    sprintf(name, data_ov017_021d751f, data_ov017_021d7526);
    switch (GameState_GetLanguage((Struct0200fb08*)game)) {
    case 3: sprintf(name, data_ov017_021d751f, data_ov017_021d7530); break;
    case 5: sprintf(name, data_ov017_021d751f, data_ov017_021d753a); break;
    }
    SprSprite_Init(&self->substruct_array_2b90[0]);
    {
        const void* file = GetFileFromNARCInMemory(name);
        if (file != 0) SprSprite_Parse(&self->substruct_array_2b90[0], file, allocator);
    }
#endif
    const void* file;
    file = GetFileFromNARCInMemory(data_ov017_021d7544);
    if (file != 0) {
        SprSprite_Init(&self->unknown_3520);
        SprSprite_Parse(&self->unknown_3520, file, allocator);
    }
    file = GetFileFromNARCInMemory(data_ov017_021d7555);
    if (file != 0) {
        SprSprite_Init(&(*reinterpret_cast<Foo02048004*>(self->unknown_35a8)));
        SprSprite_Parse(&(*reinterpret_cast<Foo02048004*>(self->unknown_35a8)), file, allocator);
    }
    var7.Destroy();
    func_02057924();
    unsigned int size;
    if (GetFileInNarc(&g_fileLoadBuffer, data_ov017_021d7567, &file, &size, 0)) {
        Object3D* object = (Object3D*)allocator->Allocate(0xac);
        if (object != 0) {
            object->Initialize();
            ObjectArchiveLoadInfo info;
            info.fileData = file;
            info.fileSize = size;
            info.allocator = allocator;
            info.unk_10 = 1;
            object->LoadFromCHRArchive(&info);
            func_0208f36c(GetData02109020_0208e9e8(), object);
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
    Zone3D_SetUpLootableModels(globals);
}
