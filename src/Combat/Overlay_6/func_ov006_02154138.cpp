#include <globaldefs.h>

extern "C" void* __clear(void*, int);
extern "C" int func_020ac4c0(void*);
extern "C" int func_020ac494(void*);

struct Struct_ov006_02154138 {
    short item;
    unsigned short selected : 1;
    unsigned short unknown_2_1_ : 15;
};
struct Struct_ov006_02154138_2 {
    short item;
    char unknown_2_[0x14];
    short unknown_16_;
    char unknown18[8];
};
struct Struct_ov006_02154138_3 {
    char unknown_0_[4];
    Struct_ov006_02154138_2* entries;
    char unknown_8_[2];
    unsigned short count;
};
struct Struct_ov006_02154138_4 {
    Struct_ov006_02154138_3* list;
    char unknown_4_[0x1c];
    Struct_ov006_02154138* unknown_20_;
    unsigned short count;
};
struct Struct_ov006_02154138_5 {
    char unknown_0_[0x10];
    unsigned int unknown_10_0_ : 23;
    unsigned int count : 9;
    char unknown14[0x9c];
};

// USA: func_ov006_02154138
extern "C" ARM int func_ov006_02154138(void* context) {
    Struct_ov006_02154138_4* state = (Struct_ov006_02154138_4*)context;
    if (!state->list) return 0;
    signed char var1[472];
    Struct_ov006_02154138_5 work;
    unsigned short count = 0;
    __clear(var1, sizeof(var1));
    for (unsigned short var4 = 0; var4 < state->count; var4++) {
        short item = state->unknown_20_[var4].item;
        var1[item] |= state->unknown_20_[var4].selected;
    }
    for (unsigned short recordIndex = 0; recordIndex < state->list->count; recordIndex++) {
        Struct_ov006_02154138_2* record = (Struct_ov006_02154138_2*)((unsigned int)state->list->entries + (short)recordIndex * 0x20);
        if (record && record->unknown_16_ < 0) var1[record->item] |= 2;
    }
    for (unsigned short var8 = 1; var8 < 472; var8++) {
        if (var1[var8] == 3) count++;
    }
    func_020ac4c0(&work);
    work.count = count;
    func_020ac494(&work);
    return (short)count;
}
