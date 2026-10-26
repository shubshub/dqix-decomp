#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>

struct Struct_ov024_021da670_6;
struct Struct_ov024_021dd028_5;
struct Struct_ov024_021eda78_6;
struct Struct_ov024_021e4604;
struct Struct_ov024_021eda78_5;
struct Struct_ov024_021eda78_8;
struct Struct_ov024_021eda78_7;
struct Struct_ov024_021eda78_9;
struct Struct_02088660;
struct Struct_ov024_021f26fc;
struct Struct_ov024_021e2bd0_4 {
    char pad0[0x18];
    unsigned int flags_;
    char unknown_1c_[0x3c];
    unsigned int unknown_58_0_ : 21;
    signed int unknown_5a_5_ : 3;
    signed int unknown_5b_0_ : 3;
    signed int unknown_5b_3_ : 3;
};

extern unsigned short data_ov024_021fea3c[4];
extern "C" int func_ov000_0215e9fc(int, unsigned short*, int, int);
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" int func_ov024_021eda60(GameObject*);
extern "C" int func_ov024_021edbc0(GameObject*);
extern "C" int func_ov024_021edbd8(GameObject*);
extern "C" int func_ov024_021edbf0(GameObject*);
extern "C" int func_ov024_021edc20(Struct_ov024_021eda78_6*);
extern "C" int func_ov024_021e47dc(Struct_ov024_021e4604*);
extern "C" int func_ov024_021edc08(Struct_ov024_021eda78_5*);
extern "C" int func_ov024_021edc50(Struct_ov024_021eda78_8*);
extern "C" int func_ov024_021edc38(Struct_ov024_021eda78_7*);
extern "C" int func_ov024_021edc68(Struct_ov024_021eda78_9*);
extern "C" int func_02088660(Struct_02088660*);
extern "C" int func_ov024_021f273c(Struct_ov024_021f26fc*);

// USA: func_ov024_021f3e64
extern "C" ARM int func_ov024_021f3e64(int* context, int unused, int arg2, int* outCount, short* arg4) {
    unsigned short targets[4];
    unsigned short* destination = targets;
    unsigned short* source = data_ov024_021fea3c;
    int remaining = 4;
    do {
        unsigned short* output = destination++;
        *output = *source++;
    } while (--remaining);
    int count = func_ov000_0215e9fc(*context, targets, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    *outCount = 0;
    for (int i = 0; i < count; ++i) {
        GameObject* target = GetCombatantByID(*context, (short)targets[i]);
        if (!target) continue;
        if (func_ov024_021da998((Struct_ov024_021da670_6*)target)
            || func_ov024_021dd260((Struct_ov024_021dd028_5*)target)
            || func_ov024_021eda60(target)
            || func_ov024_021edbc0(target)
            || func_ov024_021edbd8(target)
            || func_ov024_021edbf0(target)
            || func_ov024_021edc20((Struct_ov024_021eda78_6*)target)
            || func_ov024_021e47dc((Struct_ov024_021e4604*)target)
            || func_ov024_021edc08((Struct_ov024_021eda78_5*)target)
            || func_ov024_021edc50((Struct_ov024_021eda78_8*)target)
            || func_ov024_021edc08((Struct_ov024_021eda78_5*)target)
            || func_ov024_021edc38((Struct_ov024_021eda78_7*)target)
            || func_ov024_021edc68((Struct_ov024_021eda78_9*)target)
            || func_02088660((Struct_02088660*)target->currentStats_)
            || func_ov024_021f273c((Struct_ov024_021f26fc*)target)
            || (((Struct_ov024_021e2bd0_4*)target->currentStats_)->flags_ & 2)
            || (((Struct_ov024_021e2bd0_4*)target->currentStats_)->flags_ & 4)
            || (((Struct_ov024_021e2bd0_4*)target->currentStats_)->flags_ & 0x200)
            || (((Struct_ov024_021e2bd0_4*)target->currentStats_)->flags_ & 0x400)
            || (((Struct_ov024_021e2bd0_4*)target->currentStats_)->flags_ & 0x100)
            || target->currentStats_->attackBuff > 0
            || target->currentStats_->defenseBuff > 0
            || target->currentStats_->agilityBuff > 0
            || target->currentStats_->charmBuff != 0
            || target->currentStats_->magicalMightBuff > 0
            || target->currentStats_->magicalMendingBuff != 0
            || target->currentStats_->unknown_5a_2_ > 0
            || ((Struct_ov024_021e2bd0_4*)target->currentStats_)->unknown_5a_5_ != 0
            || ((Struct_ov024_021e2bd0_4*)target->currentStats_)->unknown_5b_0_ != 0
            || ((Struct_ov024_021e2bd0_4*)target->currentStats_)->unknown_5b_3_ != 0) found = 1;
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(arg4, targets, 8);
    return 1;
}
