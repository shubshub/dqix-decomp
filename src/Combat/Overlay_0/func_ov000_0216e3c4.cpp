#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Util/Random.h"

struct BattleCamera {
    unsigned char padding0[0x10];
    Vector3i target;
    unsigned char padding1c[0x200];
    Random* battle;
    unsigned char unknown_220_[0x18];
    int mode;
    unsigned char unknown_23c_[0x3c];
    unsigned char active;
};
struct Struct_ov000_0216e3c4 {
    Object3D object;
    unsigned char unknown_ac_[0x16];
    unsigned char flags : 4;
    unsigned char included : 1;
};
struct Struct_ov000_0216d368 { int x, y, z; };
struct GlobalObj0202e6a8;
extern "C" void func_ov000_0216d370(BattleCamera*, int, int, int);
extern "C" int func_ov000_0215e9fc(Random*, short*, int, int);
extern "C" void Camera_SetOrbit(BattleCamera*, int, int, int);
extern "C" Struct_ov000_0216e3c4* func_0200fea4(GameState*, int);
extern "C" void Camera_SetTarget(struct Camera*, int, int, int);
extern "C" void func_ov000_0216d368(Struct_ov000_0216d368*, int, int, int);
extern "C" void Camera_SetOrbitYaw(GlobalObj0202e6a8*, int);

// USA: func_ov000_0216e3c4
extern "C" ARM void func_ov000_0216e3c4(BattleCamera* camera) {
    if (!camera->battle) return;
    GameState* game = GameState::GetInstance();
    func_ov000_0216d370(camera, 1, 1, 1);
    GameObject* protagonist = game->GetProtagonist();
    int group = -1;
    if (protagonist) group = protagonist->obj3D_.GetField06();
    short ids[4];
    int count = func_ov000_0215e9fc(camera->battle, ids, 4, 0);
    Vector3i center = {};
    int var6 = 0;
    for (int i = 0; i < count; i++) {
        GameObject* object = game->GetGameObjectByIndex(ids[i]);
        if (object && group == object->obj3D_.GetField06()) {
            Vector3i position = object->obj3D_.position_;
            Vector3fix_Add(&center, &position, &center);
            var6++;
        }
    }
    if (var6 > 0) {
        int scale = fix32_Divide(0x1000, var6 << 12);
        Vector3fixMultiplyScalar(&center, scale, &center);
    }
    int distance = 0xc000 - Vector3fix_Length(&center);
    if (distance < 0x8000) {
        int scale = fix32_Divide(distance, 0x8000);
        Vector3fixMultiplyScalar(&center, scale, &center);
        distance = 0xc000;
    }
    int angle = 0;
    count = func_ov000_0215e9fc(camera->battle, ids, 4, 1);
    if (count > 0) {
        int selected = NextRandomMax(camera->battle, count);
        GameObject* object = game->GetGameObjectByIndex(ids[selected]);
        if (object) angle = object->obj3D_.rotation_.y;
    }
    angle = fix32ReduceAngle0To2Pi(angle - 0x648);
    Camera_SetTarget((struct Camera*)camera, center.x, 0x800, center.z);
    Camera_SetOrbit(camera, angle, 0x1000, distance);
    int var16 = 0;
    camera->mode = 14;
    camera->active = 1;
    Struct_ov000_0216d368 sum;
    func_ov000_0216d368(&sum, 0, 0, 0);
    for (int i = 0; i < 8; i++) {
        Struct_ov000_0216e3c4* object = func_0200fea4(game, i + 0xc0);
        if (object && object->included) {
            Vector3i position;
            position = object->object.position_;
            Vector3fix_Add(&position, (Vector3i*)&sum, (Vector3i*)&sum);
            var16++;
        }
    }
    if (var16) {
        int scale = fix32_Divide(0x1000, var16 << 12);
        Vector3fixMultiplyScalar((Vector3i*)&sum, scale, (Vector3i*)&sum);
        Vector3i current;
        current = camera->target;
        int facing = func_020c3544(sum.z - current.z, sum.x - current.x);
        Camera_SetOrbitYaw((GlobalObj0202e6a8*)camera, -0x999 + ((facing / 0xffff) << 12));
    }
}
