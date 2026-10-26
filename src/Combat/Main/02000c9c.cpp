#include <globaldefs.h>
#include "Memory/AllocatorLifecycle.h"
#include "NitroSDK/OverlayId.h"
#include "NitroSDK/Graphics.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Input/Input.h"
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/VRAM.h"
#include "NitroSDK/OSLanguage.h"


struct Struct_02000c9c_8;
struct Struct_02000c9c_9;
struct Struct_02000c9c_11;
struct Struct_02000c9c_12;
struct Struct_02000c9c_13;
struct Struct_02000c9c_14;
struct Struct_02000c9c_15;
struct Struct_02000c9c_16;
struct Struct_02000c9c_17;
struct Struct_02000c9c_18;

void* GameState_GetParty(GameState* gs);
void GX_DispOff();
extern "C" void Main_InitializeSystems();
extern "C" void ROMFilesystem_InitFileTables();
void Overlay_InitSystem();
extern "C" void Overlay_Load(unsigned int* id);
extern "C" int Overlay_Unload(unsigned int* id);
extern "C" unsigned int func_ov029_021d8e1c(void* start, void* end, int seed);
extern "C" unsigned int func_ov029_021d8f0c(void* start, void* end, int seed);
extern "C" unsigned int func_ov029_021d8ffc(void* start, void* end, int seed);
void PopulateOv33BackgroundLoader(void* buffer, unsigned int size, int count);
void VRAMStagingManager_Init();
extern "C" Manager020db0f0* ObjLoading_GetInstance();
extern "C" void func_020dafd4();
void LoadObjLoadingGraphicsResources(Manager020db0f0* mgr);
void InitSubstructAndRegisterHandler0x14_020db228(void* mgr);
void BgmPlayer_Init(Actor0209c174* actor);
void BgmPlayer_LoadArchive(void* actor);
void SePlayer_Init(Obj_0205e88c* obj);
void SePlayer_LoadArchive(void* obj, int mode);
extern "C" void func_020421c4(SafeAllocator* alloc);
void InitHalfwords02071688();
char* CharacterColors_GetInstance();
void SetByte0x4_0200fb94(char* gs, unsigned char value);
char GetByte0x4_0200fb9c(char* gs);
void SetWord0x7f6c_02012010(void* gs, int value);
int GetWord0x7f6c_0201201c(void* gs);
void SaveData_CheckOrFormat();
int GameState_IsErrorScreenRequested(StateBits5ccc_11570* gs);
void GameState_ClearErrorScreenRequest(StateBits5ccc_1155c* gs);
void* AllocatorUnion_AllocateExact(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_FreeUnlessZero(AllocatorUnion* alloc, void* data, int size);
void Party_Init(char* p);
void CharacterColors_Load(char* table);
int GetByteField0x63d6_020115a8(FieldBlock63d6_115a8* gs);
void GameState_SetMovieId(FieldBlock63d6_115b4* gs, unsigned char value);
void GameState_ClearMovieId(FieldBlock63d6_115c0* gs);
void FieldScene_Run();
void SePlayer_Reset(void* obj);
void SoundPlayer_Reset(void* obj);
void InitializeActiveAlarmList();
void SetDataFromIndex_02211c50(int index);
int GameState_GetLanguage(Struct0200fb08* gs);
void ForwardToDataHandler_0222708c(int kind, int value);
int OS_EnableIrq();
extern "C" void OS_InitReset();
void OS_ResetSystem(int mode);
void SetVBlankIrqEnable(int enable);
void GX_SetGraphicsMode(int mode, int a, int b);
void OS_WaitVBlankIntr();

extern "C" void func_ov019_0218b5a0(void* arg0);
extern "C" void func_ov019_0218b5a8(void* arg0);
extern "C" void func_ov019_0218b5a4(void* arg0);
extern "C" void func_ov020_0218b5a0(void* arg0);
extern "C" void func_ov020_0218b710(void* arg0);
extern "C" void func_ov020_0218b700(void* arg0);
extern "C" void func_ov016_0218b5a0(void* arg0);
extern "C" void func_ov016_0218b5c4(void* arg0);
extern "C" void func_ov016_0218b5c0(void* arg0);
extern "C" void func_ov021_0218b5a0(void* arg0);
extern "C" void func_ov021_0218b5fc(void* arg0);
struct Struct_02000c9c_10;
extern "C" void func_ov021_0218b5c4(Struct_02000c9c_10*);
extern "C" void func_ov015_02193294(void* arg0);
extern "C" void func_ov015_021934f8(void* arg0);
extern "C" void func_ov015_021933bc(void* arg0);

int InvokeCallbackReturnStatus020d6bac(void (*callback)());
void NotifyOverlay0211e33c_020d6c0c();
int InvokeCallbackReturnStatus020d6bc8(void (*callback)());
void GuardedNotifyOverlay0211e33c020d6c34();
int InvokeCallbackReturnStatus020d6be4(void (*callback)());
void GuardedNotifyOverlay0211e33c020d6c68();
void Main_HandleVBlank();

extern AllocatorUnion g_mainAllocator;
extern char g_fileLoadBuffer[];
extern char g_bgmPlayer[];
extern char g_sePlayer[];
extern char data_02114ec4[];

#if defined(jpn)
#define TITLE_SCENE_SIZE 0x2d0
#define WORLD_SCENE_SIZE 0x494
#define STARTUP_ALLOCATOR_SIZE 0xb000
#define SCENE_SKIP_MEMBER_INDEX (0x7c9e - 0x6d40)
#define MOVIE_RETURN_FLAG_OFFSET 0x6174
extern "C" int data_ov029_021d9b60_fake(void* arg0);
extern "C" int data_ov029_021d9d20_fake(void* arg0);
extern "C" int data_ov029_021d9ee0_fake(void* arg0);
extern "C" void func_020d8614();
#define func_020d863c func_020d6c34
#define func_020d8670 func_020d6c68
#else
#define TITLE_SCENE_SIZE 0x2e0
#define WORLD_SCENE_SIZE 0x504
#define STARTUP_ALLOCATOR_SIZE 0x9478
#define SCENE_SKIP_MEMBER_INDEX (0x7f72 - 0x6fc0)
#define MOVIE_RETURN_FLAG_OFFSET 0x63d4
#endif

#define REG_IME (*(volatile unsigned short*)0x04000208)
#define REG_POWCNT1 (*(volatile unsigned short*)0x04000304)
#define RESET_PARAMETER (*(int*)0x027ffc20)

#define RUNTITLE() \
    do { \
        Overlay_Load(&OVERLAY_19_ID); \
        void* scene = AllocatorUnion_AllocateExact(&g_mainAllocator, TITLE_SCENE_SIZE); \
        func_ov019_0218b5a0(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov019_0218b5a8(scene); \
        func_ov019_0218b5a4(scene); \
        AllocatorUnion_FreeUnlessZero(&g_mainAllocator, scene, TITLE_SCENE_SIZE); \
        Overlay_Unload(&OVERLAY_19_ID); \
    } while (0)

#define RUNOV20() \
    do { \
        Overlay_Load(&OVERLAY_20_ID); \
        void* scene = AllocatorUnion_AllocateExact(&g_mainAllocator, WORLD_SCENE_SIZE); \
        func_ov020_0218b5a0(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov020_0218b710(scene); \
        func_ov020_0218b700(scene); \
        AllocatorUnion_FreeUnlessZero(&g_mainAllocator, scene, WORLD_SCENE_SIZE); \
        Overlay_Unload(&OVERLAY_20_ID); \
    } while (0)

#define RUNOV16(again16) \
    do { \
        void* scene = AllocatorUnion_AllocateExact(&g_mainAllocator, 0x98); \
        func_ov016_0218b5a0(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov016_0218b5c4(scene); \
        again16 = *(int*)((char*)scene + 0x94); \
        func_ov016_0218b5c0(scene); \
        AllocatorUnion_FreeUnlessZero(&g_mainAllocator, scene, 0x98); \
    } while (0)

#define RUNOV21() \
    do { \
        Overlay_Load(&OVERLAY_21_ID); \
        void* scene = AllocatorUnion_AllocateExact(&g_mainAllocator, 0xbc); \
        func_ov021_0218b5a0(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov021_0218b5fc(scene); \
        ResetAllocatorAndClearField40_0218b5c4((Obj0218b5c4*)scene); \
        AllocatorUnion_FreeUnlessZero(&g_mainAllocator, scene, 0xbc); \
        Overlay_Unload(&OVERLAY_21_ID); \
    } while (0)

#define RUNOV15() \
    do { \
        Overlay_Load(&OVERLAY_15_ID); \
        void* scene = AllocatorUnion_AllocateExact(&g_mainAllocator, 0x358); \
        func_ov015_02193294(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov015_021934f8(scene); \
        func_ov015_021933bc(scene); \
        AllocatorUnion_FreeUnlessZero(&g_mainAllocator, scene, 0x358); \
        Overlay_Unload(&OVERLAY_15_ID); \
    } while (0)

#if !defined(jpn)
inline bool inline_02000c9c() {
    return func_ov029_021d8e1c((void*)func_020d6bac, (void*)func_020d6c0c, 0) == 0xffe41136;
}

inline bool inline_02000c9c_2() {
    return func_ov029_021d8f0c((void*)func_020d6bc8, (void*)func_020d6c34, 0) == 0xffe412c4;
}

inline bool inline_02000c9c_3() {
    return func_ov029_021d8ffc((void*)func_020d6be4, (void*)func_020d6c68, 0) == 0xffe41b51;
}
#endif

inline void inline_02000c9c_4(GameState* arg0) {
    func_0200fb94((char*)arg0, 6);
    if (func_0201201c(arg0) != 2) {
        func_02012010(arg0, 0);
    }
}

#define RUNOV17() \
    do { \
        Overlay_Load(&OVERLAY_17_ID); \
        FieldScene_Run(); \
        Overlay_Unload(&OVERLAY_17_ID); \
    } while (0)

// USA: func_02000c9c
extern "C" ARM void main() {
    GameState* gs = GameState::GetInstance();
    char* party = (char*)GameState_GetParty(gs);
    GX_DispOff();
    DISPCNTSUB &= ~0x10000;
    Main_InitializeSystems();
    ROMFilesystem_InitFileTables();
    Overlay_InitSystem();
    Overlay_Load(&OVERLAY_29_ID);
#if defined(jpn)
    if (!data_ov029_021d9b60_fake((void*)func_020d8614) &&
        !data_ov029_021d9d20_fake((void*)func_020d863c) &&
        !data_ov029_021d9ee0_fake((void*)func_020d8670) &&
        BackgroundLoader::GetInstance() == 0) {
#else
    if (!inline_02000c9c() && !inline_02000c9c_2() && !inline_02000c9c_3() && BackgroundLoader::GetInstance() == 0) {
#endif
        Overlay_Load(&OVERLAY_33_ID);
        PopulateOv33BackgroundLoader(g_fileLoadBuffer, 0x30000, 0x14);
    }
    Overlay_Unload(&OVERLAY_29_ID);
    Overlay_Load(&OVERLAY_32_ID);
    VRAMStagingManager_Init();
    Manager020db0f0* objLoading = ObjLoading_GetInstance();
    func_020dafd4();
    LoadObjLoadingGraphicsResources(objLoading);
    InitSubstructAndRegisterHandler0x14_020db228(objLoading);
    BgmPlayer_Init((Actor0209c174*)g_bgmPlayer);
    BgmPlayer_LoadArchive(g_bgmPlayer);
    SePlayer_Init((Obj_0205e88c*)g_sePlayer);
    SePlayer_LoadArchive(g_sePlayer, 100);
    SafeAllocator allocator;
    allocator.ResetAllocatorPointer();
    allocator.CreateTypeA(data_02114ec4, STARTUP_ALLOCATOR_SIZE);
    allocator.Reset();
    func_020421c4(&allocator);
    InitHalfwords02071688();
    char* characterColors = CharacterColors_GetInstance();
    if (RESET_PARAMETER != 0) {
        SetByte0x4_0200fb94((char*)gs, 6);
        SetWord0x7f6c_02012010(gs, 0);
    }
    SaveData_CheckOrFormat();

    for (;;) {
        if (GameState_IsErrorScreenRequested((StateBits5ccc_11570*)gs)) {
            GameState_ClearErrorScreenRequest((StateBits5ccc_1155c*)gs);
            RUNTITLE();
        }
        if (GetWord0x7f6c_0201201c(gs) != 5) {
            Party_Init(party);
        }
        CharacterColors_Load(characterColors);

        bool var5 = false;
        if (func_0201201c(var0) != 5) {
            inline_02000c9c_4(var0);
            inline_02000c9c_4(var0);
            if (func_0200fb9c((char*)var0) != 6) {
                RUNOV20();
            } else if (func_0200fb9c((char*)var0) == 6) {
                RUNOV20();
                if (*(unsigned char*)&gs->unk_6fc0[SCENE_SKIP_MEMBER_INDEX] == 0) {
                    GameState_SetMovieId((FieldBlock63d6_115b4*)gs, 1);
                    Overlay_Load(&OVERLAY_16_ID);
                    int again16 = 1;
                    while (again16) {
                        RUNOV16(again16);
                    }
                    Overlay_Unload(&OVERLAY_16_ID);
                    GameState_ClearMovieId((FieldBlock63d6_115c0*)gs);
                } else {
                    *(unsigned char*)&var0->unk_6fc0[SCENE_SKIP_MEMBER_INDEX] = 0;
                }
            }
            var5 = true;
        }

        switch (func_0200fb9c((char*)var0)) {
        case 2:
            func_02012010(var0, 0);
            break;
        case 0:
            if (var5 != true) {
                func_02012010(var0, 0);
            }
            break;
        case 7:
            func_0200fb94((char*)var0, 0);
            break;
        case 5:
            if (func_0201201c(var0) != 6) {
                func_02012010(var0, 0);
            }
            break;
        }

        bool var7 = true;
        while (var7) {
            var7 = false;
            switch (func_0200fb9c((char*)var0)) {
            case 0:
            case 4:
            case 5:
            case 9:
                RUNOV17();
                if (func_020115a8((Struct_02000c9c_12*)var0)) {
                    func_0200fb94((char*)var0, 3);
                    var7 = true;
                }
                break;
            case 2:
                RUNOV21();
                if (((unsigned char*)var0)[MOVIE_RETURN_FLAG_OFFSET] != 0) {
                    RUNOV17();
                    if (func_020115a8((Struct_02000c9c_12*)var0)) {
                        func_0200fb94((char*)var0, 3);
                        var7 = true;
                    }
                }
                break;
            case 1:
                RUNOV15();
                break;
            case 3:
                Overlay_Load(&OVERLAY_16_ID);
                int more = 1;
                while (more) {
                    RUNOV16(more);
                }
                Overlay_Unload(&OVERLAY_16_ID);
                if (GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs)) {
                    SetByte0x4_0200fb94((char*)gs, 0);
                    again = true;
                }
                break;
            case 8:
                SePlayer_Reset(g_sePlayer);
                SoundPlayer_Reset(g_bgmPlayer);
                g_touchInput.Pause();
                Overlay_Load(&OVERLAY_27_ID);
                Overlay_Load(&OVERLAY_31_ID);
                REG_IME;
                REG_IME = 0;
                InitializeActiveAlarmList();
                func_ov031_02211c50(2);
#if defined(jpn)
                func_ov031_0222708c(0, 0x10);
#else
                switch (GameState_GetLanguage((Struct0200fb08*)gs)) {
                case 1:
                    func_ov031_0222708c(1, 0);
                    break;
                case OSLanguage_French:
                    ForwardToDataHandler_0222708c(OSLanguage_French, 0);
                    break;
                case OSLanguage_German:
                    ForwardToDataHandler_0222708c(OSLanguage_German, 0);
                    break;
                case OSLanguage_Italian:
                    ForwardToDataHandler_0222708c(OSLanguage_Italian, 0);
                    break;
                case OSLanguage_Spanish:
                    ForwardToDataHandler_0222708c(OSLanguage_Spanish, 0);
                    break;
                default:
                    func_ov031_0222708c(1, 0);
                    break;
                }
#endif
                OS_EnableIrq();
                OS_InitReset();
                OS_ResetSystem(1);
                Overlay_Load(&OVERLAY_32_ID);
                g_touchInput.Unpause();
                BgmPlayer_Init((Actor0209c174*)g_bgmPlayer);
                BgmPlayer_LoadArchive(g_bgmPlayer);
                SetInterruptHandler(IRQ_MASK_LCD_VBLANK, (const void*)Main_HandleVBlank);
                EnableSpecificInterrupts(IRQ_MASK_LCD_VBLANK);
                OS_EnableIrq();
                EnableIRQInterrupts();
                SetVBlankIrqEnable(1);
                MapVRAMBanksToMainBG(VRAM_BANK_F | VRAM_BANK_G);
                GX_SetGraphicsMode(1, 0, 0);
                DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
                BG0CNT = (BG0CNT & (BGCNT_MASK_MOSAIC | BGCNT_MASK_PRIORITY)) | 4;
                BG0CNT &= ~BGCNT_MASK_PRIORITY;
                BG0CNT &= ~BGCNT_MASK_MOSAIC;
                REG_POWCNT1 &= ~0x8000;
                OS_WaitVBlankIntr();
                SetByte0x4_0200fb94((char*)gs, 6);
                SetWord0x7f6c_02012010(gs, 1);
                again = false;
                break;
            }
        }
        if (GameState_IsErrorScreenRequested((StateBits5ccc_11570*)gs)) {
            GameState_ClearErrorScreenRequest((StateBits5ccc_1155c*)gs);
            RUNTITLE();
        }
    }
}
