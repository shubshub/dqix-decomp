#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov000_02160da0;
struct Combatant020A36A8;
struct Container_021dae60;
struct Struct_02053da0;
struct Flags02033fdc;
struct Struct_02039d84;
struct Bytes02033b88;
struct S_10088;
struct Struct_ov026_021d8ba0_10;

struct Struct_ov000_02161e30 {
    char pad0[0x8e20];
    int turns;
};

struct PartyState {
    char pad0[0x2];
    unsigned short field2;
    char pad4[0x4];
    unsigned short netId;
    char unknown_a_[0x2];
    int field0c;
    char pad10[0x1a];
    signed char myIndex;
    char unknown_2b_[0xa];
    unsigned char mode;
};

struct Struct_ov026_021d8ba0_6 {
    char pad0[0x10];
    unsigned char unknown_10_[8];
    signed char cursor;
    char unknown_19_[0xb];
    unsigned char done : 1;
    unsigned char rest : 7;
    char unknown_25_[0x3];
    int owner;
};

struct Struct_ov026_021dce34_2 {
    unsigned short field06;
    char pad2[0x6];
    int handle;
};

struct Struct_ov026_021dce34_3 { char data[0x70]; };
struct Struct_ov017_021ce704 { char data[0xc]; };

struct Struct_ov000_021643d4_8 {
    Vector3i pos;
    short angle;
    short pad;
};

struct Struct_ov017_021cbc48 {
    unsigned short netId;
    unsigned short field2;
    int mode;
    unsigned char party;
    signed char myIndex;
    unsigned char unknown_a_;
    unsigned char visible;
    unsigned char kind;
    short field0c;
};

struct Struct_ov026_021dce34 {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

struct Struct_ov023_021f2a48_2 {
    char pad0[0xbe];
    unsigned char state;
    char unknown_bf_[0x2];
    Struct_ov026_021dce34 unknown_c1_;
    unsigned char unknown_c2_0_ : 5;
    unsigned char hidden : 1;
    unsigned char unknown_c2_6_ : 2;
    char padc3[0x6d];
    unsigned int* flags;
#if defined(jpn)
    char unknown_134_[0x4c];
#else
    char unknown1_134_[0x58];
#endif
    unsigned int unknown_18c_;
};

extern "C" int func_020a36a8(Combatant020A36A8*);
extern "C" int func_ov000_02160fd4(void*, int);
extern "C" void func_ov000_02160fbc(void*, int);
extern "C" void func_020a35cc(unsigned char*, unsigned char);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" Struct_ov026_021d8ba0_6* func_ov026_021dae60(Container_021dae60*, int);
extern "C" void func_02053da0(char*, Struct_02053da0*);
extern "C" void func_0208936c(char*, char*, char*);
extern "C" void func_02039d84(Struct_02039d84*);
extern "C" void GameObject_ResumeMovement(Flags02033fdc*);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void GameObject_StopSinking(unsigned char*);
extern "C" void GameObject_ClearHidden(unsigned char*);
extern "C" void func_ov000_02168644(char*, int);
extern "C" void GameObject_StopFollowing(unsigned char*);
extern "C" void func_ov000_02167e6c(unsigned char*);
extern "C" int func_02010088(S_10088*);
extern "C" int func_ov026_021dd3c4(Struct_ov026_021d8ba0_10*);
extern "C" void func_ov017_021cbc48(Struct_ov017_021cbc48*);
extern "C" void func_ov017_021cdf80(char*, unsigned char);
extern "C" int func_ov000_0215fc60(char*);
extern "C" void func_ov000_02181364(void*);
extern "C" void func_ov000_021816e8(void*, int);
extern "C" void func_ov000_02181694(void*, int);
extern "C" void func_ov000_0217f5d0(void*);

extern "C" {
int* LinkSession_GetInstance();
int func_ov000_0215fad4(Struct_ov000_02161e30*);
int func_ov000_0215e9fc(Struct_ov000_02161e30*, short*, int, int);
void func_ov000_02174738(void*, int);
void* memset(void*, int, unsigned int);
void func_02049c88(void*, void*);
void func_ov026_021dc8fc(Struct_ov000_02160da0*, Struct_ov000_02161e30*, PartyState*, void*, void*, void*, int);
void func_020531f0(void*);
void func_ov000_02167fb0(void*, GameObject*);
int LinkSession_IsGuest(int*);
int func_ov017_0219c774(int, int, int);
void func_ov017_021917f0(int, int);
void func_ov000_021675a0(Struct_ov000_02160da0*);
void func_ov026_021daec8(Struct_ov000_02161e30*, void*, int);
void func_ov000_021676a8(Struct_ov000_02160da0*);
void func_ov000_02174b14(void*);
void func_ov000_0217a8f4(void*);
void func_ov017_021c847c();
void func_ov000_0217fcc4(void*, int);
}

// USA: func_ov026_021dce34
extern "C" ARM void func_ov026_021dce34(int mode, Struct_ov000_02160da0* self, Struct_ov000_02161e30* battle, PartyState* party,
                                        void* list, Struct_ov026_021dce34_2* events, Struct_ov026_021dce34_3* models, Struct_ov017_021ce704* stats,
                                        void* arg8, void* arg9, Struct_ov000_021643d4_8* entries, void* view) {
    Struct_ov017_021cbc48 ev;
    short ids[4];
    short members[4];
    GameState* gs = GameState::GetInstance();
    GetGameResources();
    int* link = LinkSession_GetInstance();
    if (!func_020a36a8((Combatant020A36A8*)party) && !func_ov000_02160fd4(self, 0x80000000)) {
        return;
    }
    func_ov000_02160fbc(self, 0x80000000);
    int added = 0;
    int id = func_ov000_0215fad4(battle);
    func_ov000_0215e9fc(battle, ids, 4, 0);
    while (id >= 0) {
        func_020a35cc((unsigned char*)party, id);
        func_ov000_02174738(list, id);
        Struct_ov026_021d8ba0_6* slot = func_ov026_021dae60((Container_021dae60*)list, id);
        if (slot) {
            GameObject* m = gs->GetPartyMemberByIndex(id);
            if (m) {
                slot->owner = *((Struct_ov023_021f2a48_2*)m)->flags;
            }
        }
        if (mode >= 0) {
            Struct_ov026_021d8ba0_6* s = func_ov026_021dae60((Container_021dae60*)list, id);
            if (s) {
                s->unknown_10_[s->cursor] = 100;
                s->done = 0;
            }
        }
        unsigned short field06 = events->field06;
        GameObject* m = gs->GetPartyMemberByIndex(id);
        if (m) {
            m->obj3D_.MakeHidden();
            m->obj3D_.SetField06(field06);
            memset(&models[id], 0, sizeof(Struct_ov026_021dce34_3));
            func_02049c88(m, &models[id]);
            func_02053da0((char*)m, (Struct_02053da0*)&stats[id]);
            func_0208936c((char*)m->currentStats_, (char*)((Struct_ov023_021f2a48_2*)m)->flags, (char*)m->baseStats_);
            func_ov026_021dc8fc(self, battle, party, list, arg8, arg9, id);
            func_020531f0(m);
            func_02039d84((Struct_02039d84*)m);
            ((Struct_ov023_021f2a48_2*)m)->unknown_c1_.mode |= 3;
            ((Struct_ov023_021f2a48_2*)m)->hidden = 1;
            GameObject_ResumeMovement((Flags02033fdc*)m);
            GameObject_ForceMotionState((Bytes02033b88*)m, 0);
            GameObject_StopSinking((unsigned char*)m);
            m->obj3D_.SetInheritedAlpha(0x1f);
            GameObject_ClearHidden((unsigned char*)m);
            if (!(*((Struct_ov023_021f2a48_2*)m)->flags & 1)) {
                if (((Struct_ov023_021f2a48_2*)m)->unknown_18c_ & 1) {
                    ((Struct_ov023_021f2a48_2*)m)->unknown_18c_ &= ~1;
                }
            }
            if (*((Struct_ov023_021f2a48_2*)m)->flags & 1) {
                if (!(((Struct_ov023_021f2a48_2*)m)->unknown_18c_ & 1)) {
                    ((Struct_ov023_021f2a48_2*)m)->unknown_18c_ |= 1;
                }
            }
            entries[id].pos = m->obj3D_.position_;
            entries[id].angle = m->obj3D_.rotation_.y;
            added = 1;
            func_ov000_02168644((char*)self, id);
            GameObject_StopFollowing((unsigned char*)m);
            func_ov000_02167fb0(self, m);
            if (m->obj3D_.actorIndex_ == 0 && LinkSession_IsGuest(link)) {
                func_ov017_0219c774(events->handle, 0, 0);
            }
        }
        func_ov017_021917f0(id, 1);
        id = func_ov000_0215fad4(battle);
    }
    if (added) {
        func_ov000_02160fbc(self, 0x80000000);
        func_ov000_021675a0(self);
        func_ov000_02167e6c((unsigned char*)self);
        func_ov026_021daec8(battle, view, 0);
        if (battle->turns == 0) {
            func_ov000_021676a8(self);
        }
        func_ov000_02174b14(list);
        func_ov000_0217a8f4(list);
        if (func_020a36a8((Combatant020A36A8*)party)) {
            unsigned char var12 = 0;
            unsigned char visible = 0;
            int count = func_ov000_0215e9fc(battle, members, 4, 0);
            int i;
            for (i = 0; i < count; i++) {
                GameObject* c = gs->GetCombatantByIndex(members[i]);
                if (c && ((Struct_ov023_021f2a48_2*)c)->state != 4 && ((Struct_ov023_021f2a48_2*)c)->state != 6) {
                    var12 |= 1 << i;
                }
            }
            for (i = 0; i < 8; i++) {
                GameObject* c = gs->GetCombatantByIndex(i + 0xc0);
                if (c && c->obj3D_.IsVisible() && !func_02010088((S_10088*)c) &&
                    !func_ov026_021dd3c4((Struct_ov026_021d8ba0_10*)c)) {
                    visible |= 1 << i;
                }
            }
            ev.netId = party->netId;
            ev.visible = visible;
            ev.unknown_a_ = var12;
            ev.mode = mode;
            ev.kind = party->mode;
            ev.field0c = party->field0c;
            for (int j = 0; j < 4; j++) {
                if (func_020a35e0((unsigned char*)party, j)) {
                    ev.party |= 1 << j;
                } else {
                    ev.party &= ~(1 << j);
                }
            }
            ev.myIndex = party->myIndex;
            ev.field2 = party->field2;
            func_ov017_021cbc48(&ev);
            func_ov017_021cdf80((char*)battle, 1);
            func_ov017_021c847c();
            if (party->mode == 2) {
                func_ov000_0217fcc4(list, -1);
            }
        }
    }
    if (func_ov000_0215fc60((char*)battle) != 0) {
        if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0) {
            func_ov000_02181364(list);
            func_ov000_0217fcc4(list, -1);
            func_ov000_021816e8(list, -1);
            func_ov000_02181694(list, 0);
        } else {
            for (int i = 1; i < 4; i++) {
                Struct_ov026_021d8ba0_6* s = func_ov026_021dae60((Container_021dae60*)list, i);
                if (s != 0) {
                    func_ov000_0217f5d0(s);
                    s->unknown_10_[s->cursor] = 100;
                }
            }
        }
    }
}
