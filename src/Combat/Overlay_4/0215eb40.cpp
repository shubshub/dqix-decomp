#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct_ov004_0215eb40_2 {
    unsigned short keys[7];
    unsigned char values[7];
    unsigned char count;
};

struct Struct_ov004_02170b90 {
    struct Struct_ov004_0215eb40_2 entries[26];
    unsigned char pad;
    unsigned char total;
    unsigned char unknown_23e_;
    unsigned char unknown_23f_;
};

struct Struct_0209a348 { void* field0; void* field4; };
struct Pair0209a338 { int a; int b; };
struct Struct_0209a670 { char pad[4]; int field; };

struct Struct_ov004_0215eb40_4 {
#if defined(jpn)
    unsigned short key : 12;
    unsigned short pad0 : 4;
#else
    unsigned short key : 11;
    unsigned short pad0 : 5;
#endif
    unsigned short mode;
    unsigned int category : 5;
    unsigned int threshold : 7;
    unsigned int unknown_5_4_ : 20;
    unsigned int pad;
};

struct Struct_0209a654_2 { struct Struct_ov004_0215eb40_4* entries; int count; };

struct Element020de650 {
    unsigned int word0;
    unsigned int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int kind : 5;
    unsigned int unknown_9_1_ : 23;
    unsigned char pad[8];
    unsigned short v5;
};

struct ItemTable;

class Struct_ov004_0215eb40 {
public:
    virtual void v00(); virtual void inline_ov004_0215eb40_2(); virtual void inline_ov004_0215eb40_3(); virtual void inline_ov004_0215eb40_4();
    virtual void v04(); virtual void inline_ov004_0215eb40_6(); virtual void inline_ov004_0215eb40_7(); virtual void inline_ov004_0215eb40_8();
    virtual void v08(); virtual void inline_ov004_0215eb40_10(); virtual void v10(); virtual void inline_ov004_0215eb40_12();
    virtual void inline_ov004_0215eb40_13(); virtual void inline_ov004_0215eb40_14(); virtual void v14(); virtual void inline_ov004_0215eb40_16();
    virtual void inline_ov004_0215eb40_17(); virtual void inline_ov004_0215eb40_18(); virtual void v18(); virtual void inline_ov004_0215eb40_20();
    virtual void v20(); virtual void inline_ov004_0215eb40_22(); virtual void inline_ov004_0215eb40_23(); virtual void inline_ov004_0215eb40_24();
    virtual void v24(); virtual void inline_ov004_0215eb40_26(); virtual void inline_ov004_0215eb40_27(); virtual void inline_ov004_0215eb40_28();
    virtual void v28(); virtual void inline_ov004_0215eb40_30(); virtual void v30(); virtual void inline_ov004_0215eb40_32();
    virtual void inline_ov004_0215eb40_33(); virtual void inline_ov004_0215eb40_34(); virtual void v34(); virtual void inline_ov004_0215eb40_36();
    virtual void inline_ov004_0215eb40_37(); virtual void inline_ov004_0215eb40_38(); virtual void v38(); virtual void inline_ov004_0215eb40_40();
    virtual void v40(); virtual void inline_ov004_0215eb40_42(); virtual void inline_ov004_0215eb40_43(); virtual void inline_ov004_0215eb40_44();
    virtual void v44(); virtual void inline_ov004_0215eb40_46(); virtual void inline_ov004_0215eb40_47(); virtual void inline_ov004_0215eb40_48();
    virtual void v48(); virtual void inline_ov004_0215eb40_50(); virtual void v50(); virtual void inline_ov004_0215eb40_52();
    virtual void inline_ov004_0215eb40_53(); virtual void inline_ov004_0215eb40_54(); virtual void v54(); virtual void inline_ov004_0215eb40_56();
    virtual void inline_ov004_0215eb40_57(); virtual void inline_ov004_0215eb40_58();
    virtual ItemTable* GetContainer();
};

struct Struct_ov004_0215eb40_3 { unsigned char pad[0x454]; short slots[8]; };
struct Field150 { unsigned char pad[0x464]; unsigned char key[0x20]; };

extern struct Struct_ov004_02170b90 data_ov004_02170b90[] __attribute__((aligned(4)));
extern unsigned char data_ov004_021707e8;
extern unsigned char data_ov004_0216fdd0[];
extern char data_0212633c[];

extern "C" void func_0209a338(struct Pair0209a338*);
extern "C" void func_0209a348(struct Struct_0209a348*, void*);
extern "C" int func_0209a670(struct Struct_0209a670*);
extern "C" struct Struct_ov004_0215eb40_4* func_0209a654(struct Struct_0209a654_2*, unsigned int);
extern "C" void func_02083acc(unsigned char*, int);
extern "C" void func_02083b28(unsigned char*, int);
extern "C" int func_02083b00(unsigned char*, int);
extern "C" void* func_02053c6c(unsigned char*);
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable*, int);
extern "C" void* func_ov004_0215e47c(void*, int);
extern "C" void func_ov004_0215ee90(void*);

// USA: func_ov004_0215eb40
extern "C" ARM void func_ov004_0215eb40(void* self) {
    struct Struct_0209a348 ctx;
    GameState* gs;
    unsigned char* combatant;
    unsigned char* field150;
    BackgroundLoader* loader;
    struct ItemTable* container;
    int k;
    int found;
    short* slots;
    int j;
    int total;
    int count;
    struct Struct_ov004_0215eb40_4* entry;
    unsigned char var13[2];

    func_ov004_0215ee90(data_ov004_02170b90);
    gs = GameState::GetInstance();
    combatant = (unsigned char*)(void*)func_0200ff1c(gs, *(int*)((char*)&data_ov004_021707e8 + 0x1c));
    field150 = (unsigned char*)func_02053c6c(combatant);
    if (combatant == 0 || field150 == 0) {
        return;
    }
    loader = BackgroundLoader::GetInstance();
    loader->Suspend();
    char* script = data_0212633c;
    func_0209a338((struct Pair0209a338*)&ctx);
    func_0209a348(&ctx, script);
    GameState_GetParty(gs);

    container = 0;
    {
        Struct_ov004_0215eb40* node = (Struct_ov004_0215eb40*)func_ov004_0215e47c(self, 0x8d);
        if (node != 0) {
            container = node->GetContainer();
        }
    }
    if (container == 0) {
        goto afterSlots;
    }

    for (k = 0x56f9; k <= 0x5712; k++) {
        found = 0;
        slots = ((struct Struct_ov004_0215eb40_3*)*(void**)((char*)combatant
#if defined(jpn)
            + 0x144))->slots;
#else
            + 0x150))->slots;
#endif
        for (j = 0; j < 8; j++) {
            if (slots[j] == k) {
                found = 1;
                break;
            }
        }
        struct Element020de650* elem = ItemTable_Find(container, (short)k);
        if (elem == 0) {
            continue;
        }
        if (elem->kind != 0x1f) {
            continue;
        }
        if (found) {
            func_02083acc(field150, elem->v5);
        } else {
            func_02083b28(field150, elem->v5);
        }
    }

afterSlots:
    var13[0] = data_ov004_0216fdd0[0];
    var13[1] = data_ov004_0216fdd0[1];
    total = func_0209a670((struct Struct_0209a670*)&ctx);
    entry = func_0209a654((struct Struct_0209a654_2*)&ctx, 0);
    for (count = 0; count < total; entry++, count++) {
        signed char idx = entry->category;
        int slot = (signed char)(idx - 1);
        if (slot < 0) {
            continue;
        }
        unsigned short save = entry->key;
        bool ok = func_02083b00(field150, save);
        if (!ok) {
            continue;
        }
        unsigned char v = entry->threshold;
        unsigned char var22 = ((struct Field150*)field150)->key[idx];
        int which = -1;
        if ((int)entry->mode > 0) {
            which = 0;
        } else if (entry->mode == 0) {
            if (var22 >= v) {
                which = 1;
            }
        }
        if (which == -1) {
            continue;
        }

        struct Struct_ov004_02170b90* page = &data_ov004_02170b90[which];
        unsigned char val = v ? v : 0x6e;
        struct Struct_ov004_0215eb40_2* base = &page->entries[slot];
        unsigned short* keys = base->keys;
        unsigned char* values = base->values;
        unsigned char n = base->count;
        int i = 0;
        while (i < n) {
            if (val < *values) {
                break;
            }
            i++;
            keys++;
            values++;
        }
        int rest = n - i;
        if (rest > 0) {
            memmove(keys + 1, keys, rest * sizeof(*keys));
            memmove(values + 1, values, rest);
        }
        *keys = save;
        *values = val;
        base->count = base->count + 1;
        if ((signed char)var13[which] == slot) {
            continue;
        }
        var13[which] = slot;
        page->total = page->total + 1;
        if (page->total & 1) {
            page->unknown_23f_ = page->unknown_23f_ + 1;
        }
        if (page->unknown_23e_ < idx) {
            page->unknown_23e_ = idx;
        }
    }

    loader->RemoveLock();
}
