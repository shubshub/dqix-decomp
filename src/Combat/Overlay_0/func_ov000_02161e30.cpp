#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_02070b6c_3;
struct Struct_0206f01c_2;
struct Struct_02048850_2;
struct Struct_02048850;
struct Struct_02048934 { char padding0[0x2c]; char payload[1]; };
struct Struct_ov000_02161e30_3 {
    unsigned char cursor;
    char padding1;
    unsigned short key;
    unsigned int flags;
};
struct Struct_ov000_02161e30_4 {
    unsigned short key;
    unsigned char combatant;
    char unknown_3_[7];
    unsigned char count : 4;
    unsigned char mode : 4;
    char unknown_b_[0xd];
};
struct PartyRoster {
    unsigned char count;
    unsigned char memberCount : 4;
    unsigned char field1 : 2;
    unsigned char groupCount : 2;
    char padding2[2];
    Struct_ov000_02161e30_4 slots[3];
    Struct_ov000_02161e30_3 groups[3];
};
struct Struct_ov000_02161e30_5 {
    Random unknown_0_;
    char padding[0x81b0 - sizeof(Random)];
    PartyRoster roster;
};
struct Struct_ov000_02161e30_6 {
    char padding0[0x678];
    char params[0xc];
    char entries[0xc];
};
struct Struct_ov000_02161e30 {
#if defined(jpn)
    char padding0[0x218];
#else
    char padding0[0x29c];
#endif
    Struct_ov000_02161e30_5* unknown_29c_;
    Struct_ov000_02161e30_6* resources;
};
struct Struct_ov000_02161e30_2 {
    unsigned short first, second, third, unknown_6_;
    char unknown_8_[0x1d];
    unsigned char slot;
};
struct Struct_ov000_0215ab88 {
    char padding0[0x138];
    Struct_ov000_02161e30_2* unknown_138_;
    char unknown_13c_[0xc];
    Struct_02048934* entry;
    char unknown_14c_[0x30];
    unsigned char group;
    char unknown_17d_[7];
    unsigned char active;
    char unknown_185_;
    unsigned short key;
    unsigned short first, second;
    unsigned char unknown_18c_, variant;
};
extern "C" int* LinkSession_GetInstance();
extern "C" Struct_02048934* func_02070fd0(Struct_02070b6c_3*, int);
extern "C" Struct_02048850_2* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" Struct_ov000_0215ab88* func_0200fea4(GameState*, int);
extern "C" void func_ov000_021620d8(Struct_ov000_02161e30_3*);
extern "C" void func_ov000_02167c28(unsigned char*, int);
extern "C" void func_020891cc(Struct_ov000_02161e30_2*);
extern "C" void func_02089630(Struct_ov000_02161e30_2*, void*, int);
extern "C" void func_02048850(Struct_02048850*, Struct_02048850_2*);
extern "C" void func_02048934(void*, Struct_02048934*, Random*);
extern "C" int func_ov000_02161bb8(Struct_ov000_02161e30_3*);
extern "C" void func_ov000_02161bec(unsigned char*);
static inline void* inline_ov000_02161e30(Struct_02048934* entry) { return entry->payload; }
static inline int inline_ov000_02161e30_2(PartyRoster* roster) { SDK_NULL_ASSERT(roster); return roster->groupCount; }

static inline unsigned char inline_ov000_02161e30_3(Struct_ov000_0215ab88* actor) { SDK_NULL_ASSERT(actor); return actor->unknown_138_->slot; }

// USA: func_ov000_02161e30
extern "C" ARM void func_ov000_02161e30(Struct_ov000_02161e30* state, int id, int key) {
    Struct_02048934* entry;
    Struct_ov000_0215ab88* actor;
    PartyRoster* const roster = &state->unknown_29c_->roster;
    GameState* game = GameState::GetInstance();
    LinkSession_GetInstance();
    Struct_ov000_02161e30_6* resources = state->resources;
    Struct_0206f01c_2* params = (Struct_0206f01c_2*)state->resources->params;
    entry = func_02070fd0((Struct_02070b6c_3*)resources->entries, key);
    Struct_02048850_2* param = func_0206f4f0(params, (short)key);
    if (!entry || !param) return;
    actor = func_0200fea4(game, id);
    int group = actor->group;
    roster->count -= roster->slots[group].count - 1;
    roster->memberCount -= roster->slots[group].mode - 1;
    memset(&roster->slots[group], 0, sizeof(Struct_ov000_02161e30_4));
    roster->slots[group].mode = 1;
    roster->slots[group].count = 1;
    roster->slots[group].key = key;
    roster->slots[group].combatant = id - 0xc0;
    int found = 0;
    int index = 0;
    for (int i = 0; i < roster->groupCount; i++) {
        if (key == roster->groups[i].key) {
            index = i;
            found = 1;
            break;
        }
    }
    if (!found) {
        index = inline_ov000_02161e30_2(roster);
        roster->groupCount = index + 1;
        func_ov000_021620d8(&roster->groups[index]);
        roster->groups[index].key = key;
        roster->groups[index].cursor = 1;
    }
    func_ov000_02167c28((unsigned char*)state, id);
    Struct_ov000_02161e30_2* var11 = actor->unknown_138_;
    func_020891cc(var11);
    func_02089630(var11, inline_ov000_02161e30(entry), 0);
    actor->entry = entry;
    int height = ((Object3D*)actor)->GetHeight();
    int radius = ((Object3D*)actor)->GetRadius();
    func_02048850((Struct_02048850*)actor, param);
    ((Object3D*)actor)->SetHeight(height);
    ((Object3D*)actor)->SetRadius(radius);
    func_02048934(actor, entry, &state->unknown_29c_->unknown_0_);
    unsigned short first = actor->first;
    unsigned short second = actor->second;
    actor->unknown_138_->first = first;
    actor->unknown_138_->third = first;
    actor->unknown_138_->second = second;
    actor->unknown_138_->unknown_6_ = second;
    Struct_ov000_02161e30_3* selected = &roster->groups[index];
    unsigned char slot = func_ov000_02161bb8(selected);
    actor->key = key;
    if (slot == 1) slot = 0;
    actor->unknown_18c_ = group;
    actor->variant = slot;
    actor->active = 1;
    int bit = inline_ov000_02161e30_3(actor);
    roster->groups[index].flags |= 1 << bit;
    func_ov000_02161bec(&selected->cursor);
}
