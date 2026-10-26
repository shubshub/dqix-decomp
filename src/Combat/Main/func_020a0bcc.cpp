#include <globaldefs.h>

struct Struct_020a0bcc {
    short* unknown_0_;
    char* by;
    short count;
};

// USA: func_020a0bcc
extern "C" ARM void func_020a0bcc(struct Struct_020a0bcc* p) {
    short* var0 = p->unknown_0_;
    char* by = p->by;
    short count = p->count;
    short i;
    for (i = 0; i < count; i++) {
        var0[i] = -1;
        by[i] = 0;
    }
}
