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
TextRenderer* GetGlobalField0x1c020421a0();
extern "C" void func_02046380(TextRenderer*);
void CopyOutRegion0x571d_020114ec(char*, void*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
FoundReward* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
void Clear12Bytes020e46c4(void*);
extern "C" Words021edf38 func_ov023_021ed804(Words021edf38, FoundReward*);
void SetWords_021edf38_021edf38(void*, Words021edf38*);
void DispatchIfCountPositive020dcf7c(int, void*);
const char* FindEntryByKey_02072a68(TableA68*, int);
void InitObjFromCombatantId020e4bf4(void*, int);
void InitObjFromCombatant020e4c74(void*, GameObject*);
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_0204500c(TextRenderer*, const char*, int, int);
void ClearFlagBits10to24_021ed7e0(Flags_021ed7e0*);
int CopyIndexedRegion0x75f0_020ac020(void*, short*, int*, int);
extern "C" void func_020abe84(void*, short*, Flags_021ed7e0*, int);
extern "C" int func_ov023_021f4fc8();

// USA: func_ov023_021f2a48
extern "C" ARM int func_ov023_021f2a48(Struct_ov023_021f2a48_6* arg0) {
    GameState* var0 = GameState::GetInstance();
    Struct_ov023_021f2a48_7* var1 = _ZZ21inline_ov023_021f4c04vE1s.unknown_0_;
    Struct_02081870* var2 = func_020421a0();
    func_02046380(var2);
    if (var1->unknown_0_ == 0) {
        ++var1->unknown_e4_;
        if (arg0->unknown_5900_ <= var1->unknown_e4_) return 14;
        Struct_ov023_021f2a48_5* var3 = &arg0->unknown_58d0_[var1->unknown_e4_];
        unsigned short var4 = var3->unknown_2_0_;
        int var5 = var3->unknown_0_;
        int var6 = var3->unknown_3_7_;
        signed char var7 = var3->unknown_5_;
        unsigned char var8[4];
        func_020114ec((char*)var0, var8);
        GameObject* var9 = 0;
        for (int var10 = 0; var10 < 4; ++var10) {
            GameObject* var11 = var0->GetCombatantByIndex(var8[var10]);
            if (!var11) continue;
            if (!func_020a35e0((unsigned char*)arg0->unknown_2a0_, var8[var10])) continue;
            if (((Struct_ov023_021f2a48_2*)var11)->unknown_130_->unknown_0_ & 1) continue;
            var9 = var0->GetPartyMemberByIndex(var8[var10]);
            break;
        }
        if (!var9) return arg0->unknown_eac_;
        Struct_ov023_021f2a48_3* var12 = func_0206f4f0(&arg0->unknown_2a0_->unknown_678_, (short)var4);
        if (!var12) return arg0->unknown_eac_;
        Struct_ov023_021edc08_5 var13;
        Struct_ov023_021f2a48_4 var14;
        Struct_ov023_021edc08_5 var15;
        func_020e46c4(&var13);
        const Struct_ov023_021edc08_5& var16 = func_ov023_021ed804(var13, var12);
        func_ov023_021edf38(&var13, const_cast<Struct_ov023_021edc08_5*>(&var16));
        var2->unknown_20_ = &var13;
        char var17[128] = {0};
        char var18[128] = {0};
        func_020e46c4(&var14);
        var14.unknown_0_ = var17;
        var14.unknown_4_ = var18;
        func_020dcf7c((short)var5, &var14);
        var2->unknown_18_ = &var14;
        char var19[512] = {0};
        if (var7 >= 0) {
            func_0200ff1c(var0, var7);
            sprintf(var19, func_02072a68(&arg0->unknown_5904_, 0x25));
            func_020e4bf4(&var15, var7);
            var2->unknown_0_ = &var15;
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
