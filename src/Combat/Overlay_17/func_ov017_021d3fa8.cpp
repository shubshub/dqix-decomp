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
extern "C" void func_020dc548(signed char, Struct_ov017_021d6cfc*, signed char*);
extern "C" void func_02039d48(unsigned char*);
extern "C" void func_02039d24(unsigned char*);
extern "C" int func_0202c540(void*);
void CallHelperWithBuf_021907dc(int, int, int, int, int);
void GameObject_SetMotionState(Obj02033b68*, int);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);

// USA: func_ov017_021d3fa8
extern "C" ARM void func_ov017_021d3fa8(int arg0, Struct_ov017_021d3fa8* arg1, GameState* arg2, void* arg3, void* arg4) {
    GameObject* var0 = arg2->GetUnknownGameObject();
    GameObject* var1 = arg2->GetPartyMemberByIndex(arg1->unknown_7_);
    Struct_02037d10* var2 = func_020399a8(var1);
    unsigned short var3 = arg1->unknown_6_0_;
    int var4 = arg1->unknown_6_4_;
    int var5 = arg1->unknown_4_;
    int var6 = arg1->unknown_8_;
    if (var1 != 0 && var4 != 0) {
        var1->obj3D_.DisableFlag(0x1010);
        func_02038508(var2);
        Struct_ov017_021d6cfc var7 = data_ov017_021d6cfc;
        signed char var8 = 0;
        func_020dc548((signed char)arg1->unknown_7_, &var7, &var8);
        for (int var9 = 0; var9 < var8; var9++) {
            if (var7.unknown_0_[var9] == arg1->unknown_7_) continue;
            GameObject* var10 = arg2->GetPartyMemberByIndex(var7.unknown_0_[var9]);
            if (var10 == 0) continue;
            unsigned int var11 = ((Struct_ov017_021d3fa8_2*)var10)->unknown_c1_0_;
            if (!(var11 & 2)) {
                var10->obj3D_.position_ = var1->obj3D_.position_;
                var10->obj3D_.SetInheritedAlpha(31);
                func_02039d48((unsigned char*)var10);
            }
            func_02039d24((unsigned char*)var10);
        }
        if (func_0202c540(arg4)) func_ov017_021907dc((int)arg3, 0, 1, 1, 1);
    }
    if (member == 0) return;
    unsigned int member_id = member->obj3D_.GetField06();
    if (member_id != protagonist->obj3D_.GetField06()) return;
    if (reset != 0 || (((MemberState021d3fa8*)member)->flags & 2)) {
        InitBlock02038508(state);
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
                func_02039d24((unsigned char*)var16);
            }
            if (func_0202c540(arg4)) func_ov017_021907dc((int)arg3, 0, 1, 1, 1);
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
        SetByte0xbeShiftPrev((Bytes02033b88*)member, 1);
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
