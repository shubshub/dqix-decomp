#include <globaldefs.h>
#include <std_library_functions.h>

struct Unit { char pad0[0x25]; unsigned char suffix_; char unknown_26_[0xa4 - 0x26]; };
struct Struct_02070b6c_3 { char unknown_0_[4]; };
struct Struct_0200f3a4_15 { char unknown_0_[0x58]; };
struct Struct_02070b6c_4 { char pad0[0x2c]; Struct_0200f3a4_15 unknown_2c_; };
struct Struct_ov000_0215ed8c { char pad0[0x400]; Struct_02070b6c_3 unknown_400_; };
struct BattleData {
    char pad0[0x158];
    Unit unknown_158_[1];
    char unknown_1fc_[0x284 - 0x1fc];
    Struct_ov000_0215ed8c table_;
};
struct Struct_ov000_0215ed8c_2 {
    unsigned short key_;
    unsigned char members_[8];
    unsigned char memberCount_ : 4;
    unsigned char unknown_a_4_ : 4;
    char unknown_b_[0x18 - 0xb];
};
struct Struct_ov000_0215ed8c_3 {
    unsigned char unknown_0_;
    unsigned char memberCount_;
    unsigned short key_;
    unsigned int unknown_4_;
};
struct Struct_ov000_0215767c_2 {
    char pad0[0x81b1];
    unsigned char unknown_81b1_0_ : 4;
    unsigned char unknown_81b1_4_ : 2;
    unsigned char unknown_81b1_6_ : 2;
    char unknown_81b2_[2];
    Struct_ov000_0215ed8c_2 unknown_81b4_[3];
    Struct_ov000_0215ed8c_3 unknown_81fc_[4];
    char unknown_821c_[0x8e18 - 0x821c];
    BattleData* unknown_8e18_;
};
extern "C" Struct_02070b6c_4* func_02070fd0(Struct_02070b6c_3*, int);
extern "C" int func_020a3694(int*);
extern "C" void func_02089630(Unit*, Struct_0200f3a4_15*, int);

// USA: func_ov000_0215ed8c
extern "C" ARM void func_ov000_0215ed8c(Struct_ov000_0215767c_2* self) {
    Struct_02070b6c_3* table = &self->unknown_8e18_->table_.unknown_400_;
    Struct_ov000_0215ed8c_2* groups = self->unknown_81b4_;
    Struct_ov000_0215ed8c_3* var2 = self->unknown_81fc_;
    unsigned char var3 = 0;
    int totals[4] = {0};
    int i;
    int key;
    unsigned char* members;
    Unit* unit;
    Struct_02070b6c_4* entry;
    Struct_ov000_0215ed8c_2* group;
    for (i = 0; i < self->unknown_81b1_4_; ++i) {
        group = &groups[i];
        key = group->key_;
        int var11;
        for (var11 = 0; var11 < self->unknown_81b1_6_; ++var11) {
            if (key == var2[var11].key_) break;
        }
        members = groups[i].members_;
        memset(members, 0, 8);
        totals[var11] += groups[i].memberCount_;
        for (int j = 0; j < group->memberCount_; ++j) {
            members[j] = var3;
            unit = &self->unknown_8e18_->unknown_158_[var3];
            entry = func_02070fd0(table, key);
            if (entry) {
                func_02089630(unit, &entry->unknown_2c_, func_020a3694((int*)self->unknown_8e18_) != 0);
                for (;;) {
                    if (!(var2[var11].unknown_4_ & (1 << var2[var11].unknown_0_))) break;
                    ++var2[var11].unknown_0_;
                    if (var2[var11].unknown_0_ >= 18) var2[var11].unknown_0_ = 1;
                }
                unit->suffix_ = var2[var11].unknown_0_;
                var2[var11].unknown_4_ |= 1 << unit->suffix_;
                ++var2[var11].unknown_0_;
                if (var2[var11].unknown_0_ >= 18) var2[var11].unknown_0_ = 1;
            }
            ++var3;
        }
    }
    for (int j = 0; j < 4; ++j) var2[j].memberCount_ = totals[j];
    for (int j = 0; j < self->unknown_81b1_6_; ++j) {
        if (var2[j].memberCount_ <= 1) {
            int key = var2[j].key_;
            int var16;
            for (var16 = 0; var16 < self->unknown_81b1_4_; ++var16) {
                if (key == groups[var16].key_) break;
            }
            self->unknown_8e18_->unknown_158_[groups[var16].members_[0]].suffix_ = 0;
        }
    }
}
