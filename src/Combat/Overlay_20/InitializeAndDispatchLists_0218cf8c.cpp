#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"


extern "C" void GXx_SetMasterBrightness_(short* out, int value);

extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
struct BackgroundGraphics;
void Background_Init(BackgroundGraphics*);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
struct PacRecord;
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_LoadFile(void*, void*, void*, int);
void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
void Background_UploadMap(BackgroundGraphics*, void*);

extern char data_ov020_0218dcca;

struct Triple3 { unsigned int a, b, c; };
extern Triple3 data_ov020_0218d950;
extern Triple3 data_ov020_0218d944;

struct SetupContext0218cf8c {
#if defined(jpn)
    char pad0[0x400];
#else
    char pad0[0x470];
#endif

    SafeAllocator allocator;
};

// USA: func_ov020_0218cf8c  (semantic: InitializeAndDispatchLists_0218cf8c)
extern "C" ARM void func_ov020_0218cf8c(struct SetupContext0218cf8c* self) {
#if defined(jpn)
 enum {regionalOffset0=0x2c, regionalOffset1=0x448, regionalOffset2=0x468, regionalOffset3=0x4c};
#else
 enum {regionalOffset0=0x9c, regionalOffset1=0x4b8, regionalOffset2=0x4d8, regionalOffset3=0xbc};
#endif
    unsigned char* base = (unsigned char*)self;

    self->allocator.Reset();
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 0, 0x1f, 2, 0);

    Background_Init((BackgroundGraphics*)(base + regionalOffset0 + 0x400));
    Background_SetMapSize((unsigned char*)(base + regionalOffset0 + 0x400), 0);
    base[regionalOffset1] = base[regionalOffset1] & ~0xf;
    base[regionalOffset1] = (base[regionalOffset1] & ~0xf0) | 0x10;
    Background_SetPriority(base + regionalOffset0 + 0x400, 0);
    Background_AllocateMap((BackgroundGraphics*)(base + regionalOffset0 + 0x400), (SafeAllocator*)&self->allocator);
    Background_AllocateScreens((BackgroundGraphics*)(base + regionalOffset0 + 0x400), 1, (SafeAllocator*)&self->allocator);
    Background_SetScroll((BackgroundGraphics*)(base + regionalOffset0 + 0x400), 0, 0);

    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0, 0, 1, 1, 0);

    Background_Init((BackgroundGraphics*)(base + regionalOffset3 + 0x400));
    Background_SetMapSize((unsigned char*)(base + regionalOffset3 + 0x400), 0);
    base[regionalOffset2] = (base[regionalOffset2] & ~0xf) | 1;
    base[regionalOffset2] = base[regionalOffset2] & ~0xf0;
    Background_SetPriority(base + regionalOffset3 + 0x400, 0);
    Background_AllocateMap((BackgroundGraphics*)(base + regionalOffset3 + 0x400), (SafeAllocator*)&self->allocator);
    Background_AllocateScreens((BackgroundGraphics*)(base + regionalOffset3 + 0x400), 1, (SafeAllocator*)&self->allocator);
    Background_SetScroll((BackgroundGraphics*)(base + regionalOffset3 + 0x400), 0, 0);

    int taskId;
    void* loader = BackgroundLoader::GetInstance();
    ((BackgroundLoader*)loader)->MaybeReset();
    taskId = ((BackgroundLoader*)loader)->QueueLoadFile(&data_ov020_0218dcca, (SafeAllocator*)0);

  retryLoop:
    if (((BackgroundLoader*)loader)->GetTaskStatus(taskId) == 0) goto waitForLoad;

    void* recFieldScratch;
    void* fileData;
    unsigned int fileLen;
    ((BackgroundLoader*)loader)->GetLoadedFileByID(taskId, &fileData, &fileLen);
    int count = Pac_CountFiles((PacRecord*)fileData);

    void* resultsArray[6];
    int recSizeArray[6];
    for (int idx = 0; idx < count; idx++) {
        resultsArray[idx] = Pac_GetFile((PacRecord*)fileData, idx, &recFieldScratch, &recSizeArray[idx]);
    }

    Triple3 table1 = data_ov020_0218d950;
    Triple3 table2 = data_ov020_0218d944;

    int matchCount1 = 0;
    int matchCount2 = 0;

    for (int idx2 = 0; idx2 < count; idx2++) {
        if (idx2 == (&table1.a)[matchCount1]) {
            Background_LoadFile(base + regionalOffset0 + 0x400, resultsArray[idx2], &self->allocator, recSizeArray[idx2]);
            matchCount1++;
        }
        if (idx2 == (&table2.a)[matchCount2]) {
            Background_LoadFile(base + regionalOffset3 + 0x400, resultsArray[idx2], &self->allocator, recSizeArray[idx2]);
            matchCount2++;
        }
    }

    ((BackgroundLoader*)loader)->RemoveTask(taskId);

    Background_DrawScreen((BackgroundGraphics*)(base + regionalOffset0 + 0x400), 0, 0, 0, 0, 0, 0x20, 0x19, 0);
    Background_DrawScreen((BackgroundGraphics*)(base + regionalOffset3 + 0x400), 0, 0, 0, 0, 0, 0x20, 0x19, 0);
    Background_UploadMap((BackgroundGraphics*)(base + regionalOffset0 + 0x400), (void*)0);
    Background_UploadMap((BackgroundGraphics*)(base + regionalOffset3 + 0x400), (void*)0);
    goto afterLoop;
  waitForLoad:
    ((BackgroundLoader*)loader)->RemoveAllLocks();
    goto retryLoop;
  afterLoop:

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x200;
    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg1000 = (*reg1000 & ~0x1f00) | 0x100;

    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
}
