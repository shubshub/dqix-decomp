#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Graphics/LightingManager.h"
#include "World/Object3D.h"

struct Flags02033fdc;
void GameObject_ResumeMovement(struct Flags02033fdc* p);
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);
void* GetActiveCombatWork_ov000_02160130(void);
void SePlayer_UnloadExtraArchiveB(void* obj);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* arg0, int arg1);

struct Struct_ov025_021e9558 {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
    char unknown_22_[0xe];
    struct Struct_ov025_021e9558* unknown_30_;
};

struct Struct_ov025_021e9558_2 {
    char unknown_0_[0x10];
    struct Struct_ov025_021e9558* unknown_10_;
};

struct Struct_ov025_021e9558_3 {
#if defined(jpn)
    char unknown_0_[0x5b44];
#else
    char unknown1_0_[0x5954];
#endif
    Object3D unknown_5954_[2];
};

struct Struct_ov025_021e9558_4 {
    char unknown_0_[0x1c4];
    int unknown_1c4_;
    char unknown_1c8_[0x582 - 0x1c8];
    unsigned char unknown_582_;
    char unknown_583_;
    unsigned short unknown_584_[8];
    char unknown_594_[0x880 - 0x594];
    int unknown_880_;
};

extern "C" Struct_ov025_021e9558_2* func_ov000_02160f20(void* arg0);
extern "C" void func_ov025_021e8bc4(struct Struct_ov025_021e9558_4* arg0, int arg1);

extern unsigned int data_ov025_021ef990;
extern const char data_ov025_021ef8dc[];
extern char g_sePlayer[];

// USA: func_ov025_021e9558
extern "C" ARM void func_ov025_021e9558(struct Struct_ov025_021e9558_4* arg0) {
    GameState* var0 = GameState::GetInstance();
    Struct_ov025_021e9558_3* var1 = (Struct_ov025_021e9558_3*)func_ov000_02160130();
    Struct_ov025_021e9558_2* var2 = func_ov000_02160f20(var1);
    void* var3 = func_02057924();
    BackgroundLoader* var4 = BackgroundLoader::GetInstance();

    for (int var5 = 0; var5 < arg0->unknown_582_; var5++) {
        var4->RemoveTask(arg0->unknown_584_[var5]);
    }
    arg0->unknown_582_ = 0;

    if (arg0->unknown_880_ >= 0) {
        var4->RemoveTask(arg0->unknown_880_);
        arg0->unknown_880_ = -1;
    }

    func_ov025_021e8bc4(arg0, 0);

    for (unsigned int var6 = 0; var6 < data_ov025_021ef990; var6++) {
        func_02057f00(var3, var6 + 100);
    }
    func_02057f00(var3, 4);
    func_02057f00(var3, 0x20);
    func_02057f00(var3, 0x21);
    func_02057f00(var3, 0x1b);
    func_02057f00(var3, 0x19);
    func_02057f00(var3, 0x1a);
    func_02057f00(var3, 0x1f);
    func_02057f00(var3, 0x21);
    func_02057f00(var3, 0x22);
    func_02057f00(var3, 0x23);
    func_02057f00(var3, 0x24);
    data_ov025_021ef990 = 0;

    for (CombatNode021e9558* node = slot->head; node != NULL; node = node->next) {
        GameObject* c = gs->GetCombatantByIndex(node->id);
        if (c != NULL) {
            c->obj3D_.DisableFlag(0x800);
            GameObject_ResumeMovement((struct Flags02033fdc*)c);
        }
    }

    GameObject* var9 = var0->GetGameObjectByIndex(200);
    if (var9 != NULL) {
        GameObject* var10 = var0->GetGameObjectByIndex(var9->obj3D_.unknown_2_ * 12 + 0x1c);
        if (var10 != NULL) {
            var10->obj3D_.MakeVisible();
        }
        var9->obj3D_.Detach();
        func_0200fd48(var0, 200);
    }

#if defined(jpn)
    char* var11 = (char*)var1 + 0xbf0;
    var11++;
#endif
    work->actors[0].SetAnimationByName(data_ov025_021ef8dc, 1);
#if defined(jpn)
    ((Object3D*)(secondActorBase - 1 + 0x5000))->SetAnimationByName(data_ov025_021ef8dc, 1);
#else
    work->actors[1].SetAnimationByName(data_ov025_021ef8dc, 1);
#endif
    SePlayer_UnloadExtraArchiveB(g_sePlayer);
    LightingManager::GetInstance()->BeginFade(0x1000, 1000);
    arg0->unknown_1c4_ = 0;
}
