#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov000_02161e30;
struct Combatant020A36A8;
struct Struct_0207da94;
struct Entry0207d9bc;
struct Struct0216377c;

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
    char unknown_a_[0x20];
    signed char myIndex;
};

struct Container_021dae60 {
    char pad0[0xb8];
};

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif

    Struct_ov000_02161e30* battle;
    PartyState* party;
    char unknown_2a4_[0xc08];
    int state;
#if defined(jpn)
    char unknown_e2c_[0x28f0];
#else
    char unknown_eb0_[0x28b0];
#endif

    Container_021dae60 list;
#if defined(jpn)
    char unknown_37d4_[0x4164];
#else
    char unknown_3818_[0x3f30];
#endif

    unsigned char unknown_7748_;
};

extern "C" char GameState_GetProtagonistIndex(GameState* gs);
extern "C" void* func_0207d78c();
extern "C" int func_020a36a8(Combatant020A36A8* c);
extern "C" unsigned char func_0207db58(Entry0207d9bc* arr, unsigned short key, char val);
extern "C" void func_ov000_0216377c(Struct0216377c* obj, unsigned char val);
extern "C" void func_ov017_021cc050(unsigned short tag);

extern "C" {
extern "C" int func_020a35e0(PartyState* party, unsigned char bit);
extern "C" void func_020a367c(PartyState* party, unsigned char bit);
extern "C" void func_0207da94(void* entries, unsigned char member);
extern "C" void func_ov017_02191b40(GameResources* res, int member);
int* LinkSession_GetInstance();
int LinkSession_IsHostOrSolo(int*);
void func_ov000_02174a50(Container_021dae60*, int);
void func_ov017_021c9b90(unsigned short, int);
void func_ov000_0215fb04(Struct_ov000_02161e30*, int);
void func_ov026_021dbf04(Struct_ov000_02160da0*);
}

// USA: func_ov026_021dbd1c
extern "C" ARM void func_ov026_021dbd1c(Struct_ov000_02160da0* self, int member, int notify) {
    GameState* gs = GameState::GetInstance();
    PartyState* party = self->party;
    Container_021dae60* list = &self->list;
    Struct_ov000_02161e30* battle = self->battle;
    void* entries = func_0207d78c();
    int* link = LinkSession_GetInstance();
    GameResources* res = GetGameResources();
    int var7 = 0;

    if (func_020a35e0(party, member)) {
        var7 = 1;
        self->unknown_7748_ = 1;
    }
    func_ov000_02174a50(list, member);
    func_020a367c(party, member);
    func_0207da94(entries, member);
    func_ov017_02191b40(res, member);

    if (member == party->myIndex) {
        if (LinkSession_IsHostOrSolo(link)) {
            func_ov000_0216377c((Struct0216377c*)self, func_0207db58((Entry0207d9bc*)entries, party->netId, GameState_GetProtagonistIndex(gs)));
        } else {
            func_ov017_021c9b90(party->netId, member);
        }
    }
    func_ov000_0215fb04(battle, member);

    if (notify && self->state != 0x11 && var7 && func_020a36a8((Combatant020A36A8*)party)) {
        func_ov026_021dbf04(self);
        func_ov017_021cc050(party->netId);
    }
}
