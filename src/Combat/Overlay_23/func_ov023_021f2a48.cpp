#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Resource/MonsterDefinition.h"

struct Struct_ov023_021edc08_5 { unsigned int unknown_0_, unknown_4_, unknown_8_; };
struct TableA68 { int unknown_0_[4]; };
struct Struct_ov023_021ed7e0 {
    unsigned int unknown_0_0_ : 11; unsigned int unknown_1_3_ : 7; unsigned int unknown_2_2_ : 7;
    unsigned int unknown_3_1_ : 7;
};
struct SePlayer;
struct Struct_ov023_021f2a48_5 {
    unsigned short text_; unsigned short key_ : 15; unsigned short unknown_3_7_ : 1;
    unsigned char unknown_4_; signed char unknown_5_;
};
struct BattleData {
    char pad0[0x678]; Struct_0206f01c_2 unknown_678_;
};
struct Struct_ov023_021f2a48_6 {
    char pad0[0x2a0]; BattleData* battle_; char unknown_2a4_[0xeac - 0x2a4]; int state_;
    char unknown_eb0_[0x58d0 - 0xeb0]; Struct_ov023_021f2a48_5 entries_[8]; unsigned char count_;
    char unknown_5901_[3]; TableA68 texts_;
};
struct Struct_ov023_021f2a48_7 { int state_; char pad4[0xe4 - 4]; signed char unknown_e4_; };
struct Struct_ov023_021f2a48_8 { Struct_ov023_021f2a48_7* state_; int unknown_4_; int flags_; };
struct TextRenderer {
    void* actor_; char pad4[12]; void* unknown_10_; char unknown_14_[4]; void* description_;
    char unknown_1c_[4]; void* unknown_20_; char pad24[0x998 - 0x24]; int active_;
    char unknown_99c_[0x19b2 - 0x99c]; unsigned char unknown_19b2_;
};
struct Struct_ov023_021f2a48 { unsigned int flags_; };
struct Struct_ov023_021f2a48_2 { char pad0[0x130]; Struct_ov023_021f2a48* unknown_130_; };
struct Struct_ov023_021f2a48_3 { char pad0[0x10]; unsigned short id_; };
struct TextBuffers { char* unknown_0_; char* unknown_4_; int unknown_8_; };
extern "C" Struct_ov023_021f2a48_8 _ZZ21inline_ov023_021f4c04vE1s;
extern SePlayer g_sePlayer;
extern "C" TextRenderer* MessageSystem_GetInstance();
extern "C" void func_02046380(TextRenderer*);
extern "C" void GameState_GetPartyOrder(char*, void*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" Struct_ov023_021f2a48_3* func_0206f4f0(Struct_0206f01c_2*, int);
extern "C" void NameText_Clear(void*);
extern "C" Struct_ov023_021edc08_5 func_ov023_021ed804(Struct_ov023_021edc08_5, Struct_ov023_021f2a48_3*);
extern "C" void func_ov023_021edf38(void*, Struct_ov023_021edc08_5*);
extern "C" void func_020dcf7c(int, void*);
extern "C" const char* func_02072a68(TableA68*, int);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" void func_020e4c74(void*, GameObject*);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_0204500c(TextRenderer*, const char*, int, int);
extern "C" void func_ov023_021ed7e0(Struct_ov023_021ed7e0*);
extern "C" int func_020ac020(void*, short*, int*, int);
extern "C" void func_020abe84(void*, short*, Struct_ov023_021ed7e0*, int);
extern "C" int func_ov023_021f4fc8();

// USA: func_ov023_021f2a48
extern "C" ARM int func_ov023_021f2a48(Struct_ov023_021f2a48_6* self) {
    GameState* state = GameState::GetInstance();
    Struct_ov023_021f2a48_7* work = _ZZ21inline_ov023_021f4c04vE1s.state_;
    TextRenderer* renderer = MessageSystem_GetInstance();
    func_02046380(renderer);
    if (work->state_ == 0) {
        ++work->unknown_e4_;
        if (self->count_ <= work->unknown_e4_) return 14;
        Struct_ov023_021f2a48_5* reward = &self->entries_[work->unknown_e4_];
        unsigned short key = reward->key_;
        int text = reward->text_;
        int var6 = reward->unknown_3_7_;
        signed char combatant = reward->unknown_5_;
        unsigned char order[4];
        GameState_GetPartyOrder((char*)state, order);
        GameObject* recipient = 0;
        for (int i = 0; i < 4; ++i) {
            GameObject* actor = state->GetCombatantByIndex(order[i]);
            if (!actor) continue;
            if (!func_020a35e0((unsigned char*)self->battle_, order[i])) continue;
            if (((Struct_ov023_021f2a48_2*)actor)->unknown_130_->flags_ & 1) continue;
            recipient = state->GetPartyMemberByIndex(order[i]);
            break;
        }
        if (!recipient) return self->state_;
        Struct_ov023_021f2a48_3* found = func_0206f4f0(&self->battle_->unknown_678_, (short)key);
        if (!found) return self->state_;
        Struct_ov023_021edc08_5 words;
        TextBuffers description;
        Struct_ov023_021edc08_5 actorText;
        NameText_Clear(&words);
        const Struct_ov023_021edc08_5& copy = func_ov023_021ed804(words, found);
        func_ov023_021edf38(&words, const_cast<Struct_ov023_021edc08_5*>(&copy));
        renderer->unknown_20_ = &words;
        char first[128] = {0};
        char second[128] = {0};
        NameText_Clear(&description);
        description.unknown_0_ = first;
        description.unknown_4_ = second;
        func_020dcf7c((short)text, &description);
        renderer->description_ = &description;
        char message[512] = {0};
        if (combatant >= 0) {
            func_0200ff1c(state, combatant);
            sprintf(message, func_02072a68(&self->texts_, 0x25));
            NameText_InitFromPartyMember(&actorText, combatant);
            renderer->actor_ = &actorText;
        } else {
            char suffix[0x164] = {0};
            sprintf(message, func_02072a68(&self->texts_, 0x11));
            func_020e4c74(&actorText, recipient);
            renderer->unknown_10_ = &actorText;
            if (!var6) sprintf(suffix, func_02072a68(&self->texts_, 0x12));
            else sprintf(suffix, func_02072a68(&self->texts_, 0x13));
            strcat(message, suffix);
            if (work->unknown_e4_ < self->count_ - 1) strcat(message, func_02072a68(&self->texts_, 0x22));
        }
        SePlayer_Play(&g_sePlayer, 0x15, 0);
        func_0204500c(renderer, message, 1, 0xe3);
        renderer->unknown_19b2_ = 0;
        renderer->active_ = 1;
        if (self->entries_[work->unknown_e4_].unknown_4_) {
            Struct_ov023_021ed7e0 flags;
            func_ov023_021ed7e0(&flags);
            short id = found->id_;
            if (func_020ac020(0, &id, (int*)&flags, 1)) {
                switch (self->entries_[work->unknown_e4_].unknown_4_) {
                case 1: { unsigned int count = flags.unknown_1_3_ + 1; if (count > 99) count = 99; flags.unknown_1_3_ = count; break; }
                case 2: { unsigned int count = flags.unknown_2_2_ + 1; if (count > 99) count = 99; flags.unknown_2_2_ = count; break; }
                }
                func_020abe84(0, &id, &flags, 1);
            }
        }
        ++work->state_;
    } else if (work->state_ == 1) {
        if (func_ov023_021f4fc8()) work->state_ = 0;
    }
    return self->state_;
}
