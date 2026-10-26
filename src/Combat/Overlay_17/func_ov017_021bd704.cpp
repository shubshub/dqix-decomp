#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02039d84;
struct Obj02033874;
struct Struct_ov017_021bd704 {
    unsigned char unknown_0_[5];
    unsigned char enabled;
    unsigned char unknown_6_[4];
    unsigned short id;
    unsigned char unknown_c_[0x44 - 0xc];
    unsigned short flags;
    unsigned short unknown_46_;
    Vector3fix position;
    short angle;
};
struct PartyList021bd704 {
    unsigned char unknown_0_[0xf78];
    unsigned char members[4];
    unsigned char count;
};
extern "C" void* LinkSession_GetInstance();
extern "C" unsigned char GameState_GetLeaderIndex(GameState*);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_02039d48(unsigned char*);
int fix32sin(int);
int fix32cos(int);
extern "C" unsigned char GameObject_IsClimbingLadder(char*);
extern "C" void func_02039d84(Struct_02039d84*);
extern "C" void func_ov017_021d440c(int);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void GameObject_ResetTrail(unsigned char*);
extern "C" void func_ov017_021c3e18(int);

// USA: func_ov017_021bd704
extern "C" ARM void func_ov017_021bd704(Struct_ov017_021bd704* self) {
    GameState* game = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    int anchor = (self->flags & 0x40) != 0;
    int var3 = (self->flags & 0x1000) != 0 && self->enabled != 0;
    if (self->enabled == 0 && !anchor && !var3) return;
    Vector3fix position = self->position;
    int angle = self->angle;
    if (self->enabled == 0 && anchor) {
        position = game->GetLeader()->obj3D_.position_;
        angle = game->GetLeader()->obj3D_.rotation_.y;
    }
    PartyList021bd704* party = (PartyList021bd704*)GameState_GetParty(game);
    if (party != 0) {
        for (int i = 0; i < party->count; i++) {
            int id = party->members[i];
            GameObject* member = game->GetPartyMemberByIndex(id);
            if (member == 0) continue;
            if (LinkSession_IsHostOrSolo(search)) {
                int member_id = member->obj3D_.actorIndex_;
                if (member_id != GameState_GetLeaderIndex(game) && anchor) {
                    member->obj3D_.SetInheritedAlpha(0);
                    func_02039d48((unsigned char*)member);
                }
            } else if (self->enabled && !var3) {
                if (id == 1) {
                    int x = FIX32_MULTIPLY(fix32sin(angle), 0x800);
                    int z = FIX32_MULTIPLY(fix32cos(angle), -0x1333);
                    position.z += z - x;
                    x = FIX32_MULTIPLY(fix32cos(angle), 0x800);
                    z = FIX32_MULTIPLY(fix32sin(angle), -0x1333);
                    position.x += z + x;
                } else if (id == 2) {
                    int x = FIX32_MULTIPLY(fix32sin(angle), -0x800);
                    int z = FIX32_MULTIPLY(fix32cos(angle), -0x1800);
                    position.z += z - x;
                    x = FIX32_MULTIPLY(fix32cos(angle), -0x800);
                    z = FIX32_MULTIPLY(fix32sin(angle), -0x1800);
                    position.x += z + x;
                } else if (id == 3) {
                    int z = FIX32_MULTIPLY(fix32cos(angle), -0x1ccc);
                    position.z += z;
                    int x = FIX32_MULTIPLY(fix32sin(angle), -0x1ccc);
                    position.x += x;
                }
            }
            if (self->id != 8100 && GameObject_IsClimbingLadder((char*)member)) {
                func_02039d84((Struct_02039d84*)member);
                func_ov017_021d440c(-1);
            }
            member->obj3D_.position_ = position;
            GameObject_SnapFacing((Obj02033874*)member, angle);
            member->obj3D_.EnableFlag(0x4000000);
            GameObject_ResetTrail((unsigned char*)member);
        }
    }
    if (LinkSession_IsHostOrSolo(search)) func_ov017_021c3e18(0);
}
