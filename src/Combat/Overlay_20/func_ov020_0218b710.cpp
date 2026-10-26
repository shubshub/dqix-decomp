#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Input/Input.h"

#if defined(jpn)
#define data_ov020_0218dbdc data_ov020_0218e41c
#define data_ov020_0218dbef data_ov020_0218e42f
#define data_ov020_0218dbf5 data_ov020_0218e435
#define data_ov020_0218dbfc data_ov020_0218e43d
#define data_ov020_0218dc08 data_ov020_0218e449
#define data_ov020_0218dc1b data_ov020_0218e45c
#define data_ov020_0218dc2b data_ov020_0218e46c
#define data_ov020_0218dc3f data_ov020_0218e480
#define data_ov020_0218dc55 data_ov020_0218e496
#define data_ov020_0218dc65 data_ov020_0218e4a6
#define data_ov020_0218dc72 data_ov020_0218e4b3
#define data_ov020_0218dc82 data_ov020_0218e4fa
#define data_ov020_0218dc91 data_ov020_0218e54f
#define data_ov020_0218da90 data_ov020_0218e2e0
#define data_ov020_0218d9b0 data_ov020_0218e200
#endif

struct Struct_ov020_0218b710;
struct Struct_ov020_0218b710_2;
struct InitTarget0205cfd4;
struct BackgroundGraphics;
struct PacRecord;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;
struct Cont0205d228;
struct Cont0205d274;
struct Obj0205d2bc;
struct Foo0207df50;
struct CombatSlots02045cac;
struct Struct_0205bcdc;
struct Obj_0205e8ec;
struct Actor0209c3b4;
struct Obj0203bdb0;
struct Struct_ov020_0218b710_3;

extern "C" void OS_WaitVBlankIntr();
extern "C" void GXx_SetMasterBrightness_(short* out, int value);
extern "C" int func_0201201c(void* obj);
extern "C" void func_02012010(void* obj, int value);
extern "C" unsigned char func_0200fb9c(char* obj);
extern "C" void func_0200fb94(char* obj, unsigned char value);
extern "C" void func_02012028(void* obj, unsigned char value);
extern "C" void func_020c38d4();
extern "C" void func_ov020_0218d7ac(Struct_ov020_0218b710* obj, int target, int frames);
extern "C" void func_ov020_0218d800(Struct_ov020_0218b710_2* obj, int target, int frames);
extern "C" void func_020d86d0(int a, int b);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void Window_Init(InitTarget0205cfd4* obj);
extern "C" void Background_Init(BackgroundGraphics* list);
extern "C" void Background_SetMapSize(unsigned char* obj, int value);
extern "C" void Background_AllocateMap(BackgroundGraphics* obj, SafeAllocator* alloc);
extern "C" void Background_SetScroll(BackgroundGraphics* obj, int a, int b);
extern "C" int Pac_CountFiles(PacRecord* entries);
extern "C" void* Pac_GetFile(PacRecord* recs, int index, void** outField, int* outSize);
extern "C" void Background_UploadMap(BackgroundGraphics* list, void* arg);
extern "C" void WindowPane_AllocateBuffer(WindowPane* obj, SafeAllocator* alloc, int buf, unsigned int size);
extern "C" void Window_SetPanes(Struct_0205cf78* obj, WindowPane* elems, unsigned char flag);
extern "C" char* MessageSystem_GetInstance();
extern "C" int func_02041a90(char* text, int x, int y);
extern "C" int Text_Append(char* text, const char* str);
extern "C" int func_02042084(char* text, char* label, int width, int flags);
extern "C" void Window_DrawPanes(Cont0205d228* obj);
extern "C" void Window_FlushLayers(Cont0205d274* obj);
extern "C" void Window_TransferLayers(Obj0205d2bc* obj);
extern "C" void func_020bbcb4();
extern "C" void Main_UpdateLidAndInput();
void LockStagedTextureVRAMCopying();
extern "C" void func_020bb48c(unsigned int mode, int arg1);
extern "C" void func_020bb780(void* arg, int flag);
void UpdateVRAMStagingVRAMBanks();
void UnlockStagedTextureVRAMCopying();
extern "C" void func_020440a4(void* obj);
extern "C" void VramState_Rewind(Foo0207df50* obj);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
extern "C" void MessageSystem_ResetGlyphs(CombatSlots02045cac* slots);
extern "C" void func_0205c790(char* obj);
extern "C" int func_020ab9c0(int flag);
extern "C" void func_0205cb74(char* obj, int entry);
extern "C" void func_0204359c(void* obj, int value);
extern "C" void GridCursor_SelectIfValid(Struct_0205bcdc* obj, int index);
extern "C" void OamManager_Init(char* ctx);
extern "C" void func_0205e8ec(Obj_0205e8ec* obj);
extern "C" void func_0209c3b4(Actor0209c3b4* actor, int state);
extern "C" void G3X_Reset();
extern "C" void OamManager_FlushBuffers(void* oam);
extern "C" void OamManager_UploadBuffers(Obj0203bdb0* obj);
extern "C" void func_ov020_0218d8d8(Struct_ov020_0218b710_3* obj);

extern "C" int func_ov020_0218d898(void* obj);
extern "C" void func_ov020_0218d644(void* obj);
extern "C" void func_ov020_0218d854(void* obj);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
extern "C" void func_ov020_0218cd98(void* obj);
extern "C" void func_ov020_0218cf8c(void* obj);
extern "C" void func_ov020_0218d32c(void* obj, int mode);
extern "C" void func_ov020_0218c98c(void* obj);
extern "C" void func_ov020_0218c7f0(char* obj, int a, int count);
extern "C" void func_ov020_0218c840(void* obj);
extern "C" void WindowPane_Init(void* obj);
extern "C" void Background_SetPriority(void* obj, int a);
extern "C" void Background_LoadFile(void* list, void* rec, SafeAllocator* alloc, int size);
extern "C" void Background_FillRect(void* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
#if defined(jpn)
extern "C" void Window_OpenPane(void* obj, char* text, int, int, int, int, int);
#else
extern "C" void Window_OpenPane(void* obj, char* text, int, int, int, int, int, int);
#endif
extern "C" void Window_Update(void* obj, int a);
extern "C" void VramState_Reserve(void* obj, int a, int b);
extern "C" void func_02042c68(char* g);
extern "C" void MessageSystem_Stop(char* g);
extern "C" void func_020432c4(char* g);
extern "C" void func_0205cc50(void* obj, int a, int b);
#if defined(jpn)
extern "C" void func_0205dfa8(void* obj);
#endif
extern "C" void GridCursor_SetSelectedIndex(void* obj, int a);
extern "C" void func_02043368(char* g);
extern "C" void func_020439b0(char* g, int a);
extern "C" char* OamManager_GetInstance(void);
extern "C" void G3X_ResetMtxStack(void);
extern "C" void func_020bbd9c(void);
extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void MapVRAMBanksToMainObj(int);
extern "C" void MapVRAMBanksToTextureImage(int);
extern "C" void MapVRAMBanksToTexturePalette(int);

extern AllocatorUnion g_mainAllocator;
extern char g_sePlayer[];
extern char g_bgmPlayer[];
extern char data_ov020_0218dbdc[];
extern char data_ov020_0218dbef[];
extern char data_ov020_0218dbf5[];
extern char data_ov020_0218dbfc[];
extern char data_ov020_0218dc08[];
extern char data_ov020_0218dc1b[];
extern char data_ov020_0218dc2b[];
extern char data_ov020_0218dc3f[];
extern char data_ov020_0218dc55[];
extern char data_ov020_0218dc65[];
extern char data_ov020_0218dc72[];
extern char data_ov020_0218dc82[];
extern char data_ov020_0218dc91[];
extern char data_ov020_0218da90[];
extern char data_ov020_0218d9b0[];

struct Struct_ov020_0218b710_4 {
    unsigned char low : 4;
    unsigned char high : 4;
};

struct Struct_ov020_0218b710_5 {
    int state;
    int frame;
    char pad08[0xc - 0x8];
    char big[0x2c - 0xc];
    char sub2c[0x7c - 0x2c];
    char sub7c[0xbc - 0x7c];
    unsigned char unknown_bc_;
    unsigned char unknown_bd_;
    char unknown_be_[0xc0 - 0xbe];
    short posX;
    short unknown_c2_;
    short width;
    short height;
#if defined(jpn)
    char unknown_c8_[0x1d4 - 0xc8];
#else
    char unknown1_c8_[0x244 - 0xc8];
#endif
    char pairTables[0x70];
    char textCont[0x98];
    void* unknown_34c_;
    char unknown_350_[0x354 - 0x350];
    short unknown_354_;
    short unknown_356_;
    short unknown_358_;
    short unknown_35a_;
    short unknown_35c_;
    short unknown_35e_;
    short unknown_360_;
    short unknown_362_;
    char unknown_364_[0x365 - 0x364];
    unsigned char unknown_365_;
    unsigned char unknown_366_;
    char unknown_367_[0x369 - 0x367];
    unsigned char unknown_369_;
    unsigned char unknown_36a_;
    char unknown_36b_[0x370 - 0x36b];
    char list[0x1c];
    Struct_ov020_0218b710_4 unknown_38c_;
    char unknown_38d_[0x390 - 0x38d];
    char tiles[0x4];
    void* unknown_394_;
    char unknown_398_[0x470 - 0x398];
    SafeAllocator alloc;
    char unknown_484_[0x498 - 0x470 - sizeof(SafeAllocator)];
    void* buf498;
    char unknown_49c_[0x4e4 - 0x49c];
    int timer;
    char unknown_4e8_[0x4fc - 0x4e8];
    int unknown_4fc_;
};

#if defined(jpn)
struct Struct_ov020_0218b710_6 {
    char d[0x100];
};
struct Struct_ov020_0218b710_7 {
    char d[0xe0];
};
#endif

static inline int inline_ov020_0218b710(Struct_ov020_0218b710_5* self) { return self->timer > 0; }

static inline int inline_ov020_0218b710_2(Struct_ov020_0218b710_5* self) { return self->unknown_4fc_ > 0; }

#define START_FADE(self, target, frames)                                               \
    func_ov020_0218d7ac((Struct_ov020_0218b710*)(self), (target), (frames)); \
    func_ov020_0218d800((Struct_ov020_0218b710_2*)(self), (target), (frames))

#define WAIT_FADE(self)                          \
    for (;;) {                                   \
        if (!inline_ov020_0218b710_2(self)) break;          \
        func_ov020_0218d644(self);               \
        OS_WaitVBlankIntr();                     \
        Main_UpdateLidAndInput();          \
        func_020d86d0(0, 1);     \
    }

#define WAIT_TIMER(self)                         \
    for (;;) {                                   \
        if (!inline_ov020_0218b710(self)) break;         \
        func_ov020_0218d854(self);               \
        OS_WaitVBlankIntr();                     \
        Main_UpdateLidAndInput();          \
        func_020d86d0(0, 1);     \
    }

// USA: func_ov020_0218b710
extern "C" ARM void func_ov020_0218b710(Struct_ov020_0218b710_5* self) {
    GameState* gs = GameState::GetInstance();
    OS_WaitVBlankIntr();
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    if (func_0201201c(gs) == 1) {
        GXx_SetMasterBrightness_((short*)0x400006c, 16);
        GXx_SetMasterBrightness_((short*)0x400106c, 16);
    }
    func_020c38d4();
    *(volatile unsigned int*)0x4001000 |= 0x10000;

    if (func_0201201c(gs) == 1) {
        START_FADE(self, -16, 2000);
        for (;;) {
            if (!func_ov020_0218d898(self)) break;
            func_ov020_0218d644(self);
            OS_WaitVBlankIntr();
            func_020d86d0(0, 1);
        }
    }

    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    volatile unsigned short* var1 = (volatile unsigned short*)0x4000008;
    var1[0] = var1[0] & ~0x3;
    var1[1] = (var1[1] & ~0x3) | 0x1;
    OS_WaitVBlankIntr();
    func_020c38d4();
    *(volatile unsigned int*)0x4001000 |= 0x10000;
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);

    if (func_0200fb9c((char*)gs) != 6) {
        self->alloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x10000), 0x10000);
        self->alloc.Reset();
        Window_Init((InitTarget0205cfd4*)self->textCont);
        Background_Init((BackgroundGraphics*)self->list);
        WindowPane_Init(self->tiles);
        MapVRAMBanksToMainBG(4);
        func_ov020_0218c7bc(0, 0, 1, 1, 0);
        Background_SetMapSize((unsigned char*)self->list, 0);
        self->unknown_38c_.low = 0;
        self->unknown_38c_.high = 1;
        Background_SetPriority(self->list, 0);
        Background_AllocateMap((BackgroundGraphics*)self->list, &self->alloc);
        Background_SetScroll((BackgroundGraphics*)self->list, 0, 0);

        int task;
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->ClearQueue();
        task = loader->QueueLoadFile(data_ov020_0218dbdc, 0);
        for (;;) {
            if (loader->GetTaskStatus(task) != 0) {
                void* recField;
                void* file;
                unsigned int fileLen;
                loader->GetLoadedFileByID(task, &file, &fileLen);
                int count = Pac_CountFiles((PacRecord*)file);
                for (int i = 0; i < count; i++) {
                    int recSize;
                    void* rec = Pac_GetFile((PacRecord*)file, i, &recField, &recSize);
                    if (rec != 0) {
                        Background_LoadFile(self->list, rec, &self->alloc, recSize);
                    }
                }
                loader->RemoveTask(task);
                Background_FillRect(self->list, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics*)self->list, 0);
                self->buf498 = self->alloc.Allocate(0x8000);
                WindowPane_AllocateBuffer((WindowPane*)self->tiles, &self->alloc, (int)self->buf498, 0x800);
                self->unknown_394_ = self->list;
                self->unknown_34c_ = self->list;
                self->unknown_366_ = 1;
                Window_SetPanes((Struct_0205cf78*)self->textCont, (WindowPane*)self->tiles, 1);
                break;
            }
            loader->RemoveAllLocks();
        }

        self->unknown_365_ = 1;
        self->unknown_358_ = 0;
        self->unknown_35a_ = 0;
        self->unknown_35c_ = 0;
        self->unknown_35e_ = 0;
        self->unknown_354_ = 0x20;
        self->unknown_356_ = 0x18;
        self->unknown_360_ = 0xa;
        self->unknown_362_ = 0xd;
        self->unknown_369_ = 0;
        self->unknown_36a_ = 1;

#if defined(jpn)
        char* text = *(char**)(MessageSystem_GetInstance() + 0x28);
        memset(text, 0, 0x800);
#else
        char* text = *(char**)(MessageSystem_GetInstance() + 0x5c);
        memset(text, 0, 0x960);
#endif
        char buf[0x80] = {0};
        func_02041a90(text, 4, 0x68);
        sprintf(buf, data_ov020_0218dbef, data_ov020_0218dbf5, data_ov020_0218dbfc);
        Text_Append(text, buf);
        func_02041a90(text, 4, 0x74);
        sprintf(buf, data_ov020_0218dc08, 4, 2, 0x7539);
        Text_Append(text, buf);
        func_02041a90(text, 4, 0x80);
        sprintf(buf, data_ov020_0218dc1b, 0x13242d6);
        Text_Append(text, buf);
        func_02041a90(text, 4, 0x8c);
        sprintf(buf, data_ov020_0218dc2b, 2, 1, 0x7533);
        Text_Append(text, buf);
        func_02041a90(text, 4, 0x98);
        sprintf(buf, data_ov020_0218dc3f, 2, 1, 0x7533);
        Text_Append(text, buf);
        func_02041a90(text, 4, 0xa4);
        sprintf(buf, data_ov020_0218dc55, 3, 1, 0x7536);
        Text_Append(text, buf);
        func_02041a90(text, 4, 0xb0);
        sprintf(buf, data_ov020_0218dc65, 3, 0, 0x7531);
        Text_Append(text, buf);
#if defined(jpn)
        func_02041a90(text, 0x4e, 0x28);
        Text_Append(text, data_ov020_0218dc72);
        func_02041a90(text, 0x4b, 0x36);
        Text_Append(text, data_ov020_0218dc82);
        func_02041a90(text, 0x4b, 0x50);
        Text_Append(text, data_ov020_0218dc91);
#else
        func_02041a90(text, 0, 0x28);
        func_02042084(text, data_ov020_0218dc72, 0x100, 0);
        func_02041a90(text, 0, 0x36);
        func_02042084(text, data_ov020_0218dc82, 0x100, 0);
        func_02041a90(text, 0, 0x50);
        func_02042084(text, data_ov020_0218dc91, 0x100, 0);
#endif

#if defined(jpn)
        Window_OpenPane(self->textCont, text, 0, 0, 0, 1, 0);
#else
        Window_OpenPane(self->textCont, text, 0, 0, 0, 1, 0, 0);
#endif
        Window_Update(self->textCont, 1);
        Window_Update(self->textCont, 1);
        Window_DrawPanes((Cont0205d228*)self->textCont);
        Window_FlushLayers((Cont0205d274*)self->textCont);
        Window_TransferLayers((Obj0205d2bc*)self->textCont);
        func_020d86d0(0, 1);
        OS_WaitVBlankIntr();
        func_020c38d4();
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x200;
        func_020bbcb4();
        func_020d86d0(0, 1);

        while (self->state != -1) {
            Main_UpdateLidAndInput();
            if (g_keyManager.TestKeysPressed(1) || g_keyManager.TestKeysPressed(2) ||
                g_keyManager.TestKeysPressed(0x400) || g_keyManager.TestKeysPressed(0x800) ||
                g_touchInput.pressed_ != 0) {
                break;
            }
            OS_WaitVBlankIntr();
            GXx_SetMasterBrightness_((short*)0x400006c, 0);
            func_020d86d0(0, 1);
        }

        void* signedAlloc = self->alloc.GetSignedAllocator();
        self->alloc.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
    }

    OS_WaitVBlankIntr();
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    volatile unsigned short* var15 = (volatile unsigned short*)0x4000008;
    volatile unsigned short* subBg = (volatile unsigned short*)0x400100a;
    var15[0] = (var15[0] & ~0x3) | 0x1;
    var15[1] = var15[1] & ~0x3;
    var15[2] = (var15[2] & ~0x3) | 0x2;
    var15[3] = (var15[3] & ~0x3) | 0x3;
    *(volatile unsigned short*)0x4001008 = *(volatile unsigned short*)0x4001008 & ~0x3;
    subBg[0] = (subBg[0] & ~0x3) | 0x1;
    subBg[1] = (subBg[1] & ~0x3) | 0x2;
    subBg[2] = (subBg[2] & ~0x3) | 0x3;

    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(1);
    func_020bb48c(1, 1);
    MapVRAMBanksToTexturePalette(0x60);
    func_020bb780((void*)0x8000, 1);
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();

    self->alloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x10000), 0x10000);
    VramState_Reserve(self->pairTables, 0x4000, 0x400);
    char* g = MessageSystem_GetInstance();
    func_02042c68(g);
    MessageSystem_Stop(g);
    func_020440a4(g);
#if defined(jpn)
    *(char**)(g + 0x1c4c) = self->pairTables;
#else
    *(char**)(g + 0x1e28) = self->pairTables;
#endif
    VramState_Rewind((Foo0207df50*)self->pairTables);
    VramState_Restore(self->pairTables);
    func_020432c4(g);
    VramState_Save(self->pairTables);
    self->state = 100;
    self->frame = -1;

    if (func_0200fb9c((char*)gs) == 6) {
        if (func_0201201c(gs) == 0) {
#if defined(jpn)
            func_ov020_0218cf8c(self);
            func_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            self->timer = 2000;
            for (;;) {
                if (!inline_ov020_0218b710(self)) break;
                func_ov020_0218d854(self);
                OS_WaitVBlankIntr();
                func_020d86d0(0, 1);
            }
            START_FADE(self, 0, 1500);
            self->timer = 7000;
            for (;;) {
                if (!func_ov020_0218d898(self)) {
                    if (!inline_ov020_0218b710(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                    if (self->timer <= 2500) {
                        if (g_keyManager.TestKeysPressed(0xc0b) || g_touchInput.pressed_ != 0) break;
                    }
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                func_020d86d0(0, 1);
            }
            START_FADE(self, -16, 1000);
            WAIT_FADE(self)
            self->timer = 1000;
            WAIT_TIMER(self)

            func_ov020_0218d32c(self, 0);
            func_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            func_ov020_0218d800((Struct_ov020_0218b710_2*)(self), 0, 1500);
            self->timer = 6000;
            for (;;) {
                if (!inline_ov020_0218b710_2(self)) {
                    if (!inline_ov020_0218b710(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                    if (g_keyManager.TestKeysPressed(0xc0b) || g_touchInput.pressed_ != 0) break;
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                func_020d86d0(0, 1);
            }
            func_ov020_0218d800((Struct_ov020_0218b710_2*)(self), -16, 1000);
            WAIT_FADE(self)
            self->timer = 1000;
            WAIT_TIMER(self)
#else
            Set3DClearColor(0x7fff, 0x1f, 0x7fff, 0, 0);
            func_ov020_0218cd98(self);
            func_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            self->timer = 2000;
            WAIT_TIMER(self)

            START_FADE(self, 0, 500);
            self->timer = 3000;
            for (;;) {
                if (!inline_ov020_0218b710_2(self)) {
                    if (!inline_ov020_0218b710(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                func_020d86d0(0, 1);
            }
            START_FADE(self, -16, 500);
            WAIT_FADE(self)
            self->timer = 1000;
            WAIT_TIMER(self)

            func_ov020_0218cf8c(self);
            func_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            START_FADE(self, 0, 1500);
            self->timer = 7000;
            for (;;) {
                if (!func_ov020_0218d898(self)) {
                    if (!inline_ov020_0218b710(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                    if (self->timer <= 2500) {
                        if (g_keyManager.TestKeysPressed(0xf0b) || g_touchInput.pressed_ != 0) break;
                    }
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                func_020d86d0(0, 1);
            }
            START_FADE(self, -16, 1000);
            WAIT_FADE(self)
            self->timer = 1000;
            WAIT_TIMER(self)

            func_ov020_0218d32c(self, 0);
            func_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            START_FADE(self, 0, 1500);
            self->timer = 6000;
            for (;;) {
                if (!inline_ov020_0218b710_2(self)) {
                    if (!inline_ov020_0218b710(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                    if (g_keyManager.TestKeysPressed(0xf0b) || g_touchInput.pressed_ != 0) break;
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                func_020d86d0(0, 1);
            }
            START_FADE(self, -16, 1000);
            WAIT_FADE(self)
            self->timer = 1000;
            WAIT_TIMER(self)
            Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
#endif
        }
        func_02012010(gs, 5);
        func_0200fb94((char*)gs, 0);
        func_02012028(gs, 1);
    } else {
        func_02012010(gs, 0);
        func_ov020_0218c98c(self);
        func_020c38d4();
        *(volatile unsigned int*)0x4001000 |= 0x10000;
        MessageSystem_ResetGlyphs((CombatSlots02045cac*)g);
        func_0205c790(self->big);
        self->unknown_bd_ = 1;
        self->unknown_bc_ = 1;
#if defined(jpn)
        if (func_020ab9c0(1) == 4) {
            Struct_ov020_0218b710_6 entries = *(Struct_ov020_0218b710_6*)data_ov020_0218da90;
            for (int i = 0; i < 8; i++) {
                func_0205cb74(self->big, (int)(entries.d + i * 0x20));
                func_0204359c(g, 0x80);
                func_020439b0(g, 0);
            }
            func_ov020_0218c7f0(self->big, 1, 8);
        } else {
            Struct_ov020_0218b710_7 entries = *(Struct_ov020_0218b710_7*)data_ov020_0218d9b0;
            for (int i = 0; i < 7; i++) {
                func_0205cb74(self->big, (int)(entries.d + i * 0x20));
                func_0204359c(g, 0x80);
                func_020439b0(g, 0);
            }
            func_ov020_0218c7f0(self->big, 1, 7);
        }
        self->posX = 0x3e;
        self->unknown_c2_ = 0x28;
        func_0205dfa8(self->big);
#else
        if (func_020ab9c0(1) == 4) {
            for (int i = 0; i < 8; i++) {
                func_0205cb74(self->big, (int)(data_ov020_0218da90 + i * 0x20));
                func_0204359c(g, 0x10);
                func_020439b0(g, 0);
            }
            func_ov020_0218c7f0(self->big, 1, 8);
        } else {
            for (int i = 0; i < 7; i++) {
                func_0205cb74(self->big, (int)(data_ov020_0218d9b0 + i * 0x20));
                func_0204359c(g, 0x10);
                func_020439b0(g, 0);
            }
            func_ov020_0218c7f0(self->big, 1, 7);
        }
        func_0205cc50(self->big, 0, -4);
        int x = (0x100 - self->width) >> 1;
        int y = (0xc0 - self->height) >> 2;
        self->posX = x;
        self->unknown_c2_ = y;
        func_0205cc50(self->big, 0, -4);
#endif
        GridCursor_SelectIfValid((Struct_0205bcdc*)self->sub2c, 0);
        GridCursor_SetSelectedIndex(self->sub7c, 0);
        MapVRAMBanksToMainObj(2);

        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        char* global = MessageSystem_GetInstance();
        for (;;) {
            func_02043368(global);
#if defined(jpn)
            if (((unsigned char*)global)[0x237] == 2) break;
#else
            if (((unsigned char*)global)[0x2e7] == 2) break;
#endif
            loader->RemoveAllLocks();
        }

        char* ctx = OamManager_GetInstance();
        OamManager_Init(ctx);
        func_0205e8ec((Obj_0205e8ec*)g_sePlayer);
        func_0209c3b4((Actor0209c3b4*)g_bgmPlayer, 2);
        while (self->state != -1) {
            Main_UpdateLidAndInput();
            if (++self->frame >= 0xffffff) {
                self->frame = 1;
            }
            G3X_Reset();
            G3X_ResetMtxStack();
            *(volatile unsigned short*)0x4000060 &= 0xcfdf;
            switch (self->state) {
            case 100:
                func_ov020_0218c840(self);
                break;
            default:
                self->state = -1;
                break;
            }
            func_020d86d0(0, 1);
            OamManager_FlushBuffers(ctx);
            OS_WaitVBlankIntr();
            OamManager_UploadBuffers((Obj0203bdb0*)ctx);
            func_020bbcb4();
            func_020bbd9c();
            GXx_SetMasterBrightness_((short*)0x400006c, 0);
            GXx_SetMasterBrightness_((short*)0x400106c, 0);
        }

        if (func_0200fb9c((char*)gs) == 0) {
            func_02012010(gs, 6);
        } else if (func_0200fb9c((char*)gs) == 5) {
            func_02012010(gs, 6);
        }
    }

    func_ov020_0218d8d8((Struct_ov020_0218b710_3*)self);
    VramState_Rewind((Foo0207df50*)self->pairTables);
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
}
