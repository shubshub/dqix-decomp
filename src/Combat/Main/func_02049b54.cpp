#include <globaldefs.h>

extern "C" void __clear(void* dst, int size);

struct Struct_02049b54_3 {
    unsigned int v[3];
};
struct Struct_02049b54 {
    unsigned int f0, f4, f8, fc;
};
struct Struct_02049b54_2 {
    unsigned char pad[0x13c];
    struct Struct_02049b54* sub;
};

// USA: func_02049b54
extern "C" ARM struct Struct_02049b54_3 func_02049b54(struct Struct_02049b54_2* obj) {
    struct Struct_02049b54_3 local;
    __clear(&local, 0xc);
    if (obj->sub == NULL) return local;
    unsigned int a = obj->sub->f4;
    unsigned int c = obj->sub->fc;
    local.v[0] = a;
    local.v[1] = 0xcc;
    local.v[2] = c;
    return local;
}
