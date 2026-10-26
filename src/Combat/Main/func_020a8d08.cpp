#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct FlagWord020466f4;
struct Obj02033874;
struct Obj020397cc;

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" int func_02039860(void* obj);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void func_ov017_021d2ad0(short a, int b, int c, int d, unsigned char e);
extern "C" void func_ov017_021d2c34(unsigned char a, unsigned char b, unsigned char c);
extern "C" void* GlobalFlags_GetInstance();
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int value);
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

struct Struct_020a8d08 {
    Object3D obj;
    short height;
    short y;
    char unknown_b0_[0xc1 - 0xb0];
    unsigned char unknown_c1_;
};

struct Struct_020a8d08_2 {
    char pad0[4];
    unsigned char f4;
    unsigned char unknown_5_;
    char pad6[2];
    int offsetY;
    char unknown_c_[4];
    int offsetX;
    int offsetZ;
};

// USA: func_020a8d08
extern "C" ARM void func_020a8d08(struct Struct_020a8d08_2* obj, unsigned char index) {
    GameState* state = GameState::GetInstance();
    Struct_020a8d08* actor = (Struct_020a8d08*)state->GetPartyMemberByIndex(index);
    Object3D* other = &state->GetLeader()->obj3D_;
    GameState_GetParty(state);
    state->GetPartyMemberByIndex(func_02039860(actor));
    if ((obj->f4 & (1 << index)) == 0) {
        return;
    }
    if (obj->unknown_5_ & (1 << index)) {
        return;
    }
    Vector3i t;
    t = actor->obj.position_;
    t.x += obj->offsetX;
    t.z += obj->offsetZ;
    actor->obj.position_ = t;
    if (actor->height == 0) {
        actor->unknown_c1_ &= ~8;
        GameObject_EnableControl(actor);
        obj->unknown_5_ |= (1 << index);
        if (actor->obj.actorIndex_ != other->actorIndex_) {
            actor->obj.position_ = other->position_;
        }
        Vector3i v = actor->obj.position_;
        func_ov017_021d2ad0(index, v.x, v.y, v.z, 0);
        func_ov017_021d2c34(index, 0x1f, 0);
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x402);
    } else {
        GameObject_SnapFacing((struct Obj02033874*)actor, actor->y + obj->offsetY);
        if (actor->obj.actorIndex_ == other->actorIndex_) {
            obj->offsetY -= 40;
        }
        GameObject_DisableControl((struct Obj020397cc*)actor, 1);
    }
}
