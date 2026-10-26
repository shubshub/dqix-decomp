#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>
#include "Resource/ItemTable.h"

struct Element020de650;
struct Field150Holder02052e2c;
struct Struct_02052df8;

struct Struct_ov003_0217599c_3 {
    int field0;
    unsigned int low : 27;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 1;
    unsigned int high : 2;
};
struct EquipEntry {
    Struct_ov003_0217599c_3 *unknown_0_;
    unsigned char unknown4[4];
    unsigned int category : 4;
    unsigned int unknown_8_4_ : 28;
    unsigned char unknown_c_[0xc];
    short itemId;
    unsigned char unknown_1a_[6];
};
struct Struct_ov003_0217599c_5 {
    unsigned char unknown0[0x194];
    EquipEntry entries[8];
    unsigned char unknown_294_[0x49c - 0x294];
    unsigned char unknown_49c_0_ : 1;
};
struct Struct_ov003_0217599c {
    #if defined(jpn)
    unsigned char unknown0[0x144];
#else
    unsigned char unknown0[0x150];
#endif
    Struct_ov003_0217599c_5 *view;
};
struct Struct_ov003_0217e33c {
    unsigned char v[8];
};
struct Struct_0206b37c {
    SafeAllocator allocator;
    char list[0x18];
    ItemTable *containerData;
    int unknown_30_;
    int field34;
};
struct Struct_01ff91ac_34 {
    char pad0[0x74];
    char container[4];
    char unknown_78_[0x103a - 0x78 - 0x800];
};
struct Struct_ov003_0217599c_2 {
#if defined(jpn)
    char padding0[0x7f0];
#else
    char padding0[0x874];
#endif
    ItemTable entries;
    char paddingAfterEntries[0x103a - 0x874 - sizeof(ItemTable)];
    short selected;
    unsigned char count;
    char unknown_103d_[6];
    signed char character;
};

extern "C" int *LinkSession_GetInstance();
extern "C" int LinkSession_IsActive(int *);
extern "C" short *func_02052e2c(Field150Holder02052e2c *);
extern "C" EquipEntry *ItemTable_Find(ItemTable *, int);
extern "C" void *ItemTable_Construct(void *);
extern "C" void func_0207cbe8(char *);
extern "C" void func_0207cc18(void *, EquipEntry *);
extern "C" void func_0207cc0c(char *);
extern "C" int func_020dd4c4(int, void *);
extern "C" int func_02052df8(Struct_02052df8 *, int);
extern "C" void func_02052d7c(Struct_ov003_0217599c *, int, short);
extern "C" void *func_02053c6c(unsigned char *);
extern "C" void PartyMember_Equip(void *, EquipEntry *, int);
extern "C" void func_0207c378(char *, int, int, int);
static inline int inline_ov003_0217599c(unsigned int type) {
    return type <= 7;
}
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
GameResources *GetGameResources();
extern "C" void func_ov017_0218f5a4(GameResources *, int, int, int, int);

#if defined(jpn)
extern int data_ov003_0217e388[9];
extern Struct_ov003_0217e33c data_ov003_0217e33c;
#else
extern int data_ov003_0217faf4[9];
extern Struct_ov003_0217e33c data_ov003_0217faac;
#endif

// JPN: func_ov003_0217599c (021749d4)
// USA: func_ov003_0217599c
extern "C" ARM int func_ov003_0217599c(Struct_ov003_0217599c_2 *menu) {
    GameState *gs        = GameState::GetInstance();
    int *search          = LinkSession_GetInstance();
    Struct_ov003_0217599c *c = (Struct_ov003_0217599c *) func_0200ff1c(gs, menu->character);
    if (!c) return 0;
    if (!func_02052e2c((Field150Holder02052e2c *) c)) return 0;
    EquipEntry *elem =
        ItemTable_Find(&menu->entries, menu->selected);
    if (!elem) return 0;
    unsigned int category = elem->category;
    Struct_0206b37c context;
    context.allocator.ResetAllocatorPointer();
    ItemTable_Construct(context.list);
    func_0207cbe8((char *) &context);
    func_0207cbe8((char *) &context);
    context.containerData = &menu->entries;
    func_0207cc18(&context, elem);
    func_0207cc0c((char *) &context);
    if (!inline_ov003_0217599c(category)) return 0;
    if (func_020dd4c4(menu->character, elem)) return 0;
#if defined(jpn)
    int var6 = data_ov003_0217e388[category];
#else
    int var6 = data_ov003_0217faf4[category];
#endif
    if (var6 < 0) return 1;
    char *bag      = (char *) GameState_GetParty(gs);
    int equippedId = func_02052df8((Struct_02052df8 *) c, var6);
    int same       = menu->selected == equippedId;
    if (!same) {
        func_02052d7c(c, var6, menu->selected);
        PartyMember_Equip(func_02053c6c((unsigned char *) c), elem, -1);
    }
    if (ItemTable_Find(&menu->entries, equippedId)) {
        func_0207c378(bag + 0x1d4, equippedId, 1, category);
    }
    menu->count--;
    if (same) return 1;
    if (equippedId == 0x4680) {
#if defined(jpn)
        Struct_ov003_0217e33c order = data_ov003_0217e33c;
#else
        Struct_ov003_0217e33c order = data_ov003_0217faac;
#endif
        unsigned char flags[2];
        for (unsigned char i = 0; i < 8; i++) {
            if (order.v[i] == 0xff) break;
            Struct_ov003_0217599c_5 *view   = c->view;
            EquipEntry *entry = &c->view->entries[order.v[i]];
            if (!entry || entry->itemId < 0) continue;
            Struct_ov003_0217599c_3 *var15 = entry->unknown_0_;
            if (!var15 || var15->unknown_7_5_) continue;
            flags[0] = var15->unknown_7_3_ ? 1 : 0;
            flags[1] = var15->unknown_7_4_ ? 1 : 0;
            if (flags[view->unknown_49c_0_]) continue;
#if defined(jpn)
            func_02052d7c(c, data_ov003_0217e388[i], -1);
#else
            func_02052d7c(c, data_ov003_0217faf4[i], -1);
#endif
            if (!entry) continue;
            func_0207c378(bag + 0x1d4, entry->itemId, 1, entry->category);
        }
    }
    if (LinkSession_IsActive(search)) {
        func_ov017_021c3fb4(menu->character, 1);
        func_ov017_021c4418(menu->character, -1);
    }
    GameResources *resources = GetGameResources();
    BackgroundLoader::GetInstance();
    func_ov017_0218f5a4(resources, menu->character, 1, 0, 0);
    return 1;
}
