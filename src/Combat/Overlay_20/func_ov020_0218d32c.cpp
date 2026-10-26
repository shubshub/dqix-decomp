#pragma opt_vectorize_loops off
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"


extern "C" void GXx_SetMasterBrightness_(short* out, int value);

extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
struct BackgroundGraphics;
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" int DisableSubObjVRAMBanks();
extern "C" int DisableSubBGVRAMBanks();
extern "C" void GXS_SetGraphicsMode(unsigned int);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
void LoadFileIntoMemory(const char*, void*, unsigned int*);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_FlushFile(void*, char*);
extern "C" void Background_UploadFile(BackgroundGraphics*, char*);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" void Background_Destroy(BackgroundGraphics*);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

extern char data_ov020_0218dce2;
extern char data_ov020_0218dcf8;
extern int g_fileLoadBuffer;

struct Struct_ov020_0218d32c {
    unsigned char pad[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char pad2[3];
};

struct Struct_ov020_0218d32c_2 {
#if defined(jpn)
    char pad0[0x400];
#else
    char pad0[0x470];
#endif

    SafeAllocator allocator;
};

// USA: func_ov020_0218d32c
extern "C" ARM void func_ov020_0218d32c(struct Struct_ov020_0218d32c_2* self, int mode) {
#if defined(jpn)
 enum {regionalOffset0=0x2c};
#else
 enum {regionalOffset0=0x9c};
#endif
    unsigned char* base = (unsigned char*)self;
    unsigned int outLen;
    void* recFieldScratch;
    char* volatile resultsArray[3];
    int sizeArr[3];
    unsigned char list3[0x20];

    self->allocator.Reset();
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 1, 1, 1, 0);

    Background_Init((BackgroundGraphics*)(base + regionalOffset0 + 0x400));
    Background_SetMapSize((unsigned char*)(base + regionalOffset0 + 0x400), 0);
    struct Struct_ov020_0218d32c* list = (struct Struct_ov020_0218d32c*)(base + regionalOffset0 + 0x400);
    list->unknown_1c_0_ = 0;
    list->unknown_1c_4_ = 1;
    Background_SetPriority(list, 1);
    Background_AllocateMap((BackgroundGraphics*)(base + regionalOffset0 + 0x400), (SafeAllocator*)&self->allocator);
    Background_AllocateScreens((BackgroundGraphics*)(base + regionalOffset0 + 0x400), 1, (SafeAllocator*)&self->allocator);
    Background_SetScroll((BackgroundGraphics*)(base + regionalOffset0 + 0x400), 0, 0);

    DisableSubObjVRAMBanks();
    DisableSubBGVRAMBanks();
    GXS_SetGraphicsMode(0);

    volatile unsigned int* var7 = (volatile unsigned int*)0x4001000;
    *var7 = (*var7 & ~0x1f00) | 0x100;
    MapVRAMBanksToSubObj(0x100);

    *var7 = (*var7 & 0xffcfffef) | 0x10;
    MapVRAMBanksToSubBG(0x80);

    func_ov020_0218cd64(0, 0, 0xe, 0, 0);
    func_ov020_0218cd64(0, 0, 0xf, 0, 0);

    volatile unsigned short* var8 = (volatile unsigned short*)0x4001008;
    var8[0] = (var8[0] & ~3) | 1;
    var8[1] = (var8[1] & ~3) | 2;
    var8[2] = var8[2] & ~3;
    var8[3] = (var8[3] & ~3) | 3;

    BackgroundLoader::AddLockGlobal();

    if (mode == 1) {
        LoadFileIntoMemory((const char*)&data_ov020_0218dce2, (void*)&g_fileLoadBuffer, &outLen);
    } else {
        LoadFileIntoMemory((const char*)&data_ov020_0218dcf8, (void*)&g_fileLoadBuffer, &outLen);
    }

    int count = Pac_CountFiles((PacRecord*)&g_fileLoadBuffer);

    for (int i = 0; i < count; i++) {
        resultsArray[i] = (char*)Pac_GetFile((PacRecord*)&g_fileLoadBuffer, i, &recFieldScratch, &sizeArr[i]);
    }

    Background_Init((BackgroundGraphics*)list3);
    list3[0x1c] = (list3[0x1c] & ~0xf) | 1;
    list3[0x1c] = list3[0x1c] & ~0xf0;
    Background_SetPriority(list3, 3);
    Background_SetMapSize((unsigned char*)list3, 0);
    Background_SetScroll((BackgroundGraphics*)list3, 0, 0);

    for (int j = 0; j < 3; j++) {
        Background_FlushFile(list3, resultsArray[j]);
        Background_UploadFile((BackgroundGraphics*)list3, resultsArray[j]);
    }

    Background_UploadMap((BackgroundGraphics*)list3, (void*)0);
    Background_Destroy((BackgroundGraphics*)list3);
    BackgroundLoader::RemoveLockGlobal();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xf, 0x1f);

    volatile unsigned int* var12 = (volatile unsigned int*)0x4000000;
    *var12 = (*var12 & ~0x1f00) | 0x1300;

    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
}
