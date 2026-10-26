#include <globaldefs.h>

struct Struct_0201ae8c { unsigned int v[9]; };
struct Struct_0201ae8c_2 { unsigned int v[3]; };
struct Struct_0201a600_6 {
    struct Struct_0201ae8c a;   // 0x00
    struct Struct_0201ae8c_2 b;   // 0x24
    unsigned int c;             // 0x30
};

// USA: func_0201ae8c
extern "C" ARM struct Struct_0201a600_6* func_0201ae8c(struct Struct_0201a600_6* dst, struct Struct_0201a600_6* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    return dst;
}
