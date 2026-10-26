#include <globaldefs.h>
#include <Filesystem/FileIO.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/GameResources.h>
#include <World/Object3D.h>


struct Struct_ov000_02166a94_2 { int state; char unknown_4_[0x84]; };
struct Struct_ov000_02166a94_3 {
    char unknown_0_[4];
    SafeAllocator* allocator;
#if defined(jpn)
    char unknown_8_[0xe20 - 8];
    void* entryManager;
    char unknown_e24_[0x57f0 - 0xe24];
    Struct_ov000_02166a94_2 effects[2];
    char unknown_5900_[0x5ca0 - 0x5900];
    Object3D models[2];
    char unknown_5df8_[0x71ec - 0x5df8];
#else
    char unknown1_8_[0xea4 - 8];
    void* entryManager;
    char unknown_ea8_[0x5600 - 0xea8];
    Struct_ov000_02166a94_2 effects[2];
    char unknown_5710_[0x5ab0 - 0x5710];
    Object3D models[2];
    char unknown_5c08_[0x6ffc - 0x5c08];
#endif
    char battleResources[4];
};
struct BattlePairTables02166a94 {
    char unknown_0_[0x230];
    char tables[4];
};
struct Struct_02057de0_2;
struct Struct_203dafc { int words[8]; };
union Struct_ov000_02166a94 { Struct_203dafc words; ObjectArchiveLoadInfo archive; };
struct Struct_020d6d18_2;
struct Obj020d6d90;
struct Struct_020d76fc;
struct Struct_020d6ec8;
extern "C" Struct_02057de0_2* func_02057924();
extern "C" void HaltSystem();
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
extern "C" void func_02057de0(Struct_02057de0_2*, int, SafeAllocator*, int, int);
extern "C" void func_0203dafc(Struct_203dafc*);
extern "C" void SprSprite_LoadFile(void*, int, int, int);
extern "C" void func_ov000_02182114(char*);
extern "C" void func_ov000_0218214c(void*, SafeAllocator*, const void*);
extern "C" char* NumberPopups_GetInstance();
extern "C" void NumberPopups_Init(void*);
extern "C" void NumberPopups_LoadSprites(char*, int, const void*);
extern "C" void func_020d6d18(Struct_020d6d18_2*);
extern "C" void func_020d6d90(Obj020d6d90*, const void*, SafeAllocator*, char*);
extern "C" void func_020d76fc(Struct_020d76fc*);
extern "C" void func_020d771c(unsigned char*);
extern "C" void func_020d6ec8(Struct_020d6ec8*, SafeAllocator*);
extern "C" void func_ov000_02160fa8(void*, int);
extern const char data_ov000_02183a5a[], data_ov000_02183a6f[], data_ov000_02183a7a[], data_ov000_02183a85[], data_ov000_02183a93[];
extern const char data_ov000_02183910[][16];
struct Struct_ov000_02183028 {
    int entries[3];
    int Get(int i) const { return entries[i]; }
};
extern int data_ov000_021838fc[];
extern Struct_ov000_02183028 data_ov000_02183028;

// USA: func_ov000_02166a94
extern "C" ARM void func_ov000_02166a94(Struct_ov000_02166a94_3* self) {
    SafeAllocator* var0;
    BattlePairTables02166a94* pairTables;
    Struct_02057de0_2* nodes;
    SafeAllocator* destinationAllocator;
    GameResources* resources = GetGameResources();
    nodes = func_02057924();
    var0 = &resources->allocator_array_38[0];
    destinationAllocator = &resources->allocator_array_38[5];
    pairTables = (BattlePairTables02166a94*)resources->vramStates_;
    unsigned int size;
    const void* data;
    BackgroundLoader::AddLockGlobal();
    if (!LoadFileIntoMemory(data_ov000_02183a5a, g_fileLoadBuffer, &size)) HaltSystem();
    VramState_Restore(pairTables->tables);
    if (GetFileInNarc(g_fileLoadBuffer, data_ov000_02183a6f, &data, &size, 0)) {
        void* buffer = var0->Allocate(size);
        if (buffer) {
            memcpy(buffer, data, size);
            func_02057de0(nodes, 2, var0, (int)buffer, size);
        }
    }
    SafeAllocator* var8[4] = {var0, self->allocator, self->allocator, self->allocator};
    SafeAllocator* var9[4] = {destinationAllocator, destinationAllocator, self->allocator, self->allocator};
    long resourceIndex;
    SafeAllocator** sourceSlot;
    SafeAllocator** var12;
    resourceIndex = 0;
    sourceSlot = var8;
    var12 = var9;
    for (; data_ov000_021838fc[resourceIndex] >= 0; ++resourceIndex, ++sourceSlot, ++var12) {
        if (GetFileInNarc(g_fileLoadBuffer, data_ov000_02183910[resourceIndex], &data, &size, 0)) {
            void* buffer = (*sourceSlot)->Allocate(size);
            if (buffer) {
                memcpy(buffer, data, size);
                func_02057de0(nodes, data_ov000_021838fc[resourceIndex], *var12, (int)buffer, size);
            }
        }
    }
    Object3D* models[3] = {};
    models[0] = &self->models[0];
    models[1] = &self->models[1];
    char path[80];
    Struct_ov000_02166a94 loadInfo;
    Object3D* const* var17;
    Struct_ov000_02183028* var18;
    long modelIndex;
    Object3D* model;
    for (modelIndex = 0; data_ov000_02183028.entries[modelIndex] > 0; ++modelIndex) {
        var18 = &data_ov000_02183028;
        sprintf(path, data_ov000_02183a7a, var18->Get(modelIndex));
        GetFileInNarc(g_fileLoadBuffer, path, &data, &size, 0);
        if (data) {
            var17 = models;
            model = var17[modelIndex];
            func_0203dafc(&loadInfo.words);
            const void* var21;
            int modelSize;
            modelSize = size;
            var21 = data;
            loadInfo.archive.unk_10 = 1;
            loadInfo.archive.fileData = var21;
            loadInfo.archive.allocator = destinationAllocator;
            loadInfo.archive.fileSize = modelSize;
            model->Initialize();
            model->LoadFromCHRArchive(&loadInfo.archive);
            model->SetScale(0x10a, 0x10a, 0x10a);
        }
    }
    if (GetFileInNarc(g_fileLoadBuffer, data_ov000_02183a85, &data, &size, 0)) {
        SprSprite_LoadFile(&self->effects[0], (int)data, size, (int)destinationAllocator);
        self->effects[0].state = 0x3e;
    }
    if (GetFileInNarc(g_fileLoadBuffer, data_ov000_02183a93, &data, &size, 0)) {
        SprSprite_LoadFile(&self->effects[1], (int)data, size, (int)destinationAllocator);
        self->effects[1].state = 0x3e;
    }
    char* battleResources = self->battleResources;
    func_ov000_02182114(battleResources);
    func_ov000_0218214c(battleResources, destinationAllocator, g_fileLoadBuffer);
    char* objectResources = NumberPopups_GetInstance();
    NumberPopups_Init(objectResources);
    NumberPopups_LoadSprites(objectResources, (int)destinationAllocator, g_fileLoadBuffer);
    VramState_Save(pairTables->tables);
    self->entryManager = destinationAllocator->Allocate(0xa48);
    func_020d6d18((Struct_020d6d18_2*)self->entryManager);
    func_020d6d90((Obj020d6d90*)self->entryManager, g_fileLoadBuffer, destinationAllocator, pairTables->tables);
    func_020d76fc((Struct_020d76fc*)self->entryManager);
    func_020d771c((unsigned char*)self->entryManager);
    func_020d6ec8((Struct_020d6ec8*)self->entryManager, self->allocator);
    VramState_Restore(pairTables->tables);
    VramState_Save(pairTables->tables);
    func_ov000_02160fa8(self, 0x40);
    BackgroundLoader::RemoveLockGlobal();
}
