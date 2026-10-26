#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Combat/MapDisplay.h"

// data_02105244: the CachedTextTable (texts rendered to OBJ tiles; OamManager_Init points it at its +0x10)
void* CachedTextTable_GetInstance();
extern "C" void* OamManager_GetInstance(void);
// &data_021056b4, the OAM buffer the CachedTextTable draws into (OamManager_Init sets it as drawingBuffer)
extern "C" void* OamManager_GetSubOamBuffer(void);

struct PacRecord;
int SpriteContext_LoadArchive(void* spriteContext, struct PacRecord* archive, int archiveSize, void* allocator);

void SetBitfieldStoreBytes0205af38(int spriteContext, char* sprite, int c, int d);

// Main, originally func_02020aec (USA 0x02020aec, EUR 0x02020afc, JPN 0x02020710)
extern "C" ARM void MapDisplay_LoadSpriteArchive(MapDisplay* self, MapDisplayTaskHandle archiveTask, SafeAllocator* allocator) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* fileData = 0;
    unsigned int fileLength = 0;
#if defined(jpn)
    loader->GetLoadedFileByID(archiveTask, &fileData, &fileLength);
#else
    loader->GetLoadedFileByID(*archiveTask, &fileData, &fileLength);
#endif

    char* textCache = (char*)CachedTextTable_GetInstance();
    *(int*)(textCache + (IS_JPN ? 0x608 : 0x508)) = 0x2000;
    OamManager_GetInstance();

    char* drawingBuffer = (char*)OamManager_GetSubOamBuffer() + 0x2c0;
    textCache = (char*)CachedTextTable_GetInstance();
    *(char**)textCache = drawingBuffer;

    SpriteContext_LoadArchive(&self->entryList, (PacRecord*)fileData, fileLength, allocator);

    loader = BackgroundLoader::GetInstance();
#if defined(jpn)
    loader->RemoveTask(archiveTask);
#else
    loader->RemoveTask(*archiveTask);
    *archiveTask = -1;
#endif

    SetBitfieldStoreBytes0205af38((int)&self->entryList, (char*)&self->records[9], 1, 1);
    SetBitfieldStoreBytes0205af38((int)&self->entryList, (char*)&self->records[11], 1, 1);
}
