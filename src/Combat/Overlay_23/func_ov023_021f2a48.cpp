#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Resource/MonsterDefinition.h"

struct Struct_ov023_021edc08_5 { unsigned int unknown_0_, unknown_4_, unknown_8_; };
struct Struct_02072a68_2 { int unknown_0_[4]; };
struct Struct_ov023_021ed7e0 {
    unsigned int unknown_0_0_ : 11; unsigned int unknown_1_3_ : 7; unsigned int unknown_2_2_ : 7;
    unsigned int unknown_3_1_ : 7;
};
struct SePlayer;
struct RewardEntry {
    unsigned short text_; unsigned short key_ : 15; unsigned short plural_ : 1;
    unsigned char counter_; signed char combatant_;
};
struct Struct_020a95a4_8 {
    char unknown_0_[0x678]; Struct_0206f01c_2 unknown_678_;
};
struct Struct_ov023_021f2a48_6 {
    char unknown_0_[0x2a0]; Struct_020a95a4_8* unknown_2a0_; char unknown_2a4_[0xeac - 0x2a4]; int unknown_eac_;
    char unknown_eb0_[0x58d0 - 0xeb0]; Struct_ov023_021f2a48_5 unknown_58d0_[8]; unsigned char unknown_5900_;
    char unknown_5901_[3]; Struct_02072a68_2 unknown_5904_;
};
struct Struct_ov023_021f2a48_7 { int unknown_0_; char unknown_4_[0xe4 - 4]; signed char unknown_e4_; };
struct Struct_ov023_021f2a48_8 { Struct_ov023_021f2a48_7* unknown_0_; int unknown_4_; int unknown_8_; };
struct Struct_02081870 {
    void* unknown_0_; char unknown_4_[12]; void* unknown_10_; char unknown_14_[4]; void* unknown_18_;
    char unknown_1c_[4]; void* unknown_20_; char unknown_24_[0x998 - 0x24]; int unknown_998_;
    char unknown_99c_[0x19b2 - 0x99c]; unsigned char unknown_19b2_;
};
struct CombatStatus { unsigned int flags_; };
struct ActorView { char pad0[0x130]; CombatStatus* status_; };
struct FoundReward { char pad0[0x10]; unsigned short id_; };
struct TextBuffers { char* first_; char* second_; int field8_; };
extern "C" RewardGlobal _ZZ17GetGlobal021ffefcvE1s;
extern SePlayer g_sePlayer;
TextRenderer* MessageSystem_GetInstance();
extern "C" void func_02046380(TextRenderer*);
void GameState_GetPartyOrder(char*, void*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
FoundReward* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
void NameText_Clear(void*);
extern "C" Words021edf38 func_ov023_021ed804(Words021edf38, FoundReward*);
void SetWords_021edf38_021edf38(void*, Words021edf38*);
void DispatchIfCountPositive020dcf7c(int, void*);
const char* FindEntryByKey_02072a68(TableA68*, int);
void NameText_InitFromPartyMember(void*, int);
void InitObjFromCombatant020e4c74(void*, GameObject*);
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_0204500c(TextRenderer*, const char*, int, int);
void ClearFlagBits10to24_021ed7e0(Flags_021ed7e0*);
int CopyIndexedRegion0x75f0_020ac020(void*, short*, int*, int);
extern "C" void func_020abe84(void*, short*, Flags_021ed7e0*, int);
extern "C" int func_ov023_021f4fc8();

// USA: func_ov023_021f2a48
extern "C" ARM int func_ov023_021f2a48(RewardScreen* self) {
    GameState* state = GameState::GetInstance();
    RewardState* work = _ZZ17GetGlobal021ffefcvE1s.state_;
    TextRenderer* renderer = MessageSystem_GetInstance();
    func_02046380(renderer);
    if (work->state_ == 0) {
        ++work->index_;
        if (self->count_ <= work->index_) return 14;
        RewardEntry* reward = &self->entries_[work->index_];
        unsigned short key = reward->key_;
        int text = reward->text_;
        int plural = reward->plural_;
        signed char combatant = reward->combatant_;
        unsigned char order[4];
        GameState_GetPartyOrder((char*)state, order);
        GameObject* recipient = 0;
        for (int i = 0; i < 4; ++i) {
            GameObject* actor = state->GetCombatantByIndex(order[i]);
            if (!actor) continue;
            if (!TestBitAt0x34_020a35e0((unsigned char*)self->battle_, order[i])) continue;
            if (((ActorView*)actor)->status_->flags_ & 1) continue;
            recipient = state->GetPartyMemberByIndex(order[i]);
            break;
        }
        if (!recipient) return self->state_;
        FoundReward* found = SearchWithComparator0206f4f0(&self->battle_->rewards_, (short)key);
        if (!found) return self->state_;
        Words021edf38 words;
        TextBuffers description;
        Words021edf38 actorText;
        NameText_Clear(&words);
        const Words021edf38& copy = func_ov023_021ed804(words, found);
        SetWords_021edf38_021edf38(&words, const_cast<Words021edf38*>(&copy));
        renderer->reward_ = &words;
        char first[128] = {0};
        char second[128] = {0};
        NameText_Clear(&description);
        description.first_ = first;
        description.second_ = second;
        DispatchIfCountPositive020dcf7c((short)text, &description);
        renderer->description_ = &description;
        char message[512] = {0};
        if (combatant >= 0) {
            GetCombatantWithFlag0x100_0200ff1c(state, combatant);
            sprintf(message, FindEntryByKey_02072a68(&self->texts_, 0x25));
            NameText_InitFromPartyMember(&actorText, combatant);
            renderer->actor_ = &actorText;
        } else {
            char var20[0x164] = {0};
            sprintf(var19, func_02072a68(&arg0->unknown_5904_, 0x11));
            func_020e4c74(&var15, var9);
            var2->unknown_10_ = &var15;
            if (!var6) sprintf(var20, func_02072a68(&arg0->unknown_5904_, 0x12));
            else sprintf(var20, func_02072a68(&arg0->unknown_5904_, 0x13));
            strcat(var19, var20);
            if (var1->unknown_e4_ < arg0->unknown_5900_ - 1) strcat(var19, func_02072a68(&arg0->unknown_5904_, 0x22));
        }
        SePlayer_Play(&g_sePlayer, 0x15, 0);
        func_0204500c(renderer, message, 1, 0xe3);
        renderer->field19B2_ = 0;
        renderer->active_ = 1;
        if (self->entries_[work->index_].counter_) {
            Flags_021ed7e0 flags;
            ClearFlagBits10to24_021ed7e0(&flags);
            short id = found->id_;
            if (CopyIndexedRegion0x75f0_020ac020(0, &id, (int*)&flags, 1)) {
                switch (self->entries_[work->index_].counter_) {
                case 1: { unsigned int count = flags.first_ + 1; if (count > 99) count = 99; flags.first_ = count; break; }
                case 2: { unsigned int count = flags.second_ + 1; if (count > 99) count = 99; flags.second_ = count; break; }
                }
                func_020abe84(0, &var22, &var21, 1);
            }
        }
        ++var1->unknown_0_;
    } else if (var1->unknown_0_ == 1) {
        if (func_ov023_021f4fc8()) var1->unknown_0_ = 0;
    }
    return arg0->unknown_eac_;
}
