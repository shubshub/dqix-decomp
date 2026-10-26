#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
int GameState_GetFollowCamera(char* obj);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
struct Obj02033834;
void GameObject_SetFacing(struct Obj02033834* obj, int arg);
void GameObject_StartGlide(void* obj, int* src, short val);
struct Obj02033b68;
void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

struct PosData_021bf628 {
    char pad0[8];
    int x, y, z;
    char pad1[0xc];
    short angle;
};

struct Vec3i_021bf628 { int x, y, z; };
struct CombatantPos_021bf628 { char pad[0x44]; struct Vec3i_021bf628 vec44; };

struct Obj_021bf628 {
    char pad0[0xc];
    struct PosData_021bf628* pos;
    char pad1[0x14 - 0x10];
    unsigned short field14;
    char pad2[0x28 - 0x16];
    int x28, x2c, x30;
};

// USA: func_ov017_021bf628  (semantic: RepositionCombatantFromPosData_021bf628)
extern "C" ARM int func_ov017_021bf628(struct Obj_021bf628* obj) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetLeader();
    struct PosData_021bf628* pos = obj->pos;
    obj->x28 = pos->x;
    obj->x2c = pos->y;
    obj->x30 = pos->z;
    GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
    void* flagPtr = GetGameResources();
    int flagResult = GameState_GetFollowCamera((char*)battle);
    if (flagResult != 0) {
        ClearIntAt0x23c_020a27b8((unsigned char*)flagResult);
    }
    if (flagPtr != 0) {
        SetFlags04((GameResources*)flagPtr, 0x80);
    }
    GameObject_SetFacing((struct Obj02033834*)combatant, fix32ReduceAngle0To2Pi(pos->angle));
    struct Vec3i_021bf628 vec = ((struct CombatantPos_021bf628*)combatant)->vec44;
    int* vecPtr = (int*)&vec;
    vec.x = pos->x;
    vec.z = pos->z;
    GameObject_StartGlide(combatant, vecPtr, 0xcc);
    GameObject_SetMotionState((struct Obj02033b68*)combatant, 1);
    obj->field14 = 5;
    return 1;
}
