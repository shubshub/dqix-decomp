#include <globaldefs.h>

struct Struct_0209a9dc_3 { unsigned short id; unsigned short pad; };
struct Struct_0209a9dc {
    struct Struct_0209a9dc_3 entries[0x42];
    int count;
};
struct Struct_0209a9dc_2 {
    struct Struct_0209a9dc* base;
};

// USA: func_0209a9dc
extern "C" ARM struct Struct_0209a9dc_3* func_0209a9dc(struct Struct_0209a9dc_2* h, int i) {
    int j;
    struct Struct_0209a9dc* base;
    base = h->base;
    if (base == NULL) return NULL;
    if (i >= 0x42) return NULL;
    if (base->entries[i].id == i) return &base->entries[i];
    for (j = 0; j < base->count; j++) {
        if (base->entries[j].id == i) return &base->entries[j];
    }
    return NULL;
}
