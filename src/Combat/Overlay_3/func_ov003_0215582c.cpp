#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct ItemTable;
struct Struct_0207c484;
struct Field150Holder02052e14;
struct Field150Holder02052e2c;
struct Struct_020a06ec;
struct Struct_020a0258;

struct Struct_ov003_0215582c_8 {
    char pad0[8];
    unsigned int kind : 4;
    unsigned int rest : 28;
    char unknown_c_[0x18 - 0xc];
    short itemId;
    char pad1a[0x20 - 0x1a];
};

struct Struct_ov003_0215582c_9 {
    unsigned int f0;
    unsigned int : 27;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int keep : 1;
    unsigned int : 2;
};

struct ItemEntry0215582c {
    struct Struct_ov003_0215582c_9* data;
};

struct Struct_ov003_0215582c_11 {
    int f0[10];
    short id;
    short pad2a;
};

struct Struct_ov003_0215582c_12 {
    char pad0[0x194];
    struct Struct_ov003_0215582c_8 slots[1];
    char unknown_1b4_[0x49c - 0x1b4];
    unsigned char female : 1;
    unsigned char : 7;
#if defined(jpn)
    char unknown_49d_[0x8b8 - 0x49d];
#else
    char unknown1_49d_[0x950 - 0x49d];
#endif
    int unknown_950_;
};

struct Struct_ov003_0215582c {
    char pad0[0x2f4];
    struct Struct_ov003_0215582c_11 equip[8];
    char unknown_454_[0x4a4 - 0x454];
    short unknown_4a4_[12][8];
};

struct Struct_ov003_0215582c_2 {
    char pad0[4];
    unsigned short hp;
    unsigned short mp;
};

struct Struct_ov003_0215582c_3 {
    char pad0[0x30];
    unsigned short maxHp;
    unsigned short maxMp;
};

struct Struct_ov003_0215582c_4 {
    char pad0[4];
    short id;
    char pad6[0x130 - 6];
    struct Struct_ov003_0215582c_2* unknown_130_;
    struct Struct_ov003_0215582c_3* baseStats;
#if defined(jpn)
    char unknown_138_[0x144 - 0x138];
#else
    char unknown1_138_[0x150 - 0x138];
#endif
    struct Struct_ov003_0215582c_12* data;
};

struct Struct_ov003_0215582c_5 {
    char pad0[0x90];
    char f90[0xcc - 0x90];
#if defined(jpn)
    char fcc[0x174 - 0xcc];
#else
    char fcc[0x178 - 0xcc];
#endif
    char list[0x1f7 - 0x178];
    signed char combatantId;
    char pad1f8[0x1fc - 0x1f8];
    int flags;
    char unknown_200_[0x330 - 0x200];
    float hpRatio;
    float unknown_334_;
};

struct Struct_ov003_0215582c_6 {
    int f0;
    int : 19;
    int id : 11;
    int : 2;
};

struct Party0215582c {
    char pad0[0x1d4];
    char bag[1];
};

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" struct Struct_ov003_0215582c* func_02053c6c(unsigned char* obj);
extern "C" int func_ov003_02155e14(int base, int idx);
extern "C" short* func_02052e14(struct Field150Holder02052e14* obj);
extern "C" int func_0207c378(void* obj, int value, int amount, int key);
extern "C" int func_ov003_02156034(void* obj);
extern "C" void PartyMember_SetVocation(unsigned char* obj, int index);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int func_020ac4c0(void* dst);
extern "C" void func_020a06ec(struct Struct_020a06ec* p, unsigned int amount);
extern "C" void func_020a0258(struct Struct_020a0258* p, unsigned int amount);
extern "C" int func_020ac494(void* src);
extern "C" int func_0207c7a0(void* map, int value, int key);
extern "C" struct ItemEntry0215582c* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void func_02052d7c(void* obj, int index, int value);
extern "C" int func_0207c484(struct Struct_0207c484* obj, int value, int amount, int key);
extern "C" short* func_02052e2c(struct Field150Holder02052e2c* obj);
extern "C" void func_02083738(void* o, int a1);
extern "C" void PartyMember_ApplyLevelStats(void* a, void* obj, void* tail);
extern "C" void PartyMember_LearnSpell(unsigned char* obj, int index);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void func_ov017_0218f5a4(void* self, int combatantId, int flag2, int arg3, int flag4);

extern const unsigned char data_ov003_0217f2c4[];
extern const unsigned char data_ov003_0217f2b4[];
extern const unsigned char data_ov003_0217f2bc[];

static inline int inline_ov003_0215582c(unsigned int kind) {
    return kind <= 7;
}

// USA: func_ov003_0215582c
extern "C" ARM void func_ov003_0215582c(struct Struct_ov003_0215582c_5* self) {
    GameState* gs = GameState::GetInstance();
    struct Party0215582c* party = (struct Party0215582c*)GameState_GetParty(gs);
    struct Struct_ov003_0215582c_4* c = (struct Struct_ov003_0215582c_4*)gs->GetPartyMemberByIndex(self->combatantId);
    if (c == NULL) {
        return;
    }
    struct Struct_ov003_0215582c* stats = func_02053c6c((unsigned char*)c);
    if (stats == NULL) {
        return;
    }

    short (*var4)[8] = stats->unknown_4a4_;
    int value;
    if (self->flags & 1) {
        value = c->baseStats->maxHp;
        int hp = c->unknown_130_->hp;
        self->hpRatio = (float)hp / (float)value;
        value = c->baseStats->maxMp;
        int mp = c->unknown_130_->mp;
        self->unknown_334_ = (float)mp / (float)value;
    }

    short* set = (short*)func_ov003_02155e14((int)var4, c->data->unknown_950_);
    short* equipped = func_02052e14((struct Field150Holder02052e14*)c);
    if (set != NULL && equipped != NULL) {
        set[0] = equipped[7];
        set[1] = equipped[0];
        set[2] = equipped[8];
        set[3] = equipped[6];
        set[4] = equipped[4];
        set[5] = equipped[1];
        set[6] = equipped[5];
        set[7] = equipped[9];
    }

    for (unsigned short i = 0; data_ov003_0217f2c4[i] != 0xff; i++) {
        struct Struct_ov003_0215582c_8* slot = &c->data->slots[data_ov003_0217f2c4[i]];
        if (slot != NULL && inline_ov003_0215582c(slot->kind)) {
            func_0207c378(party->bag, slot->itemId, 1, slot->kind);
        }
    }

    PartyMember_SetVocation((unsigned char*)stats, func_ov003_02156034(self));

    value = GameState_GetProtagonistIndex(gs);
    if (value == c->id) {
        GameState* g = GameState::GetInstance();
#if defined(jpn)
        struct Struct_ov003_0215582c_6* w = (struct Struct_ov003_0215582c_6*)((char*)g + 0x3c + 0x5400);
#else
        struct Struct_ov003_0215582c_6* w = (struct Struct_ov003_0215582c_6*)((char*)g + 0x29c + 0x5400);
#endif
        short id = w->id;
        if (id >= 700 && id < 800) {
            struct Struct_ov003_0215582c_4* hero = (struct Struct_ov003_0215582c_4*)g->GetProtagonist();
            int var16 = hero->data->unknown_950_;
#if defined(jpn)
            w->id = var16 + 700;
#else
            int base = 20700;
            if (hero->data->female == 1) {
                base += 50;
            }
            w->id = base - 20000 + var16;
#endif
        }
        int buf[0x2c];
        func_020ac4c0(buf);
        func_020a06ec((struct Struct_020a06ec*)buf, 1);
        func_020a0258((struct Struct_020a0258*)(buf + 0x1a), 1);
        func_020ac494(buf);
    }

    int unchanged = 0;
    set = (short*)func_ov003_02155e14((int)var4, func_ov003_02156034(self));
    if (set != NULL) {
        if (set[0] == equipped[7] && set[1] == equipped[0] && set[2] == equipped[8] && set[3] == equipped[6] &&
            set[4] == equipped[4] && set[5] == equipped[1] && set[6] == equipped[5] && set[7] == equipped[9]) {
            unchanged = 1;
        }
    }

    if (set[7] == 0x4680 && func_0207c7a0(party->bag, 0x4680, 7) == 0) {
        bool var20[2];
        for (int i = 0; i < 7; i++) {
            struct ItemEntry0215582c* e = ItemTable_Find((struct ItemTable*)self->list, set[i]);
            struct Struct_ov003_0215582c_9* d;
            if (e != NULL && (d = e->data) != NULL) {
                var20[0] = d->unknown_7_3_;
                var20[1] = d->unknown_7_4_;
                if (var20[c->data->female] == 0) {
                    if (d->keep == 0) {
                        set[i] = -1;
                    }
                }
            }
        }
    }

    for (unsigned char k = 0; k < 8; k++) {
        int used = 0;
        int item = set[k];
        int kind = data_ov003_0217f2b4[k];
        if (item > 0 && func_0207c7a0(party->bag, item, kind) >= 1) {
            if (data_ov003_0217f2bc[k] != 0xff) {
                func_02052d7c(c, data_ov003_0217f2bc[k], item);
            }
            func_0207c484((struct Struct_0207c484*)party->bag, item, 1, kind);
            used = 1;
            if (data_ov003_0217f2bc[k] == 4) {
                short* p = func_02052e2c((struct Field150Holder02052e2c*)c);
                p[0xb] = -1;
                if (equipped[0] > 0) {
                    p[0xb] = equipped[0] % 1000 + 14000;
                }
            }
        }
        if (used == 0) {
            if (data_ov003_0217f2bc[k] != 0xff) {
                if (data_ov003_0217f2bc[k] == 0) {
                    func_02052e2c((struct Field150Holder02052e2c*)c)[0xb] = -1;
                }
                if (data_ov003_0217f2bc[k] == 4) {
                    short* p = func_02052e2c((struct Field150Holder02052e2c*)c);
                    p[0xb] = -1;
                    if (equipped[0] > 0) {
                        p[0xb] = equipped[0] % 1000 + 14000;
                    }
                }
                if (equipped[data_ov003_0217f2bc[k]] != -1) {
                    struct Struct_ov003_0215582c* s = func_02053c6c((unsigned char*)c);
                    func_02083738(s, kind);
                    s->equip[k].f0[0] = 0;
                    s->equip[k].f0[1] = 0;
                    s->equip[k].f0[2] = 0;
                    s->equip[k].f0[3] = 0;
                    s->equip[k].f0[4] = 0;
                    s->equip[k].f0[5] = 0;
                    s->equip[k].f0[6] = 0;
                    s->equip[k].f0[7] = 0;
                    s->equip[k].f0[8] = 0;
                    s->equip[k].f0[9] = 0;
                    s->equip[k].id = -1;
                }
                func_02052d7c(c, data_ov003_0217f2bc[k], -1);
            }
        }
    }

    PartyMember_ApplyLevelStats(stats, self->f90, self->fcc);
    switch (func_ov003_02156034(self)) {
    case 2:
        PartyMember_LearnSpell((unsigned char*)stats, 0x1a);
        break;
    case 3:
        PartyMember_LearnSpell((unsigned char*)stats, 0);
        break;
    }

    if (unchanged == 0) {
        GameResources* var31 = GetGameResources();
        LinkSession_GetInstance();
        func_ov017_0218f5a4(var31, self->combatantId, 1, 0, 0);
    }
}
