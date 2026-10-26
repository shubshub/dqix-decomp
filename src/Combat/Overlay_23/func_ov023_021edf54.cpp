#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include <Filesystem/BackgroundLoader.h>
#include "Resource/GameResources.h"

struct SearchStruct0202c1a4;
struct S_10088;
struct Struct_ov023_021edf54;
struct TagValueEntry020e385c;
struct Struct_020a0858;
struct Struct_020a0300;

struct Struct_ov023_021ed7e0 {
    unsigned int count_ : 10;
    unsigned int unknown_1_2_ : 1;
    unsigned int fieldC : 7;
    unsigned int unknown_2_2_ : 7;
    unsigned int rest : 7;
};

struct Struct_ov023_021edf54_17 { int v[6]; };
struct Struct_ov023_021edf54_18 { int v[9]; };
struct Struct_ov023_021edf54_22 { int v[22]; };
struct Struct_ov023_021edf54_23 { int v[41]; };
struct Struct_ov023_021edf54_24 { int v[13]; };
struct Struct_ov023_021edf54_25 { int v[88]; };
struct Struct_ov023_021edf54_26 { int v[39]; };
struct Struct_ov023_021edf54_27 { short v[13]; };
struct Struct_ov023_021edf54_28 { short v[8]; };
struct Struct_ov023_021edf54_29 { short v[14]; };
struct Struct_ov023_021edf54_30 { short v[96]; };
struct Struct_ov023_021edf54_31 { char v[13]; };
struct Struct_ov023_021edf54_32 { char v[27]; };
struct Struct_ov023_021edf54_2 { char v[384]; };
struct Struct_ov023_021edf54_3 { char v[36]; };
struct Struct_ov023_021edf54_4 { char v[9]; };
struct Struct_ov023_021edf54_5 { char v[24]; };

#if defined(jpn)
struct Struct_ov023_021edf54_6 { char v[231]; };
enum { Enum_ov023_021edf54_48 = 0xc, Enum_ov023_021edf54_0 = -0xc, Enum_ov023_021edf54_0_2 = -0x84, Enum_ov023_021edf54_0_3 = 0x1f0,
       Enum_ov023_021edf54_0_4 = -0x220, Enum_ov023_021edf54_0_5 = -0x1d0 };
#else
enum { Enum_ov023_021edf54_48 = 0x30, Enum_ov023_021edf54_0 = 0, Enum_ov023_021edf54_0_2 = 0, Enum_ov023_021edf54_0_3 = 0,
       Enum_ov023_021edf54_0_4 = 0, Enum_ov023_021edf54_0_5 = 0 };
#endif

struct Struct_ov023_021edf54_7 {
    Struct_ov023_021edf54_17 unknown_0_;
    Struct_ov023_021edf54_18 unknown_18_;
    Struct_ov023_021edf54_22 unknown_3c_;
    Struct_ov023_021edf54_23 unknown_94_;
    Struct_ov023_021edf54_24 unknown_138_;
    Struct_ov023_021edf54_27 unknown_16c_;
    Struct_ov023_021edf54_31 unknown_186_;
    Struct_ov023_021edf54_25 unknown_194_;
    Struct_ov023_021edf54_25 unknown_2f4_;
    Struct_ov023_021edf54_28 unknown_454_;
    Struct_ov023_021edf54_32 unknown_464_;
    unsigned long long unknown_480_;
    Struct_ov023_021edf54_29 unknown_488_;
    Struct_ov023_021edf54_30 unknown_4a4_;
    unsigned short unknown_564_;
    unsigned short unknown_566_;
    short unknown_568_;
    unsigned char unknown_56a_;
    unsigned char unknown_56b_;
    unsigned char unknown_56c_;
    unsigned char unknown_56d_;
    unsigned char unknown_56e_;
#if defined(jpn)
    Struct_ov023_021edf54_6 unknown_56f_;
#else
    unsigned char unknown1_56f_;
    Struct_ov023_021edf54_2 unknown_570_;
#endif
    Struct_ov023_021edf54_25 unknown_6f0_;
    Struct_ov023_021edf54_26 unknown_850_;
    Struct_ov023_021edf54_3 unknown_8ec_;
    Struct_ov023_021edf54_4 unknown_910_;
    Struct_ov023_021edf54_17 unknown_91c_;
    Struct_ov023_021edf54_5 unknown_934_;
    int unknown_94c_;
    int level_;
    unsigned short unknown_954_;
    short unknown_956_;
    short unknown_958_;
    short unknown_95a_;
    short unknown_95c_;
    short unknown_95e_;
    unsigned short unknown_960_;
    unsigned short unknown_962_;

};

struct Struct_ov023_021edf54_8 {
    unsigned char member_;
    unsigned char level_;
    unsigned char vocation_;
    unsigned char unknown_3_;
    int unknown_4_;
    char name_[Enum_ov023_021edf54_48];
    Struct_ov023_021edf54_7 unknown_38_;
};

struct Struct_ov023_021edf54_9 {
    char pad0[0x10];
    unsigned char unknown_10_;
    char unknown_11_[0xf4 - 0x11];
    char unknown_f4_[0x24];
    Struct_ov023_021edf54_8 results_[4];
    unsigned char unknown_2798_;
    char region_[4];
    unsigned char regionResult_;
};

struct Struct_ov023_021edf54_10 {
    Struct_ov023_021edf54_9* work_;
};

struct Struct_ov023_021edf54_11 {
    char pad0[0x134];
    const char* name_;
    char unknown_138_[0x150 + Enum_ov023_021edf54_0 - 0x138];
    Struct_ov023_021edf54_7* unknown_150_;
};

struct Struct_ov023_021edf54_12 {
    unsigned short unknown_0_0_ : 3;
    unsigned short count_ : 11;
    unsigned short unknown_1_6_ : 2;
    unsigned short id_;
    short item_;
    unsigned char unknown_6_;
    char unknown_7_[3];
};

struct Struct_ov023_021edf54_13 {
    unsigned char level_;
    unsigned char unknown_1_0_ : 6;
    unsigned char kind_ : 2;
    char pad2[0x4e - 2];
    unsigned short id_;
};

struct Struct_ov023_021edf54_14 {
    char pad0[0x81b0];
    Struct_ov023_021edf54_13 unknown_81b0_;
    char unknown_8200_[0x8d66 - 0x8200];
    Struct_ov023_021edf54_12 unknown_8d66_[17];
    char unknown_8e10_[0x8e15 - 0x8e10];
    unsigned char unknown_8e15_;
    char unknown_8e16_[0x8e20 - 0x8e16];
    int unknown_8e20_;
    char unknown_8e24_[0x8e28 - 0x8e24];
    int unknown_8e28_;
    int unknown_8e2c_;
    int unknown_8e30_;
    unsigned int unknown_8e34_;
    char unknown_8e38_[0x8e3c - 0x8e38];
    float unknown_8e3c_;
    float unknown_8e40_;

    unsigned char inline_ov023_021edf54() const { return unknown_8e15_; }
    int inline_ov023_021edf54_2() const { return unknown_8e28_; }
    int inline_ov023_021edf54_3() const { return unknown_8e2c_; }
};

struct Struct_ov023_021edf54_15 {
    char pad0[8];
    unsigned short unknown_8_;
    char padA[2];
    int type_;
    char pad10[0x25 - 0x10];
    unsigned char special_;
    char unknown_26_[0x2a - 0x26];
    signed char leader_;
};

struct Struct_ov023_021edf54_16 {
    char pad0[0x29c + Enum_ov023_021edf54_0_2];
    Struct_ov023_021edf54_14* unknown_29c_;
    Struct_ov023_021edf54_15* info_;
    char unknown_2a4_[0xeac - 0x2a4];
    int unknown_eac_;
    char unknown_eb0_[0x5758 - 0xeb0 + Enum_ov023_021edf54_0_3 - Enum_ov023_021edf54_0_2];
    int experience_[4];
    int unknown_5768_;
    char unknown_576c_[0x58c0 - 0x576c];
    int unknown_58c0_;
    int unknown_58c4_;
    unsigned char unknown_58c8_;
    unsigned char unknown_58c9_;
    unsigned short unknown_58ca_;
    unsigned short unknown_58cc_;
    char unknown_58ce_[0x58d0 - 0x58ce];
    char unknown_58d0_[0x5900 - 0x58d0];
    unsigned char unknown_5900_;
    signed char unknown_5901_;
    char unknown_5902_[0x6e24 - 0x5902];
    int map_;
    unsigned short unknown_6e28_;
};

struct Struct_ov023_021edf54_19 {
    char pad0[0x42e2 + Enum_ov023_021edf54_0_4];
    unsigned char unknown_42e2_;
};

struct Renderer_021edf54 {
    char pad0[0x19b2 + Enum_ov023_021edf54_0_5];
    unsigned char active_;
};

struct Struct_ov023_021edf54_21 {
    char pad0[0x68];
    char unknown_68_[0xb0 - 0x68];
};

extern "C" Struct_ov023_021edf54_10 _ZZ21inline_ov023_021f4c04vE1s;

extern "C" {
int func_ov023_021f5340(void* dispatch);
void* LinkSession_GetInstance();
int func_ov000_0215e9fc(Struct_ov023_021edf54_14* world, short* out, int max, unsigned int flags);
int func_ov000_0215ec1c(Struct_ov023_021edf54_14* world, short* out, int max, int flags);
int func_ov023_021f4098(Struct_ov023_021edf54_16* self, int id, int bonus);
void func_ov023_021f454c(Struct_ov023_021edf54_16* self);
void func_ov017_021cd218(unsigned short event, unsigned short value, unsigned short arg2, unsigned short bits, unsigned short kind, unsigned short id);
void func_ov017_021cd590(unsigned short event, int* experience, int a, int b);
void func_ov017_021cd35c(unsigned short event, char* arg1, unsigned char count, signed char mask);
extern "C" void func_ov017_021cd4c8(unsigned short event, unsigned short item, signed char mask);
int LinkSession_IsGuest(void* mode);
int func_020abe84(void* unused, short* indices, Struct_ov023_021ed7e0* values, int count);
int func_ov023_021f5150(Struct_ov023_021edf54_16* self, Struct_ov023_021edf54_15* info, int* experience, int* arg3, int arg4);
}

extern "C" Renderer_021edf54* MessageSystem_GetInstance();
extern "C" void func_02049ae4(unsigned char* obj);
extern "C" void func_ov023_021f50fc();
extern "C" int LinkSession_IsActive(int* mode);
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4* mode);
extern "C" int func_020a35e0(unsigned char* info, unsigned char index);
extern "C" int GameState_GetProtagonistIndex(GameState* game);
extern "C" int func_020ac4c0(void* dst);
extern "C" void func_020a0858(Struct_020a0858* block, unsigned int amount);
extern "C" void func_020a0300(Struct_020a0300* block, unsigned int amount);
extern "C" int func_020ac494(void* src);
extern "C" void func_ov000_02160fa8(void* self, int flag);
extern "C" int func_ov000_02160fd4(void* self, int flag);
extern "C" void func_ov023_021ed7e0(Struct_ov023_021ed7e0* flags);
extern "C" int func_020ac020(void* unused, short* indices, int* dest, int count);
extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);
extern "C" int func_02010088(S_10088* obj);
extern "C" int func_ov023_021eea98(Struct_ov023_021edf54* obj);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" unsigned char GameState_GetPartyOrder(char* game, void* dst);
extern "C" TagValueEntry020e385c* func_020e3808();
extern "C" void func_020e39d4(TagValueEntry020e385c* tags, int a, int b, int c);

static inline unsigned int inline_020417b0_2(float rate, int value) {
    return value * rate;
}

static inline unsigned int inline_ov023_021edf54_4(float rate, unsigned int value) {
    return value * rate;
}

// USA: func_ov023_021edf54
extern "C" ARM int func_ov023_021edf54(Struct_ov023_021edf54_16* self) {
    void* mode;
    int seen[8];
    int gained[4];
    short ids[0x10];
    short members[4];
    GameState* game = GameState::GetInstance();
    if (!func_ov023_021f5340(_ZZ21inline_ov023_021f4c04vE1s.work_->unknown_f4_))
        return self->unknown_eac_;
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0)
        return self->unknown_eac_;

    Struct_ov023_021edf54_19* resources = (Struct_ov023_021edf54_19*)GetGameResources();
    Renderer_021edf54* renderer = MessageSystem_GetInstance();
    mode = LinkSession_GetInstance();

    Struct_ov023_021edf54_14* world = self->unknown_29c_;
    if (world != 0) {
        int i;
        int count;
        GameState* state = GameState::GetInstance();
        count = 0;
        count += func_ov000_0215e9fc(world, ids, 0x10, count);
        count += func_ov000_0215ec1c(world, ids + count, 0x10 - count, 0);
        for (i = 0; i < count; i++) {
            GameObject* c = state->GetCombatantByIndex(ids[i]);
            if (c != 0)
                func_02049ae4((unsigned char*)c);
        }
    }
    func_ov023_021f50fc();

    if (!LinkSession_IsActive((int*)mode) || self->info_->leader_ == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)mode)) {
        {
            int base = self->unknown_29c_->inline_ov023_021edf54_2();
            float rate = self->unknown_29c_->unknown_8e3c_;
            self->unknown_58c0_ = (unsigned int)(base * rate);
        }
        {
            int base = self->unknown_29c_->inline_ov023_021edf54_3();
            float rate = self->unknown_29c_->unknown_8e40_;
            self->unknown_58c4_ = (unsigned int)(base * rate);
        }
        self->unknown_58cc_ = self->unknown_29c_->unknown_8e20_;

        int memberCount = func_ov000_0215e9fc(self->unknown_29c_, members, 4, 1);
        self->unknown_58c8_ = 0;
        for (int i = 0; i < memberCount; i++)
            self->unknown_58c8_ |= 1 << members[i];

        int none = 0;
        for (int i = 0; i < 4; i++) {
            if (func_020a35e0((unsigned char*)self->info_, i))
                self->experience_[i] = func_ov023_021f4098(self, i, none);
        }

        Struct_ov023_021edf54_14* w = self->unknown_29c_;
        int count = w->unknown_8e30_;
        int total;
        int unique;
        int i;
        int j;
        Struct_ov023_021edf54_12* rewards = w->unknown_8d66_;
        if (count == 0) {
            Struct_ov023_021edf54_13* outcome = &w->unknown_81b0_;
            unsigned char threshold = w->inline_ov023_021edf54();
            int high = 0;
            if (outcome->level_ <= threshold)
                high = 1;
            if (outcome->kind_ > 1) {
                if (high == 0)
                    self->unknown_58c9_ = 5;
                else
                    self->unknown_58c9_ = 8;
                self->unknown_58ca_ = 0;
            } else if (outcome->level_ > 1) {
                if (high == 0)
                    self->unknown_58c9_ = 4;
                else
                    self->unknown_58c9_ = 7;
                self->unknown_58ca_ = outcome->id_;
            } else {
                if (high == 0)
                    self->unknown_58c9_ = 3;
                else
                    self->unknown_58c9_ = 6;
                self->unknown_58ca_ = outcome->id_;
            }
        } else {
            total = 0;
            unique = 0;
            for (i = 0; i < count; i++) {
                total += rewards[i].count_;
                for (j = 0; j < unique; j++) {
                    if (rewards[i].id_ == seen[j])
                        break;
                }
                if (j == unique)
                    seen[unique++] = rewards[i].id_;
            }
            if (total == 1) {
                self->unknown_58c9_ = 0;
                self->unknown_58ca_ = rewards[0].id_;
            } else if (unique > 1) {
                self->unknown_58c9_ = 2;
                self->unknown_58ca_ = 0;
            } else {
                self->unknown_58c9_ = 1;
                self->unknown_58ca_ = rewards[0].id_;
            }
        }

        func_ov023_021f454c(self);
        func_ov017_021cd218(self->info_->unknown_8_, self->unknown_58c4_, self->unknown_58cc_, self->unknown_58c8_, self->unknown_58c9_, self->unknown_58ca_);
        if (self->info_->special_ == 0) {
            func_ov017_021cd590(self->info_->unknown_8_, self->experience_, 0, 0);
            func_ov017_021cd35c(self->info_->unknown_8_, self->unknown_58d0_, self->unknown_5900_, self->unknown_5901_);
            if (self->map_ != 0)
                func_ov017_021cd4c8(self->info_->unknown_8_, self->unknown_6e28_, self->unknown_5901_);
            if (self->unknown_29c_->unknown_8e34_ != 0) {
                unsigned int bonus = inline_ov023_021edf54_4(self->unknown_29c_->unknown_8e3c_, self->unknown_29c_->unknown_8e34_);
                GameState* state = GameState::GetInstance();
                for (int i = 0; i < 4; i++) {
                    if (func_020a35e0((unsigned char*)self->info_, i))
                        gained[i] = func_ov023_021f4098(self, i, bonus);
                }
                func_ov017_021cd590(self->info_->unknown_8_, gained, 0, 1);
                int leader = GameState_GetProtagonistIndex(state);
                Struct_ov023_021edf54_21 block;
                func_020ac4c0(&block);
                func_020a0858((Struct_020a0858*)&block, gained[leader]);
                func_020a0300((Struct_020a0300*)block.unknown_68_, gained[leader]);
                func_020ac494(&block);
            }
        }
    } else {
        if (resources->unknown_42e2_ != 0)
            func_ov000_02160fa8(self, 0x2000000);
        if (LinkSession_IsGuest(mode) && self->info_->special_ != 0)
            renderer->active_ = 0;
        if (!func_ov000_02160fd4(self, 0x2000))
            return self->unknown_eac_;
        if (!func_ov000_02160fd4(self, 0x4000))
            return self->unknown_eac_;
        if (!func_ov000_02160fd4(self, 0x8000))
            return self->unknown_eac_;
    }

    Struct_ov023_021edf54_12* reward;
    int i;
    Struct_ov023_021edf54_12* rewards;
    int var39;
    Struct_ov023_021edf54_14* w = self->unknown_29c_;
    var39 = w->unknown_8e30_;
    rewards = w->unknown_8d66_;
    for (i = 0; i < var39; i++) {
        reward = &rewards[i];
        Struct_ov023_021ed7e0 flags;
        func_ov023_021ed7e0(&flags);
        short item = reward->item_;
        if (func_020ac020(0, &item, (int*)&flags, 1)) {
            unsigned int total = flags.count_ + reward->count_;
            if (total > 999)
                total = 999;
            flags.count_ = total;
            if (reward->unknown_6_ != 0)
                flags.unknown_1_2_ = reward->unknown_6_;
            func_020abe84(0, &item, &flags, 1);
        }
    }

    Struct_ov023_021edf54_8* result = _ZZ21inline_ov023_021f4c04vE1s.work_->results_;
    for (int i = 0; i < 4; i++) {
        if (func_020a35e0((unsigned char*)self->info_, i)) {
            Struct_ov023_021edf54_11* c = (Struct_ov023_021edf54_11*)func_0200ff1c(game, i);
            if (c != 0) {
                result->member_ = i;
                result->level_ = c->unknown_150_->level_;
                result->vocation_ = GameObject_GetPartyMemberLevel(c);
                result->unknown_3_ = func_02010088((S_10088*)c);
                result->unknown_4_ = self->experience_[i] + func_ov023_021eea98((Struct_ov023_021edf54*)c);
                Struct_ov023_021edf54_7* src = (Struct_ov023_021edf54_7*)func_02053c6c((unsigned char*)c);
                result->unknown_38_.unknown_0_ = src->unknown_0_;
                result->unknown_38_.unknown_18_ = src->unknown_18_;
                result->unknown_38_.unknown_3c_ = src->unknown_3c_;
                result->unknown_38_.unknown_94_ = src->unknown_94_;
                result->unknown_38_.unknown_138_ = src->unknown_138_;
                result->unknown_38_.unknown_16c_ = src->unknown_16c_;
                result->unknown_38_.unknown_186_ = src->unknown_186_;
                result->unknown_38_.unknown_194_ = src->unknown_194_;
                result->unknown_38_.unknown_2f4_ = src->unknown_2f4_;
                result->unknown_38_.unknown_454_ = src->unknown_454_;
                result->unknown_38_.unknown_464_ = src->unknown_464_;
                result->unknown_38_.unknown_480_ = src->unknown_480_;
                result->unknown_38_.unknown_488_ = src->unknown_488_;
                result->unknown_38_.unknown_4a4_ = src->unknown_4a4_;
                result->unknown_38_.unknown_564_ = src->unknown_564_;
                result->unknown_38_.unknown_566_ = src->unknown_566_;
                result->unknown_38_.unknown_568_ = src->unknown_568_;
                result->unknown_38_.unknown_56a_ = src->unknown_56a_;
                result->unknown_38_.unknown_56b_ = src->unknown_56b_;
                result->unknown_38_.unknown_56c_ = src->unknown_56c_;
                result->unknown_38_.unknown_56d_ = src->unknown_56d_;
                result->unknown_38_.unknown_56e_ = src->unknown_56e_;
#if defined(jpn)
                result->unknown_38_.unknown_56f_ = src->unknown_56f_;
#else
                result->unknown_38_.unknown1_56f_ = src->unknown1_56f_;
                result->unknown_38_.unknown_570_ = src->unknown_570_;
#endif
                result->unknown_38_.unknown_6f0_ = src->unknown_6f0_;
                result->unknown_38_.unknown_850_ = src->unknown_850_;
                result->unknown_38_.unknown_8ec_ = src->unknown_8ec_;
                result->unknown_38_.unknown_910_ = src->unknown_910_;
                result->unknown_38_.unknown_91c_ = src->unknown_91c_;
                result->unknown_38_.unknown_934_ = src->unknown_934_;
                result->unknown_38_.unknown_94c_ = src->unknown_94c_;
                result->unknown_38_.level_ = src->level_;
                result->unknown_38_.unknown_954_ = src->unknown_954_;
                result->unknown_38_.unknown_956_ = src->unknown_956_;
                result->unknown_38_.unknown_958_ = src->unknown_958_;
                result->unknown_38_.unknown_95a_ = src->unknown_95a_;
                result->unknown_38_.unknown_95c_ = src->unknown_95c_;
                result->unknown_38_.unknown_95e_ = src->unknown_95e_;
                result->unknown_38_.unknown_960_ = src->unknown_960_;
                result->unknown_38_.unknown_962_ = src->unknown_962_;
                strcpy(result->name_, c->name_);
                result++;
                _ZZ21inline_ov023_021f4c04vE1s.work_->unknown_2798_++;
            }
        }
    }
    _ZZ21inline_ov023_021f4c04vE1s.work_->regionResult_ = GameState_GetPartyOrder((char*)game, _ZZ21inline_ov023_021f4c04vE1s.work_->region_);

    if (self->info_->special_ == 0)
        _ZZ21inline_ov023_021f4c04vE1s.work_->unknown_10_ = func_ov023_021f5150(self, self->info_, self->experience_, &self->unknown_5768_, 0) ? 1 : 0;

    if (LinkSession_IsGuest(mode) && self->info_->type_ == 0x13)
        func_020e39d4(func_020e3808(), 0, 1, 0x71e8);
    return 2;
}
