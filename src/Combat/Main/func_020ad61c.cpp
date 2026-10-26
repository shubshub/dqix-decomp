#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <Resource/GameResources.h>
#include "World/Zone3D.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_020ad61c_10168 = 0x27f8, Enum_020ad61c_10180 = 0x2804 };
#else
enum { Enum_020ad61c_10168 = 0x27b8, Enum_020ad61c_10180 = 0x27c4 };
#endif

struct Trajectory020ad61c {
    Object3D object;
    short unknown_ac_;
    short angle;
    unsigned char unknown_b0_[0x80];
    int unknown_130_;
    unsigned char unknown_134_[8];
    int state;
    int unknown_140_;
    int unknown_144_;
    int unknown_148_;
    unsigned short phase;
    unsigned short unknown_14e_;
    int unknown_150_;
    unsigned char unknown_154_[16];
    Vector3i unknown_164_;
    int firstAngle;
    Vector3i unknown_174_;
    int unknown_180_;
};
struct HeadNode02046b24;
struct Struct_ov017_021d82fc_5 {
    unsigned char field0[13];
    unsigned char flags;
};
struct Vec3copy0202ec84 {
    unsigned int v[3];
};
struct Struct_020ad61c;
struct Struct_020ad61c_2;
extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void GameObject_Update(Trajectory020ad61c*);
extern "C" void func_020adda4(Trajectory020ad61c*);
extern "C" void func_020adaac(Trajectory020ad61c*);
extern "C" void func_020ae398(Struct_020ad61c*);
extern "C" void func_020ae3f4(Struct_020ad61c_2*);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void GameObject_EnableControl(void*);
extern "C" int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" int Zone3D_GetGroundHeight(Zone3D*, Vec3copy0202ec84*);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" void func_ov017_021a72f4(GameResources*, int);
extern short data_020e9450[];
extern Struct_ov017_021d82fc_5 data_ov017_021d82fc;

// USA: func_020ad61c
extern "C" ARM void func_020ad61c(Trajectory020ad61c* object) {
    Zone3D* world;
    int touchX;
    int touchY;
    GameState* game = GameState::GetInstance();
    world = Zone3D_GetInstance();
    int var4 = object->unknown_144_;
    int var5 = object->unknown_148_;
    GameObject_Update(object);
    func_020adda4(object);
    switch (object->state) {
    case 0:
        func_020adaac(object);
        *(Vector3i*)((char*)world + Enum_020ad61c_10168) = object->object.position_;
        *(int*)((char*)world + Enum_020ad61c_10180) = object->angle;
        object->unknown_140_ = 0;
        break;
    case 1:
        func_020ae398((Struct_020ad61c*)object);
        break;
    case 2:
        func_020ae3f4((Struct_020ad61c_2*)object);
        break;
    }
    object->unknown_144_ = var4;
    object->unknown_148_ = var5;
    object->phase += game->GetTickCount() * 364;
    object->unknown_150_ = data_020e9450[(object->phase >> 4) * 2 + 1] >> 4;
    if (world->currentZoneID_ != 10100) return;
    Vector3i position;
    position = object->object.position_;
    object->unknown_130_ = 0;
    if (position.x >= 0x90000) {
        object->unknown_130_ |= 1;
        position.x -= 0x120000;
        object->unknown_164_.x -= 0x120000;
        object->unknown_174_.x -= 0x120000;
    } else if (position.x < -0x90000) {
        object->unknown_130_ |= 2;
        position.x += 0x120000;
        object->unknown_164_.x += 0x120000;
        object->unknown_174_.x += 0x120000;
    }
    if (position.z >= 0x70000) {
        object->unknown_130_ |= 4;
        position.z -= 0xe0000;
        object->unknown_164_.z -= 0xe0000;
        object->unknown_174_.z -= 0xe0000;
    } else if (position.z < -0x70000) {
        object->unknown_130_ |= 8;
        position.z += 0xe0000;
        object->unknown_164_.z += 0xe0000;
        object->unknown_174_.z += 0xe0000;
    }
    object->object.position_ = position;
    GameResources* scene = GetGameResources();
    void* camera;
    int var9;
    HeadNode02046b24** head = (HeadNode02046b24**)scene->fieldTaskQueue_;
    GameObject* actor = game->GetLeader();
    if (actor && FieldTaskQueue_GetCurrentKind(head) != 3) {
        actor->obj3D_.position_ = object->object.position_;
        GameObject_EnableControl(actor);
    }
    camera = game->GetCamera();
    int var12 = 0;
    var9 = 0;
    int screenX[3];
    int screenY[3];
    Vec3copy0202ec84 points[3] = {};
    points[0] = *(Vec3copy0202ec84*)&object->object.position_;
    points[1] = *(Vec3copy0202ec84*)&object->unknown_164_;
    points[2] = *(Vec3copy0202ec84*)&object->unknown_174_;
    for (int i = 0; i < 3; i++) Camera_WorldToScreen(camera, &points[i], &screenX[i], &screenY[i]);
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) {
        touchX = g_touchInput.prevX_;
        touchY = g_touchInput.prevY_;
    }
    for (int i = 0; i < 3; i++) {
        if (screenX[i] - 16 < touchX && touchX < screenX[i] + 16 &&
            screenY[i] - 24 < touchY && touchY < screenY[i] + 8) {
            var12 = 1;
            break;
        }
    }
    if (!var12) {
        for (int i = 0; i < 3; i++) {
            points[i].v[1] = Zone3D_GetGroundHeight(world, &points[i]);
            Camera_WorldToScreen(camera, &points[i], &screenX[i], &screenY[i]);
            if (screenX[i] - 16 < touchX && touchX < screenX[i] + 16 &&
                screenY[i] - 24 < touchY && touchY < screenY[i] + 8) {
                var9 = 1;
                break;
            }
        }
    }
    if (FieldTaskQueue_IsEmpty((void**)head) && object->state == 0) {
        if (g_keyManager.TestKeysPressed(1) || var9) {
            func_ov017_021a72f4(scene, 1);
        } else if (g_keyManager.TestKeysPressed(2) || var12) {
            func_ov017_021a72f4(scene, 0);
        } else if (g_keyManager.TestKeysPressed(256)) {
            if (!(data_ov017_021d82fc.flags & 16)) data_ov017_021d82fc.flags |= 16;
        }
    }
}
