#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/Zone3D.h"

struct Struct_ov017_02197e2c { Object3D unknown_0_; char unknown_ac_[0x12]; unsigned char unknown_be_; };
struct Struct_ov017_02197e2c_2 {
#if defined(jpn)
    char unknown_0_[0xf0];
#else
    char unknown1_0_[0x150];
#endif
    unsigned char unknown_150_0_ : 6;
    unsigned char unknown_150_6_ : 2;
};
struct InteractionRequest { unsigned char type; char pad1; short index; int field4; ZoneChestRenderRecord* point; int fieldc; short angle; short direction; };
struct S02046b1c;
struct Vec3;
extern "C" Zone3D* Zone3D_GetInstance();
void* MessageSystem_GetInstance();
bool CheckSubstructByte0x7cPositive_020535c8(signed char*);
void* GetField0x0List02046b1c(S02046b1c*);
ZoneChestRenderRecord* Zone3D_GetChest(unsigned char*, int);
int fix32abs(int);
extern "C" int fix32_CosFx64c(int);
extern "C" int fix32_SinFx64c(int);
extern "C" float _ll_sto_f(int);
int GetAbsAngleDeltaBetween_021a4754(Vector3fix*, int, Vector3fix*);
InteractionReset* TextQueue_GetInstance();
void InitObj0219a674(unsigned char*);
extern "C" void func_ov017_0219b33c(GameResources*, InteractionRequest*);

static inline int inline_ov017_02197e2c(int arg0, int arg1) { return (int)(((long long)arg0 * arg1 + 0x800) >> 12); }

// USA: func_ov017_02197e2c
extern "C" ARM void func_ov017_02197e2c(GameResources* resources) {
    GameState* game = GameState::GetInstance();
    Zone3D* zone = Zone3D_GetInstance();
    MessageSystem_GetInstance();
    game->GetCamera();
    InteractionPlayer* player = (InteractionPlayer*)game->GetUnknownGameObject();
    Vector3i* position = &player->obj.position_;
    if (CheckSubstructByte0x7cPositive_020535c8((signed char*)player)) return;
    if (!zone->numChests_) return;
    int direction = 0;
    int hasList = 0;
    void* list = GetField0x0List02046b1c((S02046b1c*)resources->fieldTaskQueue_);
    if (list) hasList = 1;
    int bestAngle = 0x3244;
    ZoneChestRenderRecord* candidate = 0;
    ZoneChestRenderRecord* selected = 0;
    int selectedIndex = -1;
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
        int squared = MultiplyFix(delta.x, delta.x) + MultiplyFix(delta.z, delta.z);
        if (squared > 0x1800) continue;
        Vector3i rotated = *position;
        rotated.y = 0;
        Vector3fix_Subtract(&rotated, &point, &rotated);
        int angle = -(candidate->angleY - 0x6487);
        int cosine = (int)(4096.0f * (_ll_sto_f(fix32_CosFx64c(angle)) / 4294967296.0f));
        int sine = (int)(4096.0f * (_ll_sto_f(fix32_SinFx64c(angle)) / 4294967296.0f));
        Matrix3x3 rotation;
        Mat3x3_WriteRotationY(&rotation, sine, cosine);
        Mat3x3_ApplyToVector(&rotated, &rotation, &rotated);
        int difference = GetAbsAngleDeltaBetween_021a4754(position, (short)player->obj.rotation_.y, &point);
        if (difference >= bestAngle) continue;
        bestAngle = difference;
        selectedIndex = i;
        selected = candidate;
        direction = fix32_Atan2(distance.x, distance.z);
    }
    if (hasList || selectedIndex < 0 || !candidate || !selected) return;
    if (player->mode != 0 && player->mode != 1) return;
    if ((selected->kind == 1 || selected->kind == 2) && selected->state != ZoneChestState_Closed) return;
    InteractionReset* reset = TextQueue_GetInstance();
    int enabled = selected->state == ZoneChestState_Closed ? 1 : 0;
    if (!enabled) return;
    if (reset->mode > 1) return;
    InteractionRequest request;
    InitObj0219a674((unsigned char*)&request);
    request.type = 2;
    request.angle = GetAbsAngleDeltaBetween_021a4754(&player->obj.position_, (short)player->obj.rotation_.y, &selected->position);
    request.point = selected;
    request.index = selectedIndex;
    request.direction = direction;
    if (request.angle >= 0xc91) return;
    func_ov017_0219b33c(resources, &request);
}
