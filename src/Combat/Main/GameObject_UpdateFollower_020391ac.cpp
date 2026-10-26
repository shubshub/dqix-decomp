#include <globaldefs.h>
#include <GameState/GameState.h>
#include <NitroSDK/Matrix.h>
#include "Resource/GameResources.h"

struct Obj02033b68;
struct Obj02033834;
struct Obj02033874;
struct Foo02033b58;
struct Struct_020391ac { unsigned int bits; };
struct Struct_020391ac_2 { int x, z; };
struct FollowingActor {
    Object3D object;
    short unknown_ac_;
    unsigned char unknown_ae_[6];
    unsigned short animation;
    unsigned char unknown_b6_[8];
    unsigned char state;
    unsigned char unknown_bf_;
    unsigned char unknown_c0_;
    unsigned char unknown_c1_[0x6f];
    Struct_020391ac* flags;
#if defined(jpn)
    unsigned char unknown_134_[0x88];
#else
    unsigned char unknown1_134_[0x94];
#endif
    signed char partyIndex;
    unsigned char unknown_1c9_;
    signed char targetIndex;
    signed char unknown_1cb_;
    signed char unknown_1cc_;
    unsigned char queued;
    unsigned char followFlags;
    unsigned char unknown_1cf_;
    Struct_020391ac_2 unknown_1d0_[16];
    unsigned char unknown_250_[0x18];
    int fade;
    unsigned char unknown_26c_;
    unsigned char unknown_26d_;
};

extern "C" void func_ov017_021917f0(int, int);
extern "C" void GameObject_SetMotionState(Obj02033b68*, int);
int fix32ReduceAngle0To2Pi(int);
extern "C" void GameObject_SetFacing(Obj02033834*, int);
extern "C" void GameObject_ResetTrail(unsigned char*);
extern "C" void GameObject_StoreMotionState(Foo02033b58*, unsigned char);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);

// Main, originally func_020391ac (USA 0x020391ac, EUR 0x020391bc, JPN 0x02038c04)
extern "C" ARM void GameObject_UpdateFollower(FollowingActor* actor) {
    GameState* game;
    FollowingActor* leader;
    FollowingActor* target;
    int var3;
    int var4;
    int var5;
    int spacing;
    int var7;
    int threshold;
    int var9;
    int angle;
    int previousIndex;
    void** resource;
    if (actor->followFlags & 1)
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
    if (target->unknown_26c_) {
        if (target->unknown_26d_ == 0 || target->unknown_26d_ == 1 || target->unknown_26d_ == 2) {
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
        } else if (target->unknown_26d_ == 3 || target->unknown_26d_ == 4 || target->unknown_26d_ == 5) {
            actor->fade = 0;
            actor->object.position_ = target->object.position_;
            actor->object.SetInheritedAlpha(31);
            GameObject_ResetTrail((unsigned char*)actor);
            GameObject_SetMotionState((Obj02033b68*)actor, 0);
            actor->followFlags |= 4;
        }
        return;
    }
    actor->fade = 0;
    Vector3fix leaderPosition = leader->object.position_;
    leaderPosition.y = 0;
    Vector3fix actorPosition = actor->object.position_;
    actorPosition.y = 0;
    var4 = Vector3fix_Distance(&actorPosition, &leaderPosition);
    if (actor->queued == 0) {
        switch (leader->unknown_c0_) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            actor->queued = 1;
            actor->unknown_1d0_[actor->unknown_1cb_].x = leaderPosition.x;
            actor->unknown_1d0_[actor->unknown_1cb_].z = leaderPosition.z;
            break;
        }
    }
    if (actor->queued == 0) {
        GameObject_StoreMotionState((Foo02033b58*)actor, 0);
        return;
    }
    var3 = actor->unknown_ac_ != 0;
    Vector3fix previous = {0, 0, 0};
    previousIndex = actor->unknown_1cb_;
    previous.x = actor->unknown_1d0_[previousIndex].x;
    previous.z = actor->unknown_1d0_[previousIndex].z;
    var5 = Vector3fix_Distance(&leaderPosition, &previous);
    spacing = 0x800;
    if ((actor->flags->bits & 1) && (leader->flags->bits & 1)) {
        int pending = actor->unknown_1cb_ - actor->unknown_1cc_;
        if (pending < 0)
            pending = 16 - actor->unknown_1cc_ + actor->unknown_1cb_;
        if (pending <= 2)
            spacing = 0xe66;
    }
    if (var5 > spacing) {
        ++actor->unknown_1cb_;
        actor->unknown_1cb_ %= 16;
        actor->unknown_1d0_[actor->unknown_1cb_].x = leaderPosition.x;
        actor->unknown_1d0_[actor->unknown_1cb_].z = leaderPosition.z;
    }
    if (actor->unknown_1cb_ < 0)
        return;
    var7 = actor->unknown_1cb_ - actor->unknown_1cc_;
    if (var7 < 0)
        var7 = 16 - actor->unknown_1cc_ + actor->unknown_1cb_;
    if (var7 > 2)
        actor->animation = 0x24d;
    else if (var7 <= 1)
        actor->animation = 0x9d;
    else
        actor->animation = 0x189;
    threshold = spacing + 0xb33;
    var9 = 1;
    if (!FieldTaskQueue_IsEmpty(resource))
        var9 = 0;
    if (var7 >= 1 || (var4 > threshold && var9) || var3) {
        Vector3fix origin = actor->object.position_;
        origin.y = 0;
        Vector3fix destination = {0, 0, 0};
        destination.x = actor->unknown_1d0_[actor->unknown_1cc_].x;
        destination.z = actor->unknown_1d0_[actor->unknown_1cc_].z;
        Vector3fix direction;
        Vector3fix_Subtract(&destination, &origin, &direction);
        int distance = Vector3fix_Length(&direction);
        Vector3fix_Normalize(&direction, &direction);
        angle = fix32ReduceAngle0To2Pi(fix32_Atan2(direction.x, direction.z));
        if (var3)
            GameObject_SnapFacing((Obj02033874*)actor, leader->object.rotation_.y);
        else
            GameObject_SetFacing((Obj02033834*)actor, angle);
        if (distance <= 0x800 && actor->unknown_1cc_ != actor->unknown_1cb_) {
            ++actor->unknown_1cc_;
            actor->unknown_1cc_ %= 16;
        }
        if (var3)
            GameObject_SetMotionState((Obj02033b68*)actor, 0);
        else if (actor->state != 1)
            GameObject_SetMotionState((Obj02033b68*)actor, 1);
    } else if (actor->state != 0)
        GameObject_SetMotionState((Obj02033b68*)actor, 0);
}
