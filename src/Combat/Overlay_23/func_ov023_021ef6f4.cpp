#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Object3D.h"

struct Struct_ov023_021eeaac_2 { int phase_; };
struct SearchStruct0202c1a4;
struct Struct_02049b54_2;
struct Obj02046574;
struct TableA68 { int unknown_0_[2]; };
struct Struct_ov000_0217964c_2 : Object3D { char unknown_ac_[0x138 - sizeof(Object3D)]; void* active_; };
struct BattleInfo { char pad0[0x2a]; signed char leader_; };
struct Struct_0202ea4c { int unknown_0_; Vector3fix position_, unknown_10_; char unknown_1c_[0x40 - 0x1c]; };
struct Struct_ov023_021ef6f4_3 {
    char pad0[0x2a0]; BattleInfo* info_;
    char unknown_2a4_[0xc18 - 0x2a4]; Struct_0202ea4c camera_;
    char unknown_c58_[0xeac - 0xc58]; int unknown_eac_;
    char unknown_eb0_[0x576c - 0xeb0]; unsigned char unknown_576c_;
    char unknown_576d_[0x58c0 - 0x576d]; int experience_;
    char unknown_58c4_[8]; unsigned short unknown_58cc_;
    char unknown_58ce_[0x5904 - 0x58ce]; TableA68 text_;
    char unknown_590c_[0x6e2e - 0x590c]; unsigned char actorCount_; char unknown_6e2f_;
    unsigned short actors_[3];
};
struct StoreStruct {
    char pad0[0x20]; void* unknown_20_;
    char pad24[0x2c8 - 0x24]; int choice_;
    char unknown_2cc_[0x998 - 0x2cc]; int unknown_998_; int unknown_99c_; int state_;
    char unknown_9a4_[0x19b2 - 0x9a4]; unsigned char unknown_19b2_;
};
struct GrottoZone { char pad0[0x23ec]; ActiveGrottoClass grotto_; };
struct Struct_ov023_021ef6f4_2 { char* name_; };
extern "C" Struct_ov023_021eeaac_2* _ZZ21inline_ov023_021f4c04vE1s;
extern char g_bgmPlayer[] __attribute__((aligned(4)));
extern char data_ov023_021fe258[];
extern "C" StoreStruct* MessageSystem_GetInstance();
extern "C" int LinkSession_IsActive(int*);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_ov000_02163b60(void*);
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2*);
extern "C" Struct_ov000_0217964c_2* func_0200fea4(GameState*, int);
extern "C" const char* func_02072a68(TableA68*, int);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" int func_0209ca2c(void*);
extern "C" void func_ov023_021f00f4(int*, int, int, int);
extern "C" Vector3fix func_02049b54(Struct_02049b54_2*);
extern "C" void func_02049f28(unsigned char*);
extern "C" void func_0202ea4c(Struct_0202ea4c*);
extern "C" void func_ov000_0216d50c(void*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_0209c6d8(void*, int);
extern "C" void func_020117cc(char*, DetailedTreasureMapData*);
extern "C" void func_ov023_021ed988(char*, int);
extern "C" Struct_ov023_021ef6f4_2* func_02079e2c(char*, int);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" {
void* LinkSession_GetInstance();
GrottoZone* Zone3D_GetInstance();
void __clear(void*, unsigned int);
void func_020e4ce8(void*, Struct_ov000_0217964c_2*, int);
void func_0204500c(StoreStruct*, const char*, int, int);
int func_ov023_021f4fc8();
void func_ov000_0216d370(void*, int, int, int);
void func_ov000_02163b90(Struct_ov023_021ef6f4_3*, int);
int func_020457e0(StoreStruct*);
void func_02011744(GameState*);
}

// USA: func_ov023_021ef6f4
extern "C" ARM int func_ov023_021ef6f4(Struct_ov023_021ef6f4_3* self) {
    GameState* game = GameState::GetInstance();
    Struct_ov023_021eeaac_2* state = _ZZ21inline_ov023_021f4c04vE1s;
    StoreStruct* messages = MessageSystem_GetInstance();
    void* search = LinkSession_GetInstance();
    DetailedTreasureMapData* map = Zone3D_GetInstance()->grotto_.GetDetailedData();
    char message[0x300];
    __clear(message, sizeof(message));
    int var6[3];
    if (state->phase_ == 0) {
        if (!LinkSession_IsActive((int*)search) || self->info_->leader_ == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) {
            func_ov000_02163b60(self);
            state->phase_ = 1;
        } else { func_ov023_021eefac(state); return 5; }
    } else if (state->phase_ == 1) {
        int count = 1;
        if (map->legacy_.bossID_ == 9) count = 3;
        for (int i = 0; i < count; ++i) {
            Struct_ov000_0217964c_2* actor = func_0200fea4(game, i + 0xc0);
            if (actor && actor->active_) {
                self->actors_[self->actorCount_] = actor->actorIndex_;
                ++self->actorCount_;
            }
        }
        if ((!map->legacy_.minTurns_ || self->unknown_58cc_ < map->legacy_.minTurns_) && self->unknown_58cc_ < 1000) {
            Struct_ov000_0217964c_2* actor = func_0200fea4(game, self->actors_[0]);
            if (map->legacy_.bossID_ == 9) actor = func_0200fea4(game, self->actors_[1]);
            func_020e4ce8(var6, actor, 1);
            sprintf(message, func_02072a68(&self->text_, 0x23));
            messages->unknown_20_ = var6;
            func_020465c0(messages, 0, self->unknown_58cc_);
            func_020465c0(messages, 1, map->legacy_.level_);
            func_0204500c(messages, message, 1, 0xe3);
            messages->unknown_19b2_ = 0;
            messages->unknown_998_ = 1;
            state->phase_ = 2;
        } else state->phase_ = 3;
    } else if (state->phase_ == 2) {
        if (!func_0209ca2c(g_bgmPlayer) && func_ov023_021f4fc8()) state->phase_ = 3;
    } else if (state->phase_ == 3) {
        func_ov000_0216d370(&self->camera_, 1, 1, 1);
        int scale = 0x3000;
        if (map->legacy_.bossID_ == 9) scale = 0x2333;
        int radius = 0;
        int height = 0;
        Vector3fix var14;
        func_ov023_021f00f4(&var14.x, 0, 0, 0);
        for (int i = 0; i < self->actorCount_; ++i) {
            Struct_ov000_0217964c_2* actor = func_0200fea4(game, self->actors_[i]);
            actor->position_ = func_02049b54((Struct_02049b54_2*)actor);
            actor->rotation_.x = 0;
            actor->rotation_.y = 0;
            actor->rotation_.z = 0;
            Vector3fix_Add(&var14, &actor->position_, &var14);
            radius += actor->GetRadius();
            if (height < actor->GetHeight()) height = actor->GetHeight();
            actor->SetAnimationByName(data_ov023_021fe258, 8);
            actor->TransitionInheritedAlpha(31, 200);
            actor->MakeVisible();
            func_02049f28((unsigned char*)actor);
        }
        var14.x = fix32_Divide(var14.x, self->actorCount_ << 12);
        var14.y = fix32_Divide(var14.y, self->actorCount_ << 12);
        var14.z = fix32_Divide(var14.z, self->actorCount_ << 12);
        func_ov000_02163b90(self, 0);
        int var17 = fix32_Divide(height, 0x2000);
        Vector3fix target;
        func_ov023_021f00f4(&target.x, var14.x, var14.y + var17, var14.z);
        int distance = FIX32_MULTIPLY(radius, scale);
        Vector3fix position;
        func_ov023_021f00f4(&position.x, target.x, target.y, target.z + distance);
        self->camera_.unknown_10_ = target;
        self->camera_.position_ = position;
        func_0202ea4c(&self->camera_);
        func_ov000_0216d50c(&self->camera_);
        sprintf(message, func_02072a68(&self->text_, 0x1b));
        Struct_ov000_0217964c_2* actor = func_0200fea4(game, self->actors_[0]);
        if (map->legacy_.bossID_ == 9) actor = func_0200fea4(game, self->actors_[1]);
        func_020e4ce8(var6, actor, 1);
        messages->unknown_20_ = var6;
        func_0204500c(messages, message, 1, 0xe3);
        messages->unknown_19b2_ = 0;
        messages->unknown_998_ = 1;
        state->phase_ = 4;
    } else if (state->phase_ == 4) {
        if (func_ov023_021f4fc8()) {
            if (map->legacy_.level_ >= 99) {
                sprintf(message, func_02072a68(&self->text_, 0x1d));
                Struct_ov000_0217964c_2* actor = func_0200fea4(game, self->actors_[0]);
                if (map->legacy_.bossID_ == 9) actor = func_0200fea4(game, self->actors_[1]);
                func_020e4ce8(var6, actor, 1);
                messages->unknown_20_ = var6;
                func_0204500c(messages, message, 1, 0xe3);
                messages->unknown_19b2_ = 0;
                messages->unknown_998_ = 1;
                state->phase_ = 8;
            } else {
                sprintf(message, func_02072a68(&self->text_, 0x1c), map->legacy_.bossName_);
                Struct_ov000_0217964c_2* actor = func_0200fea4(game, self->actors_[0]);
                if (map->legacy_.bossID_ == 9) actor = func_0200fea4(game, self->actors_[1]);
                func_020e4ce8(var6, actor, 1);
                messages->unknown_20_ = var6;
                func_0204500c(messages, message, 1, 0xe3);
                messages->unknown_19b2_ = 0;
                messages->unknown_998_ = 1;
                state->phase_ = 5;
            }
        }
    } else if (state->phase_ == 5) {
        if (func_ov023_021f4fc8()) {
            func_0200ff1c(game, GameState_GetProtagonistIndex(game));
            sprintf(message, func_02072a68(&self->text_, 0x1e));
            Struct_ov000_0217964c_2* actor = func_0200fea4(game, self->actors_[0]);
            if (map->legacy_.bossID_ == 9) actor = func_0200fea4(game, self->actors_[1]);
            func_020e4ce8(var6, actor, 1);
            messages->unknown_20_ = var6;
            func_020465c0(messages, 0, self->experience_);
            func_0204500c(messages, message, 1, 0xe3);
            messages->unknown_19b2_ = 0;
            messages->unknown_998_ = 1;
            messages->choice_ = 1;
            state->phase_ = 6;
        }
    } else if (state->phase_ == 6) {
        if (messages->state_ != 3) return self->unknown_eac_;
        if (!func_020457e0(messages)) state->phase_ = 7; else state->phase_ = 8;
    } else if (state->phase_ == 7) {
        if (func_ov023_021f4fc8()) {
            self->unknown_576c_ = 1;
            sprintf(message, func_02072a68(&self->text_, 0x1f));
            Struct_ov000_0217964c_2* actor = func_0200fea4(game, self->actors_[0]);
            if (map->legacy_.bossID_ == 9) actor = func_0200fea4(game, self->actors_[1]);
            func_020e4ce8(var6, actor, 1);
            messages->unknown_20_ = var6;
            func_020465c0(messages, 0, map->legacy_.level_ + 1);
            func_0204500c(messages, message, 1, 0xe3);
            messages->unknown_19b2_ = 0;
            messages->unknown_998_ = 1;
            func_0209c6d8(g_bgmPlayer, 0x35);
            map->UpdateFollowingCompletion(true, 0);
            func_020117cc((char*)game, map);
            func_02011744(game);
            if (map->legacy_.GetLearnedMove(map->legacy_.level_, -1)) state->phase_ = 9;
            else state->phase_ = 11;
        }
    } else if (state->phase_ == 8) {
        func_ov023_021ed988((char*)self, 1500);
        map->UpdateFollowingCompletion(false, self->unknown_58cc_);
        func_020117cc((char*)game, map);
        func_02011744(game);
        state->phase_ = 10;
    } else if (state->phase_ == 9) {
        if (func_ov023_021f4fc8()) {
            int move = map->legacy_.GetLearnedMove(map->legacy_.level_, 1);
            if (move) {
                Struct_ov023_021ef6f4_2* name = func_02079e2c((char*)func_020797dc(), (short)move);
                sprintf(message, func_02072a68(&self->text_, 0x20));
                Struct_ov000_0217964c_2* actor = func_0200fea4(game, self->actors_[0]);
                if (map->legacy_.bossID_ == 9) actor = func_0200fea4(game, self->actors_[1]);
                func_020e4ce8(var6, actor, 1);
                messages->unknown_20_ = var6;
                MessageSystem_SetStringArgument((Obj02046574*)messages, 1, name->name_);
                func_0204500c(messages, message, 1, 0xe3);
                messages->unknown_19b2_ = 0;
                messages->unknown_998_ = 1;
            }
            state->phase_ = 11;
        }
    } else if (state->phase_ == 10) {
        if (!func_0200fea4(game, self->actors_[0])->GetInheritedAlpha() || !self->actorCount_) state->phase_ = 11;
    } else if (state->phase_ == 11) {
        if (func_ov023_021f4fc8()) { func_ov023_021eefac(state); return 5; }
    }
    return self->unknown_eac_;
}
