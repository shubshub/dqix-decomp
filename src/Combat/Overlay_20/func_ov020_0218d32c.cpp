#pragma opt_vectorize_loops off
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define func_020c39a0 func_020c546c
#endif

extern "C" void func_020c39a0(short* arg0, int arg1);

extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
struct List0204af64;
void Background_Init(List0204af64*);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
struct AllocTarget0204b12c;
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
void Background_AllocateScreens(Foo0204af38*, int, SafeAllocator*);
struct Obj0204b5e8;
void Background_SetScroll(Obj0204b5e8*, int, int);
extern "C" int DisableSubObjVRAMBanks();
extern "C" int DisableSubBGVRAMBanks();
extern "C" void func_020c3984(unsigned int);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
void LoadFileIntoMemory(const char*, void*, unsigned int*);
struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900*);
struct Rec020467f0;
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
void Background_FlushFile(void*, char*);
struct SelfTag0204b3a0;
void Background_UploadFile(SelfTag0204b3a0*, char*);
struct List0204b0e8;
void Background_UploadMap(List0204b0e8*, void*);
struct List0204afb4;
void ResetRecordList0204afb4(List0204afb4*);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

extern char data_ov020_0218dce2;
extern char data_ov020_0218dcf8;
extern int data_0211e33c;

struct Struct_ov020_0218d32c {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_[3];
};

struct Struct_ov020_0218d32c_2 {
#if defined(jpn)
    char unknown_0_[0x400];
#else
    char unknown1_0_[0x470];
#endif

    SafeAllocator unknown_470_;
};

// USA: func_ov020_0218d32c
extern "C" ARM void func_ov020_0218d32c(struct Struct_ov020_0218d32c_2* arg0, int arg1) {
#if defined(jpn)
 enum {Enum_ov020_0218d32c_156=0x2c};
#else
 enum {Enum_ov020_0218d32c_156=0x9c};
#endif
    unsigned char* var0 = (unsigned char*)arg0;
    unsigned int var1;
    void* var2;
    char* volatile var3[3];
    int var4[3];
    unsigned char var5[0x20];

    arg0->unknown_470_.Reset();
    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 1, 1, 1, 0);

    Background_Init((List0204af64*)(base + regionalOffset0 + 0x400));
    Background_SetMapSize((unsigned char*)(base + regionalOffset0 + 0x400), 0);
    struct List0218d32c* list = (struct List0218d32c*)(base + regionalOffset0 + 0x400);
    list->lowNibble = 0;
    list->highNibble = 1;
    Background_SetPriority(list, 1);
    Background_AllocateMap((AllocTarget0204b12c*)(base + regionalOffset0 + 0x400), (SafeAllocator*)&self->allocator);
    Background_AllocateScreens((Foo0204af38*)(base + regionalOffset0 + 0x400), 1, (SafeAllocator*)&self->allocator);
    Background_SetScroll((Obj0204b5e8*)(base + regionalOffset0 + 0x400), 0, 0);

    DisableSubObjVRAMBanks();
    DisableSubBGVRAMBanks();
    func_020c3984(0);

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

    if (arg1 == 1) {
        LoadFileIntoMemory((const char*)&data_ov020_0218dce2, (void*)&data_0211e33c, &var1);
    } else {
        LoadFileIntoMemory((const char*)&data_ov020_0218dcf8, (void*)&data_0211e33c, &var1);
    }

    int count = Pac_CountFiles((ActiveEntry02046900*)&data_0211e33c);

    for (int i = 0; i < count; i++) {
        resultsArray[i] = (char*)Pac_GetFile((Rec020467f0*)&data_0211e33c, i, &recFieldScratch, &sizeArr[i]);
    }

    Background_Init((List0204af64*)list3);
    list3[0x1c] = (list3[0x1c] & ~0xf) | 1;
    list3[0x1c] = list3[0x1c] & ~0xf0;
    Background_SetPriority(list3, 3);
    Background_SetMapSize((unsigned char*)list3, 0);
    Background_SetScroll((Obj0204b5e8*)list3, 0, 0);

    for (int j = 0; j < 3; j++) {
        Background_FlushFile(list3, resultsArray[j]);
        Background_UploadFile((SelfTag0204b3a0*)list3, resultsArray[j]);
    }

    Background_UploadMap((List0204b0e8*)list3, (void*)0);
    ResetRecordList0204afb4((List0204afb4*)list3);
    BackgroundLoader::RemoveLockGlobal();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xf, 0x1f);

    volatile unsigned int* var12 = (volatile unsigned int*)0x4000000;
    *var12 = (*var12 & ~0x1f00) | 0x1300;

    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
}
