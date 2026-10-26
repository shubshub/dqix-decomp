#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"

struct Struct_02033b68;
struct Struct_02010604;
struct Struct_ov017_021d3fa8 {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_0_ : 4;
    unsigned char unknown_6_4_ : 4;
    unsigned char unknown_7_;
    int unknown_8_;
};
struct Struct_ov017_021d3fa8_2 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[0xc1 - 0xac];
    unsigned char unknown_c1_0_ : 2;
    unsigned char unknown_c1_2_ : 6;
};
struct Struct_ov017_021d6cfc { signed char unknown_0_[4]; };
extern const Struct_ov017_021d6cfc data_ov017_021d6cfc, data_ov017_021d6d08;
extern const char data_ov017_021d82b1[], data_ov017_021d82bb[], data_ov017_021d82c6[];
extern "C" void func_020dc548(signed char, PartyOrder021d3fa8*, signed char*);
void SetFlag0x1ceBit0x4_02039d48(unsigned char*);
void GameObject_ResetTrail(unsigned char*);
extern "C" int LinkSession_IsGuest(void*);
void CallHelperWithBuf_021907dc(int, int, int, int, int);
void GameObject_SetMotionState(Obj02033b68*, int);
void GameObject_ForceMotionState(Bytes02033b88*, int);

// USA: func_ov017_021d3fa8
extern "C" ARM void func_ov017_021d3fa8(int unused, AnimationPacket021d3fa8* packet, GameState* game, void* globals, void* search) {
    GameObject* protagonist = game->GetLeader();
    GameObject* member = game->GetPartyMemberByIndex(packet->index);
    SubBlock02038508* state = GameObject_GetLadderClimb(member);
    unsigned short mode = packet->mode;
    int reset = packet->reset;
    int command = packet->command;
    int time = packet->time;
    if (member != 0 && reset != 0) {
        member->obj3D_.DisableFlag(0x1010);
        LadderClimb_Reset(state);
        PartyOrder021d3fa8 order = data_ov017_021d6cfc;
        signed char count = 0;
        func_020dc548((signed char)packet->index, &order, &count);
        for (int i = 0; i < count; i++) {
            if (order.members[i] == packet->index) continue;
            GameObject* other = game->GetPartyMemberByIndex(order.members[i]);
            if (other == 0) continue;
            unsigned int flags = ((MemberState021d3fa8*)other)->flags;
            if (!(flags & 2)) {
                other->obj3D_.position_ = member->obj3D_.position_;
                other->obj3D_.SetInheritedAlpha(31);
                SetFlag0x1ceBit0x4_02039d48((unsigned char*)other);
            }
            GameObject_ResetTrail((unsigned char*)other);
        }
        if (LinkSession_IsGuest(search)) CallHelperWithBuf_021907dc((int)globals, 0, 1, 1, 1);
    }
    if (member == 0) return;
    unsigned int member_id = member->obj3D_.GetField06();
    if (member_id != protagonist->obj3D_.GetField06()) return;
    if (reset != 0 || (((MemberState021d3fa8*)member)->flags & 2)) {
        LadderClimb_Reset(state);
        if (reset != 0) {
            PartyOrder021d3fa8 order = data_ov017_021d6d08;
            signed char count = 0;
            func_020dc548((signed char)packet->index, &order, &count);
            for (int i = 0; i < count; i++) {
                if (order.members[i] == packet->index) continue;
                GameObject* other = game->GetPartyMemberByIndex(order.members[i]);
                if (other == 0) continue;
                unsigned int flags = ((MemberState021d3fa8*)other)->flags;
                if (!(flags & 2)) {
                    other->obj3D_.position_ = member->obj3D_.position_;
                    other->obj3D_.SetInheritedAlpha(31);
                    GameObject_SetMotionState((Obj02033b68*)other, 0);
                    SetFlag0x1ceBit0x4_02039d48((unsigned char*)other);
                }
                GameObject_ResetTrail((unsigned char*)other);
            }
            if (LinkSession_IsGuest(search)) CallHelperWithBuf_021907dc((int)globals, 0, 1, 1, 1);
        }
    } else if (command == 0) {
        member->obj3D_.DisableFlag(0x1000);
        member->obj3D_.EnableFlag(0x10);
        member->obj3D_.SetAnimationByName(data_ov017_021d82b1, 1);
        state->active = 1;
        state->command = 0;
    } else if (command == 1) {
        member->obj3D_.SetAnimationByName(data_ov017_021d82b1, 1);
        state->active = 1;
        state->command = 1;
    } else if (command == 5) {
        member->obj3D_.DisableFlag(0x1010);
        GameObject_ForceMotionState((Bytes02033b88*)member, 1);
        state->active = 1;
        state->command = 5;
    } else if (command == 4) {
        member->obj3D_.DisableFlag(0x1010);
        member->obj3D_.SetAnimationByName(data_ov017_021d82bb, 1);
        state->active = 1;
        state->command = 4;
    } else if (command == 2) {
        if (mode == 1) {
            member->obj3D_.DisableFlag(0x1000);
            member->obj3D_.EnableFlag(0x10);
            member->obj3D_.SetAnimationByName(data_ov017_021d82c6, 0);
            if (time) member->obj3D_.SetCurrentAnimationTime(time);
            state->active = 1;
        } else if (mode == 2) {
            member->obj3D_.DisableFlag(0x1000);
            member->obj3D_.EnableFlag(0x10);
            member->obj3D_.SetAnimationByName(data_ov017_021d82c6, 4);
            if (time) member->obj3D_.SetCurrentAnimationTime(time);
            state->active = 1;
        } else {
            member->obj3D_.EnableFlag(0x1010);
            member->obj3D_.SetAnimationByName(data_ov017_021d82c6, 0);
            if (time) member->obj3D_.SetCurrentAnimationTime(time);
            state->active = 1;
        }
    }
}
