#include <globaldefs.h>

struct Struct_ov000_0215767c_4 {
    char pad0[0x20];
    struct Struct_ov000_0215767c_4* next;
};
struct Struct_ov000_0215767c_5 {
    char pad0[9];
    unsigned char count;
    char pad1[0xa];
    struct Struct_ov000_0215767c_4* head;
};

// USA: func_ov000_021600cc
extern "C" ARM void func_ov000_021600cc(struct Struct_ov000_0215767c_5* obj, struct Struct_ov000_0215767c_4* arg1) {
    struct Struct_ov000_0215767c_4** p = &obj->head;
    while (*p != NULL) {
        p = &(*p)->next;
    }
    *p = arg1;
    obj->count++;
}
