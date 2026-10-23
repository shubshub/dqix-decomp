#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/VRAM.h"

struct Struct_ov001_021626e4 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};

extern "C" int func_ov017_021d612c(void* args);
extern "C" int func_ov017_021d60f4(void* args);
unsigned int LoadResourceIntoGlobalBuffer_0215a750(const char* path, void** outPtr);
struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900*);
struct Rec020467f0;
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
void SetBg3ControlFields_02162678(int a, int b, int c, int d);
void SetSubBgMode_020c3984(unsigned int mode);
void SetSubBg3ControlFields_021628d4(int a, int b, int c, int d);
struct List0204af64;
void Background_Init(List0204af64*);
extern "C" void Background_SetPriority(Background021626e4* background, int a);
void Background_SetMapSize(unsigned char*, int);
struct Obj0204b5e8;
void Background_SetScroll(Obj0204b5e8*, int, int);
void DelayThenSyncBit0_020c9820();
void Background_FlushFile(void*, char*);
struct SelfTag0204b3a0;
void Background_UploadFile(SelfTag0204b3a0*, char*);
struct List0204b0e8;
void Background_UploadMap(List0204b0e8*, void*);
struct List0204afb4;
void ResetRecordList0204afb4(List0204afb4*);

extern char data_ov001_02165745[];

// USA: func_ov001_021626e4
extern "C" ARM int func_ov001_021626e4(void* arg0) {
    char var0[0x50];
    void* var1[3];
    int var2[3];
    Struct_ov001_021626e4 var3;
    void* var4;
    unsigned int var5;
    void* var6;
    BackgroundLoader* var7;
    int var8;
    int var9;
    int var10;
    int var11;

    var7 = BackgroundLoader::GetInstance();
    var8 = func_ov017_021d612c(arg0);
    var11 = func_ov017_021d60f4((char*)arg0 + 8);
    sprintf(var0, data_ov001_02165745, var8);

    var9 = 0;
    var4 = NULL;
    var5 = 0;
    var7->GetLoadedFileByName(var0, &var4, &var5);
    if (var4 == NULL) {
        BackgroundLoader::AddLockGlobal();
        var9 = 1;
        if (func_ov001_0215a750(var0, &var4) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }

    count = Pac_CountFiles((ActiveEntry02046900*)file);
    for (int i = 0; i < count; i++) {
        records[i] = Pac_GetFile((Rec020467f0*)file, i, &name, &recordSizes[i]);
    }

    DISPCNT = (DISPCNT & ~0x1f00) | 0x800;
    if (var11 == 0) {
        func_ov001_02162678(0, 0, 1, 1);
    } else {
        DisableSubBGVRAMBanks();
        func_020c3984(0);
        MapVRAMBanksToSubBG(VRAM_BANK_H);
        func_ov001_021628d4(0, 0, 0xe, 0);
    }

    Background_Init((List0204af64*)&background);
    background.screen = subScreen;
    background.layer = 3;
    Background_SetPriority(&background, 0);
    Background_SetMapSize((unsigned char*)&background, 0);
    Background_SetScroll((Obj0204b5e8*)&background, 0, 0);
    DelayThenSyncBit0_020c9820();
    for (int i = 0; i < count; i++) {
        Background_FlushFile(&background, (char*)records[i]);
        Background_UploadFile((SelfTag0204b3a0*)&background, (char*)records[i]);
    }
    Background_UploadMap((List0204b0e8*)&background, NULL);
    ResetRecordList0204afb4((List0204afb4*)&background);

    if (var9) {
        BackgroundLoader::RemoveLockGlobal();
    }
    return 1;
}
