// USA: func_ov003_02176f94
#include <globaldefs.h>
#if defined(jpn)
enum {
    kRegion89c = 0x818
};
enum {
    kNodeOffset = 0x7f0
};
enum {
    Enum_ov003_02176f94_4124 = 0xf98
};
enum {
    Enum_ov003_02176f94_4144 = 0xfac
};
enum {
    kRegion103a = 0xfb6
};
#else
enum {
    kRegion89c = 0x89c
};
enum {
    kNodeOffset = 0x874
};
enum {
    Enum_ov003_02176f94_4124 = 0x101c
};
enum {
    Enum_ov003_02176f94_4144 = 0x1030
};
enum {
    kRegion103a = 0x103a
};
#endif

#include "GameState/GameState.h"

struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2 *obj, int key);
extern "C" void func_02080c68(void *obj, int id, int value);
extern "C" void func_02080bac(void *obj, int id);
struct ItemTable;
struct Node02176f94;
extern "C" struct Node02176f94 *ItemTable_Find(struct ItemTable *c, int key);
extern "C" void *func_02053c6c(unsigned char *obj);
struct Struct_02083994;
extern "C" int func_02083994(struct Struct_02083994 *s, int value);
struct Container02080f8c;
extern "C" void func_02080f8c(struct Container02080f8c *obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
struct Struct_02080cc0;
extern "C" void func_02080cc0(struct Struct_02080cc0 *obj, int id, int value);
struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8 *obj, int id, int value);
extern "C" int func_02080b2c(void *obj, int id);
extern "C" void func_02080b54(void *obj, int id);
extern "C" void func_02080c04(struct Struct_0207fdcc_2 *obj, int key);
extern "C" short func_02086bf4(char *obj, int key);
extern "C" void func_020813ec(void *obj, int key);
extern "C" void *GameState_GetParty(GameState *battleStruct);

struct Node02176f94 {
    char pad0[8];
    unsigned int type : 4;
    unsigned int pad8 : 28;
};

struct Struct_ov003_02176f94_2 {
    unsigned char unknown[kRegion89c];
    Struct_0207fdcc_2* menu;
    unsigned char unknown_8a0_[Enum_ov003_02176f94_4124 - kRegion89c - 4];
    int memberIds[4];
    unsigned char unknown_102c_[Enum_ov003_02176f94_4144 - Enum_ov003_02176f94_4124 - 16];
    int memberCount;
    unsigned char unknown_1034_[kRegion103a - Enum_ov003_02176f94_4144 - 4];
    short selectedItem;
};

static inline int inline_ov003_02176f94(unsigned int arg0) {
    return arg0 <= 7;
}

extern "C" ARM void func_ov003_02176f94(Struct_ov003_02176f94_2* self) {
    struct Struct_0207fdcc_2 *elem = self->menu;
    GameState *battle    = GameState::GetInstance();
    char *bag            = (char *) GameState_GetParty(battle);

    int var3    = 0x19;
    short var4    = 0xe9;
    short idCount = 0xeb;
    short var6 = 0xed;
    short var7 = 0xef;
    switch (self->memberCount) {
        case 2:
            var3  = 0x1a;
            var4    = 0xf0;
            idCount = 0xf3;
            var6 = 0xf6;
            var7 = 0xf9;
            break;
        case 3:
            idCount = 0xff;
            var6 = 0x103;
            var7 = 0x107;
            var3  = 0x1b;
            var4    = 0xfb;
            break;
        case 4:
            var3  = 0x1c;
            var4    = 0x10a;
            idCount = 0x10f;
            var6 = 0x114;
            var7 = 0x119;
            break;
    }

    func_02080c20(elem, var3);
    func_02080c68(elem, var3, 0);
    func_02080bac(elem, var3);

    bool var8                 = true;
    struct Node02176f94 *node = ItemTable_Find(
        (struct ItemTable *) ((char*)self + kNodeOffset), self->selectedItem);
    if (node != NULL) var8 = inline_ov003_02176f94(node->type);
    if (!var8) {
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
                count = func_02083994(
                    (struct Struct_02083994 *) func_02053c6c((unsigned char *) member), self->selectedItem);
            }
            func_02080f8c((struct Container02080f8c *) elem, var4, memberData);
            func_02080cc0((struct Struct_02080cc0 *) elem, var4, func_020dcc98(cid));
            func_02080fa8((struct Struct_02080fa8 *) elem, idCount, count);
            if (count != 0) {
                func_02080b2c(elem, var7);
            } else {
                func_02080b2c(elem, idCount);
                func_02080b2c(elem, var6);
            }
            var4++;
            idCount++;
            var6 = var6 + 1;
            var7 = var7 + 1;
        }
    } else {
        func_02080b54(elem, var3);
        func_02080c04(elem, var3);
    }
    func_02080fa8((struct Struct_02080fa8 *) elem, idCount,
                                                         func_02086bf4(bag, self->selectedItem));
    func_020813ec(elem, var3);
}
