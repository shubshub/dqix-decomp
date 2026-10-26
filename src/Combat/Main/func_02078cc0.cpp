#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov009_0218aa28 { int unknown_0_; int unknown_4_; int unknown_8_; };

extern "C" struct Struct_ov009_0218aa28 func_02034104(GameObject* arg0);
extern "C" int fix32_Atan2(int arg0, int arg1);

struct Obj02033834;
void GameObject_SetFacing(struct Obj02033834* obj, int arg);

struct Foo02033b58;
void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);

struct ShortPair0xba0xbc;
void GameObject_Shake(ShortPair0xba0xbc* obj, short a, unsigned short b);

struct Struct_02078cc0 {
    char unknown_0_[0x44];
    struct Struct_ov009_0218aa28 unknown_44_;
    char unknown_50_[0xb0 - 0x50];
    unsigned short unknown_b0_;
    unsigned short unknown_b2_;
    char unknown_b4_[0x166 - 0xb4];
    unsigned short unknown_166_;
    char unknown_168_[0x17a - 0x168];
    unsigned char unknown_17a_;
};

// USA: func_02078cc0
extern "C" ARM int func_02078cc0(struct Struct_02078cc0* arg0) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = var0->GetPartyMemberByIndex(arg0->unknown_166_);
    if (var1 == 0) {
        return 0;
    }
    GameObject_StoreMotionState((struct Foo02033b58*)self, 0);
    self->fb0 = 0x328;
    self->fb2 = 0;
    struct Vec3 posCopy = func_02034104(combatant);
    struct Vec3 delta;
    Vector3fix_Subtract((const Vector3fix*)&posCopy, (const Vector3fix*)&self->f44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    GameObject_SetFacing((struct Obj02033834*)self, angle);
    ((Object3D*)((unsigned char*)self))->EnableFlag(0x80);
    GameObject_Shake((struct ShortPair0xba0xbc*)self, 0xcc, 0xaf0);
    self->f17a = 0;
    return 1;
}
