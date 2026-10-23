#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* func_0203bd08(void);
extern "C" unsigned short GetSubBGVRAMBanks(void);
extern "C" void MapVRAMBanksToSubBG(int banks);
char* GetGlobalPtr02105244_0203bd14();
struct Struct020dfc40;
void KeyTable_Reset(Struct020dfc40*);
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
void ItemTable_Init(void* obj);
extern "C" void func_020dea64(void* list, void* alloc, void* data, unsigned int size, const void* entries, int count);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" char* func_ov017_021b8478(void* obj);
struct List02070f98;
struct Elem021729ac* GetElementIfInBounds(List02070f98*, int);
struct Struct02070fe4;
int GetElementCount02070fe4(Struct02070fe4*);
extern "C" int ItemTable_LoadIds(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
struct Container020e0310;
char* KeyTable_Get(Container020e0310*, int);
struct Obj0203c108;
void SwapGlobalEntry0203c108(Obj0203c108*, char*);
void* GetGlobalField0x1c020421a0();
void Clear12Bytes020e46c4(void* buf);
extern "C" void func_02046380(void* g);
extern "C" void func_02046608(void* a, int b, char* c, void* d, int e, int f, int g);
struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900*);
struct Rec020467f0;
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);
void WrapAddByteField0x22_0205aed0(void*, char*, unsigned int, int);
void SetBitfieldStoreBytes0205af38(int, char*, int, int);
int* GetData02105254_0203b628();
void SetupBankModeAndTransfer_0203b678(int* obj, int a, int b);
void TailForward0203b66c(char*);
void ClearThreeRegions0203b634(char*);
void ConfigureSubBg0Control_02172944(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
void ConfigureSubBg1Control_02172978(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void* obj, int value);
struct AllocTarget0204b12c;
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
void Background_AllocateScreens(Foo0204af38*, int, SafeAllocator*);
extern "C" void func_0204c684(void* obj);
char* CallFunc020e0434With02153694_020e51cc(int key);
extern "C" void func_0204f914(void* obj, int a, short x0, short y0, short x1, short y1);
extern "C" void func_0204f41c(void* obj, short x, short y, void* str, int d, int e, short* outA, short* outB, int zero);
extern "C" void Background_LoadFile(void* obj, void* data, SafeAllocator* alloc, int size);
struct Obj0204b8d0;
void Background_DrawScreen(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
struct List0204b0e8;
void Background_UploadMap(List0204b0e8*, void*);
extern "C" void Background_FillRect(void* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
struct Obj0204c7a8;
void WindowPane_AllocateBuffer(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
struct Elem_0205cf78;
struct Struct_0205cf78;
void Window_SetPanes(Struct_0205cf78*, Elem_0205cf78*, unsigned char);
extern "C" void func_020dc7e8(int a, int b);
struct Canvas0204e998;
void InitAndFillIndexBuffer0204c964(Canvas0204e998*);

struct Struct_ov000_021833ba {
    short unknown_0_;
    short unknown_2_[2];
};

extern char data_ov000_02183ff5[];
extern char data_ov000_0218400f[];
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern char data_ov000_02183302[];
extern const short data_ov000_02183418[];
extern char data_ov000_02184035[];
extern char data_ov000_02184020[];
extern char data_ov000_02184046[];
extern Struct_ov000_021833ba data_ov000_021833ba[];
extern Struct_ov000_021833ba data_ov000_021833bc[];
extern Struct_ov000_021833ba data_ov000_021833be[];

struct Struct_ov000_021729ac {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_ov000_021729ac_2 {
    char unknown_0_[0x684];
    char unknown_684_[4];
};

struct Struct_ov000_021729ac_3 {
    int unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 24;
    unsigned int unknown_b_0_ : 2;
    unsigned int unknown_b_2_ : 6;
};

struct Struct_ov000_021729ac_4 {
    unsigned short unknown_0_0_ : 2;
    unsigned short unknown_0_2_ : 4;
    unsigned short unknown_0_6_ : 1;
    unsigned short unknown_0_7_ : 1;
    unsigned short unknown_1_0_ : 5;
    unsigned short unknown_1_5_ : 1;
    unsigned short unknown_1_6_ : 2;
};

struct Struct_ov000_021729ac_5 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};

struct Struct_ov000_021729ac_6 {
    char unknown_0_[8];
    char* unknown_8_;
    char unknown_c_[0xa8 - 0xc];
    short unknown_a8_;
    short unknown_aa_;
    char unknown_ac_[0xe0 - 0xac];
};

struct Struct_ov000_021729ac_7 {
    char unknown_0_[4];
    Struct_ov000_021729ac_5* unknown_4_;
    char unknown_8_[0xe0 - 8];
};

struct Struct_ov000_021729ac_8 {
    char unknown_0_[0xb8];
    char unknown_b8_[0x18];
    char unknown_d0_[2][0x18];
    char unknown_100_[0x11c - 0x100];
    char unknown_11c_[0x158 - 0x11c];
    char* unknown_158_;
    char* unknown_15c_;
    char unknown_160_[0x168 - 0x160];
    short unknown_168_;
    char unknown_16a_[2];
    unsigned char unknown_16c_;
    char unknown_16d_[3];
    char* unknown_170_;
    char* unknown_174_;
    void* unknown_178_;
    char unknown_17c_[4];
    Struct_ov000_021729ac_4 unknown_180_;
    Struct_ov000_021729ac_4 unknown_182_;
    int unknown_184_;
    char unknown_188_[0x220 - 0x188];
    Struct_ov000_021729ac_5* unknown_220_;
    char unknown_224_[0x23a - 0x224];
    unsigned char unknown_23a_;
    char unknown_23b_[0x284 - 0x23b];
    Struct_ov000_021729ac_7 unknown_284_[7];
    Struct_ov000_021729ac_5 unknown_8a4_[3];
    int unknown_904_;
    int unknown_908_;
    int unknown_90c_;

#if defined(jpn)
    char unknown_910_[0x1b78 - 0x910];
#else
    char unknown1_910_[0x1a78 - 0x910];
#endif

    SafeAllocator unknown_1a78_[6];

#if defined(jpn)
    char unknown_1bf0_[0x1c0c - 0x1bf0];
#else
    char unknown_1af0_[0x1b54 - 0x1af0];
#endif

#if defined(jpn)
    char unknown_1b54_[2][0x38];
#else
    char unknown_1b54_[2][0x18];
#endif

#if defined(jpn)
    char unknown_1c7c_[5][0x38];
#else
    char unknown_1b84_[9][0x18];
#endif

#if defined(jpn)
    char unknown_1d94_[0x1faa - 0x1d94];
#else
    char unknown_1c5c_[0x1d72 - 0x1c5c];
#endif

    unsigned short unknown_1d72_;
};

// USA: func_ov000_021729ac
extern "C" ARM int func_ov000_021729ac(Struct_ov000_021729ac_8* arg0) {
    unsigned short var0[0x28];
    char var1[0x80];
    Struct_ov000_021729ac_6 var2;
    Struct_ov000_021729ac_3 var3;
    void* var4;
    unsigned int var5;
    void* var6;
    unsigned int var7;
    void* var8;
    void* var9;
    unsigned int var10;
    int var11;
    void* var12;
    void* var13;
    unsigned int var14;
    int var15;
    short var16;
    short var17;

    GameState::GetInstance();
    BackgroundLoader* var18 = BackgroundLoader::GetInstance();
    func_0203bd08();

    if (arg0->unknown_908_ == 0) {
        arg0->unknown_904_ = (*(volatile unsigned int*)0x4001000 & 0x1f00) >> 8;
        arg0->unknown_184_ = GetSubBGVRAMBanks();
        MapVRAMBanksToSubBG(0x180);
        *(int*)func_0203bd08() = 0;

#if defined(jpn)
        *(int*)(func_0203bd14() + 0x608) = 0x1d000;
#else
        *(int*)(func_0203bd14() + 0x508) = 0x18000;
#endif

#if defined(jpn)
        arg0->unknown_90c_ = var18->QueueLoadFile(data_ov000_02183ff5, 0);
#else
        arg0->unknown_90c_ = var18->QueueLoadFileInGP2(data_ov000_02183ff5, data_ov000_0218400f, 0);
#endif

        self->state++;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file1, &len1);
            if (file1 != 0) {
                self->allocs[1].Reset();
                KeyTable_Reset((Struct020dfc40*)self->container);
                KeyTable_Load(self->container, &self->allocs[1], file1, len1);
            }
            var18->RemoveTask(arg0->unknown_90c_);
            arg0->unknown_90c_ = -1;

#if defined(jpn)
            self->handle = loader->QueueLoadGP1(g_itemDataArchive, 0);
#else
            self->handle = loader->QueueLoadFileInGP2(g_itemDataArchive, g_itemDataFile, 0);
#endif

            arg0->unknown_908_++;
        }
    } else if (self->state == 2) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file2, &len2);
            if (file2 != 0) {
                self->allocs[4].Reset();
                ItemTable_Init(self->desc[0]);
                func_020dea64(self->desc[0], &self->allocs[4], file2, len2, data_ov000_02183302, 3);
                self->allocs[5].Reset();
                ItemTable_Init(self->desc[1]);
                __clear(codes, sizeof(codes));
                unsigned short n = 0;

#if defined(jpn)
                Struct_ov000_021729ac_2* var20 = (Struct_ov000_021729ac_2*)func_ov017_021b8478(*(void**)((char*)GetGameResources() + 0x3000 + 0x508));
#else
                Struct_ov000_021729ac_2* var20 = (Struct_ov000_021729ac_2*)func_ov017_021b8478(*(void**)((char*)GetGameResources() + 0x3000 + 0x718));
#endif

                if (var20 != 0) {
                    void* var21 = var20->unknown_684_;
                    for (int var22 = 0; var22 < func_02070fe4((Struct_02070fe4*)var21); var22++) {
                        if (var19 > sizeof(var0) / sizeof(var0[0])) {
                            break;
                        }
                        Struct_ov000_021729ac* var23 = func_02070f98((Struct_02070f98_2*)var21, var22);
                        if (var23 != 0) {
                            var0[var19++] = var23->unknown_4_;
                            var0[var19++] = var23->unknown_6_;
                        }
                    }
                }
                ItemTable_LoadIds(self->desc[1], &self->allocs[5], file2, len2, codes, n);
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;
            SwapGlobalEntry0203c108((Obj0203c108*)self->entries[0], KeyTable_Get((Container020e0310*)self->container, 0x754e));
            SwapGlobalEntry0203c108((Obj0203c108*)self->entries[1], KeyTable_Get((Container020e0310*)self->container, 0x7550));

#if defined(jpn)
            for (int i = 0; i < 5; i++) {
                SwapGlobalEntry0203c108((Obj0203c108*)self->labels[i], KeyTable_Get((Container020e0310*)self->container, data_ov000_02183418[i]));
            }
#else
            void* var25 = func_020421a0();
            for (int var26 = 0; var26 < 9; var26++) {
                __clear(var1, sizeof(var1));
                func_020e46c4(&var3);
                if (var26 >= 5) {
                    var3.unknown_b_0_ = 1;
                }
                func_02046380(g);
                int key = data_ov000_02183418[i];
                *(void**)g = &param;
                func_02046608(g, 0xa, KeyTable_Get((Container020e0310*)self->container, key), text, 0x100, 0, 0);
                SwapGlobalEntry0203c108((Obj0203c108*)self->labels[i], text);
            }

#endif
            arg0->unknown_908_++;
        }
    } else if (arg0->unknown_908_ == 3) {
        if (arg0->unknown_174_ == 0 || arg0->unknown_170_ == 0) {
            arg0->unknown_908_ = 3;
        }

#if defined(jpn)

#else
        arg0->unknown_16c_ = 1;
#endif

        arg0->unknown_15c_ = arg0->unknown_170_;

#if defined(jpn)
        arg0->unknown_168_ = 0x20;
#else
        arg0->unknown_168_ = 0x28;
#endif

        arg0->unknown_158_ = arg0->unknown_174_;

#if defined(jpn)
        arg0->unknown_90c_ = var18->QueueLoadFile(data_ov000_02184020, 0);
#else
        arg0->unknown_90c_ = var18->QueueLoadFileInGP2(data_ov000_02184020, data_ov000_02184035, 0);
#endif

        self->state++;
    } else if (self->state == 4) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file4, &len4);
            int count = Pac_CountFiles((ActiveEntry02046900*)file4);
            self->allocs[0].Reset();
            for (int i = 0; i < count; i++) {
                void* rec = Pac_GetFile((Rec020467f0*)file4, i, &recData4, &recSize4);
                if (rec != 0) {
                    SpriteContext_LoadFile(self->records, rec, recSize4, &self->allocs[0]);
                }
            }

#if defined(jpn)
            func_0205aed0(arg0->unknown_11c_, arg0->unknown_170_, (unsigned short)var28, 0x40);
#else
            func_0205aed0(arg0->unknown_11c_, arg0->unknown_170_, (unsigned short)var28, 0x44);
#endif

            func_0205af38((int)arg0->unknown_11c_, arg0->unknown_170_ + 0x2a8, 1, 1);
            func_0205af38((int)arg0->unknown_11c_, arg0->unknown_170_ + 0x2d0, 1, 1);
            var18->RemoveTask(arg0->unknown_90c_);
            arg0->unknown_90c_ = -1;
            arg0->unknown_908_++;
        }
    } else if (arg0->unknown_908_ == 5) {
        int* var31 = func_0203b628();
        func_0203b678(var31, 1, 0);
        func_0203b678(var31, 1, 1);
        func_0203b66c((char*)var31);
        func_0203b634((char*)var31);
        func_ov000_02172944(0, arg0->unknown_180_.unknown_0_7_, 5, arg0->unknown_180_.unknown_0_2_, arg0->unknown_182_.unknown_1_5_);
        func_ov000_02172978(0, arg0->unknown_182_.unknown_0_7_, 6, arg0->unknown_182_.unknown_0_2_, arg0->unknown_182_.unknown_1_5_);
        *(volatile unsigned short*)0x400100c = (*(volatile unsigned short*)0x400100c & 0x43) | 0x704;
        arg0->unknown_1a78_[3].Reset();

        List021729ac* list = &self->lists[0];
        Background_SetMapSize((unsigned char*)list, 0);
        list->lo = 1;
        list->hi = 0;
        Background_SetPriority(list, 2);
        Background_AllocateMap((AllocTarget0204b12c*)list, &self->allocs[3]);

        list = &self->lists[1];
        Background_SetMapSize((unsigned char*)list, 0);
        list->lo = 1;
        list->hi = 1;
        Background_SetPriority(list, 3);
        Background_AllocateMap((AllocTarget0204b12c*)list, &self->allocs[3]);

#if defined(jpn)
        Background_AllocateScreens((Foo0204af38*)list, 29, &self->allocs[3]);
#else
        Background_AllocateScreens((Foo0204af38*)list, 10, &self->allocs[3]);
#endif

        list = &self->lists[2];
        Background_SetMapSize((unsigned char*)list, 0);
        list->lo = 1;
        list->hi = 2;
        Background_SetPriority(list, 0);
        Background_AllocateMap((AllocTarget0204b12c*)list, &self->allocs[3]);

        self->handle = loader->QueueLoadFile(data_ov000_02184046, 0);
        self->state++;
    } else if (self->state == 6) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file6, &len6);
            int count = Pac_CountFiles((ActiveEntry02046900*)file6);
            for (int i = 0; i < count; i++) {
                void* rec = Pac_GetFile((Rec020467f0*)file6, i, &recData6, &recSize6);
                if (rec != 0) {
#if !defined(jpn)
                    if (var34 == 0) {
                        func_0204c684(&var2);
                        var2.unknown_a8_ = 0x20;
                        var2.unknown_aa_ = 0x20;
                        var2.unknown_8_ = (char*)var35 + 0x10;
                        char* var36;
                        char* var37 = func_020e51cc(0xc9);
                        var36 = func_020e51cc(0xca);
                        short var38;
                        short var39;
                        short var40;
                        for (int var41 = 0; var41 < 2; var41++) {
                            var38 = data_ov000_021833ba[var41].unknown_0_;
                            var39 = data_ov000_021833bc[var41].unknown_0_;
                            var40 = data_ov000_021833be[var41].unknown_0_;
                            func_0204f914(&var2, 3, var38, var39, var38 + 0x10, var39 + 8);
                            func_0204f41c(&var2, var38 + 1, var39 - 2, var37, 8, 2, &var17, &var16, 0);
                            func_0204f41c(&var2, var38, var39 - 2, var37, 8, 0xa, &var17, &var16, 0);
                            func_0204f914(&var2, 3, var38, var40, var38 + 0x10, var40 + 8);
                            func_0204f41c(&var2, var38 + 1, var40 - 2, var36, 8, 2, &var17, &var16, 0);
                            func_0204f41c(&var2, var38, var40 - 2, var36, 8, 0xa, &var17, &var16, 0);
                        }
                    }
#endif
                    Struct_ov000_021729ac_5* var42 = &arg0->unknown_8a4_[1];
                    if (var34 == var33 - 1) {
                        var42 = &arg0->unknown_8a4_[2];
                    }
                    Background_LoadFile(target, rec, &self->allocs[3], recSize6);
                }
            }
            Background_DrawScreen((Obj0204b8d0*)&self->lists[1], 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
            Background_UploadMap((List0204b0e8*)&self->lists[1], 0);
            Background_FillRect(&self->lists[0], 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((List0204b0e8*)&self->lists[0], 0);
            Background_DrawScreen((Obj0204b8d0*)&self->lists[2], 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
            Background_UploadMap((List0204b0e8*)&self->lists[2], 0);

            self->allocs[2].Reset();
            self->buffer = self->allocs[2].Allocate(0x5c00);
            WindowPane_AllocateBuffer((Obj0204c7a8*)&self->elems[0], &self->allocs[2], (int)self->buffer, 0x30c);
            WindowPane_AllocateBuffer((Obj0204c7a8*)&self->elems[1], &self->allocs[2], (int)self->buffer, 0x240);
            WindowPane_AllocateBuffer((Obj0204c7a8*)&self->elems[2], &self->allocs[2], (int)self->buffer, 0x240);
            WindowPane_AllocateBuffer((Obj0204c7a8*)&self->elems[3], &self->allocs[2], (int)self->buffer, 0x200);
            WindowPane_AllocateBuffer((Obj0204c7a8*)&self->elems[4], &self->allocs[2], (int)self->buffer, 0x200);
            WindowPane_AllocateBuffer((Obj0204c7a8*)&self->elems[5], &self->allocs[2], (int)self->buffer, 0x200);
            WindowPane_AllocateBuffer((Obj0204c7a8*)&self->elems[6], &self->allocs[2], (int)self->buffer, 0x200);
            for (int j = 0; j < 7; j++) {
                self->elems[j].list = &self->lists[2];
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->linkList = &self->lists[2];
            self->linkFlag = 1;
            Window_SetPanes((Struct_0205cf78*)self->linkHead, (Elem_0205cf78*)self->elems, 7);
            self->state++;
            self->f1d72 |= 0x40;
        }
    } else if (arg0->unknown_908_ == 7) {
        func_020dc7e8(0, -1);
        *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1700;
        *(volatile unsigned short*)0x4001050 = 0;
        func_0204c964((Struct_0204c87c*)&arg0->unknown_284_[0]);
        return 1;
    }
    return 0;
}
