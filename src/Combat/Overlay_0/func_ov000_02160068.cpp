#include <globaldefs.h>

struct Struct_ov000_0215767c_6 {
    char pad0[0x30];
    struct Struct_ov000_0215767c_6* next;
};
struct Struct_ov000_0215767c_7 {
    char pad0[8];
    unsigned char count;
    char pad1[7];
    struct Struct_ov000_0215767c_6* head;
};

// USA: func_ov000_02160068
extern "C" ARM void func_ov000_02160068(struct Struct_ov000_0215767c_7* obj, struct Struct_ov000_0215767c_6* arg1) {
    struct Struct_ov000_0215767c_6** p = &obj->head;
    while (*p != NULL) {
        p = &(*p)->next;
    }
    *p = arg1;
    obj->count++;
}
