#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021da670_6;
struct Struct_ov024_021dd028_5;
struct Struct_ov024_021e4604;
struct Struct_ov024_021eda78_5;
struct Struct_ov024_021dced0_2;
struct Struct_02088660;
struct Struct_ov024_021fa7ec_5;
struct Struct_ov024_021fa7ec_6;
struct Struct_ov024_021fc754_5;
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" int func_ov024_021e47dc(Struct_ov024_021e4604*);
extern "C" int func_ov024_021edc08(Struct_ov024_021eda78_5*);
extern "C" int func_ov024_021dd010(Struct_ov024_021dced0_2*);
extern "C" int func_02088660(Struct_02088660*);
extern "C" int func_ov024_021fb430(Struct_ov024_021fa7ec_5*);
extern "C" int func_ov024_021fb448(Struct_ov024_021fa7ec_6*);
extern "C" int func_ov024_021eadfc(GameObject*);
extern "C" int func_ov024_021fcac0(Struct_ov024_021fc754_5*);

struct Struct_ov024_021fc754_6 {
    unsigned char field_0[0x14];
    unsigned int statusFlags;
    unsigned int unknown_18_;
    unsigned char field_1c[0x58 - 0x1c];
    signed int unknown_58_0_ : 3;
    signed int unknown_58_3_ : 3;
    signed int unknown_58_6_ : 3;
    signed int unknown_59_1_ : 3;
    signed int unknown_59_4_ : 3;
    signed int unknown_59_7_ : 3;
    signed int field_18 : 3;
    signed int unknown_5a_5_ : 3;
    signed int unknown_5b_0_ : 3;
    signed int unknown_5b_3_ : 3;
    unsigned int unknown_5b_6_ : 2;
};
static inline Struct_ov024_021fc754_6* inline_ov024_021fc754(GameObject* object) {
    return (Struct_ov024_021fc754_6*)object->currentStats_;
}
struct Struct_ov024_021fc754 { unsigned char active; signed char weight; };
struct Struct_ov024_021fc754_2 { signed char level; signed char weight; };
union Struct_ov024_021ff026 { Struct_ov024_021fc754 entries[22]; signed char bytes[44]; };
union Struct_ov024_021fefd6 { Struct_ov024_021fc754_2 entries[10]; signed char bytes[20]; };
extern const Struct_ov024_021ff026 data_ov024_021ff026;
extern const Struct_ov024_021fefd6 data_ov024_021fefd6;
struct Struct_ov024_021fc754_3 { float value; unsigned char id, flag5, index, unknown_7_, code; };
struct Struct_ov024_021f6a1c { Struct_ov024_021fc754_3 entries[16]; int count; float threshold; };
extern "C" void func_ov024_021f6a1c(Struct_ov024_021f6a1c*, void*);
struct Struct_ov024_021fc754_4 {
    unsigned char field_0[4];
    short id;
    unsigned char unknown_6_[0x7c - 6];
    GameObject* entries[8];
    int count;
};
extern "C" int func_ov024_021fe698(Struct_ov024_021fc754_4*, int);
extern "C" void func_ov024_021f9874(Struct_ov024_021fc754_4*, Struct_ov024_021f6a1c*, int, int);

// USA: func_ov024_021fc754
extern "C" ARM void func_ov024_021fc754(Struct_ov024_021fc754_4* battle) {
    if (!func_ov024_021fe698(battle, 1)) return;
    int total = 0;
    for (int i = 0; i < battle->count; i++) {
        GameObject* object = battle->entries[i];
        if (!object) continue;
        int var3 = 0;
        Struct_ov024_021ff026 var4 = data_ov024_021ff026;
        var4.entries[0].active = func_ov024_021da998((Struct_ov024_021da670_6*)object);
        var4.entries[1].active = func_ov024_021dd260((Struct_ov024_021dd028_5*)object);
        var4.entries[2].active = (inline_ov024_021fc754(object)->statusFlags & 0x200) != 0;
        var4.entries[3].active = (inline_ov024_021fc754(object)->statusFlags & 0x8000000) != 0;
        var4.entries[4].active = (inline_ov024_021fc754(object)->statusFlags & 0x10000000) != 0;
        var4.entries[5].active = (inline_ov024_021fc754(object)->statusFlags & 0x20000000) != 0;
        var4.entries[6].active = (inline_ov024_021fc754(object)->statusFlags & 0x100000) != 0;
        var4.entries[7].active = func_ov024_021e47dc((Struct_ov024_021e4604*)object);
        var4.entries[8].active = func_ov024_021edc08((Struct_ov024_021eda78_5*)object);
        var4.entries[9].active = (inline_ov024_021fc754(object)->statusFlags & 0x40000000) != 0;
        var4.entries[10].active = func_ov024_021dd010((Struct_ov024_021dced0_2*)object);
        var4.entries[11].active = func_ov024_021edc08((Struct_ov024_021eda78_5*)object);
        var4.entries[12].active = (inline_ov024_021fc754(object)->statusFlags & 0x200000) != 0;
        var4.entries[13].active = (inline_ov024_021fc754(object)->statusFlags & 0x80000000) != 0;
        var4.entries[14].active = func_02088660((Struct_02088660*)object->currentStats_);
        var4.entries[15].active = (inline_ov024_021fc754(object)->unknown_18_ & 8) != 0;
        var4.entries[16].active = (inline_ov024_021fc754(object)->unknown_18_ & 0x10) != 0;
        var4.entries[17].active = func_ov024_021fb430((Struct_ov024_021fa7ec_5*)object);
        var4.entries[18].active = func_ov024_021fb448((Struct_ov024_021fa7ec_6*)object);
        var4.entries[19].active = func_ov024_021eadfc(object);
        var4.entries[20].active = func_ov024_021fcac0((Struct_ov024_021fc754_5*)object);
        var4.entries[21].active = (inline_ov024_021fc754(object)->unknown_18_ & 0x100) != 0;
        for (int j = 0; j < 22; j++) {
            unsigned char active = (unsigned char)var4.bytes[j * 2];
            int weight = var4.bytes[j * 2 + 1];
            if (active) var3 += weight;
        }
        Struct_ov024_021fefd6 var8 = data_ov024_021fefd6;
        var8.entries[0].level = inline_ov024_021fc754(object)->unknown_58_0_;
        var8.entries[1].level = inline_ov024_021fc754(object)->unknown_58_3_;
        var8.entries[2].level = inline_ov024_021fc754(object)->unknown_58_6_;
        var8.entries[3].level = inline_ov024_021fc754(object)->unknown_59_1_;
        var8.entries[4].level = inline_ov024_021fc754(object)->unknown_59_4_;
        var8.entries[5].level = inline_ov024_021fc754(object)->unknown_59_7_;
        var8.entries[6].level = inline_ov024_021fc754(object)->field_18;
        var8.entries[7].level = inline_ov024_021fc754(object)->unknown_5a_5_;
        var8.entries[8].level = inline_ov024_021fc754(object)->unknown_5b_0_;
        var8.entries[9].level = inline_ov024_021fc754(object)->unknown_5b_3_;
        for (int j = 0; j < 10; j++) {
            int level = var8.bytes[j * 2];
            int weight = var8.bytes[j * 2 + 1];
            if (level > 0) var3 += weight * level;
            else if (level < 0) var3 += weight * level * 3;
        }
        total += var3;
    }
    if (total > 0) {
        Struct_ov024_021f6a1c list;
        memset(&list, 0, sizeof(list));
        Struct_ov024_021fc754_3 entry;
        entry.value = total;
        entry.flag5 = 1;
        entry.index = 0;
        entry.unknown_7_ = 100;
        entry.code = 6;
        func_ov024_021f6a1c(&list, &entry);
        func_ov024_021f9874(battle, &list, 0, (unsigned char)battle->id);
    }
}
