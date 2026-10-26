#include "globaldefs.h"

struct Struct_ov003_02170688 {
    unsigned char unknown_0_[0xb];
    unsigned char rank : 7;
    unsigned char unknown_b_7_ : 1;
    unsigned int unknownC0 : 4;
    unsigned int category : 4;
    unsigned int unknown_d_0_ : 7;
    unsigned int order : 4;
    unsigned int unknown_e_3_ : 5;
    unsigned int unknown_f_0_ : 8;
};
struct Struct_ov003_02170688_2 {
    unsigned char unknown_0_[0x1b38];
    int count;
};
struct Struct_ov003_02170688_3 {
    unsigned char unknown_0_[0xf4];
    Struct_ov003_02170688* entries[31];
    Struct_ov003_02170688_2* unknown_170_;
};
struct Struct_02098e70;
extern "C" int func_02098e70(Struct_02098e70*);
struct Struct_02098eac;
extern "C" int func_02098eac(Struct_02098eac*);

extern "C" ARM void func_ov003_02170688(Struct_ov003_02170688_3* state) {
    Struct_ov003_02170688_2* var0 = state->unknown_170_;
    int count = var0->count;
    int first = func_02098e70((Struct_02098e70*)var0);
    int var3 = first + func_02098eac((Struct_02098eac*)var0);
    int moved = 0;
    for (int i = 0; i < count; ++i) {
        Struct_ov003_02170688* entry = state->entries[i];
        if (entry->category == 9 || entry->category == 10) {
            state->entries[i] = state->entries[moved];
            state->entries[moved] = entry;
            ++moved;
        }
    }
    for (int i = 0; i < var3 - 1; ++i) {
        for (int j = 0; j < var3 - 1 - i; ++j) {
            Struct_ov003_02170688* a = state->entries[j];
            Struct_ov003_02170688* b = state->entries[j + 1];
            if (a->rank < b->rank) {
                state->entries[j] = b;
                state->entries[j + 1] = a;
            } else if (a->rank > b->rank) {
                continue;
            } else {
                if (a->order < b->order) {
                    state->entries[j] = b;
                    state->entries[j + 1] = a;
                } else if (a->order > b->order) {
                    continue;
                } else if (a->unknown_e_3_ < b->unknown_e_3_) {
                    state->entries[j] = b;
                    state->entries[j + 1] = a;
                }
            }
        }
    }
    int var11 = 0;
    for (int i = var3; i < count - 1; ++i, ++var11) {
        for (int j = var3; j < count - 1 - var11; ++j) {
            Struct_ov003_02170688* a = state->entries[j];
            Struct_ov003_02170688* b = state->entries[j + 1];
            if (a->rank < b->rank) {
                state->entries[j] = b;
                state->entries[j + 1] = a;
            } else if (a->rank > b->rank) {
                continue;
            } else {
                if (a->order < b->order) {
                    state->entries[j] = b;
                    state->entries[j + 1] = a;
                } else if (a->order > b->order) {
                    continue;
                } else {
                    if (a->unknown_e_3_ < b->unknown_e_3_) {
                        state->entries[j] = b;
                        state->entries[j + 1] = a;
                    } else if (a->unknown_e_3_ > b->unknown_e_3_) {
                        continue;
                    } else if (a->category > b->category) {
                        state->entries[j] = b;
                        state->entries[j + 1] = a;
                    }
                }
            }
        }
    }
}
