#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define data_ov005_0215cd68 data_ov005_0215e148
#else
#define REGION_LAYOUT(j,u) u
#endif
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void func_ov005_02155424(void* self);
extern "C" void func_ov005_02155544(void* self);
extern "C" void func_ov005_021555c0(void* self);
extern "C" void func_ov005_021571d0(void* self);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
extern "C" char* MessageSystem_GetInstance();
extern "C" void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fog);
extern "C" int* BgVram_GetInstance();
extern "C" void BgVram_ResetWithBlankTile(int* obj, int a, int b);
extern "C" void BgVram_Reset(char*);
extern "C" void BgVram_Clear(char*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void* obj, int value);
struct BackgroundGraphics;
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);
struct Container020e0310;
extern "C" const char* KeyTable_Get(Container020e0310*, int);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_LoadFile(void* obj, void* data, SafeAllocator* alloc, int field44);
extern "C" void Background_FillRect(void* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
struct WindowPane;
extern "C" void WindowPane_AllocateBuffer(WindowPane*, SafeAllocator*, int, unsigned int);
struct WindowPane;
struct Struct_0205cf78;
extern "C" void Window_SetPanes(Struct_0205cf78*, WindowPane*, unsigned char);
struct Struct0200fb08;
extern "C" int GameState_GetLanguage(Struct0200fb08*);
extern "C" int FindMatchingRecords0204684c(PacRecord*, char const*, void**, int, int*, void**);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
extern "C" void SprSprite_LoadFile(void* a, int b, int c, int d);
struct Struct_ov002_0215505c_2;
extern "C" void func_ov023_021e1318(Struct_ov002_0215505c_2*);
extern "C" void func_ov023_021e133c(void* a, void* b, int c, int d, int e, short f);
extern "C" void func_ov005_02154d18(void* obj, int a, int b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d50(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);
extern "C" char* func_ov017_021a193c(int*);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_ov023_021dc134(void* obj, int key, int flag);
extern "C" void func_ov023_021dbfd0(void* obj, void* alloc);

extern char data_ov005_0215cdb4[];
extern char data_ov005_0215cdcd[];
extern unsigned int data_ov005_0215cd68[3];
extern char data_ov005_0215cddd[];
extern char data_ov005_0215cdf3[];
#if defined(jpn)
extern char data_ov005_0215e194[];
extern char data_ov005_0215e1ad[];
void* LoadFileIntoMemory(const char* path, void* archive, unsigned int* size);
#endif

struct Struct_ov005_0215436c {
    char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad1[3];
};

union Struct_ov005_0215436c_2 {
    unsigned int raw;
    struct {
        unsigned int b0 : 2;
        unsigned int b2 : 1;
        unsigned int b3 : 1;
        unsigned int unknown_0_4_ : 1;
        unsigned int unknown_0_5_ : 1;
        unsigned int unknown_0_6_ : 1;
        unsigned int unknown_0_7_ : 3;
        unsigned int b10 : 1;
        unsigned int rest : 21;
    } bits;
};

struct Struct_ov005_0215436c_3 {
    SafeAllocator alloc;
    char pad0[0x21c - sizeof(SafeAllocator)];
    SafeAllocator fileAlloc;
    char pad1[0x244 - 0x21c - sizeof(SafeAllocator)];
    SafeAllocator unknown_244_;
    char pad2[0x258 - 0x244 - sizeof(SafeAllocator)];
    SafeAllocator scriptAlloc;
    char pad3[0x294 - 0x258 - sizeof(SafeAllocator)];
    char pairTables[0xdf4 - 0x294];
    int unknown_df4_;
    char container[0xe10 - 0xdf8];
    int fe10;
    char pad4[REGION_LAYOUT(0xe80, 0xe84) - 0xe14];
    Struct_ov005_0215436c lists[3];
    char linkHead[0xf7c - 0xee4];
    Struct_ov005_0215436c* unknown_f7c_;
    char pad5[0xf96 - 0xf80];
    unsigned char unknown_f96_;
    char pad6[0xfa0 - 0xf97];
    char elems[3][0xe0];
    void* buffer;
    char effect[0x128c - 0x1244];
    int unknown_128c_;
    char unknown_1290_[REGION_LAYOUT(0x1930 - 0x128c, 0x19b8 - 0x1290)];
    unsigned short unknown_19b8_;
    char pad8[0x19be - 0x19ba];
    unsigned char unknown_19be_;
    char unknown_19bf_[0x19e0 - 0x19bf];
    char script[0x1a30 - 0x19e0];
    unsigned char unknown_1a30_;
    char pad10[0x1a34 - 0x1a31];
    void* unknown_1a34_;
    int motion[0x1a6c - 0x1a38 >> 2];
    int unknown_1a6c_;
    char records[0x2d90 - 0x1a70];
    short unknown_2d90_;
    char unknown_2d92_[0x3da9 - 0x2d92];
    unsigned char unknown_3da9_;
    unsigned char unknown_3daa_;
    char pad12[0x3db8 - 0x3dab];
    unsigned char unknown_3db8_;
    char unknown_3db9_[0x3dc4 - 0x3db9];
    unsigned char state;
    char unknown_3dc5_[3];
    int handle;
    Struct_ov005_0215436c_2 flags;
};

// USA: func_ov005_0215436c
extern "C" ARM int func_ov005_0215436c(Struct_ov005_0215436c_3* self) {
    unsigned int size;
    void* recData;
    void* file3;
    unsigned int len3;
    int recSize;
    void* file4;
    unsigned int var6;
    void* var7;
    unsigned int var8;
    void* datas[REGION_LAYOUT(36, 38)];
    int sizes[REGION_LAYOUT(36, 38)];

    if (self->state == 0xff) {
        return 1;
    }

    GameState* gs = GameState::GetInstance();
    int word = (int)gs->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->state == 0) {
        func_ov005_02155424(self);
        func_ov005_02155544(self);
        func_ov005_021555c0(self);
        self->flags.bits.unknown_0_5_ = 1;
        self->unknown_3da9_ = 0;
        self->flags.bits.unknown_0_6_ = 1;
        self->unknown_3daa_ = 0;
        self->state++;
    } else if (self->state == 1) {
        if (self->unknown_3daa_ == 0) {
            self->state++;
        }
    } else if (self->state == 2) {
#if defined(jpn)
        self->alloc.Reset();
        void* data = self->alloc.Allocate(0x2000);
        LoadFileIntoMemory(data_ov005_0215e194, data, &size);
        self->fileAlloc.Reset();
        KeyTable_Load(self->container, &self->fileAlloc, data, size);
        self->alloc.Reset();
        self->fe10 = *(int*)(MessageSystem_GetInstance() + 0x28);
#else
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        void* data = ExtractFileFromGP2(data_ov005_0215cdb4, data_ov005_0215cdcd, &size);
        self->fileAlloc.Reset();
        KeyTable_Load(self->container, &self->fileAlloc, data, size);
        BackgroundLoader::RemoveLockGlobal();
        self->fe10 = *(int*)(MessageSystem_GetInstance() + 0x5c);
#endif
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        SetFlags04((GameResources*)word, 0x800);
        int* bank = BgVram_GetInstance();
        BgVram_ResetWithBlankTile(bank, 0, 1);
        BgVram_Reset((char*)bank);
        BgVram_Clear((char*)bank);

        Background_SetMapSize((unsigned char*)&self->lists[0], 0);
        self->lists[0].lo = 0;
        self->lists[0].hi = 1;
        Background_SetPriority(&self->lists[0], 3);
        Background_SetScroll((BackgroundGraphics*)&self->lists[0], 0, 0);
        Background_AllocateMap((BackgroundGraphics*)&self->lists[0], &self->alloc);
        Background_AllocateScreens((BackgroundGraphics*)&self->lists[0], 6, &self->alloc);

        Background_SetMapSize((unsigned char*)&self->lists[1], 0);
        self->lists[1].lo = 0;
        self->lists[1].hi = 2;
        Background_SetPriority(&self->lists[1], 2);
        Background_SetScroll((BackgroundGraphics*)&self->lists[1], 0, 0);
        Background_AllocateMap((BackgroundGraphics*)&self->lists[1], &self->alloc);
        Background_AllocateScreens((BackgroundGraphics*)&self->lists[1], 9, &self->alloc);

        Background_SetMapSize((unsigned char*)&self->lists[2], 0);
        self->lists[2].lo = 0;
        self->lists[2].hi = 3;
        Background_SetPriority(&self->lists[2], 0);
        Background_SetScroll((BackgroundGraphics*)&self->lists[2], 0, 0);
        Background_AllocateMap((BackgroundGraphics*)&self->lists[2], &self->alloc);

        volatile unsigned short* var17 = (volatile unsigned short*)0x400000a;
        var17[0] = (var17[0] & 0x43) | 0x1d00;
        var17[1] = (var17[1] & 0x43) | 0x1e00;
        var17[2] = (var17[2] & 0x43) | 0x1f04;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xa, 6);

#if defined(jpn)
        self->handle = loader->QueueLoadFile(KeyTable_Get((Container020e0310*)self->container, 0x3e8), 0);
#else
        const char* inner = KeyTable_Get((Container020e0310*)self->container, 0x3e9);
        const char* gp2 = KeyTable_Get((Container020e0310*)self->container, 0x3e8);
        self->handle = loader->QueueLoadFileInGP2(gp2, inner, 0);
#endif
        self->state++;
    } else if (self->state == 3) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file3, &len3);
            int count = Pac_CountFiles((PacRecord*)file3);
            for (int i = 0; i < count; i++) {
                void* rec = Pac_GetFile((PacRecord*)file3, i, &recData, &recSize);
                if (rec != 0) {
                    if (i == 0) {
                        Background_LoadFile(&self->lists[2], rec, &self->alloc, recSize);
                    } else if (i <= 8) {
                        Background_LoadFile(&self->lists[0], rec, &self->alloc, recSize);
                    } else {
                        Background_LoadFile(&self->lists[1], rec, &self->alloc, recSize);
                    }
                }
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;

            Background_FillRect(&self->lists[1], 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((BackgroundGraphics*)&self->lists[1], 0);
            Background_FillRect(&self->lists[2], 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((BackgroundGraphics*)&self->lists[2], 0);
            Background_DrawScreen((BackgroundGraphics*)&self->lists[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            Background_UploadMap((BackgroundGraphics*)&self->lists[0], 0);
            Background_DrawScreen((BackgroundGraphics*)&self->lists[0], 1, 0, 0, 0, 0x14, 0x10, 2, 0xffff);
            Background_UploadMap((BackgroundGraphics*)&self->lists[0], 0);

            self->buffer = self->alloc.Allocate(0x2400);
            char* elem;
            for (int j = 0; j < 3; j++) {
                elem = self->elems[j];
                WindowPane_AllocateBuffer((WindowPane*)elem, &self->alloc, (int)self->buffer, data_ov005_0215cd68[j]);
                *(Struct_ov005_0215436c**)(elem + 4) = &self->lists[2];
            }
            self->unknown_f7c_ = &self->lists[2];
            self->unknown_f96_ = 1;
            Window_SetPanes((Struct_0205cf78*)self->linkHead, (WindowPane*)self->elems, 3);

            const char* name = KeyTable_Get((Container020e0310*)self->container, REGION_LAYOUT(0x3e9, 0x3ea));
            self->handle = loader->QueueLoadFile(name, 0);
            self->state++;
        }
    } else if (self->state == 4) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file4, &var6);
            int count = Pac_CountFiles((PacRecord*)file4);
#if defined(jpn)
            const char* name = KeyTable_Get((Container020e0310*)self->container, 0x7d0);
            if (FindMatchingRecords0204684c((PacRecord*)file4, name, datas, count, sizes, 0) != 0) {
                VramState_Restore((char*)self->pairTables);
                for (int i = 0; i < count; i++) {
                    SprSprite_LoadFile(self->records + i * 0x88, (int)datas[i], sizes[i], (int)((char*)self + 0x14));
                }
                VramState_Save((char*)self->pairTables);
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->handle = loader->QueueLoadFile(data_ov005_0215e1ad, 0);
#else
            int mode = GameState_GetLanguage((Struct0200fb08*)gs);
            int n = 0;
            const char* name = KeyTable_Get((Container020e0310*)self->container, 0x7d0);
            if (FindMatchingRecords0204684c((PacRecord*)file4, name, datas, count, sizes, 0) != 0) {
                VramState_Restore((char*)self->pairTables);
                for (int i = 0; i < count; i++) {
                    if (i == 0x23) {
                        if (mode == 2 || mode == 3) {
                            continue;
                        }
                    } else if (i == 0x24) {
                        if (mode != 2) {
                            continue;
                        }
                    } else if (i == 0x25) {
                        if (mode != 3) {
                            continue;
                        }
                    }
                    SprSprite_LoadFile(self->records + n * 0x88, (int)datas[i], sizes[i], (int)((char*)self + 0x14));
                    n++;
                }
                VramState_Save((char*)self->pairTables);
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->handle = loader->QueueLoadFileInGP2(data_ov005_0215cddd, data_ov005_0215cdf3, 0);
#endif
            self->state++;
        }
    } else if (self->state == 5) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &var7, &var8);
            self->scriptAlloc.Reset();
            func_ov023_021e1318((Struct_ov002_0215505c_2*)self->script);
            func_ov023_021e133c(self->script, &self->scriptAlloc, (int)var7, var8, 0, 0);
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->state++;
        }
    } else {
        char* recs = self->records;
        volatile unsigned short* var34 = (volatile unsigned short*)0x4000008;
        var34[0] = (var34[0] & ~3) | 1;
        var34[1] = (var34[1] & ~3) | 3;
        var34[2] = (var34[2] & ~3) | 2;
        var34[3] = var34[3] & ~3;
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x1f00;

        self->unknown_1a34_ = recs;
        self->motion[0] = 0x8000;
        self->motion[1] = -0x3000;
        self->motion[2] = 0x3000;
        self->motion[3] = -0x3000;
        self->motion[4] = 0x3000;
        func_ov005_02154d18(&self->unknown_1a34_, 0x85000, 0x17000);
        func_ov005_02154d34(&self->unknown_1a34_, 0x85000, 0x17000);
        func_ov005_02154d50(&self->unknown_1a34_, 0x76000, 0x16000);
        func_ov005_02154d7c(&self->unknown_1a34_, 0x76000, 0x16000);
        self->unknown_1a6c_ = 0x5000;
        self->unknown_3db8_ = 0;
        self->flags.raw |= 0x400;
        func_ov005_021571d0(self);
        self->unknown_1a30_ = 0;
        self->flags.bits.b2 = 1;
        self->flags.bits.b3 = 1;

        GameState::GetInstance();
        char* res = (char*)GetGameResources();
        int v = *(int*)(func_ov017_021a193c((int*)(*(int*)(res + REGION_LAYOUT(0x34f8, 0x3708)))) + REGION_LAYOUT(0x4f8, 0x4fc));
        func_020dc7e8(5, (signed char)v);
        self->unknown_244_.Reset();
        func_ov023_021dc134(self->effect, self->unknown_2d90_, 0);
        self->unknown_19b8_ |= 0xd0;
        func_ov023_021dbfd0(self->effect, &self->unknown_244_);
        self->unknown_128c_ = self->unknown_df4_;
        self->unknown_19be_ = v;
        self->state = 0xff;
        return 1;
    }
    return 0;
}
