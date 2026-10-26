#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>

struct Struct_ov017_021d82e0 { char pad[0x10]; int battle; };
struct Struct_ov017_021cb974_4 {
    char pad0[0x3b];
    unsigned char unknown_3b_0_ : 1;
    unsigned char unknown_3b_1_ : 7;
    char pad1[0x1c];
    unsigned int unknown_58_0_ : 21;
    signed int unknown_5a_5_ : 3;
    signed int field24 : 3;
    signed int unknown_5b_3_ : 3;
};
struct Struct_ov024_021de124;
struct Struct_ov024_021da670_7;
struct Struct_ov024_021da670_8;
struct Struct_ov024_021df454_2;
struct Struct_ov024_021dced0_2;
struct Struct_ov024_021df454_7;
struct Struct_020885b4;
struct Struct_02088644;
struct Struct_02088514;
extern "C" int func_020882f8(unsigned char*);
extern "C" void func_02088390(void*);
extern "C" int func_ov024_021de25c(Struct_ov024_021de124*);
extern "C" void func_020883fc(void*);
extern "C" int func_ov024_021da9b0(Struct_ov024_021da670_7*);
extern "C" void func_020882dc(void*);
extern "C" int func_ov024_021da9c8(Struct_ov024_021da670_8*);
extern "C" void func_020884f8(unsigned char*);
extern "C" int func_020885b4(Struct_020885b4*);
extern "C" void func_02088644(Struct_02088644*);
extern "C" int func_02088514(Struct_02088514*);
extern "C" void func_02088598(unsigned char*);
extern "C" int func_ov024_021df6ec(Struct_ov024_021df454_2*);
extern "C" void func_02088874(unsigned char*);
extern "C" int func_ov024_021dd010(Struct_ov024_021dced0_2*);
extern "C" void func_020888c4(unsigned char*);
extern "C" int func_ov024_021df704(Struct_ov024_021df454_7*);
extern "C" void func_02088d4c(unsigned char*);
extern "C" void func_02087838(void*);
extern "C" void func_0208792c(void*);
extern "C" void func_02087a20(void*);
extern "C" void func_02087b14(void*);
extern "C" void func_02087c08(void*);
extern "C" void func_02087cfc(void*);
extern "C" void func_02087df0(void*);
extern "C" void func_02087efc(unsigned char*);
extern "C" void func_02087ff0(void*);
extern "C" void func_020880e4(void*);
void ApplyCombatantBuffs(int, int);

// USA: func_ov024_021eae14
extern "C" ARM int func_ov024_021eae14(Struct_ov017_021d82e0* context, int id) {
    GameObject* combatant = GetCombatantByID(context->battle, id);
    if (!combatant) return 0;
    int count = 0;
    int var2 = 0;
    if (func_020882f8((unsigned char*)combatant->currentStats_)) {
        func_02088390(combatant->currentStats_); count++; var2 = 1;
    }
    if (func_ov024_021de25c((Struct_ov024_021de124*)combatant)) {
        func_020883fc(combatant->currentStats_); count++; var2 = 1;
    }
    if (func_ov024_021da9b0((Struct_ov024_021da670_7*)combatant)) {
        func_020882dc(combatant->currentStats_); count++; var2 = 1;
    }
    if (func_ov024_021da9c8((Struct_ov024_021da670_8*)combatant)) {
        func_020884f8((unsigned char*)combatant->currentStats_); count++; var2 = 1;
    }
    if (func_020885b4((Struct_020885b4*)combatant->currentStats_)) {
        func_02088644((Struct_02088644*)combatant->currentStats_); count++;
    }
    if (func_02088514((Struct_02088514*)combatant->currentStats_)) {
        func_02088598((unsigned char*)combatant->currentStats_); count++;
    }
    if (func_ov024_021df6ec((Struct_ov024_021df454_2*)combatant)) {
        func_02088874((unsigned char*)combatant->currentStats_); count++;
    }
    if (func_ov024_021dd010((Struct_ov024_021dced0_2*)combatant)) {
        func_020888c4((unsigned char*)combatant->currentStats_); count++;
    }
    if (func_ov024_021df704((Struct_ov024_021df454_7*)combatant)) {
        func_02088d4c((unsigned char*)combatant->currentStats_); count++;
    }
    if (combatant->currentStats_->attackBuff < 0) { func_02087838(combatant->currentStats_); count++; }
    if (combatant->currentStats_->defenseBuff < 0) { func_0208792c(combatant->currentStats_); count++; }
    if (combatant->currentStats_->agilityBuff < 0) { func_02087a20(combatant->currentStats_); count++; }
    if (combatant->currentStats_->charmBuff < 0) { func_02087b14(combatant->currentStats_); count++; }
    if (combatant->currentStats_->magicalMightBuff < 0) { func_02087c08(combatant->currentStats_); count++; }
    if (combatant->currentStats_->magicalMendingBuff < 0) { func_02087cfc(combatant->currentStats_); count++; }
    if (combatant->currentStats_->unknown_5a_2_ < 0) { func_02087df0(combatant->currentStats_); count++; }
    if (((Struct_ov017_021cb974_4*)combatant->currentStats_)->unknown_5a_5_ < 0) { func_02087efc((unsigned char*)combatant->currentStats_); count++; }
    if (((Struct_ov017_021cb974_4*)combatant->currentStats_)->unknown_5b_3_ < 0) { func_02087ff0(combatant->currentStats_); count++; }
    if (((Struct_ov017_021cb974_4*)combatant->currentStats_)->field24 < 0) { func_020880e4(combatant->currentStats_); count++; }
    if (var2) ((Struct_ov017_021cb974_4*)combatant->currentStats_)->unknown_3b_0_ = 1;
    ApplyCombatantBuffs(context->battle, id);
    return count;
}
