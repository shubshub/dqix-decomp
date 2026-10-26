#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"

struct Struct_020885b4;
struct Struct_02088644;
struct Struct_02088514;
struct Struct_ov024_021df454_2;
struct Struct_ov024_021dced0_2;
struct Struct_ov024_021df454_7;
extern "C" int func_020885b4(Struct_020885b4*);
extern "C" void func_02088644(Struct_02088644*);
extern "C" int func_02088514(Struct_02088514*);
extern "C" void func_02088598(unsigned char*);
extern "C" int func_ov024_021df6ec(Struct_ov024_021df454_2*);
extern "C" int func_ov024_021dd010(Struct_ov024_021dced0_2*);
extern "C" int func_ov024_021df704(Struct_ov024_021df454_7*);
extern "C" void func_02088874(unsigned char*);
extern "C" void func_020888c4(unsigned char*);
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
extern "C" int func_ov024_021da644(int, int, int);
void ApplyCombatantBuffs(int, int);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);

struct Struct_ov024_021df454 {
    char field_0[0x1c];
    unsigned char field_1c : 7;
    unsigned char alternate : 1;
};
struct Struct_ov024_021df454_3 {
    char field_0[0xc];
    Struct_ov024_021df454* flags;
    void* battle;
};
struct Struct_ov024_021df454_4 {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int flags : 2;
};
struct Struct_ov024_021df454_5 {
    char field_0[0x20];
    Struct_ov024_021df454_4 unknown_20_;
    Struct_ov024_021df454_4 unknown_24_;
};
struct Struct_ov024_021df454_6 {
    char field_0[0x58];
    unsigned int unknown_58_0_ : 21;
    int unknown_5a_5_ : 3;
    int unknown_5b_0_ : 3;
    int unknown_5b_3_ : 3;
};

// USA: func_ov024_021df454
extern "C" ARM void* func_ov024_021df454(Struct_ov024_021df454_3* action, int unused, int id, Struct_ov024_021df454_5* data) {
    GameObject* target = GetCombatantByID((int)action->battle, id);
    if (!target) return 0;
    int count = 0;
    if (func_020885b4((Struct_020885b4*)target->currentStats_)) {
        func_02088644((Struct_02088644*)target->currentStats_);
        ++count;
    }
    if (func_02088514((Struct_02088514*)target->currentStats_)) {
        func_02088598((unsigned char*)target->currentStats_);
        ++count;
    }
    if (func_ov024_021df6ec((Struct_ov024_021df454_2*)target)) {
        func_02088874((unsigned char*)target->currentStats_);
        ++count;
    }
    if (func_ov024_021dd010((Struct_ov024_021dced0_2*)target)) {
        func_020888c4((unsigned char*)target->currentStats_);
        ++count;
    }
    if (func_ov024_021df704((Struct_ov024_021df454_7*)target)) {
        func_02088d4c((unsigned char*)target->currentStats_);
        ++count;
    }
    if (target->currentStats_->attackBuff < 0) {
        func_02087838(target->currentStats_);
        ++count;
    }
    if (target->currentStats_->defenseBuff < 0) {
        func_0208792c(target->currentStats_);
        ++count;
    }
    if (target->currentStats_->agilityBuff < 0) {
        func_02087a20(target->currentStats_);
        ++count;
    }
    if (target->currentStats_->charmBuff < 0) {
        func_02087b14(target->currentStats_);
        ++count;
    }
    if (target->currentStats_->magicalMightBuff < 0) {
        func_02087c08(target->currentStats_);
        ++count;
    }
    if (target->currentStats_->magicalMendingBuff < 0) {
        func_02087cfc(target->currentStats_);
        ++count;
    }
    if (target->currentStats_->unknown_5a_2_ < 0) {
        func_02087df0(target->currentStats_);
        ++count;
    }
    if (((Struct_ov024_021df454_6*)target->currentStats_)->unknown_5a_5_ < 0) {
        func_02087efc((unsigned char*)target->currentStats_);
        ++count;
    }
    if (((Struct_ov024_021df454_6*)target->currentStats_)->unknown_5b_3_ < 0) {
        func_02087ff0(target->currentStats_);
        ++count;
    }
    if (((Struct_ov024_021df454_6*)target->currentStats_)->unknown_5b_0_ < 0) {
        func_020880e4(target->currentStats_);
        ++count;
    }
    int code;
    if (count > 0) code = func_ov024_021da644(id, data->unknown_20_.third, data->unknown_24_.first);
    else code = func_ov024_021da644(id, data->unknown_24_.second, data->unknown_24_.third);
    ApplyCombatantBuffs((int)action->battle, id);
    void* entry = func_ov000_0215e958(action->battle);
    if (!entry) return 0;
    func_ov000_0215a88c(action->battle, entry, (unsigned short)code);
    func_ov000_0215cd44(action->battle, entry, target, 0, 0, 0, action->flags->alternate != 0);
    return entry;
}
