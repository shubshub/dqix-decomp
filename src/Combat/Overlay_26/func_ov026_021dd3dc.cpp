#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02161e30;
struct Struct_ov000_0217e870_2;
struct Struct_ov026_021d8ba0_4;
struct Struct_0202b2f0;
struct Struct_02010088;
struct Struct_ov026_021dc8fc_4;

struct Struct_ov026_021d8ba0_6 {
    char unknown_0_[0x1c];
    signed char unknown_1c_;
};

struct Struct_ov026_021dd3dc_2 {
    char unknown_0_[0x14];
    unsigned int unknown_14_;
};

struct Struct_ov017_021af66c_5 {
    char unknown_0_[0x138];
    Struct_ov026_021dd3dc_2* unknown_138_;
};

struct Struct_ov026_021de6cc {
    short unknown_0_[4];
};

struct Struct_ov026_021dd3dc {
    char unknown_0_[0x48];
};

struct Struct_ov000_021643d4_3 {
    char unknown_0_[0x68];
    Struct_ov026_021dd3dc unknown_68_;
};

extern "C" const Struct_ov026_021de6cc data_ov026_021de6cc;
extern "C" const Struct_ov026_021de6cc data_ov026_021de6d4;

extern "C" SearchStruct* LinkSession_GetInstance();
int ClassifyField0x81fe_ov000_0215fc60(char*);
int LinkSession_IsActive(int*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
SlotWork* FindSlotById_021dae60(Container_021dae60*, int);
int LinkSession_IsSlotMember(SearchStruct*, int);
int GetSignedByte0x2d0_020546a8(void*);
int IsFlag10088Set_02010088(S_10088*);
int IsFlagBit8Set_021dce1c(FlagObj_021dce1c*);
int CheckFlag0x14Bit0x10Set_020882f8(unsigned char*);
extern "C" int func_ov000_0215f7a8(BattleState*, short*, unsigned char);
extern "C" int func_ov000_0215e9fc(BattleState*, short*, int, int);
void LoadBattleBlock020ac4c0(void*);
void AddClamped24BitFieldAt0x34_020a0780(struct S_a0780*, unsigned int);
void AddClampedLow16BitFieldAt0xc_020a0068(struct S_a0068*, unsigned int);
void AddClamped24BitFieldAt0x38_020a07b0(struct S_a07b0*, unsigned int);
void AddClampedHigh16BitFieldAt0xc_020a00a4(struct S_a00a4*, unsigned int);
void CopyInBattleField0x7540_020ac494(void*);

// USA: func_ov026_021dd3dc
extern "C" ARM int func_ov026_021dd3dc(BattleState* battle, PartyState* party, Container_021dae60* list) {
    Ids4 cands;
    Ids4 picks;
    short alive[4];
    int results[4];
    BattleBlk blk;
    GameState* gs = GameState::GetInstance();
    SearchStruct* link = LinkSession_GetInstance();
    int i;
    int result;
    int count = 0;
    if (ClassifyField0x81fe_ov000_0215fc60((char*)battle) != 0) {
        return 1;
    }
    if (LinkSession_IsActive((int*)link) == 0 || TestBitAt0x34_020a35e0((unsigned char*)party, count)) {
        result = 0;
        for (i = 0; i < 4; i++) {
            if (!TestBitAt0x34_020a35e0((unsigned char*)party, i)) continue;
            if (i != 0 && !GetCombatantWithFlag0x1000_0200ff58(gs, i)) continue;
            SlotWork* slot = FindSlotById_021dae60(list, i);
            if (!slot) continue;
            if (slot->state == 6) {
                result = 1;
                break;
            }
        }
        if (var8 == 0) {
            for (var7 = 0; var7 < 4; var7++) {
                if (!func_020a35e0((unsigned char*)arg1, var7)) continue;
                if (var7 != 0 && !func_0200ff58(var5, var7)) continue;
                GameObject* var11 = var5->GetCombatantByIndex(var7);
                if (!var11) continue;
                if ((((Struct_ov017_021af66c_5*)var11)->unknown_138_->unknown_14_ & 0x80019) == 0) {
                    var8 = 2;
                    break;
                }
            }
        }
        var3[var9] = var8;
        var9++;
    }
    if (LinkSession_IsActive((int*)link)) {
        for (i = 1; i < 4; i++) {
            if (!TestBitAt0x34_020a35e0((unsigned char*)party, i)) continue;
            if (GetCombatantWithFlag0x1000_0200ff58(gs, i)) continue;
            GameObject* c = gs->GetCombatantByIndex(i);
            if (!c) continue;
            SlotWork* slot = FindSlotById_021dae60(list, i);
            if (!slot) continue;
            int r = 0;
            if (slot->state == 6) {
                r = 1;
            } else if ((((CombatantView*)c)->status->flags & 0x80019) == 0) {
                r = 2;
            }
            var3[var9] = var14;
            var9++;
        }
    }
    int var15 = 0;
    for (int var16 = 0; var16 < var9; var16++) {
        if (var3[var16] == 1) var15 = 1;
    }
    if (var15) {
        for (int var17 = 0; var17 < var9; var17++) {
            if (var3[var17] == 2) return 4;
        }
    }
    result = 1;
    for (int j = 0; j < count; j++) {
        if (results[j] == 1) {
            cands = data_ov026_021de6cc;
            int n = 0;
            int k;
            for (k = 0; k < 4; k++) {
                if (!TestBitAt0x34_020a35e0((unsigned char*)party, k)) continue;
                if (LinkSession_IsSlotMember(link, k)) {
                    cands.v[n] = k;
                    n++;
                }
            }
            for (k = 0; k < 4; k++) {
                if (!TestBitAt0x34_020a35e0((unsigned char*)party, k)) continue;
                GameObject* m = GetCombatantWithFlag0x1000_0200ff58(gs, k);
                if (!m) continue;
                if (LinkSession_IsSlotMember(link, GetSignedByte0x2d0_020546a8(m))) {
                    cands.v[n] = k;
                    n++;
                }
            }
            var1 = data_ov026_021de6d4;
            int var22;
            int var23 = 0;
            for (var22 = 0; var22 < var19; var22++) {
                short var24 = var0.unknown_0_[var22];
                GameObject* var25 = var5->GetCombatantByIndex(var24);
                if (!var25) continue;
                if (func_02010088((Struct_02010088*)var25)) continue;
                if (func_ov026_021dce1c((Struct_ov026_021dc8fc_4*)var25)) continue;
                if (func_020882f8((unsigned char*)((Struct_ov017_021af66c_5*)var25)->unknown_138_)) continue;
                if ((((Struct_ov017_021af66c_5*)var25)->unknown_138_->unknown_14_ & 0x80000) == 0) {
                    var1.unknown_0_[var23] = var24;
                    var23++;
                }
            }
            if (func_ov000_0215f7a8(arg0, var1.unknown_0_, var23)) {
                var8 = 2;
            } else {
                var8 = 3;
            }
            break;
        }
    }
    if (var8 != 1) {
        func_020ac4c0(&var4);
        Struct_ov026_021dd3dc* var26 = &var4.unknown_68_;
        func_020a0780((Struct_020a0780*)&var4, 1);
        func_020a0068((Struct_020a0068*)var26, 1);
        if (var8 == 2) {
            int var27 = func_ov000_0215e9fc(arg0, var2, 4, 0);
            int var28 = 0;
            for (int var29 = 0; var29 < var27; var29++) {
                GameObject* var30 = var5->GetCombatantByIndex(var2[var29]);
                if (!var30) continue;
                if (func_02010088((Struct_02010088*)var30)) {
                    var28 = 1;
                    break;
                }
            }
            if (!var28) {
                func_020a07b0((Struct_020a07b0*)&var4, 1);
                func_020a00a4((Struct_020a00a4*)var26, 1);
            }
        }
        func_020ac494(&var4);
    }
    return var8;
}
