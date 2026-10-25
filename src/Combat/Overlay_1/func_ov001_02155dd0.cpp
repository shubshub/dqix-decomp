#include <globaldefs.h>
#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Graphics.h"
#include "World/Object3D.h"
#include "std_library_functions.h"


struct Struct_02000c9c_36;
struct Struct_0203dce4_2;
struct Struct_0204039c;
struct Struct_0203dd10;

struct Struct_ov001_02155dd0 {
    char unknown_0_[0xa];
    unsigned short unknown_a_;
};

char* GetFieldIfFlag4_020100f8(char* obj);
void* GetFieldPtrAt0x5ca4_02010768(void* obj);
extern "C" void* Zone3D_GetInstance();
char* MessageSystem_GetInstance();
void* GetGlobalPtr021075f4_0203cf4c(void);
void* EmptyStub0203d004(void* p);
void* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
int* GetField0x8_02040528(int* p);
struct Container02040404;
int FindEntryIndexByName02040404(Container02040404*, char const*);
void ReleaseOrDecrementSlot0204039c(Container0204039c* c, int idx);
void Reset02040504(int* p);
void SetSlotIfIndexBelow32(SlotArray0203dd10*, unsigned int, int);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
int IsScaledFieldPositive0203adfc(void* a, void* b);
void ScaleAndNotify0203ad88(void* a, void* b, int c);
void SetField0x7cClearFields0x1ec0x1ee_0202e874(unsigned char*, unsigned short);
void SetFields0x1f0And0x1f4_0202f0c4(void* obj, int a, int b);
extern "C" void* func_020704fc();
struct Struct_020708c8;
extern "C" void func_020708c8(Struct_020708c8*, unsigned int);
extern "C" void func_0209c278(void* arg0);
extern "C" void func_0209c290(void* arg0);
extern "C" void func_0205ea20(void* arg0, int arg1);
extern "C" void func_ov028_021d9714();
void PopStack1AndTrigger_020a1f4c(int v);
extern "C" void* Scenario_GetInstance();
int Scenario_TestFlag(int p, unsigned char* arr, int bit);
struct Bytes02033b88;
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void ClearCombatantSlot_0200fd48(GameState* gs, int id);
void GameState_SetCamera(GameState* gs, int val);

extern char data_ov001_02164c4a[];
extern char g_sePlayer[];
extern char g_bgmPlayer[];

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

    gs = GameState::GetInstance();
    hud = GetFieldIfFlag4_020100f8((char*)gs);
    res2 = GetGameResources();
    area = (Zone3D*)Zone3D_GetInstance();
    globalA = MessageSystem_GetInstance();
    loader = BackgroundLoader::GetInstance();
    ptr6 = (int*)GetFieldPtrAt0x5ca4_02010768(gs);

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

    if (ptr6[1] != 0) {
        if (GetFieldIfFlag4_020100f8((char*)gs) == 0) {
            GameState_SetCamera(gs, ptr6[1]);
            hud = GetFieldIfFlag4_020100f8((char*)gs);
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

    MessageSystem_Reset(globalA);
    MessageSystem_Stop(globalA);
    ClearFlags04(res2, 8);
    if (IsScaledFieldPositive0203adfc(g_sePlayer, 0) != 0) {
        ScaleAndNotify0203ad88(g_bgmPlayer, 0, 0);
    }
    ClearFlags04(var6, 0x2000);
    func_0202e874((unsigned char*)var10, 0);
    func_0202f0c4(var10, 0xf000, 0);
    func_020708c8((Struct_020708c8*)func_020704fc(), 0);
    var1->MaybeReset();

    REG_DISPSTAT_304 &= ~0x8000;
    if (TestFlags00(var6, 0x1000) != 0) {
#if !defined(jpn)
        ResetAndReinit0209c278(g_bgmPlayer);
        Dispatch0203a974With0x57000_0209c290(g_bgmPlayer);
        SetupContextForMode0205ea20(g_sePlayer, 0x64);
#endif
        ClearFlags00((GameResources*)var6, 0x1000);
        func_ov028_021d9714();
        func_020a1f4c(1);
    }

    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;

    void* events = Scenario_GetInstance();
    BmdjScriptNode* node = Zone3D_GetScriptNode((Zone3D*)Zone3D_GetInstance(), 0);
    BmdjSceneElement* e;
    int count = node->scriptState.elementCount;
    if (node != 0) {
        for (int n = 0; n < count; n++) {
            e = &node->elements[n];
            if (Scenario_TestFlag((int)events, (unsigned char*)((char*)events + 0x45b), n & 0xff) != 0) {
                if (e != 0) {
                    e->flags &= ~4;
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
