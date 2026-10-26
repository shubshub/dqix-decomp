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

struct FieldGroup4e8_0218d7ac;
struct FieldGroup4f4_0218d800;
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
struct Struct_0205e8ec;
struct Struct_0209c3b4_2;
struct Struct_0203bdb0;
struct Struct_ov020_0218b710_3;

void OS_WaitVBlankIntr();
extern "C" void GXx_SetMasterBrightness_(short* out, int value);
int GetWord0x7f6c_0201201c(void* obj);
void SetWord0x7f6c_02012010(void* obj, int value);
unsigned char GetByte0x4_0200fb9c(char* obj);
void SetByte0x4_0200fb94(char* obj, unsigned char value);
void SetByte0x7f70_02012028(void* obj, unsigned char value);
void RestoreDisplayMode_020c38d4();
void UpdateFieldGroup4e8_0218d7ac(FieldGroup4e8_0218d7ac* obj, int target, int frames);
void UpdateFieldGroup4f4_0218d800(FieldGroup4f4_0218d800* obj, int target, int frames);
void WriteControlAndToggle020d86d0(int a, int b);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void Window_Init(InitTarget0205cfd4* obj);
void Background_Init(BackgroundGraphics* list);
void Background_SetMapSize(unsigned char* obj, int value);
void Background_AllocateMap(BackgroundGraphics* obj, SafeAllocator* alloc);
void Background_SetScroll(BackgroundGraphics* obj, int a, int b);
int Pac_CountFiles(PacRecord* entries);
void* Pac_GetFile(PacRecord* recs, int index, void** outField, int* outSize);
void Background_UploadMap(BackgroundGraphics* list, void* arg);
void WindowPane_AllocateBuffer(WindowPane* obj, SafeAllocator* alloc, int buf, unsigned int size);
void Window_SetPanes(Struct_0205cf78* obj, WindowPane* elems, unsigned char flag);
char* MessageSystem_GetInstance();
int AppendXYTag_02041a90(char* text, int x, int y);
int Text_Append(char* text, const char* str);
int AppendDotLeaderLabel02042084(char* text, char* label, int width, int flags);
void Window_DrawPanes(Cont0205d228* obj);
void Window_FlushLayers(Cont0205d274* obj);
void Window_TransferLayers(Obj0205d2bc* obj);
void ProcessRingJobs020bbcb4();
void Main_UpdateLidAndInput();
void LockStagedTextureVRAMCopying();
extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void func_020bb780(void* arg0, int arg1);
void UpdateVRAMStagingVRAMBanks();
void UnlockStagedTextureVRAMCopying();
void TailForward020440a4(void* obj);
void VramState_Rewind(Foo0207df50* obj);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
void MessageSystem_ResetGlyphs(CombatSlots02045cac* slots);
void InitBigStruct0205c790(char* obj);
int CheckSaveBufferStatus_020ab9c0(int flag);
void ProcessCombatEntry0205cb74(char* obj, int entry);
void Forward0204359c(void* obj, int value);
void GridCursor_SelectIfValid(Struct_0205bcdc* obj, int index);
void OamManager_Init(char* ctx);
void RefreshDisplayState0205e8ec(Obj_0205e8ec* obj);
void SetStateAndDispatch0209c3b4(Actor0209c3b4* actor, int state);
void G3X_Reset();
void OamManager_FlushBuffers(void* oam);
void OamManager_UploadBuffers(Obj0203bdb0* obj);
void ResetAllocatorAndDispatchState_0218d8d8(AllocGroup0218d8d8* obj);

extern "C" int func_ov020_0218d898(void* arg0);
extern "C" void func_ov020_0218d644(void* arg0);
extern "C" void func_ov020_0218d854(void* arg0);
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
extern "C" void func_0205dfa8(void* arg0);
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
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};

struct Struct_ov020_0218b710_5 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0xc - 0x8];
    char unknown_c_[0x2c - 0xc];
    char unknown_2c_[0x7c - 0x2c];
    char unknown_7c_[0xbc - 0x7c];
    unsigned char unknown_bc_;
    unsigned char unknown_bd_;
    char unknown_be_[0xc0 - 0xbe];
    short unknown_c0_;
    short unknown_c2_;
    short unknown_c4_;
    short unknown_c6_;
#if defined(jpn)
    char unknown_c8_[0x1d4 - 0xc8];
#else
    char unknown1_c8_[0x244 - 0xc8];
#endif
    char unknown_244_[0x70];
    char unknown_2b4_[0x98];
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
    char unknown_370_[0x1c];
    Struct_ov020_0218b710_4 unknown_38c_;
    char unknown_38d_[0x390 - 0x38d];
    char unknown_390_[0x4];
    void* unknown_394_;
    char unknown_398_[0x470 - 0x398];
    SafeAllocator unknown_470_;
    char unknown_484_[0x498 - 0x470 - sizeof(SafeAllocator)];
    void* unknown_498_;
    char unknown_49c_[0x4e4 - 0x49c];
    int unknown_4e4_;
    char unknown_4e8_[0x4fc - 0x4e8];
    int unknown_4fc_;
};

#if defined(jpn)
struct Struct_ov020_0218b710_6 {
    char unknown_0_[0x100];
};
struct Struct_ov020_0218b710_7 {
    char unknown_0_[0xe0];
};
#endif

static inline int inline_ov020_0218b710(Struct_ov020_0218b710_5* arg0) { return arg0->unknown_4e4_ > 0; }

static inline int inline_ov020_0218b710_2(Struct_ov020_0218b710_5* arg0) { return arg0->unknown_4fc_ > 0; }

#define START_FADE(self, target, frames)                                               \
    func_ov020_0218d7ac((Struct_ov020_0218b710*)(self), (target), (frames)); \
    func_ov020_0218d800((Struct_ov020_0218b710_2*)(self), (target), (frames))

#define WAIT_FADE(self)                          \
    for (;;) {                                   \
        if (!inline_ov020_0218b710_2(self)) break;          \
        func_ov020_0218d644(self);               \
        OS_WaitVBlankIntr();                     \
        Main_UpdateLidAndInput();          \
        WriteControlAndToggle020d86d0(0, 1);     \
    }

#define WAIT_TIMER(self)                         \
    for (;;) {                                   \
        if (!inline_ov020_0218b710(self)) break;         \
        func_ov020_0218d854(self);               \
        OS_WaitVBlankIntr();                     \
        Main_UpdateLidAndInput();          \
        WriteControlAndToggle020d86d0(0, 1);     \
    }

// USA: func_ov020_0218b710
extern "C" ARM void func_ov020_0218b710(Sequence0218b710* self) {
    GameState* gs = GameState::GetInstance();
    OS_WaitVBlankIntr();
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    if (GetWord0x7f6c_0201201c(gs) == 1) {
        GXx_SetMasterBrightness_((short*)0x400006c, 16);
        GXx_SetMasterBrightness_((short*)0x400106c, 16);
    }
    func_020c38d4();
    *(volatile unsigned int*)0x4001000 |= 0x10000;

    if (func_0201201c(var0) == 1) {
        START_FADE(arg0, -16, 2000);
        for (;;) {
            if (!func_ov020_0218d898(self)) break;
            func_ov020_0218d644(self);
            OS_WaitVBlankIntr();
            WriteControlAndToggle020d86d0(0, 1);
        }
    }

    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    volatile unsigned short* bgcnt = (volatile unsigned short*)0x4000008;
    bgcnt[0] = bgcnt[0] & ~0x3;
    bgcnt[1] = (bgcnt[1] & ~0x3) | 0x1;
    OS_WaitVBlankIntr();
    RestoreDisplayMode_020c38d4();
    *(volatile unsigned int*)0x4001000 |= 0x10000;
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);

    if (GetByte0x4_0200fb9c((char*)gs) != 6) {
        self->alloc.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x10000), 0x10000);
        self->alloc.Reset();
        Window_Init((InitTarget0205cfd4*)self->textCont);
        Background_Init((BackgroundGraphics*)self->list);
        WindowPane_Init(self->tiles);
        MapVRAMBanksToMainBG(4);
        func_ov020_0218c7bc(0, 0, 1, 1, 0);
        Background_SetMapSize((unsigned char*)self->list, 0);
        self->listFlags.low = 0;
        self->listFlags.high = 1;
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
                self->list394 = self->list;
                self->list34c = self->list;
                self->b366 = 1;
                Window_SetPanes((Struct_0205cf78*)self->textCont, (WindowPane*)self->tiles, 1);
                break;
            }
            var3->RemoveAllLocks();
        }

        arg0->unknown_365_ = 1;
        arg0->unknown_358_ = 0;
        arg0->unknown_35a_ = 0;
        arg0->unknown_35c_ = 0;
        arg0->unknown_35e_ = 0;
        arg0->unknown_354_ = 0x20;
        arg0->unknown_356_ = 0x18;
        arg0->unknown_360_ = 0xa;
        arg0->unknown_362_ = 0xd;
        arg0->unknown_369_ = 0;
        arg0->unknown_36a_ = 1;

#if defined(jpn)
        char* text = *(char**)(MessageSystem_GetInstance() + 0x28);
        memset(text, 0, 0x800);
#else
        char* text = *(char**)(MessageSystem_GetInstance() + 0x5c);
        memset(text, 0, 0x960);
#endif
        char buf[0x80] = {0};
        AppendXYTag_02041a90(text, 4, 0x68);
        sprintf(buf, data_ov020_0218dbef, data_ov020_0218dbf5, data_ov020_0218dbfc);
        Text_Append(text, buf);
        AppendXYTag_02041a90(text, 4, 0x74);
        sprintf(buf, data_ov020_0218dc08, 4, 2, 0x7539);
        Text_Append(text, buf);
        AppendXYTag_02041a90(text, 4, 0x80);
        sprintf(buf, data_ov020_0218dc1b, 0x13242d6);
        Text_Append(text, buf);
        AppendXYTag_02041a90(text, 4, 0x8c);
        sprintf(buf, data_ov020_0218dc2b, 2, 1, 0x7533);
        Text_Append(text, buf);
        AppendXYTag_02041a90(text, 4, 0x98);
        sprintf(buf, data_ov020_0218dc3f, 2, 1, 0x7533);
        Text_Append(text, buf);
        AppendXYTag_02041a90(text, 4, 0xa4);
        sprintf(buf, data_ov020_0218dc55, 3, 1, 0x7536);
        Text_Append(text, buf);
        AppendXYTag_02041a90(text, 4, 0xb0);
        sprintf(buf, data_ov020_0218dc65, 3, 0, 0x7531);
        Text_Append(text, buf);
#if defined(jpn)
        AppendXYTag_02041a90(text, 0x4e, 0x28);
        Text_Append(text, data_ov020_0218dc72);
        AppendXYTag_02041a90(text, 0x4b, 0x36);
        Text_Append(text, data_ov020_0218dc82);
        AppendXYTag_02041a90(text, 0x4b, 0x50);
        Text_Append(text, data_ov020_0218dc91);
#else
        func_02041a90(var11, 0, 0x28);
        func_02042084(var11, data_ov020_0218dc72, 0x100, 0);
        func_02041a90(var11, 0, 0x36);
        func_02042084(var11, data_ov020_0218dc82, 0x100, 0);
        func_02041a90(var11, 0, 0x50);
        func_02042084(var11, data_ov020_0218dc91, 0x100, 0);
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
        WriteControlAndToggle020d86d0(0, 1);
        OS_WaitVBlankIntr();
        RestoreDisplayMode_020c38d4();
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x200;
        ProcessRingJobs020bbcb4();
        WriteControlAndToggle020d86d0(0, 1);

        while (self->state != -1) {
            Main_UpdateLidAndInput();
            if (g_keyManager.TestKeysPressed(1) || g_keyManager.TestKeysPressed(2) ||
                g_keyManager.TestKeysPressed(0x400) || g_keyManager.TestKeysPressed(0x800) ||
                g_touchInput.pressed_ != 0) {
                break;
            }
            OS_WaitVBlankIntr();
            GXx_SetMasterBrightness_((short*)0x400006c, 0);
            WriteControlAndToggle020d86d0(0, 1);
        }

        void* signedAlloc = self->alloc.GetSignedAllocator();
        self->alloc.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
    }

    OS_WaitVBlankIntr();
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    volatile unsigned short* mainBg = (volatile unsigned short*)0x4000008;
    volatile unsigned short* subBg = (volatile unsigned short*)0x400100a;
    mainBg[0] = (mainBg[0] & ~0x3) | 0x1;
    mainBg[1] = mainBg[1] & ~0x3;
    mainBg[2] = (mainBg[2] & ~0x3) | 0x2;
    mainBg[3] = (mainBg[3] & ~0x3) | 0x3;
    *(volatile unsigned short*)0x4001008 = *(volatile unsigned short*)0x4001008 & ~0x3;
    var16[0] = (var16[0] & ~0x3) | 0x1;
    var16[1] = (var16[1] & ~0x3) | 0x2;
    var16[2] = (var16[2] & ~0x3) | 0x3;

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
    TailForward020440a4(g);
#if defined(jpn)
    *(char**)(var17 + 0x1c4c) = arg0->unknown_244_;
#else
    *(char**)(var17 + 0x1e28) = arg0->unknown_244_;
#endif
    VramState_Rewind((Foo0207df50*)self->pairTables);
    VramState_Restore(self->pairTables);
    func_020432c4(g);
    VramState_Save(self->pairTables);
    self->state = 100;
    self->frame = -1;

    if (func_0200fb9c((char*)var0) == 6) {
        if (func_0201201c(var0) == 0) {
#if defined(jpn)
            func_ov020_0218cf8c(arg0);
            func_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            arg0->unknown_4e4_ = 2000;
            for (;;) {
                if (!IsTimerActive(self)) break;
                func_ov020_0218d854(self);
                OS_WaitVBlankIntr();
                WriteControlAndToggle020d86d0(0, 1);
            }
            START_FADE(arg0, 0, 1500);
            arg0->unknown_4e4_ = 7000;
            for (;;) {
                if (!func_ov020_0218d898(self)) {
                    if (!IsTimerActive(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                    if (self->timer <= 2500) {
                        if (g_keyManager.TestKeysPressed(0xc0b) || g_touchInput.pressed_ != 0) break;
                    }
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                WriteControlAndToggle020d86d0(0, 1);
            }
            START_FADE(arg0, -16, 1000);
            WAIT_FADE(arg0)
            arg0->unknown_4e4_ = 1000;
            WAIT_TIMER(arg0)

            func_ov020_0218d32c(arg0, 0);
            func_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            func_ov020_0218d800((Struct_ov020_0218b710_2*)(arg0), 0, 1500);
            arg0->unknown_4e4_ = 6000;
            for (;;) {
                if (!IsFadeActive(self)) {
                    if (!IsTimerActive(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                    if (g_keyManager.TestKeysPressed(0xc0b) || g_touchInput.pressed_ != 0) break;
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                WriteControlAndToggle020d86d0(0, 1);
            }
            func_ov020_0218d800((Struct_ov020_0218b710_2*)(arg0), -16, 1000);
            WAIT_FADE(arg0)
            arg0->unknown_4e4_ = 1000;
            WAIT_TIMER(arg0)
#else
            Set3DClearColor(0x7fff, 0x1f, 0x7fff, 0, 0);
            func_ov020_0218cd98(self);
            RestoreDisplayMode_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            arg0->unknown_4e4_ = 2000;
            WAIT_TIMER(arg0)

            START_FADE(arg0, 0, 500);
            arg0->unknown_4e4_ = 3000;
            for (;;) {
                if (!IsFadeActive(self)) {
                    if (!IsTimerActive(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                WriteControlAndToggle020d86d0(0, 1);
            }
            START_FADE(arg0, -16, 500);
            WAIT_FADE(arg0)
            arg0->unknown_4e4_ = 1000;
            WAIT_TIMER(arg0)

            func_ov020_0218cf8c(arg0);
            func_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            START_FADE(arg0, 0, 1500);
            arg0->unknown_4e4_ = 7000;
            for (;;) {
                if (!func_ov020_0218d898(self)) {
                    if (!IsTimerActive(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                    if (self->timer <= 2500) {
                        if (g_keyManager.TestKeysPressed(0xf0b) || g_touchInput.pressed_ != 0) break;
                    }
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                WriteControlAndToggle020d86d0(0, 1);
            }
            START_FADE(arg0, -16, 1000);
            WAIT_FADE(arg0)
            arg0->unknown_4e4_ = 1000;
            WAIT_TIMER(arg0)

            func_ov020_0218d32c(arg0, 0);
            func_020c38d4();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            START_FADE(arg0, 0, 1500);
            arg0->unknown_4e4_ = 6000;
            for (;;) {
                if (!IsFadeActive(self)) {
                    if (!IsTimerActive(self)) break;
                    func_ov020_0218d854(self);
                    Main_UpdateLidAndInput();
                    if (g_keyManager.TestKeysPressed(0xf0b) || g_touchInput.pressed_ != 0) break;
                }
                func_ov020_0218d644(self);
                OS_WaitVBlankIntr();
                WriteControlAndToggle020d86d0(0, 1);
            }
            START_FADE(self, -16, 1000);
            WAIT_FADE(self)
            self->timer = 1000;
            WAIT_TIMER(self)
            Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
#endif
        }
        func_02012010(var0, 5);
        func_0200fb94((char*)var0, 0);
        func_02012028(var0, 1);
    } else {
        func_02012010(var0, 0);
        func_ov020_0218c98c(arg0);
        func_020c38d4();
        *(volatile unsigned int*)0x4001000 |= 0x10000;
        MessageSystem_ResetGlyphs((CombatSlots02045cac*)g);
        InitBigStruct0205c790(self->big);
        self->flagBd = 1;
        self->flagBc = 1;
#if defined(jpn)
        if (func_020ab9c0(1) == 4) {
            Struct_ov020_0218b710_6 var18 = *(Struct_ov020_0218b710_6*)data_ov020_0218da90;
            for (int var19 = 0; var19 < 8; var19++) {
                func_0205cb74(arg0->unknown_c_, (int)(var18.unknown_0_ + var19 * 0x20));
                func_0204359c(var17, 0x80);
                func_020439b0(var17, 0);
            }
            func_ov020_0218c7f0(arg0->unknown_c_, 1, 8);
        } else {
            Struct_ov020_0218b710_7 var20 = *(Struct_ov020_0218b710_7*)data_ov020_0218d9b0;
            for (int var21 = 0; var21 < 7; var21++) {
                func_0205cb74(arg0->unknown_c_, (int)(var20.unknown_0_ + var21 * 0x20));
                func_0204359c(var17, 0x80);
                func_020439b0(var17, 0);
            }
            func_ov020_0218c7f0(arg0->unknown_c_, 1, 7);
        }
        arg0->unknown_c0_ = 0x3e;
        arg0->unknown_c2_ = 0x28;
        func_0205dfa8(arg0->unknown_c_);
#else
        if (func_020ab9c0(1) == 4) {
            for (int var22 = 0; var22 < 8; var22++) {
                func_0205cb74(arg0->unknown_c_, (int)(data_ov020_0218da90 + var22 * 0x20));
                func_0204359c(var17, 0x10);
                func_020439b0(var17, 0);
            }
            func_ov020_0218c7f0(arg0->unknown_c_, 1, 8);
        } else {
            for (int var23 = 0; var23 < 7; var23++) {
                func_0205cb74(arg0->unknown_c_, (int)(data_ov020_0218d9b0 + var23 * 0x20));
                func_0204359c(var17, 0x10);
                func_020439b0(var17, 0);
            }
            func_ov020_0218c7f0(arg0->unknown_c_, 1, 7);
        }
        func_0205cc50(arg0->unknown_c_, 0, -4);
        int var24 = (0x100 - arg0->unknown_c4_) >> 1;
        int var25 = (0xc0 - arg0->unknown_c6_) >> 2;
        arg0->unknown_c0_ = var24;
        arg0->unknown_c2_ = var25;
        func_0205cc50(arg0->unknown_c_, 0, -4);
#endif
        GridCursor_SelectIfValid((Struct_0205bcdc*)self->sub2c, 0);
        GridCursor_SetSelectedIndex(self->sub7c, 0);
        MapVRAMBanksToMainObj(2);

        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        char* global = MessageSystem_GetInstance();
        for (;;) {
            func_02043368(var27);
#if defined(jpn)
            if (((unsigned char*)var27)[0x237] == 2) break;
#else
            if (((unsigned char*)var27)[0x2e7] == 2) break;
#endif
            var26->RemoveAllLocks();
        }

        char* ctx = OamManager_GetInstance();
        OamManager_Init(ctx);
        RefreshDisplayState0205e8ec((Obj_0205e8ec*)g_sePlayer);
        SetStateAndDispatch0209c3b4((Actor0209c3b4*)g_bgmPlayer, 2);
        while (self->state != -1) {
            Main_UpdateLidAndInput();
            if (++self->frame >= 0xffffff) {
                self->frame = 1;
            }
            G3X_Reset();
            G3X_ResetMtxStack();
            *(volatile unsigned short*)0x4000060 &= 0xcfdf;
            switch (arg0->unknown_0_) {
            case 100:
                func_ov020_0218c840(arg0);
                break;
            default:
                arg0->unknown_0_ = -1;
                break;
            }
            WriteControlAndToggle020d86d0(0, 1);
            OamManager_FlushBuffers(ctx);
            OS_WaitVBlankIntr();
            OamManager_UploadBuffers((Obj0203bdb0*)ctx);
            ProcessRingJobs020bbcb4();
            func_020bbd9c();
            GXx_SetMasterBrightness_((short*)0x400006c, 0);
            GXx_SetMasterBrightness_((short*)0x400106c, 0);
        }

        if (func_0200fb9c((char*)var0) == 0) {
            func_02012010(var0, 6);
        } else if (func_0200fb9c((char*)var0) == 5) {
            func_02012010(var0, 6);
        }
    }

    ResetAllocatorAndDispatchState_0218d8d8((AllocGroup0218d8d8*)self);
    VramState_Rewind((Foo0207df50*)self->pairTables);
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
}
