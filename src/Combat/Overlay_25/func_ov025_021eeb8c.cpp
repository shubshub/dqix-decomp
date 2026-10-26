#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };
struct Struct_02028460_3 { int x; int y; int z; };
struct Struct_ov001_021592bc { int x; int y; int z; };
struct Struct_02059cfc_2;
struct Struct_02059cfc_3;

extern "C" void func_02059f38(struct Struct_02059cfc_2* dst, struct Struct_02059cfc_3* src);
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Struct_ov025_021eeb8c {
    char pad0[8];
    unsigned short combatantId;
    unsigned short remaining;
    struct Vec3 target;
};

struct Struct_ov025_021eeb8c_2 { char pad[0x44]; struct Vec3 pos; };

// USA: func_ov025_021eeb8c
extern "C" ARM int func_ov025_021eeb8c(struct Struct_ov025_021eeb8c* req) {
    GameState* battle = GameState::GetInstance();
    int elapsed = battle->GetEffectiveDeltaTime();
    GameObject* combatant = battle->GetGameObjectByIndex(req->combatantId);
    if (!combatant) return 1;
    if (req->remaining <= (unsigned int)elapsed) {
        func_02059f38((struct Struct_02059cfc_2*)combatant, (struct Struct_02059cfc_3*)&req->target);
        return 1;
    }
    struct Vec3 var3 = ((struct Struct_ov025_021eeb8c_2*)combatant)->pos;
    int dist = Vector3fix_Distance((const Vector3fix*)((struct Struct_02028460_3*)&var3), (const Vector3fix*)((struct Struct_02028460_3*)&req->target));
    float ratio = (float)(unsigned int)elapsed / (float)req->remaining;
    int step = (int)(((long long)dist * (int)(ratio * 4096.0f) + 0x800) >> 12);
    struct Vec3 diff;
    Vector3fix_Subtract((const Vector3fix*)&req->target, (const Vector3fix*)&var3, (Vector3fix*)&diff);
    int var8 = fix32_Divide((fix32_t)step, (fix32_t)dist);
    Vector3fixMultiplyScalar((Vector3i const*)&diff, var8, (Vector3i*)&diff);
    Vector3fix_Add((const Vector3fix*)&var3, (const Vector3fix*)&diff, (Vector3fix*)&var3);
    func_02059f38((struct Struct_02059cfc_2*)combatant, (struct Struct_02059cfc_3*)&var3);
    req->remaining -= elapsed;
    return 0;
}
