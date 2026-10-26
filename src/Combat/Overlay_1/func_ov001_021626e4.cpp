#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/VRAM.h"

struct Background021626e4 {
    char unk_0[0x1c];
    unsigned char screen : 4;
    unsigned char layer : 4;
    char unknown_1d_[3];
};

extern "C" int func_ov017_021d612c(void* args);
extern "C" int func_ov017_021d60f4(void* args);
extern "C" unsigned int func_ov001_0215a750(const char* path, void** outPtr);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void func_ov001_02162678(int a, int b, int c, int d);
extern "C" void GXS_SetGraphicsMode(unsigned int mode);
extern "C" void func_ov001_021628d4(int a, int b, int c, int d);
struct BackgroundGraphics;
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetPriority(Background021626e4* background, int a);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void OS_WaitVBlankIntr();
extern "C" void Background_FlushFile(void*, char*);
extern "C" void Background_UploadFile(BackgroundGraphics*, char*);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" void Background_Destroy(BackgroundGraphics*);

extern char data_ov001_02165745[];

// USA: func_ov001_021626e4
extern "C" ARM int func_ov001_021626e4(void* args) {
    char path[0x50];
    void* records[3];
    int recordSizes[3];
    Background021626e4 background;
    void* file;
    unsigned int fileSize;
    void* name;
    BackgroundLoader* loader;
    int var8;
    int locked;
    int count;
    int subScreen;

    loader = BackgroundLoader::GetInstance();
    var8 = func_ov017_021d612c(args);
    subScreen = func_ov017_021d60f4((char*)args + 8);
    sprintf(path, data_ov001_02165745, var8);

    locked = 0;
    file = NULL;
    fileSize = 0;
    loader->GetLoadedFileByName(path, &file, &fileSize);
    if (file == NULL) {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (func_ov001_0215a750(path, &file) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }

    count = Pac_CountFiles((PacRecord*)file);
    for (int i = 0; i < count; i++) {
        records[i] = Pac_GetFile((PacRecord*)file, i, &name, &recordSizes[i]);
    }

    DISPCNT = (DISPCNT & ~0x1f00) | 0x800;
    if (subScreen == 0) {
        func_ov001_02162678(0, 0, 1, 1);
    } else {
        DisableSubBGVRAMBanks();
        GXS_SetGraphicsMode(0);
        MapVRAMBanksToSubBG(VRAM_BANK_H);
        func_ov001_021628d4(0, 0, 0xe, 0);
    }

    Background_Init((BackgroundGraphics*)&background);
    background.screen = subScreen;
    background.layer = 3;
    Background_SetPriority(&background, 0);
    Background_SetMapSize((unsigned char*)&background, 0);
    Background_SetScroll((BackgroundGraphics*)&background, 0, 0);
    OS_WaitVBlankIntr();
    for (int i = 0; i < count; i++) {
        Background_FlushFile(&background, (char*)records[i]);
        Background_UploadFile((BackgroundGraphics*)&background, (char*)records[i]);
    }
    Background_UploadMap((BackgroundGraphics*)&background, NULL);
    Background_Destroy((BackgroundGraphics*)&background);

    if (locked) {
        BackgroundLoader::RemoveLockGlobal();
    }
    return 1;
}
