#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"

struct Obj02033b68;
struct Bytes02033b88;
struct Struct_ov017_021d3fa8 {
    unsigned char unknown_0_[4];
    unsigned char command;
    unsigned char unknown_5_;
    unsigned char mode : 4;
    unsigned char reset : 4;
    unsigned char index;
    int time;
};
struct Struct_ov017_021d3fa8_2 {
    Object3D object;
    unsigned char unknown_ac_[0xc1 - 0xac];
    unsigned char flags : 2;
    unsigned char reserved : 6;
};
struct Struct_ov017_021d6cfc { signed char members[4]; };
extern const Struct_ov017_021d6cfc data_ov017_021d6cfc, data_ov017_021d6d08;
extern const char data_ov017_021d82b1[], data_ov017_021d82bb[], data_ov017_021d82c6[];
extern "C" void func_020dc548(signed char, Struct_ov017_021d6cfc*, signed char*);
extern "C" void func_02039d48(unsigned char*);
extern "C" void GameObject_ResetTrail(unsigned char*);
extern "C" int LinkSession_IsGuest(void*);
extern "C" void func_ov017_021907dc(int, int, int, int, int);
extern "C" void GameObject_SetMotionState(Obj02033b68*, int);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);

// USA: func_ov017_021d3fa8
extern "C" ARM void func_ov017_021d3fa8(int unused, Struct_ov017_021d3fa8* packet, GameState* game, void* globals, void* search) {
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
        Struct_ov017_021d6cfc order = data_ov017_021d6cfc;
        signed char count = 0;
        func_020dc548((signed char)packet->index, &order, &count);
        for (int i = 0; i < count; i++) {
            if (order.members[i] == packet->index) continue;
            GameObject* other = game->GetPartyMemberByIndex(order.members[i]);
            if (other == 0) continue;
            unsigned int flags = ((Struct_ov017_021d3fa8_2*)other)->flags;
            if (!(flags & 2)) {
                other->obj3D_.position_ = member->obj3D_.position_;
                other->obj3D_.SetInheritedAlpha(31);
                func_02039d48((unsigned char*)other);
            }
            GameObject_ResetTrail((unsigned char*)other);
        }
        if (LinkSession_IsGuest(search)) func_ov017_021907dc((int)globals, 0, 1, 1, 1);
    }
    if (member == 0) return;
    unsigned int member_id = member->obj3D_.GetField06();
    if (member_id != protagonist->obj3D_.GetField06()) return;
    if (reset != 0 || (((Struct_ov017_021d3fa8_2*)member)->flags & 2)) {
        LadderClimb_Reset(state);
        if (reset != 0) {
            Struct_ov017_021d6cfc order = data_ov017_021d6d08;
            signed char count = 0;
            func_020dc548((signed char)packet->index, &order, &count);
            for (int i = 0; i < count; i++) {
                if (order.members[i] == packet->index) continue;
                GameObject* other = game->GetPartyMemberByIndex(order.members[i]);
                if (other == 0) continue;
                unsigned int flags = ((Struct_ov017_021d3fa8_2*)other)->flags;
                if (!(flags & 2)) {
                    other->obj3D_.position_ = member->obj3D_.position_;
                    other->obj3D_.SetInheritedAlpha(31);
                    GameObject_SetMotionState((Obj02033b68*)other, 0);
                    func_02039d48((unsigned char*)other);
                }
                GameObject_ResetTrail((unsigned char*)other);
            }
            if (LinkSession_IsGuest(search)) func_ov017_021907dc((int)globals, 0, 1, 1, 1);
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
