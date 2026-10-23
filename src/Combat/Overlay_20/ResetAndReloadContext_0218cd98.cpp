#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define func_020c39a0 func_020c546c
#endif

extern "C" void func_020c39a0(short* out, int value);

extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
struct List0204af64;
void Background_Init(List0204af64*);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int, void*, int);
struct AllocTarget0204b12c;
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
void Background_AllocateScreens(Foo0204af38*, int, SafeAllocator*);
struct Obj0204b5e8;
void Background_SetScroll(Obj0204b5e8*, int, int);
void LoadFileIntoMemory(const char*, void*, unsigned int*);
struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900*);
struct Rec020467f0;
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
extern "C" void Background_LoadFile(void*, void*, void*, int);
struct Obj0204b8d0;
void Background_DrawScreen(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
struct List0204b0e8;
void Background_UploadMap(List0204b0e8*, void*);

extern char data_ov020_0218dcb3;
extern int data_0211e33c;

struct ResetContext0218cd98 {
    char pad0[0x470];
    SafeAllocator allocator;
};

// USA: func_ov020_0218cd98  (semantic: ResetAndReloadContext_0218cd98)
extern "C" ARM void func_ov020_0218cd98(struct ResetContext0218cd98* self) {
    unsigned char* base = (unsigned char*)self;

    func_020c39a0((short*)0x400106c, -16);
    self->allocator.Reset();
    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0, 1, 1, 1, 0);

    Background_Init((List0204af64*)(base + 0xbc + 0x400));
    Background_SetMapSize((unsigned char*)(base + 0xbc + 0x400), 0);

    unsigned char* obj = base + 0xbc;
    unsigned char* list = obj + 0x400;
    list[0x1c] = (list[0x1c] & ~0xf) | 1;
    int v2 = list[0x1c] & ~0xf0;
    list[0x1c] = v2;
    Background_SetPriority(list, 0, obj, v2);

    Background_AllocateMap((AllocTarget0204b12c*)(base + 0xbc + 0x400), (SafeAllocator*)&self->allocator);
    Background_AllocateScreens((Foo0204af38*)(base + 0xbc + 0x400), 1, (SafeAllocator*)&self->allocator);
    Background_SetScroll((Obj0204b5e8*)(base + 0xbc + 0x400), 0, 0);
    BackgroundLoader::AddLockGlobal();

    unsigned int local1c = 0;
    LoadFileIntoMemory((const char*)&data_ov020_0218dcb3, (void*)&data_0211e33c, &local1c);
    int count = Pac_CountFiles((ActiveEntry02046900*)&data_0211e33c);

    for (int i = 0; i < count; i++) {
        int recSize;
        void* recField;
        void* rec = Pac_GetFile((Rec020467f0*)&data_0211e33c, i, &recField, &recSize);
        if (rec != 0) {
            Background_LoadFile(base + 0xbc + 0x400, rec, &self->allocator, recSize);
        }
    }

    Background_DrawScreen((Obj0204b8d0*)(base + 0xbc + 0x400), 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    Background_UploadMap((List0204b0e8*)(base + 0xbc + 0x400), (void*)0);
    BackgroundLoader::RemoveLockGlobal();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x1300;
    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg1000 = (*reg1000 & ~0x1f00) | 0x100;

    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
}
