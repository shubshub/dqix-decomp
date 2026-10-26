#include <globaldefs.h>
#include <Filesystem/FileIO.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/GameResources.h>
#include <World/Object3D.h>


struct Struct_ov000_02166a94_2 { int unknown_0_; char unknown_4_[0x84]; };
struct Struct_ov000_02166a94_3 {
    char unknown_0_[4];
    SafeAllocator* unknown_4_;
#if defined(jpn)
    char unknown_8_[0xe20 - 8];
    void* unknown_ea4_;
    char unknown_e24_[0x57f0 - 0xe24];
    Struct_ov000_02166a94_2 unknown_5600_[2];
    char unknown_5900_[0x5ca0 - 0x5900];
    Object3D unknown_5ab0_[2];
    char unknown_5df8_[0x71ec - 0x5df8];
#else
    char unknown1_8_[0xea4 - 8];
    void* unknown_ea4_;
    char unknown_ea8_[0x5600 - 0xea8];
    Struct_ov000_02166a94_2 unknown_5600_[2];
    char unknown_5710_[0x5ab0 - 0x5710];
    Object3D unknown_5ab0_[2];
    char unknown_5c08_[0x6ffc - 0x5c08];
#endif
    char unknown_6ffc_[4];
};
struct Struct_ov000_02166a94_4 {
    char unknown_0_[0x230];
    char unknown_230_[4];
};
struct NodeList02057de0;
struct Struct_203dafc { int words[8]; };
union BattleModelLoadInfo02166a94 { Struct_203dafc words; ObjectArchiveLoadInfo archive; };
struct Container020d6d18;
struct Obj020d6d90;
struct MergeLowNibbleField020d76fc;
struct Container020d6f44;
extern "C" NodeList02057de0* func_02057924();
extern "C" void HaltSystem();
void VramState_Restore(char*);
void VramState_Save(char*);
void CreateAndRegisterNode02057de0(NodeList02057de0*, int, SafeAllocator*, int, int);
void ClearEightWords_0203dafc(Struct_203dafc*);
void SprSprite_LoadFile(void*, int, int, int);
void ResetArrayAndEntry02182114(char*);
extern "C" void func_ov000_0218214c(void*, SafeAllocator*, const void*);
char* NumberPopups_GetInstance();
void NumberPopups_Init(void*);
void NumberPopups_LoadSprites(char*, int, const void*);
void ConstructEntryManager020d6d18(Container020d6d18*);
void LoadFilesAndBuildNodeList020d6d90(Obj020d6d90*, const void*, SafeAllocator*, char*);
void MergeLowNibbleField(MergeLowNibbleField020d76fc*);
void OrMaskedField24IntoField26_020d771c(unsigned char*);
void InitEntryManagerAllocator020d6ec8(Container020d6f44*, SafeAllocator*);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void*, int);
extern const char data_ov000_02183a5a[], data_ov000_02183a6f[], data_ov000_02183a7a[], data_ov000_02183a85[], data_ov000_02183a93[];
extern const char data_ov000_02183910[][16];
struct Struct_ov000_02183028 {
    int unknown_0_[3];
    int inline_ov000_02166a94(int arg0) const { return unknown_0_[arg0]; }
};
extern int data_ov000_021838fc[];
extern Struct_ov000_02183028 data_ov000_02183028;

// USA: func_ov000_02166a94
extern "C" ARM void func_ov000_02166a94(BattleWork02166a94* self) {
    SafeAllocator* sourceAllocator;
    BattlePairTables02166a94* pairTables;
    NodeList02057de0* nodes;
    SafeAllocator* destinationAllocator;
    GameResources* resources = GetGameResources();
    nodes = func_02057924();
    sourceAllocator = &resources->allocator_array_38[0];
    destinationAllocator = &resources->allocator_array_38[5];
    pairTables = (BattlePairTables02166a94*)resources->vramStates_;
    unsigned int size;
    const void* data;
    BackgroundLoader::AddLockGlobal();
    if (!LoadFileIntoMemory(data_ov000_02183a5a, g_fileLoadBuffer, &size)) HaltSystem();
    VramState_Restore(pairTables->tables);
    if (GetFileInNarc(g_fileLoadBuffer, data_ov000_02183a6f, &data, &size, 0)) {
        void* buffer = sourceAllocator->Allocate(size);
        if (buffer) {
            memcpy(buffer, data, size);
            CreateAndRegisterNode02057de0(nodes, 2, sourceAllocator, (int)buffer, size);
        }
    }
    SafeAllocator* sourceAllocators[4] = {sourceAllocator, self->allocator, self->allocator, self->allocator};
    SafeAllocator* destinationAllocators[4] = {destinationAllocator, destinationAllocator, self->allocator, self->allocator};
    long resourceIndex;
    SafeAllocator** sourceSlot;
    SafeAllocator** destinationSlot;
    resourceIndex = 0;
    sourceSlot = sourceAllocators;
    destinationSlot = destinationAllocators;
    for (; data_ov000_021838fc[resourceIndex] >= 0; ++resourceIndex, ++sourceSlot, ++destinationSlot) {
        if (GetFileInNarc(g_fileLoadBuffer, data_ov000_02183910[resourceIndex], &data, &size, 0)) {
            void* buffer = (*sourceSlot)->Allocate(size);
            if (buffer) {
                memcpy(buffer, data, size);
                CreateAndRegisterNode02057de0(nodes, data_ov000_021838fc[resourceIndex], *destinationSlot, (int)buffer, size);
            }
        }
    }
    Object3D* models[3] = {};
    models[0] = &self->models[0];
    models[1] = &self->models[1];
    char path[80];
    BattleModelLoadInfo02166a94 loadInfo;
    Object3D* const* modelSlots;
    BattleModelIDList02166a94* modelIDs;
    long modelIndex;
    Object3D* model;
    for (modelIndex = 0; data_ov000_02183028.entries[modelIndex] > 0; ++modelIndex) {
        modelIDs = &data_ov000_02183028;
        sprintf(path, data_ov000_02183a7a, modelIDs->Get(modelIndex));
        GetFileInNarc(g_fileLoadBuffer, path, &data, &size, 0);
        if (data) {
            modelSlots = models;
            model = modelSlots[modelIndex];
            ClearEightWords_0203dafc(&loadInfo.words);
            const void* modelData;
            int modelSize;
            modelSize = size;
            modelData = data;
            loadInfo.archive.unk_10 = 1;
            loadInfo.archive.fileData = modelData;
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
    ResetArrayAndEntry02182114(battleResources);
    func_ov000_0218214c(battleResources, destinationAllocator, g_fileLoadBuffer);
    char* objectResources = NumberPopups_GetInstance();
    NumberPopups_Init(objectResources);
    NumberPopups_LoadSprites(objectResources, (int)destinationAllocator, g_fileLoadBuffer);
    VramState_Save(pairTables->tables);
    self->entryManager = destinationAllocator->Allocate(0xa48);
    ConstructEntryManager020d6d18((Container020d6d18*)self->entryManager);
    LoadFilesAndBuildNodeList020d6d90((Obj020d6d90*)self->entryManager, g_fileLoadBuffer, destinationAllocator, pairTables->tables);
    MergeLowNibbleField((MergeLowNibbleField020d76fc*)self->entryManager);
    OrMaskedField24IntoField26_020d771c((unsigned char*)self->entryManager);
    InitEntryManagerAllocator020d6ec8((Container020d6f44*)self->entryManager, self->allocator);
    VramState_Restore(pairTables->tables);
    VramState_Save(pairTables->tables);
    SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x40);
    BackgroundLoader::RemoveLockGlobal();
}
