#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define func_020a0644 func_020a23bc
#endif

struct Struct_ov000_021554f4_5 {
    signed int attack : 3;
    signed int unknown_0_3_ : 3;
    signed int agility : 3;
    signed int charm : 3;
    signed int unknown_1_4_ : 3;
    signed int unknown_1_7_ : 3;
    signed int other : 3;
};

struct Struct_ov000_021554f4_9 {
    unsigned short a : 2;
    unsigned short b : 4;
    unsigned short c : 3;
    unsigned short d : 3;
};

struct Struct_ov000_021554f4_10 {
    unsigned char kind : 4;
    unsigned char rank : 4;
};

struct Struct_ov000_021554f4_11 {
    unsigned int lo;
    unsigned int hi;
};

struct Struct_ov000_021554f4_12 {
    unsigned short unknown_0_;
    char pad2[0x14 - 0x2];
    Struct_ov000_021554f4_11 status;
    char unknown_1c_[0x21 - 0x1c];
    unsigned char kind;
    Struct_ov000_021554f4_9 slots;
    unsigned char rank;
    char unknown_25_[0x2e - 0x25];
    short party;
    char unknown_30_[0x58 - 0x30];
    Struct_ov000_021554f4_5 unknown_58_;

    unsigned short inline_ov000_021554f4() { return slots.a; }
    unsigned short inline_ov000_021554f4_2() { return slots.b; }
    unsigned short inline_ov000_021554f4_3() { return slots.c; }
    unsigned short inline_ov000_021554f4_4() { return slots.d; }
    unsigned char inline_ov000_021554f4_5() { return kind; }
    unsigned char inline_ov000_021554f4_6() { return rank; }
};

struct Struct_ov000_021554f4 {
    char pad0[8];
    short id;
};

struct Struct_ov000_021554f4_2 {
    char pad0[0x138];
    Struct_ov000_021554f4_12* stats;
    char unknown_13c_[0x144 - 0x13c];
    Struct_ov000_021554f4* opt;
    char unknown_148_[0x181 - 0x148];
    unsigned char unknown_181_;
    unsigned char unknown_182_;

    Struct_ov000_021554f4_12* inline_ov000_021554f4_7() { return stats; }
};

struct Struct_ov000_021554f4_3 {
    Struct_ov000_021554f4_11 status[2];
    short unknown_10_;
    short target;
    unsigned short code;
    short turn;
    Struct_ov000_021554f4_9 slots[2];
    Struct_ov000_021554f4_10 kinds[2];
    unsigned char flags;
    unsigned char arg;
    float ratio;
    unsigned char sub;
    unsigned char unknown_25_;
    unsigned char unknown_26_;
    Struct_ov000_021554f4_5 unknown_28_[2];
    unsigned short values[8];
};

struct Struct_ov000_021554f4_4 {
    char pad0[0x24];
    unsigned char a;
    unsigned char b;
};

struct Struct_ov000_021554f4_6 {
    char pad0[0x5c60];
    Struct_ov000_021554f4_3 entries[16];
    char unknown_6060_[0x8e04 - 0x6060];
    short curId;
    signed char unknown_8e06_;
    unsigned char count;
    char unknown_8e08_[0x8e18 - 0x8e08];
    Struct_ov000_021554f4_4* info;
    char unknown_8e1c_[4];
    int turn;
};

struct Struct_ov000_021554f4_7 {
    char pad0[4];
    unsigned int code : 12;
    unsigned int rest : 20;
};

struct Struct_ov000_021554f4_8 {
    char pad0[8];
    unsigned int lo : 4;
    unsigned int sub : 5;
};

struct ArrayContainsByteStruct;
struct Struct_02054000;
struct Struct_02052df8;

extern "C" Struct_ov000_021554f4_2* func_0200fea4(GameState*, int);
extern "C" int func_ov000_02155154(GameObject*);
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
extern "C" float func_ov000_02155a04(char*);
extern "C" Struct_ov000_021554f4_8* func_02054000(Struct_02054000*);
extern "C" unsigned short func_02052df8(Struct_02052df8*, int);
struct Struct_020a0840;
struct Struct_020a02d0;
struct S_a0644;
extern "C" void func_020a0840(Struct_020a0840*, unsigned int);
extern "C" void func_020a02d0(Struct_020a02d0*, unsigned int);
extern "C" void func_020a0644(S_a0644*, unsigned int);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int func_020ac494(void*);

extern const signed char data_ov000_02182a7c[9];

static inline int inline_ov000_021554f4_8(int id) { return id >= 0 && id <= 3; }

// USA: func_ov000_021554f4
extern "C" ARM void func_ov000_021554f4(Struct_ov000_021554f4_6* self, int id, int other, Struct_ov000_021554f4_7* rec, unsigned char arg, int flags) {
    GameState* gs = GameState::GetInstance();
    ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance());
    Struct_ov000_021554f4_2* c = func_0200fea4(gs, id);
    if (!c) return;
    if (c->inline_ov000_021554f4_7()->unknown_0_ == 0 && flags == 8) {
        int idx = self->unknown_8e06_;
        if (idx < 0) return;
        if (self->curId == id) self->entries[idx].flags = flags;
        return;
    }
    if (c->opt && c->opt->id == 0xf5 && func_ov000_02155154((GameObject*)c)
        && func_02086ef0(party, c->inline_ov000_021554f4_7()->party)) {
        if (!(func_ov000_02155154((GameObject*)c) && c->unknown_181_) && c->unknown_182_
            && func_02086ef0(party, other)) {
            Struct_ov000_021554f4_2* t = (Struct_ov000_021554f4_2*)GameState::GetInstance()->GetCombatantByIndex(other);
            if (t && t->inline_ov000_021554f4_7()->unknown_58_.charm == 2) func_ov000_0215a8d4((unsigned char*)self, 8);
        }
    }
    self->curId = -1;
    self->unknown_8e06_ = -1;
    if (self->count >= 16) return;
    if (inline_ov000_021554f4_8(id)) return;
    self->curId = id;
    self->unknown_8e06_ = self->count;
    Struct_ov000_021554f4_3* e;
    Struct_ov000_021554f4* opt = c->opt;
    Struct_ov000_021554f4_2* t = (Struct_ov000_021554f4_2*)GameState::GetInstance()->GetCombatantByIndex(other);
    e = &self->entries[self->count++];
    memset(e, 0, sizeof(*e));
    unsigned int hi = c->inline_ov000_021554f4_7()->status.hi;
    if (c->unknown_181_) hi &= ~0x1000;
    e->status[0].lo = c->inline_ov000_021554f4_7()->status.lo;
    e->status[0].hi = hi;
    e->slots[0].a = c->inline_ov000_021554f4_7()->inline_ov000_021554f4();
    e->slots[0].b = c->inline_ov000_021554f4_7()->inline_ov000_021554f4_2();
    e->slots[0].c = c->inline_ov000_021554f4_7()->inline_ov000_021554f4_3();
    e->kinds[0].kind = c->inline_ov000_021554f4_7()->inline_ov000_021554f4_5();
    e->kinds[0].rank = c->inline_ov000_021554f4_7()->inline_ov000_021554f4_6();
    e->slots[0].d = c->inline_ov000_021554f4_7()->inline_ov000_021554f4_4();
    e->unknown_28_[0] = c->inline_ov000_021554f4_7()->unknown_58_;
    e->status[1].lo = t->inline_ov000_021554f4_7()->status.lo;
    e->status[1].hi = t->inline_ov000_021554f4_7()->status.hi;
    e->slots[1].a = t->inline_ov000_021554f4_7()->inline_ov000_021554f4();
    e->slots[1].b = t->inline_ov000_021554f4_7()->inline_ov000_021554f4_2();
    e->slots[1].c = t->inline_ov000_021554f4_7()->inline_ov000_021554f4_3();
    e->kinds[1].kind = t->inline_ov000_021554f4_7()->inline_ov000_021554f4_5();
    e->kinds[1].rank = t->inline_ov000_021554f4_7()->inline_ov000_021554f4_6();
    e->slots[1].d = t->inline_ov000_021554f4_7()->inline_ov000_021554f4_4();
    e->unknown_28_[1] = t->inline_ov000_021554f4_7()->unknown_58_;
    e->unknown_10_ = opt->id;
    e->target = other;
    e->flags = flags;
    e->arg = arg;
    e->turn = self->turn;
    e->ratio = func_ov000_02155a04((char*)c);
    e->sub = 0;
    e->unknown_25_ = self->info->a;
    e->unknown_26_ = self->info->b;
    if (rec) e->code = rec->code;
    if (inline_ov000_021554f4_8(other)) {
        GameObject* p = func_0200ff1c(gs, other);
        if (!p) return;
        Struct_ov000_021554f4_8* var10 = func_02054000((Struct_02054000*)p);
        if (var10) e->sub = var10->sub;
        for (int i = 0; data_ov000_02182a7c[i] != -1; i++)
            e->values[i] = func_02052df8((Struct_02052df8*)p, data_ov000_02182a7c[i]);
    }
    if (!func_02086ef0(party, other)) return;
    if (flags & 1) return;
    if (flags & 2) return;
    if (flags & 4) return;
    if (flags & 0x10) return;
    if (flags & 0x20) return;
    Struct_02061c04 snap;
    func_020ac4c0(&snap);
    func_020a0840((Struct_020a0840*)&snap, 1);
    func_020a02d0((Struct_020a02d0*)&snap.unknown_68_, 1);
    if (other == GameState_GetProtagonistIndex(gs)) func_020a0644((S_a0644*)&snap, 1);
    func_020ac494(&snap);
}
