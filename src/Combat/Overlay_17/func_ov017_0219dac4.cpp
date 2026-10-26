#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"


struct Struct_020fdd44;

struct Struct_ov017_0219dac4 {
    Object3D unknown_0_;
    char unknown_ac_[0xc2 - 0xac];
    unsigned char unknown_c2_;
#if defined(jpn)
    char unknown_c3_[0x150 - 0xc3];
#else
    char unknown1_c3_[0x15c - 0xc3];
#endif
    int unknown_15c_;
};

extern "C" void _ZN8Object3D10SetField06Et(Object3D* obj, int value);
extern "C" void* LinkSession_GetInstance(void);
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
int GetField0x158_02053ed0(void* obj);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0_020546a8(void* obj);
extern "C" void func_ov017_0219cdc0(unsigned short value, int a1, signed char id);
void GameObject_StopSinking(unsigned char* obj);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int LinkSession_IsHostOrSolo(void* p);
void SetByteIfDataAndCheckClear_021a01bc(unsigned char* self);
void EnqueueEventTag147_021cdaa0(void);

// USA: func_ov017_0219dac4
extern "C" ARM void func_ov017_0219dac4(unsigned char* self, int id, int value) {
    GameState* gs = GameState::GetInstance();
    void* ctx = LinkSession_GetInstance();
    ZoneRecords_GetInstance();
    unsigned short* current = Zone3D_GetInstance();
    Member_0219dac4* member = (Member_0219dac4*)gs->GetPartyMemberByIndex(id);
    Scenario_GetInstance();
    if (member == NULL) {
        return;
    }

    unsigned short var4 = var3->unknown_0_.GetField06();
    if (arg2 == 10000) {
        arg2 = 5900;
    } else if (arg2 == 10100) {
        arg2 = 6401;
    }

    if (var3->unknown_15c_ != -1 && func_02053ed0(var3) != 3) {
        var3->unknown_15c_ = arg2;
        for (int var5 = 0; var5 < 4; var5++) {
            Struct_ov017_0219dac4* var6 = (Struct_ov017_0219dac4*)func_0200ff58(var0, var5);
            if (var6 != NULL && arg1 == func_020546a8(var6)) {
                var6->unknown_15c_ = arg2;
            }
        }
    }

    _ZN8Object3D10SetField06Et(&member->obj3D, value);
    func_ov017_0219cdc0(value, 0, id);
    member->obj3D.SetInheritedAlpha(31);
    member->flagsC2 &= ~0x40;
    GameObject_StopSinking((unsigned char*)member);
    LadderClimb_Reset(GameObject_GetLadderClimb(member));

    for (int var7 = 0; var7 < 4; var7++) {
        Struct_ov017_0219dac4* var8 = (Struct_ov017_0219dac4*)func_0200ff58(var0, var7);
        if (var8 != NULL && arg1 == func_020546a8(var8)) {
            _ZN8Object3D10SetField06Et(&var8->unknown_0_, arg2);
            var8->unknown_c2_ &= ~0x40;
        }
    }

    if (LinkSession_IsGuest(ctx) && id == 0 && value == *current && prev != value) {
        SetByteIfDataAndCheckClear_021a01bc(self);
    }
    if (value == *current && LinkSession_IsHostOrSolo(ctx)) {
        EnqueueEventTag147_021cdaa0();
    }
}
