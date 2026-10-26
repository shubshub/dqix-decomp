#include <globaldefs.h>

#if defined(jpn)
struct Struct_020949bc {
    short id;
    char pad[0x10 - 2];
};

struct List020949bc {
    char pad0[0x8c];
    struct Struct_020949bc entries[9];
    char pad2[0x13c - 0x11c];
    signed char count;
};
#else
struct Struct_020949bc {
    short id;
    char pad[0x34 - 2];
};

struct List020949bc {
    char pad0[0x1d0];
    struct Struct_020949bc entries[9];
    char pad2[0x3cc - 0x3a4];
    signed char count;
};
#endif

// USA: func_020949bc
extern "C" ARM int func_020949bc(struct List020949bc* s, int key) {
    int i;
    for (i = 0; i < s->count; i++) {
        short id = s->entries[i].id;
        if (id == key) {
            return 1;
        }
    }
    return 0;
}
