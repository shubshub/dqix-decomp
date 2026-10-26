#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "Resource/ItemTable.h"

#if defined(jpn)
enum Enum_02000c9c_F { Enum_02000c9c_F_336 = 0x144, Enum_02000c9c_F_2384 = 0x8b8, Enum_02000c9c_F_135 = 0xc7 };
#else
enum Enum_02000c9c_F { Enum_02000c9c_F_336 = 0x150, Enum_02000c9c_F_2384 = 0x950, Enum_02000c9c_F_135 = 0x87 };
#endif

#include "GameState/GameState.h"

struct Struct_ov000_0217193c;
struct Struct_ov000_02171614;
struct Struct_ov000_02171b3c;
struct S02171698;
struct S021719c0;
struct Struct_0209a9dc_2;
struct Struct_020839dc;
struct Struct_0207d300;
struct Struct_0206f81c;
struct Struct_ov026_021dc8fc_4;
struct Struct_ov026_021dc8fc_5 {
    char pad0[8];
    unsigned int category : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 1;
    unsigned int unknown_9_2_ : 2;
    unsigned int unknown_9_4_ : 20;
    char unknown_c_[8];
    unsigned short unknown_14_;
    char pad16[2];
    unsigned int unknown_18_0_ : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
};
struct Element020de650 {
    char pad0[8];
    unsigned int category : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 23;
    char unknown_c_[8];
    unsigned short unknown_14_;
    char pad16[10];
};
struct Struct_0206f81c_8 {
    char pad0[8];
    unsigned int category : 4;
    unsigned int unknown_8_4_ : 28;
    char unknown_c_[0xc];
    short id;
    char pad1a[6];
};
struct Container_021dae60 { char pad0[0xd0]; ItemTable commands; };
struct Struct_ov026_021db090_4 {
    char pad0[0x10];
    unsigned char unknown_10_[8];
    signed char selection;
    char unknown_19_[Enum_02000c9c_F_135 - 0x19];
    unsigned char unknown_87_;
};
struct Struct_ov026_021dc8fc {
    char pad0[0x454];
    short equipped[8];
    char unknown_464_[0x488 - 0x464];
    short equipment[9];
    char unknown_49a_[Enum_02000c9c_F_2384 - 0x49a];
    int unknown_950_;
};
struct CombatantView { char pad0[Enum_02000c9c_F_336]; Struct_ov026_021dc8fc* commands; };
struct Struct_ov026_021dc8fc_2 { unsigned short id, command; char pad4[6]; unsigned short order; };
struct Struct_0209a9dc_3 { unsigned short id, command; };
struct PartyRoster { char pad0[0xf78]; unsigned char ids[4]; unsigned char count; };
struct Struct_ov026_021dc8fc_3 {
    char pad0[0x22];
    unsigned short unknown_22_0_ : 2;
    unsigned short blocked : 4;
    unsigned short reserved6 : 10;
};

extern "C" int func_02053c6c(unsigned char*);
extern "C" Struct_ov026_021db090_4* func_ov026_021dae60(Container_021dae60*, int);
extern "C" void func_ov000_0217193c(Struct_ov000_0217193c*);
extern "C" void func_ov000_02171614(Struct_ov000_02171614*);
extern "C" Element020de650* ItemTable_Find(ItemTable*, int);
extern "C" void func_02083acc(unsigned char*, int);
extern "C" void func_02083b28(unsigned char*, int);
extern "C" int func_02083b00(unsigned char*, int);
extern "C" int func_020839dc(Struct_020839dc*, unsigned char*, int);
extern "C" Struct_0209a9dc_3* func_0209a9dc(Struct_0209a9dc_2*, int);
extern "C" Struct_ov026_021dc8fc_5* func_02079e2c(char*, int);
extern "C" void func_ov000_02171640(S02171698*, int, int);
extern "C" void func_ov000_02171968(S021719c0*, int, int);
extern "C" int func_02083960(Struct_0207d300*);
extern "C" void func_ov000_02171b3c(Struct_ov000_02171b3c*);
extern "C" void func_ov000_02171b68(void*, int, void*);
extern "C" Struct_0206f81c_8* func_02083554(Struct_0206f81c*, int);
extern "C" int func_020882f8(unsigned char*);
extern "C" int func_ov026_021dce1c(Struct_ov026_021dc8fc_4*);
extern "C" Struct_ov026_021dc8fc_2* func_0209a594(void*, int);
extern "C" int func_0209ab7c(Struct_0209a9dc_2*, GameObject*, unsigned char*);

// USA: func_ov026_021dc8fc
extern "C" ARM void func_ov026_021dc8fc(void*, void*, void*, Container_021dae60* work,
                                        void* arg4, Struct_0209a9dc_2* holder, int id) {
    GameState* game = GameState::GetInstance();
    GameObject* object = func_0200ff1c(game, id);
    if (!object) return;
    Struct_ov026_021dc8fc* var2 = (Struct_ov026_021dc8fc*)func_02053c6c((unsigned char*)object);
    if (!var2) return;
    Struct_ov026_021db090_4* slot = func_ov026_021dae60(work, id);
    if (!slot) return;
    func_ov000_0217193c((Struct_ov000_0217193c*)slot);
    func_ov000_02171614((Struct_ov000_02171614*)slot);
    short var4[0x11f];
    unsigned char var5[0x42];
    Struct_ov026_021dc8fc_5* entries[0xd5];
    int equippedIds[8];
    int count = 0;
    memset(var4, -1, sizeof(var4));
    for (int key = 0x56f9; key <= 0x5712; ++key) {
        short* equipped = ((CombatantView*)object)->commands->equipped;
        int found = 0;
        for (int i = 0; i < 8; ++i) {
            if (key == equipped[i]) { found = 1; break; }
        }
        Element020de650* entry = ItemTable_Find(&work->commands, (short)key);
        if (entry && entry->unknown_8_4_ == 0x1f) {
            if (found) func_02083acc((unsigned char*)var2, entry->unknown_14_);
            else func_02083b28((unsigned char*)var2, entry->unknown_14_);
        }
    }
    for (unsigned short i = 0; i < 0x11f; ++i) {
        if (func_02083b00((unsigned char*)var2, i)) {
            Struct_ov026_021dc8fc_2* var15 = func_0209a594(arg4, i);
            if (var15 && var15->command) {
                var4[var15->order] = var15->command;
                ++count;
            }
        }
    }
    for (int i = 0; i < 0x11e; ++i) {
        if (var4[i] < 0) {
            for (int j = i + 1; j < 0x11f; ++j) {
                if (var4[j] >= 0) {
                    var4[i] = var4[j];
                    var4[j] = -1;
                    break;
                }
            }
        }
    }
    int var18;
    if (((CombatantView*)object)->commands->unknown_950_ == 0)
        var18 = func_020839dc((Struct_020839dc*)var2, var5, 0x80);
    else var18 = func_0209ab7c(holder, object, var5);
    for (int i = 0; i < var18; ++i) {
        Struct_0209a9dc_3* entry = func_0209a9dc(holder, var5[i]);
        if (entry && entry->command) var4[count++] = entry->command;
    }
    ActionDataTables* var21 = func_020797dc();
    for (int i = 0; i < count; ++i) entries[i] = func_02079e2c((char*)var21, var4[i]);
    int var23 = 0;
    int var24;
    int var25 = 0;
    for (var24 = 0; var24 < count; ++var24) {
        Struct_ov026_021dc8fc_5* entry = entries[var24];
        if (entry && (entry->unknown_9_2_ & 2)) {
            if (entry->unknown_19_4_ == 2) {
                func_ov000_02171640((S02171698*)slot, var23, (int)entry);
                ++var23;
            } else if (entry->unknown_19_4_ == 1) {
                func_ov000_02171968((S021719c0*)slot, var25, (int)entry);
                ++var25;
            }
        }
    }
    int var27 = func_02083960((Struct_0207d300*)var2);
    for (int i = 0; i < 8; ++i) equippedIds[i] = var2->equipped[i];
    short* equipment = var2->equipment;
    int var30;
    unsigned char order[8] = {7, 8, 0, 1, 6, 4, 5, 0xff};
    int equipmentIndex;
    var30 = 0;
    func_ov000_02171b3c((Struct_ov000_02171b3c*)slot);
    for (equipmentIndex = 0; equipmentIndex < 16; ++equipmentIndex) {
        if (equipmentIndex < 8) {
            if (equipmentIndex < var27) {
                Element020de650* entry = ItemTable_Find(&work->commands, (short)equippedIds[equipmentIndex]);
                if (entry) {
                    func_ov000_02171b68(slot, var30, entry);
                    ++var30;
                }
            }
        } else {
            if (equipmentIndex == 8) {
                if (var30 > 4) var30 = 8;
                else if (var30 > 0) var30 = 4;
            }
            unsigned char index = order[equipmentIndex - 8];
            if (index == 0xff) continue;
            Struct_0206f81c_8* entry = func_02083554((Struct_0206f81c*)var2, equipment[index]);
            if (entry && entry->id > 0) {
                int var36 = entry->category <= 7 ? 1 : 0;
                if (var36) {
                    func_ov000_02171b68(slot, var30, entry);
                    ++var30;
                }
            }
        }
    }
    int var37 = 0;
    slot->unknown_87_ = 0;
    PartyRoster* roster = (PartyRoster*)GameState_GetParty(game);
    for (int i = 0; i < roster->count; ++i) {
        if (id == roster->ids[i]) { var37 = 1; break; }
    }
    GameObject* combatant = game->GetCombatantByIndex(id);
    if (combatant) {
        if (func_020882f8((unsigned char*)combatant->currentStats_) ||
            ((Struct_ov026_021dc8fc_3*)combatant->currentStats_)->blocked ||
            func_ov026_021dce1c((Struct_ov026_021dc8fc_4*)combatant)) {
            slot->unknown_87_ = 0;
            slot->unknown_10_[slot->selection] = 100;
        } else if (var37) slot->unknown_87_ = 1;
    }
}
