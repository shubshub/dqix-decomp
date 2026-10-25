#include <globaldefs.h>
#if defined(jpn)
enum {
    Enum_ov003_02177938_2048 = 0x77c
};
enum {
    Enum_ov003_02177938_2204 = 0x818
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
    Enum_ov003_02177938_2048 = 0x800
};
enum {
    Enum_ov003_02177938_2204 = 0x89c
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
struct Obj2081;
void ClearElementFlag0x20_02080c20(struct Obj2081 *obj, int key);
void SetEntryLowNibbleAndElement02080c68(void *obj, int id, int value);
void SetSublistEntriesFlag1_02080b54(void *obj, int id);
void SetSublistEntriesFlag2_02080608(void *obj, int id);
unsigned char GetTableByte0207ca94(int index);
int CountPositiveEntries0207c638(void *base, unsigned int index);
int FindNthPositiveShort0207c6b8(unsigned char *obj, unsigned int index, int target);
int SetEntryFlagById02080b40(void *obj, int id);
int LookupValueByEntryKey02081010(void *obj, int key);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c *obj, int id, int value);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0 *obj, int id, int value);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *obj);
struct Slots02083960;
int CountPositiveSlots02083960(struct Slots02083960 *slots);
extern "C" int func_020dcc98(int combatantId);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c *p);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8 *obj, int id, int value);
struct ItemTable;
struct Element020de650 {
    char pad0[4];
    int value;
    char pad8[0x1a - 8];
    unsigned short count;
};
struct Element020de650 *ItemTable_Find(struct ItemTable *c, int key);
void Forward0207f7acObjPlus4Size0x40_020805f4(void *obj, int value);
void ClearSublistEntryFlag2_020806c4(void *obj, int id);
extern "C" void func_ov003_0217818c(void *self, struct Element020de650 *elem, int id, int value);
void SetEntryHalfword0xe_0208103c(void *obj, int id, int value);
void DispatchEntryOp0x8_0208108c(void *obj, int id);
extern "C" void func_020813ec(void *obj, int key);

struct Struct_ov003_02177938 {
    unsigned char unknown_0_[Enum_ov003_02177938_2204];
    struct Struct_0207fdcc_2 *unknown_89c_;
    unsigned char unknown_8a0_[Enum_ov003_02177938_4108 - Enum_ov003_02177938_2208];
    short unknown_100c_;
    short unknown_100e_;
    short unknown_1010_;
    short unknown_1012_;
    short unknown_1014_;
    short unknown_1016_;
    unsigned char unknown_1018_[Enum_ov003_02177938_4163 - Enum_ov003_02177938_4120];
    signed char unknown_1043_;
};

// USA: func_ov003_02177938
extern "C" ARM void func_ov003_02177938(ListMenu_02177938 *self) {
    func_ov003_02179e44(self);
    GameState *battle       = GameState::GetInstance();
    unsigned char *list     = (unsigned char *) GameState_GetParty(battle);
    struct Obj2081 *elemObj = self->elemObj;
    int hasAny              = 1;
    short idA               = 0x8b;
    short idB               = 0x93;
    short idC               = 0x9b;
    short msg               = 0x3c;
    int showPages;
    short ids[8];

    func_02080c20(var2, 0x15);
    func_02080c68(var2, 0x15, 0);
    func_02080b54(var2, 0x15);
    func_02080608(var2, 0x15);
    var8 = 0;
    memset(var9, 0xff, sizeof(var9));

    if (arg0->unknown_100c_ == 0x77) {
        short var10   = arg0->unknown_1012_ - 0x11e;
        unsigned int var11 = func_0207ca94(var10);
        var7 += var10 + 1;
        int var12       = func_0207c638(var1 + 0x1d4, var11);
        arg0->unknown_1016_ = (var12 + 7) / 8;
        if (arg0->unknown_1016_ == 0) {
            arg0->unknown_1016_ = 1;
        }
        if (var12 > 8) {
            var12 = 8;
        }
        for (short var13 = 0; var13 < var12; var13++) {
            var9[var13] = func_0207c6b8(var1 + 0x1d4, var11, var13);
        }
        func_02080b40(var2, 0x8a);
        func_02080f8c((struct Struct_02080f8c *) var2, 0x8a,
                                   func_02081010(var2, arg0->unknown_1012_));
        func_02080cc0((struct Struct_02080cc0 *) var2, 0x8a, 0xf);
        var8 = 1;
        var3    = var12 != 0;
    } else {
        int var14 = 0;
        if (arg0->unknown_1043_ >= 0 && arg0->unknown_1043_ <= 3) {
            var14 = 1;
        }
        if (var14) {
            GameObject *var15 = var0->GetPartyMemberByIndex(arg0->unknown_1043_);
            if (var15 != NULL) {
                unsigned char *var16 = func_02053c6c((unsigned char *) var15);
                int var17              = func_02083960((struct Struct_0207d300 *) var16);
                for (int var18 = 0; var18 < var17; var18++) {
                    var9[var18] = ((short *) (var16 + 0x454))[var18];
                }
                func_02080b40(var2, 0x8a);
                func_02080f8c((struct Struct_02080f8c *) var2, 0x8a, *(int *) ((char *) var15 + 0x134));
                func_02080cc0((struct Struct_02080cc0 *) var2, 0x8a, func_020dcc98(arg0->unknown_1043_));
                var3 = var17 != 0;
            } else {
                func_02080b54(var2, 0x15);
            }
        } else {
            int var19 = func_020a0b8c((struct Struct_020a0b8c *) var1);
            if (var19 > 8) {
                var19 = 8;
            }
            for (short var20 = 0; var20 < var19; var20++) {
                var9[var20] = ((short *) (var1 + 0xc))[var20];
            }
            func_02080b40(var2, 0x8a);
            func_02080f8c((struct Struct_02080f8c *) var2, 0x8a,
                                       func_02081010(var2, 0x7a));
            func_02080cc0((struct Struct_02080cc0 *) var2, 0x8a, 0xf);
            var8 = 1;
            var3    = var19 != 0;
        }
    }

    if (var8 != 0) {
        func_02080fa8((struct Struct_02080fa8 *) var2, 0xa3, arg0->unknown_1014_ + 1);
        func_02080fa8((struct Struct_02080fa8 *) var2, 0xa4, arg0->unknown_1016_);
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
            func_020805f4(var2, var4);
#endif
            func_020806c4(var2, var4);
            func_02080f8c((struct Struct_02080f8c *) var2, var4, var22);
            func_02080fa8((struct Struct_02080fa8 *) var2, var5, var23);
            func_02080b40(var2, var4);
            func_02080b40(var2, var5);
            func_02080b40(var2, var6);
            func_ov003_0217818c(arg0, var24, var5, var6);
        }
        var4 = var4 + 1;
        var5 = var5 + 1;
        var6 = var6 + 1;
    }

    if (var3 == 0) {
        func_0208103c(var2, 0x143, var7);
        func_02080b40(var2, 0x143);
        func_02080b40(var2, 0x144);
        func_0208108c(var2, 0x143);
        func_0208108c(var2, 0x144);
    }
    func_020813ec(var2, 0x15);
}
