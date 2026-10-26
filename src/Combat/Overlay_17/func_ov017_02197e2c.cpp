#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/Zone3D.h"

struct InteractionPlayer { Object3D obj; char unknown_ac_[0x12]; unsigned char mode; };
struct InteractionReset {
#if defined(jpn)
    char pad[0xf0];
#else
    char pad[0x150];
#endif
    unsigned char mode : 6;
    unsigned char flags : 2;
};
struct Struct_ov017_02197e2c_3 { unsigned char type; char pad1; short index; int field4; ZoneChestRenderRecord* point; int fieldc; short angle; short direction; };
struct S02046b1c;
struct Vec3;
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void* MessageSystem_GetInstance();
extern "C" bool GameObject_IsGesturing(signed char*);
extern "C" void* func_02046b1c(S02046b1c*);
extern "C" ZoneChestRenderRecord* Zone3D_GetChest(unsigned char*, int);
int fix32abs(int);
extern "C" int fix32_CosFx64c(int);
extern "C" int fix32_SinFx64c(int);
extern "C" float _ll_sto_f(int);
extern "C" int func_ov017_021a4754(Vector3fix*, int, Vector3fix*);
extern "C" InteractionReset* TextQueue_GetInstance();
extern "C" void func_ov017_0219a674(unsigned char*);
extern "C" void func_ov017_0219b33c(GameResources*, Struct_ov017_02197e2c_3*);

static inline int inline_ov017_02197e2c(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

// USA: func_ov017_02197e2c
extern "C" ARM void func_ov017_02197e2c(GameResources* resources) {
    GameState* game = GameState::GetInstance();
    Zone3D* zone = Zone3D_GetInstance();
    MessageSystem_GetInstance();
    game->GetCamera();
    InteractionPlayer* player = (InteractionPlayer*)game->GetLeader();
    Vector3i* position = &player->obj.position_;
    if (GameObject_IsGesturing((signed char*)player)) return;
    if (!zone->numChests_) return;
    int direction = 0;
    int var5 = 0;
    void* list = func_02046b1c((S02046b1c*)resources->fieldTaskQueue_);
    if (list) var5 = 1;
    int bestAngle = 0x3244;
    ZoneChestRenderRecord* candidate = 0;
    ZoneChestRenderRecord* selected = 0;
    int var10 = -1;
    for (int i = 0; i < zone->numChests_; i++) {
        candidate = Zone3D_GetChest((unsigned char*)zone, i);
        if (!candidate) continue;
        Vector3i distance;
        Vector3i delta = *position;
        Vector3i point = candidate->position;
        if (fix32abs(delta.y - point.y) > 0x1000) continue;
        delta.y = 0;
        point.y = 0;
        Vector3fix_Subtract(&delta, &point, &delta);
        distance = delta;
        int var15 = inline_ov017_02197e2c(delta.x, delta.x) + inline_ov017_02197e2c(delta.z, delta.z);
        if (var15 > 0x1800) continue;
        Vector3i var16 = *position;
        var16.y = 0;
        Vector3fix_Subtract(&var16, &point, &var16);
        int angle = -(candidate->angleY - 0x6487);
        int cosine = (int)(4096.0f * (_ll_sto_f(fix32_CosFx64c(angle)) / 4294967296.0f));
        int sine = (int)(4096.0f * (_ll_sto_f(fix32_SinFx64c(angle)) / 4294967296.0f));
        Matrix3x3 rotation;
        Mat3x3_WriteRotationY(&rotation, sine, cosine);
        Mat3x3_ApplyToVector(&var16, &rotation, &var16);
        int difference = func_ov017_021a4754(position, (short)player->obj.rotation_.y, &point);
        if (difference >= bestAngle) continue;
        bestAngle = difference;
        var10 = i;
        selected = candidate;
        direction = fix32_Atan2(distance.x, distance.z);
    }
    if (var5 || var10 < 0 || !candidate || !selected) return;
    if (player->mode != 0 && player->mode != 1) return;
    if ((selected->kind == 1 || selected->kind == 2) && selected->state != ZoneChestState_Closed) return;
    InteractionReset* reset = TextQueue_GetInstance();
    int enabled = selected->state == ZoneChestState_Closed ? 1 : 0;
    if (!enabled) return;
    if (reset->mode > 1) return;
    Struct_ov017_02197e2c_3 request;
    func_ov017_0219a674((unsigned char*)&request);
    request.type = 2;
    request.angle = func_ov017_021a4754(&player->obj.position_, (short)player->obj.rotation_.y, &selected->position);
    request.point = selected;
    request.index = var10;
    request.direction = direction;
    if (request.angle >= 0xc91) return;
    func_ov017_0219b33c(resources, &request);
}
