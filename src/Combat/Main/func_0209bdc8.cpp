#include <globaldefs.h>

struct Struct_0209bdc8_2 {
    unsigned int f0;
    unsigned int state : 3;
    unsigned int : 10;
    unsigned int mask : 8;
    unsigned int : 11;
    char pad[0x18];
};

struct Struct_0209bdc8 {
    struct Struct_0209bdc8_2 entries[6];
    int count;
};

// USA: func_0209bdc8
extern "C" ARM struct Struct_0209bdc8_2* func_0209bdc8(struct Struct_0209bdc8* c, int flag, unsigned int mask) {
    unsigned int var0 = (flag == 0);
    int i;
    for (i = 0; i < c->count; i++) {
        struct Struct_0209bdc8_2* e = &c->entries[i];
        if (var0 == e->state || e->state == 2) {
            if (mask & e->mask) {
                return e;
            }
        }
    }
    return 0;
}
