#include <globaldefs.h>

extern "C" int memcmp(void* a, void* b, int n);

struct Struct_0209859c {
    char pad0[0x14];
    char key[6];
    char pad1a[0xe8 - 0x1a];
};

// USA: func_0209859c
extern "C" ARM struct Struct_0209859c* func_0209859c(struct Struct_0209859c* list, void* key) {
    struct Struct_0209859c* e;
    int i;
    for (i = 0; i < 0x1e; i++) {
        e = &list[i];
        if (memcmp(key, e->key, 6) == 0) return e;
    }
    return 0;
}
