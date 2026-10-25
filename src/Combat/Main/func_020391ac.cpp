#include <globaldefs.h>
#include <GameState/GameState.h>
#include <NitroSDK/Matrix.h>
#include "Resource/GameResources.h"

struct Struct_02033b68;
struct Struct_02033834_2;
struct Struct_02033834;
struct Struct_02033b58;
struct Struct_020391ac { unsigned int unknown_0_; };
struct Struct_020391ac_2 { int unknown_0_, unknown_4_; };
struct Struct_020391ac_3 {
    Object3D unknown_0_;
    short unknown_ac_;
    unsigned char unknown_ae_[6];
    unsigned short unknown_b4_;
    unsigned char unknown_b6_[8];
    unsigned char unknown_be_;
    unsigned char unknown_bf_;
    unsigned char unknown_c0_;
    unsigned char unknown_c1_[0x6f];
    Struct_020391ac* unknown_130_;
#if defined(jpn)
    unsigned char unknown_134_[0x88];
#else
    unsigned char unknown1_134_[0x94];
#endif
    signed char unknown_1c8_;
    unsigned char unknown_1c9_;
    signed char unknown_1ca_;
    signed char unknown_1cb_;
    signed char unknown_1cc_;
    unsigned char unknown_1cd_;
    unsigned char unknown_1ce_;
    unsigned char unknown_1cf_;
    Struct_020391ac_2 unknown_1d0_[16];
    unsigned char unknown_250_[0x18];
    int unknown_268_;
    unsigned char unknown_26c_;
    unsigned char unknown_26d_;
};

extern "C" void func_ov017_021917f0(int, int);
void GameObject_SetMotionState(Obj02033b68*, int);
int fix32ReduceAngle0To2Pi(int);
void GameObject_SetFacing(Obj02033834*, int);
void ClearBytesAndZeroBlock02039d24(unsigned char*);
void SetByteSavingPrevious(Foo02033b58*, unsigned char);
int IsField0Null_02046b08(void**);
void SetVecYFromValue02033874(Obj02033874*, int);

// USA: func_020391ac
extern "C" ARM void func_020391ac(Struct_020391ac_3* arg0) {
    GameState* var0;
    Struct_020391ac_3* var1;
    Struct_020391ac_3* var2;
    int var3;
    int var4;
    int var5;
    int var6;
    int var7;
    int var8;
    int var9;
    int var10;
    int var11;
    void** var12;
    if (arg0->unknown_1ce_ & 1)
        return;
    resource = (void**)GetGameResources()->fieldTaskQueue_;
    game = GameState::GetInstance();
    leader = (FollowingActor*)game->GetPartyMemberByIndex(actor->partyIndex);
    target = (FollowingActor*)game->GetPartyMemberByIndex(actor->targetIndex);
    if (leader == 0 || target == 0)
        return;
    if (leader->state == 2) {
        if (actor->state != 2) {
            func_ov017_021917f0(actor->object.actorIndex_, 1);
        }
        GameObject_SetMotionState((Obj02033b68*)actor, 2);
        return;
    }
    if (actor->state == 2) {
        func_ov017_021917f0(actor->object.actorIndex_, 0);
        GameObject_SetMotionState((Obj02033b68*)actor, 0);
    }
    if (target->followerEnabled) {
        if (target->targetMode == 0 || target->targetMode == 1 || target->targetMode == 2) {
            Vector3fix origin = actor->object.position_;
            origin.y = 0;
            Vector3fix destination = target->object.position_;
            destination.y = 0;
            Vector3fix direction;
            Vector3fix_Subtract(&destination, &origin, &direction);
            int distance = Vector3fix_Length(&direction);
            Vector3fix_Normalize(&direction, &direction);
            GameObject_SetFacing((Obj02033834*)actor, fix32ReduceAngle0To2Pi(fix32_Atan2(direction.x, direction.z)));
            if (distance < 0x1000)
                GameObject_SetMotionState((Obj02033b68*)actor, 0);
            else {
                actor->animation = 0x189;
                GameObject_SetMotionState((Obj02033b68*)actor, 1);
            }
            actor->object.SetInheritedAlpha(31 - actor->fade);
            actor->followFlags &= ~4;
            actor->fade += (int)(1.5f * game->GetTickCount());
            if (actor->fade > 31)
                actor->fade = 31;
        } else if (target->targetMode == 3 || target->targetMode == 4 || target->targetMode == 5) {
            actor->fade = 0;
            actor->object.position_ = target->object.position_;
            actor->object.SetInheritedAlpha(31);
            ClearBytesAndZeroBlock02039d24((unsigned char*)actor);
            GameObject_SetMotionState((Obj02033b68*)actor, 0);
            actor->followFlags |= 4;
        }
        return;
    }
    arg0->unknown_268_ = 0;
    Vector3fix var17 = var1->unknown_0_.position_;
    var17.y = 0;
    Vector3fix var18 = arg0->unknown_0_.position_;
    var18.y = 0;
    var4 = Vector3fix_Distance(&var18, &var17);
    if (arg0->unknown_1cd_ == 0) {
        switch (var1->unknown_c0_) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            arg0->unknown_1cd_ = 1;
            arg0->unknown_1d0_[arg0->unknown_1cb_].unknown_0_ = var17.x;
            arg0->unknown_1d0_[arg0->unknown_1cb_].unknown_4_ = var17.z;
            break;
        }
    }
    if (arg0->unknown_1cd_ == 0) {
        func_02033b58((Struct_02033b58*)arg0, 0);
        return;
    }
    var3 = arg0->unknown_ac_ != 0;
    Vector3fix var19 = {0, 0, 0};
    var11 = arg0->unknown_1cb_;
    var19.x = arg0->unknown_1d0_[var11].unknown_0_;
    var19.z = arg0->unknown_1d0_[var11].unknown_4_;
    var5 = Vector3fix_Distance(&var17, &var19);
    var6 = 0x800;
    if ((arg0->unknown_130_->unknown_0_ & 1) && (var1->unknown_130_->unknown_0_ & 1)) {
        int var20 = arg0->unknown_1cb_ - arg0->unknown_1cc_;
        if (var20 < 0)
            var20 = 16 - arg0->unknown_1cc_ + arg0->unknown_1cb_;
        if (var20 <= 2)
            var6 = 0xe66;
    }
    if (var5 > var6) {
        ++arg0->unknown_1cb_;
        arg0->unknown_1cb_ %= 16;
        arg0->unknown_1d0_[arg0->unknown_1cb_].unknown_0_ = var17.x;
        arg0->unknown_1d0_[arg0->unknown_1cb_].unknown_4_ = var17.z;
    }
    if (arg0->unknown_1cb_ < 0)
        return;
    var7 = arg0->unknown_1cb_ - arg0->unknown_1cc_;
    if (var7 < 0)
        var7 = 16 - arg0->unknown_1cc_ + arg0->unknown_1cb_;
    if (var7 > 2)
        arg0->unknown_b4_ = 0x24d;
    else if (var7 <= 1)
        arg0->unknown_b4_ = 0x9d;
    else
        arg0->unknown_b4_ = 0x189;
    var8 = var6 + 0xb33;
    var9 = 1;
    if (!func_02046b08(var12))
        var9 = 0;
    if (var7 >= 1 || (var4 > var8 && var9) || var3) {
        Vector3fix var21 = arg0->unknown_0_.position_;
        var21.y = 0;
        Vector3fix var22 = {0, 0, 0};
        var22.x = arg0->unknown_1d0_[arg0->unknown_1cc_].unknown_0_;
        var22.z = arg0->unknown_1d0_[arg0->unknown_1cc_].unknown_4_;
        Vector3fix var23;
        Vector3fix_Subtract(&var22, &var21, &var23);
        int var24 = Vector3fix_Length(&var23);
        Vector3fix_Normalize(&var23, &var23);
        var10 = fix32ReduceAngle0To2Pi(fix32_Atan2(var23.x, var23.z));
        if (var3)
            func_02033874((Struct_02033834*)arg0, var1->unknown_0_.rotation_.y);
        else
            GameObject_SetFacing((Obj02033834*)actor, angle);
        if (distance <= 0x800 && actor->readIndex != actor->writeIndex) {
            ++actor->readIndex;
            actor->readIndex %= 16;
        }
        if (moving)
            GameObject_SetMotionState((Obj02033b68*)actor, 0);
        else if (actor->state != 1)
            GameObject_SetMotionState((Obj02033b68*)actor, 1);
    } else if (actor->state != 0)
        GameObject_SetMotionState((Obj02033b68*)actor, 0);
}
