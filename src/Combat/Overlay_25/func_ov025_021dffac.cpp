#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov025_021dffac { char unknown_0_[0x20]; unsigned short unknown_20_; };
struct Struct_ov025_021dffac_2 { char unknown_0_[0xe]; short unknown_e_; };
struct Struct_ov025_021dffac_3 {
    unsigned short unknown_0_; char unknown_2_[0xe]; Struct_ov025_021dffac* unknown_10_; Struct_ov025_021dffac_2* unknown_14_; char unknown_18_[0x10];
};
struct Struct_ov025_021dffac_4 { char unknown_0_[0x821c]; Struct_ov025_021dffac_3 unknown_821c_[77]; int unknown_8e24_; };
#if defined(jpn)
struct Struct_ov025_021dffac_5 { char unknown_0_[0x218]; Struct_ov025_021dffac_4* unknown_29c_; char unknown_21c_[0x57c8-0x21c]; int unknown_55d8_; };
#else
struct Struct_ov025_021dffac_5 { char unknown_0_[0x29c]; Struct_ov025_021dffac_4* unknown_29c_; char unknown_2a0_[0x5338]; int unknown_55d8_; };
#endif
union Struct_ov025_021dffac_6 { Vector3fix unknown_0_; int unknown1_0_[3]; };
struct Struct_ov025_021dffac_7 { unsigned char unknown_0_; char unknown_1_[3]; int unknown_4_; GameObject* unknown_8_; };
struct Struct_ov025_021dffac_8 { int unknown_0_, unknown_4_; };
extern "C" int func_ov000_02163690(int);
extern "C" void* func_02079e2c(char*, int);
extern "C" int func_ov000_021627fc(void*);
extern "C" int func_ov025_021e1048(Struct_ov025_021dffac_4*, Struct_ov025_021dffac_7*);
extern "C" unsigned char func_020493a4(unsigned char*);
extern "C" unsigned char func_020493c8(unsigned char*);
extern "C" unsigned char func_020493ec(unsigned char*);
extern "C" void func_02049390(unsigned char*, unsigned char);
extern "C" void func_020493b8(unsigned char*, unsigned char);
extern "C" void func_020493dc(unsigned char*, unsigned char);
extern "C" void func_02049400(unsigned char*, unsigned char);
extern "C" int func_ov025_021e1540(int);
extern "C" Struct_ov025_021dffac_7* func_ov025_021e1010(unsigned char*, int, int);
extern "C" void func_ov025_021e110c(unsigned char*, Struct_ov025_021dffac_7*, int);
extern "C" int func_02048bd0(unsigned char*);
extern "C" Struct_ov025_021dffac_8 func_ov000_0216f74c(int*);
extern "C" void __clear(void*, int);
extern "C" int Vector3fix_DistanceToSegment(const Vector3fix*, const Vector3fix*, const Vector3fix*, Vector3fix*);
extern "C" void func_ov025_021e1ff4(unsigned char*, unsigned char, unsigned char*, GameObject*, GameObject*, Entry021dffac*, int);
extern "C" int func_ov025_021e1f40(GameObject*, int);
extern "C" void func_ov025_021e16c8(Struct_ov025_021dffac_7*, Struct_ov025_021dffac_7*, unsigned char*, Struct_ov025_021dffac_3*, void*, Struct_ov025_021dffac_7*, int);
extern "C" void func_ov025_021e1d54(Struct_ov025_021dffac_7*, unsigned char*);
extern "C" int func_ov025_021e1f08(unsigned char*, unsigned char*);
extern "C" int func_ov000_021628c8(void*, int, int*);
extern "C" int func_ov025_021dfbd4(int);

inline int inline_ov025_021dffac(unsigned char arg0) {
    return arg0 >= 0xc0 && arg0 <= 0xc7;
}
inline int inline_ov025_021dffac_2(unsigned char arg0) {
    return arg0 >= 0xf2;
}

inline Struct_ov025_021dffac_3* inline_ov025_021dffac_3(Struct_ov025_021dffac_4* arg0, int arg1) { return &arg0->unknown_821c_[arg1]; }

// USA: func_ov025_021dffac
extern "C" ARM int func_ov025_021dffac(Struct_ov025_021dffac_5* arg0) {
    GameState* var0 = GameState::GetInstance();
    Struct_ov025_021dffac_4* var1 = arg0->unknown_29c_;
    int var2;
    Struct_ov025_021dffac_3* var3 = inline_ov025_021dffac_3(var1, arg0->unknown_55d8_);
    int var4 = var3->unknown_0_;
    if (func_ov000_02163690(var4)) var4 = 1;
    void* var5 = func_02079e2c((char*)func_020797dc(), (short)var4);
    if (!var5) return 0;
    if (!func_ov000_021627fc(arg0)) return 0;
    Struct_ov025_021dffac_7 var6[12];
    int var7 = func_ov025_021e1048(var1, var6);
    Struct_ov025_021dffac_3* var8 = var1->unknown_821c_;
    int var9 = var1->unknown_8e24_;
    int var10 = arg0->unknown_55d8_;
    for (int var11 = 0; var11 < var7; ++var11) {
        func_020493b8((unsigned char*)var6[var11].unknown_8_, func_020493a4((unsigned char*)var6[var11].unknown_8_));
        func_02049400((unsigned char*)var6[var11].unknown_8_, 0xff);
    }
    for (int i = 0; i < count; ++i) {
        GameObject* actor = entries[i].actor;
        int current = GetSubstructByte0x1c_020493a4((unsigned char*)actor);
        if (current == GetSubstructByte0x1e_020493ec((unsigned char*)actor))
            SetSubstructByte0x1c_02049390((unsigned char*)actor, (unsigned char)func_ov025_021e1540(actor->obj3D_.actorIndex_));
    }
    var2 = 0;
    if (var3->unknown_10_) var2 = var3->unknown_10_->unknown_20_;
    Struct_ov025_021dffac_7* var15 = func_ov025_021e1010((unsigned char*)var6, var7, var2);
    if (!var15) return 0;
    int var16 = -1;
    if (var3->unknown_14_) var16 = var3->unknown_14_->unknown_e_;
    Struct_ov025_021dffac_7* var17 = func_ov025_021e1010((unsigned char*)var6, var7, var16);
    if (!var17) return 0;
    if (var2 == var16) return 1;
    unsigned char var18[81];
    unsigned char var19[81];
    unsigned char var20[12];
    int var21[12];
    Struct_ov025_021dffac_6 var22;
    Struct_ov025_021dffac_6 var23;
    Struct_ov025_021dffac_6 var24;
    Struct_ov025_021dffac_6 var25;
    memset(var18, 0, sizeof(var18));
    memset(var20, 0, sizeof(var20));
    Struct_ov025_021dffac_3* var26;
    Struct_ov025_021dffac_3* var27;
    int var28;
    Struct_ov025_021dffac_7* var29;
    Struct_ov025_021dffac* var30;
    for (int var31 = var10; var31 < var9; ++var31) {
        func_ov025_021e110c(var18, var6, var7);
        var26 = &var8[var31];
        var30 = var26->unknown_10_;
        if (!var30 || !var26->unknown_14_) continue;
        int var32 = var30->unknown_20_;
        unsigned char var33 = var32;
        if (inline_ov025_021dffac(var33)) var33 -= 0xbc;
        if (var33 < 12) {
            if (var20[var33]) continue;
            var20[var33] = 1;
        }
        GameObject* actor = game->GetCombatantByIndex(actorIndex);
        if (!actor) continue;
        if (selectedIndex == i) {
            GameObject* target = game->GetCombatantByIndex(targetIndex);
            unsigned short actionID = action->id;
            if (actor && target && CheckSubstructFlag0x80_02048bd0((unsigned char*)actor) && (unsigned int)(actionID - 9) <= 2) {
                COPY_ARRAY(sourcePosition.coordinates, ((const Position021dffac*)&actor->obj3D_.position_)->coordinates);
                COPY_ARRAY(targetPosition.coordinates, ((const Position021dffac*)&target->obj3D_.position_)->coordinates);
                int candidateCount = 0;
                for (int cellIndex = 0; cellIndex < 81; ++cellIndex) {
                    if (cellIndex % 18 == 17) continue;
                    Cell021dffac cell = func_ov000_0216f74c(&cellIndex);
                    __clear(&position, 12);
                    position.vector.x = cell.x;
                    position.vector.z = cell.z;
                    if (Vector3fix_DistanceToSegment(&sourcePosition.vector, &targetPosition.vector, &position.vector, &projected.vector) < 0x1800)
                        candidates[candidateCount++] = cellIndex;
                }
                func_ov025_021e1ff4(var19, (unsigned char)var37, var18, var34, var35, var6, var7);
            }
        }
        if (!func_ov025_021e1f40(var34, var16)) continue;
        if (var10 == var31) {
            func_ov025_021e16c8(var15, var17, var18, &var8[var10], var5, var6, var7);
            func_02049400((unsigned char*)var15->unknown_8_, func_020493c8((unsigned char*)var17->unknown_8_));
        } else {
            Struct_ov025_021dffac_7* var40 = func_ov025_021e1010((unsigned char*)var6, var7, var30->unknown_20_);
            if (var40 && var40->unknown_4_) func_ov025_021e1d54(var40, var18);
            else if (var40 && func_020493a4((unsigned char*)var40->unknown_8_) != 0xff) {
                int var41 = func_ov025_021e1f08((unsigned char*)var40->unknown_8_, (unsigned char*)var26);
                Struct_ov025_021dffac_7* var42 = func_ov025_021e1010((unsigned char*)var6, var7, var41);
                if (!var42) continue;
                func_ov025_021e16c8(var40, var42, var18, &var8[var10], var5, var6, var7);
                func_02049400((unsigned char*)var40->unknown_8_, func_020493c8((unsigned char*)var42->unknown_8_));
            }
        }
    }
    for (int var43 = 0; var43 < var10; ++var43) {
        func_ov025_021e110c(var18, var6, var7);
        var27 = &var8[var43];
        if (!var27->unknown_10_ || !var27->unknown_14_) continue;
        var28 = func_ov000_021628c8(arg0, var43, var21);
        for (int var44 = 0; var44 < var28; ++var44) {
            int var45 = var21[var44];
            unsigned char var46 = var45;
            if (inline_ov025_021dffac(var46)) var46 -= 0xbc;
            if (var46 < 12) {
                if (var20[var46]) continue;
                var20[var46] = 1;
            }
            previousEntry = FindByteMatch_021e1010((unsigned char*)entries, count, actorIndex);
            GameObject* actor = game->GetCombatantByIndex(actorIndex);
            if (!actor || !previousEntry || !func_ov025_021e1f40(actor, targetIndex)) continue;
            unsigned char cell = GetSubstructByte0x1e_020493ec((unsigned char*)actor);
            if (cell < 81 && (!IsOccupied021dffac(occupied[cell]) || occupied[cell] == AdjustIndex_021dfbd4(actor->obj3D_.actorIndex_)))
                SetSubstructByte0x1d_020493b8((unsigned char*)actor, cell);
            else func_ov025_021e1d54(previousEntry, occupied);
            SetSubstructByte0x1e_020493dc((unsigned char*)actor, 0xff);
            int fallback = GetSubByteOrFallback_021e1f08((unsigned char*)actor, (unsigned char*)previousAction);
            GameObject* other = game->GetCombatantByIndex(fallback);
            if (other) SetSubstructByte0x1f_02049400((unsigned char*)actor, GetSubstructByte0x1d_020493c8((unsigned char*)other));
        }
    }
    return 1;
}
