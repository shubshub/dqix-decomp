#include <globaldefs.h>

struct Struct_ov006_02153e8c_2 { short f0; short f1; };

struct Struct_ov006_02153e8c_3 {
    char pad[0x20];
    struct Struct_ov006_02153e8c_2* arr;
    unsigned short count;
};

struct Struct_ov006_02153e8c { short a; short b; };

// USA: func_ov006_02153e8c
extern "C" ARM void func_ov006_02153e8c(struct Struct_ov006_02153e8c_3* obj, struct Struct_ov006_02153e8c* key) {
    short keyA = key->a;
    unsigned short count = obj->count;
    unsigned short i;
    for (i = 0; i < count; i++) {
        struct Struct_ov006_02153e8c_2* e = obj->arr + i;
        if (e->f0 == keyA) {
            e->f0 = *(short*)key;
            e->f1 = *(unsigned short*)((char*)key + 2);
            return;
        }
    }
    for (i = 0; i < count; i++) {
        struct Struct_ov006_02153e8c_2* e = obj->arr + i;
        if (e->f0 <= 0) {
            e->f0 = *(short*)key;
            e->f1 = *(unsigned short*)((char*)key + 2);
            return;
        }
    }
}
