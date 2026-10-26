#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

extern "C" struct Vec3 func_020341e0(void* obj);
extern "C" struct Vec3 func_02034104(void* obj);

struct Obj02033834;
extern "C" void GameObject_SetFacing(struct Obj02033834* obj, int arg);

struct Obj02033b68;
extern "C" void GameObject_SetMotionState(struct Obj02033b68* obj, int newVal);

struct U16Field0x6_020375f8;

struct Struct_020776a0 {
    char pad0[0x44];
    struct Vec3 unknown_44_;
    char unknown_50_[0xb0 - 0x50];
    unsigned short unknown_b0_;
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[0x166 - 0xb6];
    unsigned short f166;
    char unknown_168_[0x17a - 0x168];
    unsigned char unknown_17a_;
    char unknown_17b_[0x17d - 0x17b];
    unsigned char unknown_17d_;
};

// USA: func_020776a0
extern "C" ARM int func_020776a0(struct Struct_020776a0* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->f166);
    if (combatant == 0) {
        return 0;
    }

    self->unknown_17d_ |= 0x40;
#if defined(jpn)
    struct Vec3 var2 = func_02034104(combatant);
#else
    struct Vec3 var2 = func_020341e0(combatant);
#endif
    struct Vec3 delta;
    Vector3fix_Subtract((const Vector3fix*)&var2, (const Vector3fix*)&self->unknown_44_, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    GameObject_SetFacing((struct Obj02033834*)self, angle);

    self->unknown_b0_ = 0x97;
    self->unknown_b4_ = 0x1c2;
    self->unknown_b2_ = 0x1c2;
    GameObject_SetMotionState((struct Obj02033b68*)self, 1);

    GameObject* protagonist = battleStruct->GetProtagonist();
    unsigned short a = ((Object3D*)((struct U16Field0x6_020375f8*)protagonist))->GetField06();
    unsigned short b = ((Object3D*)((struct U16Field0x6_020375f8*)self))->GetField06();
    if (a == b) {
        ((Object3D*)((unsigned char*)self))->DisableFlag(0x80);
    }
    self->unknown_17a_ = 0;
    return 1;
}
