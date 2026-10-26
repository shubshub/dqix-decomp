#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#include "Resource/GameResources.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/Brightness.h"

extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void* OamManager_GetInstance(void);
void* BgVram_GetInstance(void);
extern "C" void MapDisplay_FadeOutSubScreen(void* obj, int amount);

void BgVram_Reset(char* obj);
void OamManager_ResetTextTable(char* obj);
void OamManager_Init(char* obj);
void BgVram_FillMap(void* objPtr, int mode, int idx, int fillByte);
extern "C" void BgTransfers_UploadDirtyScreens(void* obj);
struct Struct0205a198;
void Sprite_Init(struct Struct0205a198* p);
void SpriteContext_Init(char* obj);

void* CachedTextTable_GetInstance();
extern "C" void* OamManager_GetSubOamBuffer(void);
struct PacRecord;
int SpriteContext_LoadArchive(void* a, struct PacRecord* b, int flag, void* d);
void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d);
int ValidateResourceLookup0205a1f0(void* a, void* b, int c);
int MessageSystem_GetInstance(void);
extern "C" void VectorizedInvertedMemcpy(void* dst, void* src, int size);
void OS_WaitVBlankIntr(void);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToSubObjVRAM(int, int, unsigned int);
void MapDisplay_RefreshAllMemberPanels(void* obj);
extern "C" void func_02027974(void* obj, int a, void* b);
#if defined(jpn)
extern "C" void MapDisplay_LoadBackgroundPattern(void* obj, int handle, SafeAllocator* alloc);
#else
extern "C" void MapDisplay_LoadBackgroundPattern(void* obj, int* handle, SafeAllocator* alloc);
#endif
extern "C" void MapDisplay_LoadMapPieces(char* obj, int* handle, SafeAllocator* alloc);
struct BackgroundGraphics;
void Background_Init(struct BackgroundGraphics* obj);
extern "C" void Background_LoadFile(void* obj, void* data, SafeAllocator* alloc, int size);
extern "C" void MapDisplay_CenterOnLeader(void* obj);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void MapDisplay_Draw(void* obj);
void MapDisplay_RecheckAllMembers(unsigned char* obj);
extern "C" void MapDisplay_PlaceMembers(void* obj, int flag);
int MapDisplay_QueueMapScript(void* obj);
int ZoneId_IsGrottoBossFloor(int x);
int ZoneId_IsMainGrottoFloor(int id);
void MapDisplay_SetMapKey(char* a, char* b);

extern "C" void __clear(void* arg0, unsigned int arg1);
extern int data_020ef460;
extern char data_020ef5fa[];
extern char data_020ef613[];
extern char data_020ef622[];
extern char data_020ef632[];
extern char data_020ef642[];
extern char data_020ef649[];
extern char data_020ef5b9[];
extern char data_020ef654[];
extern char data_020ef65d[];
extern char data_020ef668[];
extern char data_020ef671[];

struct Struct_02021f88_2 {
    char unknown_0_[0x10];
    unsigned int unknown_10_;
    void* unknown_14_;
};

struct Struct_02021f88 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    short* unknown_4_;
    int unknown_8_;
    int unknown_c_;
    struct Struct_02021f88* unknown_10_;
};

static inline SafeAllocator* inline_02021f88(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

#if defined(jpn)
enum { Enum_02021f88_172 = 0xac, Enum_02021f88_0_2 = 4, Enum_02021f88_1004 = 0xc,
       Enum_02021f88_8192 = 0x2400, Enum_02021f88_9146 = 0x23da, Enum_02021f88_1288 = 0x608,
       Enum_02021f88_96 = 0x2c, Enum_02021f88_32 = 0x40 };
#else
enum { Enum_02021f88_0 = 0, Enum_02021f88_0_2 = 0, Enum_02021f88_1004 = 0x3ec,
       Enum_02021f88_8192 = 0x2000, Enum_02021f88_9146 = 0x23ba, Enum_02021f88_1288 = 0x508,
       Enum_02021f88_96 = 0x60, Enum_02021f88_32 = 0x20 };
#endif

static inline char* inline_02021f88_2(void* arg0) {
    return (char*)arg0 + Enum_02021f88_1004;
}

static inline char* inline_02021f88_3(char* arg0) {
    return arg0 + Enum_02021f88_8192;
}

// Main, originally func_02021f88 (USA 0x02021f88, EUR 0x02021f98, JPN 0x02021a44)
extern "C" ARM void MapDisplay_LoadGrottoMap(MapDisplay* self) {
    char buf4[InitialPathBufferSize];
    char buf3[0x10];
    char buf2[0x40];
    char buf1[0x40];
    void* fileData;
    unsigned int fileLength;
    Res02021f88* res;
    void* fileDataA;
    void* fileDataB;
    unsigned int fileLengthA;
    unsigned int fileLengthB;

    BackgroundLoader* var11;
    unsigned short* var12;
    GameResources* var13;
    char* var14;
    char* var15;
    int var16;
    SafeAllocator* var17;

    GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    p6 = Zone3D_GetInstance();
    axis = GetGameResources();
    battleCtx = (char*)OamManager_GetInstance();
    table = (char*)BgVram_GetInstance();
    state = self->loadStage;
    alloc = GetAlloc02021f88(axis, 12);

    if (state == 0) {
        MapDisplay_FadeOutSubScreen(self, 0x19);
        loader->AddFence();
        self->taska10 = loader->QueueLoadFile(data_020ef5fa, (SafeAllocator*)0);
        int v = *(signed char*)((char*)p6 + ZoneValueOffset);
#if !defined(jpn)
        __clear(var0, 0x20);
#endif
        if (ZoneId_IsGrottoBossFloor(*p6)) {
            strcpy(buf4, data_020ef613);
        } else {
            sprintf(var0, data_020ef622, var18);
        }
#if defined(jpn)
        arg0->unknown_a14_ = var11->QueueLoadFile(var0, (SafeAllocator*)0);
#else
        arg0->unknown_a14_ = var11->QueueLoadFileInGP2(data_020ef632, var0, (SafeAllocator*)0);
#endif
        if (ZoneId_IsGrottoBossFloor(*p6)) {
            self->namesTask = MapDisplay_QueueMapScript(self);
        } else if (ZoneId_IsMainGrottoFloor(*p6)) {
#if !defined(jpn)
            __clear(var1, 0x10);
#endif
            sprintf(buf3, data_020ef642, *p6);
            MapDisplay_SetMapKey((char*)self, buf3);
        }
        self->loadStage = self->loadStage + 1;
    } else if (state == 1) {
        if (loader->GetTaskStatus(self->taska10) == 0) return;
        if (loader->GetTaskStatus(self->taska14) == 0) return;
        MapDisplay_FadeOutSubScreen(self, 0x19);
        if (IsScreenNotFullyFaded((GameResources*)axis, true) != 0) return;
        MapDisplay_ResetMap(self);
        self->displayMode = 0;
        MapDisplay_SetUpLocalMapScreen(self);
        BgVram_Reset(table);
        alloc->Reset();
        OamManager_ResetTextTable(battleCtx);
        OamManager_Init(battleCtx);
        BgVram_FillMap(table, 1, 0, 0);
        BgVram_FillMap(table, 1, 1, 0);
        BgTransfers_UploadDirtyScreens(table);
        for (int i = 0; i < 0x1c; i++) {
            Sprite_Init(&self->records[i]);
        }
        SpriteContext_Init((char*)&self->entryList);
        self->entryList.active = 1;
        self->entryList.records = self->records;
        self->entryList.count = 0x1b;
        char* g = (char*)CachedTextTable_GetInstance();
        *(int*)(g + GlobalBufferOffset) = 0x2000;
        OamManager_GetInstance();
        char* p = (char*)OamManager_GetSubOamBuffer() + 0x2c0;
        g = (char*)CachedTextTable_GetInstance();
        *(char**)g = p;
        if (ZoneId_IsGrottoBossFloor(*p6)) {
            if (loader->GetTaskStatus(self->namesTask) == 0) return;
        }
        fileData = 0;
        fileLength = 0;
        loader->GetLoadedFileByID(self->taska10, &fileData, &fileLength);
        SpriteContext_LoadArchive((char*)&self->entryList, (struct PacRecord*)fileData, fileLength, alloc);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[9], 1, 1);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[11], 1, 1);
        BackgroundLoader::GetInstance()->RemoveTask(self->taska10);
        self->taska10 = -1;
        loader->GetLoadedFileByID(self->taska14, &fileData, &fileLength);
        res = 0;
        if (ValidateResourceLookup0205a1f0(&res, fileData, fileLength) != 0) return;
        char* vram = (char*)MessageSystem_GetInstance();
        char* dst = *(char**)(vram + VramDataOffset);
        VectorizedInvertedMemcpy(res->f14, dst, res->f10);
        OS_WaitVBlankIntr();
        CleanInvalidateCacheRange(dst, res->f10);
        LoadToSubObjVRAM((int)dst, 0x2c20, res->f10);
        BackgroundLoader::GetInstance()->RemoveTask(self->taska14);
        self->taska14 = -1;
        MapDisplay_RefreshAllMemberPanels(self);
        self->nameCount = 0;
        self->forwardingCount = 0;
        if (ZoneId_IsMainGrottoFloor(*p6)) {
            strcpy(self->name, data_020ef649);
            self->scale = 0x2000;
            self->mapState = alloc->Allocate(0x800);
            func_02027974(self, (int)((ActiveGrottoClass*)Off2000_02021f88(Zone02021f88(p6)))->floorMap_.pMapAdjacencyData, self->mapState);
            self->forwardingX = -1;
            self->forwardingY = -1;
            Node02021f88* node = (Node02021f88*)alloc->Allocate(0x14);
            if (node == 0) return;
            node->type = 0;
            node->count = 1;
            node->data = (short*)alloc->Allocate(node->count * 2);
            if (node->data == 0) return;
            for (int i = 0; i < node->count; i++) {
                node->data[i] = *p6;
            }
            Struct_02021f88* var26 = arg0->unknown_754_;
            var24->unknown_1_ = var26 ? var26->unknown_1_ + 1 : 1;
            var24->unknown_10_ = arg0->unknown_754_;
            arg0->unknown_754_ = var24;
        } else {
#if defined(jpn)
            MapDisplay_RunMapScript(self, self->namesTask, alloc);
#else
            MapDisplay_RunMapScript(self, &self->namesTask, alloc);
#endif
        }
        loader->AddFence();
        sprintf(buf2, data_020ef5b9, self->name);
        self->fileTask928 = loader->QueueLoadFileInGP2(
            *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf2, (SafeAllocator*)0);
        if (ZoneId_IsGrottoBossFloor(*p6)) {
            for (int i = 0; i < self->nameCount; i++) {
                sprintf(buf2, data_020ef5b9,
                        self->names[i].name);
                self->nameTasks[i] = loader->QueueLoadFileInGP2(
                    *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf2, (SafeAllocator*)0);
            }
        }
        self->loadStage = self->loadStage + 1;
    } else if (state == 2) {
        if (loader->GetTaskStatus(self->fileTask928) == 0) return;
        if (ZoneId_IsGrottoBossFloor(*p6)) {
            for (int i = 0; i < self->nameCount; i++) {
                if (loader->GetTaskStatus(self->nameTasks[i]) == 0) return;
            }
        }
#if defined(jpn)
        MapDisplay_LoadBackgroundPattern(self, self->fileTask928, alloc);
#else
        MapDisplay_LoadBackgroundPattern(self, &self->fileTask928, alloc);
#endif
        if (ZoneId_IsMainGrottoFloor(*p6)) {
            self->mapPalette = self->forwardingFill + 1;
            char* zone = Zone02021f88(p6);
            Background_Init(&self->list4c);
            self->list4c.subScreen_ = 1;
            self->list4c.bgNumber_ = 0;
            self->list4c.characterOffset_ = self->mapPalette << 5;
            loader->AddFence();
            ActiveGrottoClass* grotto = (ActiveGrottoClass*)(zone + ZoneLargeOffset);
            if (grotto->GetActiveGrottoEnviron() == 0) {
                sprintf(buf1, data_020ef654);
            } else {
                sprintf(var3, data_020ef65d, var30->GetActiveGrottoEnviron());
            }
            arg0->unknown_a18_ = var11->QueueLoadFileInGP2(
                *(const char**)((char*)&data_020ef460 + 8 - Enum_02021f88_0_2), var3, (SafeAllocator*)0);
            if (var30->GetActiveGrottoEnviron() == 0) {
                sprintf(var3, data_020ef668);
            } else {
                sprintf(var3, data_020ef671, var30->GetActiveGrottoEnviron());
            }
            arg0->unknown_a1c_ = var11->QueueLoadFileInGP2(
                *(const char**)((char*)&data_020ef460 + 8 - Enum_02021f88_0_2), var3, (SafeAllocator*)0);
        } else {
            MapDisplay_LoadMapPieces((char*)self, self->nameTasks, alloc);
        }
        self->loadStage = self->loadStage + 1;
    } else if (state == 3) {
        if (ZoneId_IsMainGrottoFloor(*p6)) {
            if (loader->GetTaskStatus(self->taska18) == 0) return;
            if (loader->GetTaskStatus(self->taska1c) == 0) return;
            fileDataA = 0;
            fileDataB = 0;
            fileLengthA = 0;
            fileLengthB = 0;
            loader->GetLoadedFileByID(self->taska18, &fileDataA, &fileLengthA);
            fileLengthA = (fileLengthA + 3) & ~3;
            loader->GetLoadedFileByID(self->taska1c, &fileDataB, &fileLengthB);
            fileLengthB = (fileLengthB + 3) & ~3;
            Background_LoadFile(&self->list4c, fileDataA, alloc, fileLengthA);
            Background_LoadFile(&self->list4c, fileDataB, alloc, fileLengthB);
            BackgroundLoader::GetInstance()->RemoveTask(self->taska18);
            self->taska18 = -1;
            BackgroundLoader::GetInstance()->RemoveTask(self->taska1c);
            self->taska1c = -1;
        }
        MapDisplay_CenterOnLeader(self);
        func_ov017_02191234(axis);
        self->forwardingPending = 1;
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
