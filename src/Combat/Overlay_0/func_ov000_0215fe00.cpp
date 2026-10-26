#include <globaldefs.h>

struct Struct_ov000_0215a88c {
    char pad0[4];
    struct Struct_ov000_0215a88c* next;
};
struct Struct_ov000_0215a88c_3 {
    char pad0[8];
    struct Struct_ov000_0215a88c* head;
    char pad1[0x13];
    unsigned char count;
};

// USA: func_ov000_0215fe00
extern "C" ARM void func_ov000_0215fe00(struct Struct_ov000_0215a88c_3* obj, struct Struct_ov000_0215a88c* arg1) {
    struct Struct_ov000_0215a88c** p = &obj->head;
    while (*p != NULL) {
        p = &(*p)->next;
    }
    *p = arg1;
    obj->count++;
}
