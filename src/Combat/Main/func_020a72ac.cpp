#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

struct Struct_020a72ac {
    Object3D object;
    unsigned char unknownAc[0x144 - 0xac];
    Vector3i unknown_144_;
};
struct Struct_020a72ac_2 {
    unsigned char unknown0[8];
    Vector3i position;
    unsigned char unknown14[0x20 - 0x14];
    short angle;
};
struct Obj0201b600;
struct Struct02013380;
struct Obj02033874;
struct PointerField32c_ffc0;

struct Struct_020a72ac_3 {
    unsigned short key;
#if defined(jpn)
    char pad0[0x27c4 - 2];
#else
    char pad0[0x2784 - 2];
#endif
    short unknown_2784_;
    unsigned short unknown_2786_;
    unsigned char unknown_2788_;
};

extern "C" void* LinkSession_GetInstance();
extern "C" int LinkSession_IsGuest(void* base);
extern "C" void func_020a6aa4(Vector3i* obj, int x, int y, int z);
extern "C" void* GameState_GetShip(struct PointerField32c_ffc0* p);
extern "C" struct Obj0201b600* func_0201b600(Obj0201b600* p, int a, unsigned short b);
extern "C" void BmdjSceneElement_SetShown(struct Struct02013380* p, int a, int b);
extern "C" void func_0201b8c8(struct Obj0201b600* p, int a, int b, int c);
extern "C" void* func_0201b754(void* p, int v);
extern "C" void GameObject_SnapFacing(struct Obj02033874* p, int v);

// USA: func_020a72ac
extern "C" ARM void func_020a72ac(struct Struct_020a72ac_3* p) {
    GameState* gs = GameState::GetInstance();
    GetGameResources();
    void* base = LinkSession_GetInstance();
    LightingManager::GetInstance();
    Object3D* obj = static_cast<Object3D*>(GameState_GetShip((struct PointerField32c_ffc0*)gs));
    GameObject* actor = gs->GetLeader();
    gs->GetPartyMemberByIndex(0);

    if (p->unknown_2788_ == 0) {
        if (p->unknown_2786_ == p->key) {
            if (p->key == 0x76c) {
                struct Obj0201b600* e = func_0201b600((struct Obj0201b600*)p, 0, 4);
                if (e) BmdjSceneElement_SetShown((struct Struct02013380*)e, 0, 1);
                e = func_0201b600((struct Obj0201b600*)p, 0, 0x28);
                if (e) BmdjSceneElement_SetShown((struct Struct02013380*)e, 0, 1);
            } else if (obj) {
                obj->MakeVisible();
                Struct_020a72ac_2* node = static_cast<Struct_020a72ac_2*>(func_0201b754(p, p->unknown_2784_));
                if (node) {
                    obj->position_ = node->position;
                    reinterpret_cast<Struct_020a72ac*>(obj)->unknown_144_ = node->position;
                    GameObject_SnapFacing((struct Obj02033874*)obj, node->angle);
                }
            }
        } else {
            if (p->key == 0x170c) {
                func_0201b8c8((struct Obj0201b600*)p, 0, 1, 0);
            } else if (p->key == 0x2774 || p->key == 0x2710) {
                if (obj) obj->MakeVisible();
            } else if (obj) {
                obj->MakeHidden();
            }
        }
    } else {
        if (p->unknown_2786_ == p->key) {
            if (obj) obj->MakeHidden();
        } else if (p->key == 0x170c) {
            func_0201b8c8((struct Obj0201b600*)p, 1, 0, 1);
            Vector3i local = actor->obj3D_.position_;
            if (local.z >= 0x6000 && local.x >= -0x8333 && local.x <= -0x5ccc) {
                func_020a6aa4(&local, -0x7000, 0x2e1, 0x5e66);
                actor->obj3D_.position_ = local;
            }
        } else if (p->key == 0x76c) {
            struct Obj0201b600* e = func_0201b600((struct Obj0201b600*)p, 0, 4);
            if (e) BmdjSceneElement_SetShown((struct Struct02013380*)e, 0, 0);
            e = func_0201b600((struct Obj0201b600*)p, 0, 0x28);
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
