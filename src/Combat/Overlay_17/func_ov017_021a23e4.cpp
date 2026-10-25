#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"


struct Struct_020fdd44;
struct Struct_0206f01c_2;
struct Struct_02073ec4_3;
struct Struct_ov017_021a23e4 { char unknown_0_[0xc]; short unknown_c_; short unknown_e_; };
struct Struct_ov017_021a23e4_2 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 2;
    unsigned short unknown_2_2_ : 14;
    short unknown_4_;
    unsigned short unknown_6_;
    char unknown_8_[0x10];
#if defined(jpn)
    char unknown_18_[0x44];
#else
    char unknown1_18_[0x48];
#endif
    char unknown_60_[0x298];
    char unknown_2f8_[0xc];
    char unknown_304_[0xc];
};
struct Struct_ov017_021a23e4_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
};
struct Struct_ov017_021a23e4_4 {
    Object3D unknown_0_;
    char unknown_ac_[0x130 - 0xac];
    int unknown_130_;
    char unknown_134_[4];
    Struct_ov017_021a23e4_3 unknown_138_;
    char unknown_14c_[0x16a - 0x14c];
    unsigned short unknown_16a_;
};

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
int GetBitflagForCombatantColor_021a26e8(GameResources* unused0, int combatantId);
extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
Entry_02028bd0* ZoneRecords_GetInstance();
AreaEntry021a23e4* FindInlineEntryById(Entry_02028bd0*, int);
Entry0209bd94* FindMatchingEntryByMask02073ec4(int mask, void* list);
int SelectWeightedEntry02073fdc(void* p);
MonsterInfo021a23e4* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
int FindCombatantWithNegativeField2_021a20c0(int unused, int mult, int limit);
int GetField0x17dBits4To5IfFlag8_020795cc(unsigned char* obj);
extern "C" int func_02032370(int upperBound);
extern "C" void func_02076a8c(void* obj);
extern "C" int func_ov017_021a2128(void* arena, int areaId, int monsterId, int variant, const Vector3fix* position, int y, int entryId, int flags);

// USA: func_ov017_021a23e4
extern "C" ARM int func_ov017_021a23e4(GameResources* arg0, int arg1, int arg2, int arg3) {
    GameState* var0 = GameState::GetInstance();
    if (func_0202c540(func_0202ae18())) return 0;
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(state, combatantId);
    if (!combatant) return 0;
    if (mask == 0) mask = GetBitflagForCombatantColor_021a26e8(arena, combatantId);
    int areaId = combatant->obj3D_.GetField06();
    void* dataBase = Scenario_GetInstance();
    if (Scenario_TestFlag((int)dataBase, (unsigned char*)dataBase + 0x8c, 0x79a) != 0 &&
        monsterId != 0x26 && monsterId != 0x27 && monsterId != 0x28 &&
        areaId >= 0x190 && areaId <= 0x199) {
        return 0;
    }
    AreaEntry021a23e4* area = FindInlineEntryById(ZoneRecords_GetInstance(), areaId);
    if (!area) return 0;
    Entry0209bd94* entry = FindMatchingEntryByMask02073ec4(mask, area->subentries);
    if (!entry) return 0;
    if (monsterId < 0) {
        monsterId = SelectWeightedEntry02073fdc(entry);
        if (monsterId < 0) return 0;
    }
    Struct_ov017_021a23e4* var6 = func_0206f4f0((Struct_0206f01c_2*)var4->unknown_2f8_, (short)arg3);
    if (!var6) return 0;
    int var7 = var6->unknown_c_ << 2;
    int var8 = var1->obj3D_.GetRadius() / 4 + var7 / 2;
    Vector3fix var9 = var1->obj3D_.GetPointInFront(var8);
    Vector3fix var10 = var1->obj3D_.rotation_;
    int var11 = fix32ReduceAngle0To2Pi(var10.y + 0x3244);
    if (func_ov017_021a20c0((int)arg0, var4->unknown_2_0_, 12) < 0) {
        int var12 = 0;
        int var13[12];
        for (int var14 = 0; var14 < 12; var14++) {
            int var15 = var14 + (var4->unknown_2_0_ * 12 + 0x70);
            Struct_ov017_021a23e4_4* var16 = (Struct_ov017_021a23e4_4*)var0->GetMaybeFieldMonsterByIndex(var15);
            if (var16 == 0 || var16->unknown_130_ == 9) continue;
            if (func_020795cc((unsigned char*)var16) < 0) var13[var12++] = var15;
        }
        GameObject* var17 = var0->GetMaybeFieldMonsterByIndex(var13[func_02032370(var12)]);
        if (var17) {
            func_02076a8c(var17);
            var17->obj3D_.MakeHidden();
        }
    }
    int var18 = func_ov017_021a2128(arg0, var2, arg3, *(unsigned short*)var5, &var9, var11, 0, (unsigned char)((arg1 << 4) | 8));
    if (!var18) return 0;
    GameObject* var19 = var0->GetMaybeFieldMonsterByIndex(var18);
    if (!var19) return 0;
    Struct_ov017_021a23e4_4* var20 = (Struct_ov017_021a23e4_4*)var19;
    Struct_ov017_021a23e4_3 var21;
    Struct_ov017_021a23e4_3* var22 = &var21;
    Struct_ov017_021a23e4_3* var23 = &var20->unknown_138_;
    var22->unknown_0_ = var23->unknown_0_;
    var22->unknown_1_ = var23->unknown_1_;
    var22->unknown_2_ = var23->unknown_2_;
    var22->unknown_3_ = var23->unknown_3_;
    var22->unknown_4_ = var23->unknown_4_;
    var22->unknown_8_ = var23->unknown_8_;
    var22->unknown_c_ = var23->unknown_c_;
    var22->unknown_10_ = var23->unknown_10_;
    var21.unknown_0_ = 0;
    var21.unknown_2_ = 0;
    var23->unknown_0_ = var22->unknown_0_;
    var23->unknown_1_ = var22->unknown_1_;
    var23->unknown_2_ = var22->unknown_2_;
    var23->unknown_3_ = var22->unknown_3_;
    var23->unknown_4_ = var22->unknown_4_;
    var23->unknown_8_ = var22->unknown_8_;
    var23->unknown_c_ = var22->unknown_c_;
    var23->unknown_10_ = var22->unknown_10_;
    return var20->unknown_16a_;
}
