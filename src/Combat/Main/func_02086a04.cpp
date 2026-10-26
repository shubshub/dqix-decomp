#include <globaldefs.h>

extern "C" void* func_02086868(void*, void*);

struct Struct_02086a04_2 {
    signed char id : 6;
    char rest[0x23c - 1];
};

struct Struct_02086a04 {
    char pad0[0xf80];
    struct Struct_02086a04_2 elems[13];
    unsigned char count;
};

// USA: func_02086a04
extern "C" ARM int func_02086a04(struct Struct_02086a04* c, int id) {
    if (id < 0) return 0;
    int found = 0;
    unsigned char i;
    for (i = 0; i < c->count; i++) {
        struct Struct_02086a04_2* e = &c->elems[i];
        if (id == e->id) {
            e->id = -1;
            c->count--;
            found = 1;
            break;
        }
    }
    if (found) {
        unsigned char j;
        for (j = 0; j < c->count; j++) {
            struct Struct_02086a04_2* e = &c->elems[j];
            if (e->id < 0) {
                int next = j + 1;
                struct Struct_02086a04_2* var6 = &c->elems[next];
                func_02086868(e, var6);
                var6->id = -1;
            }
        }
    }
    return found;
}
