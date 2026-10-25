#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"


struct Base02010834;
struct Container020e34bc;
struct Entry020e3054;
struct Combatant02048228;
struct Combatant02048284;
extern "C" void* Scenario_GetInstance();
extern "C" void* func_0202ae18();
extern "C" void* Zone3D_GetInstance();
extern "C" void* __clear(void*, int);
extern "C" void EventQuery_RunQueuedCommands(void*);
extern "C" void func_ov017_021c9e00(int, int, int, int);
void CopyCountedBytesToIntArray02010834(Base02010834*, int, int*, int*);
int IsField0Null_02046b08(void**);
int Scenario_RunTrigger(void*, int, void*);
void* GetData02153637_020e2ff8();
int GetEntryStatusForKey020e34bc(Container020e34bc*, int);
int CheckField0NonZero_0202b7d8(int*);
unsigned char GetByte0x26c_02039d7c(char*);
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
    leader = (Actor0208b0f8*)game->GetUnknownGameObject();
    data = Scenario_GetInstance();
    GameState_GetParty(game);
    search = (int*)func_0202ae18();
    flags = (unsigned char*)resources->unknown_ptr_36d0;
    list = (void**)resources->fieldTaskQueue_;
    if (leader == NULL) return;
    blocked = TestFlags04(resources, 0x10);
    int ids[4];
    int count;
    __clear(ids, sizeof(ids));
    CopyCountedBytesToIntArray02010834((Base02010834*)game, leader->slot, ids, &count);
    if (IsField0Null_02046b08(list) && leader->active != 0 && self->countdown != 0) {
        self->countdown--;
        if (self->countdown == 0) {
            Record0208b0f8 record;
            record.zone = *(unsigned short*)Zone3D_GetInstance();
            if (Scenario_RunTrigger(data, 0x19, &record)) {
                EventQuery_RunQueuedCommands(&record);
            }
        }
    }
    var9 = func_020e2ff8();
    var7 = 0;
    var11 = var0->unknown_94_;
    var10 = var0->unknown_98_;
    for (var13 = 0; var13 < var19; var13++) {
        var14 = func_020e34bc((Struct_0208ab34*)var9, 1);
        var15 = (Struct_0208b0f8*)var1->GetPartyMemberByIndex(var18[var13]);
        if (!func_0202b7d8(var4) || (func_0202b7d8(var4) && var14 != 1)) {
            if (var15 == NULL || var12->unknown_b2_ == 0 || func_02039d7c((char*)var12) != 0 ||
                (var15->unknown_130_[0] & 1) || !func_02046b08(var8)) {
                var7 = 1;
                continue;
            }
        }
        var16 = func_020852a4(var15->unknown_150_);
        if (var16 > 0 && var0->unknown_9c_ && !var6) {
            if (var11[var13] == 0) {
                if (var14 != 2 && var14 != 1) func_020e3368((unsigned char*)var9, 1);
                if (var14 == 1) {
                    func_02026f08(var5, (unsigned char)var18[var13], 0);
                    if (!(var15->unknown_130_[0] & 1)) func_02048228((Struct_02048228*)var15, var16);
                    var11[var13] = 0x28;
                    if (func_0202b7d8(var4)) func_ov017_021c9e00(var18[var13], 1, 0, 0);
                    var7 = 1;
                }
            } else var11[var13]--;
        }
        var17 = func_02085318(var15->unknown_150_);
        if (var17 > 0 && var0->unknown_9c_ && !var6) {
            if (var10[var13] == 0) {
                if (var14 != 2 && var14 != 1) func_020e3368((unsigned char*)var9, 1);
                if (var14 == 1) {
                    func_02026f08(var5, (unsigned char)var18[var13], 0);
                    if (!(var15->unknown_130_[0] & 1)) func_02048284((Struct_02048284*)var15, var17);
                    var10[var13] = 0x28;
                    if (func_0202b7d8(var4)) func_ov017_021c9e00(var18[var13], 1, 1, 0);
                    var7 = 1;
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
