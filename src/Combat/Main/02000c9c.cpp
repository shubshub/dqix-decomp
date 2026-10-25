#include <globaldefs.h>
#include "Memory/AllocatorLifecycle.h"
#include "NitroSDK/OverlayId.h"
#include "NitroSDK/Graphics.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Input/Input.h"

#if defined(jpn)
#define func_020daf90 func_020dc998
#endif

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
void SaveAndClearDisplayMode_020c3898();
extern "C" void func_02012c34();
extern "C" void func_020a0c0c();
extern "C" void func_020a1838();
extern "C" void func_020a1940(unsigned int* arg0);
extern "C" int func_020a1bb4(unsigned int* arg0);
extern "C" unsigned int func_ov029_021d8e1c(void* arg0, void* arg1, int arg2);
extern "C" unsigned int func_ov029_021d8f0c(void* arg0, void* arg1, int arg2);
extern "C" unsigned int func_ov029_021d8ffc(void* arg0, void* arg1, int arg2);
void PopulateOv33BackgroundLoader(void* buffer, unsigned int size, int count);
extern "C" void func_020dc034();
extern "C" Struct_02000c9c_18* func_020daf90();
extern "C" void func_020dafd4();
void LoadObjLoadingGraphicsResources(Manager020db0f0* mgr);
void InitSubstructAndRegisterHandler0x14_020db228(void* mgr);
void ResetActor0209c174(Actor0209c174* actor);
void Dispatch0203a974With0x57000_0209c290(void* actor);
void InitDisplayState0205e88c(Obj_0205e88c* obj);
void SetupContextForMode0205ea20(void* obj, int mode);
extern "C" void func_020421c4(SafeAllocator* alloc);
void InitHalfwords02071688();
char* CharacterColors_GetInstance();
void SetByte0x4_0200fb94(char* gs, unsigned char value);
char GetByte0x4_0200fb9c(char* gs);
void SetWord0x7f6c_02012010(void* gs, int value);
int GetWord0x7f6c_0201201c(void* gs);
void CheckAndApplyDebugCode020ac910();
int GetFlag0x5cccBit0_02011570(StateBits5ccc_11570* gs);
void ClearFlag0x5cccBit0_0201155c(StateBits5ccc_1155c* gs);
void* AllocateFromAllocatorUnion_02012db0(AllocatorUnion* alloc, unsigned int size);
void FreeIfFlag_02012dbc(AllocatorUnion* alloc, void* data, int size);
void InitBigManagerStruct0208660c(char* p);
void PrepareAndRunBufferedScript02099cb8(char* table);
int GetByteField0x63d6_020115a8(FieldBlock63d6_115a8* gs);
void SetByteField0x63d6_020115b4(FieldBlock63d6_115b4* gs, unsigned char value);
void ClearByte0x63d6_020115c0(FieldBlock63d6_115c0* gs);
void GuardedOverlayDispatch020d6cb4();
void ResetObjectState0205e8d4(void* obj);
void FreeAndReinit0203a950(void* obj);
void InitializeActiveAlarmList();
void SetDataFromIndex_02211c50(int index);
int GameState_GetLanguage(Struct0200fb08* gs);
void ForwardToDataHandler_0222708c(int kind, int value);
int EnableIMEReturnPrev_020d6c9c();
extern "C" void func_020c983c();
extern "C" void func_020c98f0(int arg0);
void SetInterruptHandler(unsigned int mask, const void* handler);
void EnableSpecificInterrupts(unsigned int mask);
void EnableIRQInterrupts();
extern "C" void func_020c3864(int arg0);
extern "C" void MapVRAMBanksToMainBG(int banks);
extern "C" void func_020c391c(int arg0, int arg1, int arg2);
extern "C" void func_020c9820();

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

extern "C" int func_020d6bac(void (*arg0)());
extern "C" void func_020d6c0c();
extern "C" int func_020d6bc8(void (*arg0)());
extern "C" void func_020d6c34();
extern "C" int func_020d6be4(void (*arg0)());
extern "C" void func_020d6c68();
extern "C" void func_02012bd8();

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

#define RUNTITLE() \
    do { \
        func_020a1940(&OVERLAY_19_ID); \
        void* scene = AllocateFromAllocatorUnion_02012db0(&g_mainAllocator, TITLE_SCENE_SIZE); \
        func_ov019_0218b5a0(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov019_0218b5a8(scene); \
        func_ov019_0218b5a4(scene); \
        FreeIfFlag_02012dbc(&g_mainAllocator, scene, TITLE_SCENE_SIZE); \
        func_020a1bb4(&OVERLAY_19_ID); \
    } while (0)

#define RUNOV20() \
    do { \
        func_020a1940(&OVERLAY_20_ID); \
        void* scene = AllocateFromAllocatorUnion_02012db0(&g_mainAllocator, WORLD_SCENE_SIZE); \
        func_ov020_0218b5a0(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov020_0218b710(scene); \
        func_ov020_0218b700(scene); \
        FreeIfFlag_02012dbc(&g_mainAllocator, scene, WORLD_SCENE_SIZE); \
        func_020a1bb4(&OVERLAY_20_ID); \
    } while (0)

#define RUNOV16(again16) \
    do { \
        void* scene = AllocateFromAllocatorUnion_02012db0(&g_mainAllocator, 0x98); \
        func_ov016_0218b5a0(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov016_0218b5c4(scene); \
        again16 = *(int*)((char*)scene + 0x94); \
        func_ov016_0218b5c0(scene); \
        FreeIfFlag_02012dbc(&g_mainAllocator, scene, 0x98); \
    } while (0)

#define RUNOV21() \
    do { \
        func_020a1940(&OVERLAY_21_ID); \
        void* scene = AllocateFromAllocatorUnion_02012db0(&g_mainAllocator, 0xbc); \
        func_ov021_0218b5a0(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov021_0218b5fc(scene); \
        ResetAllocatorAndClearField40_0218b5c4((Obj0218b5c4*)scene); \
        FreeIfFlag_02012dbc(&g_mainAllocator, scene, 0xbc); \
        func_020a1bb4(&OVERLAY_21_ID); \
    } while (0)

#define RUNOV15() \
    do { \
        func_020a1940(&OVERLAY_15_ID); \
        void* scene = AllocateFromAllocatorUnion_02012db0(&g_mainAllocator, 0x358); \
        func_ov015_02193294(scene); \
        EmptyStub02012de4(&g_mainAllocator); \
        func_ov015_021934f8(scene); \
        func_ov015_021933bc(scene); \
        FreeIfFlag_02012dbc(&g_mainAllocator, scene, 0x358); \
        func_020a1bb4(&OVERLAY_15_ID); \
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
        func_020a1940(&OVERLAY_17_ID); \
        func_020d6cb4(); \
        func_020a1bb4(&OVERLAY_17_ID); \
    } while (0)

// USA: func_02000c9c
extern "C" ARM void main() {
    GameState* gs = GameState::GetInstance();
    char* bigManager = (char*)GameState_GetParty(gs);
    SaveAndClearDisplayMode_020c3898();
    DISPCNTSUB &= ~0x10000;
    func_02012c34();
    func_020a0c0c();
    func_020a1838();
    func_020a1940(&OVERLAY_29_ID);
#if defined(jpn)
    if (!data_ov029_021d9b60_fake((void*)func_020d8614) &&
        !data_ov029_021d9d20_fake((void*)func_020d863c) &&
        !data_ov029_021d9ee0_fake((void*)func_020d8670) &&
        BackgroundLoader::GetInstance() == 0) {
#else
    if (!inline_02000c9c() && !inline_02000c9c_2() && !inline_02000c9c_3() && BackgroundLoader::GetInstance() == 0) {
#endif
        func_020a1940(&OVERLAY_33_ID);
        PopulateOv33BackgroundLoader(g_fileLoadBuffer, 0x30000, 0x14);
    }
    func_020a1bb4(&OVERLAY_29_ID);
    func_020a1940(&OVERLAY_32_ID);
    func_020dc034();
    Struct_02000c9c_18* var2 = func_020daf90();
    func_020dafd4();
    LoadObjLoadingGraphicsResources(ctx);
    InitSubstructAndRegisterHandler0x14_020db228(ctx);
    ResetActor0209c174((Actor0209c174*)g_bgmPlayer);
    Dispatch0203a974With0x57000_0209c290(g_bgmPlayer);
    InitDisplayState0205e88c((Obj_0205e88c*)g_sePlayer);
    SetupContextForMode0205ea20(g_sePlayer, 100);
    SafeAllocator allocator;
    allocator.ResetAllocatorPointer();
    allocator.CreateTypeA(data_02114ec4, STARTUP_ALLOCATOR_SIZE);
    allocator.Reset();
    func_020421c4(&allocator);
    InitHalfwords02071688();
    char* table = CharacterColors_GetInstance();
    if (*(int*)0x027ffc20 != 0) {
        func_0200fb94((char*)var0, 6);
        func_02012010(var0, 0);
    }
    func_020ac910();

    for (;;) {
        if (func_02011570((Struct_02000c9c_9*)var0)) {
            func_0201155c((Struct_02000c9c_11*)var0);
            RUNTITLE();
        }
        if (func_0201201c(var0) != 5) {
            func_0208660c(var1);
        }
        func_02099cb8(var4);

        bool var5 = false;
        if (func_0201201c(var0) != 5) {
            inline_02000c9c_4(var0);
            inline_02000c9c_4(var0);
            if (func_0200fb9c((char*)var0) != 6) {
                RUNOV20();
            } else if (func_0200fb9c((char*)var0) == 6) {
                RUNOV20();
                if (*(unsigned char*)&var0->unk_6fc0[SCENE_SKIP_MEMBER_INDEX] == 0) {
                    func_020115b4((Struct_02000c9c_13*)var0, 1);
                    func_020a1940(&OVERLAY_16_ID);
                    int var6 = 1;
                    while (var6) {
                        RUNOV16(var6);
                    }
                    func_020a1bb4(&OVERLAY_16_ID);
                    func_020115c0((Struct_02000c9c_14*)var0);
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
                func_020a1940(&OVERLAY_16_ID);
                int var8 = 1;
                while (var8) {
                    RUNOV16(var8);
                }
                func_020a1bb4(&OVERLAY_16_ID);
                if (func_020115a8((Struct_02000c9c_12*)var0)) {
                    func_0200fb94((char*)var0, 0);
                    var7 = true;
                }
                break;
            case 8:
                ResetObjectState0205e8d4(g_sePlayer);
                FreeAndReinit0203a950(g_bgmPlayer);
                g_touchInput.Pause();
                func_020a1940(&OVERLAY_27_ID);
                func_020a1940(&OVERLAY_31_ID);
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
                case 2:
                    func_ov031_0222708c(2, 0);
                    break;
                case 3:
                    func_ov031_0222708c(3, 0);
                    break;
                case 4:
                    func_ov031_0222708c(4, 0);
                    break;
                case 5:
                    func_ov031_0222708c(5, 0);
                    break;
                default:
                    func_ov031_0222708c(1, 0);
                    break;
                }
#endif
                func_020d6c9c();
                func_020c983c();
                func_020c98f0(1);
                func_020a1940(&OVERLAY_32_ID);
                g_touchInput.Unpause();
                ResetActor0209c174((Actor0209c174*)g_bgmPlayer);
                Dispatch0203a974With0x57000_0209c290(g_bgmPlayer);
                SetInterruptHandler(1, (const void*)InitOverlay17ObjAndBumpBattleCounter02012bd8);
                EnableSpecificInterrupts(1);
                func_020d6c9c();
                EnableIRQInterrupts();
                func_020c3864(1);
                MapVRAMBanksToMainBG(0x60);
                func_020c391c(1, 0, 0);
                DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
                BG0CNT = (BG0CNT & 0x43) | 4;
                BG0CNT &= ~3;
                BG0CNT &= ~0x40;
                REG_POWCNT1 &= ~0x8000;
                func_020c9820();
                func_0200fb94((char*)var0, 6);
                func_02012010(var0, 1);
                var7 = false;
                break;
            }
        }
        if (func_02011570((Struct_02000c9c_9*)var0)) {
            func_0201155c((Struct_02000c9c_11*)var0);
            RUNTITLE();
        }
    }
}
