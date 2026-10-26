#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov000_02166540 {
    unsigned short unknown_0_0_ : 15;
    unsigned short unknown_1_7_ : 1;
    unsigned char unknown_2_[0xe];
    unsigned int unknown_10_0_ : 28;
    unsigned int unknown_13_4_ : 1;
    unsigned int unknown_13_5_ : 3;
};
struct Struct_ov000_02166540_4 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[4];
    Struct_ov000_02166540* unknown_b0_;
};
struct Struct_ov000_02166540_5 {
    unsigned char unknown_0_[0x36];
    unsigned short unknown_36_;
    unsigned char unknown_38_[0x6c];
};
struct Struct_ov000_02166540_7 {
    Object3D unknown_0_;
    unsigned char unknown_ac_[4];
    unsigned short unknown_b0_;
    unsigned char unknown_b2_[0x10];
    unsigned char unknown_c2_;
    unsigned char unknown_c3_[0x75];
    Struct_ov000_02166540_5* unknown_138_;
    unsigned char unknown_13c_[0x40];
    unsigned char unknown_17c_;
    unsigned char unknown_17d_[0x13];
};
struct Struct_ov000_02166540_8 { unsigned char unknown_0_[0x70]; };
struct Struct_ov000_02166540_9 {
    unsigned char unknown_0_[0x400];
    unsigned char unknown_400_[0xc];
    unsigned char unknown_40c_[0xc];
};
struct Struct_ov000_02166540_2 {
    union {
        struct {
            unsigned char unknown_0_[0x158];
            Struct_ov000_02166540_5 unknown_158_[8];
            unsigned char unknown_678_[0xc];
            unsigned char unknown_684_[0xc];
        };
        struct {
            unsigned char unknown1_0_[0x278];
            Struct_ov000_02166540_9 unknown_278_;
        };
    };
};
struct Struct_ov000_02161c0c_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x21c];
#else
    unsigned char unknown1_0_[0x2a0];
#endif
    Struct_ov000_02166540_2* unknown_2a0_;
    unsigned char unknown_2a4_[0xc14];
    Struct_ov000_02166540_4* unknown_eb8_[4];
    unsigned short unknown_ec8_;
#if defined(jpn)
    unsigned char unknown_e46_[0x6014 - 0xe46];
#else
    unsigned char unknown_eca_[0x4f5a];
#endif
    Struct_ov000_02166540_7 unknown_5e24_[8];
    Struct_ov000_02166540_8 unknown_6aa4_[8];
};
struct Struct_02070b6c_3;
struct Struct_0204887c;
struct Struct_0206f01c_2;
struct Struct_02010604;
struct Struct_ov000_02166540_3 {
    unsigned char unknown_0_[0xc];
    short unknown_c_;
};
void ResetNameState02048614(unsigned char*);
extern "C" void func_02049c88(NameCombatant*, CombatantModelState*);
void CopyObjectFields02048588(unsigned char*, unsigned char*);
void BuildName020488ec(char*);
char* SearchWithLow15Comparator02070fd0(Container02070e60*, int);
void ReplaceEntryAndFormat0204887c(Obj0204887c*, char*);
void SetSubstructFlag0x80_02048bb8(unsigned char*);
void SetSubstructFlag0x200_02048bf8(unsigned char*);
CombatantScaleEntry* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
int GameObject_ForceMotionState(Bytes02033b88*, int);
void RegisterCombatantSlot_0200fd38(GameState*, int, GameObject*);
void AllocateSlotAndConfigureField02166784(Struct5e00*, unsigned char*, unsigned char*);
int FindOrAssignSlot02167c28(unsigned char*, int);
extern "C" void func_ov017_02191aac(void*, int, int, int);

// USA: func_ov000_02166540
extern "C" ARM void func_ov000_02166540(Struct_ov000_02161c0c_3* arg0, int arg1, int arg2, unsigned char arg3) {
    if (arg1 < 0xc0 || arg1 > 0xc7) return;
    GameState* var0 = GameState::GetInstance();
    void* var1 = GetGameResources();
    Struct_ov000_02166540_9* var2 = &arg0->unknown_2a0_->unknown_278_;
    int var3 = arg1 - 0xc0;
    Struct_ov000_02166540_4* var4 = 0;
    for (int var5 = 0; var5 < 4; var5++) {
        Struct_ov000_02166540_4* var6 = arg0->unknown_eb8_[var5];
        if (var6 && arg2 == var6->unknown_0_.unknown_2_) {
            var4 = var6;
            break;
        }
    }
    if (!var4) return;
    Struct_ov000_02166540_7* var7 = &arg0->unknown_5e24_[var3];
    if (!var7) return;
    func_02048614((unsigned char*)var7);
    Struct_ov000_02166540_8* var8 = &arg0->unknown_6aa4_[var3];
    if (!var8) return;
    func_02049c88(var7, var8);
    var7->unknown_c2_ |= 0x20;
    func_02048588((unsigned char*)var4, (unsigned char*)var7);
    var7->unknown_0_.SetField06(arg0->unknown_ec8_);
    var7->unknown_17c_ = arg3;
    var7->unknown_138_ = &arg0->unknown_2a0_->unknown_158_[var3];
    func_020488ec((char*)var7);
    if (var7->unknown_138_->unknown_36_) {
        char* var9 = func_02070fd0((Struct_02070b6c_3*)arg0->unknown_2a0_->unknown_684_, var7->unknown_138_->unknown_36_);
        if (var9) func_0204887c((Struct_0204887c*)var7, var9);
    }
    var7->unknown_0_.EnableFlag(8);
    Struct_ov000_02166540* var10 = var4->unknown_b0_;
    if (var10) {
        if (!var10->unknown_13_4_) func_02048bb8((unsigned char*)var7);
        if (!var10->unknown_1_7_) func_02048bf8((unsigned char*)var7);
    }
    Struct_ov000_02166540_3* var11 = func_0206f4f0((Struct_0206f01c_2*)var2->unknown_400_, (short)arg2);
    if (var11) {
        int var12 = var11->unknown_c_ << 2;
        unsigned int var13 = 0x324;
        if (var12 >= 0x4000) var13 = 0xc9;
        else if (var12 >= 0x3000) var13 = 0x10c;
        else if (var12 >= 0x2000) var13 >>= 1;
        var7->unknown_b0_ = var13;
    }
    GameObject_ForceMotionState((Bytes02033b88*)combatant, 0);
    RegisterCombatantSlot_0200fd38(game, slot, (GameObject*)combatant);
    AllocateSlotAndConfigureField02166784(state, (unsigned char*)source, (unsigned char*)combatant);
    FindOrAssignSlot02167c28((unsigned char*)state, slot);
    GameObject* registered = game->GetCombatantByIndex(slot);
    if (registered) {
        struct CombatFlags { unsigned char pad_00[0x14]; unsigned int flags; };
        if (((CombatFlags*)registered->currentStats_)->flags & 0x1000000) func_ov017_02191aac(effects, 1, slot, 4);
    }
}
