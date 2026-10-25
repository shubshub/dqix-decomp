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

struct Struct_020ad61c_3 {
    Object3D unknown_0_;
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_[0x80];
    int unknown_130_;
    unsigned char unknown_134_[8];
    int unknown_13c_;
    int unknown_140_;
    int unknown_144_;
    int unknown_148_;
    unsigned short unknown_14c_;
    unsigned short unknown_14e_;
    int unknown_150_;
    unsigned char unknown_154_[16];
    Vector3i unknown_164_;
    int unknown_170_;
    Vector3i unknown_174_;
    int unknown_180_;
};
struct Struct_02015438;
struct Struct_ov017_021d82fc_5 {
    unsigned char unknown_0_[13];
    unsigned char unknown_d_;
};
struct Struct_02015ef4 {
    unsigned int unknown_0_[3];
};
struct Entity020AE398;
struct Obj020ae3f4;
extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void func_020332ac(Trajectory020ad61c*);
extern "C" void func_020adda4(Trajectory020ad61c*);
extern "C" void func_020adaac(Trajectory020ad61c*);
void SubtractHeightOffset020ae398(Entity020AE398*);
void UpdateFallMotion020ae3f4(Obj020ae3f4*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
void GameObject_EnableControl(void*);
int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
extern "C" int Zone3D_GetGroundHeight(Zone3D*, Vec3copy0202ec84*);
int IsField0Null_02046b08(void**);
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
    int saved144 = object->saved144;
    int saved148 = object->saved148;
    func_020332ac(object);
    func_020adda4(object);
    switch (object->state) {
    case 0:
        func_020adaac(arg0);
        *(Vector3i*)((char*)var0 + Enum_020ad61c_10168) = arg0->unknown_0_.position_;
        *(int*)((char*)var0 + Enum_020ad61c_10180) = arg0->unknown_ae_;
        arg0->unknown_140_ = 0;
        break;
    case 1:
        func_020ae398((Struct_020ad61c*)arg0);
        break;
    case 2:
        func_020ae3f4((Struct_020ad61c_2*)arg0);
        break;
    }
    arg0->unknown_144_ = var4;
    arg0->unknown_148_ = var5;
    arg0->unknown_14c_ += var3->GetTickCount() * 364;
    arg0->unknown_150_ = data_020e9450[(arg0->unknown_14c_ >> 4) * 2 + 1] >> 4;
    if (var0->currentZoneID_ != 10100) return;
    Vector3i var6;
    var6 = arg0->unknown_0_.position_;
    arg0->unknown_130_ = 0;
    if (var6.x >= 0x90000) {
        arg0->unknown_130_ |= 1;
        var6.x -= 0x120000;
        arg0->unknown_164_.x -= 0x120000;
        arg0->unknown_174_.x -= 0x120000;
    } else if (var6.x < -0x90000) {
        arg0->unknown_130_ |= 2;
        var6.x += 0x120000;
        arg0->unknown_164_.x += 0x120000;
        arg0->unknown_174_.x += 0x120000;
    }
    if (var6.z >= 0x70000) {
        arg0->unknown_130_ |= 4;
        var6.z -= 0xe0000;
        arg0->unknown_164_.z -= 0xe0000;
        arg0->unknown_174_.z -= 0xe0000;
    } else if (var6.z < -0x70000) {
        arg0->unknown_130_ |= 8;
        var6.z += 0xe0000;
        arg0->unknown_164_.z += 0xe0000;
        arg0->unknown_174_.z += 0xe0000;
    }
    object->object.position_ = position;
    GameResources* scene = GetGameResources();
    void* camera;
    int groundedHit;
    HeadNode02046b24** head = (HeadNode02046b24**)scene->fieldTaskQueue_;
    GameObject* actor = game->GetUnknownGameObject();
    if (actor && GetHeadNodeIdOrMinusOne(head) != 3) {
        actor->obj3D_.position_ = object->object.position_;
        GameObject_EnableControl(actor);
    }
    camera = game->GetCamera();
    int directHit = 0;
    groundedHit = 0;
    int screenX[3];
    int screenY[3];
    Vec3copy0202ec84 points[3] = {};
    points[0] = *(Vec3copy0202ec84*)&object->object.position_;
    points[1] = *(Vec3copy0202ec84*)&object->firstPosition;
    points[2] = *(Vec3copy0202ec84*)&object->secondPosition;
    for (int i = 0; i < 3; i++) Camera_WorldToScreen(camera, &points[i], &screenX[i], &screenY[i]);
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) {
        var1 = g_touchInput.prevX_;
        var2 = g_touchInput.prevY_;
    }
    for (int var17 = 0; var17 < 3; var17++) {
        if (var13[var17] - 16 < var1 && var1 < var13[var17] + 16 &&
            var14[var17] - 24 < var2 && var2 < var14[var17] + 8) {
            var12 = 1;
            break;
        }
    }
    if (!directHit) {
        for (int i = 0; i < 3; i++) {
            points[i].v[1] = Zone3D_GetGroundHeight(world, &points[i]);
            Camera_WorldToScreen(camera, &points[i], &screenX[i], &screenY[i]);
            if (screenX[i] - 16 < touchX && touchX < screenX[i] + 16 &&
                screenY[i] - 24 < touchY && touchY < screenY[i] + 8) {
                groundedHit = 1;
                break;
            }
        }
    }
    if (func_02046b08((void**)var10) && arg0->unknown_13c_ == 0) {
        if (g_keyManager.TestKeysPressed(1) || var9) {
            func_ov017_021a72f4(var7, 1);
        } else if (g_keyManager.TestKeysPressed(2) || var12) {
            func_ov017_021a72f4(var7, 0);
        } else if (g_keyManager.TestKeysPressed(256)) {
            if (!(data_ov017_021d82fc.unknown_d_ & 16)) data_ov017_021d82fc.unknown_d_ |= 16;
        }
    }
}
