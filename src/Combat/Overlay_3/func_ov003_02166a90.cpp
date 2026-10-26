#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "std_library_functions.h"



struct Struct020865b0;
struct Obj02033874;
struct FlagWord020466f4;
struct HeadNode02046b24;
struct Struct_02082d6c;
struct Struct_02082d6c_2;
struct Struct_ov003_02166a90_5 {
#if defined(jpn)
    unsigned char pad0[0x2ca];
    signed char slot;
    unsigned char unknown_2cb_[0x2e4 - 0x2cb];
#else
    unsigned char pad0[0x4a2];
    signed char slot;
    unsigned char unknown_4a3_[0x4bc - 0x4a3];
#endif
    unsigned char step;
};
struct Struct_ov003_02166a90_6 {
    unsigned char pad0[2];
    unsigned char metadataValues[13];
    unsigned char unknown_f_[0x13f - 0xf];
    unsigned char kind : 3;
    unsigned char unknown_13f_3_ : 5;
    unsigned char name[0x34];
};
struct PartyRecord02166a90 {
    unsigned char pad0[0x568];
    short slot;
};
struct Struct_ov003_02166a90 {
    Object3D object;
    unsigned char unknown_ac_[0x134 - 0xac];
    char* name;
};
struct Struct_ov003_02166a90_2 {
    unsigned char pad0[0x16c];
    unsigned short values[16];
};
struct Struct_ov003_02166a90_3 {
    unsigned char pad0[0xb];
    unsigned char flags;
};
struct PartyFlags02166a90 {
    unsigned char pad0[0x8c];
    unsigned char flags[1];
};
extern Vector3i data_ov003_0217f4b8[3];

extern "C" Struct_ov003_02166a90_6* func_ov003_02160bf8(Struct_ov003_02166a90_5*, int);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* GameState_FindPartyMemberData(void*, int);
extern "C" void* GameState_FindFreePartyMemberData(char*);
extern "C" void func_02086380(unsigned char*);
extern "C" void func_02082d6c(Struct_02082d6c*, Struct_02082d6c_2*);
extern "C" void func_ov017_0218f064(GameResources*, int, int, int, int);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" unsigned char* func_ov017_021a4658(unsigned char*, int);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_020546a0(void*, int);
extern "C" int func_020546a8(void*);
extern "C" void func_020546b4(void*, int);
typedef void (*Type_ov003_02166a90)(void*, int);
extern "C" int func_02053c6c(unsigned char*);
extern "C" void Font_DecodeText(unsigned char*, char*, int);
extern "C" int PartyMemberRecord_GetVocation(Struct020865b0*);
extern "C" void PartyMember_SetVocation(unsigned char*, int);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_ov017_021cc340(int, int, int);
extern "C" void func_ov017_021cf078(int, unsigned short, unsigned char);
extern "C" void func_ov017_021cc97c(int);
extern "C" void func_ov017_021cca5c(int, int);
extern "C" void func_ov017_021ccb58(int, int);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_0206e424(void*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" void func_ov017_02191234(unsigned char*);
extern "C" void func_020dc2d0(int);
extern "C" void Party_ReformLine(void*, int, int, int, int);
extern "C" void func_020dc7e8(int, int);
extern "C" void func_ov017_021d0dbc(void);
extern "C" void func_ov017_021cee78(int, unsigned char);

// USA: func_ov003_02166a90
extern "C" ARM int func_ov003_02166a90(Struct_ov003_02166a90_5* self, int key) {
    Struct_ov003_02166a90_6* entry = func_ov003_02160bf8(self, key);
    if (entry == 0) {
        return 0;
    }
    int special = 0;
    if (entry->kind == 2 || entry->kind == 3 || entry->kind == 4) {
        special = 1;
    }
    GameState* state = GameState::GetInstance();
    GameResources* resources = state->GetResources();
    unsigned short* field06 = (unsigned short*)Zone3D_GetInstance();
    if (self->step == 0) {
        int var5 = -1;
        for (int slot = 3; slot >= 0; slot--) {
            if (state->GetGameObjectByIndex(slot) == 0) {
                var5 = slot;
                break;
            }
        }
        if (var5 >= 0) {
            self->slot = var5;
            SetSubBrightness(resources, -16, 20);
            self->step++;
        } else {
            self->step = 0;
            return -1;
        }
    }
    if (self->step == 1) {
        if (IsSubBrightnessTransitionActive(resources) != 0) {
            return 0;
        }
        PartyRecord02166a90* record = (PartyRecord02166a90*)GameState_FindPartyMemberData(state, self->slot);
        if (record == 0) {
            record = (PartyRecord02166a90*)GameState_FindFreePartyMemberData((char*)state);
        }
        record->slot = self->slot;
        func_02086380((unsigned char*)record);
        func_02082d6c((Struct_02082d6c*)record, (Struct_02082d6c_2*)entry);
        func_ov017_0218f064(resources, self->slot, 0x1000, 1, 0);
        GameObject* member = func_0200ff58(state, self->slot);
        if (member == 0) {
            return 0;
        }
        member->obj3D_.SetField06(*field06);
        state->GetProtagonist();
        member->obj3D_.position_ = data_ov003_0217f4b8[self->slot - 1];
        GameObject_SnapFacing((Obj02033874*)member, 0x323d);
        Struct_ov003_02166a90_3* event = (Struct_ov003_02166a90_3*)func_ov017_021a4658((unsigned char*)resources, self->slot);
        if (special == 0) {
            event->flags |= 8;
        }
        int group = GameState_GetProtagonistIndex(state);
        ((Type_ov003_02166a90)func_020546a0)(member, group);
        int var11 = 0;
        for (int slot = 0; slot < 4; slot++) {
            GameObject* other = func_0200ff58(state, slot);
            if (other != 0 && slot != self->slot) {
                if (group == func_020546a8(other)) {
                    var11++;
                }
            }
        }
        ((Type_ov003_02166a90)func_020546b4)(member, var11);
        GameState_GetParty(state);
        Struct_ov003_02166a90_2* appearance = (Struct_ov003_02166a90_2*)func_02053c6c((unsigned char*)member);
#if defined(jpn)
        strcpy(((Struct_ov003_02166a90*)member)->name, (char*)entry->name);
#else
        char name[0x30] = {0};
        Font_DecodeText(entry->name, name, 1);
        strcpy(((Struct_ov003_02166a90*)member)->name, name);
#endif
        int index = PartyMemberRecord_GetVocation((Struct020865b0*)entry);
        appearance->values[index] = entry->metadataValues[PartyMemberRecord_GetVocation((Struct020865b0*)entry)];
        PartyMember_SetVocation((unsigned char*)appearance, PartyMemberRecord_GetVocation((Struct020865b0*)entry));
        self->step++;
    }
    if (self->step == 2) {
        HeadNode02046b24** head = (HeadNode02046b24**)resources->unknown_ptr_array_3700[0];
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x41);
        if (FieldTaskQueue_GetCurrentKind(head) != 0x13) {
            self->step++;
        }
    }
    if (self->step == 3) {
        if (LinkSession_IsActive((int*)LinkSession_GetInstance()) != 0) {
            func_ov017_021cc340(self->slot, 1, -1);
            for (int i = 0; i < 13; i++) {
                func_ov017_021cf078(self->slot, (unsigned char)i, 0);
            }
            func_ov017_021cc97c(self->slot);
            func_ov017_021cca5c(self->slot, 0);
            func_ov017_021cca5c(self->slot, 1);
            func_ov017_021ccb58(self->slot, 1);
            func_ov017_021ccb58(self->slot, 4);
            func_ov017_021ccb58(self->slot, 7);
            func_ov017_021ccb58(self->slot, 10);
        }
        func_0206e424(Scenario_GetInstance(), self->slot);
        state->GetPartyMemberByIndex(self->slot);
        PartyFlags02166a90* flags = (PartyFlags02166a90*)Scenario_GetInstance();
        Scenario_SetFlag(flags, flags->flags, 0x784, 1);
        self->step = 0;
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x41);
        func_ov017_02191234((unsigned char*)resources);
        if (special != 0) {
            func_020dc2d0(0);
        }
        Party_ReformLine(resources, 1, 1, 1, 1);
        func_020dc7e8(6, -1);
        func_020dc7e8(7, -1);
        int* eventStatus = (int*)LinkSession_GetInstance();
        if (eventStatus != 0 && LinkSession_IsActive(eventStatus) != 0) {
            func_ov017_021d0dbc();
        }
        if (LinkSession_IsActive((int*)LinkSession_GetInstance()) != 0) {
            func_ov017_021cee78(self->slot, 1);
        }
        return 1;
    }
    return 0;
}
