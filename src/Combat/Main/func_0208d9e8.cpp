#include <globaldefs.h>

struct Struct_0208d9e8 {
    short h0;
    int w4;
    int w8;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
};

struct Struct_0208bf78_5 {
    struct Struct_0208d9e8* base;
    short count;
};

extern "C" struct Struct_0208d9e8* func_0208d994(struct Struct_0208bf78_5* l, int key);

// USA: func_0208d9e8
extern "C" ARM int func_0208d9e8(struct Struct_0208bf78_5* list, int key) {
    struct Struct_0208d9e8* e = func_0208d994(list, key);
    return e ? e->w4 : 0;
}
