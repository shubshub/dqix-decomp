#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02038598_4;
struct Struct_02033834;
struct Struct_02018300_3;

void* GameState_GetParty(GameState* battleStruct);
int GetSignedByte0x1c8_02039860(void* obj);
void GameObject_EnableControl(void* obj);
void EnqueueEventTag35_021d2ad0(short a, int b, int c, int d, unsigned char e);
void EnqueueEventTag36_021d2c34(unsigned char a, unsigned char b, unsigned char c);
void* GlobalFlags_GetInstance();
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
void SetVecYFromValue02033874(struct Obj02033874* obj, int value);
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

struct Struct_020a8d08 {
    Object3D unknown_0_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_[0xc1 - 0xb0];
    unsigned char unknown_c1_;
};

struct Struct_020a8d08_2 {
    char unknown_0_[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    char unknown_6_[2];
    int unknown_8_;
    char unknown_c_[4];
    int unknown_10_;
    int unknown_14_;
};

// USA: func_020a8d08
extern "C" ARM void func_020a8d08(struct Obj020a8d08* obj, unsigned char index) {
    GameState* state = GameState::GetInstance();
    Combatant020a8d08* actor = (Combatant020a8d08*)state->GetPartyMemberByIndex(index);
    Object3D* other = &state->GetUnknownGameObject()->obj3D_;
    GameState_GetParty(state);
    state->GetPartyMemberByIndex(GetSignedByte0x1c8_02039860(actor));
    if ((obj->f4 & (1 << index)) == 0) {
        return;
    }
    if (arg0->unknown_5_ & (1 << arg1)) {
        return;
    }
    Vector3i t;
    t = actor->obj.position_;
    t.x += obj->offsetX;
    t.z += obj->offsetZ;
    actor->obj.position_ = t;
    if (actor->height == 0) {
        actor->f_c1 &= ~8;
        GameObject_EnableControl(actor);
        obj->f5 |= (1 << index);
        if (actor->obj.actorIndex_ != other->actorIndex_) {
            actor->obj.position_ = other->position_;
        }
        Vector3i v = actor->obj.position_;
        EnqueueEventTag35_021d2ad0(index, v.x, v.y, v.z, 0);
        EnqueueEventTag36_021d2c34(index, 0x1f, 0);
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x402);
    } else {
        SetVecYFromValue02033874((struct Obj02033874*)actor, actor->y + obj->offsetY);
        if (actor->obj.actorIndex_ == other->actorIndex_) {
            obj->offsetY -= 40;
        }
        GameObject_DisableControl((struct Obj020397cc*)actor, 1);
    }
}
