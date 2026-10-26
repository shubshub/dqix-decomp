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
    char pad0[0xa];
    unsigned short fieldA;
};

extern "C" char* GameState_GetFollowCamera(char* obj);
extern "C" void* func_02010768(void* obj);
extern "C" void* Zone3D_GetInstance();
extern "C" char* MessageSystem_GetInstance();
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203d004(void* p);
extern "C" void* func_0203dce4(Struct_0203dce4_2*, int);
extern "C" int* func_02040528(int* p);
struct Struct_0204027c_2;
extern "C" int func_02040404(Struct_0204027c_2*, char const*);
extern "C" void func_0204039c(Struct_0204039c* c, int idx);
extern "C" void func_02040504(int* p);
extern "C" void func_0203dd10(Struct_0203dd10*, unsigned int, int);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
extern "C" int SoundPlayer_IsStreamPlaying(void* a, void* b);
extern "C" void SoundPlayer_StopStream(void* a, void* b, int c);
extern "C" void Camera_SetRoll(unsigned char*, unsigned short);
extern "C" void Camera_EaseFieldOfViewTo(void* obj, int a, int b);
extern "C" void* func_020704fc();
struct Struct_020708c8;
extern "C" void func_020708c8(Struct_020708c8*, unsigned int);
extern "C" void func_0209c278(void* obj);
extern "C" void BgmPlayer_LoadArchive(void* obj);
extern "C" void SePlayer_LoadArchive(void* obj, int mode);
extern "C" void func_ov028_021d9714();
extern "C" void func_020a1f4c(int v);
extern "C" void* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int p, unsigned char* arr, int bit);
struct Bytes02033b88;
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void func_0200fd48(GameState* gs, int id);
extern "C" void GameState_SetCamera(GameState* gs, int val);

extern char data_ov001_02164c4a[];
extern char g_sePlayer[];
extern char g_bgmPlayer[];

#define REG_DISPSTAT_304 (*(volatile unsigned short*)0x04000304)

// USA: func_ov001_02155dd0
extern "C" ARM unsigned short func_ov001_02155dd0(Struct_ov001_02155dd0* self) {
    GameResources* res = GetGameResources();
    if (IsBrightnessTransitionActive(res)) {
        return self->fieldA;
    }

        BackgroundLoader* loader;
        char* globalA;
        GameObject* obj;
        int i;
        int* ptr6;
        GameResources* res2;
        Zone3D* area;
        int k;
        int j;
        char* hud;
        GameState* gs;

    gs = GameState::GetInstance();
    hud = GameState_GetFollowCamera((char*)gs);
    res2 = GetGameResources();
    area = (Zone3D*)Zone3D_GetInstance();
    globalA = MessageSystem_GetInstance();
    loader = BackgroundLoader::GetInstance();
    ptr6 = (int*)func_02010768(gs);

    for (i = 0; i < 4; i++) {
        obj = gs->GetWanderingMonsterByIndex(i);
        if (obj != 0) {
            obj->obj3D_.RemoveAnimationPackageByID(3);
            unsigned short var12 = area->currentZoneID_;
            if (var12 == obj->obj3D_.GetField06()) {
                obj->obj3D_.MakeVisible();
            }
            GameObject_ForceMotionState((Bytes02033b88*)obj, 0);
        }
    }

    for (j = 0; j < 0x20; j++) {
        obj = gs->GetGameObjectByIndex(j + 0xa0);
        if (obj != 0) {
            obj->obj3D_.Destroy();
            func_0200fd48(gs, j + 0xa0);
        }
    }

    if (ptr6[1] != 0) {
        if (GameState_GetFollowCamera((char*)gs) == 0) {
            GameState_SetCamera(gs, ptr6[1]);
            hud = GameState_GetFollowCamera((char*)gs);
        }
    }

    void* list = func_0203cf4c();
    char buf[16];
    const char* fmt;
    char* nameBuf;

    k = 0;
    nameBuf = buf;
    fmt = data_ov001_02164c4a;
    for (; k < 0x20; k++) {
        int* entry = (int*)func_0203dce4((Struct_0203dce4_2*)list, k);
        if (entry != 0) {
            unsigned char* p = (unsigned char*)func_02040528(entry);
            if (p[2] == 3) {
                Struct_0204039c* cont = (Struct_0204039c*)func_0203d004(list);
#if defined(jpn)
                sprintf(nameBuf, fmt, p + 0x10);
#else
                sprintf(nameBuf, fmt, p + 4);
#endif
                int idx = func_02040404((Struct_0204027c_2*)cont, nameBuf);
                func_0204039c(cont, idx);
                func_02040504(entry);
                func_0203dd10((Struct_0203dd10*)list, k, 0);
            }
        }
    }

    MessageSystem_Reset(globalA);
    MessageSystem_Stop(globalA);
    ClearFlags04(res2, 8);
    if (SoundPlayer_IsStreamPlaying(g_sePlayer, 0) != 0) {
        SoundPlayer_StopStream(g_bgmPlayer, 0, 0);
    }
    ClearFlags04(res2, 0x2000);
    Camera_SetRoll((unsigned char*)hud, 0);
    Camera_EaseFieldOfViewTo(hud, 0xf000, 0);
    func_020708c8((Struct_020708c8*)func_020704fc(), 0);
    loader->ClearQueue();

    REG_DISPSTAT_304 &= ~0x8000;
    if (TestFlags00(res2, 0x1000) != 0) {
#if !defined(jpn)
        func_0209c278(g_bgmPlayer);
        BgmPlayer_LoadArchive(g_bgmPlayer);
        SePlayer_LoadArchive(g_sePlayer, 0x64);
#endif
        ClearFlags00((GameResources*)res2, 0x1000);
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
                if (e != 0) {
                    e->flags |= 4;
                }
            }
        }
    }
    return 0xf;
}
