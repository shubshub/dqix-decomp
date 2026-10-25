#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"


extern "C" void GXx_SetMasterBrightness_(short* out, int value);

extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
struct BackgroundGraphics;
void Background_Init(BackgroundGraphics*);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int, void*, int);
void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
void Background_SetScroll(BackgroundGraphics*, int, int);
void LoadFileIntoMemory(const char*, void*, unsigned int*);
struct PacRecord;
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_LoadFile(void*, void*, void*, int);
void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
void Background_UploadMap(BackgroundGraphics*, void*);

extern char data_ov020_0218dcb3;
extern int g_fileLoadBuffer;

struct ResetContext0218cd98 {
    char pad0[0x470];
    SafeAllocator allocator;
};

// USA: func_ov020_0218cd98  (semantic: ResetAndReloadContext_0218cd98)
extern "C" ARM void func_ov020_0218cd98(struct ResetContext0218cd98* self) {
    unsigned char* base = (unsigned char*)self;

    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    self->allocator.Reset();
    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0, 1, 1, 1, 0);

    Background_Init((BackgroundGraphics*)(base + 0xbc + 0x400));
    Background_SetMapSize((unsigned char*)(base + 0xbc + 0x400), 0);

    unsigned char* obj = base + 0xbc;
    unsigned char* list = obj + 0x400;
    list[0x1c] = (list[0x1c] & ~0xf) | 1;
    int v2 = list[0x1c] & ~0xf0;
    list[0x1c] = v2;
    Background_SetPriority(list, 0, obj, v2);

    Background_AllocateMap((BackgroundGraphics*)(base + 0xbc + 0x400), (SafeAllocator*)&self->allocator);
    Background_AllocateScreens((BackgroundGraphics*)(base + 0xbc + 0x400), 1, (SafeAllocator*)&self->allocator);
    Background_SetScroll((BackgroundGraphics*)(base + 0xbc + 0x400), 0, 0);
    BackgroundLoader::AddLockGlobal();

    unsigned int local1c = 0;
    LoadFileIntoMemory((const char*)&data_ov020_0218dcb3, (void*)&g_fileLoadBuffer, &local1c);
    int count = Pac_CountFiles((PacRecord*)&g_fileLoadBuffer);

    for (int i = 0; i < count; i++) {
        int recSize;
        void* recField;
        void* rec = Pac_GetFile((PacRecord*)&g_fileLoadBuffer, i, &recField, &recSize);
        if (rec != 0) {
            Background_LoadFile(base + 0xbc + 0x400, rec, &self->allocator, recSize);
        }
    }

    Background_DrawScreen((BackgroundGraphics*)(base + 0xbc + 0x400), 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    Background_UploadMap((BackgroundGraphics*)(base + 0xbc + 0x400), (void*)0);
    BackgroundLoader::RemoveLockGlobal();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x1300;
    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg1000 = (*reg1000 & ~0x1f00) | 0x100;

    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
}
