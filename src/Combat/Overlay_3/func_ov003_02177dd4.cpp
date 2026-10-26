#include <globaldefs.h>
#include "Resource/ItemTable.h"
#if defined(jpn)
enum {
    kRegion800 = 0x77c
};
enum {
    kRegion89c = 0x818
};
enum {
    Enum_ov003_02177dd4_2208 = 0x81c
};
enum {
    Enum_ov003_02177dd4_4108 = 0xf88
};
#else
enum {
    kRegion800 = 0x800
};
enum {
    kRegion89c = 0x89c
};
enum {
    Enum_ov003_02177dd4_2208 = 0x8a0
};
enum {
    Enum_ov003_02177dd4_4108 = 0x100c
};
#endif
#include "GameState/GameState.h"

extern "C" unsigned char func_0207ca94(int index);
extern "C" int func_ov003_02175f90(void *obj);
struct Struct_020a0b8c {
    short* keys;
    signed char* values;
    short count;
};
struct Struct_0207c258 {
    char pad0[0xbd0];
    short* unknown_bd0_[8];
    unsigned char* unknown_bf0_[8];
    short counts[8];
    unsigned char index[8];
    unsigned char used[8];
};
struct Inventory02177dd4 {
    Struct_020a0b8c list;
    short keys[152];
    signed char values[152];
    Struct_0207c258 unknown_1d4_;
};
extern "C" int func_020a0b8c(struct Struct_020a0b8c *p);
struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2 *obj, int key);
extern "C" void func_02080c68(void *obj, int id, int value);
extern "C" void func_02080bac(void *obj, int id);
extern "C" void func_0208065c(void *obj, int id);
extern "C" void func_02081130(void *obj, int id, int set);
extern "C" void func_020806b0(void *obj, int id);
extern "C" int func_02080b2c(void *obj, int id);
extern "C" int func_0207c6b8(unsigned char *obj, unsigned int index, int target);
struct Element020de650;
struct Element020de650 {
    char pad0[4];
    int value;
    char pad8[0x1a - 8];
    unsigned short count;
};
extern "C" struct Element020de650 *ItemTable_Find(struct ItemTable *c, int key);
extern "C" short func_0207c72c(void *obj, unsigned int index, short n);
extern "C" void func_ov003_0217818c(void *self, struct Element020de650 *elem, int id, int value);
extern "C" void func_020805f4(void *obj, int value);
struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c *obj, int id, int value);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8 *obj, int id, int value);
extern "C" int func_02081010(void *obj, int key);
extern "C" void func_020813ec(void *obj, int key);

struct Struct_ov003_02177dd4 {
    unsigned char pad0[kRegion800 + 0x74];
    struct ItemTable container;
    unsigned char paddingAfterContainer[kRegion89c - kRegion800 - 0x74 - sizeof(ItemTable)];
    struct Struct_0207fdcc_2 *unknown_89c_;
    unsigned char unknown_8a0_[Enum_ov003_02177dd4_4108 - Enum_ov003_02177dd4_2208];
    short mode;
    short cursor;
    short unknown_1010_;
    short unknown_1012_;
    short page;
    short pageCount;
};

// JPN: func_ov003_02177dd4 (02176d60)
// USA: func_ov003_02177dd4
extern "C" ARM void func_ov003_02177dd4(Struct_ov003_02177dd4 *self) {
    Inventory02177dd4* inventory = static_cast<Inventory02177dd4*>(GameState_GetParty(GameState::GetInstance()));
    unsigned int table  = 0;
    short hdr;
    short var3;
    short var4;
    short var5;
    short key;
    int count;
    short *keys             = 0;
    signed char *var9       = 0;
    struct Struct_0207fdcc_2 *var10 = self->unknown_89c_;
    int group               = 0x16;
    hdr                     = 0xa6;
    short idA               = 0xa7;
    short var13               = 0xaf;
    short var14               = 0xb7;
    var3                     = 0xbf;
    short var15               = 0xc7;
    var4                  = 0xcf;
    var5             = 0xd0;
    short var16           = 8;

    if (self->mode == 0x77) {
        short tableIndex = self->unknown_1012_ - 0x11e;
        table            = func_0207ca94(tableIndex);
        count            = func_ov003_02175f90(self);
        self->pageCount  = (count + 4) / 5;
        if (self->pageCount == 0) {
            self->pageCount = 1;
        }
        idA         = 0x127;
        key         = tableIndex + 0x11e;
        group       = 0x1e;
        hdr         = 0x126;
        var13         = 0x12c;
        var14         = 0x131;
        var3         = 0x136;
        var15         = 0x13b;
        var4      = 0x140;
        var5 = 0x141;
        var16     = 5;
    } else {
        count = func_020a0b8c(&inventory->list);
        keys  = inventory->keys;
        var9  = inventory->values;
        key   = 0x7a;
    }

    func_02080c20(var10, group);
    func_02080c68(var10, group, 0);
    func_02080bac(var10, group);
    func_0208065c(var10, group);
    func_02081130(var10, group, var16 < count);

    short i              = self->page * var16;
    short end            = i + var16;
    for (; i < end; i++) {
        if (count <= i) {
            func_020806b0(var10, idA);
            func_02080b2c(var10, idA);
            func_02080b2c(var10, var13);
            func_02080b2c(var10, var14);
            func_02080b2c(var10, var3);
            func_02080b2c(var10, var15);
        } else {
            int value = 0;
            int num   = 0;
            int k;
            if (keys != 0) {
                k = keys[i];
            } else {
                k = func_0207c6b8(((unsigned char*)(&inventory->unknown_1d4_)), table, i);
            }
            struct Element020de650 *elem = ItemTable_Find(&self->container, k);
            if (elem != NULL) {
                value = elem->value;
                num   = elem->count;
            }
            int extra;
            if (var9 != 0) {
                extra = var9[i];
            } else {
                extra = func_0207c72c(&inventory->unknown_1d4_, table, i);
            }
            func_ov003_0217818c(self, elem, var13, var14);
#if !defined(jpn)
            func_020805f4(var10, idA);
#endif
            func_02080f8c((struct Container02080f8c *) var10, idA, value);
            func_02080fa8((struct Struct_02080fa8 *) var10, var13, num);
            func_02080fa8((struct Struct_02080fa8 *) var10, var15, extra);
        }
        idA++;
        var13++;
        var14++;
        var3++;
        var15++;
    }

    func_02080f8c((struct Container02080f8c *) var10, hdr, func_02081010(var10, key));
    func_02080fa8((struct Struct_02080fa8 *) var10, var4, self->page + 1);
    func_02080fa8((struct Struct_02080fa8 *) var10, var5, self->pageCount);
    func_020813ec(var10, group);
}
