#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>
#include "Resource/ItemTable.h"

struct Element020de650;
struct Field150Holder02052e2c;
struct Field150Holder02052df8;

struct Struct_ov003_0217599c_3 {
    int unknown_0_;
    unsigned int unknown_4_0_ : 27;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 1;
    unsigned int unknown_7_6_ : 2;
};
struct Struct_ov003_0217599c_4 {
    Struct_ov003_0217599c_3 *unknown_0_;
    unsigned char unknown_4_[4];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
    unsigned char unknown_c_[0xc];
    short unknown_18_;
    unsigned char unknown_1a_[6];
};
struct Struct_ov003_0217599c_5 {
    unsigned char unknown_0_[0x194];
    Struct_ov003_0217599c_4 unknown_194_[8];
    unsigned char unknown_294_[0x49c - 0x294];
    unsigned char unknown_49c_0_ : 1;
};
struct Struct_ov003_0217599c {
    #if defined(jpn)
    unsigned char unknown_0_[0x144];
#else
    unsigned char unknown1_0_[0x150];
#endif
    Struct_ov003_0217599c_5 *unknown_150_;
};
struct Struct_ov003_0217e33c {
    unsigned char unknown_0_[8];
};
struct TextContext {
    SafeAllocator allocator;
    char list[0x18];
    ItemTable *containerData;
    int field30;
    int field34;
};
struct Struct_01ff91ac_34 {
    char unknown_0_[0x74];
    char unknown_74_[4];
    char unknown_78_[0x103a - 0x78 - 0x800];
};
struct Struct_ov003_0217599c_2 {
#if defined(jpn)
    char unknown_0_[0x7f0];
#else
    char unknown1_0_[0x874];
#endif
    ItemTable entries;
    char paddingAfterEntries[0x103a - 0x874 - sizeof(ItemTable)];
    short selected;
    unsigned char count;
    char pad3d[6];
    signed char character;
};

extern "C" int *LinkSession_GetInstance();
int LinkSession_IsActive(int *);
short *GetField150Ptr0x488_02052e2c(Field150Holder02052e2c *);
EquipEntry *ItemTable_Find(ItemTable *, int);
void *ItemTable_Construct(void *);
void InitStruct0207cbe8(char *);
extern "C" void func_0207cc18(void *, EquipEntry *);
void InitStruct0207cc0c(char *);
extern "C" int func_020dd4c4(int, void *);
int GetHalfwordEntryFromField150(Field150Holder02052df8 *, int);
extern "C" void func_02052d7c(Combatant0217599c *, int, short);
void *GetFieldAt0x150_02053c6c(unsigned char *);
extern "C" void PartyMember_Equip(void *, EquipEntry *, int);
extern "C" void func_0207c378(char *, int, int, int);
static inline int inline_ov003_0217599c(unsigned int arg0) {
    return arg0 <= 7;
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
extern "C" ARM int func_ov003_0217599c(MenuB *menu) {
    GameState *gs        = GameState::GetInstance();
    int *search          = LinkSession_GetInstance();
    Combatant0217599c *c = (Combatant0217599c *) GetCombatantWithFlag0x100_0200ff1c(gs, menu->character);
    if (!c) return 0;
    if (!GetField150Ptr0x488_02052e2c((Field150Holder02052e2c *) c)) return 0;
    EquipEntry *elem =
        ItemTable_Find(&menu->entries, menu->selected);
    if (!elem) return 0;
    unsigned int category = elem->category;
    TextContext context;
    context.allocator.ResetAllocatorPointer();
    ItemTable_Construct(context.list);
    InitStruct0207cbe8((char *) &context);
    InitStruct0207cbe8((char *) &context);
    context.containerData = &menu->entries;
    func_0207cc18(&context, elem);
    InitStruct0207cc0c((char *) &context);
    if (!IsType0217599c(category)) return 0;
    if (func_020dd4c4(menu->character, elem)) return 0;
#if defined(jpn)
    int var6 = data_ov003_0217e388[var4];
#else
    int var6 = data_ov003_0217faf4[var4];
#endif
    if (slotId < 0) return 1;
    char *bag      = (char *) GameState_GetParty(gs);
    int equippedId = GetHalfwordEntryFromField150((Field150Holder02052df8 *) c, slotId);
    int same       = menu->selected == equippedId;
    if (!same) {
        func_02052d7c(c, slotId, menu->selected);
        PartyMember_Equip(GetFieldAt0x150_02053c6c((unsigned char *) c), elem, -1);
    }
    if (ItemTable_Find(&menu->entries, equippedId)) {
        func_0207c378(bag + 0x1d4, equippedId, 1, category);
    }
    arg0->unknown_103c_--;
    if (var9) return 1;
    if (var8 == 0x4680) {
#if defined(jpn)
        Struct_ov003_0217e33c var10 = data_ov003_0217e33c;
#else
        Struct_ov003_0217e33c var10 = data_ov003_0217faac;
#endif
        unsigned char var11[2];
        for (unsigned char var12 = 0; var12 < 8; var12++) {
            if (var10.unknown_0_[var12] == 0xff) break;
            Struct_ov003_0217599c_5 *var13   = var2->unknown_150_;
            Struct_ov003_0217599c_4 *var14 = &var2->unknown_150_->unknown_194_[var10.unknown_0_[var12]];
            if (!var14 || var14->unknown_18_ < 0) continue;
            Struct_ov003_0217599c_3 *var15 = var14->unknown_0_;
            if (!var15 || var15->unknown_7_5_) continue;
            var11[0] = var15->unknown_7_3_ ? 1 : 0;
            var11[1] = var15->unknown_7_4_ ? 1 : 0;
            if (var11[var13->unknown_49c_0_]) continue;
#if defined(jpn)
            func_02052d7c(var2, data_ov003_0217e388[var12], -1);
#else
            func_02052d7c(var2, data_ov003_0217faf4[var12], -1);
#endif
            if (!var14) continue;
            func_0207c378(var7 + 0x1d4, var14->unknown_18_, 1, var14->unknown_8_0_);
        }
    }
    if (LinkSession_IsActive(search)) {
        func_ov017_021c3fb4(menu->character, 1);
        func_ov017_021c4418(menu->character, -1);
    }
    GameResources *var16 = GetGameResources();
    BackgroundLoader::GetInstance();
    func_ov017_0218f5a4(var16, arg0->unknown_1043_, 1, 0, 0);
    return 1;
}
