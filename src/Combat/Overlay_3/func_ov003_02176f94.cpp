// USA: func_ov003_02176f94
#include <globaldefs.h>
#if defined(jpn)
enum {
    Enum_ov003_02176f94_2204 = 0x818
};
enum {
    Enum_ov003_02176f94_2164 = 0x7f0
};
enum {
    Enum_ov003_02176f94_4124 = 0xf98
};
enum {
    Enum_ov003_02176f94_4144 = 0xfac
};
enum {
    Enum_ov003_02176f94_4154 = 0xfb6
};
#else
enum {
    Enum_ov003_02176f94_2204 = 0x89c
};
enum {
    Enum_ov003_02176f94_2164 = 0x874
};
enum {
    Enum_ov003_02176f94_4124 = 0x101c
};
enum {
    Enum_ov003_02176f94_4144 = 0x1030
};
enum {
    Enum_ov003_02176f94_4154 = 0x103a
};
#endif

#include "GameState/GameState.h"

struct Obj2081;
void ClearElementFlag0x20_02080c20(struct Obj2081 *obj, int key);
void SetEntryLowNibbleAndElement02080c68(void *obj, int id, int value);
void ClearSublistEntriesFlag1_02080bac(void *obj, int id);
struct ItemTable;
struct Node02176f94;
struct Node02176f94 *ItemTable_Find(struct ItemTable *c, int key);
void *GetFieldAt0x150_02053c6c(unsigned char *obj);
struct Slots02083994;
int CountMatchingUntilNegative02083994(struct Slots02083994 *s, int value);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c *obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0 *obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8 *obj, int id, int value);
int SetEntryFlagById02080b2c(void *obj, int id);
void SetSublistEntriesFlag1_02080b54(void *obj, int id);
void SetElementFlag0x20_02080c04(struct Obj2081 *obj, int key);
short SumKeyedLookups02086bf4(char *obj, int key);
extern "C" void func_020813ec(void *obj, int key);
void *GameState_GetParty(GameState *battleStruct);

struct Struct_ov003_02176f94 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
};

struct Struct_ov003_02176f94_2 {
    unsigned char unknown_0_[Enum_ov003_02176f94_2204];
    Struct_0207fdcc_2* unknown_89c_;
    unsigned char unknown_8a0_[Enum_ov003_02176f94_4124 - Enum_ov003_02176f94_2204 - 4];
    int unknown_101c_[4];
    unsigned char unknown_102c_[Enum_ov003_02176f94_4144 - Enum_ov003_02176f94_4124 - 16];
    int unknown_1030_;
    unsigned char unknown_1034_[Enum_ov003_02176f94_4154 - Enum_ov003_02176f94_4144 - 4];
    short unknown_103a_;
};

static inline int inline_ov003_02176f94(unsigned int arg0) {
    return arg0 <= 7;
}

extern "C" ARM void func_ov003_02176f94(Menu02176f94* self) {
    struct Obj2081 *elem = self->menu;
    GameState *battle    = GameState::GetInstance();
    char *bag            = (char *) GameState_GetParty(battle);

    int var3    = 0x19;
    short var4    = 0xe9;
    short var5 = 0xeb;
    short var6 = 0xed;
    short var7 = 0xef;
    switch (arg0->unknown_1030_) {
        case 2:
            var3  = 0x1a;
            var4    = 0xf0;
            var5 = 0xf3;
            var6 = 0xf6;
            var7 = 0xf9;
            break;
        case 3:
            var5 = 0xff;
            var6 = 0x103;
            var7 = 0x107;
            var3  = 0x1b;
            var4    = 0xfb;
            break;
        case 4:
            var3  = 0x1c;
            var4    = 0x10a;
            var5 = 0x10f;
            var6 = 0x114;
            var7 = 0x119;
            break;
    }

    func_02080c20(var0, var3);
    func_02080c68(var0, var3, 0);
    func_02080bac(var0, var3);

    bool skip                 = true;
    struct Node02176f94 *node = ItemTable_Find(
        (struct ItemTable *) ((char*)self + kNodeOffset), self->selectedItem);
    if (node != NULL) skip = ShouldHideMemberCounts(node->type);
    if (!skip) {
        for (unsigned char i = 0; i < self->memberCount; i++) {
            int memberData;
            short count;
            int cid;
            cid                = (signed char) self->memberIds[i];
            memberData         = 0;
            count              = 0;
            GameObject *member = battle->GetPartyMemberByIndex(cid);
            if (member != NULL) {
                memberData = (int)member->baseStats_;
                count = CountMatchingUntilNegative02083994(
                    (struct Slots02083994 *) GetFieldAt0x150_02053c6c((unsigned char *) member), self->selectedItem);
            }
            func_02080f8c((struct Struct_02080f8c *) var0, var4, var11);
            func_02080cc0((struct Struct_02080cc0 *) var0, var4, func_020dcc98(var13));
            func_02080fa8((struct Struct_02080fa8 *) var0, var5, var12);
            if (var12 != 0) {
                func_02080b2c(var0, var7);
            } else {
                func_02080b2c(var0, var5);
                func_02080b2c(var0, var6);
            }
            var4++;
            var5++;
            var6 = var6 + 1;
            var7 = var7 + 1;
        }
    } else {
        func_02080b54(var0, var3);
        func_02080c04(var0, var3);
    }
    func_02080fa8((struct Struct_02080fa8 *) var0, var5,
                                                         func_02086bf4(var2, arg0->unknown_103a_));
    func_020813ec(var0, var3);
}
