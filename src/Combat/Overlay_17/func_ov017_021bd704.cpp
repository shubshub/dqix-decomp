#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02039d84;
struct Struct_02033834;
struct Struct_ov017_021bd704 {
    unsigned char unknown_0_[5];
    unsigned char unknown_5_;
    unsigned char unknown_6_[4];
    unsigned short unknown_a_;
    unsigned char unknown_c_[0x44 - 0xc];
    unsigned short unknown_44_;
    unsigned short unknown_46_;
    Vector3fix unknown_48_;
    short unknown_54_;
};
struct Struct_ov017_021bd704_2 {
    unsigned char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};
extern "C" void* LinkSession_GetInstance();
unsigned char GameState_GetLeaderIndex(GameState*);
extern "C" int LinkSession_IsHostOrSolo(void*);
void SetFlag0x1ceBit0x4_02039d48(unsigned char*);
int fix32sin(int);
int fix32cos(int);
unsigned char GameObject_IsClimbingLadder(char*);
void ResetObjectState02039d84(Obj02039d84*);
void EnqueueEventTag60Field_021d440c(int);
void GameObject_SnapFacing(Obj02033874*, int);
void GameObject_ResetTrail(unsigned char*);
extern "C" void func_ov017_021c3e18(int);

// USA: func_ov017_021bd704
extern "C" ARM void func_ov017_021bd704(FormationState021bd704* self) {
    GameState* game = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    int anchor = (self->flags & 0x40) != 0;
    int suppress = (self->flags & 0x1000) != 0 && self->enabled != 0;
    if (self->enabled == 0 && !anchor && !suppress) return;
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
                    SetFlag0x1ceBit0x4_02039d48((unsigned char*)member);
                }
            } else if (arg0->unknown_5_ && !var3) {
                if (var8 == 1) {
                    int var11 = FIX32_MULTIPLY(fix32sin(var5), 0x800);
                    int var12 = FIX32_MULTIPLY(fix32cos(var5), -0x1333);
                    var4.z += var12 - var11;
                    var11 = FIX32_MULTIPLY(fix32cos(var5), 0x800);
                    var12 = FIX32_MULTIPLY(fix32sin(var5), -0x1333);
                    var4.x += var12 + var11;
                } else if (var8 == 2) {
                    int var13 = FIX32_MULTIPLY(fix32sin(var5), -0x800);
                    int var14 = FIX32_MULTIPLY(fix32cos(var5), -0x1800);
                    var4.z += var14 - var13;
                    var13 = FIX32_MULTIPLY(fix32cos(var5), -0x800);
                    var14 = FIX32_MULTIPLY(fix32sin(var5), -0x1800);
                    var4.x += var14 + var13;
                } else if (var8 == 3) {
                    int var15 = FIX32_MULTIPLY(fix32cos(var5), -0x1ccc);
                    var4.z += var15;
                    int var16 = FIX32_MULTIPLY(fix32sin(var5), -0x1ccc);
                    var4.x += var16;
                }
            }
            if (self->id != 8100 && GameObject_IsClimbingLadder((char*)member)) {
                ResetObjectState02039d84((Obj02039d84*)member);
                EnqueueEventTag60Field_021d440c(-1);
            }
            member->obj3D_.position_ = position;
            GameObject_SnapFacing((Obj02033874*)member, angle);
            member->obj3D_.EnableFlag(0x4000000);
            GameObject_ResetTrail((unsigned char*)member);
        }
    }
    if (LinkSession_IsHostOrSolo(search)) func_ov017_021c3e18(0);
}
