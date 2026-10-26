#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
extern "C" void func_02022da0(void*);
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"
#include "World/Zone3D.h"
#include "Combat/MapDisplay.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Memory.h"

extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void* OamManager_GetInstance(void);
void* BgVram_GetInstance(void);
extern "C" void MapDisplay_FadeOutSubScreen(void* obj, int amount);

extern "C" int Font_GetTextWidth(void* p, int flag);

void BgVram_Reset(char* obj);
void OamManager_ResetTextTable(char* obj);
void OamManager_Init(char* obj);
void BgVram_FillMap(void* objPtr, int mode, int idx, int fillByte);
extern "C" void BgTransfers_UploadDirtyScreens(void* obj);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198* p);
void SpriteContext_Init(char* obj);

int MapDisplay_QueueMapScript(void* obj);
void MapDisplay_ClearRedChests(char* obj);
#if defined(jpn)
extern "C" void MapDisplay_LoadShipPositions(char* obj, int handle);
#else
extern "C" void MapDisplay_LoadShipPositions(char* obj, int* handle);
#endif
#if defined(jpn)
#else
#endif
int MapDisplay_UploadMapName(void* obj, int flag);
void MapDisplay_RefreshAllMemberPanels(void* obj);
#if defined(jpn)
extern "C" void MapDisplay_LoadBackgroundPattern(void* obj, int handle, SafeAllocator* alloc);
#else
extern "C" void MapDisplay_LoadBackgroundPattern(void* obj, int* handle, SafeAllocator* alloc);
#endif
extern "C" void MapDisplay_LoadMapPieces(char* obj, int* handle, SafeAllocator* alloc);
extern "C" void MapDisplay_CenterOnLeader(void* obj);
extern "C" void func_ov017_02191234(void* obj);
void OS_WaitVBlankIntr(void);
extern "C" void MapDisplay_Draw(void* obj);
void MapDisplay_RecheckAllMembers(unsigned char* obj);
extern "C" void MapDisplay_PlaceMembers(void* obj, int flag);

extern const char* data_020ef460[];                 // mapname_<LG>.bin, data/map/mapname.gp2, minimap.gp2, minimapt.gp2 (usa)
extern char data_020ef598;                           // "shipMPos.bin"
extern char data_020ef5a5;                           // "data/ani/obj_mm.pac"
extern Script::OpcodeLookupEntry data_020ef4e8[];    // the map name script's opcodes
extern char data_020ef5b9;                           // "%s.obg"

enum {
    kFadeOutFrames = 25,        // MapDisplay_FadeOutSubScreen's duration
    kSpriteCount = 28,          // MapDisplay::records
    kStageFailed = 100,         // the minimap script did not load
    kMapNameTilesOffset = 0x2c20, // where MapDisplay_UploadMapName puts the map name's tiles in sub OBJ VRAM
};

static inline SafeAllocator* GetResourceAllocator(GameResources* resources, int index) {
    return &resources->allocator_array_38[index];
}

// Main, originally func_02021578 (USA 0x02021578, EUR 0x02021588, JPN 0x0202116c)
extern "C" ARM void MapDisplay_LoadLocalMap(MapDisplay* self) {
    void* fileData;
    unsigned int fileLength;
    char fileName[0x40];
    Script script;

    BackgroundLoader* loader;
    GameResources* resources;
    int spriteIndex;
    int pieceIndex;
    int pendingPiece;
    Zone3D_StructPtr_8* zoneEntry;
    char* textCacheHolder;
    char* bgTransfers;
    SafeAllocator* allocator;
    int stage;

    GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    zoneEntry = Zone3D_GetInstance()->pUnknownStruct_8_;
    resources = GetGameResources();
    textCacheHolder = (char*)OamManager_GetInstance();
    bgTransfers = (char*)BgVram_GetInstance();
    stage = self->loadStage;
    allocator = GetResourceAllocator(resources, 12);

    if (stage == 0) {
        self->failed = 0;
        MapDisplay_FadeOutSubScreen(self, kFadeOutFrames);
#if !defined(jpn)
        loader->AddFence();
        self->scriptTask = loader->QueueLoadFileInGP2(
            data_020ef460[1],
            data_020ef460[0], (SafeAllocator*)0);
#endif
        loader->AddFence();
        self->namesTask = MapDisplay_QueueMapScript(self);
        self->fileTask984 = loader->QueueLoadFileInGP2(
            data_020ef460[REGION_VALUE(1, 2)],
            &data_020ef598, (SafeAllocator*)0);
        self->fileTask920 = loader->QueueLoadFile(&data_020ef5a5, (SafeAllocator*)0);
        self->loadStage = self->loadStage + 1;
#if !defined(jpn)
    } else if (stage == 1) {
        if (loader->GetTaskStatus(self->scriptTask) == 0) return;
        VectorizedMemset(self->scriptName, 0, 0x40);
        data_020fdc4c.nameOverride = 0;
        self->scriptNameWidth = 0;
        self->fieldb3c = 0;
        self->fieldb40 = 0;
        self->fieldb42 = 0;
        loader->GetLoadedFileByID(self->scriptTask, &fileData, &fileLength);
        script.Initialize();
        script.SetOpcodeLookup(data_020ef4e8);
        script.Load(fileData, fileLength);
        script.Execute();
        const char* mapName = data_020fdc4c.nameOverride;
        if (mapName != 0) {
            memcpy(self->scriptName, mapName, strlen(mapName));
            self->scriptNameWidth = Font_GetTextWidth(self->scriptName, 0);
        }
        BackgroundLoader::GetInstance()->RemoveTask(self->scriptTask);
        self->scriptTask = -1;
        self->loadStage = self->loadStage + 1;
#endif
    } else if (stage == REGION_VALUE(1, 2)) {
        MapDisplay_FadeOutSubScreen(self, kFadeOutFrames);
        if (IsScreenNotFullyFaded((GameResources*)resources, true) != 0) return;
        MapDisplay_ResetMap(self);
        MapDisplay_SetUpLocalMapScreen(self);
        BgVram_Reset(bgTransfers);
        allocator->Reset();
        OamManager_ResetTextTable(textCacheHolder);
        OamManager_Init(textCacheHolder);
        BgVram_FillMap(bgTransfers, 1, 0, 0);
        BgVram_FillMap(bgTransfers, 1, 1, 0);
        BgTransfers_UploadDirtyScreens(bgTransfers);
        for (spriteIndex = 0; spriteIndex < kSpriteCount; spriteIndex++) {
            Sprite_Init(&self->records[spriteIndex]);
        }
        SpriteContext_Init((char*)&self->entryList);
        self->entryList.active = 1;
        self->entryList.records = self->records;
        self->entryList.count = kSpriteCount;
        int mapType = zoneEntry->unknown_c_low_;
        if (mapType == 0) {
            self->displayMode = 3;
        } else if (mapType == 7) {
            self->displayMode = 1;
        } else {
            self->displayMode = 0;
        }
        self->loadStage = self->loadStage + 1;
#if defined(jpn)
    }
    if (self->loadStage == 2) {
#else
    } else if (stage == 3) {
#endif
        int status = loader->GetTaskStatus(self->namesTask);
        if (status == 0) return;
        self->nameCount = 0;
        self->forwardingCount = 0;
        if (status == -1) {
            self->loadStage = kStageFailed;
            BackgroundLoader::GetInstance()->RemoveTask(self->namesTask);
            self->namesTask = -1;
            BackgroundLoader::GetInstance()->RemoveTask(self->fileTask984);
            self->fileTask984 = -1;
            BackgroundLoader::GetInstance()->RemoveTask(self->fileTask920);
            self->fileTask920 = -1;
            self->failed = 1;
            return;
        }
#if defined(jpn)
        MapDisplay_RunMapScript(self, self->namesTask, allocator);
#else
        MapDisplay_RunMapScript(self, &self->namesTask, allocator);
#endif
        if (self->refreshRecords != 0) {
            self->field9b8 = 1;
            self->field9b9 = 0;
            MapDisplay_ClearRedChests((char*)self);
        }
        loader->AddFence();
        sprintf(fileName, &data_020ef5b9, self->name);
        self->fileTask928 = loader->QueueLoadFileInGP2(
            data_020ef460[REGION_VALUE(1, 2)], fileName, (SafeAllocator*)0);
        for (pieceIndex = 0; pieceIndex < self->nameCount; pieceIndex++) {
            sprintf(fileName, &data_020ef5b9,
                    (self->names)[pieceIndex].name);
            self->nameTasks[pieceIndex] = loader->QueueLoadFileInGP2(
                data_020ef460[REGION_VALUE(1, 2)], fileName, (SafeAllocator*)0);
        }
        self->loadStage = self->loadStage + 1;
    }

    if (self->loadStage == REGION_VALUE(3, 4)) {
        if (loader->GetTaskStatus(self->fileTask984) == 0) return;
#if defined(jpn)
        MapDisplay_LoadShipPositions((char*)self, self->fileTask984);
#else
        MapDisplay_LoadShipPositions((char*)self, &self->fileTask984);
#endif
        self->loadStage = self->loadStage + 1;
    }
    if (self->loadStage == REGION_VALUE(4, 5)) {
        if (loader->GetTaskStatus(self->fileTask920) == 0) return;
#if defined(jpn)
        MapDisplay_LoadSpriteArchive(self, self->fileTask920, allocator);
#else
        MapDisplay_LoadSpriteArchive(self, &self->fileTask920, allocator);
#endif
#if defined(jpn)
        func_02022da0(self);
#else
        char* subObjVram = (char*)0x6600000; // sub-screen OBJ VRAM
        memcpy(self->savedTiles, subObjVram + kMapNameTilesOffset, 0x40);
        MapDisplay_UploadMapName(self, 1);
#endif
        MapDisplay_RefreshAllMemberPanels(self);
        self->loadStage = self->loadStage + 1;
    }
    if (self->loadStage == REGION_VALUE(5, 6)) {
        if (loader->GetTaskStatus(self->fileTask928) == 0) return;
#if defined(jpn)
        MapDisplay_LoadBackgroundPattern((char*)self, self->fileTask928, allocator);
#else
        MapDisplay_LoadBackgroundPattern((char*)self, &self->fileTask928, allocator);
#endif
        self->loadStage = self->loadStage + 1;
    }
    if (self->loadStage == REGION_VALUE(6, 7)) {
        for (pendingPiece = 0; pendingPiece < self->nameCount; pendingPiece++) {
            if (loader->GetTaskStatus(self->nameTasks[pendingPiece]) == 0) return;
        }
        MapDisplay_LoadMapPieces((char*)self, self->nameTasks, allocator);
        MapDisplay_CenterOnLeader(self);
        func_ov017_02191234(resources);
        self->forwardingPending = 1;
        self->field9c4 = 1;
        self->field9c8 = 0;
        self->field9c3 = 0;
        self->loadStage = self->loadStage + 1;
        OS_WaitVBlankIntr();
        MapDisplay_Draw(self);
        MapDisplay_CenterOnLeader(self);
        MapDisplay_RecheckAllMembers((unsigned char*)self);
        MapDisplay_PlaceMembers(self, 0);
    }
}
