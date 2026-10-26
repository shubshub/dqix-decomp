#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"


struct Base02010834;
struct Container020e34bc;
struct Entry020e3054;
struct Combatant02048228;
struct Combatant02048284;
extern "C" void* Scenario_GetInstance();
extern "C" void* LinkSession_GetInstance();
extern "C" void* Zone3D_GetInstance();
extern "C" void* __clear(void*, int);
extern "C" void EventQuery_RunQueuedCommands(void*);
extern "C" void func_ov017_021c9e00(int, int, int, int);
void GameState_GetPartyMemberIds(Base02010834*, int, int*, int*);
int FieldTaskQueue_IsEmpty(void**);
int Scenario_RunTrigger(void*, int, void*);
void* GetData02153637_020e2ff8();
int GetEntryStatusForKey020e34bc(Container020e34bc*, int);
int LinkSession_IsActive(int*);
unsigned char GameObject_IsClimbingLadder(char*);
int CountFlaggedSlotBit14Matches020852a4(unsigned char*);
int CountFlaggedSlotBit15Matches02085318(unsigned char*);
void StoreInFirstEmptySlot_020e3368(unsigned char*, unsigned char);
void SetBoolFlagAt558_02026f08(unsigned char*, int, int);
int RestoreMaxHpByAmount(Combatant02048228*, int);
int RestoreMaxMpByAmount(Combatant02048284*, int);
void Dispatch020e3428(void*, int);
void ClearEntryIfCurrentArrMatches020e3468(Entry020e3054*, int);

struct Struct_0208b0f8 {
    char unknown_0_[4];
    short unknown_4_;
    char unknown_6_[0xb2 - 6];
    short unknown_b2_;
    char unknown_b4_[0x130 - 0xb4];
    unsigned int* unknown_130_;
#if defined(jpn)
    char unknown_134_[0x144 - 0x134];
#else
    char unknown1_134_[0x150 - 0x134];
#endif
    unsigned char* unknown_150_;
};
struct Struct_0208b0f8_2 {
    char unknown_0_[0x94];
    unsigned char unknown_94_[4];
    unsigned char unknown_98_[4];
    unsigned char unknown_9c_;
    char unknown_9d_[0xa8 - 0x9d];
    unsigned char unknown_a8_;
};
struct Struct_0208b0f8_3 {
    char unknown_0_[0xc];
    unsigned int unknown_c_;
    char unknown_10_[0x30 - 0x10];
    void* unknown_30_;
};

// USA: func_0208b0f8
extern "C" ARM void func_0208b0f8(void* receiver) {
    State0208b0f8* self = (State0208b0f8*)receiver;
    GameState* game;
    void* data;
    GameResources* resources;
    int* search;
    unsigned char* flags;
    unsigned int blocked;
    int changed;
    void** list;
    void* entries;
    unsigned char* mpTimer;
    unsigned char* hpTimer;
    Actor0208b0f8* leader;
    int i;
    int status;
    Actor0208b0f8* party;
    int hp;
    int mp;
    game = GameState::GetInstance();
    resources = GetGameResources();
    leader = (Actor0208b0f8*)game->GetLeader();
    data = Scenario_GetInstance();
    GameState_GetParty(game);
    search = (int*)LinkSession_GetInstance();
    flags = (unsigned char*)resources->unknown_ptr_36d0;
    list = (void**)resources->fieldTaskQueue_;
    if (leader == NULL) return;
    blocked = TestFlags04(resources, 0x10);
    int ids[4];
    int count;
    __clear(ids, sizeof(ids));
    GameState_GetPartyMemberIds((Base02010834*)game, leader->slot, ids, &count);
    if (FieldTaskQueue_IsEmpty(list) && leader->active != 0 && self->countdown != 0) {
        self->countdown--;
        if (self->countdown == 0) {
            Record0208b0f8 record;
            record.zone = *(unsigned short*)Zone3D_GetInstance();
            if (Scenario_RunTrigger(data, 0x19, &record)) {
                EventQuery_RunQueuedCommands(&record);
            }
        }
    }
    entries = GetData02153637_020e2ff8();
    changed = 0;
    hpTimer = self->hpTimers;
    mpTimer = self->mpTimers;
    for (i = 0; i < count; i++) {
        status = GetEntryStatusForKey020e34bc((Container020e34bc*)entries, 1);
        party = (Actor0208b0f8*)game->GetPartyMemberByIndex(ids[i]);
        if (!LinkSession_IsActive(search) || (LinkSession_IsActive(search) && status != 1)) {
            if (party == NULL || leader->active == 0 || GameObject_IsClimbingLadder((char*)leader) != 0 ||
                (party->restorationState[0] & 1) || !FieldTaskQueue_IsEmpty(list)) {
                changed = 1;
                continue;
            }
        }
        hp = CountFlaggedSlotBit14Matches020852a4(party->skills);
        if (hp > 0 && self->enabled && !blocked) {
            if (hpTimer[i] == 0) {
                if (status != 2 && status != 1) StoreInFirstEmptySlot_020e3368((unsigned char*)entries, 1);
                if (status == 1) {
                    SetBoolFlagAt558_02026f08(flags, (unsigned char)ids[i], 0);
                    if (!(party->restorationState[0] & 1)) RestoreMaxHpByAmount((Combatant02048228*)party, hp);
                    hpTimer[i] = 0x28;
                    if (LinkSession_IsActive(search)) func_ov017_021c9e00(ids[i], 1, 0, 0);
                    changed = 1;
                }
            } else var11[var13]--;
        }
        mp = CountFlaggedSlotBit15Matches02085318(party->skills);
        if (mp > 0 && self->enabled && !blocked) {
            if (mpTimer[i] == 0) {
                if (status != 2 && status != 1) StoreInFirstEmptySlot_020e3368((unsigned char*)entries, 1);
                if (status == 1) {
                    SetBoolFlagAt558_02026f08(flags, (unsigned char)ids[i], 0);
                    if (!(party->restorationState[0] & 1)) RestoreMaxMpByAmount((Combatant02048284*)party, mp);
                    mpTimer[i] = 0x28;
                    if (LinkSession_IsActive(search)) func_ov017_021c9e00(ids[i], 1, 1, 0);
                    changed = 1;
                }
            } else var10[var13]--;
        }
    }
    if (var7) {
        int var21 = func_020e34bc((Struct_0208ab34*)var9, 1);
        if (var21 == 1) func_020e3428(var9, 1);
        else if ((unsigned int)(var21 - 3) <= 2) func_020e3468((Struct_0208ab34_2*)var9, 1);
    }
}
