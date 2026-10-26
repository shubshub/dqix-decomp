#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

struct Struct_020a72ac {
    Object3D unknown_0_;
    unsigned char unknown_ac_[0x144 - 0xac];
    Vector3i unknown_144_;
};
struct Struct_020a72ac_2 {
    unsigned char unknown_0_[8];
    Vector3i unknown_8_;
    unsigned char unknown_14_[0x20 - 0x14];
    short unknown_20_;
};
struct Struct_02017a94;
struct Struct_02013380;
struct Struct_02033834;
struct Struct_0200ffc0;

struct Struct_020a72ac_3 {
    unsigned short unknown_0_;
#if defined(jpn)
    char unknown_2_[0x27c4 - 2];
#else
    char unknown1_2_[0x2784 - 2];
#endif
    short unknown_2784_;
    unsigned short unknown_2786_;
    unsigned char unknown_2788_;
};

extern "C" void* LinkSession_GetInstance();
extern "C" int LinkSession_IsGuest(void* base);
void SetVec3At0x0020a6aa4(Vector3i* obj, int x, int y, int z);
void* GameState_GetShip(struct PointerField32c_ffc0* p);
struct Obj0201b600* FindElemByKeys(Obj0201b600* p, int a, unsigned short b);
void BmdjSceneElement_SetShown(struct Struct02013380* p, int a, int b);
void ApplyElementFlags0201b8c8(struct Obj0201b600* p, int a, int b, int c);
void* FindNodeByField0x2c0201b754(void* p, int v);
void GameObject_SnapFacing(struct Obj02033874* p, int v);

// USA: func_020a72ac
extern "C" ARM void func_020a72ac(struct Struct_020a72ac_3* arg0) {
    GameState* var0 = GameState::GetInstance();
    GetGameResources();
    void* base = LinkSession_GetInstance();
    LightingManager::GetInstance();
    Object3D* obj = static_cast<Object3D*>(GameState_GetShip((struct PointerField32c_ffc0*)gs));
    GameObject* actor = gs->GetLeader();
    gs->GetPartyMemberByIndex(0);

    if (p->flag2788 == 0) {
        if (p->field2786 == p->key) {
            if (p->key == 0x76c) {
                struct Obj0201b600* e = FindElemByKeys((struct Obj0201b600*)p, 0, 4);
                if (e) BmdjSceneElement_SetShown((struct Struct02013380*)e, 0, 1);
                e = FindElemByKeys((struct Obj0201b600*)p, 0, 0x28);
                if (e) BmdjSceneElement_SetShown((struct Struct02013380*)e, 0, 1);
            } else if (obj) {
                obj->MakeVisible();
                SavedObjectNode* node = static_cast<SavedObjectNode*>(FindNodeByField0x2c0201b754(p, p->field2784));
                if (node) {
                    obj->position_ = node->position;
                    reinterpret_cast<WorldObjectPositionView*>(obj)->secondaryPosition = node->position;
                    GameObject_SnapFacing((struct Obj02033874*)obj, node->angle);
                }
            }
        } else {
            if (arg0->unknown_0_ == 0x170c) {
                func_0201b8c8((struct Struct_02017a94*)arg0, 0, 1, 0);
            } else if (arg0->unknown_0_ == 0x2774 || arg0->unknown_0_ == 0x2710) {
                if (var2) var2->MakeVisible();
            } else if (var2) {
                var2->MakeHidden();
            }
        }
    } else {
        if (arg0->unknown_2786_ == arg0->unknown_0_) {
            if (var2) var2->MakeHidden();
        } else if (arg0->unknown_0_ == 0x170c) {
            func_0201b8c8((struct Struct_02017a94*)arg0, 1, 0, 1);
            Vector3i var6 = var3->obj3D_.position_;
            if (var6.z >= 0x6000 && var6.x >= -0x8333 && var6.x <= -0x5ccc) {
                func_020a6aa4(&var6, -0x7000, 0x2e1, 0x5e66);
                var3->obj3D_.position_ = var6;
            }
        } else if (p->key == 0x76c) {
            struct Obj0201b600* e = FindElemByKeys((struct Obj0201b600*)p, 0, 4);
            if (e) BmdjSceneElement_SetShown((struct Struct02013380*)e, 0, 0);
            e = FindElemByKeys((struct Obj0201b600*)p, 0, 0x28);
            if (e) BmdjSceneElement_SetShown((struct Struct02013380*)e, 0, 0);
        } else if (p->key == 0x2774) {
            if (obj) obj->MakeVisible();
        } else if (LinkSession_IsGuest(base) && p->key == 0x2710) {
            if (obj) obj->MakeVisible();
        } else if (obj) {
            obj->MakeHidden();
        }
    }
}
