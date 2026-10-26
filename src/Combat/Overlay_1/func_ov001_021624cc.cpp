#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/VRAM.h"

extern "C" int func_ov017_021d612c(void* obj);
extern char data_ov001_02165745[];

extern "C" unsigned int func_ov001_0215a750(const char* path, void** outPtr);
extern "C" void func_ov001_02162678(int a, int b, int c, int d);

struct PacRecord;
extern "C" int Pac_CountFiles(struct PacRecord* entry);

extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

struct BackgroundGraphics;
extern "C" void Background_Init(struct BackgroundGraphics* obj);

extern "C" void Background_SetMapSize(unsigned char* obj, int value);

extern "C" void Background_SetPriority(void*, int);

extern "C" int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);

extern "C" void OS_WaitVBlankIntr();

extern "C" void Background_FlushFile(void* obj, char* str);

extern "C" void Background_UploadFile(struct BackgroundGraphics* self, char* str);

extern "C" void Background_UploadMap(struct BackgroundGraphics* obj, void* buf);

extern "C" void Background_Destroy(struct BackgroundGraphics* obj);

struct Struct_ov001_021624cc {
    unsigned char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char unknown_1d_[3];
};

// USA: func_ov001_021624cc
extern "C" ARM int func_ov001_021624cc(void* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* records[3];
    int sizes[3];
    Struct_ov001_021624cc s;
    void* fileData;
    unsigned int size;
    void* dummyPtr;
    char path[0x50];

    sprintf(path, data_ov001_02165745, func_ov017_021d612c(self));
    int locked = 0;
    fileData = NULL;
    size = 0;
    loader->GetLoadedFileByName(path, &fileData, &size);
    if (fileData == NULL) {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (func_ov001_0215a750(path, &fileData) == 0) {
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
    func_ov001_02162678(0, 1, 1, 1);
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
    if (locked) {
        BackgroundLoader::RemoveLockGlobal();
    }
    Background_UploadMap((struct BackgroundGraphics*)&s, 0);
    Background_Destroy((struct BackgroundGraphics*)&s);
    return 1;
}
