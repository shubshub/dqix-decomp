#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Object3D.h"

struct Struct_ov023_021eeaac_2 { int unknown_0_; };
struct Struct_0202c1a4;
struct Struct_02049b54_2;
struct Struct_02046574_2;
struct Struct_02072a68_2 { int unknown_0_[2]; };
struct Struct_ov000_0217964c_2 : Object3D { char unknown_ac_[0x138 - sizeof(Object3D)]; void* unknown_138_; };
struct Struct_ov003_02162f40 { char unknown_0_[0x2a]; signed char unknown_2a_; };
struct Struct_0202ea4c { int unknown_0_; Vector3fix unknown_4_, unknown_10_; char unknown_1c_[0x40 - 0x1c]; };
struct Struct_ov023_021ef6f4_3 {
    char unknown_0_[0x2a0]; Struct_ov003_02162f40* unknown_2a0_;
    char unknown_2a4_[0xc18 - 0x2a4]; Struct_0202ea4c unknown_c18_;
    char unknown_c58_[0xeac - 0xc58]; int unknown_eac_;
    char unknown_eb0_[0x576c - 0xeb0]; unsigned char unknown_576c_;
    char unknown_576d_[0x58c0 - 0x576d]; int unknown_58c0_;
    char unknown_58c4_[8]; unsigned short unknown_58cc_;
    char unknown_58ce_[0x5904 - 0x58ce]; Struct_02072a68_2 unknown_5904_;
    char unknown_590c_[0x6e2e - 0x590c]; unsigned char unknown_6e2e_; char unknown_6e2f_;
    unsigned short unknown_6e30_[3];
};
struct Struct_020465c0 {
    char unknown_0_[0x20]; void* unknown_20_;
    char unknown_24_[0x2c8 - 0x24]; int unknown_2c8_;
    char unknown_2cc_[0x998 - 0x2cc]; int unknown_998_; int unknown_99c_; int unknown_9a0_;
    char unknown_9a4_[0x19b2 - 0x9a4]; unsigned char unknown_19b2_;
};
struct GrottoZone { char pad0[0x23ec]; ActiveGrottoClass grotto_; };
struct MoveName { char* name_; };
extern "C" Reset_021eefac* _ZZ17GetGlobal021ffefcvE1s;
extern char g_bgmPlayer[] __attribute__((aligned(4)));
extern char data_ov023_021fe258[];
StoreStruct* MessageSystem_GetInstance();
int CheckField0NonZero_0202b7d8(int*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
void ZeroFieldAndShortTriple0x6e2e_ov000_02163b60(void*);
void ResetFields_021eefac(Reset_021eefac*);
BattleActor* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
const char* FindEntryByKey_02072a68(TableA68*, int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
int IsAnimationActive0209ca2c(void*);
void SetThreeInts_021f00f4(int*, int, int, int);
Vector3fix GetSubTriple02049b54(Obj02049b54*);
void SetSubstructByte0x56_02049f28(unsigned char*);
void ComputeAngleHeightDistance0202ea4c(Obj0202ea4c*);
void UpdateEntry0216d50c(void*);
int GameState_GetProtagonistIndex(GameState*);
void ResetAndDispatchActorContext0209c6d8(void*, int);
void DispatchAndSetTreasureMapUnknownBit_020117cc(char*, DetailedTreasureMapData*);
void ScaleOrResetCombatants_021ed988(char*, int);
MoveName* SearchBothTables02079e2c(char*, int);
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" {
void* func_0202ae18();
GrottoZone* Zone3D_GetInstance();
void __clear(void*, unsigned int);
void func_020e4ce8(void*, Struct_ov000_0217964c_2*, int);
void func_0204500c(Struct_020465c0*, const char*, int, int);
int func_ov023_021f4fc8();
void func_ov000_0216d370(void*, int, int, int);
void func_ov000_02163b90(Struct_ov023_021ef6f4_3*, int);
int func_020457e0(Struct_020465c0*);
void func_02011744(GameState*);
}

// USA: func_ov023_021ef6f4
extern "C" ARM int func_ov023_021ef6f4(BattleBossScene* self) {
    GameState* game = GameState::GetInstance();
    Reset_021eefac* state = _ZZ17GetGlobal021ffefcvE1s;
    StoreStruct* messages = MessageSystem_GetInstance();
    void* search = func_0202ae18();
    DetailedTreasureMapData* map = Zone3D_GetInstance()->grotto_.GetDetailedData();
    char message[0x300];
    __clear(message, sizeof(message));
    int actorContext[3];
    if (state->phase_ == 0) {
        if (!CheckField0NonZero_0202b7d8((int*)search) || self->info_->leader_ == GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search)) {
            ZeroFieldAndShortTriple0x6e2e_ov000_02163b60(self);
            state->phase_ = 1;
        } else { ResetFields_021eefac(state); return 5; }
    } else if (state->phase_ == 1) {
        int count = 1;
        if (map->legacy_.bossID_ == 9) count = 3;
        for (int i = 0; i < count; ++i) {
            BattleActor* actor = GetCombatantWithFlag0x400_0200fea4(game, i + 0xc0);
            if (actor && actor->active_) {
                self->actors_[self->actorCount_] = actor->actorIndex_;
                ++self->actorCount_;
            }
        }
        if ((!map->legacy_.minTurns_ || self->turns_ < map->legacy_.minTurns_) && self->turns_ < 1000) {
            BattleActor* actor = GetCombatantWithFlag0x400_0200fea4(game, self->actors_[0]);
            if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400_0200fea4(game, self->actors_[1]);
            func_020e4ce8(actorContext, actor, 1);
            sprintf(message, FindEntryByKey_02072a68(&self->text_, 0x23));
            messages->actorContext_ = actorContext;
            StoreInArray0x8b0_020465c0(messages, 0, self->turns_);
            StoreInArray0x8b0_020465c0(messages, 1, map->legacy_.level_);
            func_0204500c(messages, message, 1, 0xe3);
            messages->flag19b2_ = 0;
            messages->pending_ = 1;
            state->phase_ = 2;
        } else state->phase_ = 3;
    } else if (state->phase_ == 2) {
        if (!IsAnimationActive0209ca2c(g_bgmPlayer) && func_ov023_021f4fc8()) state->phase_ = 3;
    } else if (state->phase_ == 3) {
        func_ov000_0216d370(&self->camera_, 1, 1, 1);
        int scale = 0x3000;
        if (map->legacy_.bossID_ == 9) scale = 0x2333;
        int radius = 0;
        int height = 0;
        Vector3fix average;
        SetThreeInts_021f00f4(&average.x, 0, 0, 0);
        for (int i = 0; i < self->actorCount_; ++i) {
            BattleActor* actor = GetCombatantWithFlag0x400_0200fea4(game, self->actors_[i]);
            actor->position_ = GetSubTriple02049b54((Obj02049b54*)actor);
            actor->rotation_.x = 0;
            actor->rotation_.y = 0;
            actor->rotation_.z = 0;
            Vector3fix_Add(&average, &actor->position_, &average);
            radius += actor->GetRadius();
            if (height < actor->GetHeight()) height = actor->GetHeight();
            actor->SetAnimationByName(data_ov023_021fe258, 8);
            actor->TransitionInheritedAlpha(31, 200);
            actor->MakeVisible();
            SetSubstructByte0x56_02049f28((unsigned char*)actor);
        }
        var14.x = fix32_Divide(var14.x, arg0->unknown_6e2e_ << 12);
        var14.y = fix32_Divide(var14.y, arg0->unknown_6e2e_ << 12);
        var14.z = fix32_Divide(var14.z, arg0->unknown_6e2e_ << 12);
        func_ov000_02163b90(arg0, 0);
        int var17 = fix32_Divide(var13, 0x2000);
        Vector3fix var18;
        func_ov023_021f00f4(&var18.x, var14.x, var14.y + var17, var14.z);
        int var19 = FIX32_MULTIPLY(var12, var11);
        Vector3fix var20;
        func_ov023_021f00f4(&var20.x, var18.x, var18.y, var18.z + var19);
        arg0->unknown_c18_.unknown_10_ = var18;
        arg0->unknown_c18_.unknown_4_ = var20;
        func_0202ea4c(&arg0->unknown_c18_);
        func_ov000_0216d50c(&arg0->unknown_c18_);
        sprintf(var5, func_02072a68(&arg0->unknown_5904_, 0x1b));
        Struct_ov000_0217964c_2* var21 = func_0200fea4(var0, arg0->unknown_6e30_[0]);
        if (var4->legacy_.bossID_ == 9) var21 = func_0200fea4(var0, arg0->unknown_6e30_[1]);
        func_020e4ce8(var6, var21, 1);
        var2->unknown_20_ = var6;
        func_0204500c(var2, var5, 1, 0xe3);
        var2->unknown_19b2_ = 0;
        var2->unknown_998_ = 1;
        var1->unknown_0_ = 4;
    } else if (var1->unknown_0_ == 4) {
        if (func_ov023_021f4fc8()) {
            if (var4->legacy_.level_ >= 99) {
                sprintf(var5, func_02072a68(&arg0->unknown_5904_, 0x1d));
                Struct_ov000_0217964c_2* var22 = func_0200fea4(var0, arg0->unknown_6e30_[0]);
                if (var4->legacy_.bossID_ == 9) var22 = func_0200fea4(var0, arg0->unknown_6e30_[1]);
                func_020e4ce8(var6, var22, 1);
                var2->unknown_20_ = var6;
                func_0204500c(var2, var5, 1, 0xe3);
                var2->unknown_19b2_ = 0;
                var2->unknown_998_ = 1;
                var1->unknown_0_ = 8;
            } else {
                sprintf(var5, func_02072a68(&arg0->unknown_5904_, 0x1c), var4->legacy_.bossName_);
                Struct_ov000_0217964c_2* var23 = func_0200fea4(var0, arg0->unknown_6e30_[0]);
                if (var4->legacy_.bossID_ == 9) var23 = func_0200fea4(var0, arg0->unknown_6e30_[1]);
                func_020e4ce8(var6, var23, 1);
                var2->unknown_20_ = var6;
                func_0204500c(var2, var5, 1, 0xe3);
                var2->unknown_19b2_ = 0;
                var2->unknown_998_ = 1;
                var1->unknown_0_ = 5;
            }
        }
    } else if (var1->unknown_0_ == 5) {
        if (func_ov023_021f4fc8()) {
            GetCombatantWithFlag0x100_0200ff1c(game, GameState_GetProtagonistIndex(game));
            sprintf(message, FindEntryByKey_02072a68(&self->text_, 0x1e));
            BattleActor* actor = GetCombatantWithFlag0x400_0200fea4(game, self->actors_[0]);
            if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400_0200fea4(game, self->actors_[1]);
            func_020e4ce8(actorContext, actor, 1);
            messages->actorContext_ = actorContext;
            StoreInArray0x8b0_020465c0(messages, 0, self->experience_);
            func_0204500c(messages, message, 1, 0xe3);
            messages->flag19b2_ = 0;
            messages->pending_ = 1;
            messages->choice_ = 1;
            state->phase_ = 6;
        }
    } else if (var1->unknown_0_ == 6) {
        if (var2->unknown_9a0_ != 3) return arg0->unknown_eac_;
        if (!func_020457e0(var2)) var1->unknown_0_ = 7; else var1->unknown_0_ = 8;
    } else if (var1->unknown_0_ == 7) {
        if (func_ov023_021f4fc8()) {
            self->levelledUp_ = 1;
            sprintf(message, FindEntryByKey_02072a68(&self->text_, 0x1f));
            BattleActor* actor = GetCombatantWithFlag0x400_0200fea4(game, self->actors_[0]);
            if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400_0200fea4(game, self->actors_[1]);
            func_020e4ce8(actorContext, actor, 1);
            messages->actorContext_ = actorContext;
            StoreInArray0x8b0_020465c0(messages, 0, map->legacy_.level_ + 1);
            func_0204500c(messages, message, 1, 0xe3);
            messages->flag19b2_ = 0;
            messages->pending_ = 1;
            ResetAndDispatchActorContext0209c6d8(g_bgmPlayer, 0x35);
            map->UpdateFollowingCompletion(true, 0);
            DispatchAndSetTreasureMapUnknownBit_020117cc((char*)game, map);
            func_02011744(game);
            if (map->legacy_.GetLearnedMove(map->legacy_.level_, -1)) state->phase_ = 9;
            else state->phase_ = 11;
        }
    } else if (var1->unknown_0_ == 8) {
        func_ov023_021ed988((char*)arg0, 1500);
        var4->UpdateFollowingCompletion(false, arg0->unknown_58cc_);
        func_020117cc((char*)var0, var4);
        func_02011744(var0);
        var1->unknown_0_ = 10;
    } else if (var1->unknown_0_ == 9) {
        if (func_ov023_021f4fc8()) {
            int move = map->legacy_.GetLearnedMove(map->legacy_.level_, 1);
            if (move) {
                MoveName* name = SearchBothTables02079e2c((char*)GetData02108e10_020797dc(), (short)move);
                sprintf(message, FindEntryByKey_02072a68(&self->text_, 0x20));
                BattleActor* actor = GetCombatantWithFlag0x400_0200fea4(game, self->actors_[0]);
                if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400_0200fea4(game, self->actors_[1]);
                func_020e4ce8(actorContext, actor, 1);
                messages->actorContext_ = actorContext;
                MessageSystem_SetStringArgument((Obj02046574*)messages, 1, name->name_);
                func_0204500c(messages, message, 1, 0xe3);
                messages->flag19b2_ = 0;
                messages->pending_ = 1;
            }
            var1->unknown_0_ = 11;
        }
    } else if (var1->unknown_0_ == 10) {
        if (!func_0200fea4(var0, arg0->unknown_6e30_[0])->GetInheritedAlpha() || !arg0->unknown_6e2e_) var1->unknown_0_ = 11;
    } else if (var1->unknown_0_ == 11) {
        if (func_ov023_021f4fc8()) { func_ov023_021eefac(var1); return 5; }
    }
    return arg0->unknown_eac_;
}
