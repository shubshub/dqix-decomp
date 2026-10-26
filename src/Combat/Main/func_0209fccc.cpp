#include <globaldefs.h>

struct Struct_0209fccc {
    unsigned short value;
};

struct Struct_0209d44c {
    unsigned char pad[4];
    char* ctx;
};

// USA: func_0209fccc
extern "C" ARM int func_0209fccc(struct Struct_0209d44c* obj, int mode) {
    struct Struct_0209fccc* s = *(struct Struct_0209fccc**)(obj->ctx + 0x8e18);
    if (s == NULL) {
        return -1;
    }
    if (mode == 0) {
        return s->value;
    }
    return s->value / 100;
}
