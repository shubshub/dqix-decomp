#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_0200f3a4_7 { char pad[0x568]; short unknown_568_; };
struct Struct_ov017_02190264 {
    GameObject object;
#if defined(jpn)
    char unknown_13c_[0x0c];
#else
    char unknown1_13c_[0x18];
#endif
    short* unknown_154_;
    char unknown_158_[0x17a];
    unsigned char order;
};
struct Struct_ov000_02161e30_4 { char pad[2]; unsigned char active; };
struct Struct_ov017_021d622c { int slots[13]; };
struct Struct_ov017_02190264_2 { int fields[4]; };
struct FieldBlock63d6_115a8;
struct SearchStruct0202c1a4;
extern "C" int* LinkSession_GetInstance();
extern "C" int func_ov017_021925e0();
extern "C" Struct_0200f3a4_7* func_02053c6c(unsigned char*);
extern "C" void func_02082828(Struct_0200f3a4_7*);
extern "C" void func_ov017_021bd3d4(void*, int);
extern "C" Struct_ov000_02161e30_4* func_ov017_021a4658(GameResources*, int);
extern "C" void func_02046a8c(void*, Struct_ov000_02161e30_4*);
extern "C" void func_ov017_021b33d8(void*);
extern "C" int LinkSession_IsActive(int*);
extern "C" void* GameState_GetPlayerLocation(char*, unsigned int);
extern "C" int GameObject_IsGesturing(signed char*);
extern "C" void func_020531f0(GameObject*);
extern "C" void func_020545ac(short*);
extern "C" int func_020115a8(FieldBlock63d6_115a8*);
extern "C" void func_0200fd48(GameState*, int);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" void Party_ReformLine(GameResources*, int, int, int, int);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_ov017_02190884(int, Struct_ov017_02190264_2*, int*, int, int, int);
extern "C" void func_ov017_02191234(GameResources*);
#if defined(jpn)
#define data_ov017_021d622c data_ov017_021d667c
#endif
extern Struct_ov017_021d622c data_ov017_021d622c;
static inline int inline_020dc548(int index) { return index >= 0 && index <= 3; }

// USA: func_ov017_02190264
extern "C" ARM void func_ov017_02190264(GameResources* resources, int index) {
    int var0 = inline_020dc548(index);
    if (!var0) return;
    GameState* game = GameState::GetInstance();
    int* search = LinkSession_GetInstance();
    void* node = resources->unknown_ptr_array_371c[6];
    if (func_ov017_021925e0()) {
        GameObject* member = game->GetPartyMemberByIndex(index);
        if (member && (member->obj3D_.unknown_0_ & 0x1000)) {
            Struct_0200f3a4_7* extension = func_02053c6c((unsigned char*)member);
            if (extension) {
                short var6 = extension->unknown_568_;
                func_02082828(extension);
                extension->unknown_568_ = var6;
            }
            func_ov017_021bd3d4(node, (unsigned char)index);
            return;
        }
    }
    Struct_ov000_02161e30_4* slot = func_ov017_021a4658(resources, index);
    if (slot->active) {
        func_02046a8c(resources->unknown_ptr_array_3700[0], slot);
        func_ov017_021b33d8(slot);
    }
    GameObject* combatant = func_0200ff1c(game, index);
    if (combatant) {
        if (LinkSession_IsActive(search) && (combatant->obj3D_.unknown_0_ & 0x200)) {
            short* field = (short*)GameState_GetPlayerLocation((char*)game, index);
            if (field) *field = 0;
        }
        if (GameObject_IsGesturing((signed char*)combatant)) func_020531f0(combatant);
        strcpy(resources->partyNames[index], (char*)combatant->baseStats_);
        short* reset = ((Struct_ov017_02190264*)combatant)->unknown_154_;
        if (reset) func_020545ac(reset);
        if (!func_020115a8((FieldBlock63d6_115a8*)game)) {
            Struct_0200f3a4_7* extension = func_02053c6c((unsigned char*)combatant);
            if (extension) func_02082828(extension);
        }
    }
    Struct_ov017_021d622c indices = data_ov017_021d622c;
    indices.slots[0] = index;
    indices.slots[1] = index * 12 + 0x13;
    indices.slots[2] = index * 12 + 0x14;
    indices.slots[3] = index * 12 + 0x15;
    indices.slots[4] = index * 12 + 0x16;
    indices.slots[5] = index * 12 + 0x17;
    indices.slots[6] = index * 12 + 0x18;
    indices.slots[7] = index * 12 + 0x19;
    indices.slots[8] = index * 12 + 0x1a;
    indices.slots[9] = index * 12 + 0x1b;
    indices.slots[10] = index * 12 + 0x1c;
    indices.slots[11] = index * 12 + 0x1d;
    for (int i = 0; indices.slots[i] >= 0; i++) func_0200fd48(game, indices.slots[i]);
    int memberIndex;
    GameState* var15 = GameState::GetInstance();
    Struct_ov017_02190264* members[4] = {};
    for (memberIndex = 1; memberIndex < 4; memberIndex++) {
        Struct_ov017_02190264* member = (Struct_ov017_02190264*)func_0200ff58(var15, memberIndex);
        if (member) members[member->order] = member;
    }
    int var18;
    Struct_ov017_02190264** current = members;
    int order = 1;
    for (var18 = 0; var18 < 4; var18++) { Struct_ov017_02190264* member = *current; if (member) member->order = order++; current++; }
    if (!LinkSession_IsActive(search)) {
        Party_ReformLine(resources, 1, 1, 1, 1);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (i == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) Party_ReformLine(resources, 1, 1, 1, 1);
        else {
            Struct_ov017_02190264_2 output;
            int field = 0;
            func_ov017_02190884(i, &output, &field, 1, 1, 1);
        }
    }
    func_ov017_02191234(resources);
}
