#include <globaldefs.h>
#include "Resource/ItemTable.h"
#if defined(jpn)
enum {
    Enum_ov003_02177dd4_2048 = 0x77c
};
enum {
    Enum_ov003_02177dd4_2204 = 0x818
};
enum {
    Enum_ov003_02177dd4_2208 = 0x81c
};
enum {
    Enum_ov003_02177dd4_4108 = 0xf88
};
#else
enum {
    Enum_ov003_02177dd4_2048 = 0x800
};
enum {
    Enum_ov003_02177dd4_2204 = 0x89c
};
enum {
    Enum_ov003_02177dd4_2208 = 0x8a0
};
enum {
    Enum_ov003_02177dd4_4108 = 0x100c
};
#endif
#include "GameState/GameState.h"

extern "C" unsigned char func_0207ca94(int arg0);
extern "C" int func_ov003_02175f90(void *arg0);
struct Struct_020a0b8c {
    short* unknown_0_;
    signed char* unknown_4_;
    short unknown_8_;
};
struct Struct_0207c258 {
    char unknown_0_[0xbd0];
    short* unknown_bd0_[8];
    unsigned char* unknown_bf0_[8];
    short unknown_c10_[8];
    unsigned char unknown_c20_[8];
    unsigned char unknown_c28_[8];
};
struct Struct_ov003_02177dd4_2 {
    Struct_020a0b8c unknown_0_;
    short unknown_c_[152];
    signed char unknown_13c_[152];
    Struct_0207c258 unknown_1d4_;
};
int CountNonZeroValues020a0b8c(struct S_a0b8c *p);
struct Obj2081;
void ClearElementFlag0x20_02080c20(struct Obj2081 *obj, int key);
void SetEntryLowNibbleAndElement02080c68(void *obj, int id, int value);
void ClearSublistEntriesFlag1_02080bac(void *obj, int id);
void ClearSublistEntriesFlag2_0208065c(void *obj, int id);
void SetOrClearEntryFlag0x102081130(void *obj, int id, int set);
void AddSublistEntryFlag2_020806b0(void *obj, int id);
int SetEntryFlagById02080b2c(void *obj, int id);
int FindNthPositiveShort0207c6b8(unsigned char *obj, unsigned int index, int target);
struct Element020de650;
struct Element020de650 {
    char pad0[4];
    int value;
    char pad8[0x1a - 8];
    unsigned short count;
};
struct Element020de650 *ItemTable_Find(struct ItemTable *c, int key);
short GetNthPositiveEntryValue_0207c72c(void *obj, unsigned int index, short n);
extern "C" void func_ov003_0217818c(void *self, struct Element020de650 *elem, int id, int value);
void Forward0207f7acObjPlus4Size0x40_020805f4(void *obj, int value);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c *obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8 *obj, int id, int value);
int LookupValueByEntryKey02081010(void *obj, int key);
extern "C" void func_020813ec(void *obj, int key);

struct ListMenu_02177dd4 {
    unsigned char pad0[kRegion800 + 0x74];
    struct ItemTable container;
    unsigned char paddingAfterContainer[kRegion89c - kRegion800 - 0x74 - sizeof(ItemTable)];
    struct Obj2081 *elemObj;
    unsigned char pad8a0[kRegion100c - kRegion8a0];
    short mode;
    short cursor;
    short field_0x1010;
    short tableCursor;
    short page;
    short pageCount;
};

// JPN: func_ov003_02177dd4 (02176d60)
// USA: func_ov003_02177dd4
extern "C" ARM void func_ov003_02177dd4(ListMenu_02177dd4 *self) {
    Inventory02177dd4* inventory = static_cast<Inventory02177dd4*>(GameState_GetParty(GameState::GetInstance()));
    unsigned int table  = 0;
    short hdr;
    short idD;
    short pageId;
    short pageCountId;
    short key;
    int count;
    short *keys             = 0;
    signed char *vals       = 0;
    struct Obj2081 *elemObj = self->elemObj;
    int group               = 0x16;
    hdr                     = 0xa6;
    short idA               = 0xa7;
    short idB               = 0xaf;
    short idC               = 0xb7;
    idD                     = 0xbf;
    short idE               = 0xc7;
    pageId                  = 0xcf;
    pageCountId             = 0xd0;
    short perPage           = 8;

    if (arg0->unknown_100c_ == 0x77) {
        short var17 = arg0->unknown_1012_ - 0x11e;
        var1            = func_0207ca94(var17);
        var7            = func_ov003_02175f90(arg0);
        arg0->unknown_1016_  = (var7 + 4) / 5;
        if (arg0->unknown_1016_ == 0) {
            arg0->unknown_1016_ = 1;
        }
        var12         = 0x127;
        var6         = var17 + 0x11e;
        var11       = 0x1e;
        var2         = 0x126;
        var13         = 0x12c;
        var14         = 0x131;
        var3         = 0x136;
        var15         = 0x13b;
        var4      = 0x140;
        var5 = 0x141;
        var16     = 5;
    } else {
        var7 = func_020a0b8c(&var0->unknown_0_);
        var8  = var0->unknown_c_;
        var9  = var0->unknown_13c_;
        var6   = 0x7a;
    }

    func_02080c20(var10, var11);
    func_02080c68(var10, var11, 0);
    func_02080bac(var10, var11);
    func_0208065c(var10, var11);
    func_02081130(var10, var11, var16 < var7);

    short var18              = arg0->unknown_1014_ * var16;
    short var19            = var18 + var16;
    for (; var18 < var19; var18++) {
        if (var7 <= var18) {
            func_020806b0(var10, var12);
            func_02080b2c(var10, var12);
            func_02080b2c(var10, var13);
            func_02080b2c(var10, var14);
            func_02080b2c(var10, var3);
            func_02080b2c(var10, var15);
        } else {
            int var20 = 0;
            int var21   = 0;
            int var22;
            if (var8 != 0) {
                var22 = var8[var18];
            } else {
                var22 = func_0207c6b8(((unsigned char*)(&var0->unknown_1d4_)), var1, var18);
            }
            struct Element020de650 *elem = ItemTable_Find(&self->container, k);
            if (elem != NULL) {
                value = elem->value;
                num   = elem->count;
            }
            int var24;
            if (var9 != 0) {
                var24 = var9[var18];
            } else {
                var24 = func_0207c72c(&var0->unknown_1d4_, var1, var18);
            }
            func_ov003_0217818c(arg0, var23, var13, var14);
#if !defined(jpn)
            func_020805f4(var10, var12);
#endif
            func_02080f8c((struct Struct_02080f8c *) var10, var12, var20);
            func_02080fa8((struct Struct_02080fa8 *) var10, var13, var21);
            func_02080fa8((struct Struct_02080fa8 *) var10, var15, var24);
        }
        var12++;
        var13++;
        var14++;
        var3++;
        var15++;
    }

    func_02080f8c((struct Struct_02080f8c *) var10, var2, func_02081010(var10, var6));
    func_02080fa8((struct Struct_02080fa8 *) var10, var4, arg0->unknown_1014_ + 1);
    func_02080fa8((struct Struct_02080fa8 *) var10, var5, arg0->unknown_1016_);
    func_020813ec(var10, var11);
}
