#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_0200f3a4_7 { char unknown_0_[0x568]; short unknown_568_; };
struct Struct_ov017_02190264 {
    GameObject unknown_0_;
#if defined(jpn)
    char unknown_13c_[0x0c];
#else
    char unknown1_13c_[0x18];
#endif
    short* unknown_154_;
    char unknown_158_[0x17a];
    unsigned char unknown_2d2_;
};
struct PartySlot { char pad[2]; unsigned char active; };
struct PartyIndices { int slots[13]; };
struct PartyOutput { int fields[4]; };
struct FieldBlock63d6_115a8;
struct SearchStruct0202c1a4;
extern "C" int* LinkSession_GetInstance();
extern "C" int func_ov017_021925e0();
PartyExtension* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" void func_02082828(PartyExtension*);
void SetFlagAndSyncVec3_021bd3d4(void*, int);
extern "C" PartySlot* func_ov017_021a4658(GameResources*, int);
extern "C" void func_02046a8c(void*, PartySlot*);
void ResetEntriesAndNotify_021b33d8(void*);
int LinkSession_IsActive(int*);
void* GameState_GetPlayerLocation(char*, unsigned int);
int GameObject_IsGesturing(signed char*);
extern "C" void func_020531f0(GameObject*);
void InvalidateField0_020545ac(short*);
int GetByteField0x63d6_020115a8(FieldBlock63d6_115a8*);
void ClearCombatantSlot_0200fd48(GameState*, int);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
extern "C" void Party_ReformLine(GameResources*, int, int, int, int);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_ov017_02190884(int, PartyOutput*, int*, int, int, int);
extern "C" void func_ov017_02191234(GameResources*);
#if defined(jpn)
#define data_ov017_021d622c data_ov017_021d667c
#endif
extern Struct_ov017_021d622c data_ov017_021d622c;
static inline int inline_020dc548(int arg0) { return arg0 >= 0 && arg0 <= 3; }

// USA: func_ov017_02190264
extern "C" ARM void func_ov017_02190264(GameResources* resources, int index) {
    int valid = ValidPartyIndex(index);
    if (!valid) return;
    GameState* game = GameState::GetInstance();
    int* search = LinkSession_GetInstance();
    void* node = resources->unknown_ptr_array_371c[6];
    if (func_ov017_021925e0()) {
        GameObject* var4 = var1->GetPartyMemberByIndex(arg1);
        if (var4 && (var4->obj3D_.unknown_0_ & 0x1000)) {
            Struct_0200f3a4_7* var5 = func_02053c6c((unsigned char*)var4);
            if (var5) {
                short var6 = var5->unknown_568_;
                func_02082828(var5);
                var5->unknown_568_ = var6;
            }
            func_ov017_021bd3d4(var3, (unsigned char)arg1);
            return;
        }
    }
    PartySlot* slot = func_ov017_021a4658(resources, index);
    if (slot->active) {
        func_02046a8c(resources->unknown_ptr_array_3700[0], slot);
        ResetEntriesAndNotify_021b33d8(slot);
    }
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, index);
    if (combatant) {
        if (LinkSession_IsActive(search) && (combatant->obj3D_.unknown_0_ & 0x200)) {
            short* field = (short*)GameState_GetPlayerLocation((char*)game, index);
            if (field) *field = 0;
        }
        if (GameObject_IsGesturing((signed char*)combatant)) func_020531f0(combatant);
        strcpy(resources->partyNames[index], (char*)combatant->baseStats_);
        short* reset = ((PartyObject*)combatant)->modelOwner;
        if (reset) InvalidateField0_020545ac(reset);
        if (!GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)game)) {
            PartyExtension* extension = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
            if (extension) func_02082828(extension);
        }
    }
    Struct_ov017_021d622c var12 = data_ov017_021d622c;
    var12.unknown_0_[0] = arg1;
    var12.unknown_0_[1] = arg1 * 12 + 0x13;
    var12.unknown_0_[2] = arg1 * 12 + 0x14;
    var12.unknown_0_[3] = arg1 * 12 + 0x15;
    var12.unknown_0_[4] = arg1 * 12 + 0x16;
    var12.unknown_0_[5] = arg1 * 12 + 0x17;
    var12.unknown_0_[6] = arg1 * 12 + 0x18;
    var12.unknown_0_[7] = arg1 * 12 + 0x19;
    var12.unknown_0_[8] = arg1 * 12 + 0x1a;
    var12.unknown_0_[9] = arg1 * 12 + 0x1b;
    var12.unknown_0_[10] = arg1 * 12 + 0x1c;
    var12.unknown_0_[11] = arg1 * 12 + 0x1d;
    for (int var13 = 0; var12.unknown_0_[var13] >= 0; var13++) func_0200fd48(var1, var12.unknown_0_[var13]);
    int var14;
    GameState* var15 = GameState::GetInstance();
    Struct_ov017_02190264* var16[4] = {};
    for (var14 = 1; var14 < 4; var14++) {
        Struct_ov017_02190264* var17 = (Struct_ov017_02190264*)func_0200ff58(var15, var14);
        if (var17) var16[var17->unknown_2d2_] = var17;
    }
    int scan;
    PartyObject** current = members;
    int order = 1;
    for (scan = 0; scan < 4; scan++) { PartyObject* member = *current; if (member) member->order = order++; current++; }
    if (!LinkSession_IsActive(search)) {
        Party_ReformLine(resources, 1, 1, 1, 1);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (i == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) Party_ReformLine(resources, 1, 1, 1, 1);
        else {
            Struct_ov017_02190264_2 var23;
            int var24 = 0;
            func_ov017_02190884(var22, &var23, &var24, 1, 1, 1);
        }
    }
    func_ov017_02191234(arg0);
}
