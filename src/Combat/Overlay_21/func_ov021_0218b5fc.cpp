#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "NitroSDK/Graphics.h"

static inline unsigned long inline_ov021_0218b5fc_2(volatile unsigned int* arg0) { return *arg0; }
static inline void inline_ov021_0218b5fc(volatile unsigned int* arg0, unsigned int arg1) { *arg0 = arg1; }

#if defined(jpn)
enum { Enum_ov021_0218b5fc_1288 = 0x608, Enum_ov021_0218b5fc_7720 = 0x1c4c, Enum_ov021_0218b5fc_307768 = 0x48e10, Enum_ov021_0218b5fc_3512 = 0xd90, Enum_ov021_0218b5fc_3464 = 0xd4c };
#else
enum { Enum_ov021_0218b5fc_1288 = 0x508, Enum_ov021_0218b5fc_7720 = 0x1e28, Enum_ov021_0218b5fc_307768 = 0x4b238, Enum_ov021_0218b5fc_3512 = 0xdb8, Enum_ov021_0218b5fc_3464 = 0xd88 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

#if defined(jpn)
#define func_020c51dc func_020c6ca8
#endif

#if defined(jpn)
#define func_020c39a0 func_020c546c
#endif

struct AllocatorUnion;
struct Struct_0203d028;
struct Struct_0200f3a4_9;
struct Struct_0203bdb0;
struct GameResources;
struct Struct_0209c3b4_2;
struct Struct_02109bf4_4;
struct Struct_02109bf4_3;

extern "C" void func_020a1df8(int arg0);
extern "C" void func_020a1e54(int arg0);
extern "C" void func_020a1940(unsigned int arg0);
extern "C" void func_0200fb84(int* arg0, int arg1);
extern "C" void func_020c39a0(short* arg0, int arg1);
extern "C" void* func_0203bd08(void);
extern "C" void func_0203bd24(char* arg0);
extern "C" int* func_0203bd14();
extern "C" int func_0203be4c(void* arg0);
extern "C" void func_0203c35c(int* arg0);
extern "C" void MapVRAMBanksToLCDC(unsigned short mask);
extern "C" void func_020ca458(unsigned int value, void* dest, int count);
extern "C" int DisableLCDCMappedVRAMBanks(void);
void Finish3DRendering();
extern "C" void func_020c51dc();
extern "C" void func_020c537c();
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
void UpdateVRAMStagingVRAMBanks();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void func_020bb780(void* arg0, int arg1);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void func_020c391c(int arg0, int arg1, int arg2);
extern "C" void func_020c3984(unsigned int arg0);
extern "C" void func_020c5588(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_020c555c(int arg0);
extern "C" void func_0207de48(void* arg0, int arg1, int arg2);
extern "C" void* func_020421a0();
extern "C" void func_02042c68(void* arg0);
extern "C" void func_02043124(void* arg0);
extern "C" void func_020440a4(void* arg0);
extern "C" void func_0207df50(Struct_0203d028* arg0);
extern "C" void func_0207df90(char* arg0);
extern "C" void func_020432c4(void* arg0);
extern "C" void func_0207dfac(char* arg0);
extern "C" void func_020100a0(GameState* arg0, int arg1);
extern "C" int func_020100a8(GameState* arg0);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_ov009_0218454c(void* arg0, int arg1, int arg2);
extern "C" void* func_02010954(char* arg0);
extern "C" void func_ov009_021842a0(void* arg0, SafeAllocator* arg1);
extern "C" void func_0209c3b4(Struct_0209c3b4_2* arg0, int arg1);
extern "C" void func_020c9820();
extern "C" void func_020c38d4();
extern "C" void func_02010124(Struct_0200f3a4_9* arg0);
extern "C" int func_0200fb9c(char* arg0);
extern "C" void func_02012efc();
extern "C" void func_ov021_0218bb30(void* arg0);
extern "C" void func_020bbcb4();
extern "C" void func_ov009_02184ca4(void* arg0);
extern "C" void func_0203bdb0(Struct_0203bdb0* arg0);
void UpdateAndApplyBrightness(GameResources* resources);
extern "C" void func_ov009_02184848(void* arg0);
extern "C" void func_0209c678(Struct_02109bf4_4* arg0, int arg1);
extern "C" void func_0203ad88(void* arg0, void* arg1, int arg2);
extern "C" void func_0203aa08(void* arg0);
extern "C" void func_0209c20c(Struct_02109bf4_3* arg0);
extern "C" void func_02043000(char* arg0);
extern char data_02114e20;
extern char data_02109bf4;
extern int data_02114e50;

struct Struct_ov021_0218bbc4 {
    unsigned short unknown_0_[8];
};

extern Struct_ov021_0218bbc4 data_ov021_0218bbc4;

struct Struct_ov021_0218b5fc {
    char unknown_0_[0x28];
    unsigned char unknown_28_;
    char unknown_29_[0x2c - 0x29];
    SafeAllocator unknown_2c_;
    void* unknown_40_;
    char unknown_44_[0xb4 - 0x44];
    char* unknown_b4_;
    int unknown_b8_;
};

struct Struct_ov021_0218b5fc_2;
extern "C" void func_ov021_0218baf8(Struct_ov021_0218b5fc_2* arg0);

// USA: func_ov021_0218b5fc
extern "C" ARM void func_ov021_0218b5fc(Struct_ov021_0218b5fc* arg0) {
#if !defined(jpn)
    func_020a1df8(3);
#endif
    func_020a1940(OVERLAY_ID(9));
    func_020a1940(OVERLAY_ID(23));
    GameState* var0 = GameState::GetInstance();
    func_0200fb84((int*)var0, (int)arg0);
    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
    BackgroundLoader::GetInstance()->MaybeReset();
    void* var1 = func_0203bd08();
    func_0203bd24((char*)var1);
    *(int*)var1 = 0;
    int* var2 = func_0203bd14();
    *var2 = func_0203be4c(var1) + 0x200;
    func_0203c35c(var2);
    var2[Enum_ov021_0218b5fc_1288 / 4] = 0x7000;
    MapVRAMBanksToLCDC(0x1ff);
    func_020ca458(0, (void*)0x6800000, 0xa4000);
    DisableLCDCMappedVRAMBanks();
    Finish3DRendering();
    func_020c51dc();
    func_020c537c();
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(1);
    func_020bb48c(1, 1);
    MapVRAMBanksToTexturePalette(0x40);
    func_020bb780((void*)0x4000, 1);
    MapVRAMBanksToMainBG(0x10);
    MapVRAMBanksToSubBG(4);
    MapVRAMBanksToMainObj(0x20);
    unsigned int var3 = inline_ov021_0218b5fc_2(&DISPCNT);
#if defined(jpn)
    var3 = (var3 & 0xffcfffef) | 0x10;
#else
    var3 &= 0xffcfffef;
    var3 |= 0x10;
#endif
    inline_ov021_0218b5fc(&DISPCNT, var3);
    MapVRAMBanksToSubObj(8);
    DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    var3 = inline_ov021_0218b5fc_2(&DISPCNT);
    var3 = (var3 & ~0x1f00) | 0x1f00;
    inline_ov021_0218b5fc(&DISPCNT, var3);
    func_020c391c(1, 0, 1);

    BG1CNT = (BG1CNT & 0x43) | 0x1d00;
    BG2CNT = (BG2CNT & 0x43) | 0x1e08;
    BG3CNT = (BG3CNT & 0x43) | 0x1f0c;
    BG0CNT = (BG0CNT & ~3) | 2;
    BG1CNT = (BG1CNT & ~3) | 3;
    BG2CNT = (BG2CNT & ~3) | 1;
    BG3CNT = BG3CNT & ~3;
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
    func_020c3984(0);

    BG0CNTSUB = (BG0CNTSUB & 0x43) | 0x1d00;
    BG1CNTSUB = (BG1CNTSUB & 0x43) | 0x1e10;
    BG2CNTSUB = (BG2CNTSUB & 0x43) | 0x1f18;
    BG0CNTSUB = (BG0CNTSUB & ~3) | 2;
    BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
    BG2CNTSUB = BG2CNTSUB & ~3;
    BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
    *(unsigned short*)0x4000304 |= 0x8000;
    func_020c5588(0, 0, 0x7fff, 0, 0);

    EdgeColors0218b5fc edges = data_ov021_0218bbc4;
    CallWithAddr4000330_020c555c((int)&edges);
    func_0207de48(self->state44, 0x4000, 0x40);
    void* controller = GetGlobalField0x1c020421a0();
    func_02042c68(controller);
    func_02043124(controller);
    TailForward020440a4(controller);
    *(char**)((char*)controller + kControllerBackupOffset) = self->state44;
    CopyInternalFields0207df50((Foo0207df50*)self->state44);
    RestorePairTables0207df90(self->state44);
    func_020432c4(controller);
    BackupPairTables0207dfac(self->state44);
    SetField0x3acValue_020100a0(gs, 0);
    self->allocator.CreateTypeA(AllocateAligned4_02012d88((AllocatorUnion*)&data_02114e20, kSceneAllocatorSize), kSceneAllocatorSize);
    self->allocator.Reset();
    self->scene = self->allocator.Allocate(kSceneSize);
    func_ov009_0218454c(self->scene, 0, CreationMode_NewGame);
    self->slot = (char*)FindSlotWithNegShort02010954((char*)gs);
    *(short*)(self->slot + 0x568) = GetField0x3acValue_020100a8(gs);
    *(char**)((char*)self->scene + kSceneSlotOffset) = self->slot;
    func_ov009_021842a0(self->scene, &self->allocator);
    SetStateAndDispatch0209c3b4((Actor0209c3b4*)&data_02109bf4, 2);
    DelayThenSyncBit0_020c9820();
    RestoreDisplayMode_020c38d4();
    DISPCNTSUB |= 0x10000;
    func_02010124((Struct_0200f3a4_9*)var0);

    for (;;) {
        if (func_0200fb9c((char*)var0) == 0 || arg0->unknown_b8_ != 0) {
            break;
        }
        func_02012efc();
        func_ov021_0218baf8((Struct_ov021_0218b5fc_2*)arg0);
        func_ov021_0218bb30(arg0);
        arg0->unknown_28_ = 1;
        func_020c9820();
        func_020bbcb4();
        func_ov009_02184ca4(arg0->unknown_40_);
        func_0203bdb0((Struct_0203bdb0*)func_0203bd08());
        UpdateAndApplyBrightness((GameResources*)arg0);
        data_02114e50++;
        var0->CalculateDeltaTime(0x411b);
    }

    func_ov009_02184848(arg0->unknown_40_);
    func_0209c678((Struct_02109bf4_4*)&data_02109bf4, 0);
    func_0203ad88(&data_02109bf4, 0, 0);
    func_0203aa08(&data_02109bf4);
    func_0209c20c((Struct_02109bf4_3*)&data_02109bf4);
    func_02043000((char*)var5);
    func_0207df50((Struct_0203d028*)arg0->unknown_44_);
    func_0200fb84((int*)var0, 0);
#if !defined(jpn)
    func_020a1e54(1);
#endif
}
