#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov024_021e4c04_336 = 0x144 };
#else
enum { Enum_ov024_021e4c04_336 = 0x150 };
#endif

#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_ov024_021e4c04_3 {
    unsigned char unknown_0_[0x8e02];
    unsigned char unknown_8e02_;
};
struct Struct_ov024_021e4c04_4 {
    int value0;
    int unknown_4_;
    char pad8[0x18 - 0x8];
    unsigned char unknown_18_;
    unsigned char unknown_19_;
    char pad1a[0x1c - 0x1a];
    unsigned char unused : 7;
    unsigned char forced : 1;
};
struct Struct_ov024_021e4c04_5 {
    char pad0[0xc];
    Struct_ov024_021e4c04_4* action;
    Struct_ov024_021e4c04_3* battle;
};
struct Struct_ov024_021e4c04_6 {
    char pad0[0x10];
    unsigned int flags;
};
struct Struct_ov024_021e4c04_7 {
    unsigned short hp;
    char pad2[0x22 - 0x2];
    unsigned short unknown_22_0_ : 2;
    unsigned short kind : 4;
    unsigned short code : 3;
    unsigned short rest : 7;
    unsigned char count;
    char unknown_25_[0x46 - 0x25];
    unsigned char unknown_46_;
    unsigned char unknown_47_;
    unsigned char unknown_48_;
    unsigned char unknown_49_;
    unsigned char unknown_4a_;
    unsigned char unknown_4b_;
    unsigned char unknown_4c_;
    unsigned char unknown_4d_;
    unsigned char unknown_4e_;
    unsigned char unknown_4f_;
    unsigned char unknown_50_;
};
struct Struct_ov024_021e4c04 {
    char pad0[Enum_ov024_021e4c04_336];
    unsigned char* unknown_150_;
};
union Struct_ov024_021e4c04_2 { struct { int low; int high; }; unsigned long long value; };

struct Struct_ov024_021da670_6;
struct Struct_ov024_021dd028_5;
struct Struct_ov024_021e4604;
struct Struct_ov024_021dced0_2;
struct Struct_02088418;
struct Struct_02087860;
struct Struct_ov024_021dbd84_6;
struct Struct_ov024_021dd828;
struct Struct_ov024_021dbaf4_4;
struct Struct_ov024_021ddc80_4;

extern "C" int func_020851ac(unsigned char*);
extern "C" int func_02085644(unsigned char*);
extern "C" int func_02085670(unsigned char*);
extern "C" int func_0208569c(unsigned char*);
extern "C" int func_020856c8(unsigned char*);
extern "C" int func_020856f4(unsigned char*);
extern "C" int func_02085720(unsigned char*);
extern "C" int func_02085768(unsigned char*);
extern "C" int func_02085794(unsigned char*);
extern "C" int func_020857c0(unsigned char*);
extern "C" int func_020857ec(unsigned char*);
extern "C" short func_ov024_021da998(Struct_ov024_021da670_6*);
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" int func_ov024_021e47dc(Struct_ov024_021e4604*);
extern "C" int func_ov024_021dd010(Struct_ov024_021dced0_2*);
extern "C" void func_02087704(void*);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" int func_02088840(unsigned char*);
extern "C" int func_0208830c(unsigned char*);
extern "C" int func_020883ac(unsigned char*);
extern "C" int func_02088540(unsigned char*);
extern "C" int func_0208824c(unsigned char*);
extern "C" void func_02088854(unsigned char*);
extern "C" void func_02088338(unsigned char*);
extern "C" void func_02088b34(unsigned char*);
extern "C" void func_020883cc(unsigned char*);
extern "C" void func_020888a4(unsigned char*);
extern "C" int func_02088418(Struct_02088418*, int, int);
extern "C" void func_02088474(void*, int, int);
extern "C" void func_02088560(unsigned char*);
extern "C" void func_0208826c(unsigned char*);
extern "C" int func_0208776c(void*, int);
extern "C" int func_02087860(Struct_02087860*, unsigned char);
void UpdateCombatantAttack(int, int);
void UpdateCombatantDefense(int, int);
extern "C" int func_ov024_021e929c(Struct_ov024_021dbd84_6*, int, int);
extern "C" int func_ov024_021e9320(Struct_ov024_021dd828*, int, int);
extern "C" int func_ov024_021e939c(Struct_ov024_021dbaf4_4*, int, int, int);
extern "C" int func_ov024_021e9464(Struct_ov024_021ddc80_4*, int, int);
extern "C" void func_ov000_0215ffc4(void*, void*, int);
struct Struct_ov024_021da9e0_4;
extern "C" void func_ov024_021eb4e4(Struct_ov024_021da9e0_4*, int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_02159eac(void*, void*, int);
extern "C" int func_ov000_02156068(void*, int, int, int);
extern "C" void func_ov000_0215a004(void*, int, int, int, void*, Struct_ov024_021e4c04_6*, int, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, unsigned long long, int);
extern "C" int func_ov024_021e9198(Struct_ov024_021e4c04_5*, int, int, int);
extern "C" int func_020877c0(void*, int);
extern "C" int func_020878b4(void*, int);
extern "C" int func_ov024_021e94c4(Struct_ov024_021e4c04_5*, int, Struct_ov024_021e4c04_6*, int, signed char, unsigned char, unsigned char);
extern "C" int func_ov024_021e95d4(Struct_ov024_021e4c04_5*, int, Struct_ov024_021e4c04_6*, int, signed char, unsigned char, unsigned char);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

static inline Struct_ov024_021e4c04_7* inline_ov000_0215a908_5(GameObject* c) {
    return (Struct_ov024_021e4c04_7*)c->currentStats_;
}

static inline unsigned short inline_ov000_0215a908_2(GameObject* c) { SDK_NULL_ASSERT(c); return inline_ov000_0215a908_5(c)->hp; }

// USA: func_ov024_021e4c04
extern "C" ARM void func_ov024_021e4c04(Struct_ov024_021e4c04_5* self, int arg1, int targetId, Struct_ov024_021e4c04_6* rec, int amount) {
    GameState* gs = GameState::GetInstance();
    GameObject* target = GetCombatantByID((int)self->battle, targetId);
    if (!target) return;
    void* entry = func_ov000_0215e958(self->battle);
    if (!entry) return;
    short special;
    float var4;
    int count;
    int any = 0;
    int msg = 0;
    Struct_ov024_021e4c04_2 effects;
    effects.low = 0;
    effects.high = 0;
    special = 0;
    int roll = NextRandomMax((Random*)self->battle, 100);
    if (rec->flags & 0x80000) {
        if (!IsPartyMember(arg1)) return;
        Struct_ov024_021e4c04* attacker = (Struct_ov024_021e4c04*)func_0200ff1c(gs, arg1);
        if (!attacker) return;

        if (func_020851ac(attacker->unknown_150_)
            && (func_ov024_021da998((Struct_ov024_021da670_6*)target) || func_ov024_021dd260((Struct_ov024_021dd028_5*)target))) {
            func_02087704(target->currentStats_);
            count = inline_ov000_0215a908_5(target)->count;
            switch (count) {
            case 0: msg = 0x17f; break;
            case 1: msg = 0x180; break;
            case 2: msg = 0x181; break;
            case 3: msg = 0x259; break;
            }
            func_ov000_02159eac(self->battle, &effects, 0x1d);
            if (count == 3) func_ov000_02159eac(self->battle, &effects, 8);
            func_ov000_0215a88c(self->battle, entry, msg);
            any = 1;
        }

        if (func_02085644(attacker->unknown_150_)
            && func_02088840((unsigned char*)target->currentStats_)
            && (int)inline_ov000_0215a908_5(target)->unknown_46_ > 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 20.0f)) {
                int msg = func_ov024_021e9198(self, targetId, 1, 1);
                if (!msg) msg = 0x25;
                func_ov000_0215a88c(self->battle, entry, msg);
                any = 1;
                func_02088854((unsigned char*)target->currentStats_);
                inline_ov000_0215a908_5(target)->code = 1;
            }
        }

        if (func_02085670(attacker->unknown_150_)
            && func_0208830c((unsigned char*)target->currentStats_)
            && (int)inline_ov000_0215a908_5(target)->unknown_47_ > 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 20.5f)) {
                special = func_ov024_021da998((Struct_ov024_021da670_6*)target);
                int msg = func_ov024_021e929c((Struct_ov024_021dbd84_6*)self, targetId, 1);
                func_ov000_0215a88c(self->battle, entry, msg);
                any = 1;
                func_02088338((unsigned char*)target->currentStats_);
            }
        }

        if (func_0208569c(attacker->unknown_150_)) {
            var4 = 10.5f;
            if (func_ov000_02156068(self->battle, targetId, 0, 1) == 0 && inline_ov000_0215a908_5(target)->unknown_48_ == 0) var4 = 0.0f;
            if ((float)roll < var4) {
                GameObject* victim = GetCombatantByID((int)self->battle, targetId);
                if (func_ov024_021e47dc((Struct_ov024_021e4604*)victim)) {
                    func_ov000_02159eac(self->battle, &effects, 0x29);
                    func_02088b34((unsigned char*)victim->currentStats_);
                    func_ov000_0215a004(self->battle, arg1, targetId, inline_ov000_0215a908_2(victim) - 1, &effects, rec, self->action->forced != 0, 0);
                    func_ov000_0215a88c(self->battle, entry, 200);
                } else {
                    func_ov000_0215a004(self->battle, arg1, targetId, 0xffff, &effects, rec, self->action->forced != 0, 8);
                    effects.low = 0;
                    effects.high = 0;
                    func_ov000_02159eac(self->battle, &effects, 0xd);
                    func_ov000_0215a88c(self->battle, entry, 0x257);
                }
                self->action->value0 = 0;
                self->action->unknown_18_ = 0;
                self->action->unknown_4_ = 0;
                self->action->unknown_19_ = 0;
                any = 1;
            }
        }

        if (func_020856c8(attacker->unknown_150_)
            && func_020883ac((unsigned char*)target->currentStats_)
            && inline_ov000_0215a908_5(target)->unknown_4a_ != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 10.5f)) {
                int msg = func_ov024_021e9320((Struct_ov024_021dd828*)self, targetId, 1);
                func_ov000_0215a88c(self->battle, entry, msg);
                any = 1;
                func_020883cc((unsigned char*)target->currentStats_);
            }
        }

        if (func_020856f4(attacker->unknown_150_)
            && func_ov024_021dd010((Struct_ov024_021dced0_2*)target)
            && inline_ov000_0215a908_5(target)->unknown_4b_ != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 25.0f)) {
                int msg = 0x18;
                if (func_ov024_021dd010((Struct_ov024_021dced0_2*)target)) msg = 0x1a;
                func_ov000_0215a88c(self->battle, entry, msg);
                any = 1;
                func_020888a4((unsigned char*)target->currentStats_);
            }
        }

        if (func_02085720(attacker->unknown_150_)
            && func_02088418((Struct_02088418*)target->currentStats_, 5, 0)
            && inline_ov000_0215a908_5(target)->unknown_4c_ != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 12.5f)) {
                special = func_ov024_021da998((Struct_ov024_021da670_6*)target);
                int msg = 0x5e;
                if (inline_ov000_0215a908_5(target)->kind == 5) msg = 0x60;
                func_ov000_0215a88c(self->battle, entry, msg);
                any = 1;
                func_02088474(target->currentStats_, 5, 0);
            }
        }

        if (func_02085768(attacker->unknown_150_)
            && func_02088540((unsigned char*)target->currentStats_)
            && inline_ov000_0215a908_5(target)->unknown_4d_ != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 12.5f)) {
                int msg = func_ov024_021e939c((Struct_ov024_021dbaf4_4*)self, targetId, 1, 1);
                func_ov000_0215a88c(self->battle, entry, msg);
                any = 1;
                func_02088560((unsigned char*)target->currentStats_);
            }
        }

        if (func_02085794(attacker->unknown_150_)
            && func_0208824c((unsigned char*)target->currentStats_)
            && inline_ov000_0215a908_5(target)->unknown_4e_ != 0) {
            if ((float)roll < (self->action->forced ? 100.0f : 10.0f)) {
                special = func_ov024_021da998((Struct_ov024_021da670_6*)target);
                int msg = func_ov024_021e9464((Struct_ov024_021ddc80_4*)self, targetId, 1);
                func_ov000_0215a88c(self->battle, entry, msg);
                any = 1;
                func_0208826c((unsigned char*)target->currentStats_);
            }
        }

        if (func_020857c0(attacker->unknown_150_)
            && func_0208776c(target->currentStats_, 1)
            && inline_ov000_0215a908_5(target)->unknown_4f_ != 0) {
            var4 = 20.0f;
            if ((float)roll < var4) {
                int result = func_020877c0(target->currentStats_, -1);
                UpdateCombatantAttack((int)self->battle, targetId);
                int msg = func_ov024_021e94c4(self, targetId, rec, 1, (signed char)result, 1, 1);
                func_ov000_0215a88c(self->battle, entry, msg);
                any = 1;
            }
        }

        if (func_020857ec(attacker->unknown_150_)
            && func_02087860((Struct_02087860*)target->currentStats_, 1)
            && inline_ov000_0215a908_5(target)->unknown_50_ != 0) {
            var4 = 20.0f;
            if ((float)roll < var4) {
                int result = func_020878b4(target->currentStats_, -1);
                UpdateCombatantDefense((int)self->battle, targetId);
                int msg = func_ov024_021e95d4(self, targetId, rec, 1, (signed char)result, 1, 1);
                func_ov000_0215a88c(self->battle, entry, msg);
                any = 1;
            }
        }
    }
    if (any) {
        func_ov000_0215cd44(self->battle, entry, target, 0, effects.value, 0);
        func_ov000_0215ffc4(self->action, entry, 2);
        self->battle->unknown_8e02_++;
        func_ov024_021eb4e4((Struct_ov024_021da9e0_4*)self, (int)self->action);
    }
    if (special) {
        void* extra = func_ov000_0215e958(self->battle);
        if (!extra) return;
        func_ov000_0215a88c(self->battle, extra, 0x25c);
        func_ov000_0215ffc4(self->action, extra, 2);
        self->battle->unknown_8e02_++;
        func_ov000_0215cd44(self->battle, extra, target, 0, 0, 0);
    }
}
