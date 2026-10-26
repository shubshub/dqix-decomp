#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"


struct Entry_02028bd0;

struct Struct_ov017_0219dac4 {
    Object3D obj3D;
    char unknown_ac_[0xc2 - 0xac];
    unsigned char unknown_c2_;
#if defined(jpn)
    char unknown_c3_[0x150 - 0xc3];
#else
    char unknown1_c3_[0x15c - 0xc3];
#endif
    int field15c;
};

extern "C" void _ZN8Object3D10SetField06Et(Object3D* obj, int value);
extern "C" void* LinkSession_GetInstance(void);
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" int func_02053ed0(void* obj);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_020546a8(void* obj);
extern "C" void func_ov017_0219cdc0(unsigned short value, int a1, signed char id);
extern "C" void GameObject_StopSinking(unsigned char* obj);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int LinkSession_IsHostOrSolo(void* p);
extern "C" void func_ov017_021a01bc(unsigned char* self);
extern "C" void func_ov017_021cdaa0(void);

// USA: func_ov017_0219dac4
extern "C" ARM void func_ov017_0219dac4(unsigned char* self, int id, int value) {
    GameState* gs = GameState::GetInstance();
    void* ctx = LinkSession_GetInstance();
    ZoneRecords_GetInstance();
    unsigned short* current = Zone3D_GetInstance();
    Struct_ov017_0219dac4* member = (Struct_ov017_0219dac4*)gs->GetPartyMemberByIndex(id);
    Scenario_GetInstance();
    if (member == NULL) {
        return;
    }

    unsigned short prev = member->obj3D.GetField06();
    if (value == 10000) {
        value = 5900;
    } else if (value == 10100) {
        value = 6401;
    }

    if (member->field15c != -1 && func_02053ed0(member) != 3) {
        member->field15c = value;
        for (int i = 0; i < 4; i++) {
            Struct_ov017_0219dac4* other = (Struct_ov017_0219dac4*)func_0200ff58(gs, i);
            if (other != NULL && id == func_020546a8(other)) {
                other->field15c = value;
            }
        }
    }

    _ZN8Object3D10SetField06Et(&member->obj3D, value);
    func_ov017_0219cdc0(value, 0, id);
    member->obj3D.SetInheritedAlpha(31);
    member->unknown_c2_ &= ~0x40;
    GameObject_StopSinking((unsigned char*)member);
    LadderClimb_Reset(GameObject_GetLadderClimb(member));

    for (int i = 0; i < 4; i++) {
        Struct_ov017_0219dac4* other = (Struct_ov017_0219dac4*)func_0200ff58(gs, i);
        if (other != NULL && id == func_020546a8(other)) {
            _ZN8Object3D10SetField06Et(&other->obj3D, value);
            other->unknown_c2_ &= ~0x40;
        }
    }

    if (LinkSession_IsGuest(ctx) && id == 0 && value == *current && prev != value) {
        func_ov017_021a01bc(self);
    }
    if (value == *current && LinkSession_IsHostOrSolo(ctx)) {
        func_ov017_021cdaa0();
    }
}
