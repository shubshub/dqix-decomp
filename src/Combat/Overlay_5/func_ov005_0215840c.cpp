#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct Struct_ov005_0215840c {
    unsigned int unknown_0_;
    unsigned int unknown_4_0_ : 27;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 3;
};

struct Struct_ov005_021556e4 {
    Struct_ov005_0215840c* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
};

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
    unsigned char unknown_49c_1_ : 7;
};

struct Struct_02052df8 {
    char unknown_0_[LOW_REGION(0x144, 0x150)];
    Struct_ov005_0215840c_2* unknown_150_;
};

struct ItemTable;

struct EquipmentMenu {
    char unk_0[0xdf4];
    ItemTable* items_;
};

extern "C" const unsigned char data_ov005_0215cc0c[];

int GetHalfwordEntryFromField150(Field150Holder02052df8* member, int part);
PartEntry* ItemTable_Find(ItemTable* items, int id);
PartyMemberData* GetFieldAt0x150_02053c6c(unsigned char* member);
extern "C" void func_02052d7c(Field150Holder02052df8* member, int part, short item);
extern "C" void PartyMember_Equip(PartyMemberData* data, PartEntry* item, int unk);
extern "C" void func_02083738(PartyMemberData* data, int category);
extern "C" int func_0207c378(void* lists, int item, int count, int list);

// USA: func_ov005_0215840c
extern "C" ARM int func_ov005_0215840c(Struct_ov005_02153954* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    Struct_02052df8* var1 = (Struct_02052df8*)func_0200ff1c(var0, arg1);
    if (var1 == NULL)
        return 0;
    int removed = 0;
    unsigned int female = partyMember->data_->female_;
    for (int i = 0; i < 7; i++) {
        unsigned char part = data_ov005_0215cc0c[i];
        int current = GetHalfwordEntryFromField150(partyMember, part);
        PartEntry* entry = ItemTable_Find(self->items_, current);
        if (entry == NULL)
            continue;
        unsigned int var8[2];
        var8[0] = var7->unknown_0_->unknown_7_3_;
        var8[1] = var7->unknown_0_->unknown_7_4_;
        if (var8[var3] != 0)
            continue;
        short var9 = -1;
        int var10 = -1;
        if (var5 == 0) {
            var10 = 0;
            var9 = 1000;
        }
        func_02052d7c(partyMember, part, -1);
        PartyMemberData* data = GetFieldAt0x150_02053c6c((unsigned char*)partyMember);
        PartEntry* replacementEntry = ItemTable_Find(self->items_, replacement);
        if (replacementEntry != NULL)
            PartyMember_Equip(data, replacementEntry, unk);
        else
            func_02083738(data, entry->category_);
        func_0207c378((char*)GameState_GetParty(gameState) + 0x1d4, current, 1, entry->category_);
        removed = 1;
    }
    return var2;
}
