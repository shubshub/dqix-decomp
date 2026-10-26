#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
int MessageSystem_GetInstance(void);
extern "C" void func_02023218(MapDisplay* self, void* buffer, int offset, unsigned int capacity);
extern char data_020ef4b1[], data_020ef4c9[], data_020ef4d0[];
#endif
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* OamManager_GetInstance(void);
void* BgVram_GetInstance(void);
extern "C" void MapDisplay_FadeOutSubScreen(void* obj, int amount);

void InitSubScreenDisplay_020209d0(void* context);
void BgVram_Reset(char* obj);
void OamManager_ResetTextTable(char* obj);
void OamManager_Init(char* obj);
void BgVram_FillMap(void* objPtr, int mode, int idx, int fillByte);
extern "C" void BgTransfers_UploadDirtyScreens(void* obj);
void OS_WaitVBlankIntr(void);
#if defined(jpn)
extern "C" void func_02020cb8(void* arg0, int arg1);
extern "C" void func_02020e58(void* arg0, int arg1);
#else
extern "C" void func_02020cb8(void* arg0, int* arg1);
extern "C" void func_02020e58(void* arg0, int* arg1);
#endif
void CopyStringOrDefault02026428(void* obj, const char* name);
void SetEventStringAndAccumulateLength02026470(void* obj, int flag);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198* p);
void SpriteContext_Init(char* obj);
struct PacRecord;
int SpriteContext_LoadArchive(void* a, struct PacRecord* b, int flag, void* d);
void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d);
void* CachedTextTable_GetInstance();
int MapDisplay_UploadTreasureMapName(void* arg0, int flag1);
extern "C" void* OamManager_GetSubOamBuffer(void);
void MapDisplay_RefreshAllMemberPanels(void* obj);
#if defined(jpn)
extern "C" void func_02026898(void* arg0);
#else
extern "C" void func_02026f34(void* arg0);
#endif
extern "C" void func_ov017_02191234(void* obj);
extern "C" void MapDisplay_Draw(void* obj);
void MapDisplay_RecheckAllMembers(unsigned char* obj);
extern "C" void MapDisplay_PlaceMembers(void* obj, int flag);
int MapDisplay_QueueMapScript(void* obj);

extern char data_020ef5c0[];
extern char data_020ef5d8[];
extern int data_020ef460;
extern char data_020ef5df[];

static inline SafeAllocator* inline_02021b84(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// Main, originally func_02021b84 (USA 0x02021b84, EUR 0x02021b94, JPN 0x0202162c)
extern "C" ARM void MapDisplay_LoadTreasureMap(MapDisplay* self) {
    char path[0x18];
    void* fileData;
    unsigned int fileLength;

    GameState* var3;
    BackgroundLoader* var4;
    GameResources* var5;
    char* var6;
    char* var7;
    SafeAllocator* var8;
    GrottoStruct* var9;
    int var10;

    game = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    Zone3D_GetInstance();
    axis = GetGameResources();
    battleCtx = (char*)OamManager_GetInstance();
    table = (char*)BgVram_GetInstance();
    alloc = GetAlloc02021b84(axis, 12);
    grotto = game->GetGrottoStruct();
    state = self->loadStage;

    if (state == 0) {
        MapDisplay_FadeOutSubScreen(self, 0x19);
        loader->AddFence();
        self->task9fc = loader->QueueLoadFile(
#if defined(jpn)
            data_020ef4b1,
#else
            data_020ef5c0,
#endif
            (SafeAllocator*)0);
        sprintf(var0,
#if defined(jpn)
            data_020ef4c9,
#else
            data_020ef5d8,
#endif
            var9->activeMapImageName);
        arg0->unknown_a00_ = var4->QueueLoadFileInGP2(

#if defined(jpn)
            *(const char**)&data_020ef460,
#else
            *(const char**)((char*)&data_020ef460 + 0xc),
#endif
            path, (SafeAllocator*)0);
        strcpy((char*)self->bytesa45, grotto->activeMapImageName);
        self->namesTask = MapDisplay_QueueMapScript(self);
        self->taska04 = loader->QueueLoadFile(
#if defined(jpn)
            data_020ef4d0,
#else
            data_020ef5df,
#endif
            (SafeAllocator*)0);
        self->loadStage = self->loadStage + 1;
    } else if (state == 1) {
        MapDisplay_FadeOutSubScreen(self, 0x19);
        if (IsScreenNotFullyFaded((GameResources*)axis, true) != 0) return;
        if (loader->GetTaskStatus(self->task9fc) == 0) return;
        if (loader->GetTaskStatus(self->taska00) == 0) return;
        MapDisplay_ResetMap(self);
        InitSubScreenDisplay_020209d0(self);
        alloc->Reset();
        BgVram_Reset(table);
        OamManager_ResetTextTable(battleCtx);
        OamManager_Init(battleCtx);
        BgVram_FillMap(table, 1, 0, 0);
        BgVram_FillMap(table, 1, 1, 0);
        BgTransfers_UploadDirtyScreens(table);
        OS_WaitVBlankIntr();
#if defined(jpn)
        func_02020cb8(arg0, arg0->unknown_9fc_);
#else
        func_02020cb8(arg0, &arg0->unknown_9fc_);
#endif
#if defined(jpn)
        func_02020e58(arg0, arg0->unknown_a00_);
#else
        func_02020e58(arg0, &arg0->unknown_a00_);
#endif
        self->loadStage = self->loadStage + 1;
    } else if (state == 2) {
        int status = loader->GetTaskStatus(self->namesTask);
        if (status == 0) return;
        if (status > 0) {
            MapDisplay_RunMapScript(self,
#if defined(jpn)
                arg0->unknown_9d0_,
#else
                &arg0->unknown_9d0_,
#endif
                var8);
        } else {
            BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_9d0_);
            arg0->unknown_9d0_ = -1;
        }
        arg0->unknown_14_ = 1;
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
    } else if (var10 == 3) {
        if (var4->GetTaskStatus(arg0->unknown_a04_) == 0) return;
 #if !defined(jpn)
        arg0->unknown_be4_ = 0;
        arg0->unknown_be8_ = 0;
        arg0->unknown_bec_ = 0;
        arg0->unknown_bee_ = 0;
#endif
        CopyStringOrDefault02026428(self, grotto->activeMapNameNoLevel);
        SetEventStringAndAccumulateLength02026470(self, grotto->activeMapLevel);
        strcpy((char*)self->bytesa55, grotto->activeMapNameNoLevel);
        self->fielda95 = grotto->activeMapLevel;
        fileData = 0;
        fileLength = 0;
        loader->GetLoadedFileByID(self->taska04, &fileData, &fileLength);
        for (int i = 0; i < 0x1c; i++) {
            Sprite_Init(&self->records[i]);
        }
        SpriteContext_Init((char*)&self->entryList);
        self->entryList.active = 1;
        self->entryList.records = self->records;
        self->entryList.count = 0x18;
        SpriteContext_LoadArchive((char*)&self->entryList, (struct PacRecord*)fileData, fileLength, alloc);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[9], 1, 1);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[11], 1, 1);
        *(int*)((char*)CachedTextTable_GetInstance() +
#if defined(jpn)
                0x608
#else
                0x508
#endif
        ) = 0x2000;
#if defined(jpn)
        MessageSystem* messages = (MessageSystem*)MessageSystem_GetInstance();
        char* buffer = messages->formatBuffer;
        char* vram = (char*)0x06600000;
        VectorizedInvertedMemcpy(vram + 0x2bc0, buffer, 0x540);
        func_02023218(self, buffer, 0, 0x540);
        OS_WaitVBlankIntr();
        CleanInvalidateCacheRange(buffer, 0x540);
        LoadToSubObjVRAM(buffer, 0x2bc0, 0x540);
#else
        char* vram = (char*)0x06600000;
        memcpy(self->savedTiles, vram + 0x2c00, 0x40);
        MapDisplay_UploadTreasureMapName(self, 1);
#endif
        OamManager_GetInstance();
        char* p = (char*)OamManager_GetSubOamBuffer() + 0x2e8;
        *(char**)CachedTextTable_GetInstance() = p;
        BackgroundLoader::GetInstance()->RemoveTask(self->taska04);
        self->taska04 = -1;
        MapDisplay_RefreshAllMemberPanels(self);
#if defined(jpn)
        func_02026898(arg0);
#else
        func_02026f34(arg0);
#endif
        func_ov017_02191234(axis);
        self->field9c4 = 1;
        self->field9c8 = 0;
        self->field9c3 = 0;
        self->loadStage = self->loadStage + 1;
        OS_WaitVBlankIntr();
        MapDisplay_Draw(self);
        MapDisplay_RecheckAllMembers((unsigned char*)self);
        MapDisplay_PlaceMembers(self, 0);
    }
}
