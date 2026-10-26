#include <globaldefs.h>
struct Struct_0205e3ec { unsigned int v[4]; };
struct Struct_0205e330_3 { unsigned char a; unsigned char b; unsigned char pad[2]; struct Struct_0205e3ec unknown_4_; };
// USA: func_0205e3ec
extern "C" ARM struct Struct_0205e330_3* func_0205e3ec(struct Struct_0205e330_3* dst, struct Struct_0205e330_3* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->unknown_4_ = src->unknown_4_;
    return dst;
}
