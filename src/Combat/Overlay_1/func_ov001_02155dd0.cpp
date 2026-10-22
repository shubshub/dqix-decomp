#include <globaldefs.h>
#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Graphics.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_02000c9c_36;
struct Struct_0203dce4_2;
struct Struct_0204039c;
struct Struct_0203dd10;

struct Struct_ov001_02155dd0 {
    char unknown_0_[0xa];
    unsigned short unknown_a_;
};

extern "C" char* func_020100f8(char* arg0);
extern "C" void* func_02010768(void* arg0);
extern "C" void* func_02012fe4();
extern "C" char* func_020421a0();
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203d004(void* arg0);
extern "C" void* func_0203dce4(Struct_0203dce4_2*, int);
extern "C" int* func_02040528(int* arg0);
struct Struct_0204027c_2;
extern "C" int func_02040404(Struct_0204027c_2*, char const*);
extern "C" void func_0204039c(Struct_0204039c* arg0, int arg1);
extern "C" void func_02040504(int* arg0);
extern "C" void func_0203dd10(Struct_0203dd10*, unsigned int, int);
extern "C" void func_02043204(char* arg0);
extern "C" void func_02043124(char* arg0);
extern "C" int func_0203adfc(void* arg0, void* arg1);
extern "C" void func_0203ad88(void* arg0, void* arg1, int arg2);
extern "C" void func_0202e874(unsigned char*, unsigned short);
extern "C" void func_0202f0c4(void* arg0, int arg1, int arg2);
extern "C" void* func_020704fc();
struct Struct_020708c8;
extern "C" void func_020708c8(Struct_020708c8*, unsigned int);
extern "C" void func_0209c278(void* arg0);
extern "C" void func_0209c290(void* arg0);
extern "C" void func_0205ea20(void* arg0, int arg1);
extern "C" void func_ov028_021d9714();
extern "C" void func_020a1f4c(int arg0);
extern "C" void* func_0205ec34();
extern "C" int func_0206dfb0(int arg0, unsigned char* arg1, int arg2);
struct Struct_02010604;
extern "C" void func_02033b88(Struct_02010604*, int);
extern "C" void func_0200fd48(GameState* arg0, int arg1);
extern "C" void func_020100c4(GameState* arg0, int arg1);

extern char data_ov001_02164c4a[];
extern char g_sePlayer[];
extern char data_02109bf4[];

#define REG_DISPSTAT_304 (*(volatile unsigned short*)0x04000304)

// USA: func_ov001_02155dd0
extern "C" ARM unsigned short func_ov001_02155dd0(Struct_ov001_02155dd0* arg0) {
    GameResources* var0 = GetGameResources();
    if (IsBrightnessTransitionActive(var0)) {
        return arg0->unknown_a_;
    }

        BackgroundLoader* var1;
        char* var2;
        GameObject* var3;
        int var4;
        int* var5;
        GameResources* var6;
        Zone3D* var7;
        int var8;
        int var9;
        char* var10;
        GameState* var11;

    var11 = GameState::GetInstance();
    var10 = func_020100f8((char*)var11);
    var6 = GetGameResources();
    var7 = (Zone3D*)func_02012fe4();
    var2 = func_020421a0();
    var1 = BackgroundLoader::GetInstance();
    var5 = (int*)func_02010768(var11);

    for (var4 = 0; var4 < 4; var4++) {
        var3 = var11->GetMaybeWanderingMonsterByIndex(var4);
        if (var3 != 0) {
            var3->obj3D_.RemoveAnimationPackageByID(3);
            unsigned short var12 = var7->currentZoneID_;
            if (var12 == var3->obj3D_.GetField06()) {
                var3->obj3D_.MakeVisible();
            }
            func_02033b88((Struct_02010604*)var3, 0);
        }
    }

    for (var9 = 0; var9 < 0x20; var9++) {
        var3 = var11->GetGameObjectByIndex(var9 + 0xa0);
        if (var3 != 0) {
            var3->obj3D_.Destroy();
            func_0200fd48(var11, var9 + 0xa0);
        }
    }

    if (var5[1] != 0) {
        if (func_020100f8((char*)var11) == 0) {
            func_020100c4(var11, var5[1]);
            var10 = func_020100f8((char*)var11);
        }
    }

    void* var13 = func_0203cf4c();
    char var14[16];
    const char* var15;
    char* var16;

    var8 = 0;
    var16 = var14;
    var15 = data_ov001_02164c4a;
    for (; var8 < 0x20; var8++) {
        int* var17 = (int*)func_0203dce4((Struct_0203dce4_2*)var13, var8);
        if (var17 != 0) {
            unsigned char* var18 = (unsigned char*)func_02040528(var17);
            if (var18[2] == 3) {
                Struct_0204039c* var19 = (Struct_0204039c*)func_0203d004(var13);
#if defined(jpn)
                sprintf(var16, var15, var18 + 0x10);
#else
                sprintf(var16, var15, var18 + 4);
#endif
                int var20 = func_02040404((Struct_0204027c_2*)var19, var16);
                func_0204039c(var19, var20);
                func_02040504(var17);
                func_0203dd10((Struct_0203dd10*)var13, var8, 0);
            }
        }
    }

    ReinitController02043204(globalA);
    func_02043124(globalA);
    ClearFlags04(res2, 8);
    if (IsScaledFieldPositive0203adfc(g_sePlayer, 0) != 0) {
        ScaleAndNotify0203ad88(data_02109bf4, 0, 0);
    }
    ClearFlags04(var6, 0x2000);
    func_0202e874((unsigned char*)var10, 0);
    func_0202f0c4(var10, 0xf000, 0);
    func_020708c8((Struct_020708c8*)func_020704fc(), 0);
    var1->MaybeReset();

    REG_DISPSTAT_304 &= ~0x8000;
    if (TestFlags00(var6, 0x1000) != 0) {
#if !defined(jpn)
        ResetAndReinit0209c278(data_02109bf4);
        Dispatch0203a974With0x57000_0209c290(data_02109bf4);
        SetupContextForMode0205ea20(g_sePlayer, 0x64);
#endif
        ClearFlags00((GameResources*)var6, 0x1000);
        func_ov028_021d9714();
        func_020a1f4c(1);
    }

    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;

    void* var21 = func_0205ec34();
    Struct_02013454* var22 = func_020196fc((Zone3D*)func_02012fe4(), 0);
    Struct_02016874_2* var23;
    int var24 = var22->unknown_4_.unknown_10_;
    if (var22 != 0) {
        for (int var25 = 0; var25 < var24; var25++) {
            var23 = &var22->unknown_44_[var25];
            if (func_0206dfb0((int)var21, (unsigned char*)((char*)var21 + 0x45b), var25 & 0xff) != 0) {
                if (var23 != 0) {
                    var23->unknown_2_ &= ~4;
                }
            } else {
                if (var23 != 0) {
                    var23->unknown_2_ |= 4;
                }
            }
        }
    }
    return 0xf;
}
