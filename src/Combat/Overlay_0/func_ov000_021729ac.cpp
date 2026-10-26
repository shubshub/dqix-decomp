#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* OamManager_GetInstance(void);
extern "C" unsigned short GetSubBGVRAMBanks(void);
extern "C" void MapVRAMBanksToSubBG(int banks);
extern "C" char* CachedTextTable_GetInstance();
struct Struct020dfc40;
extern "C" void KeyTable_Reset(Struct020dfc40*);
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
extern "C" void ItemTable_Init(void* obj);
extern "C" void func_020dea64(void* list, void* alloc, void* data, unsigned int size, const void* entries, int count);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" char* func_ov017_021b8478(void* obj);
struct Struct_02070f98_2;
extern "C" struct Struct_ov000_021729ac* func_02070f98(Struct_02070f98_2*, int);
struct Struct_02070fe4;
extern "C" int func_02070fe4(Struct_02070fe4*);
extern "C" int ItemTable_LoadIds(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
struct Container020e0310;
extern "C" char* KeyTable_Get(Container020e0310*, int);
struct Obj0203c108;
extern "C" void CachedTextLabel_SetText(Obj0203c108*, char*);
extern "C" void* MessageSystem_GetInstance();
extern "C" void NameText_Clear(void* buf);
extern "C" void func_02046380(void* g);
extern "C" void MessageSystem_FormatText(void* a, int b, char* c, void* d, int e, int f, int g);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void SpriteContext_LoadFile(void* a, void* ptr, int val, void* d);
extern "C" void func_0205aed0(void*, char*, unsigned int, int);
extern "C" void func_0205af38(int, char*, int, int);
extern "C" int* BgVram_GetInstance();
extern "C" void BgVram_ResetWithBlankTile(int* obj, int a, int b);
extern "C" void BgVram_Reset(char*);
extern "C" void BgVram_Clear(char*);
extern "C" void func_ov000_02172944(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void func_ov000_02172978(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void* obj, int value);
struct BackgroundGraphics;
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
extern "C" void WindowPane_Init(void* obj);
extern "C" char* StandardStrings_Get(int key);
extern "C" void func_0204f914(void* obj, int a, short arg2, short arg3, short x1, short arg5);
extern "C" void func_0204f41c(void* obj, short x, short y, void* str, int d, int e, short* outA, short* outB, int zero);
extern "C" void Background_LoadFile(void* obj, void* data, SafeAllocator* alloc, int size);
extern "C" void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" void Background_FillRect(void* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
struct WindowPane;
extern "C" void WindowPane_AllocateBuffer(WindowPane*, SafeAllocator*, int, unsigned int);
struct WindowPane;
struct Struct_0205cf78;
extern "C" void Window_SetPanes(Struct_0205cf78*, WindowPane*, unsigned char);
extern "C" void func_020dc7e8(int a, int b);
struct Canvas0204e998;
extern "C" void func_0204c964(Canvas0204e998*);

struct Struct_ov000_021833ba {
    short value;
    short pad[2];
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
    char pad0[4];
    unsigned short f4;
    unsigned short unknown_6_;
};

struct Struct_ov000_021729ac_2 {
    char pad0[0x684];
    char list[4];
};

struct Struct_ov000_021729ac_3 {
    int f0;
    int f4;
    unsigned int lo : 24;
    unsigned int mode : 2;
    unsigned int hi : 6;
};

struct Struct_ov000_021729ac_4 {
    unsigned short priority : 2;
    unsigned short charBase : 4;
    unsigned short pad1 : 1;
    unsigned short colorMode : 1;
    unsigned short screenBase : 5;
    unsigned short bit13 : 1;
    unsigned short screenSize : 2;
};

struct Struct_ov000_021729ac_5 {
    char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad1[3];
};

struct Struct_ov000_021729ac_6 {
    char pad0[8];
    char* text;
    char pad1[0xa8 - 0xc];
    short width;
    short height;
    char pad2[0xe0 - 0xac];
};

struct Struct_ov000_021729ac_7 {
    char pad0[4];
    Struct_ov000_021729ac_5* list;
    char pad1[0xe0 - 8];
};

struct Struct_ov000_021729ac_8 {
    char pad0[0xb8];
    char container[0x18];
    char desc[2][0x18];
    char pad1[0x11c - 0x100];
    char records[0x158 - 0x11c];
    char* unknown_158_;
    char* unknown_15c_;
    char pad2[0x168 - 0x160];
    short unknown_168_;
    char pad3[2];
    unsigned char unknown_16c_;
    char pad4[3];
    char* unknown_170_;
    char* unknown_174_;
    void* buffer;
    char pad5[4];
    Struct_ov000_021729ac_4 unknown_180_;
    Struct_ov000_021729ac_4 unknown_182_;
    int unknown_184_;
    char linkHead[0x220 - 0x188];
    Struct_ov000_021729ac_5* unknown_220_;
    char pad6[0x23a - 0x224];
    unsigned char unknown_23a_;
    char unknown_23b_[0x284 - 0x23b];
    Struct_ov000_021729ac_7 elems[7];
    Struct_ov000_021729ac_5 lists[3];
    int unknown_904_;
    int state;
    int handle;

#if defined(jpn)
    char pad8[0x1b78 - 0x910];
#else
    char pad8[0x1a78 - 0x910];
#endif

    SafeAllocator allocs[6];

#if defined(jpn)
    char unknown_1bf0_[0x1c0c - 0x1bf0];
#else
    char unknown_1af0_[0x1b54 - 0x1af0];
#endif

#if defined(jpn)
    char entries[2][0x38];
#else
    char entries[2][0x18];
#endif

#if defined(jpn)
    char labels[5][0x38];
#else
    char labels[9][0x18];
#endif

#if defined(jpn)
    char pad10[0x1faa - 0x1d94];
#else
    char pad10[0x1d72 - 0x1c5c];
#endif

    unsigned short unknown_1d72_;
};

// USA: func_ov000_021729ac
extern "C" ARM int func_ov000_021729ac(Struct_ov000_021729ac_8* self) {
    unsigned short codes[0x28];
    char text[0x80];
    Struct_ov000_021729ac_6 canvas;
    Struct_ov000_021729ac_3 param;
    void* file1;
    unsigned int len1;
    void* file2;
    unsigned int len2;
    void* recData4;
    void* file4;
    unsigned int var10;
    int recSize4;
    void* recData6;
    void* file6;
    unsigned int var14;
    int recSize6;
    short outB;
    short outA;

    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    OamManager_GetInstance();

    if (self->state == 0) {
        self->unknown_904_ = (*(volatile unsigned int*)0x4001000 & 0x1f00) >> 8;
        self->unknown_184_ = GetSubBGVRAMBanks();
        MapVRAMBanksToSubBG(0x180);
        *(int*)OamManager_GetInstance() = 0;

#if defined(jpn)
        *(int*)(CachedTextTable_GetInstance() + 0x608) = 0x1d000;
#else
        *(int*)(CachedTextTable_GetInstance() + 0x508) = 0x18000;
#endif

#if defined(jpn)
        self->handle = loader->QueueLoadFile(data_ov000_02183ff5, 0);
#else
        self->handle = loader->QueueLoadFileInGP2(data_ov000_02183ff5, data_ov000_0218400f, 0);
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
            loader->RemoveTask(self->handle);
            self->handle = -1;

#if defined(jpn)
            self->handle = loader->QueueLoadGP1(g_itemDataArchive, 0);
#else
            self->handle = loader->QueueLoadFileInGP2(g_itemDataArchive, g_itemDataFile, 0);
#endif

            self->state++;
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
                Struct_ov000_021729ac_2* src = (Struct_ov000_021729ac_2*)func_ov017_021b8478(*(void**)((char*)GetGameResources() + 0x3000 + 0x508));
#else
                Struct_ov000_021729ac_2* src = (Struct_ov000_021729ac_2*)func_ov017_021b8478(*(void**)((char*)GetGameResources() + 0x3000 + 0x718));
#endif

                if (src != 0) {
                    void* list = src->list;
                    for (int i = 0; i < func_02070fe4((Struct_02070fe4*)list); i++) {
                        if (n > sizeof(codes) / sizeof(codes[0])) {
                            break;
                        }
                        Struct_ov000_021729ac* elem = func_02070f98((Struct_02070f98_2*)list, i);
                        if (elem != 0) {
                            codes[n++] = elem->f4;
                            codes[n++] = elem->unknown_6_;
                        }
                    }
                }
                ItemTable_LoadIds(self->desc[1], &self->allocs[5], file2, len2, codes, n);
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;
            CachedTextLabel_SetText((Obj0203c108*)self->entries[0], KeyTable_Get((Container020e0310*)self->container, 0x754e));
            CachedTextLabel_SetText((Obj0203c108*)self->entries[1], KeyTable_Get((Container020e0310*)self->container, 0x7550));

#if defined(jpn)
            for (int i = 0; i < 5; i++) {
                CachedTextLabel_SetText((Obj0203c108*)self->labels[i], KeyTable_Get((Container020e0310*)self->container, data_ov000_02183418[i]));
            }
#else
            void* g = MessageSystem_GetInstance();
            for (int i = 0; i < 9; i++) {
                __clear(text, sizeof(text));
                NameText_Clear(&param);
                if (i >= 5) {
                    param.mode = 1;
                }
                func_02046380(g);
                int key = data_ov000_02183418[i];
                *(void**)g = &param;
                MessageSystem_FormatText(g, 0xa, KeyTable_Get((Container020e0310*)self->container, key), text, 0x100, 0, 0);
                CachedTextLabel_SetText((Obj0203c108*)self->labels[i], text);
            }

#endif
            self->state++;
        }
    } else if (self->state == 3) {
        if (self->unknown_174_ == 0 || self->unknown_170_ == 0) {
            self->state = 3;
        }

#if defined(jpn)

#else
        self->unknown_16c_ = 1;
#endif

        self->unknown_15c_ = self->unknown_170_;

#if defined(jpn)
        self->unknown_168_ = 0x20;
#else
        self->unknown_168_ = 0x28;
#endif

        self->unknown_158_ = self->unknown_174_;

#if defined(jpn)
        self->handle = loader->QueueLoadFile(data_ov000_02184020, 0);
#else
        self->handle = loader->QueueLoadFileInGP2(data_ov000_02184020, data_ov000_02184035, 0);
#endif

        self->state++;
    } else if (self->state == 4) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file4, &var10);
            int count = Pac_CountFiles((PacRecord*)file4);
            self->allocs[0].Reset();
            for (int i = 0; i < count; i++) {
                void* rec = Pac_GetFile((PacRecord*)file4, i, &recData4, &recSize4);
                if (rec != 0) {
                    SpriteContext_LoadFile(self->records, rec, recSize4, &self->allocs[0]);
                }
            }

#if defined(jpn)
            func_0205aed0(self->records, self->unknown_170_, (unsigned short)count, 0x40);
#else
            func_0205aed0(self->records, self->unknown_170_, (unsigned short)count, 0x44);
#endif

            func_0205af38((int)self->records, self->unknown_170_ + 0x2a8, 1, 1);
            func_0205af38((int)self->records, self->unknown_170_ + 0x2d0, 1, 1);
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->state++;
        }
    } else if (self->state == 5) {
        int* bank = BgVram_GetInstance();
        BgVram_ResetWithBlankTile(bank, 1, 0);
        BgVram_ResetWithBlankTile(bank, 1, 1);
        BgVram_Reset((char*)bank);
        BgVram_Clear((char*)bank);
        func_ov000_02172944(0, self->unknown_180_.colorMode, 5, self->unknown_180_.charBase, self->unknown_182_.bit13);
        func_ov000_02172978(0, self->unknown_182_.colorMode, 6, self->unknown_182_.charBase, self->unknown_182_.bit13);
        *(volatile unsigned short*)0x400100c = (*(volatile unsigned short*)0x400100c & 0x43) | 0x704;
        self->allocs[3].Reset();

        Struct_ov000_021729ac_5* list = &self->lists[0];
        Background_SetMapSize((unsigned char*)list, 0);
        list->lo = 1;
        list->hi = 0;
        Background_SetPriority(list, 2);
        Background_AllocateMap((BackgroundGraphics*)list, &self->allocs[3]);

        list = &self->lists[1];
        Background_SetMapSize((unsigned char*)list, 0);
        list->lo = 1;
        list->hi = 1;
        Background_SetPriority(list, 3);
        Background_AllocateMap((BackgroundGraphics*)list, &self->allocs[3]);

#if defined(jpn)
        Background_AllocateScreens((BackgroundGraphics*)list, 29, &self->allocs[3]);
#else
        Background_AllocateScreens((BackgroundGraphics*)list, 10, &self->allocs[3]);
#endif

        list = &self->lists[2];
        Background_SetMapSize((unsigned char*)list, 0);
        list->lo = 1;
        list->hi = 2;
        Background_SetPriority(list, 0);
        Background_AllocateMap((BackgroundGraphics*)list, &self->allocs[3]);

        self->handle = loader->QueueLoadFile(data_ov000_02184046, 0);
        self->state++;
    } else if (self->state == 6) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file6, &var14);
            int count = Pac_CountFiles((PacRecord*)file6);
            for (int i = 0; i < count; i++) {
                void* rec = Pac_GetFile((PacRecord*)file6, i, &recData6, &recSize6);
                if (rec != 0) {
#if !defined(jpn)
                    if (i == 0) {
                        WindowPane_Init(&canvas);
                        canvas.width = 0x20;
                        canvas.height = 0x20;
                        canvas.text = (char*)rec + 0x10;
                        char* label1;
                        char* label0 = StandardStrings_Get(0xc9);
                        label1 = StandardStrings_Get(0xca);
                        short x;
                        short var39;
                        short var40;
                        for (int k = 0; k < 2; k++) {
                            x = data_ov000_021833ba[k].value;
                            var39 = data_ov000_021833bc[k].value;
                            var40 = data_ov000_021833be[k].value;
                            func_0204f914(&canvas, 3, x, var39, x + 0x10, var39 + 8);
                            func_0204f41c(&canvas, x + 1, var39 - 2, label0, 8, 2, &outA, &outB, 0);
                            func_0204f41c(&canvas, x, var39 - 2, label0, 8, 0xa, &outA, &outB, 0);
                            func_0204f914(&canvas, 3, x, var40, x + 0x10, var40 + 8);
                            func_0204f41c(&canvas, x + 1, var40 - 2, label1, 8, 2, &outA, &outB, 0);
                            func_0204f41c(&canvas, x, var40 - 2, label1, 8, 0xa, &outA, &outB, 0);
                        }
                    }
#endif
                    Struct_ov000_021729ac_5* target = &self->lists[1];
                    if (i == count - 1) {
                        target = &self->lists[2];
                    }
                    Background_LoadFile(target, rec, &self->allocs[3], recSize6);
                }
            }
            Background_DrawScreen((BackgroundGraphics*)&self->lists[1], 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
            Background_UploadMap((BackgroundGraphics*)&self->lists[1], 0);
            Background_FillRect(&self->lists[0], 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((BackgroundGraphics*)&self->lists[0], 0);
            Background_DrawScreen((BackgroundGraphics*)&self->lists[2], 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
            Background_UploadMap((BackgroundGraphics*)&self->lists[2], 0);

            self->allocs[2].Reset();
            self->buffer = self->allocs[2].Allocate(0x5c00);
            WindowPane_AllocateBuffer((WindowPane*)&self->elems[0], &self->allocs[2], (int)self->buffer, 0x30c);
            WindowPane_AllocateBuffer((WindowPane*)&self->elems[1], &self->allocs[2], (int)self->buffer, 0x240);
            WindowPane_AllocateBuffer((WindowPane*)&self->elems[2], &self->allocs[2], (int)self->buffer, 0x240);
            WindowPane_AllocateBuffer((WindowPane*)&self->elems[3], &self->allocs[2], (int)self->buffer, 0x200);
            WindowPane_AllocateBuffer((WindowPane*)&self->elems[4], &self->allocs[2], (int)self->buffer, 0x200);
            WindowPane_AllocateBuffer((WindowPane*)&self->elems[5], &self->allocs[2], (int)self->buffer, 0x200);
            WindowPane_AllocateBuffer((WindowPane*)&self->elems[6], &self->allocs[2], (int)self->buffer, 0x200);
            for (int j = 0; j < 7; j++) {
                self->elems[j].list = &self->lists[2];
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->unknown_220_ = &self->lists[2];
            self->unknown_23a_ = 1;
            Window_SetPanes((Struct_0205cf78*)self->linkHead, (WindowPane*)self->elems, 7);
            self->state++;
            self->unknown_1d72_ |= 0x40;
        }
    } else if (self->state == 7) {
        func_020dc7e8(0, -1);
        *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1700;
        *(volatile unsigned short*)0x4001050 = 0;
        func_0204c964((Canvas0204e998*)&self->elems[0]);
        return 1;
    }
    return 0;
}
