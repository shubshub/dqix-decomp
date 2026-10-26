#include <globaldefs.h>

struct Struct_02098834_4 { char v[11]; };
struct Struct_02098834_5 { char v[6]; };
struct Struct_02098834 { short v[14]; };
struct Struct_02098834_2 { int v[6]; };
struct Struct_02098834_3 { int v[31]; };

struct Struct_02098630 {
    struct Struct_02098834_4 a;
    unsigned char b;
    int c;
    int d;
    struct Struct_02098834_5 e;
    struct Struct_02098834 f;
    struct Struct_02098834_2 g;
    struct Struct_02098834 h;
    struct Struct_02098834_3 i;
};

// USA: func_02098834
extern "C" ARM struct Struct_02098630* func_02098834(struct Struct_02098630* dst, struct Struct_02098630* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->g = src->g;
    dst->h = src->h;
    dst->i = src->i;
    return dst;
}
