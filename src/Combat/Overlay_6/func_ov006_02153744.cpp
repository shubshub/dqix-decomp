#include <globaldefs.h>

struct Struct_02071d60;
struct Struct_02071d60_2;
extern "C" Struct_02071d60_2* func_02071d60(Struct_02071d60* list, int key);

struct Struct_ov006_02153744 {
    short key;
    unsigned short bit0 : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short : 14;
};

struct Struct_ov006_02153744_2 {
    char pad[0x10];
    unsigned int unknown_10_0_ : 22;
    unsigned int unknown_12_6_ : 1;
    unsigned int unknown_12_7_ : 9;
};

// USA: func_ov006_02153744
extern "C" ARM void func_ov006_02153744(void* unused, Struct_02071d60* list, Struct_ov006_02153744* arr, int count) {
    int i;
    for (i = 0; i < count; i++, arr++) {
        Struct_02071d60_2* e = func_02071d60(list, arr->key);
        if (e == 0) continue;
        Struct_ov006_02153744_2* entry = (Struct_ov006_02153744_2*)e;
        entry->unknown_12_6_ = arr->bit0 || arr->unknown_2_1_;
    }
}
