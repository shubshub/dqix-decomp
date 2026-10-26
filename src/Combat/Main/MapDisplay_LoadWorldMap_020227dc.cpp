#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Resource/Brightness.h"

extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" char* OamManager_GetInstance(void);
extern "C" ARM void* BgVram_GetInstance(void);

extern "C" void MapDisplay_FadeOutSubScreen(void* unused0, int amount);
extern "C" void func_020209d0(void* context);
extern "C" void BgVram_Reset(char* obj);
extern "C" void OamManager_ResetTextTable(char* obj);
extern "C" void OamManager_Init(char* obj);

extern "C" int BgTransfers_LoadTiles(int* arr1, int idx, int category, int addr, unsigned int len, unsigned int len2);
extern "C" void BgVram_FillMap(void* objPtr, int mode, int idx, int fillByte);
extern "C" void BgTransfers_UploadDirtyScreens(void* obj);

extern "C" void Sprite_Init(struct Struct0205a198* p);
extern "C" void SpriteContext_Init(char* obj);

extern "C" void MapDisplay_RefreshAllMemberPanels(void* obj);

struct State0xbb1c;
extern "C" void BgImage_Clear(struct State0xbb1c* obj);

struct Obj0203bb3c;
extern "C" void BgImage_Load(struct Obj0203bb3c* obj, char* src, SafeAllocator* allocator, int category, unsigned short arg4);

struct Bcb8Params;
extern "C" void BgImage_Place(struct Bcb8Params* s, int arg1, int arg2);

struct ResetStruct {
    int unknown_0_;
    int w4;
    int w8;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    char pad[0x400];
    unsigned char unknown_42c_;
};

struct StreamHeader;
struct StreamState;

struct Struct_0201f040_3;

extern "C" void MapDisplay_CenterOnLeader(void* obj);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void OS_WaitVBlankIntr(void);
extern "C" void MapDisplay_Draw(void* obj);
extern "C" void MapDisplay_RecheckAllMembers(unsigned char* obj);
extern "C" void MapDisplay_PlaceMembers(void* obj, int flag);

extern char data_020ef67c;
extern int data_020ef460;
extern char data_020ef692;
extern char data_020ef69f;
extern int data_020ef498;
extern char data_020ef6b5;

#if defined(jpn)
enum { Enum_020227dc_172 = 0xac, Enum_020227dc_0_2 = 4 };
#else
enum { Enum_020227dc_0 = 0, Enum_020227dc_0_2 = 0 };
#endif

struct Struct_020fdc4c_7 {
    char pad[0x8 - Enum_020227dc_0_2];
    void* unknown_8_;
    char pad2[0x10 - 0xc];
    void* unknown_10_;
};
extern struct Struct_020fdc4c_7 data_020fdc4c;

// Main, originally func_020227dc (USA 0x020227dc, EUR 0x020227ec, JPN 0x02022274)
extern "C" ARM void MapDisplay_LoadWorldMap(MapDisplay* ctx) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned short* p6 = Zone3D_GetInstance();
    char* axisObj = ((char*)GetGameResources());
    char* p8 = OamManager_GetInstance();
    void* dataPtr = BgVram_GetInstance();
    int i;
    SafeAllocator* sb = (SafeAllocator*)(axisObj + 0x128);

    if (ctx->loadStage == 0) {
        MapDisplay_FadeOutSubScreen(ctx, 0x19);
        loader->AddFence();
        ctx->taska24 = loader->QueueLoadFile(&data_020ef67c, 0);
        ctx->taska20 = loader->QueueLoadFileInGP2((const char*)(*(int*)((char*)&data_020ef460 + 8 - Enum_020227dc_0_2)), &data_020ef692, 0);
        ctx->taska28 = loader->QueueLoadFile(&data_020ef69f, 0);
        ctx->loadStage = ctx->loadStage + 1;
        return;
    }

    if (ctx->loadStage != 1) return;

    if (loader->GetTaskStatus(ctx->taska24) == 0) return;
    if (loader->GetTaskStatus(ctx->taska20) == 0) return;
    if (loader->GetTaskStatus(ctx->taska28) == 0) return;

    MapDisplay_FadeOutSubScreen(ctx, 0x19);
    if (IsScreenNotFullyFaded((GameResources*)axisObj, true) != 0) return;

    MapDisplay_ResetMap(ctx);
    func_020209d0(ctx);
    BgVram_Reset((char*)dataPtr);
    sb->Reset();
    OamManager_ResetTextTable(p8);
    OamManager_Init(p8);

    char buf[0x20];
    memset(buf, 0, 0x20);
    BgTransfers_LoadTiles((int*)dataPtr, 1, 1, (int)buf, 0x20, 1);
    BgVram_FillMap(dataPtr, 1, 0, 0);
    BgVram_FillMap(dataPtr, 1, 1, 0);
    BgTransfers_UploadDirtyScreens(dataPtr);

    for (i = 0; i < 0x1c; i++) {
        Sprite_Init(&ctx->records[i]);
    }

    SpriteContext_Init((char*)&ctx->entryList);
    ctx->entryList.active = 1;
    ctx->entryList.records = ctx->records;
    ctx->entryList.count = 0x1c;
    ctx->displayMode = 1;
#if defined(jpn)
    MapDisplay_LoadSpriteArchive(ctx, ctx->taska24, sb);
#else
    MapDisplay_LoadSpriteArchive(ctx, &ctx->taska24, sb);
#endif

    MapDisplay_RefreshAllMemberPanels(ctx);
    ctx->nameCount = 1;
    ctx->forwardingCount = 1;

    void* fileData = 0;
    unsigned int fileSize = 0;
    loader->GetLoadedFileByID(ctx->taska20, &fileData, &fileSize);

    ctx->names = (Entry02021578*)sb->Allocate(sizeof(Entry02021578));
    BgImage_Clear((struct State0xbb1c*)((char*)ctx->names + 8));

    BgImage_Load((struct Obj0203bb3c*)((char*)ctx->names + 8), (char*)fileData, sb, 1, 0);
    BgImage_Place((struct Bcb8Params*)((char*)ctx->names + 8), 0, 0);

    BackgroundLoader::GetInstance()->RemoveTask(ctx->taska20);
    ctx->taska20 = -1;

    loader->GetLoadedFileByID(ctx->taska28, &fileData, &fileSize);

    struct ResetStruct local;
    data_020fdc4c.unknown_10_ = ctx;
    data_020fdc4c.unknown_8_ = sb;
    ((Script*)&local)->Initialize();
    ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020ef498);
    ((Script*)((struct StreamState*)&local))->Load((struct StreamHeader*)fileData, (int)fileSize);
    ((Script*)((struct Struct_0201f040_3*)&local))->Execute();

    if (*p6 == 10000 || *p6 == 10100) {
        ctx->field12 = 1;
        ctx->refreshRecords = 0;
        ctx->field9ba = 0;
        strcpy(ctx->unknown_2_, &data_020ef6b5);
    }

    BackgroundLoader::GetInstance()->RemoveTask(ctx->taska28);
    ctx->taska28 = -1;

    MapDisplay_CenterOnLeader(ctx);
    func_ov017_02191234(axisObj);
    ctx->forwardingPending = 1;
    ctx->field9c4 = 1;
    ctx->field9c8 = 0;
    ctx->field9c3 = 0;
    ctx->loadStage = ctx->loadStage + 1;
    OS_WaitVBlankIntr();
    MapDisplay_Draw(ctx);
    MapDisplay_RecheckAllMembers((unsigned char*)ctx);
    MapDisplay_PlaceMembers(ctx, 0);
}
