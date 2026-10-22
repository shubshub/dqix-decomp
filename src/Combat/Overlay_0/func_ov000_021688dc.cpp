#include <globaldefs.h>
#include <Resource/IndexedResourceEntry.h>
#include "Resource/FontBankLoader.h"
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/VRAMStaging.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/VRAM.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"
struct Struct_02032e58;

#if defined(jpn)
enum {
    Enum_ov000_021688dc_668 = 0x218,
    Enum_ov000_021688dc_672 = 0x21c,
    Enum_ov000_021688dc_676 = 0x220,
    Enum_ov000_021688dc_14076 = 0x34ec,
    Enum_ov000_021688dc_14132 = 0x3524,
    Enum_ov000_021688dc_6590 = 0x17ee,
    Enum_ov000_021688dc_30674 = 0x79c2,
    Enum_ov000_021688dc_336 = 0x144,
    Enum_ov000_021688dc_22800 = 0x5b00,
    Enum_ov000_021688dc_22784 = 0x5b00,
    Enum_ov000_021688dc_434 = 0x1a6,
    Enum_ov000_021688dc_348 = 0x150,
    Enum_ov000_021688dc_396 = 0x180,
    Enum_ov000_021688dc_340 = 0x148,
    Enum_ov000_021688dc_452 = 0x1b8,
    Enum_ov000_021688dc_29172 = 0x6fb4,
    Enum_ov000_021688dc_29156 = 0x6fa4,
    Enum_ov000_021688dc_29168 = 0x6fb0,
    Enum_ov000_021688dc_21912 = 0x5788,
    Enum_ov000_021688dc_21944 = 0x57a8,
    Enum_ov000_021688dc_14092 = 0x34fc,
    Enum_ov000_021688dc_28196 = 0x7014,
    Enum_ov000_021688dc_28202 = 0x701a,
    Enum_ov000_021688dc_28203 = 0x701b,
    Enum_ov000_021688dc_28204 = 0x701c,
    Enum_ov000_021688dc_28216 = 0x7028,
    Enum_ov000_021688dc_28 = 0xc,
    Enum_ov000_021688dc_27 = 0x2b,
    Enum_ov000_021688dc_17 = 0xc,
};
#else
enum {
    Enum_ov000_021688dc_668 = 0x29c,
    Enum_ov000_021688dc_672 = 0x2a0,
    Enum_ov000_021688dc_676 = 0x2a4,
    Enum_ov000_021688dc_14076 = 0x36fc,
    Enum_ov000_021688dc_14132 = 0x3734,
    Enum_ov000_021688dc_6590 = 0x19be,
    Enum_ov000_021688dc_30674 = 0x77d2,
    Enum_ov000_021688dc_336 = 0x150,
    Enum_ov000_021688dc_22800 = 0x5910,
    Enum_ov000_021688dc_22784 = 0x5900,
    Enum_ov000_021688dc_434 = 0x1b2,
    Enum_ov000_021688dc_348 = 0x15c,
    Enum_ov000_021688dc_396 = 0x18c,
    Enum_ov000_021688dc_340 = 0x154,
    Enum_ov000_021688dc_452 = 0x1c4,
    Enum_ov000_021688dc_29172 = 0x71f4,
    Enum_ov000_021688dc_29156 = 0x71e4,
    Enum_ov000_021688dc_29168 = 0x71f0,
    Enum_ov000_021688dc_21912 = 0x5598,
    Enum_ov000_021688dc_21944 = 0x55b8,
    Enum_ov000_021688dc_14092 = 0x370c,
    Enum_ov000_021688dc_28196 = 0x6e24,
    Enum_ov000_021688dc_28202 = 0x6e2a,
    Enum_ov000_021688dc_28203 = 0x6e2b,
    Enum_ov000_021688dc_28204 = 0x6e2c,
    Enum_ov000_021688dc_28216 = 0x6e38,
    Enum_ov000_021688dc_28 = 0x1c,
    Enum_ov000_021688dc_27 = 0x1b,
    Enum_ov000_021688dc_17 = 0x11,
};
#endif

struct Struct_ov000_02183218 { unsigned char unknown_0_[4]; };

extern "C" void* func_0202ae18(void);
extern "C" unsigned short* func_02012fe4(void);
extern "C" void* func_0203bd08(void);
extern "C" void func_02082828(int arg0);
extern "C" void func_020542b4(void* arg0, void* arg1, void* arg2);
extern "C" void func_02048b0c(void* arg0, int arg1);
extern "C" void func_02049c88(void* arg0, void* arg1);
extern "C" void func_02046a8c(void* arg0, void* arg1);
extern "C" void func_02076a8c(void* arg0);
extern "C" int func_ov000_02163c80(void* arg0, int arg1);
extern "C" void func_ov000_02168284(void* arg0);
extern "C" void func_02048150(void* arg0, int arg1, int arg2);
extern "C" int func_0202c540(void* arg0);
extern "C" void func_ov017_021917f0(int arg0, int arg1);
extern "C" void func_ov017_02191234(int arg0);
extern "C" void func_ov017_021baedc(void* arg0, int arg1);
extern "C" void func_ov017_02191108(int arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_ov017_02191aac(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov017_021c9e00(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov017_0219bd1c(int arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov000_021626a0(void* arg0, int arg1, int arg2);

extern "C" void func_ov017_0218d274(void* arg0);
extern "C" void func_ov017_021901ac(int arg0);

extern "C" int func_020100a8(GameState* arg0);
extern "C" void* func_0200fd0c(GameState* arg0);
extern "C" void func_0200fd48(GameState* arg0, int arg1);
extern "C" void func_020100c4(GameState* arg0, int arg1);

struct Struct_02010088;
extern "C" int func_02010088(struct Struct_02010088* arg0);
extern "C" void func_0208902c(unsigned char* arg0, int arg1);
extern "C" int func_0202b7d8(int* arg0);
extern "C" int func_020a35e0(unsigned char* arg0, unsigned char arg1);
extern "C" int func_020a3634(unsigned char* arg0, short* arg1);

struct Struct_02048150 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};
extern "C" int func_02086ef0(struct Struct_02048150* arg0, int arg1);

struct Struct_0207d7f4;
extern "C" void func_0207da7c(struct Struct_0207d7f4* arg0, unsigned short arg1);
extern "C" int func_ov000_02160fd4(void* arg0, int arg1);
extern "C" void func_ov000_02160fa8(void* arg0, int arg1);
extern "C" int func_02053c6c(unsigned char* arg0);

struct Struct_020fdd44;
extern "C" struct Struct_020fdd44* func_02027cb0(void);
extern "C" int func_020421a0(void);
extern "C" void* func_0207d78c(void);
extern "C" void* func_020d6c00(void);

extern "C" void func_020397c0(void* arg0);

struct Struct_02053f7c_3;
extern "C" void func_02053f7c(Struct_02053f7c_3* arg0, unsigned short arg1, int arg2);
struct Struct_02049f50;
extern "C" void func_02049f50(struct Struct_02049f50* arg0, int arg1, int arg2);
extern "C" int func_02083b00(unsigned char* arg0, int arg1);
extern "C" void func_0203400c(Struct_02032e58* arg0);
extern "C" void func_02039d48(unsigned char* arg0);
extern "C" void func_02039d58(unsigned char* arg0);
extern "C" void func_020398a4(unsigned char* arg0);
struct Struct_02033834;
extern "C" void func_02033874(struct Struct_02033834* arg0, int arg1);
extern "C" int func_ov017_0218fcf8(int arg0, int arg1, int arg2);
extern "C" void func_02039d24(unsigned char* arg0);
extern "C" void func_02039758(void* arg0, int arg1);

struct Struct_0202b2f0;
struct Struct_0202c1a4;
extern "C" int func_0202c1a4(struct Struct_0202c1a4* arg0);
extern "C" int func_0202c1c0(struct Struct_0202b2f0* arg0, int arg1);
extern "C" void func_ov017_021cc4b8(int arg0, int arg1, int arg2);
extern "C" void func_02053ec8(void* arg0, int arg1);

struct Struct_02010604;
extern "C" int func_02033b88(struct Struct_02010604* arg0, int arg1);
extern "C" GameObject* func_ov017_021a278c(void* arg0, int arg1);

struct Struct_0203d028;
extern "C" void func_02072d58(int arg0, char* arg1, char* arg2);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* arg0);
extern "C" void func_0207df50(struct Struct_0203d028* arg0);
extern "C" void func_0207df90(char* arg0);
extern "C" void func_0207dfac(char* arg0);

struct Struct_0203d028_11;
extern "C" void func_0203dafc(struct Struct_0203d028_11* arg0);

extern "C" void func_0205ea20(void* arg0, int arg1);

struct Struct_0201bdac_2;
struct Struct_0201bdac;
extern "C" void func_020469b4(struct Struct_0201bdac_2* arg0, struct Struct_0201bdac* arg1);

extern "C" void func_0201bf38(unsigned char* arg0, int arg1, int arg2, int arg3, unsigned short arg4);
extern "C" void func_0201bf70(unsigned char* arg0, int arg1);
extern "C" void func_020e1154(void* arg0);
extern "C" void func_ov017_02195530(unsigned char* arg0);
struct Struct_02038598_4;
extern "C" void func_020466f4(struct Struct_02038598_4* arg0, unsigned int arg1);
extern "C" int func_ov000_0215fc60(char* arg0);
extern "C" void func_ov017_021907dc(int arg0, int arg1, int arg2, int arg3, int arg4);

extern "C" void* func_020e3580(void);
extern "C" int func_020e37e8(unsigned char* arg0);
extern "C" void func_020e3798(unsigned char* arg0);

extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void func_ov017_021c8c04(int, int, int);
extern "C" void _ZN8Object3D10SetField06Et(void* arg0, int arg1);

struct Struct_ov000_021688dc { unsigned char unknown_0_0_ : 2; unsigned char unknown_0_2_ : 6; };

extern Struct_ov000_02183218 data_ov000_02183218;
extern int data_ov000_02183b0c;
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern const char data_ov000_02183b20[];
extern const char data_ov000_02183b3b[];
extern const char data_ov000_02183b55[];
extern int g_sePlayer;

extern "C" void func_020114c0(char* arg0, int arg1, void* arg2);
struct Struct_ov000_02164fac_2 { char unknown_0_[0x70]; };
static inline SafeAllocator* inline_ov000_02164fac(GameResources* arg0, int arg1) { return &arg0->allocator_array_38[arg1]; }
static inline Struct_ov000_02164fac_2* inline_ov000_021688dc(GameResources* arg0, int arg1) { return &((Struct_ov000_02164fac_2*)arg0->unknown_2cc_)[arg1]; }

static inline short inline_ov000_021688dc_2(GameObject* arg0) { return arg0->obj3D_.unknown_4_; }

static inline int inline_ov000_021688dc_3(GameObject* arg0) {
    return (**(int**)((char*)arg0 + 0x130) & 1) != 0;
}

// USA: func_ov000_021688dc
extern "C" ARM void func_ov000_021688dc(unsigned char* arg0) {
    if (((BackgroundLoader*)((void*)(int)BackgroundLoader::GetInstance()))->GetNumQueuedTasks() > 0) {
        return;
    }

    GPCReadPair var0;
    char var1[0xa];
    char var2[0xa];
    char var3[0x28];
    ObjectArchiveLoadInfo var4;
    ObjectArchiveLoadInfo var5;
    Struct_ov000_02183218 var6;
    short var7[4];
    unsigned int var8;

    GameState* var9 = GameState::GetInstance();
    int var10 = (int)GetGameResources();
    struct Struct_0202b2f0* var11 = (struct Struct_0202b2f0*)func_0202ae18();
    unsigned short* var12 = func_02012fe4();
    func_0203bd08();

    void* var13 = *(void**)(arg0 + Enum_ov000_021688dc_668);
    struct Struct_02048150* var14 = (struct Struct_02048150*)func_02010828(var9);
    GameObject* var15 = var9->GetProtagonist();
    struct Struct_020fdd44* var16 = func_02027cb0();
    int var17 = func_020421a0();
    void* var18 = func_0207d78c();
    void* var19 = *(void**)(var10 + Enum_ov000_021688dc_14076);
    unsigned char* var20 = *(unsigned char**)(var10 + Enum_ov000_021688dc_14132);
    func_020d6c00();

    if (*((unsigned char*)var13 + 0x8e97) != 0) {
        GameObject* var21 = var9->GetPartyMemberByIndex(func_020100a8(var9));
        if (var21 != NULL && func_02010088((struct Struct_02010088*)var21)) {
            func_0208902c(*(unsigned char**)((char*)var21 + 0x138), 1);
            func_ov017_02191108(var10, 1, 1, 1, 1);
        }
    }

    GameObject* var22 = var9->GetUnknownGameObject();

    if (func_0202b7d8((int*)var11)) {
        int var23 = 1;
        int var24;
        for (var24 = 0; var24 < 4; var24++) {
            if (func_020a35e0(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672), var24)) {
                GameObject* var25 = func_0200ff1c(var9, var24);
                if (var25 != NULL) {
                    if (!func_02010088((struct Struct_02010088*)var25)) {
                        var23 = 0;
                        break;
                    }
                }
            }
        }
        if (var23) {
            *(*(unsigned char**)(arg0 + Enum_ov000_021688dc_668) + 0x8e14) = 2;
        }
    }

    func_ov017_0218d274((void*)var10);
    ClearFlags04((GameResources*)var10, 0x200000);
    func_0207da7c((struct Struct_0207d7f4*)var18, *(unsigned short*)(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672) + 8));
    *(unsigned char*)(var17 + Enum_ov000_021688dc_6590) = 0;

    if (func_ov000_02160fd4(arg0, 0x400000)) {
        GameObject* var26 = func_0200ff1c(var9, 1);
        if (var26 != NULL) {
            int var27 = func_02053c6c((unsigned char*)var26);
            if (var27 != 0) {
                func_02082828(var27);
            }
        }
        var14->unknown_f7c_ -= 1;
        func_0200fd48(var9, 1);
        var9->SetTimeOfDay((TimeOfDay)2);

        int var28 = 1;
        var6 = data_ov000_02183218;
        func_020114c0((char*)var9, var28, &var6);

        SafeAllocator* var29 = inline_ov000_02164fac((GameResources*)var10, 3);
        Struct_ov000_02164fac_2* var30 = inline_ov000_021688dc((GameResources*)var10, 3);
        func_020542b4(func_ov017_021a11f4((GameResources*)var10, 2), var29, var30);
        *(int*)((char*)LightingManager::GetInstance() + 0x98) = 2;
    }

    int var31 = func_020a3634(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672), var7);

    if (var22 != NULL) {
        func_020397c0(var22);
        *((unsigned char*)var22 + 0xc3) = 0xf;
    }

    short var32 = var15->obj3D_.unknown_4_;
    if (func_02086ef0(var14, 0)) {
        for (int var33 = 0; var33 < var14->unknown_f7c_; var33++) {
            GameObject* var34 = var9->GetPartyMemberByIndex(var14->unknown_f78_[var33]);
            if (var34 != NULL && !func_02010088((struct Struct_02010088*)var34)) {
                if (!inline_ov000_021688dc_3(var34)) {
                    var32 = var34->obj3D_.unknown_4_;
                    break;
                }
            }
        }
    } else {
        var32 = var22->obj3D_.unknown_4_;
    }

    for (int var35 = 0; var35 < 4; var35++) {
        if (func_020a35e0(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672), var35)) {
            GameObject* var36 = var9->GetPartyMemberByIndex(var35);
            if (var36 != NULL) {
                var36->obj3D_.MakeVisible();
                func_02053f7c((struct Struct_02053f7c_3*)var36, 0, 0);
                func_02049f50((struct Struct_02049f50*)var36, 0x1f, 0);
                func_ov017_02191aac(var10, 0, var35, 2);
                func_ov017_02191aac(var10, 0, var35, 4);

                if (func_ov000_02160fd4(arg0, 1) && arg0[Enum_ov000_021688dc_30674] != 0) {
                    func_02048b0c(var36, func_02083b00(*(unsigned char**)((char*)var36 + Enum_ov000_021688dc_336), 0x99) ? 1 : 0);
                    func_0203400c((Struct_02032e58*)var36);
                }

                if (func_02086ef0(var14, inline_ov000_021688dc_2(var36))) {
                    if (var32 != var36->obj3D_.unknown_4_) {
                        func_02039d48((unsigned char*)var36);
                    }
                    if (func_ov000_02160fd4(arg0, 1)) {
                        var36->obj3D_.position_ = *(Vector3i*)(arg0 + Enum_ov000_021688dc_22800 + var32 * 16);
                        func_02033874((struct Struct_02033834*)var36, *(short*)(arg0 + var32 * 16 + Enum_ov000_021688dc_22784 + Enum_ov000_021688dc_28));
                    }
                } else {
                    if (func_ov000_02160fd4(arg0, 1)) {
                        var36->obj3D_.position_ = *(Vector3i*)(arg0 + Enum_ov000_021688dc_22800 + var35 * 16);
                        func_02033874((struct Struct_02033834*)var36, *(short*)(arg0 + var35 * 16 + Enum_ov000_021688dc_22784 + Enum_ov000_021688dc_28));
                    }
                    if (*(unsigned short*)((char*)var36 + Enum_ov000_021688dc_434) != 0) {
                        func_02039d58((unsigned char*)var36);
                    }
                }

                var36->obj3D_.unknown_9c_ = 0;
                var36->obj3D_.SetField9e(0);
                func_ov017_0218fcf8(var10, var35, 0);
                func_02039d24((unsigned char*)var36);
                func_020398a4((unsigned char*)var36);
                func_02039758(var36, 0);

                if (func_0202b7d8((int*)var11)) {
                    int var37 = func_0202c1a4((struct Struct_0202c1a4*)var11);
                    if (var37 == var35) {
                        continue;
                    }
                    if (!func_0202c1c0(var11, var35)) {
                        func_ov017_021cc4b8(var35, 0, 8);
                        continue;
                    }
                    func_ov017_021cc4b8(var35, var35, 8);
                }
                *((unsigned char*)var36 + 0xe0) |= 0x20;
            }
        }
    }

    for (int var38 = 0; var38 < var14->unknown_f7c_; var38++) {
        GameObject* var39 = func_0200ff1c(var9, var14->unknown_f78_[var38]);
        if (var39 != NULL) {
            func_02053ec8(var39, 0);
            func_ov017_021c9e00(var14->unknown_f78_[var38], 1, 0, 1);
        }
    }

    if (*(int*)(arg0 + Enum_ov000_021688dc_676) != 0) {
        func_020100c4(var9, *(int*)(arg0 + Enum_ov000_021688dc_676));
    }

    int var40 = 0;
    if (!func_0202b7d8((int*)var11) ||
        func_0202c1a4((struct Struct_0202c1a4*)var11) == 0) {
        GameObject* var41 = func_ov017_021a278c((void*)var10,
            *(unsigned short*)(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672) + 8));
        if (var41 != NULL) {
            if (func_ov000_02163c80(arg0, 0) != 0) {
                var40 = 1;
            } else {
                func_02076a8c(var41);
                var41->obj3D_.MakeHidden();
            }
        }
        if (var16 != NULL) {
            *(int*)((char*)var16 + 8) = 0;
        }
    }
    for (int var42 = 0; var42 < 8; var42++) {
        func_0200fd48(var9, var42 + 0xc0);
    }

    ClearFlags04((GameResources*)var10, 0x80);
    ClearFlags04((GameResources*)var10, 4);
    ClearFlags04((GameResources*)var10, 0x10);
    ClearFlags04((GameResources*)var10, 0x40);
    ClearFlags04((GameResources*)var10, 2);
    ClearFlags00((GameResources*)var10, 0x20);
    ClearFlags00((GameResources*)var10, 0x10);
    func_ov000_021626a0(arg0, 0x26, 1);
    *(volatile unsigned short*)0x04000304 &= ~0x8000;
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(0xf);
    func_020bb48c(4, 1);
    DisableSubBGVRAMBanks();
    MapVRAMBanksToSubBG(0x80);
    MapVRAMBanksToSubObj(0x100);
    *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    RenderConfig::SetDiffuseAmbientColors(var12[Enum_ov000_021688dc_27], 0, 0);
    func_ov017_021901ac(var10);

    for (int var43 = 0; var43 < var31; var43++) {
        GameObject* var44 = func_0200ff1c(var9, var7[var43]);
        if (var44 != NULL) {
            ((Struct_ov000_021688dc*)((char*)var44 + 0xc1))->unknown_0_0_ &= ~3;
            _ZN8Object3D10SetField06Et(var44, *(int*)((char*)var44 + Enum_ov000_021688dc_348));
            *(int*)((char*)var44 + Enum_ov000_021688dc_348) = data_ov000_02183b0c;
            if (*(int**)((char*)var44 + 0x13c) != NULL) {
                **(int**)((char*)var44 + 0x13c) = 0;
            }
            func_02049c88(var44, NULL);
            *((unsigned char*)var44 + 0xc2) &= ~0x20;
            func_ov017_021917f0(var7[var43], 0);
        }
    }

    if (!func_0202b7d8((int*)var11)) {
        if (*(signed char*)(*(unsigned char**)(arg0 + Enum_ov000_021688dc_668) + 0x8e14) != 2) {
            for (int var45 = 0; var45 < var31; var45++) {
                GameObject* var46 = func_0200ff1c(var9, var7[var45]);
                if (var46 != NULL && inline_ov000_021688dc_3(var46)) {
                    *(int*)((char*)var46 + Enum_ov000_021688dc_396) |= 1;
                    func_02033b88((struct Struct_02010604*)var46, 0);
                }
            }
        }
    } else {
        for (int var47 = 0; var47 < var31; var47++) {
            GameObject* var48 = func_0200ff1c(var9, var7[var47]);
            if (var48 != NULL && inline_ov000_021688dc_3(var48)) {
                *(int*)((char*)var48 + Enum_ov000_021688dc_396) |= 1;
                func_02033b88((struct Struct_02010604*)var48, 0);
            }
        }
    }

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    GPCReadPair* var49 = &var0;
    unsigned char* var50 = data_0211e33c;
    unsigned int var51 = 0x30000;
    ZeroInitGPCPointer(&var49->pGPCFile);
    var49->ZeroInitializeMachine();

    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&var0.pGPCFile, var0.machine,
            data_ov000_02183b20, var50, var8, var51, false, NULL)) {
        var50 += var8;
        var51 -= var8;

        for (int var52 = 0; var52 < 4; var52++) {
            if (func_020a35e0(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672), var52)) {
                GameObject* var53 = func_0200ff1c(var9, var52);
                if (var53 != NULL) {
                    var53->obj3D_.MakeVisible();
                    *((unsigned char*)var53 + 0xc1) &= ~0xf0;
                    unsigned char* var54 = *(unsigned char**)((char*)var53 + Enum_ov000_021688dc_340);
                    if (var54 != NULL) {
                        SafeAllocator* var55;

                        var53->obj3D_.RemoveAllAnimationPackages();
                        ((SafeAllocator*)(var54 + 0x52c))->Reset();
                        ((SafeAllocator*)(var54 + 0x540))->Reset();
                        func_02072d58(var52, var1, var2);

                        if (func_02061bd8((struct Struct_0205faf4_11*)var53)) {
                            var53->obj3D_.Destroy();
                            unsigned char* var56 = *(unsigned char**)((char*)var53 + Enum_ov000_021688dc_452);
                            if (var56 != NULL) {
                                sprintf(var3, data_ov000_02183b3b, var56[Enum_ov000_021688dc_17]);
                            }
                            var55 = (SafeAllocator*)(var54 + 4);
                            var55->Reset();
                            func_0207df50((struct Struct_0203d028*)(var54 + 0xcc));
                            func_0207df90((char*)(var54 + 0xcc));
                            LoadFileIntoMemory(var3, data_0211e33c, &var8);
                            var50 = data_0211e33c;
                        } else {
                            sprintf(var3, data_ov000_02183b55, var1);
                            var55 = (SafeAllocator*)(var54 + 0x52c);
                            DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var50, var8, var51, var3);
                        }

                        if (var8 != 0) {
                            func_0203dafc((struct Struct_0203d028_11*)&var4);
                            var4.allocator = var55;
                            var4.unk_10 = 1;
                            var4.packageID = 0;
                            var4.unk_8 = var8;
                            var4.fileData = var50;
                            var53->obj3D_.LoadFromCCHROrCMOTArchive(&var4, NULL);
                        }

                        if (func_02061bd8((struct Struct_0205faf4_11*)var53)) {
                            func_0207dfac((char*)(var54 + 0xcc));
                        } else {
                            sprintf(var3, data_ov000_02183b55, var2);
                            if (DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var50, var8, var51, var3)) {
                                func_0203dafc((struct Struct_0203d028_11*)&var5);
                                var5.allocator = (SafeAllocator*)(var54 + 0x540);
                                var5.unk_8 = var8;
                                var5.unk_10 = 1;
                                var5.packageID = 1;
                                var5.fileData = var50;
                                var53->obj3D_.LoadFromCCHROrCMOTArchive(&var5, NULL);
                            }
                        }

                        func_02033b88((struct Struct_02010604*)var53, 0);
                    }
                }
            }
        }

        var0.Reset();
    }

    if (func_0202b7d8((int*)var11)) {
        func_ov017_021c8c04(*(unsigned short*)(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672) + 8), var40, *var12);
    }

    func_ov000_02168284(arg0);

    LightingManager* var57 = LightingManager::GetInstance();
    var57->SetZone((Zone3D*)var12);
    var57->BeginFade(0x1000, 0);

    Struct_0208cb08* var58 = func_02094a00();
    func_02094b40(var58);
    func_02094ab0(var58);

    battle->SetGameSpeed(0x1000);
    SetCombatWorkFlags0x55f4_ov000_02160fa8(work, 0x400);
    SetupContextForMode0205ea20(&g_sePlayer, 0x64);

    unsigned char var59;
    *(int*)((char*)var9 + Enum_ov000_021688dc_29172) = 0;
    for (var59 = 0; var59 < *(short*)(arg0 + Enum_ov000_021688dc_21944); var59++) {
        if (var20[3] != 0 || var20[2] != 0) {
            break;
        }
        func_ov017_021baedc(var20, 1);
        *(unsigned short*)(var20 + 8) = *(int*)(arg0 + var59 * 4 + Enum_ov000_021688dc_21912);
        unsigned short* var60 = func_02012fe4();
        GameObject* var61 = var9->GetProtagonist();
        *(int*)((char*)var9 + Enum_ov000_021688dc_29172) = *var60;
        int var62 = var61->obj3D_.rotation_.y;
        Vector3i var63 = var61->obj3D_.position_;
        *(Vector3i*)((char*)var9 + Enum_ov000_021688dc_29156) = var63;
        *(int*)((char*)var9 + Enum_ov000_021688dc_29168) = var62;
        func_020469b4((struct Struct_0201bdac_2*)var19, (struct Struct_0201bdac*)var20);
        var59 = 1;
        break;
    }

    if (var59 == 0) {
        if (!func_ov000_02160fd4(arg0, 1)) {
            func_ov017_0219bd1c(0, 4, 0, 0);
        }
    } else {
        unsigned char* var64 = *(unsigned char**)(var10 + Enum_ov000_021688dc_14092);
        if (var64[2] != 0) {
            func_02046a8c(var19, var64);
        }
    }

    ClearFlags00((GameResources*)var10, 4);

    if (*(int*)(arg0 + Enum_ov000_021688dc_28196) != 0) {
        func_0201bf38((unsigned char*)var12, 1, arg0[Enum_ov000_021688dc_28202], arg0[Enum_ov000_021688dc_28203], *(unsigned short*)(arg0 + Enum_ov000_021688dc_28204));
    }
    if (*(int*)(arg0 + Enum_ov000_021688dc_28216) != 0) {
        func_0201bf70((unsigned char*)var12, 1);
    }
    if (*(int*)(arg0 + Enum_ov000_021688dc_28196) != 0 || *(int*)(arg0 + Enum_ov000_021688dc_28216) != 0) {
        func_020e1154((void*)0xfa0);
    }
    func_ov017_02195530((unsigned char*)var10);

    struct Struct_02038598_4* var65 = (struct Struct_02038598_4*)func_020d6c00();
    func_020466f4(var65, 2);
    func_020466f4(var65, 0x200);
    func_020466f4(var65, 0x2000);
    ClearFlags08((GameResources*)var10, 4);
    func_020466f4(var65, 0x40000);

    if (func_ov000_0215fc60((char*)var13)) {
        GameObject* var66 = func_0200ff1c(var9, 0);
        if (var66 != NULL && *(unsigned short*)(*(unsigned char**)((char*)var66 + 0x130) + 4) == 0) {
            func_02048150(var66, 1, 1);
            *(int*)((char*)var66 + Enum_ov000_021688dc_396) &= ~1;
        }
        *(*(unsigned char**)(arg0 + Enum_ov000_021688dc_668) + 0x8e14) = 1;
    }
    ClearFlags04((GameResources*)var10, 0x400);

    if (func_0202c540(var11)) {
        func_ov017_021907dc(var10, 0, 1, 1, 1);
        func_ov017_02191234(var10);
    }
    *(unsigned short*)((char*)func_0200fd0c(var9) + 0x1e) = *(int*)(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672) + 0xc);

    if (func_0202b7d8((int*)var11)) {
        unsigned char* var67 = (unsigned char*)func_020e3580();
        if (func_020e37e8(var67)) {
            func_020e3798(var67);
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    var0.Reset();
    ZeroDestroyGPCPointer(&var0.pGPCFile);
}
