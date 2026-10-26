#include <globaldefs.h>

#if defined(jpn)
struct Struct_0209497c {
    char pad0[0xc];
    short id;
    char unknown_e_[0x10 - 0xe];
};

struct List0209497c {
    struct Struct_0209497c entries[18];
    char pad[0x13b - 0x120];
    signed char count;
};
#else
struct Struct_0209497c {
    char pad0[0x30];
    short id;
    char unknown_32_[0x34 - 0x32];
};

struct List0209497c {
    struct Struct_0209497c entries[18];
    char pad[0x3cb - 0x3a8];
    signed char count;
};
#endif

// USA: func_0209497c
extern "C" ARM int func_0209497c(struct List0209497c* s, int key) {
    int i;
    for (i = 0; i < s->count; i++) {
        short id = s->entries[i].id;
        if (id == key) {
            return 1;
        }
    }
    return 0;
}
