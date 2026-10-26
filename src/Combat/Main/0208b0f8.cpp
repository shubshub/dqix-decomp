#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"


struct Base02010834;
struct Struct_0208ab34;
struct Struct_0208ab34_2;
struct Struct_02048228;
struct Struct_02048284;
extern "C" void* Scenario_GetInstance();
extern "C" void* LinkSession_GetInstance();
extern "C" void* Zone3D_GetInstance();
extern "C" void* __clear(void*, int);
extern "C" void EventQuery_RunQueuedCommands(void*);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void GameState_GetPartyMemberIds(Base02010834*, int, int*, int*);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" int Scenario_RunTrigger(void*, int, void*);
extern "C" void* func_020e2ff8();
extern "C" int func_020e34bc(Struct_0208ab34*, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" unsigned char GameObject_IsClimbingLadder(char*);
extern "C" int func_020852a4(unsigned char*);
extern "C" int func_02085318(unsigned char*);
extern "C" void func_020e3368(unsigned char*, unsigned char);
extern "C" void func_02026f08(unsigned char*, int, int);
extern "C" int func_02048228(Struct_02048228*, int);
extern "C" int func_02048284(Struct_02048284*, int);
extern "C" void func_020e3428(void*, int);
extern "C" void func_020e3468(Struct_0208ab34_2*, int);

struct Actor0208b0f8 {
    char pad0[4];
    short slot;
    char pad6[0xb2 - 6];
    short active;
    char unknown_b4_[0x130 - 0xb4];
    unsigned int* restorationState;
#if defined(jpn)
    char unknown_134_[0x144 - 0x134];
#else
    char unknown1_134_[0x150 - 0x134];
#endif
    unsigned char* unknown_150_;
};
struct Struct_0208b0f8_2 {
    char pad0[0x94];
    unsigned char unknown_94_[4];
    unsigned char unknown_98_[4];
    unsigned char enabled;
    char unknown_9d_[0xa8 - 0x9d];
    unsigned char countdown;
};
struct Struct_0208b0f8_3 {
    char pad0[0xc];
    unsigned int zone;
    char pad10[0x30 - 0x10];
    void* nodes;
};

// USA: func_0208b0f8
extern "C" ARM void func_0208b0f8(void* receiver) {
    Struct_0208b0f8_2* self = (Struct_0208b0f8_2*)receiver;
    GameState* game;
    void* data;
    GameResources* resources;
    int* search;
    unsigned char* flags;
    unsigned int blocked;
    int changed;
    void** list;
    void* entries;
    unsigned char* var10;
    unsigned char* var11;
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
            Struct_0208b0f8_3 record;
            record.zone = *(unsigned short*)Zone3D_GetInstance();
            if (Scenario_RunTrigger(data, 0x19, &record)) {
                EventQuery_RunQueuedCommands(&record);
            }
        }
    }
    entries = func_020e2ff8();
    changed = 0;
    var11 = self->unknown_94_;
    var10 = self->unknown_98_;
    for (i = 0; i < count; i++) {
        status = func_020e34bc((Struct_0208ab34*)entries, 1);
        party = (Actor0208b0f8*)game->GetPartyMemberByIndex(ids[i]);
        if (!LinkSession_IsActive(search) || (LinkSession_IsActive(search) && status != 1)) {
            if (party == NULL || leader->active == 0 || GameObject_IsClimbingLadder((char*)leader) != 0 ||
                (party->restorationState[0] & 1) || !FieldTaskQueue_IsEmpty(list)) {
                changed = 1;
                continue;
            }
        }
        hp = func_020852a4(party->unknown_150_);
        if (hp > 0 && self->enabled && !blocked) {
            if (var11[i] == 0) {
                if (status != 2 && status != 1) func_020e3368((unsigned char*)entries, 1);
                if (status == 1) {
                    func_02026f08(flags, (unsigned char)ids[i], 0);
                    if (!(party->restorationState[0] & 1)) func_02048228((Struct_02048228*)party, hp);
                    var11[i] = 0x28;
                    if (LinkSession_IsActive(search)) func_ov017_021c9e00(ids[i], 1, 0, 0);
                    changed = 1;
                }
            } else var11[i]--;
        }
        mp = func_02085318(party->unknown_150_);
        if (mp > 0 && self->enabled && !blocked) {
            if (var10[i] == 0) {
                if (status != 2 && status != 1) func_020e3368((unsigned char*)entries, 1);
                if (status == 1) {
                    func_02026f08(flags, (unsigned char)ids[i], 0);
                    if (!(party->restorationState[0] & 1)) func_02048284((Struct_02048284*)party, mp);
                    var10[i] = 0x28;
                    if (LinkSession_IsActive(search)) func_ov017_021c9e00(ids[i], 1, 1, 0);
                    changed = 1;
                }
            } else var10[i]--;
        }
    }
    if (changed) {
        int status = func_020e34bc((Struct_0208ab34*)entries, 1);
        if (status == 1) func_020e3428(entries, 1);
        else if ((unsigned int)(status - 3) <= 2) func_020e3468((Struct_0208ab34_2*)entries, 1);
    }
}
