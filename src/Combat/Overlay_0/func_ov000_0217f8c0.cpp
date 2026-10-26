#include <globaldefs.h>

struct TableEntry0217f8c0 {
    char pad0[0x4c];
    int unknown_4c_;
#if defined(jpn)
    char pad1[0x488 - 0x50];
#else
    char pad1[0x448 - 0x50];
#endif
};

struct Struct0217f8c0 {
    char pad[0x6c];
    signed char idx[4];
    char pad2[0x17c - 0x70];
    int unknown_17c_;
};

// USA: func_ov000_0217f8c0
extern "C" ARM struct TableEntry0217f8c0* func_ov000_0217f8c0(struct Struct0217f8c0* s) {
    int i;
    for (i = 0; i < 4; i++) {
        struct TableEntry0217f8c0* e = (struct TableEntry0217f8c0*)((char*)s + 0x958) + s->idx[i];
        if (s->unknown_17c_ == e->unknown_4c_) {
            return e;
        }
    }
    return 0;
}
