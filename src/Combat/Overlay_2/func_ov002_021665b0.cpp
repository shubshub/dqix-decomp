#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_ov002_021665b0_3 {
    int flags;
    unsigned short hp;
    short level;
};

struct Struct_ov002_021665b0_5 {
    char pad0[0x30];
    unsigned short maxHp;
};

struct Struct_ov002_021665b0_7 {
#if defined(jpn)
    char pad0[0x8b8];
#else
    char pad0[0x950];
#endif
    int kind;
};

struct Struct_ov002_021665b0_8 {
    char pad0[0x130];
    Struct_ov002_021665b0_3* status;
    Struct_ov002_021665b0_5* base;
#if defined(jpn)
    char unknown_138_[0x144 - 0x138];
#else
    char unknown1_138_[0x150 - 0x138];
#endif
    Struct_ov002_021665b0_7* ext;
};

struct Struct_ov002_021665b0_9 {
    char pad0[0x78];
    unsigned int : 30;
    unsigned int unknown_7b_6_ : 1;
    unsigned int : 1;
};

struct Struct_ov002_021665b0_10 {
    int unk0;
    int unk4;
    unsigned int power : 8;
    unsigned int : 6;
    unsigned int key : 8;
    unsigned int : 10;
};

struct Struct_ov002_021665b0_11 {
    short value;
    short key;
};

struct Struct_ov002_021665b0 {
    signed char id;
    signed char count;
};

struct Struct_ov002_021665b0_2 {
#if defined(jpn)
    char pad0[0x1a80];
    int unknown_1bb8_;
    int unknown_1bbc_;
    int nextC;
    char pad1bc4[0x1ae8 - 0x1a8c];
    signed char target;
    signed char actor;
    char unknown_1aea_[0x1aee - 0x1aea];
    short unknown_1c26_;
    short unknown_1c28_;
    short unknown_1c2a_;
    char pad1c2c[0x1b14 - 0x1af4];
#else
    char pad0[0x1bb8];
    int unknown_1bb8_;
    int unknown_1bbc_;
    int nextC;
    char pad1bc4[0x1c20 - 0x1bc4];
    signed char target;
    signed char actor;
    char unknown_1c22_[0x1c26 - 0x1c22];
    short unknown_1c26_;
    short unknown_1c28_;
    short unknown_1c2a_;
    char pad1c2c[0x1c50 - 0x1c2c];
#endif
    int count;
    int ids[12];
    char unknown_1c84_[2];
    short maxHp[4];
    short hp[4];
    Struct_ov002_021665b0_11 pairs[5];
    short key;
    signed char turn;
    signed char unknown_1cad_;
    signed char state;
    signed char result;
    signed char unknown_1cb0_;
    unsigned char unknown_1cb1_;
    Struct_ov002_021665b0 order[4];
    signed char unknown_1cba_[4];
    unsigned char unknown_1cbe_[4];
};

struct Struct_ov002_021665b0_4 {
    unsigned short key;
    signed char target;
    signed char unknown_3_;
    signed char actor;
    char pad5[0x3c - 5];
};

struct Struct_ov002_021665b0_6 {
    unsigned short unknown_0_;
    unsigned short id;
};

extern "C" void func_ov002_02157ce0(char*);
extern "C" void func_ov002_0215b814(Struct_ov002_021665b0_2* self);
extern "C" Struct_ov002_021665b0_8* func_0200ff94(GameState* gs, int id);
extern "C" Struct_ov002_021665b0_9* func_02053c6c(unsigned char*);
extern "C" int func_02083bc0(unsigned char*, int);
extern "C" int func_0209ac28(char* obj, Struct_ov002_021665b0_8* unit, int index);
extern "C" Struct_ov002_021665b0_10* func_02079e2c(char*, int);
struct Struct_02048448_2;
extern "C" int func_02048448(Struct_02048448_2*, int);
extern "C" void __clear(void* dst, int size);
extern "C" void func_ov002_021536e0(char** obj);
extern "C" void* func_02079ee0(void*, int);
extern "C" short func_ov002_021538e4(char** obj, Struct_ov002_021665b0_10* elem, void* sub, int target);
extern "C" void func_ov002_021594e8(Struct_ov002_021665b0_2* self, int key, int target, int actor);
extern "C" char* MessageSystem_GetInstance(void);
struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" int func_0205d97c(char* obj);
extern "C" int func_ov002_02161b48(char*, int);
extern "C" void MessageSystem_Reset(char* ctl);
struct Struct_0205def8;
extern "C" void func_0205def8(Struct_0205def8*, int, int);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);

#if defined(jpn)
#define SPELLS_021665b0 0x227c
#define LIST_021665b0 0xe20
#define CTL_FLAG_021665b0 0x17fb
#define NEXT_IDLE_021665b0 0x18
#define NEXT_BACK_021665b0 0x16
#define NEXT_MENU_021665b0 0x2e
#define FLAG_KEY_021665b0 0x2c
#define NEXT_NONE_021665b0 0x29
#else
#define SPELLS_021665b0 0x2444
#define LIST_021665b0 0xec8
#define CTL_FLAG_021665b0 0x19ca
#define NEXT_IDLE_021665b0 0x17
#define NEXT_BACK_021665b0 0x15
#define NEXT_MENU_021665b0 0x2b
#define FLAG_KEY_021665b0 0x29
#define NEXT_NONE_021665b0 0x26
#endif

// USA: func_ov002_021665b0
extern "C" ARM void func_ov002_021665b0(Struct_ov002_021665b0_2* self) {
    GameState* gs = GameState::GetInstance();
    Struct_ov002_021665b0_4 cmd;
    Struct_ov002_021665b0_9* field;
    Struct_ov002_021665b0_8* unit;
    func_ov002_02157ce0((char*)&cmd);
    ActionDataTables* data = func_020797dc();
    signed char n = self->count - 1;
    short* maxHp = self->maxHp;
    short* hp = self->hp;
    signed char* var8 = self->unknown_1cba_;
    unsigned char* var9 = self->unknown_1cbe_;
    signed char state = self->state;
    Struct_ov002_021665b0_8* member;

    if (state == 0) {
        unsigned short var12[4];
        int id;
        func_ov002_0215b814(self);
        self->unknown_1cb1_ = 0;
        self->state = 1;
        self->unknown_1c28_ = -1;
        self->unknown_1c2a_ = -1;
        for (int i = 0; i < 4; i++) {
            maxHp[i] = 0;
            hp[i] = 0;
            var9[i] = 0;
            var8[i] = 0;
            self->order[i].id = -1;
            var12[i] = 0;
            self->order[i].count = -1;
        }
        memset(self->pairs, -1, sizeof(self->pairs));
        int var15 = 0;
        for (int i = 0; i < n; i++) {
            id = self->ids[i];
            unit = func_0200ff94(gs, id);
            if (unit == NULL) {
                continue;
            }
            member = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, id);
            if (member == NULL) {
                continue;
            }
            field = func_02053c6c((unsigned char*)member);
            if (field == NULL) {
                continue;
            }
            maxHp[id] = member->base->maxHp;
            hp[id] = member->status->hp;
            var12[id] = maxHp[id] - hp[id];
            if (unit->status->flags & 2) {
                var9[id] = 1;
            }
            if (unit->status->flags & 1) {
                continue;
            }
            for (int k = 0x1a; k < 0x1f; k++) {
                if (func_02083bc0((unsigned char*)field, k) && func_0209ac28((char*)self + SPELLS_021665b0, member, k)) {
                    if (member->status->level >= 2) {
                        var8[id]++;
                    }
                }
            }
        }
        int found = 0;
        for (int i = 0; i < n; i++) {
            id = self->ids[i];
            if ((Struct_ov002_021665b0_8*)func_0200ff1c(gs, id) == NULL) {
                continue;
            }
            unit = func_0200ff94(gs, id);
            if (unit == NULL) {
                continue;
            }
            if (unit->status->flags & 1) {
                continue;
            }
            if (var12[id] != 0) {
                for (int j = 0; j < n; j++) {
                    int other = self->ids[j];
                    if ((Struct_ov002_021665b0_8*)func_0200ff1c(gs, other) != NULL && hp[other] > 0 && var8[other] > 0) {
                        found = 1;
                        break;
                    }
                }
            }
            if (var9[id] != 0) {
                for (int j = 0; j < n; j++) {
                    int other = self->ids[j];
                    Struct_ov002_021665b0_8* member = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, other);
                    if (member == NULL) {
                        continue;
                    }
                    Struct_ov002_021665b0_9* field = func_02053c6c((unsigned char*)member);
                    if (field == NULL) {
                        continue;
                    }
                    if (hp[other] <= 0) {
                        continue;
                    }
                    if (!func_02083bc0((unsigned char*)field, 0x20)) {
                        continue;
                    }
                    Struct_ov002_021665b0_8* caster = func_0200ff94(gs, other);
                    if (func_02048448((Struct_02048448_2*)caster, (unsigned short)func_02079e2c((char*)data, (short)0x23)->power)) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            var15 = 1;
        }
        if (!var15) {
            self->state = 5;
            self->result = 2;
        }
    } else if (state == 1) {
        Struct_ov002_021665b0_6 slots[4];
        Struct_ov002_021665b0_6 var28[4];
        self->state = 2;
        __clear(slots, sizeof(slots));
        __clear(var28, sizeof(var28));
        Struct_ov002_021665b0_6* slot;
        for (int i = 0; i < n; i++) {
            int id = self->ids[i];
            slot = &slots[i];
            slot->id = id;
            Struct_ov002_021665b0_8* unit = func_0200ff94(gs, id);
            if (unit == NULL) {
                continue;
            }
            member = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, id);
            if (member == NULL) {
                continue;
            }
            field = func_02053c6c((unsigned char*)member);
            if (field == NULL) {
                continue;
            }
            unsigned char kind = member->ext->kind;
            if (unit->status->flags & 1) {
                continue;
            }
            int var34 = 0;
            switch (kind) {
            case 2:
                slot->unknown_0_ += 10;
                break;
            case 10:
                slot->unknown_0_ += 8;
                break;
            case 6:
            case 9:
            case 11:
                slot->unknown_0_ += 5;
                break;
            case 5:
            case 12:
                slot->unknown_0_ += 3;
                break;
            default:
                var34 = 1;
                break;
            }
            if (var34) {
                continue;
            }
            if ((unsigned short)field->unknown_7b_6_) {
                slot->unknown_0_ += 5;
            }
            slot->unknown_0_ = slot->unknown_0_ + var8[id] * 4;
            if (func_02083bc0((unsigned char*)field, 0x1f)) {
                if (func_0209ac28((char*)self + SPELLS_021665b0, member, 0x1f)) {
                    slot->unknown_0_ += 200;
                }
            } else if (func_02083bc0((unsigned char*)field, 0x1e)) {
                if (func_0209ac28((char*)self + SPELLS_021665b0, member, 0x1e)) {
                    slot->unknown_0_ += 100;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j > i; j--) {
                unsigned short prev = slots[j - 1].unknown_0_;
                unsigned short cur = slots[j].unknown_0_;
                if (cur > prev) {
                    unsigned char id = slots[j].id;
                    slots[j].unknown_0_ = prev;
                    slots[j].id = slots[j - 1].id;
                    slots[j - 1].unknown_0_ = cur;
                    slots[j - 1].id = id;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            if (slots[i].unknown_0_ == 0) {
                break;
            }
            unsigned char id = slots[i].id;
            self->order[i].id = id;
            self->order[i].count = var8[id];
        }
    } else if (state == 2) {
        self->state = 3;
        for (int i = 0; i < 5; i++) {
            self->pairs[i].value = -1;
            self->pairs[i].key = -1;
        }
        func_ov002_02157ce0((char*)&cmd);
        cmd.actor = self->ids[self->unknown_1cb0_];
        cmd.target = self->order[self->turn].id;
        self->target = self->order[self->turn].id;
        int var43 = 0;
        if (cmd.target >= 0 && cmd.target <= 3) {
            var43 = 1;
        }
        if (!var43) {
            self->state = 2;
            self->turn = self->turn + 1;
            if (n <= self->turn) {
                self->state = 5;
                self->result = 1;
                self->unknown_1c28_ = -1;
            }
            return;
        }
        Struct_ov002_021665b0_8* member = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, cmd.target);
        if (member->status->flags & 1) {
            self->state = 2;
            self->turn = self->turn + 1;
            if (n <= self->turn) {
                self->state = 5;
                self->result = 2;
                self->unknown_1c28_ = -1;
            }
            return;
        }
        char* table;
        func_ov002_021536e0(&table);
        table = (char*)data;
        int k;
        int i;
        for (i = 0, k = 0x1a; i < 5; i++, k++) {
            self->pairs[i].value = 0;
            self->pairs[i].key = 0;
            if (!func_02083bc0((unsigned char*)(func_02053c6c((unsigned char*)member)), k)) {
                continue;
            }
            if (!func_0209ac28((char*)self + SPELLS_021665b0, member, k)) {
                continue;
            }
            if (member->status->level < 2) {
                continue;
            }
            cmd.key = i + 0x1e;
            Struct_ov002_021665b0_10* elem = func_02079e2c((char*)data, (short)cmd.key);
            void* sub = func_02079ee0((char*)data, elem->key);
            self->pairs[i].value = func_ov002_021538e4(&table, elem, sub, cmd.target);
            self->pairs[i].key = cmd.key;
        }
    } else if (state == 3) {
        self->state = 4;
        self->unknown_1c28_ = -1;
        self->unknown_1c2a_ = -1;
        self->key = 0x1e;
        short var50;
        short large;
        unsigned char done;
        int target;
        int var54;
        int actor = self->ids[self->unknown_1cb0_];
        self->actor = actor;
        for (int i = 0; i < n; i++) {
            signed char id = self->ids[i];
            Struct_ov002_021665b0_8* member = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, id);
            if (member != NULL) {
                hp[id] = member->status->hp;
            }
        }
        var54 = (unsigned short)(maxHp[actor] - hp[actor]);
        int var59 = 0;
        unsigned char t = 0;
        if (var9[actor] == 1) {
            while (t < n) {
                Struct_ov002_021665b0_8* member = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, self->order[t].id);
                if (member == NULL) {
                    t++;
                    continue;
                }
                Struct_ov002_021665b0_9* field = func_02053c6c((unsigned char*)member);
                if (field == NULL) {
                    t++;
                    continue;
                }
                if (func_0200ff94(gs, self->order[t].id)->status->flags & 1) {
                    t++;
                    continue;
                }
                if (func_02083bc0((unsigned char*)field, 0x20)) {
                    if (!func_0209ac28((char*)self + SPELLS_021665b0, member, 0x20)) {
                        t++;
                        continue;
                    }
                    cmd.key = 0x23;
                    Struct_ov002_021665b0_10* elem = func_02079e2c((char*)data, (short)cmd.key);
                    Struct_ov002_021665b0_8* caster = func_0200ff94(gs, self->order[t].id);
                    if (!func_02048448((Struct_02048448_2*)caster, (unsigned short)elem->power)) {
                        t++;
                        continue;
                    }
                    self->key = cmd.key;
                    var59 = 1;
                    self->unknown_1cb1_ = 1;
                    break;
                }
                t++;
            }
        }
        if (var59) {
            self->unknown_1cad_ = t;
            func_ov002_021594e8(self, self->key, self->order[t].id, actor);
            Struct_ov002_021665b0_8* member = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, actor);
            Struct_ov002_021665b0_8* unit = func_0200ff94(gs, actor);
            hp[actor] = member->status->hp;
            if (!(unit->status->flags & 2)) {
                var9[actor] = 0;
            }
            self->state = 6;
            return;
        }
        target = self->order[self->turn].id;
        signed char count = self->order[self->turn].count;
        self->target = target;
        Struct_ov002_021665b0_8* unit = func_0200ff94(gs, actor);
        if (count == 0) {
            self->turn = self->turn + 1;
            self->state = 2;
            if (n <= self->turn) {
                self->state = 5;
                if (self->unknown_1cb1_ == 0) {
                    self->result = 2;
                }
            }
            return;
        }
        if (unit->status->flags & 1) {
            self->state = 2;
            self->unknown_1cb0_ = self->unknown_1cb0_ + 1;
            if (n <= self->unknown_1cb0_) {
                self->state = 5;
                if (self->unknown_1cb1_ == 0) {
                    self->result = 2;
                }
            }
            return;
        }
        if (var9[actor] == 1 && n <= self->unknown_1cb0_) {
            self->state = 5;
            if (self->unknown_1cb1_ == 0) {
                self->result = 2;
            }
            return;
        }
        if (var54 == 0) {
            self->state = 2;
            self->unknown_1cb0_ = self->unknown_1cb0_ + 1;
            if (n <= self->unknown_1cb0_) {
                self->state = 5;
                if (self->unknown_1cb1_ == 0) {
                    self->result = 2;
                }
            }
            return;
        }
        Struct_ov002_021665b0_8* var69 = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, target);
        if (func_02083bc0((unsigned char*)(func_02053c6c((unsigned char*)var69)), 0x1e) && self->pairs[4].key > 0) {
            cmd.key = 0x22;
            if (func_02048448((Struct_02048448_2*)var69, (unsigned short)func_02079e2c((char*)data, (short)0x22)->power)) {
                var50 = self->pairs[0].value;
                short var70 = self->pairs[1].value;
                large = self->pairs[2].value;
                short full = self->pairs[4].value;
                int area = self->pairs[3].key;
                signed char var73 = 0;
                signed char var74 = 0;
                signed char var75 = 0;
                for (unsigned char i = 0; i < n; i++) {
                    signed char id = self->ids[i];
                    short cur = hp[id];
                    if (cur <= 0) {
                        continue;
                    }
                    unsigned short var79 = maxHp[id] - cur;
                    if (var79 == 0) {
                        continue;
                    }
                    if (var79 < var70) {
                        continue;
                    }
                    if (var70 >= full) {
                        continue;
                    }
                    if (var50 < var79) {
                        var73++;
                    }
                    if (var70 < var79) {
                        var74++;
                    }
                    if (large <= 0) {
                        continue;
                    }
                    if (var79 < full * 2) {
                        var75++;
                    }
                }
                if (area > 0) {
                    for (unsigned char i = 0; i < n; i++) {
                        signed char id = self->ids[i];
                        short cur = hp[id];
                        if (cur <= 0) {
                            continue;
                        }
                        unsigned short var83 = maxHp[id] - cur;
                        if (var83 == 0) {
                            continue;
                        }
                        if (full * 6 >= var83) {
                            continue;
                        }
                        var73--;
                        var74--;
                        var75--;
                    }
                }
                if (var73 == 4 || var74 >= 4 || var75 >= 4) {
                    self->key = 0x22;
                    var59 = 1;
                }
            }
        }
        if (var59) {
            func_ov002_021594e8(self, self->key = 0x22, target, 0);
            for (int i = 0; i < n; i++) {
                unsigned char id = self->ids[i];
                Struct_ov002_021665b0_8* member = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, id);
                if (member != NULL) {
                    hp[id] = member->status->hp;
                }
            }
            self->state = 6;
            return;
        }
        if (var54 <= self->pairs[0].value) {
            if (!var59) {
                var59 = 1;
                self->key = self->pairs[0].key;
            }
        }
        if (!var59) {
            if (var54 < self->pairs[1].value) {
                var59 = 1;
                self->key = self->pairs[1].key;
            }
        }
        if (!var59) {
            if (var54 < self->pairs[1].value * 2) {
                var59 = 1;
                self->key = self->pairs[1].key;
            } else if (var54 < self->pairs[2].value) {
                var59 = 1;
                self->key = self->pairs[2].key;
            }
        }
        if (!var59) {
            if (var54 < self->pairs[2].value * 3) {
                var59 = 1;
                self->key = self->pairs[2].key;
            } else if (self->pairs[3].key != 0) {
                self->key = self->pairs[3].key;
                var59 = 1;
            }
        }
        if (!var59 && self->pairs[0].key != 0) {
            for (int i = 3; i >= 0; i--) {
                if (self->pairs[i].value != 0) {
                    self->key = self->pairs[i].key;
                    break;
                }
            }
        }
        done = 0;
        while (!done) {
            Struct_ov002_021665b0_10* elem = func_02079e2c((char*)data, (short)self->key);
            Struct_ov002_021665b0_8* caster = func_0200ff94(gs, target);
            if (caster == NULL || elem == NULL) {
                continue;
            }
            if (func_02048448((Struct_02048448_2*)caster, (unsigned short)elem->power) == 0) {
                self->key--;
                if (self->key < 0x1e) {
                    self->turn++;
                    self->state = 2;
                    if (n <= self->turn) {
                        self->state = 5;
                        self->result = 1;
                        self->unknown_1c28_ = -1;
                    }
                    done = 1;
                }
            } else {
                done = 1;
            }
        }
    } else if (state == 4) {
        int actor = self->ids[self->unknown_1cb0_];
        func_ov002_021594e8(self, self->key, self->order[self->turn].id, actor);
        Struct_ov002_021665b0_8* member = (Struct_ov002_021665b0_8*)func_0200ff1c(gs, actor);
        Struct_ov002_021665b0_8* unit = func_0200ff94(gs, actor);
        hp[actor] = member->status->hp;
        if (!(unit->status->flags & 2)) {
            var9[actor] = 0;
        }
        self->unknown_1cb1_ = 1;
        self->state = 6;
    } else if (state == 5) {
        int changed = 0;
        self->turn = 0;
        self->unknown_1cb0_ = 0;
        self->unknown_1c26_ = -1;
        self->unknown_1bb8_ = NEXT_IDLE_021665b0;
        self->unknown_1bbc_ = NEXT_IDLE_021665b0;
        self->nextC = changed;
        char* ctl = MessageSystem_GetInstance();
        if (self->unknown_1cb1_ == 0 && self->result == 1) {
            self->result = 2;
        }
        signed char result = self->result;
        if (!(result != 0 && result != 1)) {
            ctl[CTL_FLAG_021665b0] = 0;
            int pressed = g_keyManager.TestKeysPressed(0x601);
            int cancel = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)((char*)self + LIST_021665b0), 0x14)) ? 1 : 0;
            int var98 = func_0205d97c((char*)self + LIST_021665b0) == 1 ? 1 : 0;
            int var99 = func_ov002_02161b48((char*)self, 1);
            int left = g_keyManager.TestKeysPressed(KEY_DPAD);
            if (var98 | (var99 | (cancel | (left | g_keyManager.TestKeysPressed(0x100))))) {
                MessageSystem_Reset(ctl);
                self->unknown_1bb8_ = NEXT_BACK_021665b0;
                self->unknown_1bbc_ = NEXT_MENU_021665b0;
                func_0205def8((Struct_0205def8*)((char*)self + LIST_021665b0), 1, FLAG_KEY_021665b0);
                self->result = 0;
                self->unknown_1c28_ = -1;
                self->unknown_1c2a_ = -1;
                self->state = 0;
                self->unknown_1cb1_ = 0;
                changed = 1;
            } else if (g_keyManager.TestKeysPressed(0x800)) {
                MessageSystem_Reset(ctl);
                self->unknown_1bb8_ = NEXT_MENU_021665b0;
                self->unknown_1bbc_ = NEXT_MENU_021665b0;
                self->result = 0;
                self->unknown_1c28_ = -1;
                self->unknown_1c2a_ = -1;
                self->state = 0;
                self->unknown_1cb1_ = 0;
                changed = 1;
            }
        } else if (result == 2) {
            self->unknown_1c28_ = 0x232b;
            self->unknown_1bb8_ = NEXT_NONE_021665b0;
            self->unknown_1bbc_ = NEXT_IDLE_021665b0;
            self->result = 4;
            changed = 1;
        }
        if (changed) {
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
        }
    } else if (state == 6) {
        self->state = 3;
        signed char idx = self->unknown_1cb0_;
        int actor = self->ids[idx];
        if (hp[actor] == maxHp[actor] && var9[actor] == 0) {
            self->unknown_1cb0_ = idx + 1;
            self->turn = 0;
            self->state = 2;
            if (n <= self->unknown_1cb0_) {
                self->state = 5;
            }
        }
    }
}
