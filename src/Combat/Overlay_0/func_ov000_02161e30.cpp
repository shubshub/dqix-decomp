#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_02070b6c_3;
struct Struct_0206f01c_2;
struct Struct_02048850_2;
struct Struct_02048850;
struct Struct_02048934 { char unknown_0_[0x2c]; char unknown_2c_[1]; };
struct Struct_ov000_02161e30_3 {
    unsigned char unknown_0_;
    char unknown_1_;
    unsigned short unknown_2_;
    unsigned int unknown_4_;
};
struct Struct_ov000_02161e30_4 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    char unknown_3_[7];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    char unknown_b_[0xd];
};
struct Struct_0208ab34_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    char unknown_2_[2];
    Struct_ov000_02161e30_4 unknown_4_[3];
    Struct_ov000_02161e30_3 unknown_4c_[3];
};
struct Struct_ov000_02161e30_5 {
    Random unknown_0_;
    char unknown_20_[0x81b0 - sizeof(Random)];
    Struct_0208ab34_3 unknown_81b0_;
};
struct Struct_ov000_02161e30_6 {
    char unknown_0_[0x678];
    char unknown_678_[0xc];
    char unknown_684_[0xc];
};
struct Struct_ov000_02161e30 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    Struct_ov000_02161e30_5* unknown_29c_;
    Struct_ov000_02161e30_6* unknown_2a0_;
};
struct Struct_ov000_02161e30_2 {
    unsigned short unknown_0_, unknown_2_, unknown_4_, unknown_6_;
    char unknown_8_[0x1d];
    unsigned char unknown_25_;
};
struct Struct_ov000_0215ab88 {
    char unknown_0_[0x138];
    Struct_ov000_02161e30_2* unknown_138_;
    char unknown_13c_[0xc];
    Struct_02048934* unknown_148_;
    char unknown_14c_[0x30];
    unsigned char unknown_17c_;
    char unknown_17d_[7];
    unsigned char unknown_184_;
    char unknown_185_;
    unsigned short unknown_186_;
    unsigned short unknown_188_, unknown_18a_;
    unsigned char unknown_18c_, unknown_18d_;
};
extern "C" int* LinkSession_GetInstance();
FieldStruct02048934* SearchWithLow15Comparator02070fd0(Container02070e60*, int);
Param02048850* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
Combatant* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
void ZeroStruct021620d8(ZeroableStruct021620d8*);
void FindOrAssignSlot02167c28(unsigned char*, int);
extern "C" void func_020891cc(CombatBlob*);
extern "C" void func_02089630(CombatBlob*, void*, int);
void SetupFieldsFromParam02048850(Obj02048850*, Param02048850*);
void SetRandomizedShort0x18802048934(void*, FieldStruct02048934*, Random*);
extern "C" int func_ov000_02161bb8(ZeroableStruct021620d8*);
void IncrementByteCounterWrapAt0x12_ov000_02161bec(unsigned char*);
static inline void* GetEntryPayload(FieldStruct02048934* entry) { return entry->payload; }
static inline int GetGroupCount(PartyRoster* roster) { SDK_NULL_ASSERT(roster); return roster->groupCount; }

static inline unsigned char inline_ov000_02161e30_3(Struct_ov000_0215ab88* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_138_->unknown_25_; }

// USA: func_ov000_02161e30
extern "C" ARM void func_ov000_02161e30(BattleState* state, int id, int key) {
    FieldStruct02048934* entry;
    Combatant* actor;
    PartyRoster* const roster = &state->mirror->roster;
    GameState* game = GameState::GetInstance();
    LinkSession_GetInstance();
    BattleResources* resources = state->resources;
    BinarySearchByComparatorStruct* params = (BinarySearchByComparatorStruct*)state->resources->params;
    entry = SearchWithLow15Comparator02070fd0((Container02070e60*)resources->entries, key);
    Param02048850* param = SearchWithComparator0206f4f0(params, (short)key);
    if (!entry || !param) return;
    actor = GetCombatantWithFlag0x400_0200fea4(game, id);
    int group = actor->group;
    roster->count -= roster->slots[group].count - 1;
    roster->memberCount -= roster->slots[group].mode - 1;
    memset(&roster->slots[group], 0, sizeof(PartySlot));
    roster->slots[group].mode = 1;
    roster->slots[group].count = 1;
    roster->slots[group].key = key;
    roster->slots[group].combatant = id - 0xc0;
    int found = 0;
    int index = 0;
    for (int i = 0; i < roster->groupCount; i++) {
        if (key == roster->groups[i].key) {
            index = i;
            found = 1;
            break;
        }
    }
    if (!var8) {
        var9 = inline_ov000_02161e30_2(var2);
        var2->unknown_1_6_ = var9 + 1;
        func_ov000_021620d8(&var2->unknown_4c_[var9]);
        var2->unknown_4c_[var9].unknown_2_ = arg2;
        var2->unknown_4c_[var9].unknown_0_ = 1;
    }
    func_ov000_02167c28((unsigned char*)arg0, arg1);
    Struct_ov000_02161e30_2* var11 = var1->unknown_138_;
    func_020891cc(var11);
    func_02089630(var11, inline_ov000_02161e30(var0), 0);
    var1->unknown_148_ = var0;
    int var12 = ((Object3D*)var1)->GetHeight();
    int var13 = ((Object3D*)var1)->GetRadius();
    func_02048850((Struct_02048850*)var1, var6);
    ((Object3D*)var1)->SetHeight(var12);
    ((Object3D*)var1)->SetRadius(var13);
    func_02048934(var1, var0, &arg0->unknown_29c_->unknown_0_);
    unsigned short var14 = var1->unknown_188_;
    unsigned short var15 = var1->unknown_18a_;
    var1->unknown_138_->unknown_0_ = var14;
    var1->unknown_138_->unknown_4_ = var14;
    var1->unknown_138_->unknown_2_ = var15;
    var1->unknown_138_->unknown_6_ = var15;
    Struct_ov000_02161e30_3* var16 = &var2->unknown_4c_[var9];
    unsigned char var17 = func_ov000_02161bb8(var16);
    var1->unknown_186_ = arg2;
    if (var17 == 1) var17 = 0;
    var1->unknown_18c_ = var7;
    var1->unknown_18d_ = var17;
    var1->unknown_184_ = 1;
    int var18 = inline_ov000_02161e30_3(var1);
    var2->unknown_4c_[var9].unknown_4_ |= 1 << var18;
    func_ov000_02161bec(&var16->unknown_0_);
}
