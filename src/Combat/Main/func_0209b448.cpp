#include <globaldefs.h>
#include "Util/Random.h"
#include "std_library_functions.h"

#if defined(jpn)
#define data_020e8e74 data_020e8f88
#endif

struct Struct_0209b448_3 {
    unsigned int key : 12;
    unsigned int unknown_1_4_ : 3;
    unsigned int unknown_1_7_ : 3;
    unsigned int unknown_2_2_ : 3;
    unsigned int unknown_2_5_ : 3;
    unsigned int unknown_3_0_ : 3;
    unsigned int rest : 5;
    int unk4;
};

struct Struct_0209b448_4 {
    unsigned int id : 12;
    unsigned int weight : 3;
    unsigned int unknown_1_7_ : 3;
    unsigned int unknown_2_2_ : 3;
    unsigned int rest : 11;
};

struct Struct_0209b448_5 {
    unsigned short id;
    unsigned short pad2;
    struct Struct_0209b448_3 unknown_4_[6];
    struct Struct_0209b448_4 members[6];
};

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

struct Struct_0209b448 {
#if defined(jpn)
    unsigned char pad[0x5c];
#else
    unsigned char pad[0x60];
#endif
    struct Struct_02073ec4_2 table;
};

struct Struct_0209b448_2 {
    short ids[3];
    short counts[3];
};

extern "C" struct Struct_0209b448_3* func_0209b944(struct Struct_0209b448_5* entries, int index, int key, int* arg3);
extern "C" struct Struct_02073ec4_3* func_0209bd94(struct Struct_02073ec4_2* table, int key);

extern const int data_020e8e74[6][3];

// USA: func_0209b448
extern "C" ARM void func_0209b448(struct Struct_0209b448_5* rows, int key, struct Struct_0209b448_2* out, struct Struct_0209b448* state) {
    int slot;
    int prev;
    int step;
    int var3;
    int maxCount;
    int sum;
    int l;
    int k;
    int j;
    int i;
    int weights;
    int pick;
    int roll;
    int kind;
    int index;
    struct Struct_02073ec4_3* entry;
    struct Struct_0209b448_4* member;
    int var17;
    int var18;
    int var19;
    int total;
    struct Struct_0209b448_3* sub;
    struct Random* var22;

    var22 = GetBTRandom();
    kind = 1;
    index = 0;
    sub = func_0209b944(rows, 0, key, &index);
    if (sub == NULL) {
        kind = 1;
        out->counts[0] = 1;
        out->ids[0] = 0x10;
    } else {
        weights = sub->unknown_2_2_ + sub->unknown_2_5_ + sub->unknown_3_0_;
        roll = rand() % weights + 1;
        if (roll <= sub->unknown_2_2_) {
            kind = 1;
        } else if (roll <= sub->unknown_2_2_ + sub->unknown_2_5_) {
            kind = 2;
        } else if (roll <= sub->unknown_2_2_ + sub->unknown_2_5_ + sub->unknown_3_0_) {
            kind = 3;
        }
        total = 0;
        for (i = 0; i < 6; i++) {
            member = &rows[index].members[i];
            total += member->weight;
        }
        if (total == 0) {
            kind = 1;
            out->counts[0] = 1;
            out->ids[0] = 0x10;
        } else {
            pick = rand() % total + 1;
            sum = 0;
            for (j = 0; j < 6; j++) {
                member = &rows[index].members[j];
                sum += member->weight;
                if (pick <= sum) {
                    break;
                }
            }
            out->ids[0] = member->id;
            var17 = member->unknown_2_2_ - member->unknown_1_7_;
            out->counts[0] = rand() % (var17 + 1) + member->unknown_1_7_;
            if (kind != 1) {
                pick = rand() % total + 1;
                sum = 0;
                for (k = 0; k < 6; k++) {
                    member = &rows[index].members[k];
                    sum += member->weight;
                    if (pick <= sum) {
                        break;
                    }
                }
                out->ids[1] = member->id;
                var18 = member->unknown_2_2_ - member->unknown_1_7_;
                out->counts[1] = rand() % (var18 + 1) + member->unknown_1_7_;
                if (kind != 2) {
                    pick = rand() % total + 1;
                    sum = 0;
                    for (l = 0; l < 6; l++) {
                        member = &rows[index].members[l];
                        sum += member->weight;
                        if (pick <= sum) {
                            break;
                        }
                    }
                    out->ids[2] = member->id;
                    var19 = member->unknown_2_2_ - member->unknown_1_7_;
                    out->counts[2] = rand() % (var19 + 1) + member->unknown_1_7_;
                }
            }
        }
    }

    entry = func_0209bd94(&state->table, key);
    if (entry != NULL) {
        maxCount = entry->maxCount;
    } else {
        maxCount = 5;
    }
    var3 = out->counts[0] + out->counts[1] + out->counts[2] - maxCount;
    if (var3 > 0) {
        step = var3 / 3;
        if (step == 0) {
            step = 1;
        }
        slot = 0;
        while (var3 > 0) {
            prev = out->counts[slot];
            out->counts[slot] -= step;
            if (out->counts[slot] < 0) {
                out->counts[slot] = 0;
            }
            if (slot == 0 && out->counts[slot] == 0) {
                out->counts[slot] = 1;
            }
            var3 -= prev - out->counts[slot];
            slot++;
            if (slot >= 3) {
                slot = 0;
            }
        }
    }

    if (kind == 2) {
        if (NextRandomMax(var22, 2) != 0) {
            short id = out->ids[0];
            short count = out->counts[0];
            out->ids[0] = out->ids[1];
            out->counts[0] = out->counts[1];
            out->ids[1] = id;
            out->counts[1] = count;
        }
    } else if (kind == 3) {
        struct Struct_0209b448_2 saved;
        int order = NextRandomMax(var22, 6);
        saved = *out;
        out->ids[data_020e8e74[order][0]] = saved.ids[0];
        out->counts[data_020e8e74[order][0]] = saved.counts[0];
        out->ids[data_020e8e74[order][1]] = saved.ids[1];
        out->counts[data_020e8e74[order][1]] = saved.counts[1];
        out->ids[data_020e8e74[order][2]] = saved.ids[2];
        out->counts[data_020e8e74[order][2]] = saved.counts[2];
    }
}
