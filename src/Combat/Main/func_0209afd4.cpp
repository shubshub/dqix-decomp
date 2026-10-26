#include <globaldefs.h>
#include "Util/Random.h"

#if defined(jpn)
#define data_020e8e2c data_020e8f40
#endif

struct Struct_0209afd4_3 {
    unsigned int key : 12;
    unsigned int unknown_1_4_ : 3;
    unsigned int unknown_1_7_ : 3;
    unsigned int unknown_2_2_ : 3;
    unsigned int unknown_2_5_ : 3;
    unsigned int unknown_3_0_ : 3;
    unsigned int rest : 5;
    int unk4;
};

struct Struct_0209afd4_4 {
    unsigned int id : 12;
    unsigned int weight : 3;
    unsigned int unknown_1_7_ : 3;
    unsigned int unknown_2_2_ : 3;
    unsigned int rest : 11;
};

struct Struct_0209afd4_5 {
    unsigned short id;
    unsigned short pad2;
    struct Struct_0209afd4_3 unknown_4_[6];
    struct Struct_0209afd4_4 members[6];
};

struct Struct_0209afd4_6;

struct Struct_02073ec4_3 {
    unsigned short key;
    unsigned short pad2;
    unsigned int unknown_4_0_ : 10;
    unsigned int maxCount : 3;
    unsigned int unknown_5_5_ : 19;
    unsigned char pad8[0x18];
};

struct Struct_02073ec4_2 {
    struct Struct_02073ec4_3 entries[6];
    int count;
};

struct Struct_0209afd4 {
#if defined(jpn)
    unsigned char pad[0x5c];
#else
    unsigned char pad[0x60];
#endif
    struct Struct_02073ec4_2 table;
};

struct Struct_0209afd4_2 {
    short ids[3];
    short counts[3];
};

struct Struct_020e8e2c {
    int slots[6][3];
};

extern "C" struct Struct_0209afd4_3* func_0209b8d4(struct Struct_0209afd4_6* table, int key, int id, int* out);
extern "C" struct Struct_0209afd4_5* func_0209b9e4(struct Struct_0209afd4_5* base, int key);
extern "C" struct Struct_02073ec4_3* func_0209bd94(struct Struct_02073ec4_2* table, int key);

extern struct Struct_020e8e2c data_020e8e2c;

// USA: func_0209afd4
extern "C" ARM void func_0209afd4(struct Struct_0209afd4_5* rows, int arg1, int arg2, int arg3, struct Struct_0209afd4_2* out, struct Struct_0209afd4* state) {
    struct Random* var0;
    struct Struct_0209afd4_3* sub;
    struct Struct_0209afd4_5* row;
    struct Struct_0209afd4_4* member;
    struct Struct_02073ec4_3* entry;
    int index;
    int kind;
    int roll;
    int total;
    int i;
    int k;
    int j;
    int l;
    int maxCount;
    int var14;
    int step;
    int prev;
    int slot;

    var0 = GetBTRandom();
    out->ids[0] = arg1;
    index = 0;
    sub = func_0209b8d4((struct Struct_0209afd4_6*)rows, arg1, arg3, &index);
    kind = 1;
    if ((unsigned short)(short)(arg1 - 0x26) <= 2) {
        out->counts[0] = 1;
    } else if (sub == NULL) {
        out->counts[0] = 1;
    } else {
        out->counts[0] = NextRandomMax(var0, sub->unknown_1_7_ - sub->unknown_1_4_ + 1) + sub->unknown_1_4_;
        roll = NextRandomMax(var0, sub->unknown_2_2_ + sub->unknown_2_5_ + sub->unknown_3_0_) + 1;
        if (roll <= sub->unknown_2_2_) {
            kind = 1;
        } else if (roll <= sub->unknown_2_2_ + sub->unknown_2_5_) {
            kind = 2;
        } else if (roll <= sub->unknown_2_2_ + sub->unknown_2_5_ + sub->unknown_3_0_) {
            kind = 3;
        }
        if (kind != 1) {
            row = func_0209b9e4(rows, arg2);
            total = 0;
            for (i = 0; i < 6; i++) {
                member = &row->members[i];
                total += member->weight;
            }
            if (total == 0) {
                kind = 1;
            } else {
                roll = NextRandomMax(var0, total) + 1;
                total = 0;
                for (j = 0; j < 6; j++) {
                    member = &row->members[j];
                    total += member->weight;
                    if (roll <= total) {
                        break;
                    }
                }
                out->ids[1] = member->id;
                out->counts[1] = NextRandomMax(var0, member->unknown_2_2_ - member->unknown_1_7_ + 1) + member->unknown_1_7_;
                if (kind != 2) {
                    total = 0;
                    for (k = 0; k < 6; k++) {
                        member = &row->members[k];
                        total += member->weight;
                    }
                    roll = NextRandomMax(var0, total) + 1;
                    total = 0;
                    for (l = 0; l < 6; l++) {
                        member = &row->members[l];
                        total += member->weight;
                        if (roll <= total) {
                            break;
                        }
                    }
                    out->ids[2] = member->id;
                    out->counts[2] = NextRandomMax(var0, member->unknown_2_2_ - member->unknown_1_7_ + 1) + member->unknown_1_7_;
                }
            }
        }
    }

    entry = func_0209bd94(&state->table, arg2);
    if (entry != NULL) {
        maxCount = entry->maxCount;
    } else {
        maxCount = 5;
    }
    var14 = out->counts[0] + out->counts[1] + out->counts[2] - maxCount;
    if (var14 > 0) {
        step = var14 / 3;
        if (step == 0) {
            step = 1;
        }
        slot = 0;
        while (var14 > 0) {
            prev = out->counts[slot];
            out->counts[slot] -= step;
            if (out->counts[slot] < 0) {
                out->counts[slot] = 0;
            }
            if (slot == 0 && out->counts[slot] == 0) {
                out->counts[slot] = 1;
            }
            var14 -= prev - out->counts[slot];
            slot++;
            if (slot >= 3) {
                slot = 0;
            }
        }
    }

    if (kind == 2) {
        if (NextRandomMax(var0, 2) != 0) {
            short id = out->ids[0];
            short count = out->counts[0];
            out->ids[0] = out->ids[1];
            out->counts[0] = out->counts[1];
            out->ids[1] = id;
            out->counts[1] = count;
        }
    } else if (kind == 3) {
        struct Struct_020e8e2c var20 = data_020e8e2c;
        struct Struct_0209afd4_2 saved;
        int pick = NextRandomMax(var0, 6);
        saved = *out;
        out->ids[var20.slots[pick][0]] = saved.ids[0];
        out->counts[var20.slots[pick][0]] = saved.counts[0];
        out->ids[var20.slots[pick][1]] = saved.ids[1];
        out->counts[var20.slots[pick][1]] = saved.counts[1];
        out->ids[var20.slots[pick][2]] = saved.ids[2];
        out->counts[var20.slots[pick][2]] = saved.counts[2];
    }
}
