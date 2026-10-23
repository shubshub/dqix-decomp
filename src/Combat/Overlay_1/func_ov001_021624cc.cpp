#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/VRAM.h"

extern "C" int func_ov017_021d612c(void* arg0);
extern char data_ov001_02165745[];

extern "C" unsigned int func_ov001_0215a750(const char* arg0, void** arg1);
extern "C" void func_ov001_02162678(int arg0, int arg1, int arg2, int arg3);

struct ActiveEntry02046900;
int Pac_CountFiles(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
void Background_Init(struct List0204af64* obj);

void Background_SetMapSize(unsigned char* obj, int value);

extern "C" void Background_SetPriority(void*, int);

struct Obj0204b5e8;
int Background_SetScroll(struct Obj0204b5e8* obj, int a, int b);

extern "C" void func_020c9820();

void Background_FlushFile(void* obj, char* str);

struct SelfTag0204b3a0;
void Background_UploadFile(struct SelfTag0204b3a0* self, char* str);

struct List0204b0e8;
void Background_UploadMap(struct List0204b0e8* obj, void* buf);

struct Struct_02020cb8_3;
extern "C" void func_0204afb4(struct Struct_02020cb8_3* arg0);

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
    int count = Pac_CountFiles((struct ActiveEntry02046900*)fileData);
    for (int i = 0; i < count; i++) {
        records[i] = (char*)Pac_GetFile((struct Rec020467f0*)fileData, i, &dummyPtr, &sizes[i]);
    }
    ReleaseMainBGVRAMBanks();
    MapVRAMBanksToMainBG(0x10);
    DISPCNT = (DISPCNT & ~0x1f00) | 0x800;
    SetBg3ControlFields_02162678(0, 1, 1, 1);
    Background_Init((struct List0204af64*)&s);
    s.lo = 0;
    s.hi = 3;
    Background_SetPriority(&s, 0);
    Background_SetMapSize((unsigned char*)&s, 0);
    Background_SetScroll((struct Obj0204b5e8*)&s, 0, 0);
    DelayThenSyncBit0_020c9820();
    for (int i = 0; i < count; i++) {
        char* record = records[i];
        Background_FlushFile(&s, record);
        Background_UploadFile((struct SelfTag0204b3a0*)&s, record);
    }
    if (var8) {
        BackgroundLoader::RemoveLockGlobal();
    }
    Background_UploadMap((struct List0204b0e8*)&s, 0);
    ResetRecordList0204afb4((struct List0204afb4*)&s);
    return 1;
}
