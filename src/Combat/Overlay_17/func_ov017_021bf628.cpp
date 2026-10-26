#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a27b8(unsigned char* obj);
struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);
extern "C" void GameObject_StartGlide(void* obj, int* src, short val);
struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

struct Struct_ov017_021bf628 {
    char pad0[8];
    int x, y, z;
    char pad1[0xc];
    short angle;
};

struct Struct_ov017_021bf628_2 { int x, y, z; };
struct Struct_ov017_021bf628_3 { char pad[0x44]; struct Struct_ov017_021bf628_2 vec44; };

struct Struct_ov017_021bf628_4 {
    char pad0[0xc];
    struct Struct_ov017_021bf628* pos;
    char pad1[0x14 - 0x10];
    unsigned short field14;
    char pad2[0x28 - 0x16];
    int unknown_28_, unknown_2c_, x30;
};

// USA: func_ov017_021bf628
extern "C" ARM int func_ov017_021bf628(struct Struct_ov017_021bf628_4* obj) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetLeader();
    struct Struct_ov017_021bf628* pos = obj->pos;
    obj->unknown_28_ = pos->x;
    obj->unknown_2c_ = pos->y;
    obj->x30 = pos->z;
    GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
    void* var3 = GetGameResources();
    int flagResult = GameState_GetFollowCamera((char*)battle);
    if (flagResult != 0) {
        func_020a27b8((unsigned char*)flagResult);
    }
    if (var3 != 0) {
        SetFlags04((GameResources*)var3, 0x80);
    }
    GameObject_SetFacing((struct Obj02033834*)combatant, fix32ReduceAngle0To2Pi(pos->angle));
    struct Struct_ov017_021bf628_2 vec = ((struct Struct_ov017_021bf628_3*)combatant)->vec44;
    int* vecPtr = (int*)&vec;
    vec.x = pos->x;
    vec.z = pos->z;
    GameObject_StartGlide(combatant, vecPtr, 0xcc);
    GameObject_SetMotionState((struct Obj02033b68*)combatant, 1);
    obj->field14 = 5;
    return 1;
}
