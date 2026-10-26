#include <globaldefs.h>
#include "Resource/GameResources.h"


#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct GameState;

struct Struct_ov005_02157b74_4 {
    unsigned int pad0 : 27;
    unsigned int sound : 2;
    unsigned int pad1 : 3;
};

struct Item02157b74 {
    Struct_ov005_02157b74_4* unknown_0_;
    int f4;
    unsigned int unknown_8_0_ : 4;
    unsigned int pad0 : 14;
    unsigned int unknown_a_2_ : 1;
    unsigned int pad1 : 13;
    int fc;
    unsigned int pad2 : 20;
    unsigned int kind : 8;
    unsigned int pad3 : 4;
};

struct Struct_ov005_02157b74_6 {
    char pad0[0x18];
    short id;
};

struct Struct_ov005_02157b74_7 {
    char pad0[0x16];
    short unknown_16_;
};

struct Struct_ov005_02157b74_8 {
    char pad0[4];
    short id;
    char pad1[LOW_REGION(0x144 - 6, 0x150 - 6)];
    void* model;
};

struct Struct_ov005_02157b74_9 {
    char pad0[LOW_REGION(0x4f8, 0x4fc)];
    int actor;
    char pad1[LOW_REGION(0x56c - 0x4fc, 0x634 - 0x500)];
    unsigned short flags;
};

struct Struct_ov005_02157b74 {
    short id;
    signed char state;
    char pad[0x1c - 3];
};

struct Menu02157b74 {
    char pad0[0xdf4];
    void* items;
    char pad1[LOW_REGION(0x19ac - 0xdf8, 0x1a34 - 0xdf8)];
    char cursor[0x2d90 - 0x1a34];
    Struct_ov005_02157b74 entries[0x18];
    char pad2[0x3da8 - 0x3030];
    unsigned char unknown_3da8_;
    unsigned char unknown_3da9_;
    unsigned char unknown_3daa_;
    unsigned char unknown_3dab_;
    unsigned short unknown_3dac_;
    char pad3[0x3dbb - 0x3dae];
    signed char selected;
    unsigned char tab;
    char pad4[0x3dcc - 0x3dbd];
    unsigned int dirty;
    unsigned char pad5;
    unsigned char message;
    unsigned char unknown_3dd2_;
};

extern "C" GameState* _ZN9GameState11GetInstanceEv();
extern "C" Struct_ov005_02157b74_9* func_ov017_021a193c(int*);
extern "C" Struct_ov005_02157b74_8* func_0200ff1c(GameState* gs, int idx);
extern "C" char* GameState_GetParty(GameState* gs);
struct Struct_02052df8;
extern "C" short func_02052df8(Struct_02052df8*, int);
struct ItemTable;
extern "C" Item02157b74* ItemTable_Find(ItemTable*, int);
extern "C" void func_02052d7c(Struct_ov005_02157b74_8* c, int slot, short id);
extern "C" void* func_02053c6c(unsigned char*);
extern "C" void PartyMember_Equip(void* model, Item02157b74* item, int arg);
extern "C" void func_02083738(void* model, int type);
struct Struct_ov005_02157b74_3;
extern "C" void func_ov005_021583fc(Struct_ov005_02157b74_3*, char);
struct Field150Holder02052e2c;
extern "C" Struct_ov005_02157b74_7* func_02052e2c(Field150Holder02052e2c*);
extern "C" int func_ov005_0215840c(Menu02157b74* self, int id);
extern "C" void PartyMember_RecalculateStats(void* model, int arg);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_0207c378(char* list, short key, int amount, int category);
extern "C" void func_ov005_021551fc(char*, int, int);
extern "C" void func_ov005_02155544(Menu02157b74* self);
extern "C" void func_ov005_021555c0(Menu02157b74* self);
struct SePlayer;
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" int func_020dd4c4(signed char id, Item02157b74* item);
struct Fields020deda4;
extern "C" Struct_ov005_02157b74_6* func_020deda4(int, int, Fields020deda4*);
extern "C" void func_020483f0(unsigned char*, unsigned short);
extern "C" int func_0207c7a0(char* list, short key, int category);
extern "C" int func_0207caa4(char* list, short key, int category);
extern "C" void func_0207c484(char* list, short key, int amount, int category);
struct Struct_0207cb38;
extern "C" void func_0207cb38(Struct_0207cb38*, int, int, int, char);
extern "C" void func_ov023_021e4e1c(void* ctx, int actor, short key, int category);
extern "C" void func_ov005_02154d18(void* obj, int a, int b);
extern "C" void func_ov005_02154d50(void* obj, int a, int b);

extern signed char data_ov005_0215cd40[];
extern unsigned char data_ov005_0215cd38[];
extern char g_sePlayer[];
extern unsigned char data_ov005_0215cd30[];

// Overlay 5, originally func_ov005_02157b74 (USA/EUR 0x02157b74, JPN 0x0215916c)
extern "C" ARM void EquipMenu_EquipItem(Menu02157b74* self, int key, int keepStock) {
    char* bag;
    GameState* gs = _ZN9GameState11GetInstanceEv();
    Struct_ov005_02157b74_9* ctx = func_ov017_021a193c((int*)(*(int*)((char*)GetGameResources() + LOW_REGION(0x34f8, 0x3708))));
    int bareArg;
    int actor = ctx->actor;
    Struct_ov005_02157b74_8* who = func_0200ff1c(gs, actor);
    if (who == 0) return;

    bag = GameState_GetParty(gs);

    if (key == 0xffff) {
        int slot = data_ov005_0215cd40[self->tab];
        short cur = func_02052df8((Struct_02052df8*)who, slot);
        Item02157b74* item = ItemTable_Find((ItemTable*)self->items, (short)cur);
        if (item == 0) return;

        if (item->unknown_a_2_ == 1) {
            self->message = 0xc;
            self->dirty |= 0x8000;
            return;
        }

        short bareKey = -1;
        bareArg = -1;
        if (slot == 0) {
            bareArg = 0;
            bareKey = 0x3e8;
        }
        func_02052d7c(who, slot, -1);
        void* model = func_02053c6c((unsigned char*)who);
        Item02157b74* bare = ItemTable_Find((ItemTable*)self->items, (short)bareKey);
        if (bare != 0) {
            PartyMember_Equip(model, bare, bareArg);
        } else {
            func_02083738(model, item->unknown_8_0_);
            if (item->unknown_8_0_ == 7) {
                func_ov005_021583fc((Struct_ov005_02157b74_3*)who, 1);
            }
        }
        if (slot == 0) {
            func_02052e2c((Field150Holder02052e2c*)who)->unknown_16_ = -1;
        }
        if (cur == 0x4680) {
            if (func_ov005_0215840c(self, who->id) != 0) {
                if (self->message == 0xa && keepStock != 0) {
                    self->unknown_3dd2_ = 0xe;
                } else {
                    self->message = 0xe;
                }
            }
        }
        PartyMember_RecalculateStats(who->model, 0);
        func_ov017_021c9e00(who->id, 0, 0, 1);
        ctx->flags |= 4;
        if (keepStock == 0) {
            func_0207c378(bag + 0x1d4, cur, 1, data_ov005_0215cd38[self->tab]);
        }
        self->entries[self->selected].id = -1;
        func_ov005_021551fc((char*)self, func_ov017_021a193c((int*)(*(int*)((char*)GetGameResources() + LOW_REGION(0x34f8, 0x3708))))->actor, 1);
        func_ov005_02155544(self);
        self->dirty |= 0x10;
        self->unknown_3da8_ = 0;
        self->unknown_3dac_ = self->tab;
        if (keepStock == 0) {
            func_ov005_021555c0(self);
            for (int i = 8; i < 0x18; i++) {
                if (cur == self->entries[i].id && self->entries[i].state == 1) {
                    self->dirty |= 0x40;
                    self->unknown_3daa_ = 0;
                    break;
                }
            }
        }
        SePlayer_Play((SePlayer*)g_sePlayer, 0x5c, 0);
        self->dirty |= 0x200;
        self->dirty |= 1;
        return;
    }

    Item02157b74* item = ItemTable_Find((ItemTable*)self->items, (short)key);
    if (item == 0) return;

    unsigned int kind = item->kind;
    int slot = -1;
    switch (kind) {
    case 0x73: slot = 8; break;
    case 0x62: slot = 0; break;
    case 0x70: slot = 1; break;
    case 0x61: slot = 4; break;
    case 0x67: slot = 4; break;
    case 0x72: slot = 5; break;
    case 0x6d: slot = 6; break;
    case 0x77: slot = 7; break;
    case 0x63: slot = 9; break;
    }

    int var16 = func_020dd4c4(who->id, item);
    if (var16 != 0) {
        if (var16 & 0x100) {
            self->message = 5;
            return;
        }
        if (var16 & 0x80) {
            self->message = 2;
            if (func_02052df8((Struct_02052df8*)who, 9) == 0x4680) {
                self->message = 7;
            }
            return;
        }
        if (var16 & 0x10) {
            self->message = 6;
            return;
        }
        if (var16 & 2) {
            self->message = 4;
            return;
        }
        if (var16 & 1) {
            self->message = 3;
            return;
        }
        if (var16 & 4) {
            self->message = 1;
        }
        return;
    }

    short old = func_02052df8((Struct_02052df8*)who, slot);
    if (old == (short)key) return;

    Item02157b74* oldItem = ItemTable_Find((ItemTable*)self->items, (short)old);
    if (oldItem != 0 && oldItem->unknown_a_2_ == 1) {
        self->message = 0xc;
        self->dirty |= 0x8000;
        return;
    }

    if (slot >= 0) {
        if (old == 0x4680) {
            if (func_ov005_0215840c(self, who->id) != 0) {
                self->message = 0xe;
            }
        }
        func_02052d7c(who, slot, (unsigned short)key);
        void* model = func_02053c6c((unsigned char*)who);
        PartyMember_Equip(model, item, -1);
        PartyMember_RecalculateStats(model, 0);
        func_ov017_021c9e00(who->id, 0, 0, 1);
        if (item->unknown_8_0_ == 7) {
            func_ov005_021583fc((Struct_ov005_02157b74_3*)who, 1);
        }
        func_ov005_021551fc((char*)self, func_ov017_021a193c((int*)(*(int*)((char*)GetGameResources() + LOW_REGION(0x34f8, 0x3708))))->actor, 1);
    }

    if (kind == 0x62) {
        Struct_ov005_02157b74_6* linked = func_020deda4((int)self->items, 0x61, (Fields020deda4*)item);
        if (linked != 0) {
            func_02052e2c((Field150Holder02052e2c*)who)->unknown_16_ = linked->id;
        }
    }

    if (item->unknown_a_2_ == 1) {
        if (self->message == 0xe) {
            self->unknown_3dd2_ = 0xe;
        }
        self->message = 0xd;
        self->dirty |= 0x8000;
        func_020483f0((unsigned char*)who, 4);
        func_ov017_021c9e00(actor, 0, 0, 1);
    }

    if (item->unknown_0_->sound == 1) {
        SePlayer_Play((SePlayer*)g_sePlayer, 3, 0);
    } else if (item->unknown_0_->sound == 2) {
        SePlayer_Play((SePlayer*)g_sePlayer, 4, 0);
    }

    ctx->flags |= 4;

    unsigned char category = data_ov005_0215cd30[self->tab];
    signed char var22 = func_0207c7a0(bag + 0x1d4, key, category);
    signed char var23 = func_0207c7a0(bag + 0x1d4, old, category);
    if (var22 == 1 && var23 == 0) {
        int index = func_0207caa4(bag + 0x1d4, key, category);
        func_0207c484(bag + 0x1d4, key, 1, category);
        if (index >= 0) {
            func_0207cb38((Struct_0207cb38*)(bag + 0x1d4), index, category, old, 1);
        } else {
            func_0207c378(bag + 0x1d4, old, 1, category);
        }
    } else {
        func_0207c484(bag + 0x1d4, key, 1, category);
        func_0207c378(bag + 0x1d4, old, 1, category);
    }

    func_ov023_021e4e1c(ctx, actor, key, data_ov005_0215cd30[self->tab]);
    func_ov005_02155544(self);
    self->dirty |= 0x10;
    self->unknown_3da8_ = 0;
    self->unknown_3dac_ = self->tab;
    self->selected = self->tab;
    func_ov005_02154d18(self->cursor, 0x85000, 0x17000);
    func_ov005_02154d50(self->cursor, 0x76000, 0x16000);
    func_ov005_021555c0(self);
    for (int i = 8; i < 0x18; i++) {
        if (old == self->entries[i].id && self->entries[i].state == 1) {
            self->dirty |= 0x40;
            self->unknown_3daa_ = 0;
            break;
        }
    }
    self->dirty |= 0x200;
    self->dirty |= 1;
}
