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
struct Struct_ov000_02171640;
struct Struct_ov000_02171968;
struct Struct_0209a9dc_2;
struct Struct_020839dc;
struct Struct_0207d300;
struct Struct_0206f81c;
struct Struct_ov026_021dc8fc_4;
struct Struct_ov026_021dc8fc_5 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 1;
    unsigned int unknown_9_2_ : 2;
    unsigned int unknown_9_4_ : 20;
    char unknown_c_[8];
    unsigned short unknown_14_;
    char unknown_16_[2];
    unsigned int unknown_18_0_ : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
};
struct Struct_0201099c_9 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 23;
    char unknown_c_[8];
    unsigned short unknown_14_;
    char unknown_16_[10];
};
struct Struct_0206f81c_8 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
    char unknown_c_[0xc];
    short unknown_18_;
    char unknown_1a_[6];
};
struct Container_021dae60 { char pad0[0xd0]; ItemTable commands; };
struct CommandSlot {
    char pad0[0x10];
    unsigned char selections[8];
    signed char selection;
    char pad19[kEligibilityOffset - 0x19];
    unsigned char eligible;
};
struct Struct_ov026_021dc8fc {
    char unknown_0_[0x454];
    short unknown_454_[8];
    char unknown_464_[0x488 - 0x464];
    short unknown_488_[9];
    char unknown_49a_[Enum_02000c9c_F_2384 - 0x49a];
    int unknown_950_;
};
struct Struct_ov017_021af66c_5 { char unknown_0_[Enum_02000c9c_F_336]; Struct_ov026_021dc8fc* unknown_150_; };
struct Struct_ov026_021dc8fc_2 { unsigned short unknown_0_, unknown_2_; char unknown_4_[6]; unsigned short unknown_a_; };
struct Struct_0209a9dc_3 { unsigned short unknown_0_, unknown_2_; };
struct Struct_0208ab34_3 { char unknown_0_[0xf78]; unsigned char unknown_f78_[4]; unsigned char unknown_f7c_; };
struct Struct_ov026_021dc8fc_3 {
    char unknown_0_[0x22];
    unsigned short unknown_22_0_ : 2;
    unsigned short unknown_22_2_ : 4;
    unsigned short unknown_22_6_ : 10;
};

int GetFieldAt0x150_02053c6c(unsigned char*);
CommandSlot* FindSlotById_021dae60(Container_021dae60*, int);
void ZeroArr1a4AndFlag0x840217193c(Struct0217193c*);
void ZeroArr9cAndFlag0x8202171614(Struct02171614*);
Element020de650* ItemTable_Find(ItemTable*, int);
void SetBitInArray0x8ec_02083acc(unsigned char*, int);
void ClearBitInArray0x8ec_02083b28(unsigned char*, int);
int TestBitInArray0x8ec_02083b00(unsigned char*, int);
int CollectSetBitIndices020839dc(BitArray020839dc*, unsigned char*, int);
Entry0209a9dc* FindEntryById0209a9dc(Holder0209a9dc*, int);
CommandEntry* SearchBothTables02079e2c(char*, int);
void SetFieldAndUpdateCount02171640(S02171698*, int, int);
void SetFieldAndUpdateCount02171968(S021719c0*, int, int);
int CountPositiveSlots02083960(Slots02083960*);
void ZeroArr3f0AndFlag0x8602171b3c(Struct02171b3c*);
void SetPointerField0x3f002171b68(void*, int, void*);
Entry02083554* FindEntryByShortField02083554(Container02083554*, int);
int CheckFlag0x14Bit0x10Set_020882f8(unsigned char*);
int IsFlagBit8Set_021dce1c(FlagObj_021dce1c*);
extern "C" AbilityEntry* func_0209a594(void*, int);
extern "C" int func_0209ab7c(Holder0209a9dc*, GameObject*, unsigned char*);

// USA: func_ov026_021dc8fc
extern "C" ARM void func_ov026_021dc8fc(void*, void*, void*, Struct_ov026_021d8ba0_4* arg3,
                                        void* arg4, Struct_0209a9dc_2* arg5, int arg6) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = func_0200ff1c(var0, arg6);
    if (!var1) return;
    Struct_ov026_021dc8fc* var2 = (Struct_ov026_021dc8fc*)func_02053c6c((unsigned char*)var1);
    if (!var2) return;
    Struct_ov026_021db090_4* var3 = func_ov026_021dae60(arg3, arg6);
    if (!var3) return;
    func_ov000_0217193c((Struct_ov000_0217193c*)var3);
    func_ov000_02171614((Struct_ov000_02171614*)var3);
    short var4[0x11f];
    unsigned char var5[0x42];
    Struct_ov026_021dc8fc_5* var6[0xd5];
    int var7[8];
    int var8 = 0;
    memset(var4, -1, sizeof(var4));
    for (int var9 = 0x56f9; var9 <= 0x5712; ++var9) {
        short* var10 = ((Struct_ov017_021af66c_5*)var1)->unknown_150_->unknown_454_;
        int var11 = 0;
        for (int var12 = 0; var12 < 8; ++var12) {
            if (var9 == var10[var12]) { var11 = 1; break; }
        }
        Element020de650* entry = ItemTable_Find(&work->commands, (short)key);
        if (entry && entry->learnedType == 0x1f) {
            if (found) SetBitInArray0x8ec_02083acc((unsigned char*)learned, entry->bitIndex);
            else ClearBitInArray0x8ec_02083b28((unsigned char*)learned, entry->bitIndex);
        }
    }
    for (unsigned short var14 = 0; var14 < 0x11f; ++var14) {
        if (func_02083b00((unsigned char*)var2, var14)) {
            Struct_ov026_021dc8fc_2* var15 = func_0209a594(arg4, var14);
            if (var15 && var15->unknown_2_) {
                var4[var15->unknown_a_] = var15->unknown_2_;
                ++var8;
            }
        }
    }
    for (int var16 = 0; var16 < 0x11e; ++var16) {
        if (var4[var16] < 0) {
            for (int var17 = var16 + 1; var17 < 0x11f; ++var17) {
                if (var4[var17] >= 0) {
                    var4[var16] = var4[var17];
                    var4[var17] = -1;
                    break;
                }
            }
        }
    }
    int var18;
    if (((Struct_ov017_021af66c_5*)var1)->unknown_150_->unknown_950_ == 0)
        var18 = func_020839dc((Struct_020839dc*)var2, var5, 0x80);
    else var18 = func_0209ab7c(arg5, var1, var5);
    for (int var19 = 0; var19 < var18; ++var19) {
        Struct_0209a9dc_3* var20 = func_0209a9dc(arg5, var5[var19]);
        if (var20 && var20->unknown_2_) var4[var8++] = var20->unknown_2_;
    }
    Struct_02108e10* var21 = func_020797dc();
    for (int var22 = 0; var22 < var8; ++var22) var6[var22] = func_02079e2c((char*)var21, var4[var22]);
    int var23 = 0;
    int var24;
    int var25 = 0;
    for (var24 = 0; var24 < var8; ++var24) {
        Struct_ov026_021dc8fc_5* var26 = var6[var24];
        if (var26 && (var26->unknown_9_2_ & 2)) {
            if (var26->unknown_19_4_ == 2) {
                func_ov000_02171640((Struct_ov000_02171640*)var3, var23, (int)var26);
                ++var23;
            } else if (var26->unknown_19_4_ == 1) {
                func_ov000_02171968((Struct_ov000_02171968*)var3, var25, (int)var26);
                ++var25;
            }
        }
    }
    int equippedCount = CountPositiveSlots02083960((Slots02083960*)learned);
    for (int i = 0; i < 8; ++i) equippedIds[i] = learned->equipped[i];
    short* equipment = learned->equipment;
    int stored;
    unsigned char order[8] = {7, 8, 0, 1, 6, 4, 5, 0xff};
    int equipmentIndex;
    stored = 0;
    ZeroArr3f0AndFlag0x8602171b3c((Struct02171b3c*)slot);
    for (equipmentIndex = 0; equipmentIndex < 16; ++equipmentIndex) {
        if (equipmentIndex < 8) {
            if (equipmentIndex < equippedCount) {
                Element020de650* entry = ItemTable_Find(&work->commands, (short)equippedIds[equipmentIndex]);
                if (entry) {
                    SetPointerField0x3f002171b68(slot, stored, entry);
                    ++stored;
                }
            }
        } else {
            if (var32 == 8) {
                if (var30 > 4) var30 = 8;
                else if (var30 > 0) var30 = 4;
            }
            unsigned char var34 = var31[var32 - 8];
            if (var34 == 0xff) continue;
            Struct_0206f81c_8* var35 = func_02083554((Struct_0206f81c*)var2, var29[var34]);
            if (var35 && var35->unknown_18_ > 0) {
                int var36 = var35->unknown_8_0_ <= 7 ? 1 : 0;
                if (var36) {
                    func_ov000_02171b68(var3, var30, var35);
                    ++var30;
                }
            }
        }
    }
    int listed = 0;
    slot->eligible = 0;
    PartyRoster* roster = (PartyRoster*)GameState_GetParty(game);
    for (int i = 0; i < roster->count; ++i) {
        if (id == roster->ids[i]) { listed = 1; break; }
    }
    GameObject* var40 = var0->GetCombatantByIndex(arg6);
    if (var40) {
        if (func_020882f8((unsigned char*)var40->currentStats_) ||
            ((Struct_ov026_021dc8fc_3*)var40->currentStats_)->unknown_22_2_ ||
            func_ov026_021dce1c((Struct_ov026_021dc8fc_4*)var40)) {
            var3->unknown_87_ = 0;
            var3->unknown_10_[var3->unknown_18_] = 100;
        } else if (var37) var3->unknown_87_ = 1;
    }
}
