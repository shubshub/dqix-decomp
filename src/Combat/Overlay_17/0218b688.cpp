#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "World/ZoneLootableRecord.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"
#include "Resource/ActionDataTables.h"
#include "World/LootableContainer.h"
#include "Graphics/LightingManager.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define func_020c51dc func_020c6ca8
#endif

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct GameResources;
struct AllocatorUnion;

extern "C" unsigned int* func_020d6c00();
extern "C" void func_020466e4(unsigned int* arg0, unsigned int arg1);
struct Struct_02038598_4;
extern "C" void func_020466f4(Struct_02038598_4*, unsigned int);
extern "C" int func_0201201c(void* arg0);
extern "C" void func_02012010(void* arg0, int arg1);
struct Struct_02000c9c_12;
extern "C" unsigned char func_020115a8(Struct_02000c9c_12*);
struct Struct_02000c9c_14;
extern "C" void func_020115c0(Struct_02000c9c_14*);
extern "C" void func_020daf9c(int arg0, int arg1, int arg2, int arg3);
void SetMainBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
extern "C" void func_0200fb84(int*, int);
extern "C" char* func_02012fe4();
extern "C" void* func_0200fd0c(GameState* arg0);
extern "C" void func_0201133c(char*);
extern "C" void* func_020a6084();
extern "C" void func_020a6180(void* arg0);
extern "C" void func_020a6194(void* arg0);
extern "C" void* func_0203b628();
extern "C" void func_0203b634(char*);
extern "C" void* func_0203bd08();
extern "C" void func_0203bd24(char*);
extern "C" void* func_0203cf4c();
struct Struct_0203cf58;
extern "C" void func_0203cf58(Struct_0203cf58*);
extern "C" void* func_0202ae18();
extern "C" void func_0202aec0(void* arg0);
extern "C" void* func_0202ae24();
extern "C" void func_0205e22c(void* arg0);
extern "C" void* func_02011584(void* arg0);
extern "C" void func_02099898(unsigned int*);
extern "C" void func_ov017_021b2f64(unsigned char*);
extern "C" void* func_0208e0a8();
extern "C" void func_0208e4bc(char*);
extern "C" void* func_020e2ff8();
struct Struct_020e3004;
extern "C" void func_020e3004(Struct_020e3004*);
extern "C" void* func_020e3808();
struct Struct_020e3814;
extern "C" void func_020e3814(Struct_020e3814*);
extern "C" void* func_020e3580();
struct Struct_020e358c;
extern "C" void func_020e358c(Struct_020e358c*);
extern "C" char* func_0205ec34();
extern "C" char* func_02094d6c();
extern "C" unsigned char func_0200fb9c(char*);
extern "C" void func_0200fb94(char*, unsigned char);
extern "C" void func_0205facc(void* arg0);
extern "C" void func_02095518(char*);
extern "C" void func_020ac0dc();
extern "C" void func_02096524(void* arg0);
extern "C" void* func_020704fc();
struct Struct_02108d5c;
extern "C" void func_02070508(Struct_02108d5c*);
extern "C" void func_0209c2e0(void* arg0, int arg1, int arg2);
extern "C" void func_0205e944(void* arg0, int arg1);
extern "C" void* func_020d7a50();
struct Struct_0214e34c;
extern "C" void func_020d7a5c(Struct_0214e34c*);
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
void UpdateVRAMStagingVRAMBanks();
void Finish3DRendering();
extern "C" unsigned int DisableTextureImageVRAMBanks();
extern "C" unsigned int DisableTexturePaletteVRAMBanks();
extern "C" unsigned int DisableMainBGVRAMBanks();
extern "C" unsigned int DisableSubBGVRAMBanks();
extern "C" unsigned int DisableMainObjVRAMBanks();
extern "C" unsigned int DisableSubObjVRAMBanks();
extern "C" void func_ov017_0218d274(void* arg0);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int v);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void func_020c391c(int arg0, int arg1, int arg2);
extern "C" void func_020c3984(unsigned int arg0);
extern "C" void func_020c51dc();
extern "C" void func_020c537c();
extern "C" void func_0202ac74();
extern "C" void func_02028d68(int arg0);
extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void func_020bb780(void* arg0, int arg1);
extern "C" void func_0202c288(void* arg0);
extern "C" int func_0202b7d8(int*);
extern "C" void func_020100a0(GameState* arg0, int arg1);
extern "C" unsigned char func_020100a8(GameState* arg0);
struct Struct_0202c1a4;
extern "C" int func_0202c1a4(Struct_0202c1a4*);
extern "C" void func_020c555c(int);
extern "C" void func_ov017_021a02f0(void* arg0);
extern "C" void func_02079870(char*);
extern "C" void func_020798b8(char*);
struct Struct_020995c0;
extern "C" void func_020998c4(Struct_020995c0*);
extern "C" void* func_0209cb68();
struct Struct_0209cbb8;
extern "C" void func_0209cbb8(Struct_0209cbb8*);
extern "C" void func_0209cbcc(void* arg0);
extern "C" void* func_02099f60();
extern "C" void func_02099f6c(char*);
extern "C" void func_020e5058();
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_020e50ec(void* arg0, unsigned int arg1);
extern "C" void func_020e5114();
extern "C" void func_0207de48(void* arg0, int arg1, int arg2);
extern "C" void func_02013718(char* arg0, int arg1, int arg2);
extern "C" void func_0202df68(void* arg0);
struct Struct_0204a120_2;
extern "C" void func_020a2cf0(Struct_0204a120_2*);
extern "C" void func_020a2010(void* arg0);
extern "C" void func_020100c4(GameState* arg0, int arg1);
struct Struct_02046958;
extern "C" void func_02046958(Struct_02046958*);
extern "C" void func_ov017_021a124c(void* arg0);
extern "C" void func_ov017_0218f064(void* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" int func_02011ff0(void* arg0, int arg1);
extern "C" void* func_0200ff58(GameState* arg0, int arg1);
extern "C" void func_020546a0(void* arg0, int arg1);
extern "C" char* func_02053c6c(unsigned char*);
extern "C" int func_020aaf84(void* arg0, int arg1, int arg2, int arg3);
extern "C" int func_020ac864(int arg0);
extern "C" int func_020ab9c0(int arg0);
extern "C" int func_020abca8();
struct Struct_02011544;
extern "C" void func_02011544(Struct_02011544*);
struct Struct_02000c9c_9;
extern "C" int func_02011570(Struct_02000c9c_9*);
extern "C" void* func_0208e9e8();
extern "C" void func_0208ea10(void* arg0, int arg1);
unsigned long long GetCurrentTimestamp();
extern "C" int func_02011494(char*, void*);
extern "C" int func_020dcd40();
extern "C" void func_ov017_02191108(void* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_020897b4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);
extern "C" void func_0201099c(void* arg0);
extern "C" void func_02070378(char*);
extern "C" void func_02010774(char*, int);
extern "C" void func_020107a8(char*, int);
extern "C" void func_020107dc(char*, int);
extern "C" void func_0206df6c(void* arg0, unsigned char* arg1, int arg2, int arg3);
extern "C" void func_020120f0(void* arg0);
extern "C" int func_02032370(int arg0);
extern "C" void func_02039768(GameObject* arg0, void* arg1);
extern "C" short func_020100b0(GameState* arg0);
extern "C" void func_020a2770(void* arg0, short arg1);
extern "C" int rand();
extern "C" void func_0201206c(void* arg0, int arg1);
extern "C" void func_0206dfe8(void* arg0, int arg1, int arg2);
extern "C" void* func_02057924();
struct Struct_02057930;
extern "C" void func_02057930(Struct_02057930*);
extern "C" void func_02057978(Struct_02057930*);
extern "C" void* func_02027ca4();
#if defined(jpn)
extern "C" void func_02028894(void* arg0, void* arg1);
#else
extern "C" void func_02028894(void* arg0, void* arg1, void* arg2);
#endif
extern "C" void func_020287b4(void* arg0);
extern "C" void* func_02039e70();
extern "C" void func_02039e7c(void* arg0);
struct Struct_0203a54c;
extern "C" void func_0203a54c(Struct_0203a54c*);
extern "C" void* func_020421a0();
extern "C" void func_02042c68(void* arg0);
extern "C" void func_02043124(void* arg0);
extern "C" void func_02042b30(void* arg0, void* arg1);
extern "C" void func_ov017_0219b624(void* arg0);
extern "C" void func_ov017_0219ba0c(void* arg0, int arg1);
struct Struct_0203d028;
extern "C" void func_0207df50(Struct_0203d028*);
extern "C" void func_0207df90(char*);
extern "C" void func_020432c4(void* arg0);
extern "C" void func_0207dfac(char*);
extern "C" void func_02020554(void* arg0);
extern "C" void* func_020936f8();
extern "C" void func_020938f0(void* arg0);
extern "C" void func_020939ac(void* arg0);
extern "C" void func_0206ebf4(char*);
extern "C" void* func_0207d78c();
struct Struct_0207d798;
extern "C" void func_0207d798(Struct_0207d798*);
extern "C" int func_0206dfb0(int arg0, unsigned char* arg1, int arg2);
extern "C" void func_ov017_0219bfb4(int arg0, int arg1);
extern "C" void func_ov017_0219e310(unsigned char*, int);
struct Struct_0201bdac_2;
struct Struct_0201bdac;
extern "C" void func_020469b4(Struct_0201bdac_2*, Struct_0201bdac*);
struct Struct_0203d028_4;
extern "C" void func_ov017_021a3498(Struct_0203d028_4*);
extern "C" void func_ov017_021baedc(void* arg0, int arg1);
extern "C" void func_ov017_021b2174(unsigned char*);
struct Struct_0206f81c_2;
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2*, char*);
extern "C" void func_ov017_021b2bd0(void* arg0, int arg1, int arg2);
extern "C" int GetMainBGAssignedVRAMSize();
extern "C" void func_020ca458(unsigned int value, void* dest, int count);
extern "C" void func_020c9820();
extern "C" void func_020c38d4();
struct Struct_0200f3a4_9;
extern "C" void func_02010124(Struct_0200f3a4_9*);
extern "C" void func_020c3a0c(int arg0);
struct Struct_02015438;
extern "C" int func_02046b24(Struct_02015438**);
extern "C" void func_0206e424(void* arg0, int arg1);
extern "C" void func_ov017_021bdbf0(unsigned char*);
extern "C" void func_0202ad30();
extern "C" void func_0202adf0();
extern "C" void func_02012efc();
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_02046b08(void**);
struct Vector3i;
struct Struct_020115d0;
extern "C" int func_020115d0(Struct_020115d0*);
extern "C" int func_020115e8(void* arg0);
extern "C" void func_02011600(void* arg0);
struct Struct_02071488;
extern "C" int func_02071574(unsigned int, Struct_02071488*);
extern "C" int func_02011610(void* arg0);
extern "C" int func_02011628(void* arg0);
extern "C" void func_02011634(void* arg0);
extern "C" void func_020bc028(int arg0);
extern "C" void func_020d84e0();
extern "C" void func_0202aff4(void* arg0);
extern "C" void func_02043368(void* arg0);
extern "C" void func_ov017_0218cbd4(void* arg0);
extern "C" void func_ov017_02191cc0(void* arg0);
extern "C" void func_ov017_02195a20(void* arg0);
extern "C" void func_020d9834(int arg0);
extern "C" void func_0209c840(void* arg0);
extern "C" void func_0203aa08(void* arg0);
extern "C" void func_020bbd9c();
extern "C" void func_0203bd88(void* arg0);
extern "C" void func_0204359c(void* arg0, int arg1);
extern "C" void func_0203dd94(char*);
extern "C" void func_ov017_0219a188(void* arg0);
extern "C" void func_ov017_021a63cc(void* arg0);
extern "C" void func_020d86d0(int arg0, int arg1);
extern "C" void func_ov017_021a4358(int arg0);
struct Struct_0203bdb0;
extern "C" void func_0203bdb0(Struct_0203bdb0*);
extern "C" int* func_ov017_021a193c(int*);
extern "C" void func_020439b0(void* arg0, int arg1);
struct Struct_020579ec;
extern "C" void func_020579ec(Struct_020579ec**);
extern "C" void func_ov017_021a63d0(void* arg0);
extern "C" void func_ov017_0219a18c(void* arg0);
extern "C" void func_0203ba74(void* arg0);
extern "C" void func_02027438(void* arg0);
struct Struct_020275e4;
extern "C" void func_020275e4(Struct_020275e4*);
struct Struct_0205eac8;
extern "C" int func_0205eac8(Struct_0205eac8*);
extern "C" void func_0205ea20(void* arg0, int arg1);
struct Struct_02109bf4_3;
extern "C" void func_0209c20c(Struct_02109bf4_3*);
struct Struct_0205e8ec;
extern "C" void func_0205e8ec(Struct_0205e8ec*);
extern "C" void func_ov017_021a3ef0(void* arg0);
struct Struct_0203cfb4;
extern "C" void func_0203cfb4(Struct_0203cfb4*);
extern "C" void func_ov017_021a316c(void* arg0);
extern "C" void func_02043000(char*);
extern "C" void func_ov017_02190238(void* arg0);
extern "C" void func_02013750(void* arg0, int arg1);
extern "C" void func_020998ac(int*);
extern "C" void func_0209cd24(Struct_0209cbb8*);
extern "C" void func_ov017_0219b938(void* arg0);
extern "C" void func_ov017_0219bc50(unsigned char*);
extern "C" void func_02012da4(AllocatorUnion*, void*);
extern "C" void func_ov017_021a0790(char*);
extern "C" void func_ov017_021a0964(char*);
extern "C" void func_ov017_021a0ba8(char*);
extern "C" void func_ov017_021a0f40(char*);
extern "C" void func_ov017_021a1114(char*);
extern "C" void func_ov017_021a0d6c(char*);
extern "C" void func_ov017_021a0470(void* arg0);
extern "C" void func_0200fd58(GameState* arg0);
extern "C" void func_020a1edc();
extern "C" void func_020a1de4();
extern "C" void func_020e5094();
extern "C" void func_ov004_0216e9cc();
extern "C" void func_ov004_0216f854();

struct Struct_02109bf4_9 {
    char unknown_0_[0xc8];
    unsigned char unknown_c8_;
};

struct Struct_ov017_021d82e0_2 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    int unknown_4_;
};

extern Flags02109bf4 data_02109bf4;
extern char g_sePlayer;
extern char data_ov017_021d615c;
extern char data_02114e20;
extern char data_ov017_021d736c;
extern char data_ov017_021d7378;
extern Struct_ov017_021d82e0_2 data_ov017_021d82e0;
extern int data_02114e50;

struct Struct_ov017_0218b688 {
    unsigned short unknown_0_;
    char unknown_2_[5];
    unsigned char unknown_7_;
    char unknown_8_[8];
    int unknown_10_[3];
    unsigned short unknown_1c_;
    char unknown_1e_[2];
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
};

struct Struct_ov017_0218b688_2 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov017_0218b688_3 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    char unknown_25_[3];
    int unknown_28_;
    int unknown_2c_;
};

struct Struct_ov017_0218b688_4 {
    char* unknown_0_;
};

struct Struct_01ff91ac_17 {
    char unknown_0_[0x48];
};

struct Struct_ov017_0218b688_5 {
    char unknown_0_[0x28];
    unsigned char unknown_28_;
    char unknown_29_[0x38 - 0x29];
    char unknown_38_[0xc4 - 0x38];
    SafeAllocator unknown_c4_;
    char unknown_d8_[0x150 - 0xd8];
    char unknown_150_[0x27c - 0x150];
#if !defined(jpn)
    char unknown_27c_[0x2cc - 0x27c];
#endif
    char unknown_2cc_[0x87c - 0x2cc];
    char unknown_87c_[0xf0c - 0x87c];
#if defined(jpn)
    char unknown_f0c_[0x28f8 - 0xebc];
#else
    char unknown_f0c_[0x2b08 - 0xf0c];
#endif
    int unknown_2b08_;
    char unknown_2b0c_[0x2b90 - 0x2b0c];
    Struct_02012fa4 unknown_2b90_[0x12];
    char unknown_3520_[0x3634 - 0x3520];
    unsigned char unknown_3634_[0x12];
    unsigned char unknown_3646_[0x12];
    unsigned char unknown_3658_[0x12];
    char unknown_366a_[0x36d0 - 0x366a];
    char* unknown_36d0_;
    char unknown_36d4_[0x36fc - 0x36d4];
    void* unknown_36fc_;
    void* unknown_3700_;
    void* unknown_3704_;
    void* unknown_3708_;
    void* unknown_370c_;
    char unknown_3710_[0x371c - 0x3710];
    Struct_ov017_0218b688_3* unknown_371c_;
    char unknown_3720_[0x3734 - 0x3720];
    char* unknown_3734_;
    char unknown_3738_[0x373c - 0x3738];
    Struct_01ff91ac_17 unknown_373c_[4];
#if defined(jpn)
    char unknown_364c_[0x3b3c - 0x385c];
#else
    char unknown_385c_[0x3b4c - 0x385c];
#endif
    void* unknown_3b4c_;
    char unknown_3b50_[0x3b60 - 0x3b50];
    char* unknown_3b60_;
    char unknown_3b64_[0x4324 - 0x3b64];
    int unknown_4324_;
#if defined(jpn)
    char unknown_4108_[0x4434 - 0x4328];
#else
    char unknown_4328_[0x44c4 - 0x4328];
#endif
    void* unknown_44c4_;
};

#if defined(jpn)
enum { Enum_ov017_0218b688_15820 = 0x3d44, Enum_ov017_0218b688_396 = 0x180, Enum_ov017_0218b688_24 = 0x10 };
#else
enum { Enum_ov017_0218b688_15820 = 0x3dcc, Enum_ov017_0218b688_396 = 0x18c, Enum_ov017_0218b688_24 = 0x18 };
#endif
#define IS_OBJ_FLAG2_SET(h) ((h)->unknown_0_ != 0 ? ((*(int*)((h)->unknown_0_ + Enum_ov017_0218b688_15820) & 2) ? 1 : 0) : 0)

// USA: func_ov017_0218b688
extern "C" ARM void func_ov017_0218b688(Struct_ov017_0218b688_5* arg0) {
    char var0[0x2c8];
    char var1[0x68];
    char var2[8];
    unsigned char var3[4];

    SafeAllocator::GetLiveCount();
    unsigned int* var4 = func_020d6c00();
    func_020466e4(var4, 0x100);
    GameState* var5 = GameState::GetInstance();
    int var6 = func_0201201c(var5);
    unsigned char var7 = func_020115a8((Struct_02000c9c_12*)var5);
    if (var6 != 5 && var7 != 4 && var7 != 8 && var7 != 0xc) {
        func_020daf9c(1, 0, 1, 0);
    }
    SetMainBrightness((GameResources*)arg0, -16, 0);
    SetSubBrightness((GameResources*)arg0, -16, 0);
    func_0200fb84((int*)var5, (int)arg0);
    BackgroundLoader* var8 = BackgroundLoader::GetInstance();
    char* var9 = func_02012fe4();
    Struct_ov017_0218b688* var10 = (Struct_ov017_0218b688*)func_0200fd0c(var5);
    var8->MaybeReset();
    func_0201133c((char*)var5);
    void* var11 = func_020a6084();
    func_020a6180(var11);
    func_020a6194(var11);
    void* var12 = func_0203b628();
    func_0203b634((char*)var12);
    void* var13 = func_0203bd08();
    func_0203bd24((char*)var13);
    void* var14 = func_0203cf4c();
    func_0203cf58((Struct_0203cf58*)var14);
    void* var15 = func_0202ae18();
    func_0202aec0(var15);
    SetFlags00((GameResources*)arg0, 2);
    func_0205e22c(func_0202ae24());
    void* var16 = func_02011584(var5);
    func_02099898((unsigned int*)var16);
    for (int var17 = 0; var17 < 4; var17++) {
        func_ov017_021b2f64((unsigned char*)&arg0->unknown_373c_[var17]);
    }
    LootableContainerManager::GetMainInstance()->Reset();
    func_0208e4bc((char*)func_0208e0a8());
    func_020e3004((Struct_020e3004*)func_020e2ff8());
    func_020e3814((Struct_020e3814*)func_020e3808());
    func_020e358c((Struct_020e358c*)func_020e3580());
    char* var18 = func_0205ec34();
    char* var19 = func_02094d6c();
    if (func_020115a8((Struct_02000c9c_12*)var5) == 0) {
        if (func_0201201c(var5) == 5 || func_0200fb9c((char*)var5) == 4) {
            func_0205facc(var18);
            func_02095518((char*)var19);
            func_020ac0dc();
        }
        func_02096524(var19);
    }
    *(int*)(var18 + 0x480) = 0;
    *(int*)(var18 + 0x47c) = 0;
    func_02070508((Struct_02108d5c*)func_020704fc());
    func_0209c2e0(&data_02109bf4, 0x7f, 0);
    func_0205e944(&g_sePlayer, 0x7f);
    data_02109bf4.flagsC8 &= ~4;
    ResetAndClearFlags020d7a5c((ResetObj020d7a5c*)GetGlobalResetObj020d7a50());
    if (GetWord0x7f6c_0201201c(gs) == 5 && GetByte0x4_0200fb9c((char*)gs) != 9) {
        SetByte0x4_0200fb94((char*)gs, 6);
    }

    LockStagedTextureVRAMCopying();
    DisableTextureImageVRAMBanks();
    DisableTexturePaletteVRAMBanks();
    DisableMainBGVRAMBanks();
    DisableSubBGVRAMBanks();
    DisableMainObjVRAMBanks();
    DisableSubObjVRAMBanks();
    func_ov017_0218d274(arg0);
    MapVRAMBanksToTexturePalette(0x40);
    MapVRAMBanksToMainBG(0x10);
    *(volatile unsigned int*)0x4000000 &= ~0x7000000;
    *(volatile unsigned int*)0x4000000 &= ~0x38000000;
    *(volatile unsigned short*)0x400000a = (*(volatile unsigned short*)0x400000a & 0x43) | 4;
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x1300;
    func_020c391c(1, 0, 1);
    func_020c3984(0);
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1300;
    MapVRAMBanksToSubBG(0x80);
    unsigned short* var20 = (unsigned short*)0x4001008;
    var20[0] = (var20[0] & 0x43) | 0x4e00;
    var20[1] = (var20[1] & 0x43) | 0xd00;
    MapVRAMBanksToMainObj(0x20);
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & 0xffcfffef) | 0x10;
    MapVRAMBanksToSubObj(0x100);
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    *(unsigned short*)0x4000304 &= ~0x8000;
    Finish3DRendering();
    func_020c51dc();
    func_020c537c();
    unsigned short* var21 = (unsigned short*)0x4001008;
    *(unsigned short*)0x400000a &= ~3;
    *(unsigned short*)0x4000008 = (*(unsigned short*)0x4000008 & ~3) | 1;
    var21[0] = (var21[0] & ~3) | 1;
    var21[1] = (var21[1] & ~3) | 2;
    var21[2] = (var21[2] & ~3);
    func_0202ac74();
    func_02028d68(3);
    func_020bb48c(4, 1);
    func_020bb780((void*)0x4000, 1);

    func_0202c288(var15);
    if (func_0202b7d8((int*)var15) == 0) {
        func_020100a0(GameState::GetInstance(), 0);
    } else {
        GameState* var22 = GameState::GetInstance();
        func_020100a0(var22, func_0202c1a4((Struct_0202c1a4*)var15));
    }
    func_020c555c((int)&data_ov017_021d615c);
    func_ov017_021a02f0(arg0);
    func_020466f4((Struct_02038598_4*)var4, 0x100);
    Struct_02108e10* var23 = func_020797dc();
    func_02079870((char*)var23);
    func_02079900(var23, (SafeAllocator*)arg0->unknown_150_);
    func_020998c4((Struct_020995c0*)var16);
    void* var24 = func_0209cb68();
    func_0209cbb8((Struct_0209cbb8*)var24);
    func_0209cbcc(var24);
    func_02099f6c((char*)func_02099f60());
    func_0204719c(&arg0->unknown_2b90_[11]);
    int var25 = 0;
#if !defined(jpn)
    func_020e5058();
    void* var26 = func_02012d88((AllocatorUnion*)&data_02114e20, 0x1866);
    if (var26 != 0) {
        func_020e50ec(var26, 0x1866);
    }
    func_020e5114();
#endif
    if (func_0200fb9c((char*)var5) == 9) {
        var25 = 1;
        arg0->unknown_c4_.CreateTypeA(func_02012d88((AllocatorUnion*)&data_02114e20, 0x30000), 0x30000);
        func_0207de48(arg0->unknown_f0c_, 0x10, 0x10);
    }
    func_02013718(var9, (int)arg0->unknown_38_, (int)arg0->unknown_2cc_);
    func_0202df68(var0);
    func_020a2cf0((Struct_0204a120_2*)var0);
    func_020a2010(var0);
    func_020100c4(var5, (int)var0);
    func_02046958((Struct_02046958*)arg0->unknown_36fc_);
    func_02046958((Struct_02046958*)arg0->unknown_3700_);
    func_02046958((Struct_02046958*)arg0->unknown_3704_);
    func_ov017_021a124c(arg0->unknown_3708_);
    int var27;
    int var28;
    int var29 = 0;
    Struct_ov017_0218b688_3* var30 = arg0->unknown_371c_;
    var30->unknown_24_ = var29;
    var30->unknown_28_ = var29;
    var30->unknown_2c_ = var29 - 1;
    var27 = var29;
    int var31 = var29;
    int var32 = var29;

    if (func_0200fb9c((char*)var5) != 6 && func_0200fb9c((char*)var5) != 9) {
        if (func_020115a8((Struct_02000c9c_12*)var5) != 0) {
            var27 = 1;
        } else {
            if (func_0200fb9c((char*)var5) == 0 || func_0200fb9c((char*)var5) == 5) {
                int var33 = func_0200fb9c((char*)var5) == 5;
                var27 = var29 = 1;
                var31 = !var33;
                if (func_0201201c(var5) == 6) {
                    var28 = 0;
                    if (func_020aaf84(var2, 0, var33, 0) != 0) {
                        if (func_020ac864(var31 == 0) != 0) {
                            var28 = 1;
                            if (var33 != 0 && func_020ab9c0(0) == 0 &&
                                func_020abca8() == 0) {
                                func_02011544((Struct_02011544*)var5);
                                var28 = 0;
                            }
                        } else {
                            func_02011544((Struct_02011544*)var5);
                        }
                    }
                    if (var28 == 0) {
                        var29 = 0;
                        var27 = var29;
                        var31 = var29;
                    }
                }
            }
            if (func_0200fb9c((char*)var5) != 5) {
                func_0208ea10(func_0208e9e8(), 1);
            }
            var5->mainTimestamp_ = GetCurrentTimestamp();
            var5->altTimestamp_ = GetCurrentTimestamp();
        }

        if (var27 != 0) {
            char* var34 = (char*)func_02010828(var5);
            int var35 = func_02011494((char*)var5, var3);
            unsigned char* var36;
            if (func_020115a8((Struct_02000c9c_12*)var5) != 0) {
                var36 = var3;
            } else {
                var36 = (unsigned char*)(var34 + 0xf78);
                var35 = *(unsigned char*)(var34 + 0xf7c);
            }
            for (int var37 = 0; var37 < var35; var37++, var36++) {
                int var38 = *var36;
                if (var38 == func_020100a8(var5)) {
                    func_ov017_0218f064(arg0, var38, 0x200, 1, 0);
                } else {
                    if (func_02011ff0(var5, var38) > 0) {
                        func_ov017_0218f064(arg0, var38, 4, 1, func_02011ff0(var5, var38));
                    } else {
                        func_ov017_0218f064(arg0, var38, 0x1000, 1, 0);
                    }
                    void* var39 = func_0200ff58(var5, var38);
                    if (var39 != 0) {
                        func_020546a0(var39, func_020100a8(var5));
                    }
                }
                char* var40 = (char*)func_0200ff1c(var5, var38);
                if (var40 != 0) {
                    char* var41 = func_02053c6c((unsigned char*)var40);
                    if (var41 != 0 && (*(int*)(var41 + 0x18) & 1)) {
                        *(int*)(var40 + Enum_ov017_0218b688_396) |= 1;
                    }
                }
            }
            if (func_020dcd40() != 0) {
                func_ov017_02191108(arg0, 1, 1, 1, 1);
            }
        } else {
            func_ov017_0218f064(arg0, 0, 0x200, 1, 0);
            if (var29 == 0) {
                func_020897b4(0, 1, 6, 1, 1, 0, 0, 0, 0);
                func_0201099c(var5);
                g_keyManager.RefreshKeys();
                if (func_0200fb9c((char*)var5) == 0) {
                    func_02070378((char*)var10);
                    var10->unknown_0_ = 100;
                    func_02010774((char*)var5, 3);
                    func_020107a8((char*)var5, 1);
                    func_020107dc((char*)var5, 1);
                    func_0206df6c(var18, (unsigned char*)(var18 + 0x8c), 0xaed, 1);
                    func_020120f0(var5);
                    GameObject* var42 = var5->GetProtagonist();
                    if (var42 != 0) {
                        Struct_ov017_0218b688_2* var43 = (Struct_ov017_0218b688_2*)func_02053c6c((unsigned char*)var42);
                        if (var43 != 0) {
                            if (g_keyManager.TestKeysHeld(0x100)) {
                                var43->unknown_49c_0_ = 0;
                            } else if (g_keyManager.TestKeysHeld(0x200)) {
                                var43->unknown_49c_0_ = 1;
                            } else {
                                var43->unknown_49c_0_ = (unsigned char)func_02032370(2);
                            }
                        }
                    }
                } else if (func_0200fb9c((char*)var5) == 2) {
                    func_02070378((char*)var10);
                    var10->unknown_0_ = 0x1905;
                    var10->unknown_20_ = 0x53fc;
                    func_02010774((char*)var5, 1);
                    func_020107a8((char*)var5, 1);
                    func_020107dc((char*)var5, 1);
                    func_020120f0(var5);
                    char* var44 = (char*)func_0200ff1c(var5, 0);
                    if (var44 != 0) {
                        char* var45 = func_02053c6c((unsigned char*)var44);
                        if (var45 != 0) {
                            *(unsigned short*)(var45 + 0x496) = 0x4e24;
                        }
                    }
                    var32 = 1;
                } else {
                    func_02070378((char*)var10);
                    var10->unknown_0_ = 1;
                    var10->unknown_7_ = 1;
                    var10->unknown_1c_ = 0;
                    var10->unknown_10_[0] = 0;
                    var10->unknown_10_[1] = 0;
                    var10->unknown_10_[2] = 0;
                    func_02010774((char*)var5, 1);
                    func_020107a8((char*)var5, 1);
                    func_020107dc((char*)var5, 1);
                    func_020120f0(var5);
                }
            }
            if (var29 != 0) {
                char* var46 = (char*)func_02010828(var5);
                GameObject* var47 = var5->GetProtagonist();
                if (var47 != 0) {
                    func_02039768(var47, var46 + 0x2c8d);
                }
            }
        }
        func_ov017_02191108(arg0, 1, 1, 1, 1);
    }

    func_020a2770(var0, func_020100b0(var5));
    if (func_020115a8((Struct_02000c9c_12*)var5) == 0) {
        func_0201206c(var5, rand());
        if (func_0200fb9c((char*)var5) != 5) {
            func_0206dfe8(var18, 0x79e, 0x2bc);
        }
    }
    void* var48 = func_02057924();
    func_02057930((Struct_02057930*)var48);
    void* var49 = func_02027ca4();
#if defined(jpn)
    func_02028894(var49, arg0->unknown_d8_);
#else
    func_02028894(var49, arg0->unknown_d8_, arg0->unknown_27c_);
#endif
    void* var50 = func_02039e70();
    func_02039e7c(var50);
    void* var51 = func_020421a0();
    func_02042c68(var51);
    func_02043124(var51);
    func_02042b30(var51, arg0->unknown_87c_);
    func_ov017_0219b624(arg0);
    func_ov017_0219ba0c(arg0, 0);
    func_0207df50((Struct_0203d028*)arg0->unknown_87c_);
    func_0207df90((char*)arg0->unknown_87c_);
    func_020432c4(var51);
    func_0207dfac((char*)arg0->unknown_87c_);
    if (func_0200fb9c((char*)var5) != 6 && func_0200fb9c((char*)var5) != 9) {
        arg0->unknown_3634_[0] = 0xd4;
        arg0->unknown_3646_[0] = 8;
        arg0->unknown_3658_[0] = 0;
        arg0->unknown_3634_[1] = 0xc0;
        arg0->unknown_3646_[1] = 8;
        arg0->unknown_3658_[1] = 0;
    }
    func_02020554(arg0->unknown_36d0_);
    *(int*)(arg0->unknown_36d0_ + 0x5a4) |= 1;
    void* var52 = func_020936f8();
    func_020938f0(var52);
    func_0206ebf4((char*)arg0->unknown_44c4_);
    void* var53 = func_0207d78c();
    func_0207d798((Struct_0207d798*)var53);
    char* var54 = (char*)LightingManager::GetInstance();
    *(float*)(var54 + 0x94) = var5->GetDayTimer();
    *(int*)(var54 + 0x98) = var5->GetTimeOfDay();
    if (func_0200fb9c((char*)var5) != 6 && func_0200fb9c((char*)var5) != 9) {
        char* var55 = func_0205ec34();
        if (func_0206dfb0((int)var55, (unsigned char*)(var55 + 0x8c), 0x1142) != 0) {
            var31 = 0;
        }
        if (var31 == 1) {
            func_ov017_0219bfb4(1, 0);
        } else {
            func_ov017_0219e310((unsigned char*)arg0->unknown_370c_, 0);
            func_020469b4((Struct_0201bdac_2*)arg0->unknown_36fc_, (Struct_0201bdac*)arg0->unknown_370c_);
            func_ov017_021a3498((Struct_0203d028_4*)arg0->unknown_36fc_);
            if (func_0206dfb0((int)var55, (unsigned char*)(var55 + 0x8c), 0x1142) != 0) {
                func_ov017_021baedc(arg0->unknown_3734_, 1);
                *(unsigned short*)(arg0->unknown_3734_ + 8) = 0x730a;
                func_020469b4((Struct_0201bdac_2*)arg0->unknown_36fc_, (Struct_0201bdac*)arg0->unknown_3734_);
            }
        }
    }
    if (func_0200fb9c((char*)var5) == 6 || func_0200fb9c((char*)var5) == 9) {
        void* var56 = arg0->unknown_3b4c_;
        func_ov017_021b2174((unsigned char*)var56);
        if (func_0200fb9c((char*)var5) == 6) {
            func_ov017_021b2ba0((Struct_0206f81c_2*)var56, (char*)&data_ov017_021d736c);
            func_ov017_021b2bd0(var56, (int)func_ov004_0216e9cc, OVERLAY_ID(4));
        } else if (func_0200fb9c((char*)var5) == 9) {
            func_ov017_021b2ba0((Struct_0206f81c_2*)var56, (char*)&data_ov017_021d7378);
            func_ov017_021b2bd0(var56, (int)func_ov004_0216f854, OVERLAY_ID(4));
        }
        func_020469b4((Struct_0201bdac_2*)arg0->unknown_36fc_, (Struct_0201bdac*)var56);
    }
    func_020ca458(0, (void*)0x6000000, GetMainBGAssignedVRAMSize());
    func_020c9820();
    func_020c38d4();
    *(volatile unsigned int*)0x4001000 |= 0x10000;
    func_02010124((Struct_0200f3a4_9*)var5);
    func_020c3a0c(0);
    unsigned long long var57 = GetCurrentTimestamp();
    void* var58 = arg0->unknown_3700_;
    while (func_02046b24((Struct_02015438**)var58) == 0x13) {
        var8->RemoveAllLocks();
        func_ov017_021a3498((Struct_0203d028_4*)var58);
    }
    func_0206e424(var18, 0);
    if (var32 != 0) {
        func_ov017_021bdbf0((unsigned char*)arg0->unknown_3b60_);
        arg0->unknown_3b60_[0x11] = 2;
        func_020469b4((Struct_0201bdac_2*)arg0->unknown_36fc_, (Struct_0201bdac*)arg0->unknown_3b60_);
    }
    if (func_020115a8((Struct_02000c9c_12*)var5) != 0) {
        func_020115c0((Struct_02000c9c_14*)var5);
    }
    Struct_0208cb08* var59 = func_02094a00();
    func_0202ad30();
    func_0202adf0();

    for (;;) {
        int var60 = 0;
        if (TestFlags00((GameResources*)arg0, 0x4000) != 0) {
            var60 = 1;
        }
        func_02012efc();
        GameState::GetInstance();
        func_0205ec34();
        func_02094b4c(var59);
        int var61 = 0;
        if (arg0->unknown_4324_ == 1) {
            arg0->unknown_4324_ = 0;
            var61 = 1;
        }
        if (func_02011570((Struct_02000c9c_9*)var5) != 0) {
            if (IsBrightnessTransitionActive((GameResources*)arg0) == 0) {
                var61 = 1;
            }
        }
        if (func_020115a8((Struct_02000c9c_12*)var5) != 0 && func_02046b08((void**)arg0->unknown_36fc_) != 0) {
            var61 = 1;
            func_02070378((char*)var10);
            var10->unknown_0_ = *(unsigned short*)var9;
            var10->unknown_7_ = var61;
            GameObject* var62 = var5->GetUnknownGameObject();
            if (var62 != 0) {
                *(Vector3i*)var10->unknown_10_ = *(Vector3i const*)((char*)var62 + 0x44);
                var10->unknown_1c_ = var62->obj3D_.rotation_.y;
            }
            if (func_020115d0((Struct_020115d0*)var5) != 0) {
                var10->unknown_20_ = func_020115e8(var5);
                func_02011600(var5);
                if (func_02071574((unsigned short)var10->unknown_20_, (Struct_02071488*)var1) != 0) {
                    var10->unknown_0_ = *(unsigned short*)(var1 + 0xe);
                    var10->unknown_7_ = 0;
                }
            }
            if (func_02011610(var5) != 0) {
                var10->unknown_28_ = func_02011628(var5);
                func_02011634(var5);
            }
        }
        if (var61 != 0) {
            if (func_0200fb9c((char*)var5) != 2) {
                func_020bc028(0);
            }
            func_020d84e0();
            func_0202aff4(var15);
            SetMainBrightness((GameResources*)arg0, -16, 0);
            SetSubBrightness((GameResources*)arg0, -16, 0);
            if (func_0200fb9c((char*)var5) == 8) {
                SetMainBrightness((GameResources*)arg0, 16, 0);
                SetSubBrightness((GameResources*)arg0, 16, 0);
            }
            break;
        }
        func_02043368(var51);
        func_ov017_0218cbd4(arg0);
        func_ov017_02191cc0(arg0);
        if (data_ov017_021d82e0.unknown_0_ == 0 && TestFlags04((GameResources*)arg0, 1) == 0) {
            func_ov017_02195a20(arg0);
        }
        if (var60 != 0) {
            func_020d9834(1);
        }
        func_0209c840(&data_02109bf4);
        ResetXYField0203aa08(&g_sePlayer);
        func_020bbd9c();
        func_0203bd88(var13);
        func_0204359c(var51, Enum_ov017_0218b688_24);
        if (var60 != 0) {
            func_020d9834(1);
        } else {
            func_020d9834(0);
        }
        var8->RemoveAllLocks();
        func_0203dd94((char*)var14);
        func_ov017_0219a188(arg0);
        func_ov017_021a63cc(arg0);
        if (data_ov017_021d82e0.unknown_0_ == 0) {
            int var63 = var5->currentNumTicks_;
            for (int var64 = 1; var64 < 2 - var63; var64++) {
                func_020c9820();
            }
            func_020d86d0(1, 0);
            arg0->unknown_28_ = 1;
            func_020c9820();
        }
        if (data_ov017_021d82e0.unknown_0_ != 0) {
            var5->CalculateDeltaTime(0);
        } else {
            unsigned long long var65 = GetCurrentTimestamp();
            var5->CalculateDeltaTime(((var65 - var57) * 64000) / 33514);
        }
        var57 = GetCurrentTimestamp();
        data_02114e50++;
        func_ov017_021a4358((int)arg0->unknown_36fc_);
        func_0203bdb0((Struct_0203bdb0*)var13);
        int var66 = 1;
        if (func_02046b24((Struct_02015438**)arg0->unknown_36fc_) == 2) {
            Struct_ov017_0218b688_4* var67 = (Struct_ov017_0218b688_4*)func_ov017_021a193c((int*)arg0->unknown_3708_);
            if (var67 != 0 && IS_OBJ_FLAG2_SET(var67)) {
                var66 = 0;
            }
        }
        func_020439b0(var51, var66);
        func_020579ec((Struct_020579ec**)var48);
        func_ov017_021a63d0(arg0);
        func_ov017_0219a18c(arg0);
        func_0203ba74(var12);
        func_02027438(arg0->unknown_36d0_);
#if !defined(jpn)
        func_020275e4((Struct_020275e4*)arg0->unknown_36d0_);
#endif
        if (var60 != 0) {
            func_020d9834(1);
        }
    }

    if (func_02011570((Struct_02000c9c_9*)var5) != 0) {
        SetMainBrightness((GameResources*)arg0, -16, 0);
        SetSubBrightness((GameResources*)arg0, -16, 0);
    }
    if (GetByte0x4_0200fb9c((char*)gs) != 2) {
        if (GetShortAt0xb4((ShortField0xb4_0205eac8*)&g_sePlayer) != 100) {
            SetupContextForMode0205ea20(&g_sePlayer, 100);
        }
        InitActorContext0209c20c((Actor0209c20c*)&data_02109bf4);
        RefreshDisplayState0205e8ec((Obj_0205e8ec*)&g_sePlayer);
        func_020bbd9c();
    }
    data_02109bf4.unknown_c8_ &= ~4;
    func_ov017_021a3ef0(arg0->unknown_36fc_);
    func_0203cfb4((Struct_0203cfb4*)var14);
    func_ov017_021a316c(arg0);
    for (int var68 = 0; var68 < 0x12; var68++) {
        func_02047230(&arg0->unknown_2b90_[var68]);
    }
    func_020798b8((char*)var23);
    func_02043000((char*)var51);
    func_020939ac(var52);
    func_0203a54c((Struct_0203a54c*)var50);
    func_02057978((Struct_02057930*)var48);
    func_020287b4(var49);
    func_ov017_02190238(arg0);
    func_02013750(var9, 1);
    func_020998ac((int*)var16);
    func_0209cd24((Struct_0209cbb8*)var24);
    func_0207d798((Struct_0207d798*)var53);
    func_ov017_0219b938(arg0);
    func_ov017_0219bc50((unsigned char*)arg0);
    if (func_0200fb9c((char*)var5) == 9 && var25 == 1) {
        void* var69 = arg0->unknown_c4_.GetSignedAllocator();
        if (var69 != 0) {
            arg0->unknown_c4_.Destroy();
            func_02012da4((AllocatorUnion*)&data_02114e20, var69);
        }
        func_0200fb94((char*)var5, 6);
        func_02012010(var5, 2);
    }
    int var70 = arg0->unknown_2b08_;
    if (var70 == 0) {
        func_ov017_021a0790((char*)arg0);
    } else if (var70 == 1) {
        func_ov017_021a0964((char*)arg0);
    } else if (var70 == 2) {
        func_ov017_021a0ba8((char*)arg0);
    } else if (var70 == 3) {
        func_ov017_021a0f40((char*)arg0);
    } else if (var70 == 4) {
        func_ov017_021a1114((char*)arg0);
    } else if (var70 == 5) {
        func_ov017_021a0d6c((char*)arg0);
    }
    func_ov017_021a0470(arg0);
    func_0200fd58(var5);
    func_020a1edc();
    func_020a1de4();
    *(volatile unsigned int*)0x4000000 &= ~0xe000;
    data_ov017_021d82e0.unknown_4_ = 0;
#if !defined(jpn)
    func_020e5094();
#endif
    SafeAllocator::GetLiveCount();
    func_0200fb84((int*)var5, 0);
    func_020a2010(var0);
    func_020a2cf0((Struct_0204a120_2*)var0);
    func_0202df68(var0);
}
