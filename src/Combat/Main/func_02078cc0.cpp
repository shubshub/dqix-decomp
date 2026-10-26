#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

extern "C" struct Vec3 func_02034104(GameObject* combatant);
extern "C" int fix32_Atan2(int x, int z);

struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);

struct Foo02033b58;
extern "C" void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);

struct ShortPair0xba0xbc;
extern "C" void GameObject_Shake(ShortPair0xba0xbc* obj, short a, unsigned short b);

struct Struct_02078cc0 {
    char pad0[0x44];
    struct Vec3 unknown_44_;
    char unknown_50_[0xb0 - 0x50];
    unsigned short unknown_b0_;
    unsigned short unknown_b2_;
    char unknown_b4_[0x166 - 0xb4];
    unsigned short f166;
    char unknown_168_[0x17a - 0x168];
    unsigned char unknown_17a_;
};

// USA: func_02078cc0
extern "C" ARM int func_02078cc0(struct Struct_02078cc0* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->f166);
    if (combatant == 0) {
        return 0;
    }
    GameObject_StoreMotionState((struct Foo02033b58*)self, 0);
    self->unknown_b0_ = 0x328;
    self->unknown_b2_ = 0;
    struct Vec3 var2 = func_02034104(combatant);
    struct Vec3 delta;
    Vector3fix_Subtract((const Vector3fix*)&var2, (const Vector3fix*)&self->unknown_44_, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    GameObject_SetFacing((struct Obj02033834*)self, angle);
    ((Object3D*)((unsigned char*)self))->EnableFlag(0x80);
    GameObject_Shake((struct ShortPair0xba0xbc*)self, 0xcc, 0xaf0);
    self->unknown_17a_ = 0;
    return 1;
}
