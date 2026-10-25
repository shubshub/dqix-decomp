#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "std_library_functions.h"



struct Struct_0201099c_16;
struct Struct_02033834;
struct Struct_02038598_4;
struct Struct_02015438;
struct Struct_02082d6c;
struct Struct_02082d6c_2;
struct Struct_ov003_02166a90_5 {
#if defined(jpn)
    unsigned char unknown_0_[0x2ca];
    signed char unknown_4a2_;
    unsigned char unknown_2cb_[0x2e4 - 0x2cb];
#else
    unsigned char unknown1_0_[0x4a2];
    signed char unknown_4a2_;
    unsigned char unknown_4a3_[0x4bc - 0x4a3];
#endif
    unsigned char unknown_4bc_;
};
struct Struct_ov003_02166a90_6 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_[13];
    unsigned char unknown_f_[0x13f - 0xf];
    unsigned char unknown_13f_0_ : 3;
    unsigned char unknown_13f_3_ : 5;
    unsigned char unknown_140_[0x34];
};
struct Struct_ov003_02166a90_7 {
    unsigned char unknown_0_[0x568];
    short unknown_568_;
};
struct Struct_ov003_02166a90 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[0x134 - 0xac];
    char* unknown_134_;
};
struct Struct_ov003_02166a90_2 {
    unsigned char unknown_0_[0x16c];
    unsigned short unknown_16c_[16];
};
struct Struct_ov003_02166a90_3 {
    unsigned char unknown_0_[0xb];
    unsigned char unknown_b_;
};
struct Struct_ov003_02166a90_4 {
    unsigned char unknown_0_[0x8c];
    unsigned char unknown_8c_[1];
};
extern Vector3i data_ov003_0217f4b8[3];

extern "C" SelectedEntry02166a90* func_ov003_02160bf8(SelectionPage02166a90*, int);
extern "C" void* Zone3D_GetInstance(void);
void* FindRecordByShortField020108f0(void*, int);
void* FindSlotWithNegShort02010954(char*);
void ResetShortFields02086380(unsigned char*);
extern "C" void func_02082d6c(SlotState02082d6c*, SlotRecord02082d6c*);
extern "C" void func_ov017_0218f064(GameResources*, int, int, int, int);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" void func_02033874(Struct_02033834*, int);
extern "C" unsigned char* func_ov017_021a4658(unsigned char*, int);
int GameState_GetProtagonistIndex(GameState*);
void SetField0x2d0_020546a0(void*, int);
int GetSignedByte0x2d0_020546a8(void*);
void SetField0x2d1_020546b4(void*, int);
typedef void (*ByteSetterWithIntArgument02166a90)(void*, int);
int GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" void Font_DecodeText(unsigned char*, char*, int);
int GetFieldAt0x50(Struct020865b0*);
void PartyMember_SetVocation(unsigned char*, int);
void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int*, unsigned int);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202b7d8(int*);
extern "C" void func_ov017_021cc340(int, int, int);
extern "C" void func_ov017_021cf078(int, unsigned short, unsigned char);
extern "C" void func_ov017_021cc97c(int);
extern "C" void func_ov017_021cca5c(int, int);
extern "C" void func_ov017_021ccb58(int, int);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_0206e424(void*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" void func_ov017_02191234(unsigned char*);
extern "C" void func_020dc2d0(int);
extern "C" void func_ov017_02191108(void*, int, int, int, int);
extern "C" void func_020dc7e8(int, int);
extern "C" void func_ov017_021d0dbc(void);
extern "C" void func_ov017_021cee78(int, unsigned char);

// USA: func_ov003_02166a90
extern "C" ARM int func_ov003_02166a90(Struct_ov003_02166a90_5* arg0, int arg1) {
    Struct_ov003_02166a90_6* var0 = func_ov003_02160bf8(arg0, arg1);
    if (var0 == 0) {
        return 0;
    }
    int var1 = 0;
    if (var0->unknown_13f_0_ == 2 || var0->unknown_13f_0_ == 3 || var0->unknown_13f_0_ == 4) {
        var1 = 1;
    }
    GameState* state = GameState::GetInstance();
    GameResources* resources = state->GetResources();
    unsigned short* field06 = (unsigned short*)Zone3D_GetInstance();
    if (self->step == 0) {
        int freeSlot = -1;
        for (int slot = 3; slot >= 0; slot--) {
            if (state->GetGameObjectByIndex(slot) == 0) {
                freeSlot = slot;
                break;
            }
        }
        if (var5 >= 0) {
            arg0->unknown_4a2_ = var5;
            SetSubBrightness(var3, -16, 20);
            arg0->unknown_4bc_++;
        } else {
            arg0->unknown_4bc_ = 0;
            return -1;
        }
    }
    if (arg0->unknown_4bc_ == 1) {
        if (IsSubBrightnessTransitionActive(var3) != 0) {
            return 0;
        }
        Struct_ov003_02166a90_7* var7 = (Struct_ov003_02166a90_7*)func_020108f0(var2, arg0->unknown_4a2_);
        if (var7 == 0) {
            var7 = (Struct_ov003_02166a90_7*)func_02010954((char*)var2);
        }
        var7->unknown_568_ = arg0->unknown_4a2_;
        func_02086380((unsigned char*)var7);
        func_02082d6c((Struct_02082d6c*)var7, (Struct_02082d6c_2*)var0);
        func_ov017_0218f064(var3, arg0->unknown_4a2_, 0x1000, 1, 0);
        GameObject* var8 = func_0200ff58(var2, arg0->unknown_4a2_);
        if (var8 == 0) {
            return 0;
        }
        var8->obj3D_.SetField06(*var4);
        var2->GetProtagonist();
        var8->obj3D_.position_ = data_ov003_0217f4b8[arg0->unknown_4a2_ - 1];
        func_02033874((Struct_02033834*)var8, 0x323d);
        Struct_ov003_02166a90_3* var9 = (Struct_ov003_02166a90_3*)func_ov017_021a4658((unsigned char*)var3, arg0->unknown_4a2_);
        if (var1 == 0) {
            var9->unknown_b_ |= 8;
        }
        int group = GameState_GetProtagonistIndex(state);
        ((ByteSetterWithIntArgument02166a90)SetField0x2d0_020546a0)(member, group);
        int sameGroup = 0;
        for (int slot = 0; slot < 4; slot++) {
            GameObject* other = GetCombatantWithFlag0x1000_0200ff58(state, slot);
            if (other != 0 && slot != self->slot) {
                if (group == GetSignedByte0x2d0_020546a8(other)) {
                    sameGroup++;
                }
            }
        }
        ((ByteSetterWithIntArgument02166a90)SetField0x2d1_020546b4)(member, sameGroup);
        GameState_GetParty(state);
        Appearance02166a90* appearance = (Appearance02166a90*)GetFieldAt0x150_02053c6c((unsigned char*)member);
#if defined(jpn)
        strcpy(((Struct_ov003_02166a90*)var8)->unknown_134_, (char*)var0->unknown_140_);
#else
        char name[0x30] = {0};
        Font_DecodeText(entry->name, name, 1);
        strcpy(((Combatant02166a90*)member)->name, name);
#endif
        int index = GetFieldAt0x50((Struct020865b0*)entry);
        appearance->values[index] = entry->metadataValues[GetFieldAt0x50((Struct020865b0*)entry)];
        PartyMember_SetVocation((unsigned char*)appearance, GetFieldAt0x50((Struct020865b0*)entry));
        self->step++;
    }
    if (self->step == 2) {
        HeadNode02046b24** head = (HeadNode02046b24**)resources->unknown_ptr_array_3700[0];
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x41);
        if (GetHeadNodeIdOrMinusOne(head) != 0x13) {
            self->step++;
        }
    }
    if (arg0->unknown_4bc_ == 3) {
        if (func_0202b7d8((int*)func_0202ae18()) != 0) {
            func_ov017_021cc340(arg0->unknown_4a2_, 1, -1);
            for (int var18 = 0; var18 < 13; var18++) {
                func_ov017_021cf078(arg0->unknown_4a2_, (unsigned char)var18, 0);
            }
            func_ov017_021cc97c(arg0->unknown_4a2_);
            func_ov017_021cca5c(arg0->unknown_4a2_, 0);
            func_ov017_021cca5c(arg0->unknown_4a2_, 1);
            func_ov017_021ccb58(arg0->unknown_4a2_, 1);
            func_ov017_021ccb58(arg0->unknown_4a2_, 4);
            func_ov017_021ccb58(arg0->unknown_4a2_, 7);
            func_ov017_021ccb58(arg0->unknown_4a2_, 10);
        }
        func_0206e424(Scenario_GetInstance(), self->slot);
        state->GetPartyMemberByIndex(self->slot);
        PartyFlags02166a90* flags = (PartyFlags02166a90*)Scenario_GetInstance();
        Scenario_SetFlag(flags, flags->flags, 0x784, 1);
        self->step = 0;
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x41);
        func_ov017_02191234((unsigned char*)resources);
        if (special != 0) {
            SetCombatModeFromCase020dc2d0(0);
        }
        func_ov017_02191108(var3, 1, 1, 1, 1);
        func_020dc7e8(6, -1);
        func_020dc7e8(7, -1);
        int* var20 = (int*)func_0202ae18();
        if (var20 != 0 && func_0202b7d8(var20) != 0) {
            func_ov017_021d0dbc();
        }
        if (func_0202b7d8((int*)func_0202ae18()) != 0) {
            func_ov017_021cee78(arg0->unknown_4a2_, 1);
        }
        return 1;
    }
    return 0;
}
