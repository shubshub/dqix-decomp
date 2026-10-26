#include <globaldefs.h>

struct Struct_020a2928 { unsigned int v[4]; };
struct Struct_020a2928_2 { unsigned int v[3]; };

struct Struct_020a2908 {
    struct Struct_020a2928 a;
    unsigned int b;
    struct Struct_020a2928_2 c;
    struct Struct_020a2928_2 d;
};

// USA: func_020a2928
extern "C" ARM struct Struct_020a2908* func_020a2928(struct Struct_020a2908* dst, struct Struct_020a2908* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    return dst;
}
