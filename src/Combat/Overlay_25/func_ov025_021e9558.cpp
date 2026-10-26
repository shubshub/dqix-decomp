#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Graphics/LightingManager.h"
#include "World/Object3D.h"

struct Flags02033fdc;
extern "C" void GameObject_ResumeMovement(struct Flags02033fdc* p);
extern "C" void func_0200fd48(GameState* battleStruct, int id);
extern "C" void* func_ov000_02160130(void);
extern "C" void SePlayer_UnloadExtraArchiveB(void* obj);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* obj, int index);

struct Struct_ov025_021e9558 {
    char pad0[0x20];
    unsigned short id;
    char unknown_22_[0xe];
    struct Struct_ov025_021e9558* next;
};

struct Struct_ov025_021e9558_2 {
    char pad0[0x10];
    struct Struct_ov025_021e9558* head;
};

struct Struct_ov025_021e9558_3 {
#if defined(jpn)
    char pad0[0x5b44];
#else
    char pad0[0x5954];
#endif
    Object3D actors[2];
};

struct Struct_ov025_021e9558_4 {
    char pad0[0x1c4];
    int unknown_1c4_;
    char unknown_1c8_[0x582 - 0x1c8];
    unsigned char unknown_582_;
    char unknown_583_;
    unsigned short unknown_584_[8];
    char unknown_594_[0x880 - 0x594];
    int unknown_880_;
};

extern "C" Struct_ov025_021e9558_2* func_ov000_02160f20(void* work);
extern "C" void func_ov025_021e8bc4(struct Struct_ov025_021e9558_4* obj, int priority);

extern unsigned int data_ov025_021ef990;
extern const char data_ov025_021ef8dc[];
extern char g_sePlayer[];

// USA: func_ov025_021e9558
extern "C" ARM void func_ov025_021e9558(struct Struct_ov025_021e9558_4* obj) {
    GameState* gs = GameState::GetInstance();
    Struct_ov025_021e9558_3* work = (Struct_ov025_021e9558_3*)func_ov000_02160130();
    Struct_ov025_021e9558_2* slot = func_ov000_02160f20(work);
    void* list = func_02057924();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    for (int i = 0; i < obj->unknown_582_; i++) {
        loader->RemoveTask(obj->unknown_584_[i]);
    }
    obj->unknown_582_ = 0;

    if (obj->unknown_880_ >= 0) {
        loader->RemoveTask(obj->unknown_880_);
        obj->unknown_880_ = -1;
    }

    func_ov025_021e8bc4(obj, 0);

    for (unsigned int i = 0; i < data_ov025_021ef990; i++) {
        func_02057f00(list, i + 100);
    }
    func_02057f00(list, 4);
    func_02057f00(list, 0x20);
    func_02057f00(list, 0x21);
    func_02057f00(list, 0x1b);
    func_02057f00(list, 0x19);
    func_02057f00(list, 0x1a);
    func_02057f00(list, 0x1f);
    func_02057f00(list, 0x21);
    func_02057f00(list, 0x22);
    func_02057f00(list, 0x23);
    func_02057f00(list, 0x24);
    data_ov025_021ef990 = 0;

    for (Struct_ov025_021e9558* node = slot->head; node != NULL; node = node->next) {
        GameObject* c = gs->GetCombatantByIndex(node->id);
        if (c != NULL) {
            c->obj3D_.DisableFlag(0x800);
            GameObject_ResumeMovement((struct Flags02033fdc*)c);
        }
    }

    GameObject* holder = gs->GetGameObjectByIndex(200);
    if (holder != NULL) {
        GameObject* target = gs->GetGameObjectByIndex(holder->obj3D_.unknown_2_ * 12 + 0x1c);
        if (target != NULL) {
            target->obj3D_.MakeVisible();
        }
        holder->obj3D_.Detach();
        func_0200fd48(gs, 200);
    }

#if defined(jpn)
    char* secondActorBase = (char*)work + 0xbf0;
    secondActorBase++;
#endif
    work->actors[0].SetAnimationByName(data_ov025_021ef8dc, 1);
#if defined(jpn)
    ((Object3D*)(secondActorBase - 1 + 0x5000))->SetAnimationByName(data_ov025_021ef8dc, 1);
#else
    work->actors[1].SetAnimationByName(data_ov025_021ef8dc, 1);
#endif
    SePlayer_UnloadExtraArchiveB(g_sePlayer);
    LightingManager::GetInstance()->BeginFade(0x1000, 1000);
    obj->unknown_1c4_ = 0;
}
