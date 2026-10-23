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
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
char* GetGlobalField0x1c020421a0();
void Set3DClearColor_020c5588(int color, int alpha, int depth, int polygonId, int fog);
int* GetData02105254_0203b628();
void SetupBankModeAndTransfer_0203b678(int* obj, int a, int b);
void TailForward0203b66c(char*);
void ClearThreeRegions0203b634(char*);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void* obj, int value);
struct Obj0204b5e8;
void Background_SetScroll(Obj0204b5e8*, int, int);
struct AllocTarget0204b12c;
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
void Background_AllocateScreens(Foo0204af38*, int, SafeAllocator*);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);
struct Container020e0310;
const char* KeyTable_Get(Container020e0310*, int);
struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900*);
struct Rec020467f0;
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
extern "C" void Background_LoadFile(void* obj, void* data, SafeAllocator* alloc, int field44);
extern "C" void Background_FillRect(void* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
struct List0204b0e8;
void Background_UploadMap(List0204b0e8*, void*);
struct Obj0204b8d0;
void Background_DrawScreen(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
struct Obj0204c7a8;
void WindowPane_AllocateBuffer(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
struct Elem_0205cf78;
struct Struct_0205cf78;
void Window_SetPanes(Struct_0205cf78*, Elem_0205cf78*, unsigned char);
struct Struct0200fb08;
int NormalizeField5_0200fb08(Struct0200fb08*);
int FindMatchingRecords0204684c(Rec020467f0*, char const*, void**, int, int*, void**);
void VramState_Restore(char*);
void VramState_Save(char*);
void Forward02047b30(void* a, int b, int c, int d);
struct Obj021e1318;
void ClearObj_021e1318(Obj021e1318*);
void InitScriptAndRun_021e133c(void* a, void* b, int c, int d, int e, short f);
extern "C" void func_ov005_02154d18(void* obj, int a, int b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d50(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);
char* GetField1c_021a193c(int*);
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
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};

union Struct_ov005_0215436c_2 {
    unsigned int unknown_0_;
    struct {
        unsigned int unknown_0_0_ : 2;
        unsigned int unknown_0_2_ : 1;
        unsigned int unknown_0_3_ : 1;
        unsigned int unknown_0_4_ : 1;
        unsigned int unknown_0_5_ : 1;
        unsigned int unknown_0_6_ : 1;
        unsigned int unknown_0_7_ : 3;
        unsigned int unknown_1_2_ : 1;
        unsigned int unknown_1_3_ : 21;
    } unknown1_0_;
};

struct Struct_ov005_0215436c_3 {
    SafeAllocator unknown_0_;
    char unknown_14_[0x21c - sizeof(SafeAllocator)];
    SafeAllocator unknown_21c_;
    char unknown_230_[0x244 - 0x21c - sizeof(SafeAllocator)];
    SafeAllocator unknown_244_;
    char unknown_258_[0x258 - 0x244 - sizeof(SafeAllocator)];
    SafeAllocator unknown1_258_;
    char unknown_26c_[0x294 - 0x258 - sizeof(SafeAllocator)];
    char unknown_294_[0xdf4 - 0x294];
    int unknown_df4_;
    char unknown_df8_[0xe10 - 0xdf8];
    int unknown_e10_;
    char unknown_e14_[REGION_LAYOUT(0xe80, 0xe84) - 0xe14];
    Struct_ov005_0215436c unknown_e84_[3];
    char unknown_ee4_[0xf7c - 0xee4];
    Struct_ov005_0215436c* unknown_f7c_;
    char unknown_f80_[0xf96 - 0xf80];
    unsigned char unknown_f96_;
    char unknown_f97_[0xfa0 - 0xf97];
    char unknown_fa0_[3][0xe0];
    void* unknown_1240_;
    char unknown_1244_[0x128c - 0x1244];
    int unknown_128c_;
    char unknown_1290_[REGION_LAYOUT(0x1930 - 0x128c, 0x19b8 - 0x1290)];
    unsigned short unknown_19b8_;
    char unknown_19ba_[0x19be - 0x19ba];
    unsigned char unknown_19be_;
    char unknown_19bf_[0x19e0 - 0x19bf];
    char unknown_19e0_[0x1a30 - 0x19e0];
    unsigned char unknown_1a30_;
    char unknown_1a31_[0x1a34 - 0x1a31];
    void* unknown_1a34_;
    int unknown_1a38_[0x1a6c - 0x1a38 >> 2];
    int unknown_1a6c_;
    char unknown_1a70_[0x2d90 - 0x1a70];
    short unknown_2d90_;
    char unknown_2d92_[0x3da9 - 0x2d92];
    unsigned char unknown_3da9_;
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3db8 - 0x3dab];
    unsigned char unknown_3db8_;
    char unknown_3db9_[0x3dc4 - 0x3db9];
    unsigned char unknown_3dc4_;
    char unknown_3dc5_[3];
    int unknown_3dc8_;
    Struct_ov005_0215436c_2 unknown_3dcc_;
};

// USA: func_ov005_0215436c
extern "C" ARM int func_ov005_0215436c(Struct_ov005_0215436c_3* arg0) {
    unsigned int var0;
    void* var1;
    void* var2;
    unsigned int var3;
    int var4;
    void* var5;
    unsigned int var6;
    void* var7;
    unsigned int var8;
    void* var9[REGION_LAYOUT(36, 38)];
    int var10[REGION_LAYOUT(36, 38)];

    if (arg0->unknown_3dc4_ == 0xff) {
        return 1;
    }

    GameState* gs = GameState::GetInstance();
    int word = (int)gs->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (arg0->unknown_3dc4_ == 0) {
        func_ov005_02155424(arg0);
        func_ov005_02155544(arg0);
        func_ov005_021555c0(arg0);
        arg0->unknown_3dcc_.unknown1_0_.unknown_0_5_ = 1;
        arg0->unknown_3da9_ = 0;
        arg0->unknown_3dcc_.unknown1_0_.unknown_0_6_ = 1;
        arg0->unknown_3daa_ = 0;
        arg0->unknown_3dc4_++;
    } else if (arg0->unknown_3dc4_ == 1) {
        if (arg0->unknown_3daa_ == 0) {
            arg0->unknown_3dc4_++;
        }
    } else if (arg0->unknown_3dc4_ == 2) {
#if defined(jpn)
        self->alloc.Reset();
        void* data = self->alloc.Allocate(0x2000);
        LoadFileIntoMemory(data_ov005_0215e194, data, &size);
        self->fileAlloc.Reset();
        KeyTable_Load(self->container, &self->fileAlloc, data, size);
        self->alloc.Reset();
        self->fe10 = *(int*)(GetGlobalField0x1c020421a0() + 0x28);
#else
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        void* data = ExtractFileFromGP2(data_ov005_0215cdb4, data_ov005_0215cdcd, &size);
        self->fileAlloc.Reset();
        KeyTable_Load(self->container, &self->fileAlloc, data, size);
        BackgroundLoader::RemoveLockGlobal();
        arg0->unknown_e10_ = *(int*)(func_020421a0() + 0x5c);
#endif
        func_020c5588(0, 0, 0x7fff, 0, 0);
        SetFlags04((GameResources*)var12, 0x800);
        int* var16 = func_0203b628();
        func_0203b678(var16, 0, 1);
        func_0203b66c((char*)var16);
        func_0203b634((char*)var16);

        Background_SetMapSize((unsigned char*)&self->lists[0], 0);
        self->lists[0].lo = 0;
        self->lists[0].hi = 1;
        Background_SetPriority(&self->lists[0], 3);
        Background_SetScroll((Obj0204b5e8*)&self->lists[0], 0, 0);
        Background_AllocateMap((AllocTarget0204b12c*)&self->lists[0], &self->alloc);
        Background_AllocateScreens((Foo0204af38*)&self->lists[0], 6, &self->alloc);

        Background_SetMapSize((unsigned char*)&self->lists[1], 0);
        self->lists[1].lo = 0;
        self->lists[1].hi = 2;
        Background_SetPriority(&self->lists[1], 2);
        Background_SetScroll((Obj0204b5e8*)&self->lists[1], 0, 0);
        Background_AllocateMap((AllocTarget0204b12c*)&self->lists[1], &self->alloc);
        Background_AllocateScreens((Foo0204af38*)&self->lists[1], 9, &self->alloc);

        Background_SetMapSize((unsigned char*)&self->lists[2], 0);
        self->lists[2].lo = 0;
        self->lists[2].hi = 3;
        Background_SetPriority(&self->lists[2], 0);
        Background_SetScroll((Obj0204b5e8*)&self->lists[2], 0, 0);
        Background_AllocateMap((AllocTarget0204b12c*)&self->lists[2], &self->alloc);

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
            int count = Pac_CountFiles((ActiveEntry02046900*)file3);
            for (int i = 0; i < count; i++) {
                void* rec = Pac_GetFile((Rec020467f0*)file3, i, &recData, &recSize);
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
            var13->RemoveTask(arg0->unknown_3dc8_);
            arg0->unknown_3dc8_ = -1;

            Background_FillRect(&self->lists[1], 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((List0204b0e8*)&self->lists[1], 0);
            Background_FillRect(&self->lists[2], 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((List0204b0e8*)&self->lists[2], 0);
            Background_DrawScreen((Obj0204b8d0*)&self->lists[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            Background_UploadMap((List0204b0e8*)&self->lists[0], 0);
            Background_DrawScreen((Obj0204b8d0*)&self->lists[0], 1, 0, 0, 0, 0x14, 0x10, 2, 0xffff);
            Background_UploadMap((List0204b0e8*)&self->lists[0], 0);

            self->buffer = self->alloc.Allocate(0x2400);
            char* elem;
            for (int j = 0; j < 3; j++) {
                elem = self->elems[j];
                WindowPane_AllocateBuffer((Obj0204c7a8*)elem, &self->alloc, (int)self->buffer, data_ov005_0215cd68[j]);
                *(List0215436c**)(elem + 4) = &self->lists[2];
            }
            self->linkList = &self->lists[2];
            self->linkFlag = 1;
            Window_SetPanes((Struct_0205cf78*)self->linkHead, (Elem_0205cf78*)self->elems, 3);

            const char* name = KeyTable_Get((Container020e0310*)self->container, REGION_LAYOUT(0x3e9, 0x3ea));
            self->handle = loader->QueueLoadFile(name, 0);
            self->state++;
        }
    } else if (self->state == 4) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file4, &len4);
            int count = Pac_CountFiles((ActiveEntry02046900*)file4);
#if defined(jpn)
            const char* name = KeyTable_Get((Container020e0310*)self->container, 0x7d0);
            if (FindMatchingRecords0204684c((Rec020467f0*)file4, name, datas, count, sizes, 0) != 0) {
                VramState_Restore((char*)self->pairTables);
                for (int i = 0; i < count; i++) {
                    Forward02047b30(self->records + i * 0x88, (int)datas[i], sizes[i], (int)((char*)self + 0x14));
                }
                VramState_Save((char*)self->pairTables);
            }
            var13->RemoveTask(arg0->unknown_3dc8_);
            arg0->unknown_3dc8_ = -1;
            arg0->unknown_3dc8_ = var13->QueueLoadFile(data_ov005_0215e1ad, 0);
#else
            int mode = NormalizeField5_0200fb08((Struct0200fb08*)gs);
            int n = 0;
            const char* name = KeyTable_Get((Container020e0310*)self->container, 0x7d0);
            if (FindMatchingRecords0204684c((Rec020467f0*)file4, name, datas, count, sizes, 0) != 0) {
                VramState_Restore((char*)self->pairTables);
                for (int i = 0; i < count; i++) {
                    if (i == 0x23) {
                        if (mode == 2 || mode == 3) {
                            continue;
                        }
                    } else if (var32 == 0x24) {
                        if (var29 != 2) {
                            continue;
                        }
                    } else if (var32 == 0x25) {
                        if (var29 != 3) {
                            continue;
                        }
                    }
                    func_02047b30(arg0->unknown_1a70_ + var30 * 0x88, (int)var9[var32], var10[var32], (int)((char*)arg0 + 0x14));
                    var30++;
                }
                VramState_Save((char*)self->pairTables);
            }
            var13->RemoveTask(arg0->unknown_3dc8_);
            arg0->unknown_3dc8_ = -1;
            arg0->unknown_3dc8_ = var13->QueueLoadFileInGP2(data_ov005_0215cddd, data_ov005_0215cdf3, 0);
#endif
            arg0->unknown_3dc4_++;
        }
    } else if (arg0->unknown_3dc4_ == 5) {
        if (var13->GetTaskStatus(arg0->unknown_3dc8_) != 0) {
            var13->GetLoadedFileByID(arg0->unknown_3dc8_, &var7, &var8);
            arg0->unknown1_258_.Reset();
            func_ov023_021e1318((Struct_ov002_0215505c_2*)arg0->unknown_19e0_);
            func_ov023_021e133c(arg0->unknown_19e0_, &arg0->unknown1_258_, (int)var7, var8, 0, 0);
            var13->RemoveTask(arg0->unknown_3dc8_);
            arg0->unknown_3dc8_ = -1;
            arg0->unknown_3dc4_++;
        }
    } else {
        char* var33 = arg0->unknown_1a70_;
        volatile unsigned short* var34 = (volatile unsigned short*)0x4000008;
        var34[0] = (var34[0] & ~3) | 1;
        var34[1] = (var34[1] & ~3) | 3;
        var34[2] = (var34[2] & ~3) | 2;
        var34[3] = var34[3] & ~3;
        volatile unsigned int* var35 = (volatile unsigned int*)0x4000000;
        *var35 = (*var35 & ~0x1f00) | 0x1f00;

        arg0->unknown_1a34_ = var33;
        arg0->unknown_1a38_[0] = 0x8000;
        arg0->unknown_1a38_[1] = -0x3000;
        arg0->unknown_1a38_[2] = 0x3000;
        arg0->unknown_1a38_[3] = -0x3000;
        arg0->unknown_1a38_[4] = 0x3000;
        func_ov005_02154d18(&arg0->unknown_1a34_, 0x85000, 0x17000);
        func_ov005_02154d34(&arg0->unknown_1a34_, 0x85000, 0x17000);
        func_ov005_02154d50(&arg0->unknown_1a34_, 0x76000, 0x16000);
        func_ov005_02154d7c(&arg0->unknown_1a34_, 0x76000, 0x16000);
        arg0->unknown_1a6c_ = 0x5000;
        arg0->unknown_3db8_ = 0;
        arg0->unknown_3dcc_.unknown_0_ |= 0x400;
        func_ov005_021571d0(arg0);
        arg0->unknown_1a30_ = 0;
        arg0->unknown_3dcc_.unknown1_0_.unknown_0_2_ = 1;
        arg0->unknown_3dcc_.unknown1_0_.unknown_0_3_ = 1;

        GameState::GetInstance();
        char* var36 = (char*)GetGameResources();
        int var37 = *(int*)(func_ov017_021a193c((int*)(*(int*)(var36 + REGION_LAYOUT(0x34f8, 0x3708)))) + REGION_LAYOUT(0x4f8, 0x4fc));
        func_020dc7e8(5, (signed char)var37);
        arg0->unknown_244_.Reset();
        func_ov023_021dc134(arg0->unknown_1244_, arg0->unknown_2d90_, 0);
        arg0->unknown_19b8_ |= 0xd0;
        func_ov023_021dbfd0(arg0->unknown_1244_, &arg0->unknown_244_);
        arg0->unknown_128c_ = arg0->unknown_df4_;
        arg0->unknown_19be_ = var37;
        arg0->unknown_3dc4_ = 0xff;
        return 1;
    }
    return 0;
}
