#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/VRAM.h"

extern "C" int func_ov017_021d612c(void* arg0);
extern char data_ov001_02165745[];

extern "C" unsigned int func_ov001_0215a750(const char* arg0, void** arg1);
extern "C" void func_ov001_02162678(int arg0, int arg1, int arg2, int arg3);

struct PacRecord;
int Pac_CountFiles(struct PacRecord* entry);

void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

struct BackgroundGraphics;
void Background_Init(struct BackgroundGraphics* obj);

void Background_SetMapSize(unsigned char* obj, int value);

extern "C" void Background_SetPriority(void*, int);

int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);

void OS_WaitVBlankIntr();

void Background_FlushFile(void* obj, char* str);

void Background_UploadFile(struct BackgroundGraphics* self, char* str);

void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);

void Background_Destroy(struct BackgroundGraphics* obj);

struct Struct_ov001_021624cc {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_[3];
};

// USA: func_ov001_021624cc
extern "C" ARM int func_ov001_021624cc(void* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    char* var1[3];
    int var2[3];
    Struct_ov001_021624cc var3;
    void* var4;
    unsigned int var5;
    void* var6;
    char var7[0x50];

    sprintf(var7, data_ov001_02165745, func_ov017_021d612c(arg0));
    int var8 = 0;
    var4 = NULL;
    var5 = 0;
    var0->GetLoadedFileByName(var7, &var4, &var5);
    if (var4 == NULL) {
        BackgroundLoader::AddLockGlobal();
        var8 = 1;
        if (func_ov001_0215a750(var7, &var4) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    int count = Pac_CountFiles((struct PacRecord*)fileData);
    for (int i = 0; i < count; i++) {
        records[i] = (char*)Pac_GetFile((struct PacRecord*)fileData, i, &dummyPtr, &sizes[i]);
    }
    ReleaseMainBGVRAMBanks();
    MapVRAMBanksToMainBG(0x10);
    DISPCNT = (DISPCNT & ~0x1f00) | 0x800;
    SetBg3ControlFields_02162678(0, 1, 1, 1);
    Background_Init((struct BackgroundGraphics*)&s);
    s.lo = 0;
    s.hi = 3;
    Background_SetPriority(&s, 0);
    Background_SetMapSize((unsigned char*)&s, 0);
    Background_SetScroll((struct BackgroundGraphics*)&s, 0, 0);
    OS_WaitVBlankIntr();
    for (int i = 0; i < count; i++) {
        char* record = records[i];
        Background_FlushFile(&s, record);
        Background_UploadFile((struct BackgroundGraphics*)&s, record);
    }
    if (var8) {
        BackgroundLoader::RemoveLockGlobal();
    }
    Background_UploadMap((struct BackgroundGraphics*)&s, 0);
    Background_Destroy((struct BackgroundGraphics*)&s);
    return 1;
}
