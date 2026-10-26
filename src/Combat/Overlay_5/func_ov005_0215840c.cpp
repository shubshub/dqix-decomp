#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct Struct_ov005_0215840c {
    unsigned int unk_0;
    unsigned int unknown_4_0_ : 27;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 3;
};

struct PartEntry {
    Struct_ov005_0215840c* model_;
    int unk_4;
    unsigned int category_ : 4;
    unsigned int unknown_8_4_ : 28;
};

struct PartyMemberData {
    char unk_0[0x49c];
    unsigned char female_ : 1;
    unsigned char unknown_49c_1_ : 7;
};

struct Struct_02052df8 {
    char unk_0[LOW_REGION(0x144, 0x150)];
    PartyMemberData* unknown_150_;
};

struct ItemTable;

struct EquipmentMenu {
    char unk_0[0xdf4];
    ItemTable* items_;
};

extern "C" const unsigned char data_ov005_0215cc0c[];

extern "C" int func_02052df8(Struct_02052df8* member, int part);
extern "C" PartEntry* ItemTable_Find(ItemTable* items, int id);
extern "C" PartyMemberData* func_02053c6c(unsigned char* member);
extern "C" void func_02052d7c(Struct_02052df8* member, int part, short item);
extern "C" void PartyMember_Equip(PartyMemberData* data, PartEntry* item, int unk);
extern "C" void func_02083738(PartyMemberData* data, int category);
extern "C" int func_0207c378(void* lists, int item, int count, int list);

// USA: func_ov005_0215840c
extern "C" ARM int func_ov005_0215840c(EquipmentMenu* self, int member) {
    GameState* gameState = GameState::GetInstance();
    Struct_02052df8* partyMember = (Struct_02052df8*)func_0200ff1c(gameState, member);
    if (partyMember == NULL)
        return 0;
    int removed = 0;
    unsigned int female = partyMember->unknown_150_->female_;
    for (int i = 0; i < 7; i++) {
        unsigned char part = data_ov005_0215cc0c[i];
        int current = func_02052df8(partyMember, part);
        PartEntry* entry = ItemTable_Find(self->items_, current);
        if (entry == NULL)
            continue;
        unsigned int var8[2];
        var8[0] = entry->model_->unknown_7_3_;
        var8[1] = entry->model_->unknown_7_4_;
        if (var8[female] != 0)
            continue;
        short replacement = -1;
        int unk = -1;
        if (part == 0) {
            unk = 0;
            replacement = 1000;
        }
        func_02052d7c(partyMember, part, -1);
        PartyMemberData* data = func_02053c6c((unsigned char*)partyMember);
        PartEntry* replacementEntry = ItemTable_Find(self->items_, replacement);
        if (replacementEntry != NULL)
            PartyMember_Equip(data, replacementEntry, unk);
        else
            func_02083738(data, entry->category_);
        func_0207c378((char*)GameState_GetParty(gameState) + 0x1d4, current, 1, entry->category_);
        removed = 1;
    }
    return removed;
}
