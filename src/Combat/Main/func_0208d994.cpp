#include <globaldefs.h>

struct Struct_0208d994 {
    short h0;
    int w4;
    int w8;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
};

struct Struct_0208bf78_5 {
    struct Struct_0208d994* base;
    short count;
};

// USA: func_0208d994
extern "C" ARM struct Struct_0208d994* func_0208d994(struct Struct_0208bf78_5 *l, int key) {
    short i;
    if (key < 0) return NULL;
    for (i = 0; i < l->count; i++) {
        if (key == l->base[i].h0) return &l->base[i];
    }
    return NULL;
}
