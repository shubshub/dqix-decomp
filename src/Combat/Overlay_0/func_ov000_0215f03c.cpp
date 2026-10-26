#include <globaldefs.h>

struct Struct_ov000_0215f03c {
    char text[0x16];
};

struct Struct_ov000_0215f03c_6 {
    char pad0[0x6c];
    Struct_ov000_0215f03c name;
    unsigned char unknown_82_;
    unsigned char unknown_83_;
};

struct Struct_02070b6c_3 {
    char pad0[4];
};

extern "C" Struct_ov000_0215f03c_6* func_02070fd0(struct Struct_02070b6c_3* container, int key);

struct Struct_ov000_0215f03c_2 {
    char pad0[0x3e];
    Struct_ov000_0215f03c name;
    unsigned char field54;
    unsigned char unknown_55_;
    char unknown_56_[0xa4 - 0x56];
};

struct Struct_ov000_0215f03c_3 {
    char pad0[0x400];
    Struct_02070b6c_3 container;
};

struct Struct_ov000_0215f03c_4 {
    char pad0[0x158];
    Struct_ov000_0215f03c_2 unknown_158_[1];
    char unknown_1fc_[0x284 - 0x1fc];
    Struct_ov000_0215f03c_3 table;
};

struct Struct_ov000_0215f03c_5 {
    unsigned short key;
    unsigned char members[8];
    unsigned char memberCount : 4;
    unsigned char matched : 4;
    char unknown_b_[0x18 - 0xb];
};

struct Struct_ov000_0215f03c_7 {
    char pad0[0x81b1];
    unsigned char counter : 4;
    unsigned char groupCount : 2;
    unsigned char unused : 2;
    char unknown_81b2_[2];
    Struct_ov000_0215f03c_5 groups[4];
    char unknown_8214_[0x8e18 - 0x8214];
    Struct_ov000_0215f03c_4* data;
};

// USA: func_ov000_0215f03c
extern "C" ARM void func_ov000_0215f03c(Struct_ov000_0215f03c_7* self) {
    Struct_ov000_0215f03c_4* data = self->data;
    Struct_ov000_0215f03c_3* table = &data->table;
    Struct_ov000_0215f03c_2* var2 = data->unknown_158_;
    Struct_ov000_0215f03c_5* groups = self->groups;
    int i;
    unsigned char* members;
    int j;
    Struct_ov000_0215f03c_2* unit;
    Struct_ov000_0215f03c_5* group;
    for (i = 0; i < self->groupCount; i++) {
        group = &groups[i];
        int key = group->key;
        members = group->members;
        for (j = 0; j < group->memberCount; j++) {
            unit = &var2[members[j]];
            Struct_ov000_0215f03c_6* e = func_02070fd0(&table->container, key);
            if (e != NULL) {
                unit->name = e->name;
                unit->field54 = e->unknown_82_;
                unit->unknown_55_ = e->unknown_83_;
            }
        }
    }
}
