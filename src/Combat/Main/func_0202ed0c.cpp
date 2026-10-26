#include <globaldefs.h>

struct Struct_0202ed0c_3 {
    unsigned int v[3];
};

struct Struct_0202ed0c_4 {
    unsigned int v[12];
};

struct Struct_0202ed0c {
    struct Struct_0202ed0c_3 a;
    struct Struct_0202ed0c_3 b;
    struct Struct_0202ed0c_3 c;
    struct Struct_0202ed0c_4 d;
};

struct Struct_0202ed0c_2 {
    char pad[4];
    struct Struct_0202ed0c_3 a;
    struct Struct_0202ed0c_3 b;
    struct Struct_0202ed0c_3 c;
    struct Struct_0202ed0c_4 d;
};

// USA: func_0202ed0c
extern "C" ARM void func_0202ed0c(struct Struct_0202ed0c_2* dst, struct Struct_0202ed0c* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
}
