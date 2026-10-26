#include <globaldefs.h>
#if defined(jpn)
enum {
    kRegion800 = 0x77c
};
enum {
    kRegion89c = 0x818
};
enum {
    Enum_ov003_02177938_2208 = 0x81c
};
enum {
    Enum_ov003_02177938_4108 = 0xf88
};
enum {
    Enum_ov003_02177938_4120 = 0xf94
};
enum {
    Enum_ov003_02177938_4163 = 0xfbf
};
#else
enum {
    kRegion800 = 0x800
};
enum {
    kRegion89c = 0x89c
};
enum {
    Enum_ov003_02177938_2208 = 0x8a0
};
enum {
    Enum_ov003_02177938_4108 = 0x100c
};
enum {
    Enum_ov003_02177938_4120 = 0x1018
};
enum {
    Enum_ov003_02177938_4163 = 0x1043
};
#endif
#include "GameState/GameState.h"

extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" int func_ov003_02179e44(void *obj);
struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2 *obj, int key);
extern "C" void func_02080c68(void *obj, int id, int value);
extern "C" void func_02080b54(void *obj, int id);
extern "C" void func_02080608(void *obj, int id);
extern "C" unsigned char func_0207ca94(int index);
extern "C" int func_0207c638(void *base, unsigned int index);
extern "C" int func_0207c6b8(unsigned char *obj, unsigned int index, int target);
extern "C" int func_02080b40(void *obj, int id);
extern "C" int func_02081010(void *obj, int key);
struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c *obj, int id, int value);
struct Struct_02080cc0;
extern "C" void func_02080cc0(struct Struct_02080cc0 *obj, int id, int value);
extern "C" unsigned char *func_02053c6c(unsigned char *obj);
struct Struct_0207d300;
extern "C" int func_02083960(struct Struct_0207d300 *slots);
extern "C" int func_020dcc98(int combatantId);
struct Struct_020a0b8c;
extern "C" int func_020a0b8c(struct Struct_020a0b8c *p);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8 *obj, int id, int value);
struct ItemTable;
struct Element020de650 {
    char pad0[4];
    int value;
    char pad8[0x1a - 8];
    unsigned short count;
};
extern "C" struct Element020de650 *ItemTable_Find(struct ItemTable *c, int key);
extern "C" void func_020805f4(void *obj, int value);
extern "C" void func_020806c4(void *obj, int id);
extern "C" void func_ov003_0217818c(void *self, struct Element020de650 *elem, int id, int value);
extern "C" void func_0208103c(void *obj, int id, int value);
extern "C" void func_0208108c(void *obj, int id);
extern "C" void func_020813ec(void *obj, int key);

struct Struct_ov003_02177938 {
    unsigned char pad0[kRegion89c];
    struct Struct_0207fdcc_2 *unknown_89c_;
    unsigned char unknown_8a0_[Enum_ov003_02177938_4108 - Enum_ov003_02177938_2208];
    short mode;
    short cursor;
    short unknown_1010_;
    short unknown_1012_;
    short page;
    short pageCount;
    unsigned char unknown_1018_[Enum_ov003_02177938_4163 - Enum_ov003_02177938_4120];
    signed char combatantId;
};

// USA: func_ov003_02177938
extern "C" ARM void func_ov003_02177938(Struct_ov003_02177938 *self) {
    func_ov003_02179e44(self);
    GameState *battle       = GameState::GetInstance();
    unsigned char *list     = (unsigned char *) GameState_GetParty(battle);
    struct Struct_0207fdcc_2 *var2 = self->unknown_89c_;
    int var3              = 1;
    short idA               = 0x8b;
    short var5               = 0x93;
    short var6               = 0x9b;
    short msg               = 0x3c;
    int var8;
    short ids[8];

    func_02080c20(var2, 0x15);
    func_02080c68(var2, 0x15, 0);
    func_02080b54(var2, 0x15);
    func_02080608(var2, 0x15);
    var8 = 0;
    memset(ids, 0xff, sizeof(ids));

    if (self->mode == 0x77) {
        short tableIndex   = self->unknown_1012_ - 0x11e;
        unsigned int table = func_0207ca94(tableIndex);
        msg += tableIndex + 1;
        int count       = func_0207c638(list + 0x1d4, table);
        self->pageCount = (count + 7) / 8;
        if (self->pageCount == 0) {
            self->pageCount = 1;
        }
        if (count > 8) {
            count = 8;
        }
        for (short i = 0; i < count; i++) {
            ids[i] = func_0207c6b8(list + 0x1d4, table, i);
        }
        func_02080b40(var2, 0x8a);
        func_02080f8c((struct Container02080f8c *) var2, 0x8a,
                                   func_02081010(var2, self->unknown_1012_));
        func_02080cc0((struct Struct_02080cc0 *) var2, 0x8a, 0xf);
        var8 = 1;
        var3    = count != 0;
    } else {
        int inParty = 0;
        if (self->combatantId >= 0 && self->combatantId <= 3) {
            inParty = 1;
        }
        if (inParty) {
            GameObject *member = battle->GetPartyMemberByIndex(self->combatantId);
            if (member != NULL) {
                unsigned char *var16 = func_02053c6c((unsigned char *) member);
                int count              = func_02083960((struct Struct_0207d300 *) var16);
                for (int i = 0; i < count; i++) {
                    ids[i] = ((short *) (var16 + 0x454))[i];
                }
                func_02080b40(var2, 0x8a);
                func_02080f8c((struct Container02080f8c *) var2, 0x8a, *(int *) ((char *) member + 0x134));
                func_02080cc0((struct Struct_02080cc0 *) var2, 0x8a, func_020dcc98(self->combatantId));
                var3 = count != 0;
            } else {
                func_02080b54(var2, 0x15);
            }
        } else {
            int count = func_020a0b8c((struct Struct_020a0b8c *) list);
            if (count > 8) {
                count = 8;
            }
            for (short i = 0; i < count; i++) {
                ids[i] = ((short *) (list + 0xc))[i];
            }
            func_02080b40(var2, 0x8a);
            func_02080f8c((struct Container02080f8c *) var2, 0x8a,
                                       func_02081010(var2, 0x7a));
            func_02080cc0((struct Struct_02080cc0 *) var2, 0x8a, 0xf);
            var8 = 1;
            var3    = count != 0;
        }
    }

    if (var8 != 0) {
        func_02080fa8((struct Struct_02080fa8 *) var2, 0xa3, self->page + 1);
        func_02080fa8((struct Struct_02080fa8 *) var2, 0xa4, self->pageCount);
        func_02080b40(var2, 0xa3);
        func_02080b40(var2, 0xa4);
        func_02080b40(var2, 0xa5);
    }

    for (unsigned char i = 0; i < 8; i++) {
        int value = 0;
        int count = 0;
        if (ids[i] > 0) {
            struct Element020de650 *elem = ItemTable_Find((struct ItemTable *) ((unsigned char *) self + kRegion800 + 0x74), ids[i]);
            if (elem != NULL) {
                count = elem->count;
                value = elem->value;
            }
#if !defined(jpn)
            func_020805f4(var2, idA);
#endif
            func_020806c4(var2, idA);
            func_02080f8c((struct Container02080f8c *) var2, idA, value);
            func_02080fa8((struct Struct_02080fa8 *) var2, var5, count);
            func_02080b40(var2, idA);
            func_02080b40(var2, var5);
            func_02080b40(var2, var6);
            func_ov003_0217818c(self, elem, var5, var6);
        }
        idA = idA + 1;
        var5 = var5 + 1;
        var6 = var6 + 1;
    }

    if (var3 == 0) {
        func_0208103c(var2, 0x143, msg);
        func_02080b40(var2, 0x143);
        func_02080b40(var2, 0x144);
        func_0208108c(var2, 0x143);
        func_0208108c(var2, 0x144);
    }
    func_020813ec(var2, 0x15);
}
