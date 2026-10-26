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
extern "C" void* BgVram_GetInstance(void);
extern "C" void MapDisplay_FadeOutSubScreen(void* obj, int amount);

extern "C" void BgVram_Reset(char* obj);
extern "C" void OamManager_ResetTextTable(char* obj);
extern "C" void OamManager_Init(char* obj);
extern "C" void BgVram_FillMap(void* objPtr, int mode, int idx, int fillByte);
extern "C" void BgTransfers_UploadDirtyScreens(void* obj);
struct Struct0205a198;
extern "C" void Sprite_Init(struct Struct0205a198* p);
extern "C" void SpriteContext_Init(char* obj);

extern "C" void* CachedTextTable_GetInstance();
extern "C" void* OamManager_GetSubOamBuffer(void);
struct PacRecord;
extern "C" int SpriteContext_LoadArchive(void* a, struct PacRecord* b, int flag, void* d);
extern "C" void func_0205af38(int a, char* obj, int c, int d);
extern "C" int func_0205a1f0(void* a, void* b, int c);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void VectorizedInvertedMemcpy(void* dst, void* src, int size);
extern "C" void OS_WaitVBlankIntr(void);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToSubObjVRAM(int, int, unsigned int);
extern "C" void MapDisplay_RefreshAllMemberPanels(void* obj);
extern "C" void func_02027974(void* obj, int a, void* b);
#if defined(jpn)
extern "C" void MapDisplay_LoadBackgroundPattern(void* obj, int handle, SafeAllocator* alloc);
#else
extern "C" void MapDisplay_LoadBackgroundPattern(void* obj, int* handle, SafeAllocator* alloc);
#endif
extern "C" void MapDisplay_LoadMapPieces(char* obj, int* handle, SafeAllocator* alloc);
struct BackgroundGraphics;
extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void Background_LoadFile(void* obj, void* data, SafeAllocator* alloc, int size);
extern "C" void MapDisplay_CenterOnLeader(void* obj);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void MapDisplay_Draw(void* obj);
extern "C" void MapDisplay_RecheckAllMembers(unsigned char* obj);
extern "C" void MapDisplay_PlaceMembers(void* obj, int flag);
extern "C" int MapDisplay_QueueMapScript(void* obj);
extern "C" int ZoneId_IsGrottoBossFloor(int x);
extern "C" int ZoneId_IsMainGrottoFloor(int id);
extern "C" void MapDisplay_SetMapKey(char* a, char* b);

extern "C" void __clear(void* dst, unsigned int size);
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
    char pad0[0x10];
    unsigned int f10;
    void* f14;
};

struct Node02021f88 {
    unsigned char type;
    unsigned char id;
    unsigned char count;
    unsigned char pad3;
    short* data;
    int x;
    int y;
    struct Node02021f88* next;
};

static inline SafeAllocator* inline_02021f88(GameResources* axis, int i) {
    return &axis->allocator_array_38[i];
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

static inline char* inline_02021f88_2(void* p) {
    return (char*)p + Enum_02021f88_1004;
}

static inline char* inline_02021f88_3(char* p) {
    return p + Enum_02021f88_8192;
}

// Main, originally func_02021f88 (USA 0x02021f88, EUR 0x02021f98, JPN 0x02021a44)
extern "C" ARM void MapDisplay_LoadGrottoMap(MapDisplay* self) {
    char var0[Enum_02021f88_32];
    char buf3[0x10];
    char buf2[0x40];
    char buf1[0x40];
    void* fileData;
    unsigned int fileLength;
    Struct_02021f88_2* res;
    void* fileDataA;
    void* fileDataB;
    unsigned int fileLengthA;
    unsigned int fileLengthB;

    BackgroundLoader* loader;
    unsigned short* p6;
    GameResources* axis;
    char* battleCtx;
    char* table;
    int state;
    SafeAllocator* alloc;

    GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    p6 = Zone3D_GetInstance();
    axis = GetGameResources();
    battleCtx = (char*)OamManager_GetInstance();
    table = (char*)BgVram_GetInstance();
    state = self->loadStage;
    alloc = inline_02021f88(axis, 12);

    if (state == 0) {
        MapDisplay_FadeOutSubScreen(self, 0x19);
        loader->AddFence();
        self->taska10 = loader->QueueLoadFile(data_020ef5fa, (SafeAllocator*)0);
        int v = *(signed char*)((char*)p6 + Enum_02021f88_9146);
#if !defined(jpn)
        __clear(var0, 0x20);
#endif
        if (ZoneId_IsGrottoBossFloor(*p6)) {
            strcpy(var0, data_020ef613);
        } else {
            sprintf(var0, data_020ef622, v);
        }
#if defined(jpn)
        self->taska14 = loader->QueueLoadFile(var0, (SafeAllocator*)0);
#else
        self->taska14 = loader->QueueLoadFileInGP2(data_020ef632, var0, (SafeAllocator*)0);
#endif
        if (ZoneId_IsGrottoBossFloor(*p6)) {
            self->namesTask = MapDisplay_QueueMapScript(self);
        } else if (ZoneId_IsMainGrottoFloor(*p6)) {
#if !defined(jpn)
            __clear(buf3, 0x10);
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
        *(int*)(g + Enum_02021f88_1288) = 0x2000;
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
        func_0205af38((int)((char*)&self->entryList), (char*)&self->records[9], 1, 1);
        func_0205af38((int)((char*)&self->entryList), (char*)&self->records[11], 1, 1);
        BackgroundLoader::GetInstance()->RemoveTask(self->taska10);
        self->taska10 = -1;
        loader->GetLoadedFileByID(self->taska14, &fileData, &fileLength);
        res = 0;
        if (func_0205a1f0(&res, fileData, fileLength) != 0) return;
        char* vram = (char*)MessageSystem_GetInstance();
        char* dst = *(char**)(vram + Enum_02021f88_96);
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
            func_02027974(self, (int)((ActiveGrottoClass*)inline_02021f88_3(inline_02021f88_2(p6)))->floorMap_.pMapAdjacencyData, self->mapState);
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
            Node02021f88* head = self->field754;
            node->id = head ? head->id + 1 : 1;
            node->next = self->field754;
            self->field754 = node;
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
            *(const char**)((char*)&data_020ef460 + 8 - Enum_02021f88_0_2), buf2, (SafeAllocator*)0);
        if (ZoneId_IsGrottoBossFloor(*p6)) {
            for (int i = 0; i < self->nameCount; i++) {
                sprintf(buf2, data_020ef5b9,
                        self->names[i].name);
                self->nameTasks[i] = loader->QueueLoadFileInGP2(
                    *(const char**)((char*)&data_020ef460 + 8 - Enum_02021f88_0_2), buf2, (SafeAllocator*)0);
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
            char* zone = inline_02021f88_2(p6);
            Background_Init(&self->list4c);
            self->list4c.subScreen_ = 1;
            self->list4c.bgNumber_ = 0;
            self->list4c.characterOffset_ = self->mapPalette << 5;
            loader->AddFence();
            ActiveGrottoClass* grotto = (ActiveGrottoClass*)(zone + Enum_02021f88_8192);
            if (grotto->GetActiveGrottoEnviron() == 0) {
                sprintf(buf1, data_020ef654);
            } else {
                sprintf(buf1, data_020ef65d, grotto->GetActiveGrottoEnviron());
            }
            self->taska18 = loader->QueueLoadFileInGP2(
                *(const char**)((char*)&data_020ef460 + 8 - Enum_02021f88_0_2), buf1, (SafeAllocator*)0);
            if (grotto->GetActiveGrottoEnviron() == 0) {
                sprintf(buf1, data_020ef668);
            } else {
                sprintf(buf1, data_020ef671, grotto->GetActiveGrottoEnviron());
            }
            self->taska1c = loader->QueueLoadFileInGP2(
                *(const char**)((char*)&data_020ef460 + 8 - Enum_02021f88_0_2), buf1, (SafeAllocator*)0);
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
